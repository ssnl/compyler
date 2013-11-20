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
Environ* curr_environ;

/*****   MODULE    *****/

/** A module, representing a complete source file. */
class Module_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

    int lineNumber () {
        return 0;
    }

    /** Top-level semantic processing for the program. */
    AST_Ptr doOuterSemantics () {
        AST_Ptr self = this;
        Decl* me = makeModuleDecl("__main__");
        outer_environ = me->getEnviron();
        curr_environ = new Environ(NULL);

        /** The steps for processing a module should be, in this
         *  general order:
         *      1. Error Checking
         *      2. Basic rewrites
         *      3. Collecting declarations, resolve identifiers
         *      4. Perform type inference
         *      5. Final rewrites
         */

        // 1. Error Checking (TODO)
        // 2. Convert None to __None__
        self = self->rewriteNone();
        // 2/3. Collect/Resolve declarations
        for_each_child_var (c, self) {
            c->collectDecls(me);
            c->resolveSimpleIds(curr_environ);
            c = c->doInnerSemantics();
        } end_for;

        // 2. Rewrite simple types and allocators
        for_each_child_var (c, self) {
            c = c->rewriteSimpleTypes(outer_environ);
            c = c->rewriteAllocators(outer_environ);
        } end_for;
        // 4. Fill in types for primitives
        gcstring key;
        for (Decl_Map::iterator i = primitiveDecls.begin();
            i != primitiveDecls.end(); i++) {
            key = i->first;
            primitiveDecls[key] = outer_environ->find(key);
        }
        // 4. Perform type inference
        cout << "(Module_AST) resolving outer types..." << endl;
        for_each_child_var (c, self) {
            //c = c->resolveTypesOuter(me);
        } end_for;
        // TODO: Print errors

        // 5. Final rewrites (TODO)

        return self;
    }
};

NODE_FACTORY (Module_AST, MODULE);

