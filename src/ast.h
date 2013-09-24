/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* ast.h: Top-level definitions for abstract syntax trees. */

/* Authors: */

#ifndef _AST_H_
#define _AST_H_

#include "horn-common.h"

class AST;
class AST_Token;
class AST_Tree;
class Type;

/* The Horn framework uses reference-counting to reclaim space.  The
 * type Pointer<T> is a reference-counted pointer to type T.  It acts
 * like a T* (so -> and * work), and there is an implicit coercion
 * from T* to Pointer<T>.  */

typedef Pointer<AST> AST_Ptr;
typedef Pointer<Type> Type_Ptr;
YYDEFINE_LIST_TYPE(List_Ptr, AST_Ptr);

/** The base type of all nodes in the abstract syntax tree. */
class AST : public CommonNode<AST, AST_Token, AST_Tree> {
public:
    virtual int lineNumber ();

    /** Print my representation as an AST on OUT.  Use INDENT as the
     *  indentation for subsequent lines if my representation takes up
     *  multiple lines. */
    virtual void print (std::ostream& out, int indent) = 0;

    /** For nodes that represent types, return the node with a static
     *  type that reveals its Type operations.  An error on node types
     *  that do not represent types. */
    virtual Type_Ptr as_type ();

protected:

};

class AST_Token : public CommonToken<AST, AST_Token, AST_Tree> {
public:
    AST_Token (int syntax, const char* text, size_t len, bool owner = false)
        : CommonToken<AST, AST_Token, AST_Tree> (syntax, text, len, owner) { }

    AST_Token (int syntax, const std::string& text, bool owner)
        : CommonToken<AST, AST_Token, AST_Tree> (syntax, text, owner) { }

    void print (std::ostream& out, int indent);

    /** The text denoted by THIS, if a string literal.  Undefined
     *  otherwise.  This is distinct from the actual text of a
     *  literal; all escape sequences have been replaced with their
     *  denotations. */
    virtual std::string string_text () const;

    /** Append S to the value of string_text(), if allowed.  Otherwise
     *  undefined. */
    virtual void append_text(const std::string& s);

protected:

    /** Used to produce factory objects. */
    AST_Token (int syntax) 
        : CommonToken<AST, AST_Token, AST_Tree>(syntax) {
    }

};
    
class AST_Tree : public CommonTree<AST, AST_Token, AST_Tree> {
    typedef CommonTree<AST, AST_Token, AST_Tree> Parent;
public:

    /** Overrides AST::print.  Default definition of printing on
     *  trees: prints (<OP> <LINE> <CHILD0> ...), where <OP> is the 
     *  external operator name and line is the source line number. */
    void print (std::ostream& out, int indent);

    NODE_BASE_CONSTRUCTORS (AST_Tree, Parent);

protected:

    /** External name of this type of node, for printing purposes.
     *  This is NOT intended as a way of determine the type of a
     *  node. */
    virtual const char* external_name ();

};

/** The supertype of all tree nodes that represent types.  We could
 *  instead define type-specific operations in AST, but that clutters
 *  ASTs with operations that apply only to certain subtypes.  This
 *  class is intended to factor out the operations specific to types. */
class Type : public AST_Tree {
public:

    /** Overrides AST::as_type. Effectively reveals the Type-specific
     *  operations on this node.  */
    Pointer<Type> as_type () {
        return this;
    }

    NODE_BASE_CONSTRUCTORS (Type, AST_Tree);
};

/** Control structure: 
 *      For each child, VAR, of AST_Node* NODE, ...
 *  Usage:
 *      for_each_child (C, aTree) {
 *           <operations involving C (an AST_Node*)>
 *      } end_for;
 *  Inside the body, C_i_ is the index of C within aTree.
 */
#define for_each_child(Var, Node)                                            \
    do {                                                                     \
       AST_Ptr Var ## _n_ = Node;                                            \
       for (int Var ## _i_ = 0, Var ## _e_ = Var ## _n_->arity ();           \
            Var ## _i_ < Var ## _e_; Var ## _i_ += 1) {                      \
           const AST_Ptr Var  = Var ## _n_->child (Var ## _i_);

/** Control structure: 
 *      For each child, VAR, of AST_Node* NODE in reverse order, ...
 *  Usage:
 *      for_each_child (C, aTree) {
 *           <operations involving C (an AST_Node*)>
 *      } end_for;
 *  Inside the body, C_i_ is the index of C within aTree.
 */
#define for_each_child_reverse(Var, Node)                                    \
    do {                                                                     \
       AST_Ptr Var ## _n_ = Node;                                            \
       for (int Var ## _i_ = Var ## _n_->arity () - 1;                       \
            Var ## _i_ >= 0; Var ## _i_ -= 1) {                              \
           const AST_Ptr Var  = Var ## _n_->child (Var ## _i_);

/** Control structure: 
 *      For each child, VAR, of AST_Node* NODE, ...
 *  replacing the child with the value of VAR at the end of each iteration.
 *    
 *  Usage:
 *      for_each_child_var (C, aTree) {
 *           <operations involving C (an AST_Node*)>
 *      } end_for;
 */
#define for_each_child_var(Var, Node)                                        \
    do {                                                                     \
       AST_Ptr Var ## _n_ = Node;                                            \
       AST_Ptr Var = NULL;                                                   \
       for (int Var ## _i_ = 0;                                              \
            Var ## _i_ < (int) Var ## _n_->arity ();                         \
            _replace_and_incr (Var ## _n_, Var ## _i_, Var)) {               \
           Var = Var ## _n_->child (Var ## _i_);

#define end_for } } while (0)

#endif

