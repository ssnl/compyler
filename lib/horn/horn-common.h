/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

/* This file contains code that is common to all Horn parsers and that
 * might also be used by other parts of the compilers that incorporate
 * these parsers and use the semantic values they generate. */

/* Copyright (C) 2011, 2012 by Paul N. Hilfinger and the Regents of the
 * University of California under terms of the BSD license. */

#ifndef _HORN_COMMON_H
#define _HORN_COMMON_H

#include <string>
#include <list>
#include <cassert>
#include <cstdlib>
#include <cstddef>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <iomanip>
#include <stdexcept>

#if !defined(__attribute__) && !defined(__GNUC__)
#  define __attribute__(LST)
#endif

#if !defined(UNUSED)
#  define UNUSED __attribute__ ((unused))
#endif

#ifdef YYNAMESPACE
#  define YYEXTERNAL_TOKEN_NAME YYNAMESPACE::yyexternal_token_name
namespace YYNAMESPACE {
   extern const char* yyexternal_token_name (int syntax);
};
#else
#  define YYEXTERNAL_TOKEN_NAME yyexternal_token_name
   extern const char* yyexternal_token_name (int syntax);
#endif

/** A mixin class that provides general-purpose reference-counted
 *  objects, in cooperation with the template type Pointer. The intended use:
 * 
 *      class YourType;
 *      typedef Pointer<YourType> YourTypePtr;
 *      class YourType : public RefCounted {
 *         ...
 *      };
 *      YourTypePtr ptr = new YourType(...);
 *      ptr->aMethod (...);
 *      etc.
 *
 *  Objects begin with a reference count of 0, and the pointer to them
 *  is then transferred to a Pointer, which functions as a C/C++
 *  pointer, but which also uses the reference count to track the total
 *  number of Pointers containing a reference to the object.
 *  When this count goes back to 0, the object finalizes and deletes
 *  itself.  If the reference count overflows, the object becomes
 *  permanent.
 * 
 *  Programs must not use a T* value or the object it points to after
 *  some operation on a Pointer has reduced the reference count of the
 *  object to 0.  Under certain assumptions, it is safe to manipulate 
 *  the T* value or its referent directly, where needed:
 *  1. After being assigned to Pointer<T>, a copy of a T* value can be
 *     considered valid until that Pointer<T> object is modified.
 *  2. Likewise, the T* value returned by the data method, which extracts
 *     the tracked pointer, is safe while the Pointer from which
 *     it was extracted remains unmodified.
 *  3. In an expression of the form P->f(...) or (*P).f(...) where P
 *     is a Pointer,  the 'this' object will remain valid throughout the 
 *     method call at least as long as P remains unmodified.
*/
class RefCounted {

    template <class T> friend class Pointer;

public:

    /** Mark this object not to be deallocated by reference counting. */
    void do_not_deallocate () { _count = SATURATED; }

protected:
    static const unsigned int SATURATED = ~(~0U >> 1);

    RefCounted () : _count (0) { }
    /** A permanent object. */
    RefCounted (bool) : _count (SATURATED) { }

private:

    mutable unsigned int _count;
    
};

/** A reference-counting pointer-to-T. Requires that T include RefCounted as a
 *  base class. */

template <class T>
class Pointer {
public:

    /** An initially null pointer. */
    Pointer () : _ptr (NULL) { }

    Pointer (T* ptr) : _ptr (ptr) {
	ref ();
    }

    /** A reference-counted version of PTR. */
    template <class T1>
    Pointer (T1* ptr) : _ptr (ptr) {
	ref ();
    }

    /** Copy constructors */
    Pointer (const Pointer& x) : _ptr (x.data ()) {
	ref ();
    }
    template <class T1>
    Pointer (const Pointer<T1>& x) : _ptr (x.data ()) {
	ref ();
    }

    ~Pointer () {
	unref ();
    }

    inline bool operator== (const Pointer& ptr) const {
	return _ptr == ptr._ptr;
    }

    inline bool operator== (const T* ptr) const {
	return ptr == _ptr;
    }

    inline bool operator!= (const Pointer& ptr) const {
	return _ptr != ptr._ptr;
    }

    inline bool operator!= (const T* ptr) const {
	return _ptr != ptr;
    }

    inline Pointer& operator= (const Pointer& ptr) {
	ptr.ref ();
	unref ();
	_ptr = ptr._ptr;
	return *this;
    }

    /** Set THIS to a reference-counted version of PTR. */
    inline Pointer& operator= (T* ptr) {
	unref ();
	_ptr = ptr;
	ref ();
	return *this;
    }

    inline T& operator* () const {
	return *_ptr;
    }

    inline T* operator-> () const {
	return _ptr;
    }

    /** An ordinary C++ pointer version of me.  CAUTION: This value is valid
     *  only until I am modified. */
    inline T* data () const {
	return _ptr;
    }

private:

    /** Increase reference count of my referenced object. */
    inline void ref () const { 
	if (_ptr) {
	    unsigned int& count = _ptr->_count;
	    _ptr->_count = (count + 1) | (count & RefCounted::SATURATED);
	}
    }

