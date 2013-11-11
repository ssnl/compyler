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

#include <gc/gc_allocator.h>
#include <gc/gc_cpp.h>

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

/** Garbage-collected C++ strings. */
typedef std::basic_string< char, std::char_traits<char>, gc_allocator<char> >
_gcstring;

class gcstring : public _gcstring, public gc 
{
public:
    /* CAUTION: Do not initialize a std::string from a gcstring using the
     * standard copy constructor (string(a_gcstring)) or the 
     * assignment operator.  The GNU implementation uses reference counting
     * to share structure in such cases.  If the last object referencing
     * a given piece of string data is of type 'string', the standard delete
     * method will be called to deallocate it, even though it is supposed to
     * be GC-controlled storage.  */

    explicit gcstring () { }
    gcstring (const gcstring& x) : _gcstring(x) { }
    gcstring (const std::string& x) : _gcstring(x.data (), x.size ()) { }
    gcstring (const _gcstring& x) : _gcstring(x) { }
    gcstring (const gcstring& str, size_type pos, size_type len = npos)
        : _gcstring (str, pos, len) { }
    gcstring (const char* s) : _gcstring (s) { }
    gcstring (const char* s, size_type n) : _gcstring (s, n) { }
    gcstring (size_type n, char c) : _gcstring (n, c) { }
    template <class InputIterator>
    gcstring (InputIterator first, InputIterator last)
        : _gcstring(first, last) { }
};

/** Garbage-collected vectors. */

template <class T>
class gcvector : public std::vector<T, gc_allocator<T> >, public gc
{
    typedef std::vector<T, gc_allocator<T> > _gcvector;
public:
    explicit gcvector () : _gcvector() {}
    explicit gcvector (size_t n, const T& val = T()) :
        _gcvector (n, val) { }
    template <class InputIterator>
    gcvector (InputIterator first, InputIterator last) :
        _gcvector (first, last) { }
    gcvector (const gcvector<T>& x) : _gcvector (x) { }
    gcvector (const std::vector<T>& x) : 
        _gcvector (x.begin (), x.end ()) { }
};

/** Garbage-collected maps. */

