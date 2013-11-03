/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* exprs.cc: AST subclasses related to expressions. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/*****   EXPR_LIST    *****/

/** A list of expressions. */
class Expr_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Expr_List_AST, AST_Tree);

};

NODE_FACTORY (Expr_List_AST, EXPR_LIST);


/* The following is an EXAMPLE of a potentially useful AST class
 * structure, showing the macros you can use to set up base classes
 * and their subtypes. */

/*****   CALLS    *****/

/** The supertype of "callable" things, including ordinary calls,
 *  binary operators, unary operators, subscriptions, and slices. */

class Callable : public AST_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Callable, AST_Tree);
    
    /** Returns the expression representing the quantity that is
     *  called to evaluate this expression. */
    virtual AST_Ptr calledExpr () = 0;

    /** Returns the number of actual parameters in this call. */
    virtual int numActuals () = 0;

    /** Return the Kth actual parameter in this call. */
    virtual AST_Ptr actualParam (int k) = 0;

    /** Set the Kth actual parameter in this call to EXPR. */
    virtual void setActual (int k, AST_Ptr expr) = 0;

    // PUT COMMON CODE DEALING WITH TYPE-CHECKING or SCOPE RULES HERE.
    // USE THE METHODS ABOVE TO ADAPT IT TO PARTICULAR TYPES OF NODE.


};

/** A function call. */
class Call_AST : public Callable {
protected:

    NODE_CONSTRUCTORS (Call_AST, Callable);

    AST_Ptr calledExpr () {
        return child (0);
    }

    int numActuals () {
        return child (1)->arity ();
    }

    AST_Ptr actualParam (int k) {
        return child (1)->child (k);
    }

    void setActual (int k, AST_Ptr expr) {
        child (1)->replace (k, expr);
    }

};

NODE_FACTORY (Call_AST, CALL);

/** A binary operator. */
class Binop_AST : public Callable {

    NODE_CONSTRUCTORS (Binop_AST, Callable);

    AST_Ptr calledExpr () {
        return child (3);
    }

    int numActuals () {
        return 2;
    }

    AST_Ptr actualParam (int k) {
        return child(k * 2);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k, expr);
    }

};    

NODE_FACTORY (Binop_AST, BINOP);

/** A unary operator. */
class Unop_AST : public Callable {

    NODE_CONSTRUCTORS (Unop_AST, Callable);

    AST_Ptr calledExpr () {
        return child (2);
    }

    int numActuals () {
        return 1;
    }

    AST_Ptr actualParam (int k) {
        return child(2*k + 1);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k + 1, expr);
    }

};    

NODE_FACTORY (Unop_AST, UNOP);


