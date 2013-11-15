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

    /** By default simply run inner semantic analysis using
     *  outer_environ as the environment */
    AST_Ptr doOuterSemantics () {
        return doInnerSemantics ();
    }

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
        child(0)->addTargetDecls(enclosing);
    }
};

NODE_FACTORY (Assign_AST, ASSIGN);

/***** STMT_LIST *****/

/** A list of statements. */
class StmtList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (StmtList_AST, AST_Tree);

    AST_Ptr doOuterSemantics () {
        for_each_child_var (c, this) {
            c = c->doOuterSemantics ();
        } end_for;
        return this;
    }

};

NODE_FACTORY (StmtList_AST, STMT_LIST);

/*****   PRINTLN   *****/

/** A print statement without trailing comma. */
class Println_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Println_AST, AST_Tree);

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
        child(0)->addTargetDecls(enclosing);
        child(1)->collectDecls(enclosing);
        child(2)->collectDecls(enclosing);
        child(3)->collectDecls(enclosing);
    }
};

NODE_FACTORY (For_AST, FOR);

/*****   DEF   *****/
class Def_AST : public Region_AST {
protected:

    NODE_CONSTRUCTORS (Def_AST, Region_AST);

    AST_Ptr doInnerSemantics () {
        Decl *decl = getDecl();
        const Environ *myenv = decl->getEnviron();
        child(1)->collectDecls(decl);
        child(1)->resolveSimpleIds(myenv);
        child(2)->collectDecls(decl);
        child(2)->resolveSimpleIds(myenv);

        // Fix type

        for_each_child (c, child(3)) {
            c->collectDecls(decl);
            c->resolveSimpleIds(myenv);
        } end_for;
        child(3)->doInnerSemantics();
        return this;
    }

    void collectDecls (Decl* enclosing) {
        Decl* decl = enclosing->addDefDecl(child(0));
        addDecl(decl);
    }

    void resolveSimpleIds (const Environ* env) {
        child(0)->resolveSimpleIds(env);
    }
};

NODE_FACTORY (Def_AST, DEF);

/*****   METHOD   *****/

class Method_AST : public Def_AST {
protected:

    NODE_CONSTRUCTORS (Method_AST, Def_AST);
};

NODE_FACTORY (Method_AST, METHOD);


/*****   CLASS   *****/
class Class_AST : public Region_AST {
protected:

    NODE_CONSTRUCTORS (Class_AST, Region_AST);

    AST_Ptr doInnerSemantics () {
        Decl *decl = getDecl();
        const Environ *myenv = decl->getEnviron();
        // Fix type
        for_each_child (c, child(2)) {
            c->collectDecls(decl);
            c->resolveSimpleIds(myenv);
        } end_for;
        child(2)->doInnerSemantics();
        return this;
    }

    void collectDecls (Decl* enclosing) {
        gcstring name = child(0)->as_token()->as_string();
        Decl* decl = makeClassDecl(name , child(1));
        enclosing->addMember(decl);
        addDecl(decl);
    }

    void resolveSimpleIds (const Environ* env) {
        child(0)->resolveSimpleIds(env);
    }
};

NODE_FACTORY (Class_AST, CLASS);

/*****   FORMALS_LIST   *****/
class Formal_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Formal_List_AST, AST_Tree);

    void collectDecls (Decl* enclosing) {
        for_each_child (c, this) {
            c->addParamDecls(enclosing, c_i_);
        } end_for;
    }
};

NODE_FACTORY (Formal_List_AST, FORMALS_LIST);

/***** BLOCK *****/

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

/***** CLASS_BLOCK *****/

/** A list of statements. */
class Class_Block_AST : public Block_AST {
protected:

    NODE_CONSTRUCTORS (Class_Block_AST, Block_AST);
};

NODE_FACTORY (Class_Block_AST, CLASS_BLOCK);

