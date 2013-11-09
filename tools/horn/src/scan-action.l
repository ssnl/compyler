/* -*- c-file-style: "stroustrup"; -*- */

%option nodefault never-interactive noyywrap noinput nounput
%option prefix="scan_act_"

%{
#include "horn.h"

using namespace std;

static vector<lstring>* refs;

%}

splice	 (\\[ \f\t\v]*\n)*

ccomment ("/*"([^*]|"*"+[^*/])*"*"+"/")
ws       ({splice}|[ \f\n\t\v]|"//".*|{ccomment})*

letter	  [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_]
id	  {letter}({letter}|[0-9])*

%%


"$$"      |
"$"{id}   |
"$*"      |
"$^"      { refs->push_back (lstring (yytext, yyleng)); }

"$"[-0-9]+                    |
"$<"[^[:space:]]*">"[-0-9]*    { 
                                  complain ("'%s' is not allowed in this "
                                            "dialect.", yytext); }

{ws}                                 |
"'"("\\".|[^\n\\'])"'"               |
"\""("\\".|[^\n\\"]|{splice})*"\""   |
.                                    { }

%%

void
action_scan (text_buffer& action, vector<lstring>& ref_vec) {
    refs = &ref_vec;
    action.append ("\000\000", 2);
    lstring eofs = action.substr (action.data () + action.data_size () - 2, 2);
    action.erase (eofs);
    yy_switch_to_buffer (yy_scan_buffer (action.data (),
					 action.data_size ()));
    ref_vec.clear ();
    
    scan_act_lex ();

    scan_act__delete_buffer (YY_CURRENT_BUFFER);
}