template <class Key, class Value, class Compare = std::less<Key> >
class gcmap : public std::map<Key, Value, Compare, 
                              gc_allocator<std::pair<Key, Value> > >, public gc
{
    typedef std::map<Key, Value, Compare, 
                     gc_allocator<std::pair<Key, Value> > > _gcmap;

public:
    typedef typename _gcmap::key_compare key_compare;

    explicit gcmap (const key_compare& comp = key_compare())
        : _gcmap(comp) { }
    template <class InputIterator>
    gcmap (InputIterator first, InputIterator last,
         const key_compare& comp = key_compare())
        : _gcmap (first, last, comp) { }
    gcmap (const gcmap& x) : _gcmap (x) { }
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
 *     // Common definition of list type (for convenience).
 *     typedef gcvector<TYPE> list_obj;
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

#define YYDEFINE_LIST_TYPE(Name, ValueType)                                  \
    typedef gcvector< ValueType > Name ## _obj;                \
    typedef Name ## _obj* Name

#ifndef YY_DEFAULT_MAKE_TOKEN
# define YY_DEFAULT_MAKE_TOKEN _default_make_token
#endif

template <class Type>
class Simple_Value_Semantics {
public:
    typedef Type value_type;
    typedef gcvector<Type> list_obj;

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

    static inline gcstring text (value_type val) {
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
#define TOKEN_BASE_CONSTRUCTORS(Type, Supertype)                             \
                                                                             \
    Type (int syntax, const char* text, size_t len)                          \
        : Supertype (syntax, text, len) {                                    \
    }                                                                        \
                                                                             \
    Type (int syntax, const gcstring& text)                               \
        : Supertype (syntax, text) {                                         \
    }                                                                        \
                                                                             \
    Type (int syntax) : Supertype (syntax) { }
									    
/** As for TOKEN_BASE_CONSTRUCTORS, but used in cases where the TYPE's 
 *  constructors require trailing initializers. */
#define TOKEN_BASE_CONSTRUCTORS_INIT(Type, Supertype, ...)		     \
									     \
    Type (int syntax, const char* text, size_t len)		     \
        : Supertype (syntax, text, len), __VA_ARGS__ {		     \
    }									     \
									     \
    Type (int syntax, const gcstring& text)		     \
        : Supertype (syntax, text), __VA_ARGS__ {		     \
    }									     \
									     \
    Type (int syntax) : Supertype (syntax), __VA_ARGS__ { }

									    
/** Standard constructors, factory method, and factory object used to
 *  connect TYPE to the token-factory machinery.  SUPERTYPE is
 *  the immediate base type of TYPE. */
#define TOKEN_CONSTRUCTORS(Type, Supertype)                                  \
    TOKEN_BASE_CONSTRUCTORS (Type, Supertype)                                \
                                                                             \
    /** As for the CommonToken constructors, but the resulting token         \
     *  has the same concrete type as THIS. */                               \
    virtual NodePtr make (int syntax, const char* text, size_t len) {        \
	return new Type (syntax, text, len);                                 \
    }                                                                        \
                                                                             \
    /** As for the CommonToken constructors, but the resulting token         \
     *  has the same concrete type as THIS. */                               \
    virtual NodePtr make (int syntax, const gcstring& text) {             \
	return new Type (syntax, text);                                      \
    }                                                                        \
                                                                             \
    static const Type factory


/** As for TOKEN_CONSTRUCTORS, but used in cases where the TYPE's 
 *  constructors require trailing initializers. */
#define TOKEN_CONSTRUCTORS_INIT(Type, Supertype, ...)                        \
protected:                                                                   \
    TOKEN_BASE_CONSTRUCTORS_INIT (Type, Supertype, __VA_ARGS__)              \
                                                                             \
    /** As for the CommonToken constructors, but the resulting token         \
     *  has the same concrete type as THIS. */                               \
    virtual NodePtr make (int syntax, const char* text,                      \
			  size_t len) {                                      \
	return new Type (syntax, text, len);                                 \
    }                                                                        \
                                                                             \
    /** As for the CommonToken constructors, but the resulting token         \
     *  has the same concrete type as THIS. */                               \
    virtual NodePtr make (int syntax, const gcstring& text) {                 \
	return new Type (syntax, text);                                      \
    }                                                                        \
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
 *  themselves trees, and an "operator", which is a token. */

template <class Node, class Token, class Tree>
class CommonNode : public gc {
public:
    
    typedef Node* NodePtr;
    typedef gcvector<NodePtr> NodeVector;
    typedef typename NodeVector::const_iterator iterator;

    typedef Token Token_Type;
    typedef Tree Tree_Type;

    virtual ~CommonNode () { }

    /** The character sequence associated with this node. Empty if
     *  there is no associated sequence. */
    virtual gcstring as_string () const { return gcstring (); }
    /** The character sequence associated with this node, or NULL if
     *  there is none.  This value need not be null-terminated.  The
     *  caller should NOT delete it.  */
    virtual const char* as_chars () const { return NULL; }
    /** A null-terminated copy of the character array associated with 
     *  this node, or NULL if there is none.  The caller is
     *  responsible for deleting the returned value. */
    virtual char* chars_dup () const { return strdup (""); }
    /** The number of valid characters in the sequence returned by
     *  as_chars.  */
    virtual size_t text_size () const { return 0; }
    /** The Bison syntactic category associated with this token. */
    virtual int syntax () const { return -1; }

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
    virtual size_t arity () const { return 0; }

    /** Replace child(K) with VAL.  If VAL is a list, splices its
     *  sequence of values in place of the original child(K), moving
     *  subsequent children right (or left if VAL is the empty list) 
     *  as needed. Returns THIS. */
    virtual Node* replace (int k, const NodePtr& val) { 
	throw std::out_of_range ("no children to replace");
    }
    /** Insert VAL at position K, moving over existing children. 
        If VAL is a list, inserts all of its constituent values in turn.
        Returns THIS. */
    virtual Node* insert (int k, const NodePtr& val) {
	throw std::domain_error ("cannot insert");
    }
    /** Append VAL to the end of my kids.  If VAL is a list, appends
     *  all of its constituent values  Returns THIS. */
    virtual Node* append (const NodePtr& val) {
	throw std::domain_error ("cannot append");
    }

    /** Append the new children given by BEGIN .. END (standard STL 
     *  input iterators yielding NodePtr) to me. Returns THIS. */
    template <class InputIterator>
    Node* append (InputIterator start, InputIterator end) {
	for (InputIterator p = start; p != end; p++)
	    append (*p);
        return (Node*) this;
    }

    /** Print a representation of me on OUT, indenting each line by
     *  INDENT. */
    virtual void dump (std::ostream& out, int indent = 0) = 0;
    static void dump (NodePtr node, std::ostream& out, int indent = 0);

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
     *  NUL) with given SYNTAX.  */
    static NodePtr make_token (int syntax, size_t len, const char* text);
    /** A token whose string is TEXT (a NUL-terminated string) with given
     *  SYNTAX. */
    static NodePtr make_token (int syntax, const char* text);
    /** A token whose string is TEXT (a NUL-terminated string) with given
     *  SYNTAX.  */
    static NodePtr make_token (int syntax, const gcstring& text);
    /** A token with given SYNTAX that does not correspond to source
     *  text, but is intended merely for use as an operator. There is
     *  no guarantee of uniqueness. */
    static NodePtr make_token (int syntax);

protected:

    CommonNode () : _loc (NULL) { }

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

    static NodeVector* tree_exemplars;
    static NodeVector* token_exemplars;

    typedef gcmap<int, NodePtr> TokenMap;
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
     *  NUL) with given SYNTAX.  */
    CommonToken (int syntax, const char* text, size_t len);
    /** A token with given TEXT and SYNTAX. */
    CommonToken (int syntax, const gcstring& text);

    /** As for the CommonToken constructors, but the resulting token
     *  has the same concrete type as THIS. */
    virtual NodePtr make (int syntax, const char* text, size_t len);
    virtual NodePtr make (int syntax, const gcstring& text);

    /** If I own my text string, release it. */
    ~CommonToken ();

    gcstring as_string () const { 
	return gcstring (_text, _len); 
    }
    const char* as_chars () const { return _text; }
    char* chars_dup () const;
    size_t text_size () const { return _len; }
    int syntax () const { return _syntax; }

    Token* as_token () { return static_cast<Token*> (this); }

    Location_Type loc () const;

    /** A token is its own operator. */
    Node* oper () const { 
	return const_cast<Node*> (static_cast<const Node*> (this));
    }

    void dump (std::ostream& out, int indent);

protected:

    /** An exemplar, intended to serve as the factory for other tokens
     *  of the same concrete type (via the "make" method).  As a side effect,
     *  the created token is registered in Node's current node token
     *  factory, indexed under SYNTAX. */
    CommonToken (int syntax);

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

    NodePtr oper () const { return _oper; }
    Tree* as_tree () { return static_cast<Tree*> (this); }
    NodePtr child (int k) const { 
        return _kids.at (k); 
    }
    size_t arity () const { return _kids.size (); }
    NodePtr replace (int k, const NodePtr& val);
    NodePtr insert (int k, const NodePtr& val);
    NodePtr append (const NodePtr& c);
    NodePtr append (size_t n, va_list children);

    void dump (std::ostream& out, int indent = 0);

protected:
    NodePtr _oper;
    mutable gcvector<NodePtr> _kids;

    /** An exemplar, intended to serve as the factory for other tree nodes
     *  of the same concrete type (via the "make" method).  As a side effect,
     *  the created token is registered in Node's current node token
     *  factory, indexed under SYNTAX. */
    CommonTree (int syntax);

};



#define TEMPLATE template <class Node, class Token, class Tree>
#define MEMBER CommonNode<Node, Token, Tree>::

TEMPLATE typename MEMBER NodeVector* MEMBER tree_exemplars = NULL;
TEMPLATE typename MEMBER NodeVector* MEMBER token_exemplars = NULL;

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax, size_t len, const char* text)
{
    if (token_exemplars != NULL && syntax < (int) token_exemplars->size () 
	&& (*token_exemplars)[syntax] != NULL)
	return (*token_exemplars)[syntax]
	    ->as_token ()->make (syntax, text, len)->post_make ();
    return (new Token (syntax, text, len))->post_make ();
}

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax, const char* text)
{
    return make_token (syntax, strlen (text), text);
}

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax, const gcstring& text)
{
    if (token_exemplars != NULL && syntax < (int) token_exemplars->size () 
	&& (*token_exemplars)[syntax] != NULL)
	return (*token_exemplars)[syntax]
	    ->as_token ()->make (syntax, text)->post_make ();
    return (new Token (syntax, text))->post_make ();
}

