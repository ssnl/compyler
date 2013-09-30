#include <cstdarg>
#include <iomanip>
#include "horn.h"
#include "parse-horn.h"

using namespace std;

Unit UNIT;

static string
separation (const string& base, int syntax)
{
    if (!base.empty ())
	return base;
    switch (syntax) {
    case LOWER_ID:
    case UPPER_ID:
    case UNDERSCORE_ID:
    case STRING:
    case CHAR:
	return " ";
    default:
	return "";
    }
}

				/* Nodes */

#define member Node::

member
~Node ()
{ }

location member
get_loc () const
{
    if (loc != NULL)
	return loc;
    for (int i = 0; i < arity (); i += 1) {
	location L = child (i)->get_loc ();
	if (L != NULL)
	    return L;
    }
    return NULL;
}

bool member
is_leaf () const
{
    return true;
}

bool member
is_literal () const
{
    return false;
}

lstring member 
text () const
{
    UNIMPLEMENTED_METHOD (text);
}

lstring member
preceding_ws () const
{
    UNIMPLEMENTED_METHOD (preceding_ws);
}

location member
set_err_loc ()
{
    Token* tok = first_token ();
    if (tok != NULL)
	return ::set_err_loc (tok->text ().start);
    return current_complaint_location;
}

int member
syntax () const
{
    return -1;
}

Token* member
oper () const
{
    UNIMPLEMENTED_METHOD (oper);
}

Node* member
child (int i) const
{
    UNIMPLEMENTED_METHOD (child);
}

int member
arity () const
{
    return 0;
}

void member
replace (int, Node*, size_t)
{
    UNIMPLEMENTED_METHOD (setChild);
}

void member
swap (Node_Vector& kids)
{
    UNIMPLEMENTED_METHOD (swap);
}

const Node_Vector& member
children () const
{
    UNIMPLEMENTED_METHOD (children);
}
    
Node* member
extract_to_list ()
{
    UNIMPLEMENTED_METHOD (extract_to_list);
}

Node* member
add (Node* child, int k)
{
    UNIMPLEMENTED_METHOD (add);
}

Node* member 
merge (Node* tree, int)
{
    UNIMPLEMENTED_METHOD (merge);
}

Node* member
dadd (Node* child, int k)
{
    UNIMPLEMENTED_METHOD (dadd);
}

bool member
is_rhs_item () const
{
    return false;
}

bool member
is_action () const
{
    return false;
}

bool member
is_empty_list ()
{
    return false;
}

List* member
as_list ()
{
    return new List (this, NULL);
}

Token* member
as_token ()
{
    throw invalid_argument ("must be a token");
}

Lex_Set* member
as_set ()
{
    return NULL;
}

Token* member
id_of ()
{
    UNIMPLEMENTED_METHOD (id_of);
}

Token* member
ref_name_of ()
{
    UNIMPLEMENTED_METHOD (ref_name_of);
}

ostream&
operator<< (ostream& os, Node* node)
{
    if (node != NULL)
	node->write_grammar (os);
    return os;
}

#undef member

				/* Tokens */

#define member Token::

static Token TOKEN_OBJ(NULL_LS, NULL_LS, TOKEN_TAG);
Token* const _TOKEN = &TOKEN_OBJ;

lstring member 
text () const
{
    return _text;
}

lstring member
preceding_ws () const
{
    return _preceding_ws;
}

void member
set_preceding_ws (lstring ws)
{
    _preceding_ws = ws;
}

bool member
is_literal () const 
{
    switch (syntax ()) {
    default:
	return false;
    case STRING: case INT: case CHAR:
	return true;
    }
}

bool member
is_rhs_item () const
{
    return true;
}

void member
to_string (stringstream& out, int indent) const
{
    const char* name = tokenName (syntax ());
    int namel = strlen (name);
    out << "<" << name;

    if (name[0] != '"' || name[namel-1] != '"'
	|| text ().as_string () != string (name+1, namel-2))
	out << " \"" << text ().as_string () << "\"";
    out << ">";
}

void member
write_grammar (ostream& out) const
{
    string text = _text.as_string ();
    out << separation (_preceding_ws.as_string (), syntax ());
    if (text == "error")
        out << "__error__";
    else
	out << _text.as_string ();
}

Token* member
first_token ()
{
    return this;
}

Token* member
as_token ()
{
    return this;
}

Token* member
id_of ()
{
    return this;
}

Token* member
ref_name_of ()
{
    return this;
}

int member
compare (Node* x) {
    if (x->is_leaf ()) {
	int d = syntax () - x->syntax ();
	if (d != 0)
	    return d;
	else
	    return as_string ().compare (x->as_string ());
    } else
	return -1;
}

void member
init_loc ()
{
    if (location_line_number (_preceding_ws.start) > 0)
	set_loc (_preceding_ws.start);
    else if (location_line_number (_text.start) > 0)
	set_loc (_text.start);
}

#undef member

				/* Trees */

#define member Tree::

static Token LIST_OBJ (NULL_LS, NULL_LS, LIST_TAG);
Token* const _LIST = &LIST_OBJ;

map<int, Tree*>* member exemplars;

Node* member
make (Node* op, ...) 
{
    va_list ap;
    Node* result;

    Tree* exemplar = (*exemplars)[op->as_token ()->syntax ()];

    va_start (ap, op);
    if (exemplar == NULL)
	result = new Tree (ap, op);
    else
	result = exemplar->make (op, ap);
    va_end (ap);

    return result;
}

