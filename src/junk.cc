#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"
#include <iostream>

using namespace std;

void DBcheck(const char* name, const AST_Ptr& p) {
    if (p->arity () == 0) {
        try {
            if (p->getId () == p && (name == NULL || p->as_string() == name) &&
                p->getDecl () == NULL) {
                cerr << p->as_string () << " undecorated at " 
                     << yyprinted_location (p->loc ()) << endl;
            }
        } catch (logic_error e) {
        }
    } else {
        for_each_child (c, p) {
            DBcheck(name, c);
        } end_for;
    }
}

