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

/** Helper method to unify two the two AST's LEFT and RIGHT enclosed
 *  in ENCLOSING. Also assumes that LEFT and RIGHT both have accessable types
 *  via getType(). Updates RESOLVED, AMBIGUITIES, and ERROR accordingly. If
 *  unification is successful, returns the resulting Type_Ptr_Vector (containing
 *  one element). Otherwise, arbitrarily returns a Type_Ptr_Vector. */
static Type_Ptr_Vector unify(AST_Ptr enclosing, AST_Ptr left, AST_Ptr right,
                             int& resolved, int& ambiguities, bool& errors) {
    Type_Ptr_Vector leftT = left->getDecl()->getTypesInternal();
    Type_Ptr_Vector rightT = right->getDecl()->getTypesInternal();
    Type_Ptr_Vector result1;
    Type_Ptr_Vector result2;
    Type::unifies(leftT, rightT, result1);
    Type::unifies(rightT, leftT, result2);
    left->getDecl()->replaceTypesInternal(result1);
    right->getDecl()->replaceTypesInternal(result2);

    if (result1.size() == 0 || result2.size() == 0) {
        errors = true;
        error(enclosing->loc(), "type error: incompatible types");
    } else if (result1.size() == 1 && result2.size() == 1) {
        resolved += 2;
        left->getType()->unify(result1[0], global_bindings);
        right->getType()->unify(result2[0], global_bindings);
    } else {
        ambiguities += result1.size() + result2.size() - 2;
    }

    return result1;
}

/*****   TYPED_EXPR *****/
class Typed_Expr : public AST_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Typed_Expr, AST_Tree);

    Decl* getDecl (int k = 0) {
        return _decl;
    }

    /** Returns the type of a typed expression. */
    Type_Ptr getType() {
        if (_decl->getTypesInternal().size() == 1) {
            return _decl->getTypesInternal()[0];
        } else {
            return NULL;
        }
    }

    /** Overrides addDecl to simply replace the decl associated
     *  with this expression with DECLARATION. */
    void addDecl (Decl* declaration) {
        _decl = declaration;
    }

    /** Clooge hack to create decl for a typed expression. */
    void createDecl() {
        AST_Ptr dummy[1];
        Type_Ptr result = AST::make_tree (TYPE_VAR, dummy, dummy)->asType ();
        addDecl(makeTypeVarDecl (result->as_string (), result));
    }

    void collectDecls(Decl *enclosing) {
        createDecl();
        // Recursively collect declarations
        for_each_child (c, this) {
            c->collectDecls(enclosing);
        } end_for;
    }

private:
    Decl* _decl;
};

/*****   TYPED_ID   *****/
class Typed_Id_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (Typed_Id_AST, Typed_Expr);

    /** Should never be called. */
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

    Decl* getDecl(int k = 0) {
        return child(0)->getDecl();
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                        int& ambiguities,  bool& errors) {
        Type_Ptr type = child(1)->asType();
        bool success = child(0)->getType()->unify(type, global_bindings);

        if (success && getDecl()->getTypesInternal().size() == 0) {
            Type_Ptr_Vector result;
            result.push_back(type);
            getDecl()->replaceTypesInternal(result);
        } else if (!success) {
            error (loc(), "type error: type mismatch");
        }
        return this;
    }

};

NODE_FACTORY (Typed_Id_AST, TYPED_ID);

