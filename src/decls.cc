/* Implementations of declaration and type-related classes */

/* Authors:  YOUR NAMES HERE */
/* From a skeleton by Paul N. Hilfinger */

#include <stdexcept>
#include "apyc.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

/** Names of built-int constants used to fill in the primitive map below. */
const gcstring Int = "int";
const gcstring List = "list";
const gcstring Tuple = "tuple";
const gcstring Tuple0 = "tuple0";
const gcstring Tuple1 = "tuple1";
const gcstring Tuple2 = "tuple2";
const gcstring Tuple3 = "tuple3";
const gcstring Str = "str";
const gcstring Dict = "dict";
const gcstring Bool = "bool";
const gcstring File = "file";
const gcstring Range = "range";

/** This map is filled in with (name, declaration) pairs
 *  from the standard prelude. They are used to supply the types
 *  of built-int constructs. */
static Decl_Map initializeMap() {
    Decl_Map r;
    r[Int] = NULL;
    r[List] = NULL;
    r[Tuple0] = NULL;
    r[Tuple1] = NULL;
    r[Tuple2] = NULL;
    r[Tuple3] = NULL;
    r[Str] = NULL;
    r[Dict] = NULL;
    r[Bool] = NULL;
    r[File] = NULL;
    r[Range] = NULL;
    return r;
}
Decl_Map primitiveDecls = initializeMap();

/** List of declarations corresponding to the module and actual
 *  declarations in the program (as opposed to type variables
 *  introduced by freshen). */
static gcvector<Decl*> allDecls;

Decl::Decl (const gcstring& name, Decl* container, Environ* members)
    : _frozen (true), _name (name), _container (container),
      _members (members) {
    _index = allDecls.size ();
    allDecls.push_back (this);
    /* Allow name.c_str() to be used in the future without reallocation. */
    name.c_str ();
}

/* Print THIS on the standard output. */
void
Decl::print () const
{
    printf ("(%s %d %s ", declTypeName (),
            getIndex (), getName().c_str ());
    printContainer ();
    printPosition ();
    printType ();
    printTypeParams ();
    printMembersList ();
    printf (")");
    fflush (stdout);
}

void
Decl::printContainer () const
{
    if (getContainer () != NULL)
        printf ("%d ", getContainer ()->getIndex ());
    else
        printf ("-1 ");
}

void
Decl:: printPosition () const {
}

void
Decl::printType () const {
}

void
Decl::printMembersList () const {
    if (_members != NULL) {
	printf (" (index_list");
	const gcvector<Decl*>& members = getEnviron ()->get_members ();
	for (size_t i = 0; i < members.size (); i += 1)
	    printf (" %d", members[i]->getIndex ());
	printf (")");
    }
}

void
Decl::printTypeParams () const {
}

Type_Ptr
Decl::getType () const
{
    return NULL;
}

void
Decl::setType (Type_Ptr type) {}

Type_Ptr
Decl::getTypeInternal (int k) const {
    return NULL;
}

int
Decl::getNumTypesInternal () const {
    return -1;
}

void
Decl::addTypeInternal (Type_Ptr type) {}

void
Decl::removeTypeInternal(int k) {}


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

bool
Decl::isType () const
{
    return false;
}

bool
Decl::isInternal () const
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
Decl::addVarDecl (AST_Ptr) {
    UNIMPLEMENTED (addVarDecl);
}

Decl*
Decl::addDefDecl (AST_Ptr) {
    UNIMPLEMENTED (addDefDecl);
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

    Type_Ptr getTypeInternal (int k) const {
        return _type_vector[k];
    }

    int getNumTypesInternal () const {
        return _type_vector.size();
    }

    void addTypeInternal (Type_Ptr type) {
        return _type_vector.push_back(type);
    }

    void removeTypeInternal(int k) {
        _type_vector.erase(_type_vector.begin() + k);
    }

protected:

    void printType () const {
        printf (" ");
        if (_type != NULL) {
            _type->binding ()->print (cout, 0);
        } else
            printf ("?");
    }

private:
    Type_Ptr _type;
    Type_Ptr_Vector _type_vector;
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

    void printPosition () const {
        printf (" %d", getPosition ());
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

protected:

    bool isInternal () const {
	return getAst () != NULL && getAst ()->arity () == 0;
    }

    void printContainer () const {
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

    const char* declTypeName () const {
        return "funcdecl";
    }

    void setFrozen (bool freeze) {
        _frozen = freeze;
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeVarDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* addDefDecl (AST_Ptr id) {
	Decl* decl = makeFuncDecl (id->as_string (), this, NULL);
	addMember (decl);
	return decl;
    }
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
        : Decl (name, NULL, new Environ (outer_environ)), _params (params) {
    }

protected:

    bool isType () const {
	return true;
    }

    void printContainer () const {
    }

    void printTypeParams () const {
        printf (" (index_list");
	for_each_child (c, _params) {
	    Decl* decl = c->getDecl ();
	    if (decl == NULL)
		printf (" ?");
	    else
		printf (" %d", decl->getIndex ());
	} end_for;
	printf (")");
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
        Type_Ptr params[] = { t0, t1 };
        return asType (arity, params);
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeInstanceDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* addDefDecl (AST_Ptr id) {
	Decl* decl = makeMethodDecl (id->as_string (), this, NULL);
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

    void printContainer () const {
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeVarDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* addDefDecl (AST_Ptr id) {
	Decl* decl = makeFuncDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

};

Decl*
makeModuleDecl (const gcstring& name)
{
    return new ModuleDecl (name);
}

bool
undefinable (const gcstring& name)
{
    return name == "None";
}

void
outputDecls ()
{
    for (size_t i = 0; i < allDecls.size (); i += 1) {
	if (!allDecls[i]->isInternal ()) {
	    allDecls[i]->print ();
	    printf ("\n");
	}
    }
}
