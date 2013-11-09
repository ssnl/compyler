/* -*-C++-*- */
@@@timestamp@@@

%code top {
@@@namespace@@@
@@@semantics@@@
@@@error_function_define@@@

# define YY_PARSER_1
# include "horn-parse-lex.cc"
}

%{

    YYNAMESPACE_OPEN

%}

/* User prologue code */

@@@user_defns@@@
@@@*RESYNC*@@@

/* Horn prologue */

%defines
%token-table

%{

#define YY_PARSER_2
#include "horn-parse-lex.cc"

%}

/* Token definitions */

@@@token_defs@@@

/* Destroying discarded semantic values. */
%destructor { $$._destructor (); } <>

%{
@@@var_decls@@@
%}

%%

@@@grammar@@@
@@@error_rule@@@
@@@*RESYNC*@@@

%%

@@@user_epilogue@@@
@@@*RESYNC*@@@

const char* 
yyexternal_token_name (int syntax)
{
    int internal_num = YYTRANSLATE (syntax);
    return yytname[internal_num];
}

#include "@@@generated_lexer_file@@@"

YYNAMESPACE_CLOSE

template <class Type>
Type Simple_Value_Semantics<Type>::default_make_token (int syn,
						       size_t len,
						       const char* text)
{
    return YY_DEFAULT_MAKE_TOKEN(syn, len, text);
}
