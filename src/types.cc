
/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* types.cc: AST subclasses related to types. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/***** AST *****/

static GCINIT _gcdummy;

AST_Ptr
AST::resolveTypes (Decl* context)
{
    AST_Ptr r;
    int resolved0, ambiguities0, resolved, ambiguities;
    int errors;

    r = this;
    resolved = ambiguities = -1;
    do {
        resolved0 = resolved;
        ambiguities0 = ambiguities;
        resolved = ambiguities = 0;
        errors = numErrors ();
        r = r->resolveTypes (context, resolved, ambiguities);
    } while (errors == numErrors () &&
             (resolved != resolved0 || ambiguities != ambiguities0));
    if (ambiguities > 0)
        error (this,
               "unresolved overloadings in left side of attribute reference");
    return r;
}

AST_Ptr
AST::resolveTypesOuter (Decl* context)
{
    AST_Ptr r;
    r = this;
    r->freezeDecls (true);
    r = r->resolveTypes (context);
    r->freezeDecls (false);
    return r;
}


/*****    TYPE    *****/

Type_Ptr
Type::getType ()
{
    error (this, "a type may not be used as a value in this dialect");
    return makeVar ();
}

gcstring
Type::getRuntimeName ()
{
    return "";
}

int
Type::numParams ()
{
    return -1;
}

Type_Ptr
Type::returnType ()
{
    return NULL;
}

Type_Ptr
Type::paramType (int k)
{
    throw range_error ("function type has no parameters");
}

int
Type::numTypeParams ()
{
    return -1;
}

Type_Ptr
Type::typeParam (int k)
{
    throw range_error ("type has no type parameters");
}

const Environ*
Type::getEnviron ()
{
    return theEmptyEnviron;
}

Type_Ptr
Type::makeVar ()
{
    AST_Ptr dummy[1];

    Type_Ptr result = AST::make_tree (TYPE_VAR, dummy, dummy)->asType ();
    result->addDecl (makeTypeVarDecl (result->as_string (), result));
    return result;
}

Type_Ptr
Type::binding ()
{
    Type_Ptr p;
    p = this;
    while (p->_binding != NULL)
	p = p->_binding;
    return p;
}

bool
Type::unifies (Type_Ptr type)
{
    Unwind_Stack bindings;
    bool result = unify (type, bindings);
    popBindings (bindings, 0);
    return result;
}

bool
Type::unify (Type_Ptr type, Unwind_Stack& bindings)
{
    Type_Ptr me = binding ();
    type = type->binding ();
    if (me == type)
	return true;
    if (me->isTypeVariable ())
	return me->bind (type, bindings);

    size_t numBindings0 = bindings.size ();
    if (!type->bind (me, bindings))
	return false;
    if (type->checkBinding (bindings))
        return true;
    else {
        popBindings (bindings, numBindings0);
        return false;
    }
}

bool
Type::unify (Type_Ptr type)
{
    Unwind_Stack dummy;
    return unify (type, dummy);
}

bool
Type::unifyLists (AST_Ptr L1, AST_Ptr L2, Unwind_Stack& bindings)
{
    size_t b0 = bindings.size ();
    if (L1->arity () != L2->arity ())
        return false;
    for_each_child (c, L1) {
        if (!c->asType ()->unify (L2->child (c_i_)->asType (), bindings)) {
            popBindings (bindings, b0);
            return false;
        }
    } end_for;
    return true;
}

void
Type::popBindings (Unwind_Stack& bindings, size_t trimTo)
{
    while (bindings.size () > trimTo) {
        bindings.top ()->unbind ();
        bindings.pop ();
    }
}

bool
Type::bind (Type_Ptr target, Unwind_Stack& bindings)
{
    assert (_binding == NULL && target != NULL);
    bindings.push (this);
    _binding = target;
    return true;
}

void
Type::unbind ()
{
    assert (_binding != NULL);
    _binding = NULL;
}

bool
Type::isTypeVariable ()
{
    return false;
}

bool
Type::hasFreeVariables (Type_Ptr type)
{
    current_mark += 1;
    return type->hasFreeVariables ();
}

bool
Type::hasFreeVariables ()
{
    if (mark ()) {
        for_each_child (c, this) {
            if (c->asType ()->hasFreeVariables ())
                return true;
        } end_for;
    }
    return false;
}

/** Default implementation of checkBinding for non-function types. */
bool
Type::checkBinding (Unwind_Stack& bindings)
{
    size_t numBindings0 = bindings.size ();
    Type_Ptr target = binding ();

    if (child(1)->arity () != target->child(1)->arity ())
        return false;
    if (child (0)->getDecl () != target->child (0)->getDecl ())
        return false;
    for_each_child (c, child(1)) {
        if (! c->asType ()
            ->unify (target->child (1)->child (c_i_)->asType (), bindings)) {
            popBindings (bindings, numBindings0);
            return false;
        }
    } end_for;
    return true;
}

