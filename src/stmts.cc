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

    void collectDecls(Decl* enclosing) {
        // do nothing
    }

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

class Print_AST : public Statement_AST {
protected:

    NODE_CONSTRUCTORS (Print_AST, Statement_AST);

    const char* externalName () {
        return "print";
    }

};

NODE_FACTORY (Print_AST, PRINT);


class Def_AST : public Statement_AST {
protected:

    NODE_CONSTRUCTORS (Def_AST, Statement_AST);

    AST_Ptr doInnerSemantics (const Environ* env) {
        Decl *decl = getDecl();
        child(1)->addTargetDecls(decl);
        child(3)->collectDecls(decl);
        child(3)->doInnerSemantics(decl->getEnviron());
        return this;
    }

    void collectDecls (Decl* enclosing) {
        // Get the name of the function
        gcstring name = child(0)->as_token()->as_string();

        // TODO: Potential error checking

        // Create a new funcdecl, with enclosing as the container
        Decl* decl = makeFuncDecl(name, enclosing, NULL);
        child(0)->as_token()->addDecl(decl);
        // Add the current funcdecl to the enclosing decl before returning
        enclosing->addMember(decl);
        // Add decl to myself
        addDecl(decl);
    }
};

NODE_FACTORY (Def_AST, DEF);


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

/***** BLOCK *****/

/** A list of statements. */
class Block_AST : public Statement_AST {
protected:

    NODE_CONSTRUCTORS (Block_AST, Statement_AST);

    void collectDecls (Decl* enclosing) {
        for_each_child (c, this) {
            c->collectDecls (enclosing);
        } end_for;
    }
};

NODE_FACTORY (Block_AST, BLOCK);
