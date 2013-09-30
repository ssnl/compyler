#include <cassert>
#include <cstdarg>
#include <cctype>
#include <iomanip>
#include "horn.h"
#include "parse-horn.h"

using namespace std;

/** The length of the character or escape sequence starting at
 *  location K of S. */
static int
char_length (const string& s, int k)
{
    int i;
    int N = s.size ();

    i = k;
    if (s[i] == '\\' && i < N-1) {
	i += 1;
	if (isdigit (s[i]) && s[i] < '8') {
	    i += 1;
	    if (i < N && isdigit (s[i]) && s[i] < '8')
		i += 1;
	    if (i < N && isdigit (s[i]) && s[i] < '8')
		i += 1;
	} else if (s[i] == 'x') {
	    i += 1;
	    if (i < N && isxdigit (s[i]))
		i += 1;
	    if (i < N && isxdigit (s[i]))
		i += 1;
	} else
	    i += 1;
    } else
	i += 1;
    return i - k;
}

/** The length of string S[I .. E-1] after applying escape conversions */
int
real_length (const string& s, int i, size_t e)
{
    int n;

    n = 0;
    if (e == string::npos)
	e = s.size ();
    while (i < (int) e) {
	n += 1;
	i += char_length (s, i);
    }
    return n;
}

static string
string_escaped (const string& s)
{
    string r;
    size_t i;
    i = 0;
    while (i < s.size ()) {
	switch (s[i]) {
	case '\\':
	    r += "\\";
	    if (i >= s.size ())
		break;
	    r += s[i+1];
	    i += 1;
	    while (i+1 < s.size () && isdigit (s[i+1])) {
		i += 1;
		r += s[i];
	    }
	    break;
	case '/': case '[': case ']': case '*': case '(': case ')':
	case '+': case '?': case '{': case '}': case '.': case '^':
	case '$': case '|': case '<': case '>':
	    r += "\\";
	    r += s[i];
	    break;
	default:
	    if (isgraph (s[i]))
		r += s[i];
	    else {
		r += "\\";
		r += s[i];
	    }
	    break;
	}
	i += 1;
    }
    return r;
}

/** The 1-character character literal S as an unsigned char.  Converts
 *  escape sequences. */
static unsigned char
to_char (const string& s)
{
    assert (real_length (s, 1, s.size () - 1) == 1);

    if (s[1] != '\\')
	return (unsigned char) (0xff & s[1]);
    
    switch (s[2]) {
    default:
	return (unsigned char) (0xff & s[2]);
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': 
    case '7': 
    {
	unsigned int n;
	n = s[2] - '0';
	if (isdigit (s[3]) && s[3] < '8') {
	    n = n*8 + s[3] - '0';
	    if (isdigit (s[4]) && s[4] < '8') 
		n = n*8 + s[4] - '0';
	}
	return n;
    }
    case 'a':
	return '\a';
    case 'b':
	return '\b';
    case 'f':
	return '\f';
    case 'n':
	return '\n';
    case 'r':
	return '\r';
    case 't':
	return '\t';
    case 'v':
	return '\v';
    }
}    

Node*
lex_action (Node* syntax, Node* action_tok)
{
    string name = syntax == NULL ? "" : syntax->as_string ();
    string* new_action;

    if (action_tok == NULL)
	new_action = new string (lang_lex_action (name, ""));
    else {
	text_buffer raw_action;
	vector<lstring> refs;

	raw_action.append (action_tok->text ().start, action_tok->text ().len);
	action_scan (raw_action, refs);
	for_each (ref, lstring, refs) {
	    string ref_name = string (ref.start+1, ref.len-1);	    
	    if (ref_name == "$")
		raw_action.replace (ref, lang_lex_lhs ());
	    else if (ref_name == "TEXT")
		raw_action.replace (ref, lang_lex_text ());
	    else if (ref_name == "TEXT_SIZE")
		raw_action.replace (ref, lang_lex_text_size ());
	    else 
		complain_at (action_tok->text ().start, 
			     "invalid reference to $%s in lexical rule",
			     ref_name.c_str ());
	} end_for;
	new_action = 
	    new string (lang_lex_action (name, raw_action.as_string ()));
    }

    Node* result = 
	TREE (ACTION,
	      new Token (lstring (*new_action), lstring (""), BRACED_CODE));
    if (action_tok != NULL && action_tok->get_loc () != NULL)
	result->set_loc (action_tok->get_loc ());
    return result;
}

Token* const No_Token = new Token (lstring (""), lstring (""), 0);    