Tree* member
make (Node* op, Node_Vector& kids) 
{
    Tree* result;

    Tree* exemplar = (*exemplars)[op->as_token ()->syntax ()];

    if (exemplar == NULL)
	result = new Tree (op, UNIT, false);
    else
	result = exemplar->make (op, UNIT);
    result->_kids.swap (kids);

    return result;
}

Node* member
make (int syntax, ...) 
{
    va_list ap;
    Node* result;

    Tree* exemplar = (*exemplars)[syntax];
    Token* op = new Token (syntax);

    va_start (ap, syntax);
    if (exemplar == NULL)
	result = new Tree (ap, op);
    else
	result = exemplar->make (op, ap);
    va_end (ap);

    return result;
}

Node* member
make (Node* op, va_list ap)
{
    return new Tree (ap, op);
}

Tree* member
make (Node* op, Unit)
{
    UNIMPLEMENTED_METHOD (make);
}

bool member
register_me ()
{
    if (exemplars == NULL)
	exemplars = new map<int, Tree*> ();
    (*exemplars)[oper ()->syntax ()] = this;
    return true;
}

void member
add (va_list ap)
{
    while (true) {
	Node* v = va_arg (ap, Node*);
	if (v == NULL)
	    break;
	if (v->oper () == _LIST)
	    _kids.insert (_kids.end (), 
			  v->children ().begin (), v->children ().end ());
	else 
	    _kids.push_back (v);
    }
}

member
Tree (Node* op, Unit, bool reg)
    : _oper (op->as_token ())
{
    if (reg)
	register_me ();
}

member
Tree (Node* op)
    : _oper (op->as_token ())
{
}

member
Tree (int op, ...)
    : Node (), _oper (new Token (op))
{
    va_list ap;
    va_start (ap, op);
    add (ap);
    va_end (ap);
}    

member
Tree (va_list ap, Node* op)
    : Node (), _oper (op->as_token ())
{
    add (ap);
}

lstring member
preceding_ws () const
{
    lstring result;
    result = NULL_LS;
    for (int i = 0; i < arity () && result.is_null (); i += 1)
	result = child (i)->preceding_ws ();
    return result;
}

Token* member
first_token ()
{
    Token* result;
    result = NULL;
    for (int i = 0; i < arity () && result == NULL; i += 1)
	result = child (i)->first_token ();
    return result;
}

void member
set_preceding_ws (lstring ws)
{
    if (arity () > 0)
	child (0)->set_preceding_ws (ws);
}

bool member
is_leaf () const 
{
    return false;
}

Token* member
oper () const
{
    return _oper;
}

Node* member
child (int i) const
{
    return _kids.at (i);
}

void member
replace (int i, Node* val, size_t n)
{
    if (val->oper () == _LIST) {
	_kids.erase (_kids.begin () + i, _kids.begin () + i + n);
	_kids.insert (_kids.begin () + i, 
		      val->children ().begin (), val->children ().end ());
    } else {
	_kids.at (i) = val;
	_kids.erase (_kids.begin () + i + 1, _kids.begin () + i + n);
    }
}

Node* member
extract_to_list ()
{
    List* result = new List ();
    result->swap (_kids);
    return result;
}

void member
swap (Node_Vector& kids)
{
    _kids.swap (kids);
}

const Node_Vector& member
children () const
{
    return _kids;
}

Node* member
add (Node* child, int k)
{
    if (child->oper () != _LIST) {
	_kids.insert (k == -1 ? _kids.end () : _kids.begin () + k, child);
    } else
	merge (child, k);
    return this;
}

Node* member
merge (Node* tree, int k)
{
    _kids.insert (k == -1 ? _kids.end () : _kids.begin () + k, 
		  tree->children ().begin (), tree->children ().end ());
    return this;
}

Node* member
dadd (Node* child, int k)
{
    add (child, k);
    if (child->oper () == _LIST)
	delete child;
    return this;
}

void member
to_string (stringstream& out, int indent) const
{
    out << "(" << tokenName (oper()->syntax ());
    for (int i = 0; i < (int) children ().size (); i += 1) {
	out << endl << setw (indent+4) << ""; 
	child (i)->to_string (out, indent+4);
    }
    out << ")";
}

void member
write_grammar (std::ostream& out) const
{
    for (int i = 0; i < arity (); i += 1) {
	if (resync_flag)
	    if (child (i)->get_loc () != NULL)
		write_resync (out, child (i)->get_loc ());
	out << child (i);
    }
}

int member
compare (Node* x) {
    if (x->is_leaf ())
	return 1;
    int d = oper ()->compare (x->oper ());
    if (d != 0)
	return d;
    for (int i = 0; i < arity () && i < x->arity (); i += 1) {
	int c = child (i)->compare (x->child (i));
	if (c != 0)
	    return c;
    }
    return arity () - x->arity ();
}

#undef member

				/* Lists */

#define member List::

member
List (Node* first, ...) : Tree (_LIST)
{
    va_list ap;
   
    add (first);
    va_start (ap, first);
    for (Node* elt = va_arg (ap, NodePtr); elt != NULL; 
	 elt = va_arg (ap, NodePtr)) {
	add (elt);
    }
    va_end (ap);
}

bool member
is_empty_list ()
{
    return arity () == 0;
}

void member
to_string (stringstream& out, int indent) const

{
    out << "[ ";
    for (int i = 0; i < (int) children ().size (); i += 1) {
	out << endl << setw (indent+2) << ""; 
	child (i)->to_string (out, indent+2);
    }
    out << " ]";
}

Node* member
copy () 
{
    return internal_copy ();
}

void
debug_tree (Node* t)
{
    fprintf (stderr, "%s\n", t->to_string ().c_str ());
}


#undef member
