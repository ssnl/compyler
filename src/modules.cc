/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* modules.cc: Describes programs or libraries.  Contains top-level routines. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

const Environ* outerEnviron;
Decl* mainModule;
VirtualMachine* VM;

/*****   MODULE    *****/

/** A module, representing a complete source file. */
class Module_AST : public AST_Tree {
protected:

    int lineNumber () {
	return 0;
    }

    /** Top-level semantic processing for the program. */
    AST_Ptr doOuterSemantics () {
        mainModule = makeModuleDecl("__main__");
        outerEnviron = mainModule->getEnviron();
        for_each_child_var (c, this) {
            c = c->doOuterSemantics ();
        } end_for;
        return this;
    }

    /** Top-level code generation routine.  */
    void outerCodeGen (ostream& out) {
        VM = new VirtualMachine(out);
        out << "#include \"runtime.h\"" << endl;
        int startDepth = 0;
        gcmap<gcstring, int> names;
        for_each_child(c, this) {
            c->declDepthPreprocess(startDepth);
            c->declNamePreprocess(names);
        } end_for;

        // Placeholder Code
        out << "int main()"
            << "{" << endl
            << "    cout << \"Hello, world!\" << endl;" << endl
            << "}";
    }

    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

};

NODE_FACTORY (Module_AST, MODULE);