bool interactive_parser;

				/* Default definitions for Node */

#define member Node::

Node_Vector member lexical_rules;
Node_Vector member lexical_subrules;
Implicit_Token_Map  member implicit_lexical_rules;
Token_Map  member all_tokens;
String_Set member explicit_tokens;

static String_Set lex_dict;

static void
define_subrules (ostream& out)
{
    lex_dict.clear ();
    for_each (subrule, Node*, Node::lexical_subrules) {
	subrule->check_lex_subrules ();
	out << subrule->rewrite_extended ();
    } end_for;
}

static NodePtr
make_implicit_rule (NodePtr token, NodePtr sym, NodePtr user_action)
{
    string text = token->as_string ();
    if (text[0] != '\'' || user_action != NULL) {
	NodePtr syntax;
	if (text[0] == '\'')
	    syntax = token;
	else
	    syntax = sym;
	return TREE (LEX_RULE, No_Token, 
		     TREE (LEX_PHRASE, TREE (LEX_STRING, token)),
		     lex_action (syntax, user_action));
    }
    return No_Token;
}

static NodePtr
accum_single_char_rule (NodePtr list, NodePtr token, NodePtr user_action)
{
    string text = token->as_string ();
    if (text[0] == '\'' && user_action == NULL) {
	return list->as_list ()->dadd (TREE (LEX_PHRASE, 
					     TREE (LEX_SET, token, token)));
    } else
	return list;
}

static Node*
make_single_char_rule (NodePtr single_chars)
{
    if (single_chars->arity () == 0)
	return NULL;
    
    if (single_chars->arity () > 1) 
	single_chars = TREE (LEX_GROUP, single_chars);

    string* new_action = new string (lang_lex_single_char_action ());
    return TREE (LEX_RULE, No_Token, single_chars, 
		 TREE (ACTION, 
		       new Token (lstring (*new_action), lstring (""), 
				  BRACED_CODE)));
}    

static void
process_rules (ostream& out)
{
    NodePtr single_char_rules;
    single_char_rules = EMPTY;
    gen_for_each (rule, Implicit_Token_Map, Node::implicit_lexical_rules) {
	out << make_implicit_rule (rule.second.text, 
				   rule.second.sym, rule.second.user_action);
	single_char_rules = 
	    accum_single_char_rule (single_char_rules,
				    rule.second.text, rule.second.user_action);
    } end_for;
    Node* single_rule = make_single_char_rule (single_char_rules);
    if (single_rule != NULL)
	out << single_rule->rewrite_extended ();
    for_each (rule, Node*, Node::lexical_rules) {
	rule->check_lex_subrules ();
	out << rule->rewrite_extended ();
    } end_for;
}

void member
process_lexical (const string& input_name, ostream& out)
{
    map<string, string> dict;
    string lexer_template_file;

    dict["timestamp"] = gen_timestamp (infile);
    dict["outfile"] = lex_generated_file;
    
    {
	stringstream subrules;
	define_subrules (subrules);
	dict["subrules"] = subrules.str ();
    }

    {
	stringstream rules;
	process_rules (rules);
	dict["rules"] = rules.str ();
    }

    if (interactive_parser)
	lexer_template_file = data_dir + INTERACTIVE_LEXER_TEMPLATE_FILE_TAIL;
    else
	lexer_template_file = data_dir + LEXER_TEMPLATE_FILE_TAIL;

    copy_subst_file (out, lexer_template_file.c_str (), dict);
}

void member
add_implicit_token (Node*)
{
    UNIMPLEMENTED_METHOD (add_implicit_token);
}

void member
add_explicit_token (Node* denotation)
{
    UNIMPLEMENTED_METHOD (add_explicit_token);
}

void member
add_explicit_token ()
{
    UNIMPLEMENTED_METHOD (add_explicit_token);
}

void member
declare_tokens (ostream& out) {
    for (Token_Map::const_iterator term_pair = all_tokens.begin (); 
	 term_pair != all_tokens.end (); term_pair++) {
	string sym = term_pair->second->as_string ();
	if (explicit_tokens.find (sym) == explicit_tokens.end ()
	    && explicit_tokens.find (term_pair->first) == explicit_tokens.end ())
	    out << "%token " << sym << " " << term_pair->first << endl;
    }
}

void member
check_lex_subrules ()
{
    kids_preorder (check_lex_subrules, ());
}

bool member
static_match_nonempty () const
{
    return false;
}

#undef member

                              /* Default definitions for Tree */

