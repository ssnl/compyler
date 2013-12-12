/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* ast.h: Top-level definitions for abstract syntax trees. */

/* Authors: */

#ifndef _AST_H_
#define _AST_H_

#include <stack>
#include <map>
#include <string>
#include "horn-common.h"

class AST;
class AST_Token;
class AST_Tree;
class Type;
class Decl;
class Environ;

/* The Horn framework uses reference-counting to reclaim space.  The
 * type Pointer<T> is a reference-counted pointer to type T.  It acts
 * like a T* (so -> and * work), and there is an implicit coercion
 * from T* to Pointer<T>.  */

typedef AST* AST_Ptr;
typedef Type* Type_Ptr;
YYDEFINE_LIST_TYPE(List_Ptr, AST_Ptr);

typedef std::stack<Type_Ptr> Unwind_Stack;

/* General Design Note:  We have only a few base types defined in .h
 * files.  Concrete types are typically defined in .cc files because
 * in general, their type names are not expected to be used directly
 * elsewhere in the program.  Instead, we rely on having these
 * concrete classes override virtual methods as appropriate, and use
 * factory methods to find and instantiate instances of these classes
 * where needed.  Thus AST and Type declare a common behavior for all
 * their subtypes, and it is that common behavior that the rest of the
 * program relies on exclusively, minimizing inquiries into the
 * specific types of child nodes.  */


/** The base type of all nodes in the abstract syntax tree. */
class AST : public CommonNode<AST, AST_Token, AST_Tree> {
public:
    typedef gcmap<std::string, AST_Ptr> AST_Map;

    virtual int lineNumber ();

    /** Print my representation of as an AST on OUT.  Use INDENT as the
     *  indentation for subsequent lines if my representation takes up
     *  multiple lines. */
    void print (std::ostream& out, int indent);

    /** For nodes that represent types, return the node with a static
     *  type that reveals its Type operations.  Returns NULL on node types
     *  that do not represent types. */
    virtual Type_Ptr asType ();

    /** True if I represent a type. */
    virtual bool isType ();

    /** For nodes representing formal parameters, ids, or attribute
     *  references, the id part.  */
    virtual AST_Ptr getId ();

    /** For nodes that represent named entities, the number of
     *  possible declarations of that entity.  (For overloaded names,
     *  therefore, may be >1). */
    virtual int numDecls ();

    /** The Kth declaration (0 <= K < numDecls()) of me.  Returns NULL
     *  if there is none. */
    virtual Decl* getDecl (int k = 0);

    /** Add DECL to the end of the list of declarations of this node,
     *  if allowed. */
    virtual void addDecl (Decl* decl);

    /** Remove Kth declaration (0 <= K < numDecls()) of me. */
    virtual void removeDecl (int k);

    /** Get my type, if I have one. */
    virtual Type_Ptr getType ();

    /** Set my type to TYPE, or unify with TYPE if already
     *  set. Returns true iff successful. */
    virtual bool setType (Type_Ptr type);

    /** True for a missing node. */
    virtual bool isMissing ();

    /** True if I represent a "bound method" (i.e., OBJ.ID where OBJ
     *  is a value of type C and ID is a method defined in C.). */
    virtual bool isBoundMethod ();

    /** True if I represent a "target list." */
    virtual bool isTargetList ();

    /** Do outer-level semantic analysis on me---all scope and type
     *  analysis that applies to definitions and statements that are
     *  not nested inside classes or function definitions.  Modifies
     *  the global environment with any definitions I represent.
     *  Returns the modified tree.  */
    virtual AST_Ptr doOuterSemantics ();

    /** Add any declarations that I represent to ENCLOSING, the
     *  environment in which I am nested.  This does not add
     *  declarations for declarative regions nested within me. */
    virtual void collectDecls (Decl* enclosing);

    /** Add declarations that result from occurrences of type
     *  variables in type attributions to ENCLOSING. */
    virtual void collectTypeVarDecls (Decl* enclosing);

