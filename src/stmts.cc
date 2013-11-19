/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* stmts.cc: AST subclasses related to statements and modules. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

class Region_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Region_AST, AST_Tree);

    /** By default, a Suite AST_Tree does not do anything
     *  collecting declarations. Will be overloaded by trees
     *  that will actually add appropriate declarations to
     *  ENCLOSING. */
    void collectDecls(Decl* enclosing) {
        // do nothing
    }

    /** Simple overloading that makes it easy to associate
     *  Suite AST_Tree's with a corresponding declaration. */
    Decl* getDecl(int k = 0) {
        return _me;
    }

    void addDecl(Decl* decl) {
        _me = decl;
    }

private:

    Decl *_me;
};

/*****   ASSIGN   *****/
class Assign_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Assign_AST, AST_Tree);

    void collectDecls (Decl* enclosing) {
        // Specify that left hand side is a target
        child(0)->addTargetDecls(enclosing);
        // Recursively collect declarations from right hand side
        child(1)->collectDecls(enclosing);
    }

    Type_Ptr getType() {
        return child(1)->getType();
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities,
                          bool& errors) {
        // Perform type inference on children
        for_each_child_var (c, this) {
            c = c->resolveTypes(context, resolved, ambiguities, errors);
        } end_for;
        // Unification step
        Unwind_Stack unwind_stack;
        Type_Ptr left = child(0)->getType();
        Type_Ptr right = child(1)->getType();
        if (left != NULL) {
            // Single target: unify
            left->unify(right, unwind_stack);
        } else {
            // Multiple targets: check if RHS is tuple or list
            gcstring rightName = right->as_string();
            if (rightName.substr(0, rightName.length() - 1) == Tuple) {
                if (child(0)->arity() ==  right->numParams())
                    error(loc(), "type error: too many values to unpack");
                for_each_child (c, child(0)) {
                    c->getType()->unify(right->typeParam(c_i_), unwind_stack);
                } end_for;
            } else if (rightName == List) {
                Type_Ptr type = right->typeParam(0);
                for_each_child (c, child(0)) {
                    c->getType()->unify(type, unwind_stack);
                } end_for;
            } else {
                error(loc(), "type error: '%s' object is not iterable",
                    rightName.c_str());
            }
        }
        return this;
    }
};

NODE_FACTORY (Assign_AST, ASSIGN);

/***** STMT_LIST *****/

/** A list of statements. */
class StmtList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (StmtList_AST, AST_Tree);

    AST_Ptr doInnerSemantics () {
        for_each_child_var (c, this) {
            c = c->doInnerSemantics ();
        } end_for;
        return this;
    }
};

NODE_FACTORY (StmtList_AST, STMT_LIST);

/*****   PRINTING   *****/
class Printing_AST : public AST_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Printing_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        for_each_child_var (c, this) {
            c = c->resolveTypes (context, resolved, ambiguities, errors);
        } end_for;
        Unwind_Stack unwind_stack;
        if (!child(0)->isMissing()) {
            child(0)->getType()->unify(primitiveDecls[File]->asType(),
                unwind_stack);
        }
        return this;
    }
};

/*****   PRINT   *****/
/** A print statement with trailing comma. */
class Print_AST : public Printing_AST {
protected:

    NODE_CONSTRUCTORS (Print_AST, Printing_AST);
};

NODE_FACTORY (Print_AST, PRINT);

/*****   PRINTLN   *****/
/** A print statement without trailing comma. */
class Println_AST : public Printing_AST {
protected:

    NODE_CONSTRUCTORS (Println_AST, Printing_AST);

    const char* externalName () {
        return "println";
    }
};

NODE_FACTORY (Println_AST, PRINTLN);

/*****   FOR   *****/
class For_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (For_AST, AST_Tree);

    void collectDecls (Decl* enclosing) {
        // Add declarations for variable in head
        child(0)->addTargetDecls(enclosing);
        // Recursively collect declarations for body
        child(1)->collectDecls(enclosing);
        child(2)->collectDecls(enclosing);
        child(3)->collectDecls(enclosing);
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        for_each_child_var (c, this) {
            c = c->resolveTypes (context, resolved, ambiguities, errors);
        } end_for;
        bool success = false;
        Unwind_Stack unwind_stack;
        Type_Ptr left = child(0)->getType();
        Type_Ptr right = child(1)->getType();
        gcstring leftName = left->as_string();
        gcstring rightName = right->as_string();

        if (rightName != List && rightName != Range && rightName != Str)
            error(loc(),
                "type error: '%s' object is not an iterable",
                rightName.c_str());
        if (rightName == List) {
            success = left->unify(right->typeParam(0), unwind_stack);
            if (!success)
                error(loc(),
                    "type error: type of '%s' does not match list type",
                    leftName.c_str());
        } else if (rightName == Range && leftName != Int) {
            error(loc(), "type error: type of '%s' must be int",
                leftName.c_str());
        } else if (rightName == Str && leftName != Str) {
            error(loc(), "type error: type of '%s' must be str",
                leftName.c_str());
        }
        return this;
    }
};