    /** Decrease reference count of my referenced object, and delete
     *  it if the reference count goes to 0. */
    inline void unref () const { 
	if (_ptr) {
	    unsigned int& count = _ptr->_count;
	    if (count < RefCounted::SATURATED && 
		(_ptr->_count = count - 1) == 0) {
		delete _ptr;
	    }
	}
    }

    T* _ptr;

};

/** We represent source locations as character pointers, assuming that
 *  there exists a mapping mechanism from character positions to
 *  source-code locations.  We are agnostic here about how this mapping is
 *  implemented, but we do assume that a copy of a C string will not
 *  in general represent the same source location. */
typedef const char* Location_Type;

/* The Horn framework is parameterized by a variety of functions and
 * types, which for convenience are to be packaged into a namespace or
 * class supplied by the client (its name is the argument of the %semantic-type
 * parameter).  Here are minimal components (items in angle brackets
 * are parameters). 

 * class <SEMANTICS> {
 *     // Type of semantic values, which will be available as the 
 *     // .value() attribute of grammar symbols.
 *     typedef <TYPE> value_type;
 *     
 *     // Default value of type value_type.
 *     value_type default_value ();
 *
 *     // Create a new value that represents the list of values between
 *     // the iterators BEGIN and END (for the first form) or the
 *     // empty list (for the second).  This operation is optional: it
 *     // may throw an exception if it makes no sense.  It must work
 *     // if the Horn tree-building operators are being used.
 *     template <class InputIterator>
 *     value_type make_list_value (InputIterator begin, InputIterator end);
 *     value_type make_list_value ();
 *
 *     // Create a new token value whose syntactic category is SYNTAX,
 *     // and whose text is TEXT[0 .. LEN-1].
 *     value_type default_make_token (int syntax, size_t len, const char* text);
 *
 *     // Create a new tree value whose operator is OP and whose 
 *     // children are supplied by the values between BEGIN and END.
 *     // The value of this function is irrelevant if the Horn 
 *     // tree-building operators are not being used, and it should raise
 *     // an exception if value_type does not support it.
 *     template <class InputIterator>
 *     value_type make_tree (value_type op, InputIterator begin, 
 *                           InputIterator end);
 *     // As above, but supply an operator (possibly shared) with 
 *     // given syntax.
 *     template <class InputIterator>
 *     value_type make_tree (value_type syntax, InputIterator begin, 
 *                           InputIterator end);
 *
 *     // Extract a source location from VAL.  Should yield NULL
 *     // if unavailable.
 *     Location_Type loc (value_type val);
 *
 *     // Set LOC as the source location for VAL, if possible.  This
 *     // operation does nothing if VAL does not carry location
 *     // information.
 *     void set_loc (value_type val, Location_Type loc);
 *
 *     // The source text associated with VAL, as a string.  Should 
 *     // yield an empty string if unavailable.
 *     string text (value_type val);
 *
 *     // The source text associated with VAL as a C string that need
 *     not be NUL-terminated. Should return NULL if not available.
 *     const char* c_text (value_type val);
 *     
 *     // The length of text associated with VAL (== text().size()).
 *     size_t text_size (value_type val);
 * }; 
 */

template <class Type>
class RefCountedList : public std::vector<Type>, public RefCounted {
public:
    typedef Pointer<RefCountedList> ListPtr;

    RefCountedList () { }
    RefCountedList (Type val) : std::vector<Type> (1, val) { }
    template <class InputIterator>
    RefCountedList (InputIterator begin, InputIterator end) 
	: std::vector<Type> (begin, end) { }

};

#define YYDEFINE_LIST_TYPE(Name, ValueType)                                  \
    typedef RefCountedList<ValueType> Name ## _obj;                          \
    typedef Pointer<Name ## _obj> Name

#ifndef YY_DEFAULT_MAKE_TOKEN
# define YY_DEFAULT_MAKE_TOKEN _default_make_token
#endif

template <class Type>
class Simple_Value_Semantics {
public:
    typedef Type value_type;

    static inline value_type default_value () {
	return value_type();
    }

    template <class InputIterator>
    static inline value_type make_list_value (InputIterator, InputIterator) {
	throw std::logic_error ("type cannot represent lists of values.");
    }

    static inline value_type make_list_value () {
	throw std::logic_error ("type cannot represent lists of values.");
    }

    static inline value_type default_make_token (int syn, size_t len,
						 const char* text);

    static inline Location_Type loc (value_type val) {
	return NULL;
    }

    static inline void set_loc (value_type val, Location_Type loc) {
    }

    static inline std::string text (value_type val) {
	return "";
    }

    static inline const char* c_text (value_type val) {
	return NULL;
    }

    static inline size_t text_size (value_type val) {
	return 0;
    }

private:
    static inline value_type _default_make_token (int, size_t, const char*) {
	return default_value ();
    }

};	    

/** Standard constructors used to connect TYPE to the node-factory
 *  machinery.  SUPERTYPE is the immediate base type of TYPE. */
#define NODE_BASE_CONSTRUCTORS(Type, Supertype)                              \
                                                                             \
    template <class InputIterator>                                           \
    Type (const Type::NodePtr& oper,                                         \
          InputIterator begin, InputIterator end)                            \
          : Supertype (oper, begin, end) {                                   \
    }                                                                        \
                                                                             \
    Type (int syntax) : Supertype (syntax) { }
									    
