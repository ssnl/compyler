/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* exprs.cc: AST subclasses related to expressions. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

/*****   Typed_Tree   *****/

Type_Ptr
Typed_Tree::getType ()
{
    if (_type == NULL)
        _type = computeType ();
    return _type;
}

bool
Typed_Tree::setType (Type_Ptr type)
{
    if (_type == NULL) {
        _type = type;
        return true;
    } else return _type->unify (type);
}

AST_Ptr
Typed_Tree::resolveTypes (Decl* context, int& resolved, int& ambiguities)
{
    AST_Tree::resolveTypes (context, resolved, ambiguities);
    getType ();
    return this;
}

Type_Ptr
Typed_Tree::computeType ()
{
    return Type::makeVar ();
}

/*****   EXPR_LIST    *****/

/** A list of expressions. */
class Expr_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Expr_List_AST, AST_Tree);

    void exprCodeGen (int depth) {
        for_each_child_reverse (c, this) {
            c->exprCodeGen (depth);
        } end_for;
    }

};

NODE_FACTORY (Expr_List_AST, EXPR_LIST);


/*****   CALLS    *****/

/** The supertype of "callable" things, including ordinary calls,
 *  binary operators, unary operators, subscriptions, and slices. */

class Callable : public Typed_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Callable, Typed_Tree);

    /** Returns the expression representing the quantity that is
     *  called to evaluate this expression. */
    virtual AST_Ptr calledExpr () = 0;

    /** Returns the number of actual parameters in this call. */
    virtual int numActuals () = 0;

    /** Return the Kth actual parameter in this call. */
    virtual AST_Ptr actualParam (int k) = 0;

    /** Set the Kth actual parameter in this call to EXPR. */
    virtual void setActual (int k, AST_Ptr expr) = 0;

public:

    Type_Ptr computeType () {
        return calledExpr ()->getType ()->binding ()->returnType ();
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        Type_Ptr funcType;
        funcType = calledExpr ()->getType ()->binding ();

        if (!makeFuncType (numActuals (), funcType)) {
            error (this,
                   "called object is not a %d-parameter function",
                   numActuals ());
            return this;
        }

        if (!setType (computeType ())) {
            error (this, "inappropriate function return type");
            return this;
        }

        funcType = funcType->binding ();
        if (funcType->numParams () != numActuals ()) {
            error (this, "wrong number of parameters to function");
            return this;
        }
        for (int i = 0; i < numActuals (); i += 1) {
            if (!actualParam (i)->getType ()->unify (funcType->paramType (i))) {
                error (this, "non-matching parameter type (parameter #%d)",
                       i);
                break;
            }
        }
        return this;
    }

};

/** A function call. */
class Call_AST : public Callable {
protected:

    NODE_CONSTRUCTORS (Call_AST, Callable);

    AST_Ptr calledExpr () {
        return child (0);
    }

    int numActuals () {
        return child (1)->arity ();
    }

    AST_Ptr actualParam (int k) {
        return child (1)->child (k);
    }

    void setActual (int k, AST_Ptr expr) {
        child (1)->replace (k, expr);
    }

    AST_Ptr resolveAllocators (const Environ* env) {
        Callable::resolveAllocators (env);
        AST_Ptr callable = calledExpr ();
        if (callable->isType ()) {
            gcvector<AST_Ptr> initArgs;
            initArgs.push_back (consTree (NEW, callable));
            for (int i = 0; i < numActuals (); i += 1)
                initArgs.push_back (actualParam (i));

            AST_Ptr init = consTree(ATTRIBUTEREF, callable,
                                    make_id ("__init__", loc ()));
            return consTree (CALL1, init,
                             AST::make_tree (EXPR_LIST,
                                             &initArgs[0],
                                             &initArgs[initArgs.size ()]));
        }
        return this;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        replace (0, child (0)->resolveTypes (context, resolved, ambiguities));
        AST_Ptr call = child (0)->convertMethodCall (child (1));
        if (call == NULL)
            return Callable::resolveTypes (context, resolved, ambiguities);
        else
            return dynamic_cast<Callable*>(call)
                ->Callable::resolveTypes (context, resolved, ambiguities);
    }

};

NODE_FACTORY (Call_AST, CALL);

/***** CALL1 *****/

/** __init__(new T, ...)      */
class Call1_AST : public Call_AST {
protected:

    NODE_CONSTRUCTORS (Call1_AST, Call_AST);

    Type_Ptr computeType () {
        return calledExpr ()->getType ()->binding ()->paramType (0);
    }

};

NODE_FACTORY (Call1_AST, CALL1);

/***** NEW *****/

/**  new T     */
class New_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (New_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        if (!setType (child (0)->asType ())) {
            error (this, "inconsistent types");
        }
        return this;
    }

};

NODE_FACTORY (New_AST, NEW);


/** A binary operator. */
class Binop_AST : public Callable {
protected:

    NODE_CONSTRUCTORS (Binop_AST, Callable);

    AST_Ptr calledExpr () {
        return child (3);
    }

    int numActuals () {
        return 2;
    }

    AST_Ptr actualParam (int k) {
        return child(k * 2);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k, expr);
    }

};

NODE_FACTORY (Binop_AST, BINOP);

/***** COMPARE *****/

/** A comparison yielding bool */
class Compare_AST : public Binop_AST {
protected:

    NODE_CONSTRUCTORS (Compare_AST, Binop_AST);

    Type_Ptr computeType () {
        return boolDecl->asType ();
    }

};

NODE_FACTORY (Compare_AST, COMPARE);



/***** LEFT_COMPARE *****/

/** A comparison yielding its second operand's type. */
class LeftCompare_AST : public Binop_AST {
protected:

    NODE_CONSTRUCTORS (LeftCompare_AST, Binop_AST);

    Type_Ptr computeType () {
        return actualParam (1)->getType ();
    }

};

NODE_FACTORY (LeftCompare_AST, LEFT_COMPARE);


/** A unary operator. */
class Unop_AST : public Callable {

    NODE_CONSTRUCTORS (Unop_AST, Callable);

    AST_Ptr calledExpr () {
        return child (2);
    }

    int numActuals () {
        return 1;
    }

    AST_Ptr actualParam (int k) {
        return child(2*k + 1);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k + 1, expr);
    }

};

NODE_FACTORY (Unop_AST, UNOP);


/***** SUBSCRIPTION *****/

/** E1[E2] */
class Subscription_AST : public Callable {
protected:

    NODE_CONSTRUCTORS (Subscription_AST, Callable);

    int numActuals () {
        return 2;
    }

    AST_Ptr actualParam (int k) {
        return child (k);
    }

    AST_Ptr calledExpr () {
        return child (2);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (k, expr);
    }

    void addTargetDecls (Decl* enclosing) {
    }

};

NODE_FACTORY (Subscription_AST, SUBSCRIPTION);


/***** SLICING *****/

/** E1[E2:E3] */
class Slicing_AST : public Callable {
protected:

    NODE_CONSTRUCTORS (Slicing_AST, Callable);

    int numActuals () {
        return 3;
    }

    AST_Ptr actualParam (int k) {
        return child (k);
    }

    AST_Ptr calledExpr () {
        return child (3);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (k, expr);
    }

    void addTargetDecls (Decl* enclosing) {
    }

};

NODE_FACTORY (Slicing_AST, SLICING);


/***** EMPTY_INTEGER *****/

/** Empty integer argument (to a slice) */
class EmptyInteger_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (EmptyInteger_AST, Typed_Tree);

    /** Override AST_Tree::_print */
    void _print (ostream& out, int indent) {
        out << "()";
    }

    bool isMissing () {
        return true;
    }

    Type_Ptr computeType () {
        return intDecl->asType ();
    }

};

NODE_FACTORY (EmptyInteger_AST, EMPTY_INTEGER);




/***** ATTRIBUTEREF *****/

/** E.ID */
class AttributeRef_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (AttributeRef_AST, Typed_Tree);

    AST_Ptr getId () {
        return child (1);
    }

    Decl* getDecl (int k = 0) {
        return getId ()->getDecl (k);
    }

    int numDecls () {
        return getId ()->numDecls ();
    }

    void addTargetDecls (Decl* enclosing) {
    }

    AST_Ptr resolveStaticSelections (const Environ* env) {
        AST_Ptr left = child (0)->resolveStaticSelections (env);
        if (!left->isType ())
            return this;
        AST_Ptr id = getId ();
        if (id->getDecl () != NULL)
            return id;
        gcstring name = id->as_string ();
        const Environ* members = left->getDecl ()->getEnviron ();
        Decl_Vector defns;
        members->find_immediate (name, defns);
        if (defns.empty ()) {
            error (this, "no definition of %s in type", name.c_str ());
            id->addDecl (makeUnknownDecl (name, false));
        }
        for (size_t i = 0; i < defns.size (); i += 1)
            id->addDecl (defns[i]);
        return id;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        AST_Ptr id = getId ();
        gcstring name = id->as_string ();
        int errs0 = numErrors ();
        replace (0, child (0)->resolveTypes (context));
        if (errs0 == numErrors ()) {
            id->resolveSelectedType (child (0)->getType (),
                                     resolved, ambiguities);
        } else if (id->numDecls () == 0) {
            id->addDecl (makeUnknownDecl (name, false));
        }

        if (!setType (id->getType ()))
            error (this,
                   "attribute %s has no definition that fits the context.",
                   name.c_str ());
        return this;
    }

    AST_Ptr convertMethodCall (AST_Ptr args) {
        AST_Ptr id = getId ();
        if (id->numDecls () > 0 && id->getDecl ()->isMethod ())
            return consTree (CALL, id, args->insert (0, child (0)));
        else
            return NULL;
    }

    AST_Ptr resolveSimpleIds (const Environ* env) {
        replace (0, child (0)->resolveSimpleIds (env));
        return this;
    }

    void checkNoBoundMethodValues () {
        child (0)->checkNoBoundMethodValues ();
        if (getDecl () != NULL && getDecl ()->isMethod ())
            error (this, "bound method value outside a call");
    }

};