    /** Assuming I am a target of an assignment, add any local
     *  declarations that would result from assignments to me to
     *  ENCLOSING, my enclosing construct.  (Used by overridings of
     *  collectDecls.) */
    virtual void addTargetDecls (Decl* enclosing);

    /** Resolve all simple (non-qualified) identifiers in me, assuming
     *  that ENV defines declarations visible at my outer level.
     *  Returns the resolved node.  This will differ from THIS when it
     *  denotes a type.  */
    virtual AST_Ptr resolveSimpleIds (const Environ* env);

    /** Resolve all simple (non-qualified) type identifiers in a typed
     *  identifier.  Does nothing for other nodes. Assumes that
     *  that ENV defines declarations visible at my outer level. */
    virtual void resolveSimpleTypeIds (const Environ* env);

    /** Replace any allocators in me with appropriate NEW nodes,
     *  returning the modified node. */
    virtual AST_Ptr resolveAllocators (const Environ* env);

    /** Resolve all selections of the form CLASS.ID by replacing them
     *  with ID, appropriately decorated, assuming that ENV defines
     *  all visible classes.   Returns the modified tree. */
    virtual AST_Ptr resolveStaticSelections (const Environ* env);

    /** If THIS denotes a bound method with argument list ARGS, return
     *  the equivalent method call.  Otherwise, return NULL. */
    virtual AST_Ptr convertMethodCall (AST_Ptr args);

    /** Set the "freeze" state of everything defined by "def" in me to
     *  FROZEN. */
    virtual void freezeDecls (bool frozen);

    /** Resolve the types of me and my subcomponents, and resolve
     *  the meanings of unresolved attribute references (OBJ.ID, where
     *  OBJ is not a class, so that the possible meanings of ID depends
     *  on the type of OBJ).  During resolution, all def's in me are
     *  frozen---i.e., references to them do not create fresh type
     *  variables. Returns the modified tree.   The return value
     *  differs from THIS only in the case where I am a call whose
     *  function has the form OBJ.ID, and this is found to denote a
     *  (possibly overloaded) method, in which case the return value
     *  is me rewritten as an ordinary call (that is OBJ.ID(ARG1, ...)
     *  becomes ID(OBJ, ARG1, ...)). */
    virtual AST_Ptr resolveTypesOuter(Decl* context);

    /** Resolve the types of me and my subcomponents, and resolve
     *  the meanings of unresolved attribute references (OBJ.ID, where
     *  OBJ is not a class, so that the possible meanings of ID depends on the
     *  type of OBJ).  Increments RESOLVED by the number of previously
     *  unresolved identifiers that are so resolved and increments
     *  AMBIGUITIES by the number of ambiguities (the number of
     *  ambiguities of an identifier is the number of declarations
     *  found for it in excess of 1). CONTEXT provides the module or function
     *  containing me.  Returns the modified tree (see
     *  resolveTypesOuter for details of modifications.)
     */
    virtual AST_Ptr resolveTypes (Decl* context,
                                  int& resolved, int& ambiguities);


    /** Resolve my meaning, given that I am selected from an object of
     *  type OBJECTTYPE, (i.e., I am ID in OBJ.ID).  Increments RESOLVED
     *  by the number of previously unresolved identifiers that are so
     *  resolved and increments AMBIGUITIES by the number of
     *  ambiguities (the number of ambiguities of an identifier is the
     *  number of declarations found for it in excess of 1).
     */
    virtual void resolveSelectedType (Type_Ptr objectType, int& resolved,
                                      int& ambiguities);

    /** Resolve the types of me and my subcomponents, and resolve
     *  the meanings of unresolved attribute references (OBJ.ID, where
     *  OBJ is not a class, so that the possible meanings of ID depends on the
     *  type of OBJ).  All overloaded identifiers must be resolved.
     *  CONTEXT provides the module or function containing me.
     *  Returns the modified tree (see also resolveTypesOuter).
     */
    virtual AST_Ptr resolveTypes (Decl* context);

    /** Find and report improper uses of bound method values. */
    virtual void checkNoBoundMethodValues ();

    /** Report unresolved overloaded names in me as errors. */
    virtual void checkResolved ();