/** As for NODE_BASE_CONSTRUCTORS, but used in cases where the TYPE's 
 *  constructors require trailing initializers. */
#define NODE_BASE_CONSTRUCTORS_INIT(Type, Supertype, ...)                    \
                                                                             \
    template <class InputIterator>                                           \
    Type (const Type::NodePtr& oper,                                         \
          InputIterator begin, InputIterator end)                            \
          : Supertype (oper, begin, end), __VA_ARGS__ {                      \
    }                                                                        \
                                                                             \
    Type (int syntax) : Supertype (syntax), __VA_ARGS__ { }

/** Standard constructors, factory method, and factory object used to
 *  connect TYPE to the node-factory machinery.  SUPERTYPE is
 *  the immediate base type of TYPE. */
#define NODE_CONSTRUCTORS(Type, Supertype)                                   \
    NODE_BASE_CONSTRUCTORS (Type, Supertype)                                 \
                                                                             \
    NodePtr make (const Type::NodePtr& oper,                                 \
                  const Type::iterator& begin, const Type::iterator& end) {  \
	return new Type (oper, begin, end);                                  \
    }                                                                        \
                                                                             \
    NodePtr make (const Type::NodePtr& oper,                                 \
                  const Type::NodePtr* begin, const Type::NodePtr* end) {    \
	return new Type (oper, begin, end);                                  \
    }                                                                        \
                                                                             \
    static const Type factory

/** As for NODE_CONSTRUCTORS, but used in cases where the TYPE's 
 *  constructors require trailing initializers. */
#define NODE_CONSTRUCTORS_INIT(Type, Supertype, ...)                         \
protected:                                                                   \
    NODE_BASE_CONSTRUCTORS_INIT (Type, Supertype, __VA_ARGS__)               \
                                                                             \
    NodePtr make (const Type::NodePtr& oper,                                 \
                  const Type::iterator& begin, const Type::iterator& end) {  \
	return new Type (oper, begin, end);                                  \
    }                                                                        \
                                                                             \
    NodePtr make (const Type::NodePtr& oper,                                 \
                const Type::NodePtr* begin, const Type::NodePtr* end) {      \
	return new Type (oper, begin, end);                                  \
    }                                                                        \
                                                                             \
    static const Type factory

/** Define the standard factory object for TYPE, registering it with
 *  SYNTAX. */ 
#define NODE_FACTORY(Type, Syntax)                                           \
    const Type Type::factory (Syntax)

/** Standard constructors used to connect TYPE to the token-factory
 *  machinery.  SUPERTYPE is the immediate base type of TYPE. */
#define TOKEN_BASE_CONSTRUCTORS(Type, Supertype)			     \
									     \
    Type (int syntax, const char* text, size_t len, bool owner)		     \
        : Supertype (syntax, text, len, owner) {			     \
    }									     \
									     \
    Type (int syntax, const std::string& text, bool owner)		\
        : Supertype (syntax, text, owner) {			     \
    }									     \
									     \
    Type (int syntax) : Supertype (syntax) { }
									    
/** As for TOKEN_BASE_CONSTRUCTORS, but used in cases where the TYPE's 
 *  constructors require trailing initializers. */
#define TOKEN_BASE_CONSTRUCTORS_INIT(Type, Supertype, ...)		     \
									     \
    Type (int syntax, const char* text, size_t len, bool owner)		     \
        : Supertype (syntax, text, len, owner), __VA_ARGS__ {		     \
    }									     \
									     \
    Type (int syntax, const std::string& text, bool owner)		     \
        : Supertype (syntax, text, owner), __VA_ARGS__ {		     \
    }									     \
									     \
    Type (int syntax) : Supertype (syntax), __VA_ARGS__ { }

									    
/** Standard constructors, factory method, and factory object used to
 *  connect TYPE to the token-factory machinery.  SUPERTYPE is
 *  the immediate base type of TYPE. */
#define TOKEN_CONSTRUCTORS(Type, Supertype)				     \
    TOKEN_BASE_CONSTRUCTORS (Type, Supertype)				     \
									     \
    /** As for the CommonToken constructors, but the resulting token	     \
     *  has the same concrete type as THIS. */				     \
    virtual NodePtr make (int syntax, const char* text, 		     \
			  size_t len, bool owner) {			     \
	return new Type (syntax, text, len, owner);			     \
    }									     \
									     \
    /** As for the CommonToken constructors, but the resulting token	     \
     *  has the same concrete type as THIS. */				     \
    virtual NodePtr make (int syntax, const std::string& text, bool owner) { \
	return new Type (syntax, text, owner);				     \
    }									     \
									     \
    static const Type factory


/** As for TOKEN_CONSTRUCTORS, but used in cases where the TYPE's 
 *  constructors require trailing initializers. */