NODE_FACTORY (AttributeRef_AST, ATTRIBUTEREF);

/***** TUPLE *****/

/** (E1, ...)  */
class Tuple_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (Tuple_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        if (arity () > 3)
            error (this, "tuple has too many elements (max 3)");
        Type_Ptr componentTypes[3];
        for (size_t i = 0; i < arity (); i += 1)
            componentTypes[i] = child (i)->getType ();
        Type_Ptr tupleType =
            tupleDecl[arity ()]->asType (arity (), componentTypes);
        if (!setType (tupleType))
            error (this, "type mismatch on tuple");
        return this;
    }

    void exprCodeGen(int depth) {
        for_each_child_reverse(c, this) {
            c->exprCodeGen(depth);
        } end_for;
        stringstream ss;
        ss << "__tuple" << arity() << "__";
        VM->emit(NTV, ss.str(), arity());
    }

};

NODE_FACTORY (Tuple_AST, TUPLE);

/***** TARGET_LIST *****/

/** (TARGET, ...) on left-hand side of assignment, for. */
class TargetList_AST : public Tuple_AST {
protected:

    NODE_CONSTRUCTORS (TargetList_AST, Tuple_AST);

    void addTargetDecls (Decl* enclosing) {
        for_each_child (c, this) {
            c->addTargetDecls (enclosing);
        } end_for;
    }

    bool isTargetList () {
        return true;
    }

    AST_Ptr convertNone (bool) {
        for_each_child_var (c, this) {
            c = c->convertNone (true);
        } end_for;
        return this;
    }

};

NODE_FACTORY (TargetList_AST, TARGET_LIST);


/***** LIST_DISPLAY *****/

/** [E1, ...]  */
class ListDisplay_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (ListDisplay_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        Type_Ptr componentType;
        if (arity () == 0)
            componentType = Type::makeVar ();
        else
            componentType = child (0)->getType ();
        for (size_t i = 1; i < arity (); i += 1)
            if (!componentType->unify (child (i)->getType ())) {
                error (child (i), "type mismatch in list display");
                break;
            }
        Type_Ptr listType =
            listDecl->asType (1, componentType);
        if (!setType (listType))
            error (this, "type mismatch on list display");
        return this;
    }

};

NODE_FACTORY (ListDisplay_AST, LIST_DISPLAY);


/***** DICT_DISPLAY *****/

/**       */
class DictDisplay_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (DictDisplay_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        Type_Ptr keyType, valType;
        if (arity () == 0) {
            keyType = Type::makeVar ();
            valType = Type::makeVar ();
        } else  {
            keyType = child (0)->child (0)->getType ();
            valType = child (0)->child (1)->getType ();
        }
        for (size_t i = 1; i < arity (); i += 1) {
            if (!keyType->unify (child (i)->child (0)->getType ())) {
                error (child (i), "key type mismatch in dict display");
                break;
            }
            if (!valType->unify (child (i)->child (1)->getType ())) {
                error (child (i), "value type mismatch in dict display");
                break;
            }
        }
        Type_Ptr dictType =
            dictDecl->asType (2, keyType, valType);
        if (!setType (dictType))
            error (this, "type mismatch on dict display");
        return this;
    }

};

NODE_FACTORY (DictDisplay_AST, DICT_DISPLAY);



/** A class of expression in which its subexpressions must agree as to
 *  type and its value's type is that of its subexpressios. */
class BalancedExpr : public Typed_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (BalancedExpr, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        int k = arity ();
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        if (!child (k - 2)->getType ()->unify (child (k - 1)->getType ()))
            error (this, "types of alternatives do not match");
        if (!setType (child (k - 1)->getType ()))
            error (loc (), "inconsistent types");
        return this;
    }

};

/***** IF_EXPR *****/

/**  E1 if Cond else E2  */
class IfExpr_AST : public BalancedExpr {
protected:

    NODE_CONSTRUCTORS (IfExpr_AST, BalancedExpr);

};


NODE_FACTORY (IfExpr_AST, IF_EXPR);

/***** AND *****/

/** E1 and E2 */
class And_AST : public BalancedExpr {
protected:

    NODE_CONSTRUCTORS (And_AST, BalancedExpr);

};

NODE_FACTORY (And_AST, AND);

/***** OR *****/

/** E1 or E2 */
class Or_AST : public BalancedExpr {
protected:

    NODE_CONSTRUCTORS (Or_AST, BalancedExpr);

};

NODE_FACTORY (Or_AST, OR);


