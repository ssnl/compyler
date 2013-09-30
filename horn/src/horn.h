/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

#ifndef _HORN_H
#define HORN_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <stdexcept>
#include <sstream>
#include <cstdarg>
#include "xalloc.h"

#define DATA_DIR_TAIL "lib/"

#define PARSER_TEMPLATE_FILE_TAIL "parser-template.y"
#define LEXER_TEMPLATE_FILE_TAIL "lexer-template.l"
#define INTERACTIVE_LEXER_TEMPLATE_FILE_TAIL "interactive-lexer-template.l"
#define PARSER_INCLUDE_FILE_TAIL "common-include.h"

extern std::string grammar_outfile;
extern std::string lexical_outfile;
extern std::string lex_generated_file;
extern std::string infile;
extern std::string file_root;
extern std::string data_dir;
extern std::string directory_separator;

extern std::string parser_template_file;

extern std::string api_namespace;

#define _ 

#define UNIMPLEMENTED1(prefix, name) \
    throw std::logic_error (#prefix #name " is unimplemented")

#define UNIMPLEMENTED2(prefix, name) UNIMPLEMENTED1(prefix, name)

#define UNIMPLEMENTED(name) UNIMPLEMENTED1(,name) 

#define UNIMPLEMENTED_METHOD(name) UNIMPLEMENTED2(member, name)

#define UNUSED __attribute__ ((unused))

struct Unit { };

extern Unit UNIT;

#define for_each(Var, Type, Vector)					     \
    for (vector<Type>::const_iterator					     \
	     Var ## _s = (Vector).begin(), Var ## _i = Var ## _s,	     \
	     Var ## _e = (Vector).end ();				     \
	 Var ## _i != Var ## _e; Var ## _i += 1) {			     \
         Type const Var = *Var ## _i;


#define for_each_var(Var, Type, Vector)					     \
    for (vector<Type>::iterator						     \
	     Var ## _s = (Vector).begin(), Var ## _i = Var ## _s,	     \
	     Var ## _e = (Vector).end ();				     \
	 Var ## _i != Var ## _e; Var ## _i += 1) {			     \
         typedef Type Var ## _t;					     \
         Var ## _t& Var = *Var ## _i;

#define gen_for_each(Var, Type, Obj)					     \
    for (Type::const_iterator Var ## _i = (Obj).begin (), 		     \
         Var ## _e = (Obj).end ();					     \
	 Var ## _i != Var ## _e; Var ## _i ++) {			     \
         typedef Type::value_type Var ## _t;				     \
	 Var ## _t const Var = *Var ## _i;

#define gen_for_each_var(Var, Type, Obj)				     \
    for (Type::iterator Var ## _i = (Obj).begin (), 		     \
         Var ## _e = (Obj).end ();					     \
	 Var ## _i != Var ## _e; Var ## _i ++) {			     \
         typedef Type::value_type Var ## _t;				     \
	 Var ## _t& Var = *Var ## _i;

#define end_for }

#define kids_preorder(Method, Args)					     \
    for (int _i_ = 0; _i_ < arity (); _i_ += 1) {			     \
        child (_i_)->Method Args;					     \
    }

#define kids_preorder_replace(Method, Args)				     \
    for (int _i_ = 0; _i_ < arity (); _i_ += 1) {			     \
        replace (_i_, child (_i_)->Method Args);			     \
    }

#define kids_preorder_replace_reverse(Method, Args)			     \
    for (int _i_ = arity ()-1; _i_ >= 0; _i_ -= 1) {			     \
        replace (_i_, child (_i_)->Method Args);			     \
    }

class Node;
class Token;
class Tree;
class List;

class Lex_Set;

/** True if %output-ast declared. */
extern bool producing_trees;
extern std::string semantic_params;
extern std::string semantic_type;
extern std::string token_factory;
extern std::string error_function_name;

/* Major kludge:  on some systems (MacOS X, e.g.), strings don't
 * entirely work until after static initialization (the representation
 * for the empty string is not done).  This flag allows us to test for
 * that state and take precautions. */
extern bool init_phase_done;

/** True if we are building a parser that should read only as much as
 *  needed for each lexical or grammatical step. */
extern bool interactive_parser;

				/* Lexical items */

typedef const char* location;

#define YYLTYPE_IS_DECLARED 1
typedef const char* YYLTYPE;


struct lstring {
    lstring (const char *s) 
	: len (strlen (s)), start (s) {} 
    
    lstring (const char *s, size_t len) : len (len), start (s) {}

    lstring (const lstring &s) : len (s.len), start (s.start) {}

    /** S must be permanent */
    lstring (const std::string& s) : len (s.size ()), start (s.data ()) { }

    /** A null string, which is both empty and part of any
     *  text_buffer. */
    lstring () : len (0), start (NULL) {}

    bool is_null () const {
	return start == NULL;
    }

    std::string as_string () const {
	return std::string(start, len);
    }

    bool operator== (const char* x) const {
	return len == strlen (x) && strncmp (start, x, len) == 0;
    }
    bool operator!= (const char* x) const {
	return len != strlen (x) || strncmp (start, x, len) != 0;
    }

    int compare (const lstring& x) const {
	int len2 = len < x.len ? len : x.len;
	int c = strncmp (start, x.start, len2);
	if (c == 0)
	    return len - x.len;
	else
	    return c;
    }

    std::string& insert_into (std::string& str,
			      size_t s = std::string::npos) const {
	str.insert ((s == std::string::npos) ? str.size () : s, start, len);
	return str;
    }

    void fprintf (FILE *out) const {
      ::fprintf (out, "%.*s", (int) len, start);
    }

    size_t len;
    const char *start;
};

extern const lstring NULL_LS;

/** A text_buffer is a mutable string that may be annotated with
 *  deletions, insertions, and replacements of its contents whose
 *  effect on the contents of the string are usually delayed until the
 *  buffer's contents are to be written out or otherwise exported.
 *  After the initial data is set and before the contents are exported,
 *  the data may be manipulated freely and assumed not to move.  */
class text_buffer {
    friend class annotation_compare;

public:

    /** An empty text file. */
    text_buffer ();

    /** Release all dynamic data, invalidating contents. */
    ~text_buffer ();

    /* Queries */

    /** The total length of text in THIS, accounting for annotations. */
    size_t size () const;

    /** The length of text in data () (not accounting for
     *  annotations). */

    size_t data_size () const;

    /** The data in THIS. */
    char* data ();

    /** True iff there have been modifications posted against data
     *  since the last clear () or append (). */
    int num_modifications () const;

    /* Creating lstrings */
    
    /** The value of lstring (TEXT, LEN), if TEXT and LEN are within
     *  the bounds of THIS. */
    lstring substr (const char* text, size_t len);

    /** The lstring spanning S0 and S1, assuming they are both in
     *  THIS. */
    lstring join (lstring s0, lstring s1);

    /** The leftmost of S0 and S1, or the span of S0 and S1 if they
     *  overlap or adjoin, assuming they are both in THIS. */
    lstring left_join (lstring s0, lstring s1);

    /* Operations that set the initial data. */

    /** Append STR[0 .. LEN-1] to end of THIS.  Invalidates prior
     *  value of data (). */
    void append (const char *str, size_t len);
    /** Append STR to end of THIS.  Invalidates prior
     *  value of data (). */
    void append (const std::string& str);

    /** Clear current contents of THIS.  Invalidates prior value of
     *  data (). */
    void clear ();

    /* Modifiers that do not invalidate initial data (but may change
     * its contents). */

    /** Annotate to insert TEXT[0 .. LEN-1] before POSN, which must be within
     *  data ().  Does not change contents of data (). */
    void insert (const char* posn, const char* text, size_t len);
    void insert (lstring& posn, const char* text, size_t len);
    void insert (const char* posn, const std::string& text);
    void insert (lstring& posn, const std::string& text);

    /** Annotate to insert TEXT[0 .. LEN-1] after POSN, which must be within
     *  data ().  Does not change contents of data (). */
    void insert_after (lstring& posn, const char* text, size_t len);
    void insert_after (lstring& posn, const std::string& text);
    
    /** Annotate to remove TEXT[0 .. LEN-1], which must be within data ().
     *  Does not change contents of data (). */
    void erase (const char* text, size_t len);
    void erase (lstring& text);

    /** Annotate to replace TEXT[0 .. LEN-1], which must be within
     *  data (), with REPL[0 .. RLEN-1].  TEXT is not modified.
     *  [4 variants].  */
    void replace (char* text, size_t len, const char* repl, size_t rlen);
    void replace (char* text, size_t len, const std::string& repl);
    void replace (const lstring& text, const char* repl, size_t rlen);
    void replace (const lstring& text, const std::string& repl);

    /* Exporters */

    /** Write current contents, as modified by annotations, to OUT.
     *  Returns true iff successful.  */
    void fwrite (FILE* out);

    /** Return current contents, as modified by annotations, as a
     *  string. */
    std::string as_string ();
    std::string* as_string_ptr ();
    /** Append current contents, as modified by annotations, to OUT. */
    void write (std::string& out);
    void write (std::ostream& out);

    /** Return up to SIZE characters of contents, as modified by annotations,
     *  in OUT.  Returns the number of characters transferred, which
     *  is always min(SIZE, size()). */
    size_t write (char* out, size_t size);

private:

    /** No copy constructor. */
    text_buffer (const text_buffer&) { 
	throw std::domain_error ("no copy constructor for text_buffer"); 
    }

    /** No assignment operator. */
    text_buffer& operator= (const text_buffer&) { 
	throw std::domain_error ("text_buffers are not assignable");
    }

    void check_include (const char *std, size_t len) const;
    void check_include (lstring) const;
    void check_include1 (const char *std, size_t len) const;
    void check_include1 (lstring) const;
    void check_annotations () const;

    std::string _data;
    size_t _size;
    typedef std::pair<lstring, std::string> annotation;
    std::vector<annotation> _annotations;
    
};

extern std::string current_file;
extern std::string program_name;
extern text_buffer input_buffer;

extern std::string format_string (const char* message, ...);

extern bool resync_flag;

				/* Errors and warnings. */

enum warnings
  {
    warnings_none             = 0,      /**< Issue no warnings.  */
    warnings_error            = 1 << 0, /**< Warnings are treated as errors.  */
    warnings_midrule_values   = 1 << 1, /**< Unset or unused midrule values.  */
    warnings_yacc             = 1 << 2, /**< POSIXME.  */
    warnings_all              = ~warnings_error /**< All above warnings.  */
  };
/** What warnings are issued.  */
extern int warnings_flag;

/** Informative messages, but we proceed.  */

void warn (char const *format, ...)
  __attribute__ ((__format__ (__printf__, 1, 2)));

void warn_at (location loc, char const *format, ...)
  __attribute__ ((__format__ (__printf__, 2, 3)));

/* Generate a message aligned by an indent.
   When *indent == 0, assign message's indent to *indent,
   When *indent > 0, align the message by *indent value. */
void warn_at_indent (location loc, unsigned *indent,
                     char const *format, ...)
  __attribute__ ((__format__ (__printf__, 3, 4)));

/** An error, but we continue and die later.  */

void complain (char const *format, ...)
  __attribute__ ((__format__ (__printf__, 1, 2)));

void complain_at (location loc, char const *format, ...)
  __attribute__ ((__format__ (__printf__, 2, 3)));

/* Generate a message aligned by an indent.
   When *indent == 0, assign message's indent to *indent,
   When *indent > 0, align the message by *indent value. */
void complain_at_indent (location loc, unsigned *indent,
                         char const *format, ...)
  __attribute__ ((__format__ (__printf__, 3, 4)));

/** A fatal error, causing immediate exit.  */

void fatal (char const *format, ...)
  __attribute__ ((__noreturn__, __format__ (__printf__, 1, 2)));

void fatal_at (location loc, char const *format, ...)
  __attribute__ ((__noreturn__, __format__ (__printf__, 2, 3)));

/** Whether an error was reported.  */
extern bool complaint_issued;

extern location current_complaint_location;

static inline location set_err_loc (location loc) {
    location old = current_complaint_location;
    current_complaint_location = loc;
    return old;
}


				/* Nodes */

#define EMPTY new List ()
#define LIST(...) new List (__VA_ARGS__, NULL)
#define TREE(...) Tree::make (__VA_ARGS__, NULL)

typedef Node* NodePtr;
typedef std::vector<Node*> Node_Vector;
typedef std::set<std::string> String_Set;
typedef std::map<std::string, Node*> Token_Map;
struct Implicit_Token {
    Implicit_Token () : text (NULL), sym (NULL), user_action (NULL) { }
    NodePtr text;
    NodePtr sym;
    NodePtr user_action;
};
typedef std::map<std::string, Implicit_Token> Implicit_Token_Map;    

class Node {
    struct Node_Compare {
	bool operator () (Node* x, Node* y) {
	    return x->compare (y) < 0;
	}
    };

public: 
   
    typedef std::set<Node*, Node_Compare> Node_Set;

    virtual ~Node ();

    virtual Node* copy ();

    /* Locations */

    void set_loc (location loc) { this->loc = loc; }
    location get_loc () const;

    /* Tokens */

    virtual lstring text () const;
    virtual lstring preceding_ws () const;
    virtual void set_preceding_ws (lstring ws) = 0;
    std::string as_string () const {
	return text ().as_string ();
    }
    virtual location set_err_loc ();

    virtual bool is_leaf () const;
    /** True iff I am a literal constant. */
    virtual bool is_literal () const;
    virtual int syntax () const;

    /* Trees */

    virtual Token* oper () const;
    virtual Node* child (int i) const;
    virtual int arity () const;
    virtual int compare (Node* x) = 0;

    virtual void replace (int i, Node* val, size_t n = 1);
    /** Swap my children with the contents of KIDS. */
    void swap (Node_Vector& kids);

    virtual const Node_Vector& children () const;

    /** Return my children as a list. */
    virtual Node* extract_to_list ();
    
    virtual Token* first_token () = 0;

    virtual Node* add (Node* child, int k = -1);
    virtual Node* merge (Node* tree, int k = -1);
    virtual Node* dadd (Node* child, int k = -1);

    virtual bool is_rhs_item () const;

    virtual bool is_action () const;

    virtual bool is_empty_list ();
    virtual List* as_list ();
    virtual Token* as_token ();
    virtual Lex_Set* as_set ();

    virtual void to_string (std::stringstream& out, int indent = 0) const = 0;

    std::string to_string () const {
	std::stringstream s;
	to_string (s, 0);
	return s.str ();
    }

    virtual void write_grammar (std::ostream& out) const = 0;
    static void declare_tokens (std::ostream& out);

				/* Semantic */

    /** True iff I perform "administrative" actions---pushing the
     *  semantic variable frame, moving tokens to the semantic stack,
     *  etc. */
    virtual bool does_admin () const;

    /** True iff I contain a use of the special Bison token
     *  'error'. */
    virtual bool uses_error_token () const;

    /** Modify me to remove extended BNF constructs: +, *, ?, (...). 
     *  Returns modified node. */
    virtual Node* rewrite_extended ();

    /** Remove any top-level alternative ("|") operators within me,
     *  transferring my alternatives, if necessary, to a generated rule.
     *  Returns the modified version (either the original node or a 
     *  generated rule). */
    virtual Node* convert_choices ();

    /** Generate the lexer. */
    static void process_lexical (const std::string& input_name,
				 std::ostream& out);

    /** Ensure that I have a single trailing action, adding one if necessary,
     *  and that, aside from the trailing action, I have no empty
     *  actions.  Returns me as modified. */
    virtual Node* normalize_action ();

    /** If I am an empty action, returns the empty list, otherwise
     *  me. */
    virtual Node* replace_null_action ();

    /** Insert necessary generated code my actions to carry out the
     *  formation of semantic values.
     *
     *  LEFT_CONTEXT contains all the 
     *  grammar symbols and actions in all rules that enclose me
     *  that will be on the parsing stack before me during compilation.
     *  If I am part of a generated rule, then symbols from the rules
     *  that enclose it will be in LEFT_CONTEXT.  For example, if I am d in
     *      a: b (c d | ...) 
     *  then I will be part of a generated rule:
     *      a:   b __1 ;
     *      __1: c d  | ...
     *  and LEFT_CONTEXT should be [ b, c ].  Update LEFT_CONTEXT as 
     *  necessary for items to my right.
     *
     *  FIRST_INDEX will contain
     *  the index in LEFT_CONTEXT of the first symbol in my rule (what
     *  Bison would call $1).  Thus, in the example, FIRST_INDEX would
     *  be 1, and Bison would refer c as $1 and to b as $0.  
     *  
     *  DEPTH is the number of generated rules I'm nested in.  In the
     *  example above, DEPTH would be 1. 
     *
     *  CURRENT_OUTER_ACTION is the last action in the right-hand side
     *  of which I am a part. */
    virtual void add_generated_semantics (Node_Vector& left_context, 
                                          int first_index, int depth,
                                          NodePtr current_last_action);

    /** Write any necessary code to mark the auxiliary semantic action
     *  stack (yysemact), assuming that $MY_INDEX denotes me to
     *  Bison. */
    virtual void mark_actions (std::ostream& out, int my_index);

    /** Write any code necessary to assign semantic values I define to
     *  to named variables ($varname) to OUT, assuming that $MY_INDEX
     *  denotes me to Bison. */
    virtual void write_var_assigns (std::ostream& out, int my_index);

    /** Add all grammar symbols defined in me to the global symbol
     *  collection, and also check that uses of variables in each
     *  encountered action are kosher.  SYMS contains the set of
     *  symbols known to be visible to me. */
    virtual void collect_check_vocab (String_Set& syms);

    /** The nonterminal symbol, if any, that I denote.  */
    virtual Token* id_of (); 

    /** The token used to refer to this symbol. */
    virtual Token* ref_name_of ();

    /** Last (non-embedded) action in me. */
    virtual Node* last_action_of () const;

    /** Replace generated rules contained in me with "interned"
     *  versions already found in INTERNED, if present, adding any not
     *  found to INTERNED.  Returns modified node. */
    virtual Node* intern_generated_rules (Node_Set& interned);

    /** If this is an applicable rule, replace the dummy
     *  self-referencing symbol throughout with NEW_VAR or (if that is
     *  null) with a new, unique symbol.  */
    virtual void set_unique_id (Token* new_var);

    /** Replace all generated rules in right-hand sides with their
     *  grammar symbols.  Returns the modified nodes. */
    virtual Node* generated_rules_to_syms ();

    void process (std::ostream& out);

    /* Methods associated with tree formation (usually applicable only
     * when producing_trees). */

    enum Tree_Status { PROCESSED, NODE_FORMED, NODE_OPER, IGNORE, ABSORB };
    typedef std::vector<Tree_Status> Tree_Status_Vector;

				/* Lexical */

    /** Add a lexical rule for me (a character or string token). */
    virtual void add_implicit_token (Node* user_action = NULL);

    /** Add a lexical rule for me (a symbol), using DENOTATION as the 
     *  string alias. */
    virtual void add_explicit_token (Node* denotation);

    /** Add a lexical rule for me (a symbol), with no string alias. */
    virtual void add_explicit_token ();

    /** Check that I contain only correct references to lexical
     *  subrules. */
    virtual void check_lex_subrules ();

    /** True iff I am a lexical item that is certain to match (or look
     *  ahead) at least one character, if it matches at all. */
    virtual bool static_match_nonempty () const;

protected:

    Node () : loc (NULL) { }
    
public:
    static Node_Vector lexical_rules;
    static Node_Vector lexical_subrules;
    static Token_Map all_tokens;
    static String_Set explicit_tokens;
    static Implicit_Token_Map implicit_lexical_rules;

private:

    location loc;
};

extern std::ostream& operator<< (std::ostream& os, Node* node);

extern Token* const _TOKEN;

class Token : public Node {
public:
    Token (lstring text, lstring whitespace, int syntax)
	: _text (text), _preceding_ws (whitespace), _syntax (syntax)
	{ init_loc (); }
    Token (lstring text, int syntax) 
	: _text (text), _preceding_ws (NULL_LS), _syntax (syntax)
	{ init_loc (); }
    explicit Token (int syntax)
	: _text (NULL_LS), _preceding_ws (NULL_LS), _syntax (syntax)
	{ init_loc (); }
    explicit Token (const char* s) 
	: _text (lstring (s)), _preceding_ws (NULL_LS), _syntax (s[0])
	{ init_loc (); }

    Token* oper () const {
	return _TOKEN;
    }

    lstring text () const;
    lstring preceding_ws () const;
    void set_preceding_ws (lstring ws);
    int compare (Node* x);

    bool uses_error_token () const;

    int syntax () const { return _syntax; }
    bool is_literal () const;

    Token* first_token ();

    Token* as_token ();
    bool is_rhs_item () const;

    void to_string (std::stringstream& out, int indent = 0) const;

    void write_grammar (std::ostream& out) const;

    Token* id_of ();
    Token* ref_name_of ();

    bool does_admin () const;
    void add_generated_semantics (Node_Vector& left_context, 
                                  int first_index, int depth,
                                  NodePtr current_last_action);
    void write_var_assigns (std::ostream& out, int my_index);

    void collect_check_vocab (String_Set& syms);
    void get_index (const std::string& name, int& index,
		    bool& is_gram_var, bool& is_list, bool& is_shadowed);

    void add_implicit_token (Node*);
    void add_explicit_token (Node* denotation);
    void add_explicit_token ();

private:
    lstring _text, _preceding_ws;
    const int _syntax;

    void init_loc ();
};

extern Token* const No_Token;
extern const char* tokenName (int syntax);

class Tree : public Node {
public:

    explicit Tree (Node* op, Unit, bool reg = true);
    explicit Tree (Node* op);
    explicit Tree (int op, ...);
    Tree (va_list args, Node* op);

    static Node* make (Node* op, ...);
    static Node* make (int op, ...);
    static Tree* make (Node* op, Node_Vector& kids);

    lstring preceding_ws () const;
    void set_preceding_ws (lstring ws);
    int compare (Node* x);

    Token* first_token ();

    bool is_leaf () const;

    Token* oper () const;
    Node* child (int i) const;

    void replace (int i, Node* val, size_t n=1);
    void swap (Node_Vector& kids);
    Node* extract_to_list ();

    int arity () const { return _kids.size (); }
    const Node_Vector& children () const;
    
    Node* add (Node* child, int k = -1);
    Node* merge (Node* tree, int k = -1);
    Node* dadd (Node* child, int k = -1);

    void to_string (std::stringstream& out, int indent = 0) const;

    void write_grammar (std::ostream& out) const;

				/* Semantic */

    Node* rewrite_extended ();
    Node* process_new_rules ();
    Node* intern_generated_rules (Node_Set& interned);

				/* Lexical */

    bool static_match_nonempty () const;

protected:
    Tree* internal_copy ();

    virtual Node* make (Node* op, va_list args);
    virtual Tree* make (Node* op, Unit);
    bool register_me ();
    void add (va_list ap);

private:

    static std::map<int, Tree*>* exemplars;

    Token* _oper;
    Node_Vector _kids;

};

extern Token* const _LIST;

class List : public Tree {
public:

    List () : Tree ((Node*) _LIST) { }
    List (Node* first, ...);
    List (va_list ap) : Tree (ap, _LIST) {}

    bool is_empty_list ();
    List* as_list () { return this; }

    Node* copy ();

    void to_string (std::stringstream& out, int indent = 0) const;
};

				/* Target-language specific */

extern std::string lang_create_ref (const std::string& name);
extern std::string lang_manual_tree_creator ();
extern std::string lang_define_semantic_var (const std::string& name);

extern std::string lang_def_admin_var (bool outer, bool push_frame, 
                                       bool assemble_value, int n, int sym1);
extern std::string lang_mark_ignore (int index);
extern std::string lang_mark_op (int index);
extern std::string lang_assign (int index, const std::string& name);
extern std::string lang_append (int index, const std::string& name);
extern std::string lang_arguments ();
extern std::string lang_cfg_lhs ();
extern std::string lang_error_rule ();
extern bool lang_is_empty_action (const std::string& text);

extern std::string lang_lex_action (const std::string& syntax, 
				    const std::string& init);
extern std::string lang_lex_single_char_action ();
extern std::string lang_lex_lhs ();
extern std::string lang_lex_text ();
extern std::string lang_lex_text_size ();
				     
extern std::string lang_define_semantics (const std::string& params);
extern std::string lang_define_tree_semantics (const std::string& type);
extern std::string lang_define_simple_semantics (const std::string& type, 
						 const std::string& token_factory);
extern std::string lang_define_error_function (const std::string& name);


				/* Other function headers */

extern void copy_file (std::ostream& out, const char* infile_name,
                       size_t* newline_countp = NULL);
extern void copy_subst_file (std::ostream& out,
			     const char* infile_name,
			     std::map<std::string,std::string>& dict,
			     const char* outfile_name = NULL);
extern void copy_file_if_needed (const std::string& newfile_name, 
                                 const std::string& infile_name);

extern void set_symbol_prefix (const std::string& prefix);
extern Token* new_symbol ();

/** The line number on which *TEXT occurs. */
extern int location_line_number (location loc);

extern void write_resync (std::ostream& out, location loc);

/** Print LOC (relative to input file) on FILE in Unix format.
 *  Returns number of characters printed.  */
extern int location_print (FILE* file, location loc);

extern void gram_scanner_free ();

extern void gram_scanner_initialize (FILE *, const std::string&);

extern void gram_scanner_write_file (FILE *);

extern void action_scan (text_buffer& action, std::vector<lstring>& ref_vec);

extern int real_length (const std::string& s, int i = 0, 
			size_t e = std::string::npos);

extern Node* lex_action (Node* syntax, Node* action_tok);

extern std::string gen_timestamp (const std::string& src_file_name);

/** Default semantic type for parser. */
#define YYSTYPE NodePtr

extern const char* uniqstr_new (const char *);

extern void debug_tree (Node* t);

#endif
