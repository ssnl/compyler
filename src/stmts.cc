/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* stmts.cc: AST subclasses related to statements and modules. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

class Statement_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Statement_AST, AST_Tree);

    AST_Ptr doOuterSemantics () {
        return doInnerSemantics (outer_environ);
    }

    AST_Ptr doInnerSemantics (const Environ* env) {
        for_each_child (c, this) {
            c->resolveSimpleIds (env);
            c->resolveSimpleTypeIds(env);
        } end_for;

        return this;
    }
};

/*****   ASSIGN   *****/
class Assign_AST : public Statement_AST {
protected:

    NODE_CONSTRUCTORS (Assign_AST, Statement_AST);

    AST_Ptr doInnerSemantics (const Environ* env) {
        child(1)->resolveSimpleIds(env);
        child(1)->resolveSimpleTypeIds(env);
        return this;
    }

    void collectDecls (Decl* enclosing) {
        child(0)->addTargetDecls(enclosing);
    }
};

NODE_FACTORY (Assign_AST, ASSIGN);

/*****   PRINTLN   *****/

/** A print statement without trailing comma. */
class Println_AST : public Statement_AST {
protected:

    NODE_CONSTRUCTORS (Println_AST, Statement_AST);

    const char* externalName () {
	return "println";
    }

};

NODE_FACTORY (Println_AST, PRINTLN);

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