#define TOKEN_CONSTRUCTORS_INIT(Type, Supertype, ...)			     \
protected:								     \
    TOKEN_BASE_CONSTRUCTORS_INIT (Type, Supertype, __VA_ARGS__)		     \
									     \
    /** As for the CommonToken constructors, but the resulting token	     \
     *  has the same concrete type as THIS. */				     \
    virtual NodePtr make (int syntax, const char* text,			     \
			  size_t len, bool owner) {			     \
	return new Type (syntax, text, len, owner);			     \
    }									     \
									     \
    /** As for the CommonToken constructors, but the resulting token	     \
     *  has the same concrete type as THIS. */				     \
    virtual NodePtr make (int syntax, const std::string& text, bool owner) { \
	return new Type (syntax, text, owner);				     \
    }									     \
									     \
    static const Type factory

/** Define the standard factory object for TYPE, registering it with
 *  SYNTAX. */ 
#define TOKEN_FACTORY(Type, Syntax)                                           \
    const Type Type::factory (Syntax)


/** The base type for abstract syntax trees, meeting the basic requirements
 *  of the Horn tree-building facilities.  A tree consists of either a
 *  token (type CommonToken)---a leaf node---or an internal node (type
 *  CommonTree).  Internal nodes have 0 or more children, which are
 *  themselves trees, and an "operator", which is a token.

 *  Tree nodes are reference-counted, using the RefCounted mixin class
 *  and the Pointer class.  All references to tree nodes go through
 *  Pointer objects, to which each newly created Node pointer is 
 *  immediately transfered. */

template <class Node, class Token, class Tree>
class CommonNode : public RefCounted {
public:
    
    typedef Pointer<Node> NodePtr;
    typedef typename std::vector<NodePtr>::const_iterator iterator;

    typedef Token Token_Type;
    typedef Tree Tree_Type;

    /** Unreference all children and the operator. */
    virtual ~CommonNode () { sanity = 0; }

    /** The character sequence associated with this node. Empty if
     *  there is no associated sequence. */
    virtual std::string as_string () const { repcheck (); return std::string (); }
    /** The character sequence associated with this node, or NULL if
     *  there is none.  This value need not be null-terminated.  The
     *  caller should NOT delete it.  */
    virtual const char* as_chars () const { repcheck (); return NULL; }
    /** A null-terminated copy of the character array associated with 
     *  this node, or NULL if there is none.  The caller is
     *  responsible for deleting the returned value. */
    virtual char* chars_dup () const { repcheck (); return strdup (""); }
    /** The number of valid characters in the sequence returned by
     *  as_chars.  */
    virtual size_t text_size () const { repcheck (); return 0; }
    /** The Bison syntactic category associated with this token. */
    virtual int syntax () const { repcheck (); return -1; }

    /** A value serves as the source location for this node.  Although
     *  it is actually a const char*, it is not intended for use as a
     *  C-string value.  NULL denotes an unknown location. */
    virtual Location_Type loc () const = 0;
    
    /** Force loc() to LOC. */
    void set_loc (Location_Type loc) { _loc = loc; }

    /** The operator for this node.  */
    virtual Node* oper () const = 0;
    /** True iff I am a true list of trees. */
    virtual bool is_list () const { return oper () == NULL; }
    /** My value recast as a tree, or NULL if I am not a tree. */
    virtual Tree* as_tree () { return NULL; }
    /** My value recast as a token, or NULL if I am not a token. */
    virtual Token* as_token () { return NULL; }
    /** The Kth child of this node (numbering from 0). */
    virtual Node* child (int k) const { 
	throw std::out_of_range ("no children"); 
    }
    /** The number of children of this node. */
    virtual size_t arity () const { repcheck (); return 0; }

    /** Replace child(K) with VAL.  Unpacks and unreferences VAL if it
     *  is a list. Takes over one claim on each child inserted, and 
     *  unreferences the replaced child.  Returns THIS. */
    virtual Node* replace (int k, const NodePtr& val) { 
	throw std::out_of_range ("no children to replace");
    }
    /** Insert VAL at position K, moving over existing children. 
        Unpacks and dereferences VAL if it is a list. Takes over one 
        claim on each child inserted.  Returns THIS. */
    virtual Node* insert (int k, const NodePtr& val) {
	throw std::domain_error ("cannot insert");
    }
    /** Append VAL to the end of my kids.  Unpacks and dereferences
     *  VAL if it is a list.  Takes over one claim on each child added.
     *  Returns THIS. */
    virtual Node* append (const NodePtr& val) {
	throw std::domain_error ("cannot append");
    }

    /** Append the new children given by BEGIN .. END (standard STL 
     *  input iterators yielding NodePtr) to me. Returns THIS. */
    template <class InputIterator>
    Node* append (InputIterator start, InputIterator end) {
	repcheck ();
	for (InputIterator p = start; p != end; p++)
	    append (*p);
        return (Node*) this;
    }

    /** Print a representation of me on OUT, indenting each line by
     *  INDENT. */
    virtual void dump (std::ostream& out, int indent = 0) = 0;
    static void dump (Node* node, std::ostream& out, int indent = 0);
    static void dump (const NodePtr& node, std::ostream& out, int indent = 0);

    static NodePtr make_tree (const NodePtr& oper, 
                              const NodePtr* begin, const NodePtr* end);

    static NodePtr make_tree (int syntax, 
                              const NodePtr* begin, const NodePtr* end);

