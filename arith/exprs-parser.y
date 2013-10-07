/* -*-C++-*- */
/* Generated from exprs.hn at Thu Aug 18 21:53:51 2011 GMT. */

%code top {

#define YYPARAM Tree_Semantics< Arith_Node >
#define YYPRODUCING_TREES


# define YY_PARSER_1
# include "horn-parse-lex.cc"
}

%{

    YYNAMESPACE_OPEN

%}

/* User prologue code */


#line 3 "exprs.hn"


%{
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

#include "arith.h"

%}

%left "+" "-"
%left "*" "/"
%right "**"

/* Give "**" a name we can refer to in arith.cc */
%token EXPO "**"

%debug

#line 47 "exprs-parser.y"

/* Horn prologue */

%defines
%token-table

%{

#define YY_PARSER_2
#include "horn-parse-lex.cc"

%}

/* Token definitions */

%token '(' "("
%token ')' ")"
%token '*' "*"
%token '+' "+"
%token '-' "-"
%token '/' "/"
%token ';' ";"
%token  NUM


/* Destroying discarded semantic values. */
%destructor { $$._destructor (); } <>

%{
static yyvar yyv_NUM;
static yyvar yyv_expr;
static yyvar yyv_prog;

%}

%%


#line 27 "exprs.hn"


prog : 
#line 29 "exprs.hn"
/* empty */  /* empty */	    { YYCTLPA($$,0,0); yylhs = NULL; } 
 | 
#line 30 "exprs.hn"
 prog expr ";"        { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_prog = $1; yyv_expr = $2;cout << yyv_expr.value() << "=" 
       	    	 	           << yyv_expr.value()->eval() << endl; } 
;



expr : 
#line 34 "exprs.hn"
 expr "+" expr { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.mark_tree_op (); yyv_expr = $1; yyv_expr = $3; }
;


expr : 
#line 35 "exprs.hn"
 expr "-" expr { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.mark_tree_op (); yyv_expr = $1; yyv_expr = $3; }
;


expr : 
#line 36 "exprs.hn"
 expr "*" expr { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.mark_tree_op (); yyv_expr = $1; yyv_expr = $3; }
;


expr : 
#line 37 "exprs.hn"
 expr "/" expr { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.mark_tree_op (); yyv_expr = $1; yyv_expr = $3; }
;


expr : 
#line 38 "exprs.hn"
 expr "**" expr { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.mark_tree_op (); yyv_expr = $1; yyv_expr = $3; }
;


expr : 
#line 39 "exprs.hn"
 NUM { YYCTLPA($$,0,1,&$1);  yyv_NUM = $1; }
;


expr : 
#line 40 "exprs.hn"
 "(" expr ")" { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_expr = $2; }
;




#line 144 "exprs-parser.y"

%%


#line 46 "exprs.hn"


int
main (int argc, char* argv[])
{
    if (argc > 1) {
	FILE* inp = fopen (argv[1], "r");
	if (inp == NULL) {
	    fprintf (stderr, "could not open %s\n", argv[1]);
	    exit (1);
	}
	yypush_lexer (inp, argv[1]);
    } else
	yypush_lexer (stdin, "<stdin>");
    return yyparse ();
}


#line 168 "exprs-parser.y"

const char* 
yyexternal_token_name (int syntax)
{
    int internal_num = YYTRANSLATE (syntax);
    return yytname[internal_num];
}

#include "exprs-lexer.cc"

YYNAMESPACE_CLOSE