/*****   ASSIGN   *****/
class Assign_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (Assign_AST, Typed_Expr);

    void collectDecls (Decl* enclosing) {
        AST_Ptr dummy[1];
        Type_Ptr result = AST::make_tree (TYPE_VAR, dummy, dummy)->asType ();
        addDecl(makeTypeVarDecl (result->as_string (), result));
        // Specify that left hand side is a target
        child(0)->addTargetDecls(enclosing);
        // Recursively collect declarations from right hand side
        child(1)->collectDecls(enclosing);
    }

    gcstring as_string () const {
        if (_name == "")
            return "Assign";
        return _name;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities,
                          bool& errors) {
        cout << "  (Assign_AST) resolving types for " << as_string() << endl;
        // Perform type inference on children
        for_each_child_var (c, this) {
            c = c->resolveTypes(context, resolved, ambiguities, errors);
        } end_for;
        // Save helper variables
        Type_Ptr_Vector right;
        Type_Ptr_Vector left;
        Type_Ptr_Vector result;
        // Unification step
        if (child(0)->as_string() == Target_List) {
            // Multiple targets
            right = child(1)->getDecl()->getTypesInternal();
            if (child(1)->as_string() == List) {
                // If right side is a list
                // HACKHACK: Lists only have one type
                Type_Ptr_Vector tmp;
                tmp.push_back(right[0]->typeParam(0));
                for_each_child (c, child(0)) {
                    result.clear();
                    left = c->getDecl()->getTypesInternal();
                    Type::unifies(left, tmp, result);

                    if (result.size() == 0) {
                        errors = true;
                        error(loc(), "type error: incompatible types");
                    } else if (result.size() == 1) {
                        resolved++;
                        c->getDecl()->getType()->unify(result[0], global_bindings);
                    } else {
                        ambiguities += result.size() - 1;
                    }
                } end_for;
            } else if (child(1)->as_string() == Tuple) {
                // If right side is a Tuple
                if (child(0)->arity() != child(1)->arity()) {
                    error(loc(), "type error: too many values to unpack");
                } else {
                    // HACKHACK: Tuples only have one type
                    Type_Ptr_Vector tmp;
                    for_each_child (c, child(0)) {
                        tmp.clear();
                        result.clear();
                        tmp.push_back(right[0]->typeParam(c_i_));
                        left = c->getDecl()->getTypesInternal();
                        Type::unifies(left, tmp, result);
                        c->getDecl()->replaceTypesInternal(result);

                        if (result.size() == 0) {
                            errors = true;
                            error(loc(), "type error: incompatible types");
                        } else if (result.size() == 1) {
                            resolved++;
                            c->getDecl()->getType()->unify(result[0], global_bindings);
                        } else {
                            ambiguities += result.size() - 1;
                        }
                    } end_for;
                }
            } else {
                // Otherwise Error
                errors = true;
                error(loc(), "type error: '%s' object is not iterable",
                    child(1)->as_string().c_str());
            }
            getDecl()->replaceTypesInternal(right);
        } else {
            // Single target
            left = child(0)->getDecl()->getTypesInternal();
            right = child(1)->getDecl()->getTypesInternal();
            Type::unifies(left, right, result);
            child(0)->getDecl()->replaceTypesInternal(result);

            if (result.size() == 0) {
                errors = true;
                error(loc(), "type error: incompatible types");
            } else if (result.size() == 1) {
                resolved++;
                child(0)->getDecl()->getType()->unify(result[0], global_bindings);
            } else {
                ambiguities += result.size() - 1;
            }
            getDecl()->replaceTypesInternal(result);
        }
        // Change name of the node
        if (child(1)->as_string() == List)
            _name = List;
        else if (child(1)->as_string() == Tuple)
            _name = Tuple;
        return this;
    }

private:

    gcstring _name;
};

NODE_FACTORY (Assign_AST, ASSIGN);

/*****   EXPR_LIST    *****/

/** A list of expressions. */
class Expr_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Expr_List_AST, AST_Tree);

};

NODE_FACTORY (Expr_List_AST, EXPR_LIST);

/*****   TUPLE   *****/
class Tuple_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (Tuple_AST, Typed_Expr);

    gcstring as_string() const {
        return Tuple;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        Type_Ptr_Vector result;
        // Perform type inference on children
        int ar = arity();
        if (ar > 3) {
            error (loc(), "type error: tuple too large");
        } else {
            stringstream ss;
            ss << ar;
            // HACKHACK: Ignoring case when tuple contains functions
            Type_Ptr *params = new Type_Ptr[ar];
            for_each_child_var (c, this) {
                c = c->resolveTypes(context, resolved, ambiguities, errors);
                params[c_i_] = c->getDecl()->getTypesInternal()[0];
            } end_for;
            result.push_back(primitiveDecls[Tuple.c_str() + ss.str()]
                ->asType(ar, params));
        }
        getDecl()->replaceTypesInternal(result);
        return this;
    }
};

NODE_FACTORY (Tuple_AST, TUPLE);

/*****   LIST_DISPLAY   *****/
class List_Display_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (List_Display_AST, Typed_Expr);

    gcstring as_string() const {
        return List;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        int ar = arity();
        Type_Ptr_Vector result;
        if (ar == 0 && getDecl()->getTypesInternal().size()) {
            result.push_back(primitiveDecls[List]->asType(1, Type::makeVar()));
            getDecl()->replaceTypesInternal(result);
        } else {
            Type_Ptr type;
            bool success = true;


            // HACKHACK: Ignoring case when list contains functions
            for_each_child_var (c, this) {
                c = c->resolveTypes(context, resolved, ambiguities, errors);
                if (c_i_ == 0) {
                    type = c->getDecl()->getTypesInternal()[0];
                } else {
                    bool r = type->unify(c->getDecl()->getTypesInternal()[0],
                        global_bindings);
                    if (r) {
                        resolved += 1;
                    } else {
                        success = false;
                    }
                }
            } end_for;
            if (!success) {
                errors = true;
                error(loc(), "type error: incompatible types");
            }
            result.push_back(primitiveDecls[List]->asType(1, type));
            getDecl()->replaceTypesInternal(result);
        }
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
        if (!child(0)->isMissing()) {
            for_each_child_var (c, this) {
                c = c->resolveTypes(context, resolved, ambiguities, errors);
            } end_for;
            Type_Ptr funcType = context->getType();
            Type_Ptr returnType = funcType->returnType();
            Type_Ptr_Vector typeVec = child(0)->getDecl()->getTypesInternal();
            // TODO handle multiple function return types
            Type_Ptr_Vector returnVec;
            returnVec.push_back(returnType);
            Type_Ptr_Vector result;
            Type::unifies(returnVec, typeVec, result);
            if (result.size() >= 1) {
                returnType->unify(result[0], global_bindings);
                resolved++;
                ambiguities += (result.size() - 1);
            } else if (result.size() == 0) {
                errors = true;
                error(loc(), "type error: type mismatch");
            }
        }
        return this;
    }
};