    static NodePtr make_tree (const NodePtr& oper, 
                              const iterator& begin, const iterator& end);

    static NodePtr make_tree (int syntax, 
                              const iterator& begin, const iterator& end);

    template <class InputIterator> 
    static NodePtr make_tree (const NodePtr& oper, 
                              InputIterator begin, InputIterator end); 

    template <class InputIterator>
    static NodePtr make_tree (int syntax,
                              InputIterator begin, InputIterator end);

    template <class InputIterator> 
    static NodePtr make_list (InputIterator begin, InputIterator end) {
	return make_tree ((NodePtr) NULL, begin, end);
    }

    static NodePtr make_list () {
	return make_tree ((NodePtr) NULL, (NodePtr*) NULL, (NodePtr*) NULL);
    }

    /** A token whose string is TEXT[0..LEN-1] (TEXT[LEN] need not be ASCII
     *  NUL) with given SYNTAX.  If OWNER, then the token assumes it
     *  owns the text and should release it when deleted.  */
    static NodePtr make_token (int syntax, size_t len, const char* text,
			      bool owner = false);
    /** A token whose string is TEXT (a NUL-terminated string) with given
     *  SYNTAX.  If OWNER, then the token assumes it owns the text and 
     *  should release it when deleted.  */
    static NodePtr make_token (int syntax, const char* text, bool owner = false);
    /** A token whose string is TEXT (a NUL-terminated string) with given
     *  SYNTAX.  If OWNER, then the token assumes it owns &TEXT the text and 
     *  should release it when deleted (WARNING: DON'T set OWNER to true
     *  unless TEXT is a heap-allocated object!).  If OWNER is false, saves
     *  a copy of TEXT. */
    static NodePtr make_token (int syntax, const std::string& text, 
			      bool owner = false);
    /** A token with given SYNTAX that does not correspond to source
     *  text, but is intended merely for use as an operator. There is
     *  no guarantee of uniqueness. */
    static NodePtr make_token (int syntax);

    /** Check the representation (cursorily) and complain if something 
     *  seems wrong. */
    void repcheck () const {
	if (sanity != 0xdeadbeef)
	    throw std::logic_error ("bad object");
    }

    /** Check the representations of each child (as for check()). */
    void repcheck_kids () const {
	for (size_t i = 0; i < arity (); i += 1)
	    if (child (i) != NULL) 
		child (i)->repcheck ();
    }

protected:

    CommonNode () : sanity (0xdeadbeef), _loc (NULL) { }

    /** The make_tree and make_token functions call this function on their
     *  completed results.  The user may override it to perform any
     *  desired checks or other actions.  By default, it does
     *  nothing and returns THIS. */
    virtual Node* post_make () { return (Node*) this; }

    /** Register me as a tree factory for trees of my concrete type,
     *  indexed under SYNTAX. */
    void register_tree (int syntax);
    /** Register me as a token factory for tokens of my concrete type,
     *  indexed under SYNTAX. */
    void register_token (int syntax);

private:

    /** A sanity check, set to a distinguished value on node
     *  construction, and set to 0 by the destructor (or to arbitrary
     *  values by memory errors). */
    mutable unsigned int sanity;

    static std::vector<NodePtr>* tree_exemplars;
    static std::vector<NodePtr>* token_exemplars;

    typedef std::map<int, NodePtr> TokenMap;
    static TokenMap non_source_tokens;

protected:

    Location_Type _loc;
};

/** A lexical token, which also functions as a leaf node.   A token's
 *  value includes an integer "syntax", representing the syntactic
 *  category of the token, and a "string" containing the external text 
 *  of the token.  A Token may, but need not, "own" the text of its token.
 *  If it does, then deleting the token also deletes the text.  */
template <class Node, class Token, class Tree> 
class CommonToken : public Node {
public:
    typedef typename Node::NodePtr NodePtr;

    /** A token whose string is TEXT[0..LEN-1] (TEXT[LEN] need not be ASCII
     *  NUL) with given SYNTAX.  If OWNED, then the token assumes it
     *  owns the text and should release it when deleted.  */
    CommonToken (int syntax, const char* text, size_t len, bool owner);
    /** A token with given TEXT and SYNTAX.  If OWNER is false, stores a 
     *  null-terminated copy of TEXT.  Otherwise, it deletes &text when
     *  destructed. */
    CommonToken (int syntax, const std::string& text, bool owner);

    /** As for the CommonToken constructors, but the resulting token
     *  has the same concrete type as THIS. */
    virtual NodePtr make (int syntax, const char* text, 
			 size_t len, bool owner);
    virtual NodePtr make (int syntax, const std::string& text, 
			 bool owner);

    /** If I own my text string, release it. */
    ~CommonToken ();

    std::string as_string () const { 
	Node::repcheck (); return std::string (_text, _len); 
    }
    const char* as_chars () const { Node::repcheck (); return _text; }
    char* chars_dup () const;
    size_t text_size () const { Node::repcheck (); return _len; }
    int syntax () const { Node::repcheck (); return _syntax; }

    Token* as_token () { return static_cast<Token*> (this); }

    Location_Type loc () const;

    /** A token is its own operator. */
    Node* oper () const { 
	Node::repcheck (); 
	return const_cast<Node*> (static_cast<const Node*> (this));
    }

