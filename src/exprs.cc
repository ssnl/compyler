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

/*****   TYPED_ID   *****/
class Typed_Id_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Typed_Id_AST, AST_Tree);

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

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                        int& ambiguities,  bool& errors) {
        // Unwind_Stack unwind_stack;
        // Type_Ptr type = child(1)->asType();
        // child(0)->getType()->unify(type, unwind_stack);
        // setType(type);
        return this;
    }

};

NODE_FACTORY (Typed_Id_AST, TYPED_ID);

/*****   EXPR_LIST    *****/

/** A list of expressions. */
class Expr_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Expr_List_AST, AST_Tree);

};

NODE_FACTORY (Expr_List_AST, EXPR_LIST);

/*****   TUPLE   *****/
class Tuple_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Tuple_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        // int ar = arity();
        // if (ar > 3) {
        //     error (loc(), "type error: tuple too large");
        // } else {
        //     Type_Ptr *params = new Type_Ptr[ar];
        //     for_each_child_var (c, this) {
        //         params[c_i_] = c->getType();
        //         c = c->resolveTypes(context, resolved, ambiguities, errors);
        //     } end_for;
        //     stringstream ss;
        //     ss << ar;
        //     setType(primitiveDecls[Tuple.c_str() + ss.str()]->asType(ar, params));
        // }
        return this;
    }
};

NODE_FACTORY (Tuple_AST, TUPLE);

/*****   LIST_DISPLAY   *****/
class List_Display_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (List_Display_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        // int ar = arity();
        // if (ar == 0) {
        //     setType(primitiveDecls[List]->asType(1, Type::makeVar()));
        // } else {
        //     Type_Ptr type;
        //     Unwind_Stack unwind_stack;
        //     for_each_child_var (c, this) {
        //         c = c->resolveTypes(context, resolved, ambiguities, errors);
        //         if (c_i_ == 0)
        //             type = c->getType();
        //         else
        //             type->unify(c->getType(), unwind_stack);
        //     } end_for;
        //     setType(primitiveDecls[List]->asType(1, type));
        // }
        return this;
    }
};

NODE_FACTORY (List_Display_AST, LIST_DISPLAY);

/*****   RETURN    *****/
class Return_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Return_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        // if (!child(0)->isMissing()) {
        //     for_each_child_var (c, this) {
        //         c = c->resolveTypes(context, resolved, ambiguities, errors);
        //     } end_for;
        //     Unwind_Stack unwind_stack;
        //     Type_Ptr functype = context->getType();
        //     Type_Ptr ret_type = functype->returnType();
        //     child(0)->getType()->unify(ret_type, unwind_stack);
        // }
        return this;
    }
};

NODE_FACTORY (Return_AST, RETURN);

/*****   LOGICAL EXPRESSIONS   *****/
class Logical_AST : public AST_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Logical_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        // for_each_child_var (c, this) {
        //     c = c->resolveTypes(context, resolved, ambiguities, errors);
        // } end_for;
        // Unwind_Stack unwind_stack;
        // child(0)->getType()->unify(child(1)->getType(), unwind_stack);
        // setType(child(0)->getType());
        return this;
    }
};

class And_AST : public Logical_AST {
protected:

    NODE_CONSTRUCTORS (And_AST, Logical_AST);
};

NODE_FACTORY (And_AST, AND);

class Or_AST : public Logical_AST {
protected:

    NODE_CONSTRUCTORS (Or_AST, Logical_AST);
};

NODE_FACTORY (Or_AST, OR);

class If_Expr_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (If_Expr_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        // for_each_child_var (c, this) {
        //     c = c->resolveTypes(context, resolved, ambiguities, errors);
        // } end_for;
        // Unwind_Stack unwind_stack;
        // Type_Ptr left = child(1)->getType();
        // Type_Ptr right = child(2)->getType();
        // left->unify(right, unwind_stack);
        // setType(left);
        return this;
    }
};

NODE_FACTORY (If_Expr_AST, IF_EXPR);

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

    /** Returns the list of parameters in this call. */
    virtual AST_Ptr paramsList () = 0;

    virtual void setActual (int k, AST_Ptr expr) = 0;

    virtual void setCalledExpr (AST_Ptr expr) = 0;

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

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        // cout << "  (Callable) resolving types for " + child(0)->as_string();
        // for_each_child_var (c, this) {
        //     // If the child is not an id node, resolve its type
        //     if (c_i_ != 0) {
        //         c = c->resolveTypes(context,resolved,ambiguities,errors);
        //     }
        // } end_for;
        // Decl_Vector decls;
        // Unwind_Stack unwind_stack;
        // gcstring idname = child(0)->as_string();
        // if (idname.size() == 0) {
        //     error(loc(), "you done fucked up.");
        // }
        // Type_Ptr functype;
        // bool success = true;
        // int success_count = 0;
        // Decl* success_decl;
        // context->getEnviron()->find(idname, decls);
        // for (int i = 0; i < decls.size(); i++) {
        //     Decl* d = decls.at(i);
        //     success = true;
        //     functype = d->getType();
        //     for_each_child (c, child(1)) {
        //         success = success &&
        //             functype->paramType(c_i_)->unify(c->asType(), unwind_stack);
        //     } end_for;
        //     if (success) {
        //         success_decl = d;
        //         success_count++;
        //     }
        // }
        // if (success_count == 0) {
        //     error(loc(), "type error: invalid function call");
        // } // TODO else if > 1 handle ambiguous call error
        // else if (success_count == 1) {
        //     setType(success_decl->getType()->returnType());
        // }
        // // Set type of this to the return type
        return this;
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


