@@@timestamp@@@

%option 8bit nodefault noinput nounput noyywrap

%{ 
#define YY_LEXER_1
#include "horn-parse-lex.cc"
%}

%option outfile="@@@outfile@@@"

%x YYPREFERRED

_EOF  "\377"
@@@subrules@@@

%%

@@@rules@@@

<YYPREFERRED>.|\n  { yyless(0); return -1; }
.|\n               { if (yytext[0] == YYEOF_CHAR) {
                         yyless (0);     
                         return YYEOF;
                     }
                     return yytext[0]; }

%%

#define YY_LEXER_2
#include "horn-parse-lex.cc"