Type_Ptr
Type::freshen ()
{
    current_mark += 1;
    return _freshen ();
}

Type_Ptr
Type::_freshen ()
{
    Type_Ptr me = binding ();
    if (me != this)
        return me->_freshen ();

    if (!mark ())
        return _forward;

    _forward = this;
    if (arity () == 0)
        return this;

    bool modified;
    modified = false;

    AST_Ptr arg0;
    if (child (0)->asType () == NULL)
        arg0 = child (0);
    else {
        arg0 = child (0)->asType ()->_freshen ();
        if (child (0) != arg0)
            modified = true;
    }

    int type_arity = child (1)->arity ();
    AST_Ptr* type_args = new AST_Ptr[type_arity];
    for_each_child (c, child (1)) {
        type_args[c_i_] = c->asType ()->_freshen ();
        if (c != type_args[c_i_])
            modified = true;
    } end_for;

    if (!modified) {
        delete [] type_args;
        return this;
    }

    AST_Ptr kids[2] = {
        arg0, AST::make_tree (TYPE_LIST, type_args, type_args + type_arity)
    };
    _forward = AST::make_tree (oper ()->syntax (), kids, kids + 2)->asType ();

    delete [] type_args;
    return _forward;
}

void
Type::freshen (gcvector<Type_Ptr>& types)
{
    current_mark += 1;

    for (size_t i = 0; i < types.size (); i += 1) {
        types[i] = types[i]->_freshen ();
    }
}

Type_Ptr
Type::replaceBindings (Type_Ptr type)
{
    current_mark += 1;
    return type->replaceBindings ();
}

Type_Ptr
Type::replaceBindings ()
{
    Type_Ptr me = binding ();
    if (me->mark ()) {
        for_each_child_var (c, this) {
            c = c->asType()->replaceBindings ();
        } end_for;
    }
    return me;
}

Type_Ptr
makeFuncType (int n)
{
    gcvector<AST_Ptr> params;
    for (int i = 0; i < n; i += 1)
        params.push_back(Type::makeVar ());
    AST_Ptr paramList =
        AST::make_tree (TYPE_LIST, &params[0], &params[params.size()]);

    return consTree (FUNCTION_TYPE, Type::makeVar (), paramList)->asType ();
}

bool
makeFuncType (int n, Type_Ptr type)
{
    type = type->binding ();
    if (! type->isTypeVariable ())
        return (type->returnType () != NULL && type->numParams () == n);
    type->unify (makeFuncType (n));
    return true;
}

Type_Ptr
makeMethodType (int n, Decl* clas)
{
    gcvector<AST_Ptr> params;
    params.push_back (clas->asGenericType ());
    for (int i = 1; i < n; i += 1)
        params.push_back(Type::makeVar ());
    AST_Ptr paramList =
        AST::make_tree (TYPE_LIST, &params[0], &params[params.size()]);

    return consTree (FUNCTION_TYPE, Type::makeVar (), paramList)->asType ();
}

/*****  TYPE VARIABLES *****/

class TypeVar_AST : public Type {
public:

    gcstring getRuntimeName () {
        return getDecl ()->getRuntimeName ();
    }

protected:

    NODE_CONSTRUCTORS_INIT (TypeVar_AST, Type, _me (NULL));

    bool isTypeVariable () {
        return true;
    }

    bool hasFreeVariables () {
        Type_Ptr b = binding ();
        if (b == this)
            return true;
        else
            return b->hasFreeVariables ();
    }

    /* Each TypeVarDecl contains a pointer to a "canonical
     *  TypeVar_AST" for its type variable.  Binding and freshening
     *  work on this canonical AST. */

    Type_Ptr binding () {
        Decl* me = getDecl ();
        if (me == NULL)
            return this;
        else
            return me->getAst ()->asType ()->Type::binding ();
    }

    bool bind (Type_Ptr target, Unwind_Stack& bindings) {
        assert (_binding == NULL && target != NULL);
        Decl* me = getDecl ();
        assert (me != NULL);
        TypeVar_AST* canonical =
            dynamic_cast<TypeVar_AST*> (me->getAst ());
        if (canonical == this) {
            bindings.push (this);
            _binding = target;
            return true;
        } else
            return canonical->bind (target, bindings);
    }

    void unwind () {
        assert (_binding != NULL);
        Decl* me = getDecl ();
        assert (me != NULL && me->getAst () == this);
        _binding = NULL;
    }

    Type_Ptr _freshen () {
        Type_Ptr me = binding ();
        if (mark ()) {
            if (me == this) {
                _forward = makeVar ();
                return _forward;
            }
        } else if (me == this)
            return _forward;
        return me->_freshen ();
    }

    /** Since we will already have checked that we are bound to
     *  something proper in bind, this needn't do anything but return
     *  true. */
    bool checkBinding (Unwind_Stack&) {
        return true;
    }

