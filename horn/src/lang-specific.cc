
#include "horn.h"

using namespace std;

static string
eol_sequence ()
{
    stringstream out;
    out << endl;
    return out.str ();
}

static const string eol_string = eol_sequence ();

string
lang_define_semantics (const string& params)
{
    return "#define YYPARAM " + params;
}

string
lang_define_tree_semantics (const string& type)
{
    return string ("#define YYPARAM Tree_Semantics< ") + type + " >"
	+ eol_string + "#define YYPRODUCING_TREES";
}

string
lang_define_simple_semantics (const string& type, const string& token_factory)
{
    string make_token;
    if (token_factory != "") 
	make_token = "#define YY_DEFAULT_MAKE_TOKEN " + token_factory + "\n";
    
    return make_token + "#define YYPARAM Simple_Value_Semantics< " + type + " >";
}

string
lang_define_error_function (const string& name)
{
    return "#define YYERROR_FUNCTION_NAME " + name;
}

/** Bison's 'error' token comes with an uninitialized semantic value,
 *  which could cause problems were it to be used by destructors or by
 *  the adjust_positions method in the parser code.  Rather than make
 *  a special case out of it elsewhere, we centralize its special
 *  treatment by introducing a NONterminal symbol that produces just 'error',
 *  giving that a (null) semantic value, and substituting this
 *  nonterminal for all uses of 'error' in the parser. */
string
lang_error_rule ()
{
    return "__error__ : error   { $$._clear (); } ;";
}


string
lang_define_semantic_var (const string& name)
{
    return "static yyvar yyv_" + name + ";" + eol_string;
}

string
lang_create_ref (const string& name)
{
    return "yyv_" + name;
}

string
lang_def_admin_var (bool outer, bool push_frame, bool assemble_value,
                    int n, int sym1)
{
    stringstream out;
    out << "YYCTL" << (push_frame ? "P" : "");
    if (outer) {
        out << (assemble_value ? "A" : "C") << "($$," << sym1 << "," << n;
        for (int i = 1; i <= n; i += 1) 
            out << ",&$" << i-sym1;
        out << "); ";
    } else
        out << "($$, 0, 0); ";
    return out.str ();
}

string
lang_mark_ignore (int index)
{
    return format_string (" $%d.ignore();", index);
}

string
lang_mark_op (int index)
{
    return format_string (" $%d.mark_tree_op ();", index);
}

string
lang_assign (int index, const string& name)
{
    return format_string (" yyv_%s = $%d;", name.c_str (), index);
}

string
lang_append (int index, const string& name)
{
    return format_string (" yyv_%s += $%d;", name.c_str (), index);
}

string
lang_manual_tree_creator ()
{
    return "YYMAKE_TREE";
}

string
lang_arguments ()
{
    return "yylhs.all_values ()";
}

bool
lang_is_empty_action (const string& text)
{
    if (text.empty ())
        return true;
    for (size_t i = 0; i < text.size (); i += 1)
        if (!isspace (text[i]))
            return false;
    return true;
}

string
lang_lex_action (const string& syntax, const string& init)
{
    if (syntax.empty ())
	return string("{ YY_LEXLHS; ") + init + " YYLEXRET; }";
    else
	return string("{ YY_LEXLHS(") + syntax + ");" + init + " YYLEXRET; }";
}

string
lang_lex_single_char_action ()
{
    return "{ YYSIMPLELEXRET; }";
}

string
lang_cfg_lhs ()
{
    return "yylhs";
}

string
lang_lex_lhs ()
{
    return "yylhs";
}

string
lang_lex_text ()
{
    return "yylhs.text ()";
}

string
lang_lex_text_size ()
{
    return "yylhs.text_size ()";
}