#define member Tree::

bool member
static_match_nonempty () const
{
    for (int i = 0; i < arity (); i += 1) {
	if (child (i)->static_match_nonempty ())
	    return true;
    }
    return false;
}

#undef member

				/* Default definitions for Token */

#define member Token::

static string
canonical_token_name (const string& name)
{
    if (name[0] != '\'' && real_length (name, 1, name.size ()-1) == 1) {
	if (name[1] == '\'')
	    return string ("'\\''");
	else
	    return string ("'") + name.substr (1, name.size () - 2) + "'";
    } else
	return name;
}
 
static string
string_token_name (const string& name)
{
    if (name[0] == '\'') {
	if (name[1] == '"') 
	    return "\"\\\"\"";
	else
	    return string("\"") + name.substr (1, name.size () - 2) + "\"";
    } else
	return name;
}

static NodePtr
canonical_token (NodePtr token)
{
    string name0 = token->as_string ();
    string name = canonical_token_name (name0);
    if (name == name0)
	return token;
    else 
	return new Token (lstring (*new string (name)), lstring (""), CHAR);
}

void member
add_implicit_token (NodePtr user_action)
{
    string name0 = text ().as_string ();
    NodePtr token = canonical_token (this);
    string name = token->text ().as_string ();

    Implicit_Token_Map::value_type new_val = make_pair (name, Implicit_Token());
    pair<Implicit_Token_Map::iterator, bool> p = 
	implicit_lexical_rules.insert (new_val);
    Implicit_Token& entry = (*p.first).second;
    if (p.second) {
	if (name0 != name) {
	    entry.sym = No_Token;
	    all_tokens[name0] = token;
	} else if (name[0] == '\'') {
	    entry.sym = No_Token;
	    all_tokens[string_token_name (name)] = token;
	} else {
	    set_symbol_prefix ("TOK");
	    entry.sym = new_symbol ();
	    all_tokens[name0] = entry.sym;
	} 
	entry.text = token;
    }
    if (user_action != NULL) {
	if (entry.user_action != NULL)
	    complain_at (user_action->text ().start, 
			 "attempt to redefine action for token");
	entry.user_action = user_action;
    }
}

void member
add_explicit_token (Node* denotation)
{
    string name = canonical_token_name (denotation->text ().as_string ());

    Implicit_Token_Map::value_type new_val = make_pair (name, Implicit_Token ());

    explicit_tokens.insert (this->as_string ());
    pair<Implicit_Token_Map::iterator, bool> p = 
	implicit_lexical_rules.insert (new_val);
    if (p.second) {
	Implicit_Token& entry = (*p.first).second;
	entry.sym = this;
	entry.text = denotation;
	all_tokens[name] = this;
    }	
}

void member
add_explicit_token ()
{
    explicit_tokens.insert (this->as_string ());
}

#undef member

				/* Lexical rules */

static Token* LEX_RULE_TOK = new Token (LEX_RULE);

class Lex_Rule_Tree : public Tree {
protected:

    Lex_Rule_Tree (Node* op, Unit) : Tree (op, UNIT) { }

    Lex_Rule_Tree (va_list args, Node* op) : Tree (args, op) {
	if (arity () != 3)
	    throw invalid_argument ("LEX_RULE takes 3 arguments");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Rule_Tree (args, op);
    }

    void write_grammar (ostream& out) const {
	out << child (1) << "\t" << child (2) << endl;
    }

private:

    static const Lex_Rule_Tree exemplar;

};

const Lex_Rule_Tree Lex_Rule_Tree::exemplar (LEX_RULE_TOK, UNIT);

static Token* LEX_RULE_PREFERRED_TOK = new Token (LEX_RULE_PREFERRED);

class Lex_Rule_Preferred_Tree : public Tree {
protected:

    Lex_Rule_Preferred_Tree (Node* op, Unit) : Tree (op, UNIT) { }

    Lex_Rule_Preferred_Tree (va_list args, Node* op) : Tree (args, op) {
	if (arity () != 3)
	    throw invalid_argument ("LEX_RULE_PREFERRED takes 3 arguments");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Rule_Preferred_Tree (args, op);
    }

    void write_grammar (ostream& out) const {
	out << "<YYPREFERRED>" << child (1);
	if (!child (1)->static_match_nonempty ())
	    out << "/[\\000-\\377]";
	out << "\t" << child (2) << endl;
    }

private:

    static const Lex_Rule_Preferred_Tree exemplar;

};