NODE_FACTORY (For_AST, FOR);

/*****   DEF   *****/
class Def_AST : public Region_AST {
protected:

    NODE_CONSTRUCTORS (Def_AST, Region_AST);

    virtual Environ* setupEnviron () {
        return new Environ(curr_environ);
    }

    AST_Ptr doInnerSemantics () {
        Decl *decl = getDecl();
        Environ* prev_environ = curr_environ;
        curr_environ = setupEnviron();
        // Collect and resolve formals
        child(1)->collectDecls(decl);
        child(1)->resolveSimpleIds(curr_environ);
        // Collect and resolve return type
        child(2)->collectDecls(decl);
        child(2)->resolveSimpleIds(curr_environ);
        // Collect and resolve function body
        for_each_child (c, child(3)) {
            c->collectDecls(decl);
            c->resolveSimpleIds(curr_environ);
        } end_for;
        // Recursively do inner semantic analysis on function body
        child(3)->doInnerSemantics();
        // Change type from a ordinary type to a function_type
        _fixType();
        curr_environ = prev_environ;
        return this;
    }

    void _fixType() {
        Decl *decl = getDecl();
        // Set the return type
        AST_Ptr returntype = Type::makeVar();
        // Set the type_list of param types
        AST_Ptr typelist = consTree(TYPE_LIST);
        int arity = child(1)->arity();
        if (arity > 0) {
            AST_Ptr *args = new AST_Ptr[arity];
            for (int i = 0; i < arity; i++) {
                args[i] = Type::makeVar();
            }
            typelist = make_tree(TYPE_LIST, args, args + arity);
        }
        // Make a new function type AST
        AST_Ptr functype = consTree(FUNCTION_TYPE, returntype, typelist);
        // Set decl's type to the type AST
        decl->setType(functype->asType());
    }

    void collectDecls (Decl* enclosing) {
        Decl* decl = enclosing->addDefDecl(child(0));
        curr_environ->define(decl);
        addDecl(decl);
    }

    void resolveSimpleIds (const Environ* env) {
        child(0)->resolveSimpleIds(env);
    }

    AST_Ptr rewriteSimpleTypes (const Environ* unused) {
        const Environ *env = getDecl()->getEnviron();
        for_each_child_var (c, this) {
            if (c_i_ != 0) {
                c = c->rewriteSimpleTypes(env);
            }
        } end_for;
        return this;
    }

    AST_Ptr _setupSelf(Decl* context, int& resolved,
                          int& ambiguities,  bool& errors) {}

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities,  bool& errors) {
        Decl* decl = getDecl();
        AST_Ptr me = this;
        // Resolve formal params
        for_each_child_var (c, me->child(1)) {
            c = c->resolveTypes(decl, resolved, ambiguities, errors);
        } end_for;
        // Resolve function body
        for_each_child_var (c, me->child(3)) {
            c = c->resolveTypesOuter(decl);
        } end_for;
        Unwind_Stack unwind_stack;
        Type_Ptr functype = decl->getType();
        // Unify self (if required)
        me = _setupSelf(context, resolved, ambiguities, errors);
        // Unify parameters with formals list
        for_each_child (c, me->child(1)) {
            c->getType()->unify(functype->paramType(c_i_), unwind_stack);
        } end_for;
        // Unify return type
        Type_Ptr returnType = functype->returnType();
        bool noReturn = returnType->binding() == returnType;
        if (noReturn) {
            // If there is no function return parameter
            if (me->child(2)->isMissing()) {
                Decl* nonedecl = outer_environ->find("__None__");
                Type_Ptr nonetype = nonedecl->getType()->returnType();
                returnType->unify(nonetype,unwind_stack);
            // Otherwise, there should be a return parameter
            } else {
                error(loc(), "type error: expected function %s to return a value",
                    me->child(0)->as_token()->as_string().c_str());
            }
        } else {
            // If there is a function return parameter
            if (!me->child(2)->isMissing())
                returnType->unify(me->child(2)->asType(), unwind_stack);
        }
        return me;
    }
};

