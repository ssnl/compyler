/* Implementations of declaration and type-related classes */

/* Authors:  YOUR NAMES HERE */
/* From a skeleton by Paul N. Hilfinger */

#include <stdexcept>
#include <map>
#include <sstream>
#include "apyc.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

/** These must be filled in with declarations from the standard
 *  prelude.  They are used to supply the types of built-in
 *  constructs.  All are initially NULL. */
Decl* intDecl;
Decl* listDecl;
Decl* tupleDecl[4];
Decl* strDecl;
Decl* dictDecl;
Decl* boolDecl;
Decl* fileDecl;
Decl* rangeDecl;

typedef gcmap<gcstring, Decl**> BuiltinMap;
static BuiltinMap builtinMap;

static struct { const char* name; Decl** var; } builtinInit[] = {
    { "int", &intDecl },
    { "list", &listDecl },
    { "tuple0", &tupleDecl[0] },
    { "tuple1", &tupleDecl[1] },
    { "tuple2", &tupleDecl[2] },
    { "tuple3", &tupleDecl[3] },
    { "str", &strDecl },
    { "dict", &dictDecl },
    { "bool", &boolDecl },
    { "file", &fileDecl },
    { "range", &rangeDecl },
    { NULL, NULL }
};



/** List of declarations corresponding to the module and actual
 *  declarations in the program (as opposed to type variables
 *  introduced by freshen). */
static gcvector<Decl*> allDecls;

Decl::Decl (const gcstring& name, Decl* container, Environ* members)
    : _frozen (true), _depth(-1), _name (name), _container (container),
      _members (members) {
    _index = allDecls.size ();
    allDecls.push_back (this);
    /* Allow name.c_str() to be used in the future without reallocation. */
    name.c_str ();
}

/* Print THIS on OUT. */
void
Decl::print (ostream& out) const
{
    out << "(" << declTypeName () << " " << getIndex ()
	<< " " << getName () << " ";
    printContainer (out);
    printPosition (out);
    printType (out);
    printTypeParams (out);
    printMembersList (out);
    out << ")";
    out.flush ();
}

void
Decl::print () const
{
    print (cout);
}

void
Decl::printContainer (ostream& out) const
{
    if (getContainer () != NULL)
        out << getContainer ()->getIndex () << " ";
    else
        out << "-1 ";
}

void
Decl:: printPosition (ostream& out) const {
}

void
Decl::printType (ostream& out) const {
}

void
Decl::printMembersList (ostream& out) const {
    if (_members != NULL) {
	out << " (index_list";
	const gcvector<Decl*>& members = getEnviron ()->get_members ();
	for (size_t i = 0; i < members.size (); i += 1)
	    out << " " << members[i]->getIndex ();
	out << ")";
    }
}

void
Decl::printTypeParams (ostream& out) const {
}

void
Decl::setupRuntimeName (gcmap<gcstring, int>& names) {
    gcstring originalName = getName ();
    int num = names[originalName]++;
    stringstream newName;
    newName << originalName << "_" << num << "$";
    _runtimeName = newName.str();
}

Type_Ptr
Decl::getType () const
{
    return NULL;
}

void
Decl::setType (Type_Ptr type)
{
}

gcstring
Decl::getRuntimeTypeName () const
{
    return "";
}

int
Decl::getPosition () const
{
    return -1;
}

AST_Ptr
Decl::getAst () const
{
    return _ast;
}

void
Decl::setAst (AST_Ptr ast)
{
    _ast = ast;
}

void
Decl::setNative (bool native)
{
    UNIMPLEMENTED (setNative);
}

bool
Decl::isType () const
{
    return false;
}

bool
Decl::isTypeVar () const
{
    return false;
}

bool
Decl::isNative () const
{
    return false;
}

bool
Decl::isInternal () const
{
    return false;
}

bool
Decl::isOverloadable () const
{
    return false;
}

bool
Decl::isMethod () const
{
    return false;
}

