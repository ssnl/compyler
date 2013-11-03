/* Generated from apyc.hn at Wed Oct 16 13:37:59 2013 GMT. */

%option 8bit nodefault noinput nounput noyywrap

%{ 
#define YY_LEXER_1
#include "horn-parse-lex.cc"
%}

%option outfile="apyc-lexer.cc"

%x YYPREFERRED

_EOF  "\377"


_LETTER	[A-Za-z]


_DIGIT	[0-9]


_OCTAL_DIGIT	[0-7]


_HEX_DIGIT	({_DIGIT}|[a-f]|[A-F])


_OCTAL_INTEGER	([0]({_OCTAL_DIGIT})+)


_HEX_INTEGER	([0][Xx]({_HEX_DIGIT})+)


_DECIMAL_INTEGER	([1-9][0-9]*|[0])


_OCTAL	({_OCTAL_DIGIT}{_OCTAL_DIGIT}?{_OCTAL_DIGIT}?)


_ESCAPESEQ	([\\][\001-\376]|[\\]{_OCTAL})


_STRINGPIECE1	([\001-\011\013-!#-[\]-\376]|{_ESCAPESEQ})


_STRINGPIECE2	([\001-\011\013-&(-[\]-\376]|{_ESCAPESEQ})


_LONGSTRINGPIECE1	([\001-!#-[\]-\376]|{_ESCAPESEQ})


_LONGSTRINGPIECE2	([\001-&(-[\]-\376]|{_ESCAPESEQ})


%%

!=	{ { YY_LEXLHS(_TOK_23); YYLEXRET; } } 
\*\*	{ { YY_LEXLHS(EXPO); YYLEXRET; } } 
-\>	{ { YY_LEXLHS(_TOK_17); YYLEXRET; } } 
\/\/	{ { YY_LEXLHS(_TOK_25); YYLEXRET; } } 
::	{ { YY_LEXLHS(_TOK_3); YYLEXRET; } } 
\<=	{ { YY_LEXLHS(_TOK_20); YYLEXRET; } } 
==	{ { YY_LEXLHS(_TOK_22); YYLEXRET; } } 
\>=	{ { YY_LEXLHS(_TOK_21); YYLEXRET; } } 
\>\>	{ { YY_LEXLHS(_TOK_16); YYLEXRET; } } 
@and	{ { YY_LEXLHS(AND); YYLEXRET; } } 
@assign	{ { YY_LEXLHS(ASSIGN); YYLEXRET; } } 
@attributeref	{ { YY_LEXLHS(ATTR_REF); YYLEXRET; } } 
@binop	{ { YY_LEXLHS(BINOP); YYLEXRET; } } 
@block	{ { YY_LEXLHS(BLOCK); YYLEXRET; } } 
@break	{ { YY_LEXLHS(BREAK); YYLEXRET; } } 
@call	{ { YY_LEXLHS(CALL); YYLEXRET; } } 
@class	{ { YY_LEXLHS(CLASS); YYLEXRET; } } 
@compare	{ { YY_LEXLHS(COMPARE); YYLEXRET; } } 
@continue	{ { YY_LEXLHS(CONTINUE); YYLEXRET; } } 
@def	{ { YY_LEXLHS(DEFINITION); YYLEXRET; } } 
@dict_display	{ { YY_LEXLHS(DICT); YYLEXRET; } } 
@expr_list	{ { YY_LEXLHS(EXPR_LIST); YYLEXRET; } } 
@for	{ { YY_LEXLHS(FOR); YYLEXRET; } } 
@formals_list	{ { YY_LEXLHS(FORMALS_LIST); YYLEXRET; } } 
@function_type	{ { YY_LEXLHS(FUNCT_TYPE); YYLEXRET; } } 
@if	{ { YY_LEXLHS(IF); YYLEXRET; } } 
@if_expr	{ { YY_LEXLHS(IF_EXPR); YYLEXRET; } } 
@left_compare	{ { YY_LEXLHS(LCOMPARE); YYLEXRET; } } 
@list_display	{ { YY_LEXLHS(LIST); YYLEXRET; } } 
@module	{ { YY_LEXLHS(MODULE); YYLEXRET; } } 
@native	{ { YY_LEXLHS(NATIVE); YYLEXRET; } } 
@or	{ { YY_LEXLHS(OR); YYLEXRET; } } 
@pair	{ { YY_LEXLHS(PAIR); YYLEXRET; } } 
@print	{ { YY_LEXLHS(PRINT); YYLEXRET; } } 
@println	{ { YY_LEXLHS(PRINTLN); YYLEXRET; } } 
@return	{ { YY_LEXLHS(RETURN); YYLEXRET; } } 
@slicing	{ { YY_LEXLHS(SLICING); YYLEXRET; } } 
@stmt_list	{ { YY_LEXLHS(STMT_LIST); YYLEXRET; } } 
@subscription	{ { YY_LEXLHS(SUBSCRIPTION); YYLEXRET; } } 
@target_list	{ { YY_LEXLHS(TARGET_LIST); YYLEXRET; } } 
@tuple	{ { YY_LEXLHS(TUPLE); YYLEXRET; } } 
@type	{ { YY_LEXLHS(TYPE); YYLEXRET; } } 
@type_formals_list	{ { YY_LEXLHS(TYPE_FORMALS_LIST); YYLEXRET; } } 
@type_list	{ { YY_LEXLHS(TYPE_LIST); YYLEXRET; } } 
@type_var	{ { YY_LEXLHS(TYPE_VAR); YYLEXRET; } } 
@typed_id	{ { YY_LEXLHS(TYPED_ID); YYLEXRET; } } 
@unop	{ { YY_LEXLHS(UNOP); YYLEXRET; } } 
@while	{ { YY_LEXLHS(WHILE); YYLEXRET; } } 
and	{ { YY_LEXLHS(_TOK_18); YYLEXRET; } } 
break	{ { YY_LEXLHS(_TOK_6); YYLEXRET; } } 
class	{ { YY_LEXLHS(_TOK_0); YYLEXRET; } } 
continue	{ { YY_LEXLHS(_TOK_7); YYLEXRET; } } 
def	{ { YY_LEXLHS(_TOK_2); YYLEXRET; } } 
elif	{ { YY_LEXLHS(_TOK_12); YYLEXRET; } } 
else	{ { YY_LEXLHS(_TOK_13); YYLEXRET; } } 
for	{ { YY_LEXLHS(_TOK_8); YYLEXRET; } } 
if	{ { YY_LEXLHS(_TOK_11); YYLEXRET; } } 
in	{ { YY_LEXLHS(_TOK_9); YYLEXRET; } } 
is	{ { YY_LEXLHS(_TOK_24); YYLEXRET; } } 
native	{ { YY_LEXLHS(_TOK_14); YYLEXRET; } } 
not	{ { YY_LEXLHS(_TOK_26); YYLEXRET; } } 
of	{ { YY_LEXLHS(_TOK_1); YYLEXRET; } } 
or	{ { YY_LEXLHS(_TOK_19); YYLEXRET; } } 
pass	{ { YY_LEXLHS(_TOK_4); YYLEXRET; } } 
print	{ { YY_LEXLHS(_TOK_15); YYLEXRET; } } 
return	{ { YY_LEXLHS(_TOK_5); YYLEXRET; } } 
while	{ { YY_LEXLHS(_TOK_10); YYLEXRET; } } 
\(	{ { YY_LEXLHS('(');bracket_count++; YYLEXRET; } } 
\)	{ { YY_LEXLHS(')');bracket_count--; YYLEXRET; } } 
\[	{ { YY_LEXLHS('[');bracket_count++; YYLEXRET; } } 
\]	{ { YY_LEXLHS(']');bracket_count--; YYLEXRET; } } 
\{	{ { YY_LEXLHS('{');bracket_count++; YYLEXRET; } } 
\}	{ { YY_LEXLHS('}');bracket_count--; YYLEXRET; } } 
[%*-/:->]	{ { YYSIMPLELEXRET; } } 
[\011\015 ]+	{ { YY_LEXLHS;  YYLEXRET; } } 
[#][\001-\011\013-\376]*	{ { YY_LEXLHS;  YYLEXRET; } } 
[\\][\015]?[\012][\011 ]*	{ { YY_LEXLHS;  YYLEXRET; } } 
<YYPREFERRED>^[\011 ]*[\015]?[\012]	{ { YY_LEXLHS;  YYLEXRET; } } 
<YYPREFERRED>^[\011 ]*{_EOF}	{ { YY_LEXLHS(END_OF_FILE);int dedent_count = 0;
                        while ( indent_stack.top() > 0 ) {
                          dedent_count++;
                          indent_stack.pop();
                        }
                        // Need to generate DEDENT tokens
                        if (dedent_count > 0) {
                          for (int i = 0; i < dedent_count-1; i++) {
                            yyqueue_token(DEDENT, NULL);
                          }
                          // Put the EOF token back into queue.
                          yyqueue_token(0, NULL);
                          YYSET_TOKEN(DEDENT);
                        } else {

                          YYSET_TOKEN(0);
                        } YYLEXRET; } } 
<YYPREFERRED>{_EOF}	{ { YY_LEXLHS(END_OF_FILE);int dedent_count = 0;
                        while ( indent_stack.top() > 0 ) {
                          dedent_count++;
                          indent_stack.pop();
                        }
                        // Need to generate DEDENT tokens
                        if (dedent_count > 0) {
                          for (int i = 0; i < dedent_count; i++) {
                            yyqueue_token(DEDENT, NULL);
                          }
                        }
                        // Put the EOF token back into queue.
                        yyqueue_token(0, NULL);
                        // Insert a NEWLINE token.
                        YYSET_TOKEN(NEWLINE); YYLEXRET; } } 
[\012]	{ { YY_LEXLHS(NEWLINE);if (bracket_count > 0) {
                          YYIGNORE;
                        } else {
                          YYSET_TOKEN(NEWLINE);
                        } YYLEXRET; } } 
(as|assert|del|except|exec|finally|future|global|import|lambda|raise|try|with|yield|from)	{ { YY_LEXLHS(UNUSED_KEYWORD);error(yylhs.text (), "syntax error: invalid syntax"); YYIGNORE; YYLEXRET; } } 
<YYPREFERRED>^[\011 ]*/[\000-\377]	{ { YY_LEXLHS(INDENTATION);int spaces = count_leading_whitespaces(yylhs.text (), yylhs.text_size ());
                        if ( indent_stack.empty() ) {
                          if ( spaces > 0 )
                            error(yylhs.text (), "indentation error: unexpected indent");
                          indent_stack.push(0);
                          YYIGNORE;
                        } else {
                          //if (bracket_count > 0)
                          //  cout << "Bracket count: " + bracket_count << endl;
                          if ( bracket_count > 0 || indent_stack.top() == spaces )
                            YYIGNORE;
                          else if ( indent_stack.top() < spaces ) {
                            indent_stack.push(spaces);
                            YYSET_TOKEN(INDENT);
                          }
                          else {
                            int dedent_count = 0;
                            while ( indent_stack.top() > spaces ) {
                              indent_stack.pop();
                              dedent_count++;
                            }
                            if ( indent_stack.top() != spaces ) {
                              error(yylhs.text (), "indentation error: unindent does not match outer indentation level");
                              YYIGNORE;
                            }
                            for (int i = 0; i < dedent_count-1; i++) {
                              yyqueue_token(DEDENT, NULL);
                            }
                            YYSET_TOKEN(DEDENT);
                          }
                        } YYLEXRET; } } 
<YYPREFERRED>^[\011 ]*[#][\001-\011\013-\376]*	{ { YY_LEXLHS(BLANK_LINE);YYIGNORE; YYLEXRET; } } 
not[ ]+in	{ { YY_LEXLHS(NOTIN);yylhs = AST::make_token(ID, 5, "notin", false); YYLEXRET; } } 
is[ ]+not	{ { YY_LEXLHS(ISNOT);yylhs = AST::make_token(ID, 5, "isnot", false); YYLEXRET; } } 
({_DECIMAL_INTEGER}|{_OCTAL_INTEGER}|{_HEX_INTEGER})	{ { YY_LEXLHS(INT_LITERAL); YYLEXRET; } } 
({_LETTER}|[_])({_LETTER}|{_DIGIT}|[_])*	{ { YY_LEXLHS(ID); YYLEXRET; } } 
[$]({_LETTER}|[_])({_LETTER}|{_DIGIT}|[_])*	{ { YY_LEXLHS(TYPE_VAR); YYLEXRET; } } 
["]{_STRINGPIECE1}*["]	{ { YY_LEXLHS(STRING);yylhs = AST::make_token (STRING, yylhs.text_size () - 2,
                                              yylhs.text ()+1, false); YYLEXRET; } } 
\"\"\"(["]["]?)?({_LONGSTRINGPIECE1}+(["]["]?)?)*\"\"\"	{ { YY_LEXLHS(STRING);yylhs = AST::make_token (STRING, yylhs.text_size () - 6,
                                              yylhs.text ()+3, false); YYLEXRET; } } 
[']{_STRINGPIECE2}*[']	{ { YY_LEXLHS(STRING);yylhs = AST::make_token (STRING, yylhs.text_size () - 2,
                                              yylhs.text ()+1, false); YYLEXRET; } } 
\'\'\'(['][']?)?({_LONGSTRINGPIECE2}+(['][']?)?)*\'\'\'	{ { YY_LEXLHS(STRING);yylhs = AST::make_token (STRING, yylhs.text_size () - 6,
                                              yylhs.text ()+3, false); YYLEXRET; } } 
["]{_STRINGPIECE1}*	{ { YY_LEXLHS(BADSTRING);error(yylhs.text (), "syntax error: invalid string"); YYIGNORE; YYLEXRET; } } 
(r\"|R\"){_STRINGPIECE1}*	{ { YY_LEXLHS(BADSTRING);error(yylhs.text (), "syntax error: invalid rawstring"); YYIGNORE; YYLEXRET; } } 
[']{_STRINGPIECE2}*	{ { YY_LEXLHS(BADSTRING);error(yylhs.text (), "syntax error: invalid string"); YYIGNORE; YYLEXRET; } } 
(r\'|R\'){_STRINGPIECE2}*	{ { YY_LEXLHS(BADSTRING);error(yylhs.text (), "syntax error: invalid rawstring"); YYIGNORE; YYLEXRET; } } 
(r\"|R\"){_STRINGPIECE1}*\"	{ { YY_LEXLHS(RAWSTRING);yylhs = AST::make_token (RAWSTRING, yylhs.text_size () - 3,
                                              yylhs.text ()+2, false); YYLEXRET; } } 
(r\"\"\"|R\"\"\")(["]["]?)?({_LONGSTRINGPIECE1}+(["]["]?)?)*\"\"\"	{ { YY_LEXLHS(RAWSTRING);yylhs = AST::make_token (RAWSTRING, yylhs.text_size () - 7,
                                              yylhs.text ()+4, false); YYLEXRET; } } 
(r\'|R\'){_STRINGPIECE2}*\'	{ { YY_LEXLHS(RAWSTRING);yylhs = AST::make_token (RAWSTRING, yylhs.text_size () - 3,
                                              yylhs.text ()+2, false); YYLEXRET; } } 
(r\'\'\'|R\'\'\')(['][']?)?({_LONGSTRINGPIECE2}+(['][']?)?)*\'\'\'	{ { YY_LEXLHS(RAWSTRING);yylhs = AST::make_token (RAWSTRING, yylhs.text_size () - 7,
                                              yylhs.text ()+4, false); YYLEXRET; } } 


<YYPREFERRED>.|\n  { yyless(0); return -1; }
.|\n               { if (yytext[0] == YYEOF_CHAR) {
                         yyless (0);     
                         return YYEOF;
                     }
                     return yytext[0]; }

%%

#define YY_LEXER_2
#include "horn-parse-lex.cc"