const Lex_Rule_Preferred_Tree 
    Lex_Rule_Preferred_Tree::exemplar (LEX_RULE_PREFERRED_TOK, UNIT);

				/* Subrules */

static Token* LEX_SUBRULE_TOK = new Token (LEX_SUBRULE);

class Lex_Subrule_Tree : public Tree {
protected:

    Lex_Subrule_Tree (Unit) : Tree (LEX_SUBRULE_TOK, UNIT) { }

    Lex_Subrule_Tree (va_list args) : Tree (args, LEX_SUBRULE_TOK) {
	if (arity () != 2)
	    throw invalid_argument ("LEX_SUBRULE takes 2 arguments");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Subrule_Tree (args);
    }

    void write_grammar (ostream& out) const {
	out << child (0) << "\t" << child (1) << endl;
    }

    void check_lex_subrules () {
	lstring text = child (0)->text ();
	string name = text.as_string ();
	if (lex_dict.find (name) != lex_dict.end ()) {
	    complain_at (text.start, "Redefinition of subrule name %s",
			 name.c_str ());
	}
	Node::check_lex_subrules ();
	lex_dict.insert (name);
    }


private:

    static const Lex_Subrule_Tree exemplar;

};

const Lex_Subrule_Tree Lex_Subrule_Tree::exemplar (UNIT);
    
		/* LEX_PHRASE */

static Token* LEX_PHRASE_TOK = new Token (LEX_PHRASE);

class Lex_Phrase_Tree : public Tree {
protected:

    Lex_Phrase_Tree (Unit) : Tree (LEX_PHRASE_TOK, UNIT) { }

    Lex_Phrase_Tree (va_list args) : Tree (args, LEX_PHRASE_TOK) {
    }

    Node* make (Node* op, va_list args) {
	Node* tree = new Lex_Phrase_Tree (args);
	if (tree->arity () == 1) {
	    Node* result = tree->child (0);
	    delete tree;
	    return result;
	} else
	    return tree;
    }

private:

    static const Lex_Phrase_Tree exemplar;

};

const Lex_Phrase_Tree Lex_Phrase_Tree::exemplar (UNIT);
    
		/* LEX_STAR */

static Token* LEX_STAR_TOK = new Token (LEX_STAR);

class Lex_Star : public Tree {
protected:

    Lex_Star (Unit) : Tree (LEX_STAR_TOK, UNIT) { }

    Lex_Star (va_list args) : Tree (args, LEX_STAR_TOK) {
	if (arity () != 1)
	    throw invalid_argument ("LEX_STAR takes 1 argument");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Star (args);
    }

    void write_grammar (std::ostream& out) const {
	out << child (0) << "*";
    }

    bool static_match_nonempty () const {
	return false;
    }


private:

    static const Lex_Star exemplar;

};

const Lex_Star Lex_Star::exemplar (UNIT);

		/* LEX_PLUS */

static Token* LEX_PLUS_TOK = new Token (LEX_PLUS);

class Lex_Plus : public Tree {
protected:

    Lex_Plus (Unit) : Tree (LEX_PLUS_TOK, UNIT) { }

    Lex_Plus (va_list args) : Tree (args, LEX_PLUS_TOK) {
	if (arity () != 1)
	    throw invalid_argument ("LEX_PLUS takes 1 argument");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Plus (args);
    }

    void write_grammar (std::ostream& out) const {
	out << child (0) << "+";
    }

private:

    static const Lex_Plus exemplar;

};

const Lex_Plus Lex_Plus::exemplar (UNIT);

		/* LEX_OPT */

static Token* LEX_OPT_TOK = new Token (LEX_OPT);

class Lex_Opt : public Tree {
protected:

    Lex_Opt (Unit) : Tree (LEX_OPT_TOK, UNIT) { }

    Lex_Opt (va_list args) : Tree (args, LEX_OPT_TOK) {
	if (arity () != 1)
	    throw invalid_argument ("LEX_OPT takes 1 argument");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Opt (args);
    }

    void write_grammar (std::ostream& out) const {
	out << child (0) << "?";
    }

    bool static_match_nonempty () const {
	return false;
    }

private:

    static const Lex_Opt exemplar;

};

const Lex_Opt Lex_Opt::exemplar (UNIT);

		/* LEX_SET */

static Token* LEX_SET_TOK = new Token (LEX_SET);

class Lex_Set : public Tree {
public:

    void add_set (Lex_Set* node) {
        for (size_t i = 0; i < sizeof (charset); i += 1) {
	    charset[i] |= node->charset[i];
        }
    }