    void dump (std::ostream& out, int indent);

protected:

    /** An exemplar, intended to serve as the factory for other tokens
     *  of the same concrete type (via the "make" method).  As a side effect,
     *  the created token is registered in Node's current node token
     *  factory, indexed under SYNTAX. */
    CommonToken (int syntax);

    const char* owned_source_chars;
    const std::string* owned_source_string;
    const char* _text;
    size_t _len;
    int _syntax;

};

/** A CommonTree is an internal node, with an operator and 0 or more
 *  child nodes.
 *
 *  Trees with NULL operators represent lists of nodes.  A list cannot
 *  be a child of a node.  Whenever one is included as a child of a
 *  tree (whether by construction, appending, or replacement), the
 *  resulting structure is "flattened", Perl-fashion.  Thus, replacing 
 *  a child with a 3-element list replaces one child with 3, moving
 *  the subsequent children over.  A node value of NULL is an
 *  alternative representation of an empty list (thus, children of
 *  trees are never NULL). */

template <class Node, class Token, class Tree>
class CommonTree : public Node {
    template <class InputIterator>
    inline void init_kids (InputIterator begin, InputIterator end) {
	_kids.reserve (end - begin);
	while (begin != end) {
	    NodePtr c = *begin;
	    begin++;
	    if (c == NULL)
		continue;
	    else if (c->is_list ()) {
		Tree* t = c->as_tree ();
		_kids.insert (_kids.end (), t->_kids.begin (), t->_kids.end ());
	    } else
                _kids.push_back (c);
	}
    }

public:
    
    typedef typename Node::NodePtr NodePtr;
    typedef typename Node::iterator iterator;

    template <class InputIterator>
    CommonTree (const NodePtr& oper, InputIterator begin, InputIterator end)
	: _oper (oper) {
	init_kids (begin, end);
    }
	
    template <class InputIterator>
    CommonTree (int syntax, InputIterator begin, InputIterator end)
	: _oper (Node::make_token (syntax)) {
	init_kids (begin, end);
    }
	
    /** As for the CommonTree constructor, but the resulting tree
     *  has the same concrete type as THIS.  We can't make this a
     *  template function because it has to be virtual.  Therefore, we
     *  use a particular InputIterator type: NodePtr*, which is
     *  compatible with our other machinery.  */
    virtual NodePtr make (const NodePtr& oper, const NodePtr* begin,
                          const NodePtr* end);
    virtual NodePtr make (const NodePtr& oper, 
                          const iterator& begin, const iterator& end);

    Location_Type loc () const;

    Node* oper () const { Node::repcheck (); return _oper.data (); }
    Tree* as_tree () { return static_cast<Tree*> (this); }
    Node* child (int k) const { 
        Node::repcheck (); return _kids.at (k).data (); 
    }
    size_t arity () const { Node::repcheck (); return _kids.size (); }
    Node* replace (int k, const NodePtr& val);
    Node* insert (int k, const NodePtr& val);
    Node* append (const NodePtr& c);
    Node* append (size_t n, va_list children);

    void dump (std::ostream& out, int indent = 0);

protected:
    NodePtr _oper;
    mutable std::vector<NodePtr> _kids;

    /** An exemplar, intended to serve as the factory for other tree nodes
     *  of the same concrete type (via the "make" method).  As a side effect,
     *  the created token is registered in Node's current node token
     *  factory, indexed under SYNTAX. */
    CommonTree (int syntax);

};



#define TEMPLATE template <class Node, class Token, class Tree>
#define MEMBER CommonNode<Node, Token, Tree>::

TEMPLATE std::vector<typename MEMBER NodePtr>* MEMBER tree_exemplars = NULL;
TEMPLATE std::vector<typename MEMBER NodePtr>* MEMBER token_exemplars = NULL;

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax, size_t len, const char* text, bool owner)
{
    if (token_exemplars != NULL && syntax < (int) token_exemplars->size () 
	&& (*token_exemplars)[syntax] != NULL)
	return (*token_exemplars)[syntax]
	    ->as_token ()->make (syntax, text, len, owner)->post_make ();
    return (new Token (syntax, text, len, owner))->post_make ();
}

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax, const char* text, bool owner)
{
    return make_token (syntax, strlen (text), text, owner);
}

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax, const std::string& text, bool owner)
{
    if (token_exemplars != NULL && syntax < (int) token_exemplars->size () 
	&& (*token_exemplars)[syntax] != NULL)
	return (*token_exemplars)[syntax]
	    ->as_token ()->make (syntax, text, owner)->post_make ();
    return (new Token (syntax, text, owner))->post_make ();
}

TEMPLATE typename MEMBER TokenMap MEMBER non_source_tokens;

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax)
{
    NodePtr& result = non_source_tokens[syntax];
    if (result == NULL) {
	result = make_token (syntax, (const char*) "", false);
	result->do_not_deallocate ();
    }
    return result;
}