Type_Ptr
Decl::asType (int, Type_Ptr, Type_Ptr) const
{
    UNIMPLEMENTED (asType);
}

Type_Ptr
Decl::asType (int arity, Type_Ptr*) const
{
    UNIMPLEMENTED (asType);
}

Type_Ptr
Decl::asBaseType () const
{
    return NULL;
}

Type_Ptr
Decl::asGenericType ()
{
    UNIMPLEMENTED (asType);
}

int
Decl::getTypeArity () const
{
    return 0;
}

const Environ*
Decl::getEnviron () const
{
    if (_members == NULL)
	UNIMPLEMENTED (get_members);
    return _members;
}

void
Decl::addMember (Decl* new_member)
{
    if (_members == NULL)
	UNIMPLEMENTED (addMember);
    _members->define (new_member);
}

Decl*
Decl::newVarDecl (AST_Ptr) {
    UNIMPLEMENTED (newVarDecl);
}

Decl*
Decl::addVarDecl (AST_Ptr) {
    UNIMPLEMENTED (addVarDecl);
}

Decl*
Decl::addParamDecl (AST_Ptr id, int k) {
    gcstring name = id->as_string ();
    const Environ* env = getEnviron ();
    Decl* old = env->find_immediate (name);
    if (old != NULL) {
	error (id, "multiply defined formal parameter: %s",
	       name.c_str ());
	return old;
    }
    Decl* result = makeParamDecl (name, this, k, Type::makeVar ());
    addMember (result);
    return result;
}


Decl*
Decl::addTypeVarDecl (AST_Ptr id) {
    gcstring name = id->as_string ();
    const Environ* env = getEnviron ();
    Decl* old = env->find_immediate (name);
    if (old != NULL)
	return old;
    Decl* result = makeTypeVarDecl (name, id);
    addMember (result);
    return result;
}

Decl*
Decl::newDefDecl (AST_Ptr, int) {
    UNIMPLEMENTED (addDefDecl);
}

Decl*
Decl::addDefDecl (AST_Ptr id, int k) {
    Decl* decl = newDefDecl (id, k);
    Decl* old = getEnviron ()->find_immediate (id->as_string());
    if (old != NULL && !old->isOverloadable()) {
        error (id, "invalid attempt to overload %s",
               id->as_string().c_str());
    } else {
        addMember (decl);
    }
    return decl;
}

bool
Decl::assignable () const
{
    return false;
}

bool
Decl::isFrozen () const
{
    return _frozen;
}

void
Decl::setFrozen (bool freeze)
{
}

Decl::~Decl ()
{
}

const char*
Decl::declTypeName () const
{
    return "?";
}

/** The superclass of declarations that describe an entity with a type. */
class TypedDecl : public Decl {
protected:
    TypedDecl (const gcstring& name, Decl* container, AST_Ptr type,
	       Environ* members = NULL)
        :  Decl (name, container, members),
           _type (type == NULL ? NULL : type->asType ()) {
    }

public:

    Type_Ptr getType () const {
	if (isFrozen () || _type == NULL)
	    return _type;
	else
	    return _type->freshen ();
    }

    void setType (Type_Ptr type) {
        _type = type;
    }

    gcstring getRuntimeTypeName () const {
        return getType ()->getDecl ()->getRuntimeName ();
    }

protected:

    void printType (ostream& out) const {
        out << " ";
        if (_type != NULL) {
            _type->binding ()->print (cout, 0);
        } else
            out << "?";
    }

private:
    Type_Ptr _type;
};

class VarDecl : public TypedDecl {
public:

    VarDecl (const gcstring& name, Decl* container, AST_Ptr type)
        :  TypedDecl (name, container, type) {
    }

protected:

    const char* declTypeName () const {
        return "vardecl";
    }

    bool assignable () const {
	return true;
    }

};

Decl*
makeVarDecl (const gcstring& name, Decl* func, AST_Ptr type)
{
    return new VarDecl (name, func, type);
}


class ParamDecl : public TypedDecl {
public:

    ParamDecl (const gcstring& name, Decl* func, int k,
              AST_Ptr type)
        :  TypedDecl (name, func, type), _posn (k) {
    }

    int getPosition () const {
        return _posn;
    }

protected:

    const char* declTypeName () const {
        return "paramdecl";
    }

    void printPosition (ostream& out) const {
        out << " " << getPosition ();
    }

    bool assignable () const {
	return true;
    }

private:

    int _posn;

};

Decl*
makeParamDecl (const gcstring& name, Decl* func, int k, AST_Ptr type)
{
    return new ParamDecl (name, func, k, type);
}


class InstanceDecl : public TypedDecl {
public:

    InstanceDecl (const gcstring& name, Decl* cls, AST_Ptr type)
        :  TypedDecl (name, cls, type) {
    }

protected:

    const char* declTypeName () const {
        return "instancedecl";
    }

    bool assignable () const {
	return true;
    }

};

Decl*
makeInstanceDecl (const gcstring& name, Decl* cls, AST_Ptr type)
{
    return new InstanceDecl (name, cls, type);
}

class TypeVarDecl : public Decl {
public:

    TypeVarDecl (const gcstring& name, AST_Ptr canonical)
        :  Decl (name, NULL) {
	setAst (canonical);
    }

    bool isTypeVar () const {
        return true;
    }

protected:

    bool isInternal () const {
	return getAst () != NULL && getAst ()->arity () == 0;
    }

    void printContainer (ostream&) const {
    }

    const char* declTypeName () const {
        return "typevardecl";
    }

};

Decl*
makeTypeVarDecl (const gcstring& name, AST_Ptr typeVar)
{
    return new TypeVarDecl (name, typeVar);
}

class FuncDecl : public TypedDecl {
public:

    FuncDecl (const gcstring& name, Decl* container, AST_Ptr type,
              Environ* env)
        :  TypedDecl (name, container, type, env) {
    }

protected:

    bool isOverloadable () const {
        return true;
    }

    const char* declTypeName () const {
        return "funcdecl";
    }

    void setFrozen (bool freeze) {
        _frozen = freeze;
    }

    void setNative (bool native) {
        _native = native;
    }

    bool isNative () const {
        return _native;
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeVarDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* newDefDecl (AST_Ptr id, int k) {
	return makeFuncDecl (id->as_string (), this, makeFuncType (k));
    }
private:

    bool _native;
};

Decl*
makeFuncDecl (const gcstring& name, Decl* container, AST_Ptr type)
{
    return new FuncDecl (name, container, type,
			 new Environ (container->getEnviron ()));
}

class MethodDecl : public FuncDecl {
public:

    MethodDecl (const gcstring& name, Decl* container, AST_Ptr type)
        :  FuncDecl (name, container, type,
		     new Environ (container->getEnviron ()->get_enclosure ())) {
    }

protected:

    bool isMethod () const {
	return true;
    }

};

Decl*
makeMethodDecl (const gcstring& name, Decl* cls, AST_Ptr type)
{
    return new MethodDecl (name, cls, type);
}

class ClassDecl : public Decl {
public:

    ClassDecl (const gcstring& name, AST_Ptr params)
        : Decl (name, NULL, new Environ (outerEnviron)), _params (params) {
    }

protected:

    bool isType () const {
	return true;
    }

    void printContainer (ostream&) const {
    }

    void printTypeParams (ostream& out) const {
        out << " (index_list";
	for_each_child (c, _params) {
	    Decl* decl = c->getDecl ();
	    if (decl == NULL)
		out << " ?";
	    else
		out << " " << decl->getIndex ();
	} end_for;
	out << ")";
    }

    const char* declTypeName () const {
        return "classdecl";
    }

