#include <cstdarg>
#include <set>
#include <climits>
#include <cassert>
#include "horn.h"
#include "parse-horn.h"


using namespace std;

bool producing_trees;
string semantic_params;
string semantic_type;
string token_factory;
string error_function_name;

static String_Set all_new_symbols;
static string nterm_prefix = "__.";

/* Terminology: A "permanent string" is a string object that is never
 * modified and released only on program exit.  For a permanent
 * string, s, s.data() and &s[0] may be assumed to be valid to program
 * exit.  */

/** New terminal symbols have the form __<base>.<numeral>, where
 *  <base> is either an identifier or empty.  We assume the user
 *  introduces no symbols of this form.  */

/** Create a new nonterminal symbol.  BASE forms part of the name, for 
 *  documentation purposes.  */
Token*
new_symbol ()
{
    for (int i = 0; ; i += 1) {
	char num[11];
	sprintf (num, "%d", i);
	string name = nterm_prefix + num;
	pair<String_Set::iterator, bool> probe = 
	    all_new_symbols.insert (name);
	if (probe.second) {
	    lstring name = lstring (probe.first->data ());
	    Token* result = new Token (name, " ", ID);
	    return result;
	}
    }
}

void
set_symbol_prefix (const string& prefix)
{
    nterm_prefix = "_" + prefix + "_";
}

Token* const new_rule_symbol = new_symbol ();

String_Set semantic_variables;

/** If not present, define semantic variable NAME. */
void
define_semantic_sym (const string& name)
{
    semantic_variables.insert (name);
}

static void
write_semantic_var_decls (ostream& out)
{
    gen_for_each (name, String_Set, semantic_variables) {
        out << lang_define_semantic_var (name);
    } end_for;
}

				/* Default definitions for Node */
#define member Node::

Node* member
copy ()
{
    return this;
}

Node* member
rewrite_extended ()
{
    return this;
}

Node* member
convert_choices ()
{
    UNIMPLEMENTED_METHOD (convert_choices);
}

void member
process (ostream& out)
{
    rewrite_extended ();
    out << this;
}

Node* member
normalize_action ()
{
    UNIMPLEMENTED_METHOD (normalize_action);
}

Node* member
replace_null_action ()
{
    return this;
}

bool member
does_admin () const
{
    return false;
}

bool member
uses_error_token () const
{
    for (int i = arity () - 1; i >= 0; i -= 1) 
        if (child (i)->uses_error_token ())
            return true;
    return false;
}

void member
add_generated_semantics (Node_Vector&, int, int, NodePtr)
{
}

void member
mark_actions (ostream&, int)
{
}

void member
write_var_assigns (ostream&, int)
{
}

void member
collect_check_vocab (String_Set& syms)
{
}

Node* member
last_action_of () const
{
    UNIMPLEMENTED_METHOD (last_action_of);
}

Node* member
intern_generated_rules (Node_Set& interned)
{
    return this;
}

Node* member
generated_rules_to_syms ()
{
    return this;
}

void member
set_unique_id (Token* new_sym)
{
}

#undef member

				/* Default definitions for Tree */

#define member Tree::

Node* member
copy ()
{
    Node_Vector new_kids;
    new_kids.resize (_kids.size ());
    for (int i = _kids.size () - 1; i >= 0; i -= 1)
	new_kids[i] = _kids[i]->copy ();
    Tree* result = make (oper (), new_kids);
    if (get_loc () != NULL)
	result->set_loc (get_loc ());
    return result;
}

Node* member 
rewrite_extended ()
{
    kids_preorder_replace_reverse (rewrite_extended, ());
    return this;
}

Node* member
intern_generated_rules (Node_Set& interned)
{
    kids_preorder_replace (intern_generated_rules, (interned));
    return this;
}

#undef member

				/* Semantic methods for Token */

#define member Token::

bool member
does_admin () const
{
    return this == new_rule_symbol;
}

bool member
uses_error_token () const
{
    return text () == "error";
}

void member
collect_check_vocab (String_Set& syms)
{
    if (this != new_rule_symbol && ! is_literal ()) {
        string name = as_string ();
        define_semantic_sym (name);
        syms.insert (name);
    }
}

void member
add_generated_semantics (Node_Vector& left_context, int, int, NodePtr) {
    left_context.push_back (this);
}

void member
write_var_assigns (ostream& out, int my_index)
{
    if (this == new_rule_symbol || is_literal ())
        return;
    string name = as_string ();
    if (name == "error")
        return;
    out << lang_assign (my_index, name);
}

