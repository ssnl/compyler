/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* exprs.cc: AST subclasses related to expressions. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include <string>
#include <sstream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

/********************   TYPED_EXPR   ********************/
class Typed_Expr : public AST_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Typed_Expr, AST_Tree);

    /** Override AST::getType to return the type of the expression. If
     *  if the type is null, computes the type first before returning it. */
    Type_Ptr getType() {
        if (_type != NULL) {
            return _type;
        }
        return computeType();
    }

    /** Computes the type of the expression. This should be overrided by
     *  each specific typed expression. */
    virtual Type_Ptr computeType () = 0;

private:
    Type_Ptr _type;
};


/********************   ASSIGN   ********************/
class Assign_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Assign_AST, AST_Tree);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }

    /** Overrides AST::collectDecls() to specify that the left hand
     *  side of an assignment expression is a target. Also implements
     *  a kludge fix so that nested assignments work. */
    void collectDecls (Decl* enclosing) {
        child(1)->collectDecls(enclosing);
        child(1)->resolveSimpleIds(curr_environ);
        child(0)->addTargetDecls(enclosing);
    }

    void resolveSimpleIds (const Environ* env) {
        child(0)->resolveSimpleIds(env);
    }
};

NODE_FACTORY (Assign_AST, ASSIGN);


/********************   IF EXPRESSION   ********************/
class If_Expr_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (If_Expr_AST, Typed_Expr);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }
};

NODE_FACTORY (If_Expr_AST, IF_EXPR);


/********************   LIST_DISPLAY   ********************/
class List_Display_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (List_Display_AST, Typed_Expr);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }
};

NODE_FACTORY (List_Display_AST, LIST_DISPLAY);


/********************   LOGICAL EXPRESSIONS   ********************/
class Logical_AST : public Typed_Expr {
protected:

    NODE_BASE_CONSTRUCTORS (Logical_AST, Typed_Expr);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }
};

class And_AST : public Logical_AST {
protected:

    NODE_CONSTRUCTORS (And_AST, Logical_AST);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }
};

NODE_FACTORY (And_AST, AND);

class Or_AST : public Logical_AST {
protected:

    NODE_CONSTRUCTORS (Or_AST, Logical_AST);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }
};

NODE_FACTORY (Or_AST, OR);


/********************   RETURN    ********************/
class Return_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Return_AST, AST_Tree);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }
};

NODE_FACTORY (Return_AST, RETURN);


/********************   TUPLE   ********************/
class Tuple_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (Tuple_AST, Typed_Expr);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }
};

NODE_FACTORY (Tuple_AST, TUPLE);


/********************   TYPED_ID   ********************/
class Typed_Id_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (Typed_Id_AST, Typed_Expr);

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }

    /** Stop the recursion. */
    void collectDecls(Decl *enclosing) {}

    /** Specify that the identifier is a parameter and collect
     *  the declaration of the type. */
    void addParamDecls(Decl* enclosing, int k) {
        child(0)->addParamDecls(enclosing, k);
        child(1)->collectDecls(enclosing);
    }

    /** Only recurse down to the identifier since the type should
     *  not need a declaration. */
    void addTargetDecls(Decl* enclosing) {
       child(0)->addTargetDecls(enclosing);
    }
};

NODE_FACTORY (Typed_Id_AST, TYPED_ID);


/********************   CALLS   ********************/

/** The supertype of "callable" things, including ordinary calls,
 *  binary operators, unary operators, subscriptions, and slices. */

class Callable : public Typed_Expr {
protected:

    NODE_BASE_CONSTRUCTORS (Callable, Typed_Expr);

    /** Returns the expression representing the quantity that is
     *  called to evaluate this expression. */
    virtual AST_Ptr calledExpr () = 0;

    /** Returns the number of actual parameters in this call. */
    virtual int numActuals () = 0;

    /** Return the Kth actual parameter in this call. */
    virtual AST_Ptr actualParam (int k) = 0;

    /** Returns the list of parameters in this call. */
    virtual AST_Ptr paramsList () = 0;

    virtual void setActual (int k, AST_Ptr expr) = 0;

    virtual void setCalledExpr (AST_Ptr expr) = 0;

    Type_Ptr computeType () {
        // FIXME
        return NULL;
    }

    AST_Ptr rewriteSimpleTypes (const Environ* env) {
        setCalledExpr(calledExpr()->rewriteSimpleTypes(env));
        for (int i = 0; i < numActuals(); i++) {
            setActual(i, actualParam(i)->rewriteSimpleTypes(env));
        }
        return this;
    }

    void collectDecls(Decl *enclosing) {
        // do nothing
    }

    void resolveSimpleIds(const Environ* env) {
        calledExpr()->resolveSimpleIds(env);
        for (int i = 0; i < numActuals(); i++) {
            actualParam(i)->resolveSimpleIds(env);
        }
    }
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

    AST_Ptr paramsList () {
        return child (1);
    }

    void setActual (int k, AST_Ptr expr) {
        child (1)->replace (k, expr);
    }

    void setCalledExpr (AST_Ptr expr) {
        replace(0, expr);
    }

    AST_Ptr rewriteAllocators (const Environ* env) {
        if (calledExpr()->asType() != NULL) {
            AST_Ptr id = make_token(ID, 8, "__init__");
            AST_Ptr nu = consTree(NEW, calledExpr());
            AST_Ptr call1 = consTree(CALL1, id, paramsList()->insert(0, nu));
            id->set_loc(loc());
            nu->set_loc(loc());
            call1->set_loc(loc());
            return call1;
        }
        return this;
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
        return child(2*k);
    }

    AST_Ptr paramsList () {
        return NULL;
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k, expr);
    }

    // Should never change the called expression
    void setCalledExpr (AST_Ptr expr) {}

};

NODE_FACTORY (Binop_AST, BINOP);

/** A binary operator. */
class Compare_AST : public Callable {

    NODE_CONSTRUCTORS (Compare_AST, Callable);

    AST_Ptr calledExpr () {
        return child (3);
    }

    int numActuals () {
        return 2;
    }

    AST_Ptr actualParam (int k) {
        return child(2*k);
    }

    AST_Ptr paramsList () {
        return NULL;
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k, expr);
    }

    // Should never change the called expression
    void setCalledExpr (AST_Ptr expr) {}

};

NODE_FACTORY (Compare_AST, COMPARE);

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

    AST_Ptr paramsList () {
        return NULL;
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k + 1, expr);
    }

    // Should never change the called expression
    void setCalledExpr (AST_Ptr expr) {}
};

NODE_FACTORY (Unop_AST, UNOP);