TEMPLATE typename MEMBER TokenMap MEMBER non_source_tokens;

TEMPLATE typename MEMBER NodePtr MEMBER
make_token (int syntax)
{
    NodePtr& result = non_source_tokens[syntax];
    if (result == NULL) {
	result = make_token (syntax, (const char*) "");
    }
    return result;
}

TEMPLATE void MEMBER
register_tree (int syntax)
{
    if (tree_exemplars == NULL)
	tree_exemplars = new gcvector<NodePtr>;
    if (syntax >= (int) tree_exemplars->size ())
	tree_exemplars->resize (syntax+1);
    tree_exemplars->at (syntax) = this->as_tree ();
}

TEMPLATE void MEMBER
register_token (int syntax)
{
    if (token_exemplars == NULL)
	token_exemplars = new gcvector<NodePtr>;
    if (syntax >= (int) token_exemplars->size ())
	token_exemplars->resize (syntax+1);
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
dump (NodePtr node, std::ostream& out, int indent)
{
    if (node == NULL)
        out << "(null)";
    else
        node->dump (out, indent);
}

#undef MEMBER

    /* Additional bodies for CommonToken */

#define MEMBER CommonToken<Node, Token, Tree>::

TEMPLATE MEMBER
CommonToken (int syntax, const char* text, size_t len)
    : _text (text), _len (len), _syntax (syntax) {
}

TEMPLATE MEMBER
CommonToken (int syntax, const gcstring& text)
    : _text (GC_strndup(text.data (), text.size())), _len (text.size ()), 
      _syntax (syntax) {
}

TEMPLATE MEMBER
CommonToken (int syntax) 
    : _text (NULL), _len (0), _syntax (syntax) {
    Node::register_token (syntax);
}

TEMPLATE typename MEMBER NodePtr MEMBER
make (int syntax, const char* text, size_t len)
{
    return new Token (syntax, text, len);
}

TEMPLATE typename MEMBER NodePtr MEMBER
make (int syntax, const gcstring& text)
{
    return new Token (syntax, text);
}

TEMPLATE MEMBER
~CommonToken ()
{
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
    char* result = new char[_len+1];
    result[_len] = '\0';
    return (char*) memcpy (result, _text, _len);
}

TEMPLATE void MEMBER
dump (std::ostream& out, int indent)
{
    gcstring syntax_name = YYEXTERNAL_TOKEN_NAME (syntax ());
    gcstring text = as_string ();

    if ((syntax_name[0] == '"' 
	 && text.compare (0, gcstring::npos, 
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

TEMPLATE typename MEMBER NodePtr MEMBER
replace (int k, const NodePtr& val)
{
    NodePtr old_val = _kids.at(k);
    if (val == old_val)
        return this;
    if (val == NULL || val->oper () == NULL) {
	Tree* L = val->as_tree ();
	if (L == NULL || L->arity () == 0)
	    _kids.erase (_kids.begin () + k);
	else {
	    _kids[k] = L->child (0);
	    _kids.insert (_kids.begin () + k + 1, 
			  L->_kids.begin () + 1, L->_kids.end ());
	}
    } else
	_kids[k] = val;
    return this;
}

TEMPLATE typename MEMBER NodePtr MEMBER
insert (int k, const NodePtr& val)
{
    if (val == NULL)
        return this;
    if (val->oper () == NULL) {
        Tree* L = val->as_tree ();
        _kids.insert (_kids.begin () + k, L->_kids.begin (), L->_kids.end ());
    } else
        _kids.insert (_kids.begin () + k, val);
    return this;
}        

TEMPLATE typename MEMBER NodePtr MEMBER
append (const NodePtr& val)
{
    if (val != NULL) {
	if (val->oper () == NULL) {
	    Tree* L = val->as_tree ();
	    if (L->arity () > 0)
		_kids.insert (_kids.end (), L->_kids.begin (), L->_kids.end ());
	} else 
	    _kids.push_back (val);
    }
    return this;
}

TEMPLATE typename MEMBER NodePtr MEMBER
append (size_t n, va_list children) {
    for (size_t i = 0; i < n; i += 1)
	append (va_arg (children, NodePtr));
    return this;
}

TEMPLATE void MEMBER
dump (std::ostream& out, int indent)
{
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
    typedef gcvector<value_type> list_obj;

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

    static inline gcstring text (value_type val) {
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