NODE_FACTORY (Return_AST, RETURN);

/*****   LOGICAL EXPRESSIONS   *****/
class Logical_AST : public Typed_Expr {
protected:

    NODE_BASE_CONSTRUCTORS (Logical_AST, Typed_Expr);

    gcstring as_string () const {
        return "Logical";
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        cout << "  (Logical_AST) resolving types for " << as_string() << endl;
        // Resolution
        for_each_child_var (c, this) {
            c = c->resolveTypes(context, resolved, ambiguities, errors);
        } end_for;
        // Unification
        Type_Ptr_Vector result =
            unify(this, child(0), child(1), resolved, ambiguities, errors);
        // Set my own internal type
        getDecl()->replaceTypesInternal(result);
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

class If_Expr_AST : public Typed_Expr {
protected:

    NODE_CONSTRUCTORS (If_Expr_AST, Typed_Expr);

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        // Resolve children
        for_each_child_var (c, this) {
            c = c->resolveTypes(context, resolved, ambiguities, errors);
        } end_for;
        // Unification
        Type_Ptr_Vector result =
            unify(this, child(1), child(2), resolved, ambiguities, errors);
        getDecl()->replaceTypesInternal(result);
        return this;
    }
};

NODE_FACTORY (If_Expr_AST, IF_EXPR);

/*****   CALLS    *****/

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

    AST_Ptr rewriteSimpleTypes (const Environ* env) {
        setCalledExpr(calledExpr()->rewriteSimpleTypes(env));
        for (int i = 0; i < numActuals(); i++) {
            setActual(i, actualParam(i)->rewriteSimpleTypes(env));
        }
        return this;
    }

    void collectDecls(Decl *enclosing) {
        createDecl();
    }

    void resolveSimpleIds(const Environ* env) {
        calledExpr()->resolveSimpleIds(env);
        for (int i = 0; i < numActuals(); i++) {
            actualParam(i)->resolveSimpleIds(env);
        }
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved,
                          int& ambiguities, bool& errors) {
        cout << "  (Callable_AST) resolving types for " << as_string() << endl;
        // Resolve children
        for_each_child_var (c, this) {
            c = c->resolveTypes(context, resolved, ambiguities, errors);
        } end_for;
        cout << "      Finished resolving children..." << endl;
        // Unify
        Type_Ptr_Vector funcTypes = calledExpr()->getDecl()->getTypesInternal();
        Type_Ptr funcType;
        Type_Ptr_Vector paramType;
        Type_Ptr_Vector result;
        Type_Ptr_Vector resolutions;
        bool success;
        for (int i = 0; i < funcTypes.size(); i++) {
            funcType = funcTypes[i]->freshen();
            success = true;
            if (funcType->numParams() == numActuals()) {
                for (int j = 0; j < funcType->numParams(); j++) {
                    paramType.clear();
                    result.clear();
                    paramType.push_back(funcType->paramType(j));
                    Type::unifies(actualParam(j)->getDecl()->getTypesInternal(),
                        paramType, result);
                    if (result.size() == 0) {
                        success = false;
                        break;
                    }
                }
                if (success) {
                    resolutions.push_back(funcType);
                }
            }
        }
        cout << "      Finished finding function resolution..." << endl;
        cout << "      Found " << resolutions.size() << " resolutions..." << endl;

        if (resolutions.size() == 0) {
            errors = true;
            error (loc(), "type error: no suitable function found");
        } else {
            if (resolutions.size() > 1) {
                ambiguities += resolutions.size() - 1;
            } else {
                resolved += 1;
                // Unify parameters
                funcType = resolutions[0];
                for (int i = 0; i < funcType->numParams(); i++) {
                    paramType.clear();
                    result.clear();
                    paramType.push_back(funcType->paramType(i));
                    Type::unifies(paramType,
                        actualParam(i)->getDecl()->getTypesInternal(), result);
                    actualParam(i)->getDecl()->replaceTypesInternal(result);
                    if (result.size() == 1) {
                        resolved += 1;
                        ambiguities += result.size() - 1;
                    }
                }
            }
        }

        Type_Ptr_Vector tmp;
        for (int i = 0; i < resolutions.size(); i++) {
            tmp.push_back(resolutions[i]->returnType());
        }
        getDecl()->replaceTypesInternal(tmp);
        calledExpr()->getDecl()->replaceTypesInternal(resolutions);

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
            // Fix the declaration for the __init__ id
            gcstring name = calledExpr()->child(0)->as_token()->as_string();
            Decl* decl = outer_environ->find(name);
            id->resolveSimpleIds(decl->getEnviron());
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


