/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* modules.cc: Describes programs or libraries.  Contains top-level routines. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include <sstream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

const Environ* outerEnviron;
Decl* mainModule;
VirtualMachine* VM;
gcmap<Decl*, gcstring> declName;

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
        VM = new VirtualMachine (out);
        out << "#include \"runtime.h\"" << endl << endl;
        int startDepth = 0;
        gcmap<gcstring, int> names;
        declDepthPreprocess (startDepth);
        declNamePreprocess (names);
        runtimeDataStructGen (out);

        // Placeholder Code
        out << "int main()"
            << "{" << endl
            << "    cout << \"Hello, world!\" << endl;" << endl
            << "}";
    }

    /** Creates a new name for every declaration, starting at but not including
     *  the module, and recursively iterating to its children. Determines the
     *  new name using NAMES to create a unique identifier. */
    void declNamePreprocess (gcmap<gcstring, int>& names) {
        Decl* me = mainModule;
        Decl_Vector members = me->getEnviron ()->get_members ();
        for (int i = 0; i < members.size (); i++) {
            members[i]->setupRuntimeName(names);
        }
        AST::declNamePreprocess (names);
    }

    /** Generates a struct containing the local variables for the main module.
     *  Recursively generates runtime data structures for functions and classes
     *  within the main module. */
    void runtimeDataStructGen (std::ostream& out) {
        AST::runtimeDataStructGen (out);
        Decl* me = mainModule;
        Decl_Vector members = me->getEnviron ()->get_members ();
        Decl* memberDecl;
        gcstring memberName, memberTypeName;
        stringstream body, generics;
        for (int i = 0; i < members.size(); i++) {
            memberDecl = members[i];
            memberName = memberDecl->getRuntimeName();
            memberTypeName = memberDecl->getRuntimeTypeName();
            if (memberTypeName != "") {
                body << "    " << memberTypeName << " "
                     << memberName << ";" << endl;
            }
        }
        out << "struct __main__ {" << endl
            << body.str()
            << "};" << endl << endl;
    }

    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

};

NODE_FACTORY (Module_AST, MODULE);