#undef member	    


				/* GRAMMAR nodes */

class Grammar_Tree : public Tree {

    CONSTRUCTORS (Grammar_Tree, GRAMMAR);

protected:

    void write_grammar (ostream& out) const {
	map<string, string> dict;

	dict["timestamp"] = gen_timestamp (infile);

	if (!semantic_params.empty ())
	    dict["semantics"] = lang_define_semantics (semantic_params);
	else if (!semantic_type.empty () && producing_trees)
	    dict["semantics"] = 
		lang_define_tree_semantics (semantic_type);
	else if (!semantic_type.empty ())
	    dict["semantics"] =
		lang_define_simple_semantics (semantic_type, token_factory);
	else
	    dict["semantics"] = "";
	
	if (!error_function_name.empty ())
	    dict["error_function_define"] = 
		lang_define_error_function (error_function_name);
	else
	    dict["error_function_define"] = "";

	if (api_namespace == "")
	    dict["namespace"] = "";
	else if (api_namespace[0] == '\"')
	    dict["namespace"] = "#define YYNAMESPACE " +
		api_namespace.substr (1, api_namespace.size () - 2);
	else
	    dict["namespace"] = "#define YYNAMESPACE " + api_namespace;

        if (uses_error_token ()) 
            dict["error_rule"] = lang_error_rule ();

	{ 
	    stringstream body;
	    resync_flag = true;
	    body << child (0) << endl;
	    dict["user_defns"] = body.str ();
	}

	{
	    stringstream tokendefs;
	    declare_tokens (tokendefs);
	    dict["token_defs"] = tokendefs.str ();
	}

	{   
	    stringstream grammar;
	    grammar << child (1) << endl;
	    dict["grammar"] = grammar.str ();
	}

	{
	    stringstream epi;
	    resync_flag = true;
	    epi << child (2) << endl;
	    dict["user_epilogue"] = epi.str ();
	}

        {
            stringstream vars;
            write_semantic_var_decls (vars);
            dict["var_decls"] = vars.str ();
        }

	dict["generated_lexer_file"] = lex_generated_file;

	copy_subst_file (out, (data_dir + PARSER_TEMPLATE_FILE).c_str (),
                         dict, grammar_outfile.c_str ());
    }
};

EXEMPLAR(Grammar_Tree);


				/* Grouping nodes: (...) */

class Group_Tree : public Tree {

    CONSTRUCTORS (Group_Tree, '(');

protected:

    void write_grammar (ostream& out) const {
	out << "(" << child (0) << ") ";
    }

    bool is_rhs_item () const {
	return true;
    }
    
    Node* rewrite_extended () {
	Node* result = child (0)->rewrite_extended ()->convert_choices ();
	delete this;
	return result;
    }

};


EXEMPLAR(Group_Tree);
    
				/* RHS_CHOICES nodes */

class Rhs_Choices_Tree : public Tree {
    CONSTRUCTORS (Rhs_Choices_Tree, RHS_CHOICES);

protected:

    void write_grammar (ostream& out) const {
	out << child(0);
	for (int i = 1; i < arity (); i += 1)
	    out << endl << " | " << child (i);
    }

    void collect_check_vocab (String_Set& syms) {
        String_Set syms0 = syms;
	for (int i = 0; i < arity (); i += 1) {
            String_Set s = syms0;
	    child (i)->collect_check_vocab (s);
            syms.insert (s.begin (), s.end ());
	}
    }

    void add_generated_semantics (Node_Vector& left_context, int first_index,
                                  int depth, NodePtr last_action) {
	size_t init_context = left_context.size ();
	for (int i = 0; i < arity (); i += 1) {
	    child (i)->add_generated_semantics (left_context, 
                                                first_index, depth, last_action);
	    left_context.resize (init_context);
	}
    }
        
    Node* rewrite_extended () {
	location old = set_err_loc ();
	Tree::rewrite_extended ();
	::set_err_loc (old);
	if (arity () == 1) {
	    Node* result = child (0);
	    delete this;
	    return result;
	} else
	    return this;
    }

    Node* convert_choices () {
	Node* result;
	if (arity () == 1) {
	    result = new List (child (0));
	    delete this;
	}
	else
	    result = TREE (GENERATED_RULE, new_rule_symbol, this);
	return result;
    }

    void set_unique_id (Token* new_sym) {
	kids_preorder (set_unique_id, (new_sym));
    }

    Node* generated_rules_to_syms () {
	kids_preorder (generated_rules_to_syms, ());
	return this;
    }
    
};