TEMPLATE void MEMBER
register_tree (int syntax)
{
    if (tree_exemplars == NULL)
	tree_exemplars = new std::vector<NodePtr>;
    if (syntax >= (int) tree_exemplars->size ())
	tree_exemplars->resize (syntax+1);
    /* Although THIS does have type Tree, we can't use a dynamic_cast
     * because register_tree is called before the dynamic type of THIS
     * is set. */
    do_not_deallocate ();
    tree_exemplars->at (syntax) = this->as_tree ();
}

TEMPLATE void MEMBER
register_token (int syntax)
{
    if (token_exemplars == NULL)
	token_exemplars = new std::vector<NodePtr>;
    if (syntax >= (int) token_exemplars->size ())
	token_exemplars->resize (syntax+1);
    /* Although THIS does have type Token, we can't use a dynamic_cast
     * because register_tree is called before the dynamic type of THIS
     * is set. */
    do_not_deallocate ();
    token_exemplars->at (syntax) = this->as_token ();
}

TEMPLATE typename MEMBER NodePtr MEMBER
make_tree (const NodePtr& oper, const NodePtr* begin, const NodePtr* end)
{
    if (oper != NULL && tree_exemplars != NULL) {
	NodePtr exemplar;
	int syntax = oper->syntax();
	if (syntax < (int) tree_exemplars->size () 
	    && (exemplar = (*tree_exemplars)[syntax]) != NULL)
	    return exemplar->as_tree ()->make (oper, begin, end)->post_make ();
    }
    return ((NodePtr) (new Tree (oper, begin, end)))->post_make ();
}

TEMPLATE typename MEMBER NodePtr MEMBER
make_tree (int syntax, const NodePtr* begin, const NodePtr* end)
{
    return make_tree (Node::make_token (syntax), begin, end);
}

TEMPLATE template <class InputIterator>
typename MEMBER NodePtr MEMBER
make_tree (const NodePtr& oper, InputIterator begin, InputIterator end)
{
    if (oper != NULL && tree_exemplars != NULL) {
	NodePtr exemplar;
	int syntax = oper->syntax();
	if (syntax < (int) tree_exemplars->size () 
	    && (exemplar = (*tree_exemplars)[syntax]) != NULL)
	    return exemplar->as_tree ()->make (oper, begin, end)->post_make ();
    }
    return ((NodePtr) (new Tree (oper, begin, end)))->post_make ();
}

TEMPLATE template <class InputIterator>
typename MEMBER NodePtr MEMBER
make_tree (int syntax, InputIterator begin, InputIterator end)
{
    return make_tree (Node::make_token (syntax), begin, end);
}

TEMPLATE void MEMBER
dump (Node* node, std::ostream& out, int indent)
{
    if (node == NULL)
        out << "(null)";
    else
        node->dump (out, indent);
}


TEMPLATE void MEMBER
dump (const NodePtr& node, std::ostream& out, int indent)
{
    dump (node.data (), out, indent);
}


#undef MEMBER

    /* Additional bodies for CommonToken */

#define MEMBER CommonToken<Node, Token, Tree>::

TEMPLATE MEMBER
CommonToken (int syntax, const char* text, size_t len, bool owner)
    : owned_source_chars (owner ? text : NULL), owned_source_string (NULL),
      _text (text), _len (len), _syntax (syntax) {
}

TEMPLATE MEMBER
CommonToken (int syntax, const std::string& text, bool owner)
    : owned_source_chars (NULL), 
      owned_source_string (owner ? &text : new std::string (text)),
      _text (owned_source_string->data ()), _len (text.size ()), 
      _syntax (syntax) {
}

TEMPLATE MEMBER
CommonToken (int syntax) 
    : owned_source_chars (NULL), owned_source_string (NULL), _text (NULL),
      _len (0), _syntax (syntax) {
    Node::register_token (syntax);
}

TEMPLATE typename MEMBER NodePtr MEMBER
make (int syntax, const char* text, size_t len, bool owner)
{
    return new Token (syntax, text, len, owner);
}

TEMPLATE typename MEMBER NodePtr MEMBER
make (int syntax, const std::string& text, bool owner)
{
    return new Token (syntax, text, owner);
}

TEMPLATE MEMBER
~CommonToken ()
{
    Node::repcheck ();
    free (const_cast<char*> (owned_source_chars));
    delete owned_source_string;
}    

TEMPLATE Location_Type MEMBER
loc () const
{
    if (Node::_loc != NULL)
	return Node::_loc;
    else
	return (Location_Type) _text;
}

TEMPLATE char* MEMBER
chars_dup () const
{
    Node::repcheck ();
    char* result = new char[_len+1];
    result[_len] = '\0';
    return (char*) memcpy (result, _text, _len);
}

TEMPLATE void MEMBER
dump (std::ostream& out, int indent)
{
    Node::repcheck ();
    std::string syntax_name = YYEXTERNAL_TOKEN_NAME (syntax ());
    std::string text = as_string ();

    if ((syntax_name[0] == '"' 
	 && text.compare (0, std::string::npos, 
			  syntax_name, 1, syntax_name.size ()-2) == 0)
	|| (syntax_name[0] != '"'
	    && text == syntax_name))
	out << "<" << text << ">";
    else if (syntax_name[0] == '"')
	out << "<" << syntax_name.substr (1, syntax_name.size () - 2)
	    << " '" << text << "'>";
    else
	out << "<" << syntax_name << " '" << text << "'>";
}