    void subtract_set (Lex_Set* node) {
        for (size_t i = 0; i < sizeof (charset); i += 1) {
	    charset[i] &= ~node->charset[i];
        }
    }

protected:

    Lex_Set (Unit) : Tree (LEX_SET_TOK, UNIT) { }

    Lex_Set (va_list args) : Tree (LEX_SET_TOK) {
	memset (charset, '\0', sizeof (charset));
    }

    Node* make (Node* op, va_list args) {
	Lex_Set* result = new Lex_Set (args);

	while (true) { 
	    Node* c0 = va_arg (args, Node*);
	    if (c0 == NULL)
		break;
	    Node* c1 = va_arg (args, Node*);
	    if (c1 == NULL)
		throw invalid_argument ("Lex_Set::make takes an even "
					"number of arguments");
	    memset (result->charset + to_char (c0->as_string ()), '\01', 
		    to_char (c1->as_string ()) - to_char (c0->as_string ()) + 1);
	}

	return result;
    }

    void write_grammar (ostream& out) const {
	out << "[";
	for (size_t i = 1; i < sizeof (charset); i += 1) {
	    if (!charset[i])
		continue;
	    out_char (out, i);
	    if (charset[i+1]) {
		for (i = i+1; i < sizeof (charset); i += 1) {
		    if (!charset[i]) {
			out << "-";
			out_char (out, i-1);
			break;
		    }
		}
	    }
	}
	out << "]";
    }

    Lex_Set* as_set () {
	return this;
    }

    bool static_match_nonempty () const {
	return true;
    }

private:

    static void out_char (ostream& out, unsigned char i) {
	if (i == ']' || i == '\\' || i == '^' || i == '-')
	    out << "\\" << (char) i;
	else if (isprint (i))
	    out << i;
	else
	    out << "\\" << setw (3) << setfill ('0') << oct
		<< (unsigned int) i << dec << setfill (' ');
    }

    unsigned char charset[257];

    static const Lex_Set exemplar;

};

const Lex_Set Lex_Set::exemplar (UNIT);

		/* LEX_SUB */

static Token* LEX_SUB_TOK = new Token (LEX_SUB);

class Lex_Sub : public Tree {
public:

protected:

    Lex_Sub (Unit) : Tree (LEX_SUB_TOK, UNIT) { }

    Lex_Sub (va_list args) : Tree (args, LEX_SUB_TOK) {
    }

    Node* make (Node* op, va_list args) {
        return new Lex_Sub (args);
    }

    Node* rewrite_extended () {
	Tree::rewrite_extended ();
        Lex_Set* left = child (0)->as_set ();
        Lex_Set* right = child (1)->as_set ();
        if (left == NULL || right == NULL)
            complain_at (get_loc (), "Can only subtract sets of characters");
        else
            left->subtract_set (right);
        return child (0);
    }

    bool static_match_nonempty () const {
	return true;
    }

private:

    static const Lex_Sub exemplar;

};

const Lex_Sub Lex_Sub::exemplar (UNIT);

		/* LEX_GROUP */

static Token* LEX_GROUP_TOK = new Token (LEX_GROUP);

class Lex_Group : public Tree {
protected:

    Lex_Group (Unit) : Tree (LEX_GROUP_TOK, UNIT) { }

    Lex_Group (va_list args) : Tree (args, LEX_GROUP_TOK) {
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Group (args);
    }

    void write_grammar (std::ostream& out) const {
	if (arity () == 0)
	    return;
	out << "(" << child (0);
	for (int i = 1; i < arity (); i += 1)
	    out << "|" << child (i);
	out << ")";
    }

    Node* rewrite_extended () {
	Tree::rewrite_extended ();
	if (arity () > 0) {
	    Lex_Set* first = child (0)->as_set ();
	    if (first != NULL) {
		int i;
		for (i = 1; 
		     i < arity () && child (i)->as_set () != NULL; 
		     i += 1)
		    first->add_set (child (i)->as_set ());
		if (i > 1) 
		    replace (1, EMPTY, i-1);
		if (arity () == 1)
		    return child (0);
	    }
	}
	return this;
    }

    bool static_match_nonempty () const {
	if (arity () == 0)
	    return false;
	for (int i = 0; i < arity (); i += 1)
	    if (! child (i)->static_match_nonempty ())
		return false;
	return true;
    }

private:

    static const Lex_Group exemplar;

};

const Lex_Group Lex_Group::exemplar (UNIT);

		/* LEX_STRING */