    /** Convert all references to the value None in me to calls on
     *  __None__, returning the modified tree.  DEFININGCONTEXT should
     *  be true if THIS appears in a defining context (such as the
     *  left side of an assignment). Does not modify
     *  defining contexts (which must be caught separately). */
    virtual AST_Ptr convertNone (bool definingContext);

    /** Generate code for me on OUT. */
    virtual void outerCodeGen (std::ostream& out);

    /** Generate code for me if I am a class by recursively generating code for
     *  instance variables/methods within me. */
    virtual void classCodeGen (int depth);

    /** Generate code for me if I am a definition by recursively generating
     *  code for all definitions within me before generating code for the
     *  statements within me. */
    virtual void defCodeGen (int depth);

    /** Generate code for me and all expressions within me, leaving the stack
     *  machine unchanged afterwards. */
    virtual void stmtCodeGen (int depth);

    /** Generate code for me assuming I am within an expression, leaving the
     *  result of my evaluation at the top of the stack machine. */
    virtual void exprCodeGen (int depth);

    /** Generates runtime data structures for modules, functions, and classes
     *  and prints them on OUT. */
    virtual void runtimeDataStructGen (std::ostream& out);

    /** Preprocess the declarations for each AST, providing new names for any
     *  declaration that already has a name previously declared. Uses NAMES to
     *  determine which names have already been declared. Modfies all
     *  declaration names to be <Name>_<#>$ for some <#> corresponding to which
     *  time it has appeared. */
    virtual void declNamePreprocess (gcmap<gcstring, int>& names);

    /** Preprocess any function declarations for each AST, setting their static
     *  frame depths to be CURRDEPTH. Each function definition increments
     *  CURRDEPTH by one to preprocess its children and decrements CURRDEPTH by
     *  one after preprocessing its children. Declarations that are not
     *  function definitions have undefined depth. */
    virtual void declDepthPreprocess (int& currDepth);

    /** True if an error has been reported on me. */
    bool errorReported ();

    /** Indicate that an error has been reported on this node (to
     *  avoid multiple error messages. */
    void recordError ();

protected:

    AST ();

    /** It is possible to have "trees" that are actually DAGS or even
     *  circular graphs (because of recursive types, for example).  We
     *  use the following trick to avoid visiting a node multiple
     *  times: At the beginning of each potentially circular
     *  traversal, increment current_mark.  Critical nodes contain a
     *  mark value (initially 0), that the traversal sets to
     *  current_mark, so that when the same node is encountered a
     *  second time during the same traversal, its mark will equal
     *  current_mark.  Alternatively, by bracketing the body of a
     *  traversal method with mark() and unmark(), we can avoid
     *  traversing cycles infinitely. */
    static int current_mark;

    /** Mark THIS with the current traversal number, and return
     *  true if this is the first visit to THIS. */
    bool mark ();

    /** Undo the mark on THIS. */
    void unmark ();

    /** Print me as an AST on OUT.  Use INDENT as the indentation for
     *  subsequent lines if my representation takes up multiple lines.
     *  This method is intended to be called by other print methods
     *  during a traversal (using the print method below), whereas
     *  the public print method begins a traversal.  Nodes already
     *  printed during the current traversal are not followed. */
    virtual void _print (std::ostream& out, int indent) = 0;

    /** Print TREE on OUT at given INDENT level, being sure not to
     *  traverse circular structures.  This is the intended way that
     *  overridings of _print should recursively print their children.
     */
    static void print (AST_Ptr tree, std::ostream& out, int indent);

private:
    /** The sequence number of the last traversal involving this
     *  node.  The .mark() method updates this to the current
     *  traversal's sequence number.  Hence, we can tell if this node
     *  has been visited during the current traversal. */
    int _mark;

    /** Set to true to indicate that an error has been flagged on this
     *  node.  Used to avoid multiple error messages on a node. */
    bool _erroneous;

};

class AST_Token : public CommonToken<AST, AST_Token, AST_Tree> {
public:
    AST_Token (int syntax, const char* text, size_t len)
	: CommonToken<AST, AST_Token, AST_Tree> (syntax, text, len) { }