NODE_FACTORY (Def_AST, DEF);

/*****   METHOD   *****/

class Method_AST : public Def_AST {
protected:

    NODE_CONSTRUCTORS (Method_AST, Def_AST);

    Environ* setupEnviron () {
        return new Environ(curr_environ->get_enclosure());
    }

    AST_Ptr _setupSelf(Decl* context, int& resolved,
                          int& ambiguities,  bool& errors) {
        Unwind_Stack unwind_stack;
        Type_Ptr classType = context->getType();
        child(0)->getType()->unify(classType, unwind_stack);
        return this;
    }
};

NODE_FACTORY (Method_AST, METHOD);


/*****   CLASS   *****/
class Class_AST : public Region_AST {
protected:

    NODE_CONSTRUCTORS (Class_AST, Region_AST);

    AST_Ptr doInnerSemantics () {
        Decl* decl = getDecl();
        Environ* prev_environ = curr_environ;
        curr_environ = new Environ(curr_environ);
        // Collect and resolve class type parameters
        child(1)->collectDecls(decl);
        child(1)->resolveSimpleIds(curr_environ);
        // Collect and resolve class body
        for_each_child (c, child(2)) {
            c->collectDecls(decl);
            c->resolveSimpleIds(curr_environ);
        } end_for;
        // Recursively do inner semantic analysis on class body
        child(2)->doInnerSemantics();
        // Add an __init__ method if required
        _rewriteInit();
        curr_environ = prev_environ;
        return this;
    }

    void _rewriteInit () {
        Decl* decl = getDecl();
        Decl* init = decl->getEnviron()->find_immediate("__init__");
        if (init == NULL) {
            // Create AST for init
            AST_Ptr id = make_token(ID, 8, "__init__");
            AST_Ptr formals = consTree(FORMALS_LIST, make_token(ID, 4, "self"));
            AST_Ptr type = consTree(EMPTY);
            AST_Ptr block = consTree(BLOCK, consTree(STMT_LIST));
            AST_Ptr init = consTree(METHOD, id, formals, type, block);
            // Add AST class body
            child(2)->insert(0, init);
            // Collect and resolve
            init->collectDecls(decl);
            init->resolveSimpleIds(curr_environ);
            init->doInnerSemantics();
        }
    }

    void collectDecls (Decl* enclosing) {
        gcstring name = child(0)->as_token()->as_string();
        Decl* decl = makeClassDecl(name , child(1));
        enclosing->addMember(decl);
        curr_environ->define(decl);
        addDecl(decl);
    }

    void resolveSimpleIds (const Environ* env) {
        child(0)->resolveSimpleIds(env);
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities,  bool& errors) {
        Decl* decl = getDecl();
        for_each_child_var (c, this) {
            c = c->resolveTypes(decl, resolved, ambiguities, errors);
        } end_for;
        return this;
    }

    AST_Ptr rewriteSimpleTypes (const Environ* unused) {
        const Environ *env = getDecl()->getEnviron();
        for_each_child_var (c, this) {
            if (c_i_ != 0) {
                c = c->rewriteSimpleTypes(env);
            }
        } end_for;
        return this;
    }
};

NODE_FACTORY (Class_AST, CLASS);

/*****   FORMALS_LIST   *****/
class Formal_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Formal_List_AST, AST_Tree);

    void collectDecls (Decl* enclosing) {
        // Specify that children are parameters
        for_each_child (c, this) {
            c->addParamDecls(enclosing, c_i_);
        } end_for;
    }
};

NODE_FACTORY (Formal_List_AST, FORMALS_LIST);

/*****   BLOCK   *****/

/** A list of statements. */
class Block_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Block_AST, AST_Tree);

    AST_Ptr doInnerSemantics () {
        for_each_child_var (c, this) {
            c = c->doInnerSemantics ();
        } end_for;
        return this;
    }
};

NODE_FACTORY (Block_AST, BLOCK);

/*****   CLASS_BLOCK   *****/

/** A list of statements. */
class Class_Block_AST : public Block_AST {
protected:

    NODE_CONSTRUCTORS (Class_Block_AST, Block_AST);
};

NODE_FACTORY (Class_Block_AST, CLASS_BLOCK);

/*****   TARGET_LIST   *****/
class Target_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Target_List_AST, AST_Tree);

    Type_Ptr getType() {
        return NULL;
    }
};

NODE_FACTORY (Target_List_AST, TARGET_LIST);