    void _print (ostream& out, int indent) {
        Type_Ptr me = binding ();
        if (me == this) {
            if (arity () == 1) {
                out << "(type_var " << lineNumber () << " "
                    << child(0)->as_string ();
            } else
                out << "(type_var 0 $#" << uid;
            if (getDecl () != NULL)
                out << " " << getDecl ()->getIndex ();
            out << ")";
        } else
            print (me, out, indent);
    }

    gcstring as_string () const {
        if (arity () == 1)
            return child (0)->as_string ();
        else {
            char numeral[14];
            sprintf(numeral, "$#%d", uid);
            return string(numeral);
        }
    }

    AST* post_make () {
        uid = next_uid;
        next_uid += 1;
        return this;
    }

    Decl* getDecl (int k = 0) {
        return _me;
    }

    int numDecls () {
        return _me == NULL ? 0 : 1;
    }

    void addDecl (Decl* decl) {
        assert (_me == NULL);
        _me = decl;
    }

    void collectTypeVarDecls (Decl* enclosing) {
        addDecl (enclosing->addTypeVarDecl (this));
    }

    AST_Ptr resolveSimpleIds (const Environ* env) {
        if (_me == NULL) {
            gcstring name = as_string ();
            _me = env->find_immediate (name);
            if (_me == NULL) {
                error (this, "the type variable %s is undefined",
                       name.c_str ());
                _me = makeTypeVarDecl (name, this);
            }
        }
        return this;
    }

private:

    Decl* _me;

    int uid;
    static int next_uid;
};

NODE_FACTORY (TypeVar_AST, TYPE_VAR);
int TypeVar_AST::next_uid = 0;


/***** FUNCTION TYPES *****/

class FunctionType_AST: public Type {
public:

    gcstring getRuntimeName () {
        return "FuncDesc";
    }

protected:

    int numParams () {
        return child (1)->arity ();
    }

    Type_Ptr paramType (int k) {
        return child (1)->child (k)->asType ();
    }

    Type_Ptr returnType () {
        return child (0)->asType ();
    }

    bool checkBinding (Unwind_Stack& bindings) {
        Type_Ptr target = binding ();

        if (target->returnType () == NULL)
            return false;
        if (!returnType ()->unify (target->returnType (), bindings))
            return false;
        if (!unifyLists (child (1), target->child (1), bindings))
            return false;
        return true;
    }

    void collectTypeVarDecls (Decl* enclosing) {
        for_each_child(c, this) {
            c->collectTypeVarDecls (enclosing);
        } end_for;
    }

    NODE_CONSTRUCTORS (FunctionType_AST, Type);

};

NODE_FACTORY (FunctionType_AST, FUNCTION_TYPE);


/***** CLASSES *****/

class ClassType_AST: public Type {
public:

    gcstring getRuntimeName () {
        return getDecl ()->getRuntimeName ();
    }

protected:

    NODE_CONSTRUCTORS (ClassType_AST, Type);

    int numTypeParams () {
        return child(1)->arity();
    }

    Type_Ptr typeParam (int k) {
        int ar = child(1)->arity();
        if (k == -1 || k > ar)
            logic_error("invalid parameter index");
        return (Type_Ptr) child(1)->child(k);
    }

    AST_Ptr getId () {
        return child (0);
    }

    Decl* getDecl (int k = 0) {
        return getId ()->getDecl (k);
    }

    int numDecls () {
        return getId ()->numDecls ();
    }

    void addDecl (Decl* decl) {
        child (0)->addDecl (decl);
    }

    void collectTypeVarDecls (Decl* enclosing) {
        child (1)->collectTypeVarDecls (enclosing);
    }

    const Environ* getEnviron () {
        if (numDecls () == 1)
            return getDecl ()->getEnviron ();
        else
            return theEmptyEnviron;
    }

    void resolveSimpleTypeIds (const Environ* env) {
        Type::resolveSimpleTypeIds (env);
        if (getDecl () != NULL)
            return;
        gcstring name = getId ()->as_string ();
        Decl* decl = env->find (name);
        if (decl == NULL) {
            error (this, "undefined type: %s", name.c_str ());
            addDecl (makeUnknownDecl (name, true));
        } else if (!decl->isType ()) {
            error (this, "%s is not a type", name.c_str ());
            addDecl (makeUnknownDecl (name, true));
        } else {
            addDecl (decl);
        }
    }

};

NODE_FACTORY (ClassType_AST, TYPE);

/***** TYPE_LIST *****/

/** of [T1, ...]  */
class TypeList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (TypeList_AST, AST_Tree);

    void collectTypeVarDecls (Decl* enclosing) {
        for_each_child (c, this) {
            c->collectTypeVarDecls (enclosing);
        } end_for;
    }

};

NODE_FACTORY (TypeList_AST, TYPE_LIST);