    AST_Token (int syntax, const gcstring& text)
        : CommonToken<AST, AST_Token, AST_Tree> (syntax, text) { }

    /** The text denoted by THIS, if a string literal.  Undefined
     *  otherwise.  This is distinct from the actual text of a
     *  literal; all escape sequences have been replaced with their
     *  denotations. */
    virtual gcstring string_text () const;

    /** Append S to the value of string_text(), if allowed.  Otherwise
     *  undefined. */
    virtual void append_text(const gcstring& s);

protected:

    /** Used to produce factory objects. */
    AST_Token (int syntax)
        : CommonToken<AST, AST_Token, AST_Tree>(syntax) {
    }

    void _print (std::ostream& out, int indent);
};

class AST_Tree : public CommonTree<AST, AST_Token, AST_Tree> {
    typedef CommonTree<AST, AST_Token, AST_Tree> Parent;

public:

    NODE_BASE_CONSTRUCTORS (AST_Tree, Parent);

protected:

    /** Overrides AST::print.  Default definition of printing on
     *  trees: prints (<OP> <LINE> <CHILD0> ...), where <OP> is the
     *  external operator name and line is the source line number. */
    void _print (std::ostream& out, int indent);

    /** External name of this type of node, for printing purposes.
     *  This is NOT intended as a way of determine the type of a
     *  node, and is valid only until the next call on externalName. */
    virtual const char* externalName ();

};

/** The supertype of all tree nodes that represent types.  We could
 *  instead define type-specific operations in AST, but that clutters
 *  ASTs with operations that apply only to certain subtypes.  This
 *  class is intended to factor out the operations specific to types. */
class Type : public AST_Tree {
    friend class TypeVar_AST;
public:

    /** Overrides AST::asType. Effectively reveals the Type-specific
     *  operations on this node.  */
    Type_Ptr asType () {
        return this;
    }

    bool isType () {
        return true;
    }

    /** Reports an erroneous type reference. */
    Type_Ptr getType ();

    /** My runtime type name. By default, returns "". */
    virtual gcstring getRuntimeName ();

    /** My arity, if I am a function type.  Otherwise -1. */
    virtual int numParams ();

    /** The type of my Kth parameter, 0 <= K < numParams(). */
    virtual Type_Ptr paramType (int k);

    /** My return type, if I am a function type.  Otherwise NULL. */
    virtual Type_Ptr returnType ();

    /** My number of type parameters. */
    virtual int numTypeParams ();

    /** My Kth type parameter, 0 <= K < numParams(), */
    virtual Type_Ptr typeParam (int k);

    /** An environment defining all my attributes. */
    virtual const Environ* getEnviron ();

    /** My current binding.  Initially THIS, and then changed by
     *  unification. */
    virtual Type_Ptr binding ();

    /** Unify THIS with TYPE, returning true iff successful, and
     *  recording all bindings at the end of BINDINGS, so that
     *  unbind(BINDINGS, k), where k is the initial size of BINDINGS,
     *  will restore all bindings to their previous states.  If unsuccessful,
     *  leaves BINDINGS, restoring all type to their original binding state
     *  and returning false. */
    bool unify (Type_Ptr type, Unwind_Stack& bindings);

    /** Unify THIS with TYPE, returning true iff successful. */
    bool unify (Type_Ptr type);

    /** Unify the two lists of types L1 and L2, returning true iff
     *  successful and appending new bindings to BINDINGS.  Otherwise
     *  returns false and does not change BINDINGS. */
    static bool unifyLists (AST_Ptr L1, AST_Ptr L2, Unwind_Stack& bindings);

    /** Pops and reverts all bindings recorded in BINDINGS until
     *  BINDINGS has size K.  */
    static void popBindings (Unwind_Stack& bindings, size_t k);

    /** True iff THIS would unify with TYPE.  Does not change
     *  bindings. */
    virtual bool unifies (Type_Ptr type);

    /** Return a copy of me with all unbound type variables replaced
     *  by fresh unbound variables. */
    Type_Ptr freshen ();