#undef MEMBER

				/* Additional bodies for CommonTree */

#define MEMBER CommonTree<Node, Token, Tree>::

TEMPLATE Location_Type MEMBER
loc () const
{
    if (Node::_loc != NULL)
	return Node::_loc;
    for (size_t i = 0; i < _kids.size (); i += 1) {
	Location_Type kid_loc = child (i)->loc ();
	if (kid_loc != NULL)
	    return kid_loc;
    }
    return NULL;
}

TEMPLATE Node* MEMBER
replace (int k, const NodePtr& val)
{
    Node::repcheck ();
    if (val != NULL) 
	val->repcheck ();
    NodePtr old_val = _kids.at(k);
    if (val == old_val)
        return this;
    if (val == NULL || val->oper () == NULL) {
	Tree* L = val->as_tree ();
	if (L == NULL || L->arity () == 0)
	    _kids.erase (_kids.begin () + k);
	else {
	    L->repcheck_kids ();
	    _kids[k] = L->child (0);
	    _kids.insert (_kids.begin () + k + 1, 
			  L->_kids.begin () + 1, L->_kids.end ());
	}
    } else
	_kids[k] = val;
    return this;
}

TEMPLATE Node* MEMBER
insert (int k, const NodePtr& val)
{
    Node::repcheck ();
    if (val == NULL)
        return this;
    else
        val->repcheck ();
    if (val->oper () == NULL) {
        Tree* L = val->as_tree ();
        L->repcheck_kids ();
        _kids.insert (_kids.begin () + k, L->_kids.begin (), L->_kids.end ());
    } else
        _kids.insert (_kids.begin () + k, val);
    return this;
}        

TEMPLATE Node* MEMBER
append (const NodePtr& val)
{
    Node::repcheck ();
    if (val != NULL) {
	val->repcheck ();
	if (val->oper () == NULL) {
	    Tree* L = val->as_tree ();
	    L->repcheck_kids ();
	    if (L->arity () > 0)
		_kids.insert (_kids.end (), L->_kids.begin (), L->_kids.end ());
	} else 
	    _kids.push_back (val);
    }
    return this;
}

TEMPLATE Node* MEMBER
append (size_t n, va_list children) {
    for (size_t i = 0; i < n; i += 1)
	append (va_arg (children, NodePtr));
    return this;
}

TEMPLATE void MEMBER
dump (std::ostream& out, int indent)
{
    Node::repcheck ();
    if (oper () == NULL) {
	out << "[";
	for (size_t i = 0; i < arity (); i += 1) {
	    out << std::endl;
	    out << std::setw (indent+2) << "";
            Node::dump (child (i), out, indent+2);
	}
	out << "]";
    } else {
	out << "(" << YYEXTERNAL_TOKEN_NAME (oper ()->syntax ());
	for (size_t i = 0; i < arity (); i += 1) {
	    out << std::endl;
	    out << std::setw (indent+2) << "";
            Node::dump (child (i), out, indent+2);
	}
	out << ")";
    }
}
    
TEMPLATE MEMBER
CommonTree (int syntax) : _oper (NULL) {
    Node::register_tree (syntax);
}

TEMPLATE typename Node::NodePtr MEMBER
make (const NodePtr& oper, const NodePtr* begin, const NodePtr* end)
{
    return new Tree (oper, begin, end);
}

TEMPLATE typename Node::NodePtr MEMBER
make (const NodePtr& oper, const iterator& begin, const iterator& end)
{
    return new Tree (oper, begin, end);
}

#undef MEMBER
#undef TEMPLATE

				/* Interface to Horn tree-building. */

template <class Node> 
class Tree_Semantics {
public:

    typedef typename Node::NodePtr value_type;

    static inline value_type default_value () { return NULL; }

    template <class InputIterator>
    static inline value_type make_list_value (InputIterator begin, 
					      InputIterator end) {
        return Node::make_list (begin, end);
    }

    static inline value_type make_list_value () {
        return Node::make_list ();
    }

    template <class InputIterator>
    static inline value_type make_tree (value_type op,
					InputIterator begin, InputIterator end) {
	return Node::make_tree (op, begin, end);
    }

    template <class InputIterator>
    static inline value_type make_tree (int syntax,
					InputIterator begin, InputIterator end) {
	return Node::make_tree (syntax, begin, end);
    }

    static inline value_type default_make_token (int syntax, size_t len,
						 const char* text) {
	return Node::make_token (syntax, len, text);
    }

    static inline Location_Type loc (value_type val) {
	if (val == NULL)
	    return NULL;
	else
	    return val->loc ();
    }

    static inline void set_loc (value_type val, Location_Type loc) {
	if (val != NULL)
	    val->set_loc (loc);
    }

    static inline std::string text (value_type val) {
	if (val == NULL)
	    return "";
	else
	    return val->as_string ();
    }

    static inline const char* c_text (value_type val) {
	if (val == NULL)
	    return NULL;
	else
	    return val->as_chars ();
    }

    static inline size_t text_size (value_type val) {
	if (val == NULL)
	    return 0;
	else
	    return val->text_size ();
    }


};

#endif