EXEMPLAR(Rhs_Choices_Tree);

				/* RHS node */

class Rhs_Tree : public Tree {

    CONSTRUCTORS (Rhs_Tree, RHS);

    Node* add (va_list args) {
        Tree::add (args);
	for (int i = arity () - 1; i >= 0; i -= 1)
	    if (child (i)->is_rhs ())
		replace (i, child (i)->extract_to_list ());
	set_loc (get_loc ());  // ???
        return this;
    }

    bool is_rhs () const {
        return true;
    }

protected:

    void write_grammar (ostream& out) const {
	write_resync (out, get_loc ());
	if (arity () == 1)
	    out << "/* empty */ ";
	Tree::write_grammar (out);
    }

    Node* convert_choices () {
	return this;
    }

    int last_action_index () const {
	for (int i = arity ()-1; i >= 0; i -= 1) {
	    if (child (i)->is_action ())
		return i;
	    if (child (i)->is_rhs_item ())
		return -1;
	}
	return -1;
    }

    Node* last_action_of () const {
	int k = last_action_index ();
	if (k == -1)
	    return NULL;
	else
	    return child (k);
    }

    Node* normalize_action () {
        int place;
        place = last_action_index ();
	if (place == -1) {
            for (place = arity () - 1; place >= 0; place -= 1)
                if (child (place)->is_rhs_item ())
                    break;
            place += 1;
            Tree::add (TREE (ACTION), place);
	}
        place -= 1;
        while (place >= 0) {
            replace (place, child (place)->replace_null_action ());
            place -= 1;
        }
	return this;
    }

    void set_unique_id (Token* new_sym) {
	for (int i = 0; i < arity (); i += 1) {
	    if (child (i) == new_rule_symbol)
		replace (i, new_sym);
	}
    }

    void collect_check_vocab (String_Set& syms) {
	kids_preorder (collect_check_vocab, (syms));
    }

    Node* generated_rules_to_syms () {
	kids_preorder_replace (generated_rules_to_syms, ());
	return this;
    }

    void add_generated_semantics (Node_Vector& left_context, int first_index,
                                  int depth, NodePtr) {
        kids_preorder (add_generated_semantics, 
                       (left_context, first_index, depth, last_action_of ()));
    }
        
    Node* rewrite_extended () {
	for (int i = arity () - 1; i >= 0; i -= 1) {
	    Node* new_child = child (i)->rewrite_extended ();
	    if (new_child->is_rhs ())
		replace (i, new_child->extract_to_list ());
	    else
		replace (i, new_child);
	}
        normalize_action ();
	return this;
    }

};

EXEMPLAR(Rhs_Tree);


				/* RULES node */

class Rules_Tree : public Tree {
    
    CONSTRUCTORS (Rules_Tree, RULES);

protected:

    Node* rewrite_extended () {
	Tree::rewrite_extended ();
	Node_Set interned;
	intern_generated_rules (interned);
        gen_for_each (rule, Node_Set, interned) {
	    rule->set_unique_id (NULL);
	    add (rule);
	} end_for;
	generated_rules_to_syms ();
	return this;
    }
	
    Node* generated_rules_to_syms () {
	kids_preorder (generated_rules_to_syms, ());
	return this;
    }

};

const Rules_Tree Rules_Tree::exemplar (UNIT);

				/* PERCENTS node */

class Percents_Tree : public Tree {

    CONSTRUCTORS (Percents_Tree, PERCENTS);

};

EXEMPLAR (Percents_Tree);



				/* RULE node */

class Rule_Tree : public Tree {

    CONSTRUCTORS (Rule_Tree, RULE);

protected:

    void write_grammar (ostream& out) const {
	out << child (0) << " : " << child (1) << "\n;\n" << endl;
    }

    Node* rewrite_extended () {
	set_err_loc ();
	Tree::rewrite_extended ();
        
        String_Set syms;
	child (1)->collect_check_vocab (syms);

	Node_Vector left_context;
        child (1)->add_generated_semantics (left_context, 0, 0, NULL);
	return this;
    }
    
    Node* generated_rules_to_syms () {
	child (1)->generated_rules_to_syms ();
	return this;
    }

};

EXEMPLAR (Rule_Tree);

				/* GENERATED_RULE node */

class Generated_Rule_Tree : public Rule_Tree {
    
    SUBTYPE_CONSTRUCTORS (Generated_Rule_Tree, GENERATED_RULE, Rule_Tree);

protected:

    bool does_admin () const {
        return true;
    }

    bool is_rhs_item () const {
	return true;
    }

    void collect_check_vocab (String_Set& syms) {
        child (1)->collect_check_vocab (syms);
    }

    void add_generated_semantics (Node_Vector& left_context, 
                                  int first_index, int depth,
                                  NodePtr last_action) {
        size_t init_context = left_context.size ();
        child (1)->add_generated_semantics (left_context, init_context, depth+1,
                                            last_action);
        left_context.resize (init_context);
        left_context.push_back (this);
    }

    void set_unique_id (Token* new_sym) {
	if (new_sym == NULL) {
	    set_symbol_prefix ("");
	    new_sym = new_symbol ();
	}
	replace (0, new_sym);
	child (1)->set_unique_id (new_sym);
    }

    Node* intern_generated_rules (Node_Set& interned) {
	Tree::intern_generated_rules (interned);
	Node_Set::const_iterator rule = interned.insert (this).first;
	return *rule;
    }

    Node* generated_rules_to_syms () {
	child (1)->generated_rules_to_syms ();
	return child (0)->id_of ();
    }

};

EXEMPLAR (Generated_Rule_Tree);

				/* Closures and optional markings. */

class Suffix_Annotation_Tree : public Tree {

    BASE_CONSTRUCTORS (Suffix_Annotation_Tree, Tree);

public:

    void write_grammar (ostream& out) const {
	out << child (0) << oper ()->text ().as_string () << " ";
    }

    bool is_rhs_item () const {
	return true;
    }

};

class Star_Tree : public Suffix_Annotation_Tree {

    SUBTYPE_CONSTRUCTORS (Star_Tree, '*', Suffix_Annotation_Tree);

public:

    Node* rewrite_extended () {
	Tree::rewrite_extended ();
	Node* new_rule = TREE (GENERATED_RULE, new_rule_symbol, 
			       TREE (RHS_CHOICES,
				     TREE (RHS)->normalize_action (),
				     TREE (RHS, new_rule_symbol, child (0))
				     ->normalize_action ()));
	return new_rule;
    }

};

EXEMPLAR (Star_Tree);


class Plus_Tree : public Suffix_Annotation_Tree {

    SUBTYPE_CONSTRUCTORS (Plus_Tree, '+', Suffix_Annotation_Tree);

public:

    Node* rewrite_extended () {
	Tree::rewrite_extended ();
	Node* rhs_copy = child (0)->copy ();
	Node* new_rule = TREE (GENERATED_RULE, new_rule_symbol, 
			       TREE (RHS_CHOICES, 
				     TREE (RHS, child (0))
				     ->normalize_action (),
				     TREE (RHS, new_rule_symbol, rhs_copy)
				     ->normalize_action ()));
	return new_rule;
    }


};

EXEMPLAR (Plus_Tree);


class Optional_Tree : public Suffix_Annotation_Tree {

    SUBTYPE_CONSTRUCTORS (Optional_Tree, '?', Suffix_Annotation_Tree);

public:

    Node* rewrite_extended () {
	Tree::rewrite_extended ();
	Node* new_rule = TREE (GENERATED_RULE, new_rule_symbol, 
			       TREE (RHS_CHOICES,
				     TREE (RHS)->normalize_action (),
				     TREE (RHS, child (0))->normalize_action ()));
	return new_rule;
    }


};

EXEMPLAR (Optional_Tree);

				/* Actions ({...}) */

Token* ACTION_TOK = new Token (ACTION);

class Action_Tree : public Tree {

    CONSTRUCTORS (Action_Tree, ACTION);

protected:

    lstring text () const {
	if (arity () == 0)
	    return lstring ("", 0);
	else
	    return child (0)->text ();
    }

    bool is_action () const {
        return true;
    }

    bool does_admin () const {
        return true;
    }

    void write_grammar (ostream& out) const {
        if (arity () == 0)
            out << " { " << action_prefix << " }";
        else {
            out << child (0)->preceding_ws ().as_string ()
                << "{ " << action_prefix << convert_refs () << " } ";
        }
    }

    Tree* make (Node* op, Unit) {
	return new Action_Tree (op);
    }

    Node* copy () {
	Node_Vector new_kid;
	if (arity () > 0)
	    new_kid.push_back (new Token (child (0)->text (),
					  child (0)->preceding_ws (),
					  child (0)->syntax ()));
	Action_Tree* result = (Action_Tree*) Tree::make (oper (), new_kid);
        result->action_prefix = action_prefix;
	return result;
    }