    /** Simultaneously freshen all unbound type variables in the trees in
     *  TYPES, replacing each TYPES[i] with a freshened version. */
    static void freshen (gcvector<Type_Ptr>& types);

    /** A new, unbound type variable. */
    static Type_Ptr makeVar ();

    /** True iff I am a type variable. */
    virtual bool isTypeVariable ();

    /** True if I contain any unbound type variables. */
    static bool hasFreeVariables(Type_Ptr type);

    /** Return a type equivalent to TYPE in which all nodes are replaced
     *  by their bindings. */
    static Type_Ptr replaceBindings (Type_Ptr type);

    NODE_BASE_CONSTRUCTORS_INIT (Type, AST_Tree, _binding (NULL));

protected:

    /** Bind me to TARGET.  Returns true and records the binding on
     *  BINDINGS if successful, and returns false (and does nothing) otherwise.
     *  Requires that I be unbound. */
    virtual bool bind (Type_Ptr target, Unwind_Stack& bindings);

    /** Undo my binding. */
    virtual void unbind ();

    /** Check that my current binding is appropriate: that I am a type
     *  variable or of the same operator as my binding and that our
     *  children unify.  Add any resulting new bindings to BINDINDS. Returns
     *  true if the binding succeeds, and otherwise false (leaving
     *  BINDINGS unchanged). Assumes I am bound, and that id nodes for
     *  named types have been decorated with the appropriate Decls. */
    virtual bool checkBinding (Unwind_Stack& BINDINGS);

    /** Used internally by replaceBindings to do most of the work,
     *  avoiding circular traversals. */
    Type_Ptr replaceBindings ();

    /** Used internally by hasFreeVariables to do most of the work,
     *  avoiding circular traversals. */
    bool hasFreeVariables ();

    /** Used internally by freshen to perform the traversal. */
    virtual Type_Ptr _freshen ();

private:
    Type_Ptr _binding;
    Type_Ptr _forward;
};

/** Unify a most-general function type having N formals with TYPE,
 *  returning true iff successful. */
extern bool makeFuncType (int n, Type_Ptr type);

/** Return a most-general function type having N formals. */
extern Type_Ptr makeFuncType (int n);

/** Return a most-general method type for a method of class CLAS
 *  having N>=1 formals. */
extern Type_Ptr makeMethodType (int n, Decl* clas);

/** The supertype of AST_Trees that represent expressions that have a
 *  type. */
class Typed_Tree : public AST_Tree {
public:

    Type_Ptr getType ();

    bool setType (Type_Ptr type);

protected:

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities);

    /** Computes my type, which is then cached by getType(). */
    virtual Type_Ptr computeType ();

    Type_Ptr _type;

    NODE_BASE_CONSTRUCTORS_INIT (Typed_Tree, AST_Tree, _type(NULL));

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

/** Auxiliary function used by the for_each_child_var */
static inline int
_replace_and_incr (AST_Ptr& node, int& k, AST_Ptr& new_child)
{
    int n = new_child == NULL ? 0
        : new_child->is_list () ? new_child->arity ()
        : 1;
    node->replace (k, new_child);
    return k += n;
}


/** Create an "id" node for the identifier TEXT, giving LOC as its
 *  location. TEXT must be a permanent string (that is, it must not
 *  get deallocated while the resulting node is in use.) */
extern AST_Ptr make_id (const char* text, const char* loc);

/** Convenience methods to create trees with given SYNTAX and various
 *  numbers of children. */
extern AST_Ptr consTree (int syntax);
extern AST_Ptr consTree (int syntax, const AST_Ptr& c0);
extern AST_Ptr consTree (int syntax, const AST_Ptr& c0, const AST_Ptr& c1);
extern AST_Ptr consTree (int syntax, const AST_Ptr& c0, const AST_Ptr& c1,
                         const AST_Ptr& c2);
extern AST_Ptr consTree (int syntax, const AST_Ptr& c0, const AST_Ptr& c1,
                         const AST_Ptr& c2, const AST_Ptr& c3);

#endif