static Token* LEX_STRING_TOK = new Token (LEX_STRING);

class Lex_String_Tree : public Tree {
protected:
    Lex_String_Tree (Unit) : Tree (LEX_STRING_TOK, UNIT) { }

    Lex_String_Tree (va_list args) : Tree (args, LEX_STRING_TOK) {
	if (arity () != 1)
	    throw invalid_argument ("LEX_STRING takes 1 arguments");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_String_Tree (args);
    }

    lstring text () const {
	return child (0)->text ();
    }

    void write_grammar (std::ostream& out) const {
	string content = text ().as_string ();
	size_t i;

	i = 1;
	while (i < content.size ()-1) {
	    int k = char_length (content, i);
	    out << string_escaped (content.substr (i, k));
	    i += k;
	}
    }

    bool static_match_nonempty () const {
	return (text ().len > 0);
    }


private:

    static const Lex_String_Tree exemplar;

};

const Lex_String_Tree Lex_String_Tree::exemplar (UNIT);
    

		/* LEX_REF */

static Token* LEX_REF_TOK = new Token (LEX_REF);

class Lex_Ref_Tree : public Tree {
protected:
    Lex_Ref_Tree (Unit) : Tree (LEX_REF_TOK, UNIT) { }

    Lex_Ref_Tree (va_list args) : Tree (args, LEX_REF_TOK) {
	if (arity () != 1)
	    throw invalid_argument ("LEX_REF takes 1 arguments");
    }

    Node* make (Node* op, va_list args) {
	return new Lex_Ref_Tree (args);
    }

    lstring text () const {
	return child (0)->text ();
    }

    void write_grammar (std::ostream& out) const {
	out << "{" << text ().as_string () << "}";
    }

    void check_lex_subrules () {
	string name = text ().as_string ();
	if (lex_dict.find (name) == lex_dict.end ()) {
	    complain_at (text ().start,
			 "Use of subrule %s without preceding definition.",
			 name.c_str ());
	}
    }

    bool static_match_nonempty () const {
	return false;
    }

private:

    static const Lex_Ref_Tree exemplar;

};

const Lex_Ref_Tree Lex_Ref_Tree::exemplar (UNIT);
    
				/* _BOL expression  */

static Token* BOL_TOK = new Token (BOL);

class BOL_Tree : public Tree {
protected: 

    BOL_Tree (Unit) : Tree (BOL_TOK, UNIT) { }

    BOL_Tree (va_list args) : Tree (args, BOL_TOK) {
	if (arity () > 0)
	    throw invalid_argument ("BOL takes no arguments");
    }

    Node* make (Node* op, va_list args) {
	return new BOL_Tree (args);
    }

    void write_grammar (std::ostream& out) const {
	out << "^";
    }

    bool static_match_nonempty () const {
	return false;
    }

private:

    static const BOL_Tree exemplar;
    
};

const BOL_Tree BOL_Tree::exemplar (UNIT);


				/* _EOF expression  */

static Token* ENDFILE_TOK = new Token (ENDFILE);

class ENDFILE_Tree : public Tree {
protected: 

    ENDFILE_Tree (Unit) : Tree (ENDFILE_TOK, UNIT) { }

    ENDFILE_Tree (va_list args) : Tree (args, ENDFILE_TOK) {
	if (arity () > 0)
	    throw invalid_argument ("ENDFILE takes no arguments");
    }

    Node* make (Node* op, va_list args) {
	return new ENDFILE_Tree (args);
    }

    void write_grammar (std::ostream& out) const {
	out << "{_EOF}";
    }

    bool static_match_nonempty () const {
	return true;
    }

private:

    static const ENDFILE_Tree exemplar;
    
};

const ENDFILE_Tree ENDFILE_Tree::exemplar (UNIT);

				/* _EOL expression  */

static Token* EOL_TOK = new Token (EOL);

class EOL_Tree : public Tree {
protected: 

    EOL_Tree (Unit) : Tree (EOL_TOK, UNIT) { }

    EOL_Tree (va_list args) : Tree (args, EOL_TOK) {
	if (arity () > 0)
	    throw invalid_argument ("EOL takes no arguments");
    }

    Node* make (Node* op, va_list args) {
	return new EOL_Tree (args);
    }

    void write_grammar (std::ostream& out) const {
	out << "/\\r?\\n";
    }

    bool static_match_nonempty () const {
	return true;
    }

private:

    static const EOL_Tree exemplar;
    
};

const EOL_Tree EOL_Tree::exemplar (UNIT);