    void collect_check_vocab (String_Set& dict) {
        // FIXME restore some static checking.
	if (arity () == 0)
	    return;
	vector<lstring> refs;
	text_buffer text;
	text.append (child (0)->text ().as_string ());
	action_scan (text, refs);
	for_each(ref, lstring, refs) {
	    string name = string (ref.start+1, ref.len-1);
	    if (name == "error") {
		complain ("the value of $error is undefined");
		continue;
	    }
	    if (name.size () == 1 && 
		(name[0] == '^' || name[0] == '$' || name[0] == '*'))
		continue;
            if (dict.find (name) == dict.end ())
		complain ("reference $%s undefined", name.c_str ());
	} end_for;
    }

    void add_generated_semantics (Node_Vector& left_context, int first_index, 
                                  int depth, NodePtr last_action) {
        bool am_outer = this == last_action;
        bool assem_by_default = am_outer && depth == 0;
        stringstream code;
        write_admin_code (code, left_context, first_index,
                          am_outer, assem_by_default);
        if (am_outer)
            write_marking_code (code, left_context, first_index);
        write_var_assign_code (code, left_context, first_index);
        action_prefix = code.str ();
	left_context.push_back (this);
    }

    bool is_rhs_item () const {
	return true;
    }
    
    Node* replace_null_action () {
        if (action_prefix.empty () 
            && (arity () == 0 
                || lang_is_empty_action (child (0)->as_string ()))) {
            delete this;
            return EMPTY;
        } else
            return this;
    }

private:

    /** Generated code that precedes user-supplied code. */
    string action_prefix;

    int last_admin_index (const Node_Vector& left_context) {
        for (int i = left_context.size () - 1; i >= 0; i -= 1) {
            if (left_context[i]->does_admin ())
                return i;
        }
        return -1;
    }


    /** Write any code necessary to create the yylhs administrative variable 
     *  onto OUT, assuming that LEFT_CONTEXT indicates the symbols to my 
     *  left, FIRST_INDEX is the index in LEFT_CONTEXT of $1, AM_OUTER 
     *  iff this is a final action, and ASSEM_BY_DEFAULT if the
     *  default action for an outer action is to process ! and ^
     *  operators (ignored on inner actions). */
    void write_admin_code (ostream& out, const Node_Vector& left_context,
                           int first_index, 
                           bool am_outer, bool assem_by_default) {
        bool must_push_frame = (last_admin_index (left_context) == -1);
        out << lang_def_admin_var (am_outer, must_push_frame, assem_by_default, 
                                   left_context.size (), first_index);
				       
    }
            
    /** Write any code necessary on OUT to handle the ! and ^ operators for 
     *  symbols in my rule to the left of me in LEFT_CONTEXT, where FIRST_INDEX 
     *  is the index in LEFT_CONTEXT of $1. */
    void write_marking_code (ostream& out, const Node_Vector& left_context,
                             int first_index) {
        for (size_t i = first_index; i < left_context.size (); i += 1)
            left_context[i]->mark_actions (out, i - first_index + 1);
    }

    /** Write any code necessary to assign semantic values to named variables
     *  ($varname) to OUT.  LEFT_CONTEXT is the sequence symbols to my left;
     *  FIRST_INDEX is the position in LEFT_CONTEXT of $1. */
    void write_var_assign_code (ostream& out, const Node_Vector& left_context, 
                                int first_index) {
        int i;
        for (i = left_context.size ()-1; i >= 0; i -= 1)
            if (left_context[i]->does_admin ())
                break;
        for (i += 1; i < (int) left_context.size (); i += 1)
            left_context[i]->write_var_assigns (out, i - first_index + 1);
    }

    /** The contents of the users' action, with $ references
     *  replaced. */
    string convert_refs () const {
	vector<lstring> refs;
	text_buffer text;

	lstring orig_text = child (0)->text ();

	text.append (orig_text.start, orig_text.len);
	action_scan (text, refs);
	for_each(ref, lstring, refs) {
	    string name = string (ref.start+1, ref.len-1);
            if (name == "$")
                text.replace (ref, lang_cfg_lhs ());
	    else if (name == "^")
		text.replace (ref, lang_manual_tree_creator ());
	    else if (name == "*") {
		text.replace (ref, lang_arguments ());
	    } else
		text.replace (ref, lang_create_ref (name));
	} end_for;

	stringstream new_text;
	text.write (new_text);
        return new_text.str ();
    }
    
