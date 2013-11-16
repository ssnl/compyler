/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* modules.cc: Describes programs or libraries.  Contains top-level routines. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

const Environ* outer_environ;

/*****   MODULE    *****/

/** A module, representing a complete source file. */
class Module_AST : public AST_Tree {
protected:

    int lineNumber () {
        return 0;
    }

    /** Top-level semantic processing for the program. */
    AST_Ptr doOuterSemantics () {
        Decl* moduleDecl = makeModuleDecl("__main__");
        outer_environ = moduleDecl->getEnviron();
        // TODO: Error checking
        rewriteNone();
        // Create declarations, simple resolutions, and basic rewrites
        for_each_child_var (c, this) {
            // Declarations
            c->collectDecls(moduleDecl);
            c->resolveSimpleIds(outer_environ);
            c = c->doOuterSemantics();
            // Rewrites
            c = c->rewriteSimpleTypes(outer_environ);
            c = c->rewriteAllocators(outer_environ);
        } end_for;
        return this;
    }

    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

};

NODE_FACTORY (Module_AST, MODULE);

