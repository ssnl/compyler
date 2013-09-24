/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* ast.cc: Basic AST subclasses. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/* Definitions of methods in base class AST. */

Type_Ptr
AST::as_type ()
{
    throw logic_error ("node does not represent a type");
}

/* Definitions of methods in base class AST_Tree. */

void
AST_Tree::print (ostream& out, int indent)
{
    out << "(" << external_name () << " " << lineNumber ();
    for_each_child (c, this) {
        out << endl << setw (indent + 4) << "";
        c->print (out, indent + 4);
    } end_for;
    out << ")";
}

/** My node operator name, as it appears in my external (text) AST
 *  representation.  The value is valid only until the next call to
 *  external_name. */
const char*
AST_Tree::external_name ()
{
    static string result;

    int syntax = oper ()->syntax ();
    const char* name;
    name = yyexternal_token_name (syntax);
    if (name == NULL)
        return "?";
    if (name[0] != '"')
        return name;
    name += 1;
    while (*name == '@')
        name += 1;
    
    if (name[0] == '\0')
        return "?";

    result = string (name, strlen (name)-1);
    return result.c_str();
}


/* The Horn framework has a provision (the NODE_FACTORY macro) that
 * allows AST subclasses to "register" themselves with the parser and
 * associate themselves with a particular syntactic category so that
 * the parser will create instances of the appropriate subclass when
 * asked to produce an AST node with a particular operator.  The
 * NODE_..._CONSTRUCTOR... macros set up the necessary constructors
 * and factory declarations in any given class.  To associate a
 * class with a given operator token, pass the (int) value of that
 * token's syntactic category to the NODE_FACTORY macro (for
 * one-character tokens, the character itself is usually the syntactic
 * category; for other tokens, use the name declared in the Horn
 * source file (those definitions appear in apyc-parser.hh, included above).
 */

/** A node representing a missing element in the AST (e.g., a missing 
 *  >>FILE argument in a print node.) */
class Empty_AST : public AST_Tree {

    /** Override AST_Tree::print */
    void print (ostream& out, int indent) {
        out << "()";
    }

    NODE_CONSTRUCTORS (Empty_AST, AST_Tree);

};

NODE_FACTORY (Empty_AST, EMPTY);