    int compare (Node* x) {
	int c = Tree::compare (x);
	if (c == 0) {
	    Action_Tree* xt = dynamic_cast<Action_Tree*> (x);
	    return action_prefix.compare (xt->action_prefix);
	} else 
	    return c;
    }	

};

EXEMPLAR (Action_Tree);

			       /* Assignment (=). */

class Assign_Tree : public Tree {

    CONSTRUCTORS (Assign_Tree, '=');

protected: 

    void write_grammar (ostream& out) const {
	out << child(1) << " ";
    }

    Token* id_of () {
	return child (1)->as_token ();
    }

    bool is_rhs_item () const {
	return true;
    }
    
    Token* ref_name_of () {
	return child (0)->as_token ();
    }

    void collect_check_vocab (String_Set& syms) {
        string ref_name = ref_name_of ()->as_string (),
            id = id_of ()->as_string ();
	if (ref_name == "error") 
	    complain ("the name 'error' is reserved");
	else if (id == "error") 
	    complain ("the error token has no defined value");
        define_semantic_sym (ref_name);
        syms.insert (ref_name);
	id_of ()->collect_check_vocab (syms);
    }

    void add_generated_semantics (Node_Vector& left_context, 
                                  int first_index, int depth, NodePtr) {
        left_context.push_back (this);
    }

    void write_var_assigns (ostream& out, int my_index) {
        out << lang_assign (my_index, ref_name_of ()->as_string ());
	if (! id_of ()->is_literal ())
	    out << lang_assign (my_index, id_of ()->as_string ());
    }

};

EXEMPLAR (Assign_Tree);

				/* Appending assignment (+=) */

class Plus_Assign_Tree : public Assign_Tree {

    SUBTYPE_CONSTRUCTORS (Plus_Assign_Tree, PLUS_EQ, Assign_Tree);

protected: 

    void write_var_assigns (ostream& out, int my_index) {
        out << lang_append (my_index, ref_name_of ()->as_string ());
	if (! id_of ()->is_literal ())
	    out << lang_assign (my_index, id_of ()->as_string ());
    }

};

EXEMPLAR (Plus_Assign_Tree);

				/* Base tree-related operation */

class Tree_Forming_Tree : public Tree {

    BASE_CONSTRUCTORS (Tree_Forming_Tree, Tree);

public:

    void write_grammar (ostream& out) const {
	out << child (0);
    }

    Token* first_token () {
	return child (0)->first_token ();
    }

    Token* id_of () {
	return child (0)->id_of ();
    }

    bool is_rhs_item () const {
	return true;
    }
    
    Token* ref_name_of () {
	return child (0)->ref_name_of ();
    }

    void collect_check_vocab (String_Set& syms) {
	child (0)->collect_check_vocab (syms);
    }

    void add_generated_semantics (Node_Vector& left_context, 
                                  int first_index, int depth, 
                                  NodePtr last_action) {
	left_context.push_back (this);
    }

};

				/* ^ (cons-tree) expression  */

class Cons_Tree : public Tree_Forming_Tree {

    SUBTYPE_CONSTRUCTORS (Cons_Tree, '^', Tree_Forming_Tree);

protected: 

    void write_grammar (ostream& out) const {
	out << child(0);
    }

    void mark_actions (ostream& out, int my_index) {
        out << lang_mark_op (my_index);
    }

    void write_var_assigns (ostream& out, int my_index) {
        child (0)->write_var_assigns (out, my_index);
    }

};

EXEMPLAR (Cons_Tree);

				/* ! (ignore value) expression  */

class Ignore_Tree : public Tree_Forming_Tree {

    SUBTYPE_CONSTRUCTORS (Ignore_Tree, '!', Tree_Forming_Tree);

protected: 

    void mark_actions (ostream& out, int my_index) {
        out << lang_mark_ignore (my_index);
    }

    void write_var_assigns (ostream& out, int my_index) {
        child (0)->write_var_assigns (out, my_index);
    }

};

EXEMPLAR (Ignore_Tree);


    /* Line synchronization action */

class Sync_Tree : public Tree {

    CONSTRUCTORS (Sync_Tree, SYNC);

protected: 

    void write_grammar (ostream& out) const {
	resync_flag = true;
    }

};

EXEMPLAR (Sync_Tree);

bool resync_flag;

void
write_resync (ostream& out, location loc)
{
    int L = location_line_number (loc);
    if (L <= 0)
	return;
    out << endl << "#line " << L << " \"" << current_file << "\"" << endl;
    resync_flag = false;
}