    Type_Ptr asType (int arity, Type_Ptr* params0) const {
        AST_Ptr* params = (AST_Ptr*) params0;
        if (getTypeArity () != -1 && getTypeArity () != arity) {
	    throw range_error ("wrong number of type parameters");
        }
        for (int i = 0; i < arity; i += 1)
            if (params[i] == NULL)
                throw domain_error ("attempt to pass null type parameter");

	AST_Ptr id = make_id (getName ().c_str (), NULL);
	id->addDecl (const_cast<ClassDecl*> (this));

        return consTree (TYPE, id,
			 AST::make_tree (TYPE_LIST, params, params+arity))
            ->asType ();
    }

    Type_Ptr asType (int arity, Type_Ptr t0, Type_Ptr t1) const {
        gcvector<Type_Ptr> params;
        params.push_back (t0); params.push_back (t1);
        return asType (arity, &params[0]);
    }

    Type_Ptr asBaseType () const {
        gcvector<Type_Ptr> params;
        for (size_t i = 0; i < _params->arity (); i += 1) {
            params.push_back (_params->child (i)->asType ());
        }
        return asType (getTypeArity (), &params[0]);
    }

    Type_Ptr asGenericType () {
        gcvector<Type_Ptr> params;
        for (int i = 0; i < getTypeArity (); i += 1) {
            params.push_back (Type::makeVar ());
        }
        return asType (getTypeArity (), &params[0]);
    }


    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeInstanceDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* newDefDecl (AST_Ptr id, int k) {
	return makeMethodDecl (id->as_string (), this, makeMethodType (k, this));
    }

    Decl* addTypeVarDecl (AST_Ptr id) {
	gcstring name = id->as_string ();
	Decl* prev = getEnviron ()->find_immediate (name);
	if (prev != NULL)
	    return prev;
	Decl* decl = makeTypeVarDecl (name, id);
	addMember (decl);
	return decl;
    }

    int getTypeArity () const {
	return _params->arity ();
    }

    AST_Ptr _params;
};

Decl*
makeClassDecl (const gcstring& name, AST_Ptr params)
{
    return new ClassDecl (name, params);
}

class ModuleDecl : public Decl {
public:

    ModuleDecl (const gcstring& name)
        :  Decl (name, NULL, new Environ (NULL)) {
    }

protected:

    const char* declTypeName () const {
        return "moduledecl";
    }

    void printContainer (ostream& os) const {
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeVarDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* newDefDecl (AST_Ptr id, int k) {
	return makeFuncDecl (id->as_string (), this, makeFuncType (k));
    }

};

Decl*
makeModuleDecl (const gcstring& name)
{
    return new ModuleDecl (name);
}

class UnknownDecl : public Decl {
public:

    UnknownDecl (const gcstring& name, bool isType)
        :  Decl (name, mainModule, new Environ (NULL)), _isType (isType) {
        if (!isType)
            _dummyType = Type::makeVar ();
    }

protected:

    bool isType () const {
        return _isType;
    }

    Type_Ptr getType () const {
        return _dummyType;
    }

private:
    Type_Ptr _dummyType;
    const bool _isType;
};

Decl*
makeUnknownDecl (const gcstring& name, bool isType)
{
    return new UnknownDecl (name, isType);
}


bool
undefinable (const gcstring& name)
{
    return name == gcstring("None");
}

void
setBuiltinDecl (Decl* decl)
{
    if (builtinMap.size () == 0) {
        for (int i = 0; builtinInit[i].name != NULL; i += 1) {
            builtinMap[builtinInit[i].name] = builtinInit[i].var;
        }
    }

    BuiltinMap::const_iterator entryPair = builtinMap.find (decl->getName ());
    if (entryPair != builtinMap.end ()) {
        if (*entryPair->second != NULL) {
            throw logic_error (string("multiple definition of builtin class ")
                               + decl->getName ().c_str());
        }
        *entryPair->second = decl;
    }
}

void
outputDecls (ostream& out)
{
    for (size_t i = 0; i < allDecls.size (); i += 1) {
	if (!allDecls[i]->isInternal ()) {
	    allDecls[i]->print (out);
	    out << endl;
	}
    }
}
