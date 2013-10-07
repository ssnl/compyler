/* Generated from exprs.hn at Thu Aug 18 21:53:51 2011 GMT. */

%option 8bit nodefault nounput noyywrap interactive

%{ 
#define YY_ILEXER_1
#include "horn-parse-lex.cc"
%}

%option outfile="exprs-lexer.cc"

%x YYPREFERRED

_EOF  "\377"


_DIG	[0-9]


%%

\*\*	{ { YY_LEXLHS(EXPO); YYLEXRET; } } 
[(-+\-/;]	{ { YYSIMPLELEXRET; } } 
{_DIG}+(\.{_DIG}*)?((e|E)(\+|-)?{_DIG}+)?	{ { YY_LEXLHS(NUM); YYLEXRET; } } 
[\011-\012 ]	{ { YY_LEXLHS;  YYLEXRET; } } 


<YYPREFERRED>.|\n  { yyless(0); return -1; }
.|\n               { if (yytext[0] == YYEOF_CHAR) {
                         yyless (0);     
                         return YYEOF;
                     }
                     return yytext[0]; }

%%

#define YY_ILEXER_2
#include "horn-parse-lex.cc"
