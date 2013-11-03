/* -*-C++-*- */
/* Generated from apyc.hn at Wed Oct 16 13:37:59 2013 GMT. */

%code top {

#define YYPARAM Tree_Semantics< AST >
#define YYPRODUCING_TREES
#define YYERROR_FUNCTION_NAME error

# define YY_PARSER_1
# include "horn-parse-lex.cc"
}

%{

    YYNAMESPACE_OPEN

%}

/* User prologue code */


#line 7 "apyc.hn"


%{
  #include <string>
  #include <stack>
  #include "apyc.h"
  #include "ast.h"

  using namespace std;

  static AST_Ptr theTree;
  static stack <int> indent_stack;
  static int bracket_count;

  /* Utilities */
  /** Return a new unop node corresponding to OPERANDS, which is the list of
   *  right-hand-side semantic values of a unop production (consisting of a
   *  token for the operator, followed by the AST for the operand). */
  static AST_Ptr make_unop (const List_Ptr& operands);

  /** Return a new binop node corresponding to OPERANDS, which is the list of
   *  right-hand-side semantic values of a binop production (consisting of an
   *  AST for the first operand, a token for the operator, and an AST for the
   *  second operand). */
  static AST_Ptr make_binop (const List_Ptr& operands);

  /** Return a new ID node, where the text of the identifier is given by
   *  TOKEN. */
  static AST_Ptr make_id (AST_Ptr& token);

  /** Return a new KEY node corresponding to OPERANDS. */
  static AST_Ptr make_expr (const int KEY, const List_Ptr& operands);

  /** Return the number of spaces in the leading whitespace (including tabs)
   *  of a line. From left to right, the tab is replaced with one to eight
   *  whitespace such that the number of whitespaces up to and including
   *  the replacement is a multiple of eight. */
  static int count_leading_whitespaces (const char* text, const int text_size);

%}

%glr-parser
%expect 1
%expect-rr 5
%debug
#line 52 "apyc.hn"


/* A token declaration such as
 *   %token INDENT
 * declares a new integer constant INDENT, which serves as a syntactic category
 * (suitable for output by the lexer) identifying a kind of token, which we
 * also often refer to as INDENT. A declaration such as
 *   %token IF "if"
 * defines a constant IF and makes it the syntactic category for the token
 * "if".  The built-in function yyexternal_token_name(...) maps between
 * syntactic categories (like IF) and the token strings defined in these
 * %token declarations (like "if").
 *
 * The Horn system uses tokens as leaf nodes and as AST node operators.  A
 * rule such as
 *     if_stmt: "if"^ expression ":"! ...
 * with no action, by default creates an AST node whose operator is an "if"
 * token (with syntactic category IF, given the %token declaration above).
 * When the node type does not correspond to a token that appears in the
 * program, we define a dummy token type that serves only as an AST
 * node type.  For example, we can define
 *     %token DICT_DISPLAY ...
 * and then use
 *     dict_display: "{"! key_datum_list? "}"!
 *              { $$ = $^(DICT_DISPLAY, $*); }
 * in the grammar (using DICT_DISPLAY only in actions, not as a grammar
 * symbol).
 *
 * In this skeleton, we've used a simple kludge to extract the printed forms
 * of AST operators from the operators themselves.  When a token such as IF
 * is the operator, yyexternal_token_name returns the operator name directly.
 * When there is no such correspondence, as with DICT_DISPLAY, we'll define
 *     %token DICT_DISPLAY "@dict_display"
 * Since "@dict_display" is not a valid token (it would be an error for this
 * to appear in any Python program) and does not appear in the grammar, this
 * declaration has no effect on the language recognized.  However, it
 * still provides an easy way to find the external name of an operator (just
 * strip off the leading "@").  (We can't just use "dict_display", since that
 * would tell Horn to define 'dict_display' as a token, whereas it would be a
 * simple identifier if it actually appeared in a Python program.  This is
 * where the kludginess comes in.) The AST_Tree::external_name method does
 * this conversion, converting tokens that are supposed to represent
 * node operators to printable strings.
 */

%token ID

%token PRINTLN "@println"
%token EMPTY
%token EXPR_LIST "@expr_list"
%token MODULE "@module"
%token BINOP "@binop"
%token UNOP "@unop"
/* Indentation */
%token INDENT
%token DEDENT
/* Basic Statements */
%token STMT_LIST "@stmt_list"
%token PRINT "@print"
%token RETURN "@return"
%token BREAK "@break"
%token CONTINUE "@continue"
%token NATIVE "@native"
/* Control Structures */
%token IF "@if"
%token FOR "@for"
%token WHILE "@while"
%token BLOCK "@block"
/* Assignments and Types */
%token ASSIGN "@assign"
%token TARGET_LIST "@target_list"
%token ATTR_REF "@attributeref"
%token SUBSCRIPTION "@subscription"
%token SLICING "@slicing"
%token TYPE "@type"
%token TYPED_ID "@typed_id"
%token TYPE_VAR "@type_var"
%token TYPE_LIST "@type_list"
%token TYPE_FORMALS_LIST "@type_formals_list"
%token FORMALS_LIST "@formals_list"
%token FUNCT_TYPE "@function_type"
/* Special structures */
%token DEFINITION "@def"
%token CLASS "@class"
/* Expressions */
%token COMPARE "@compare"
%token LCOMPARE "@left_compare"
%token AND "@and"
%token OR "@or"
%token IF_EXPR "@if_expr"
%token TUPLE "@tuple"
%token LIST "@list_display"
%token DICT "@dict_display"
%token PAIR "@pair"
%token CALL "@call"
%token EXPO "**"
%token ISNOT
%token NOTIN
/* Associativity + Precedence */
%left "or"
%left "and"
%left "in" NOTIN
%left "is" ISNOT
%left '<' '>' "<=" ">=" "==" "!="
%left '+' '-'
%left '%' '*' '/' "//"
%left "&&" "||"
%right EXPO

#line 180 "apyc-parser.y"

/* Horn prologue */

%defines
%token-table

%{

#define YY_PARSER_2
#include "horn-parse-lex.cc"

%}

/* Token definitions */

%token _TOK_23 "!="
%token '%' "%"
%token '(' "("
%token ')' ")"
%token '*' "*"
%token '+' "+"
%token ',' ","
%token '-' "-"
%token _TOK_17 "->"
%token '.' "."
%token '/' "/"
%token _TOK_25 "//"
%token ':' ":"
%token _TOK_3 "::"
%token ';' ";"
%token '<' "<"
%token _TOK_20 "<="
%token '=' "="
%token _TOK_22 "=="
%token '>' ">"
%token _TOK_21 ">="
%token _TOK_16 ">>"
%token '[' "["
%token ']' "]"
%token _TOK_18 "and"
%token _TOK_6 "break"
%token _TOK_0 "class"
%token _TOK_7 "continue"
%token _TOK_2 "def"
%token _TOK_12 "elif"
%token _TOK_13 "else"
%token _TOK_8 "for"
%token _TOK_11 "if"
%token _TOK_9 "in"
%token _TOK_24 "is"
%token _TOK_14 "native"
%token _TOK_26 "not"
%token _TOK_1 "of"
%token _TOK_19 "or"
%token _TOK_4 "pass"
%token _TOK_15 "print"
%token _TOK_5 "return"
%token _TOK_10 "while"
%token '{' "{"
%token '}' "}"
%token  BADSTRING
%token  BLANK_LINE
%token  END_OF_FILE
%token  INDENTATION
%token  INT_LITERAL
%token  NEWLINE
%token  RAWSTRING
%token  STRING
%token  UNUSED_KEYWORD


/* Destroying discarded semantic values. */
%destructor { $$._destructor (); } <>

%{
static yyvar yyv_B;
static yyvar yyv_D;
static yyvar yyv_DEDENT;
static yyvar yyv_E;
static yyvar yyv_E0;
static yyvar yyv_E1;
static yyvar yyv_EXPO;
static yyvar yyv_I;
static yyvar yyv_ID;
static yyvar yyv_INDENT;
static yyvar yyv_INT_LITERAL;
static yyvar yyv_ISNOT;
static yyvar yyv_NEWLINE;
static yyvar yyv_NOTIN;
static yyvar yyv_P1;
static yyvar yyv_P2;
static yyvar yyv_RAWSTRING;
static yyvar yyv_S;
static yyvar yyv_S1;
static yyvar yyv_S2;
static yyvar yyv_STRING;
static yyvar yyv_T;
static yyvar yyv_TYPE_VAR;
static yyvar yyv_arith_expr;
static yyvar yyv_assign;
static yyvar yyv_basic_statement;
static yyvar yyv_block;
static yyvar yyv_boolean_expr;
static yyvar yyv_classdef;
static yyvar yyv_compare_expr;
static yyvar yyv_control_structure;
static yyvar yyv_definition;
static yyvar yyv_dict;
static yyvar yyv_elif_stmts;
static yyvar yyv_else_stmt;
static yyvar yyv_expo_expr;
static yyvar yyv_expression;
static yyvar yyv_expression0;
static yyvar yyv_expression_list;
static yyvar yyv_expression_list0;
static yyvar yyv_for_loop;
static yyvar yyv_formals;
static yyvar yyv_function_call;
static yyvar yyv_if_expr;
static yyvar yyv_if_stmt;
static yyvar yyv_lcompare_expr;
static yyvar yyv_native_stmt;
static yyvar yyv_pair;
static yyvar yyv_plist;
static yyvar yyv_primary_expr;
static yyvar yyv_print_stmt;
static yyvar yyv_right_side;
static yyvar yyv_root_expr;
static yyvar yyv_semi_block;
static yyvar yyv_semi_stmt_list;
static yyvar yyv_simple_target;
static yyvar yyv_statement;
static yyvar yyv_stmt_list;
static yyvar yyv_stmt_list0;
static yyvar yyv_str_expr;
static yyvar yyv_target;
static yyvar yyv_target_list;
static yyvar yyv_target_list_br;
static yyvar yyv_tlist;
static yyvar yyv_tuple_ext_expr;
static yyvar yyv_type;
static yyvar yyv_type_formals;
static yyvar yyv_type_id;
static yyvar yyv_type_id0;
static yyvar yyv_type_list0;
static yyvar yyv_type_list1;
static yyvar yyv_type_var;
static yyvar yyv_typed_id;
static yyvar yyv_unary_expr;
static yyvar yyv_while_loop;

%}

%%



program : 
#line 163 "apyc.hn"
 stmt_list   { YYCTLPA($$,0,1,&$1);  yyv_stmt_list = $1;theTree = YYMAKE_TREE(MODULE, yylhs.all_values ()); yylhs = NULL; } 
;



stmt_list : 
#line 167 "apyc.hn"
 __13
                        { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); } 
 | 
#line 169 "apyc.hn"
/* empty */  /* empty */       { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(STMT_LIST); } 
;



stmt_list0 : 
#line 173 "apyc.hn"
 __15
                        { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); } 
 | 
#line 175 "apyc.hn"
/* empty */  /* empty */       { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(STMT_LIST); } 
;



/* STATEMENT */
statement : 
#line 179 "apyc.hn"

      basic_statement { YYCTLPA($$,0,1,&$1);  yyv_basic_statement = $1; }
;



// CLASS

classdef : 
#line 185 "apyc.hn"

      "class" ID "of" '[' type_formals ']' ':' NEWLINE INDENT block DEDENT
                      { YYCTLPA($$,0,11,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10,&$11);  $1.ignore(); $3.ignore(); $4.ignore(); $6.ignore(); $7.ignore(); $8.ignore(); $9.ignore(); $11.ignore(); yyv_ID = $2; yyv_type_formals = $5; yyv_NEWLINE = $8; yyv_INDENT = $9; yyv_block = $10; yyv_DEDENT = $11;yylhs = YYMAKE_TREE(CLASS,yyv_ID,yyv_type_formals,yyv_block); } 
 | 
#line 188 "apyc.hn"
 "class" ID ':' NEWLINE INDENT block DEDENT
                      { YYCTLPA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $1.ignore(); $3.ignore(); $4.ignore(); $5.ignore(); $7.ignore(); yyv_ID = $2; yyv_NEWLINE = $4; yyv_INDENT = $5; yyv_block = $6; yyv_DEDENT = $7;yylhs = YYMAKE_TREE(CLASS,yyv_ID,YYMAKE_TREE(TYPE_FORMALS_LIST),yyv_block); } 
 | 
#line 190 "apyc.hn"
 "class" ID "of" '[' type_formals ']' ':' semi_block NEWLINE
                      { YYCTLPA($$,0,9,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9);  $1.ignore(); $3.ignore(); $4.ignore(); $6.ignore(); $7.ignore(); $9.ignore(); yyv_ID = $2; yyv_type_formals = $5; yyv_semi_block = $8; yyv_NEWLINE = $9;yylhs = YYMAKE_TREE(CLASS,yyv_ID,yyv_type_formals,yyv_semi_block); } 
 | 
#line 192 "apyc.hn"
 "class" ID ':' semi_block NEWLINE
                      { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $3.ignore(); $5.ignore(); yyv_ID = $2; yyv_semi_block = $4; yyv_NEWLINE = $5;yylhs = YYMAKE_TREE(CLASS,yyv_ID,YYMAKE_TREE(TYPE_FORMALS_LIST),yyv_semi_block); } 
;



type_formals : 
#line 196 "apyc.hn"

      type_var __28
                      { YYCTLA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(TYPE_FORMALS_LIST,yylhs.all_values ()); } 
;



// DEFINITION

definition : 
#line 203 "apyc.hn"

      "def" ID '(' formals ')' "::" type ':' NEWLINE INDENT block DEDENT
                      { YYCTLPA($$,0,12,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10,&$11,&$12);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $8.ignore(); $9.ignore(); $10.ignore(); $12.ignore(); yyv_ID = $2; yyv_formals = $4; yyv_type = $7; yyv_NEWLINE = $9; yyv_INDENT = $10; yyv_block = $11; yyv_DEDENT = $12;yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,yyv_type,yyv_block); } 
 | 
#line 206 "apyc.hn"
 "def" ID '(' formals ')' ':' NEWLINE INDENT block DEDENT
                      { YYCTLPA($$,0,10,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $7.ignore(); $8.ignore(); $10.ignore(); yyv_ID = $2; yyv_formals = $4; yyv_NEWLINE = $7; yyv_INDENT = $8; yyv_block = $9; yyv_DEDENT = $10;yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,YYMAKE_TREE(EMPTY),yyv_block); } 
 | 
#line 208 "apyc.hn"
 "def" ID '(' formals ')' "::" type ':' semi_block NEWLINE
                      { YYCTLPA($$,0,10,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $8.ignore(); $10.ignore(); yyv_ID = $2; yyv_formals = $4; yyv_type = $7; yyv_semi_block = $9; yyv_NEWLINE = $10;yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,yyv_type,yyv_semi_block); } 
 | 
#line 210 "apyc.hn"
 "def" ID '(' formals ')' ':' semi_block NEWLINE
                      { YYCTLPA($$,0,8,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $8.ignore(); yyv_ID = $2; yyv_formals = $4; yyv_semi_block = $7; yyv_NEWLINE = $8;yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,YYMAKE_TREE(EMPTY),yyv_semi_block); } 
 | 
#line 212 "apyc.hn"
 "def" ID '(' formals ')' ':' native_stmt __34 NEWLINE
                      { YYCTLA($$,0,9,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $9.ignore(); yyv_NEWLINE = $9;yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, YYMAKE_TREE(EMPTY), YYMAKE_TREE(BLOCK, yyv_native_stmt)); } 
 | 
#line 214 "apyc.hn"
 "def" ID '(' formals ')' ':' NEWLINE INDENT native_stmt __35 NEWLINE DEDENT
                      { YYCTLA($$,0,12,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10,&$11,&$12);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $11.ignore(); $12.ignore(); yyv_NEWLINE = $11; yyv_DEDENT = $12;yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, YYMAKE_TREE(EMPTY), YYMAKE_TREE(BLOCK, yyv_native_stmt)); } 
 | 
#line 216 "apyc.hn"
 "def" ID '(' formals ')' "::" type ':' native_stmt __36 NEWLINE
                      { YYCTLA($$,0,11,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10,&$11);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $8.ignore(); $11.ignore(); yyv_NEWLINE = $11;yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, yyv_type, YYMAKE_TREE(BLOCK, yyv_native_stmt)); } 
 | 
#line 218 "apyc.hn"
 "def" ID '(' formals ')' "::" type ':' NEWLINE INDENT native_stmt __29 NEWLINE DEDENT
                      { YYCTLA($$,0,14,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10,&$11,&$12,&$13,&$14);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $8.ignore(); $13.ignore(); $14.ignore(); yyv_NEWLINE = $13; yyv_DEDENT = $14;yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, yyv_type, YYMAKE_TREE(BLOCK, yyv_native_stmt)); } 
;



formals : 
#line 223 "apyc.hn"
 __8 __16 __18
                      { YYCTLA($$,0,3,&$1,&$2,&$3); yylhs = YYMAKE_TREE(FORMALS_LIST,yylhs.all_values ()); } 
 | 
#line 225 "apyc.hn"
/* empty */  /*empty*/
                      { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(FORMALS_LIST); } 
;



block : 
#line 230 "apyc.hn"
 __14
                      { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); } 
 | 
#line 232 "apyc.hn"
/* empty */  /*empty*/       { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(BLOCK); } 
;



semi_block : 
#line 235 "apyc.hn"

      statement __26 __19
                      { YYCTLA($$,0,3,&$1,&$2,&$3); yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); } 
;



basic_statement : 
#line 240 "apyc.hn"

      print_stmt { YYCTLPA($$,0,1,&$1);  yyv_print_stmt = $1; }
 | 
#line 242 "apyc.hn"
 assign { YYCTLPA($$,0,1,&$1);  yyv_assign = $1; }
 | 
#line 243 "apyc.hn"
 expression { YYCTLPA($$,0,1,&$1);  yyv_expression = $1; }
 | 
#line 244 "apyc.hn"
 "pass" { YYCTLPA($$,0,1,&$1);  $1.ignore(); }
 | 
#line 245 "apyc.hn"
 "return" expression0
                    { YYCTLPA($$,0,2,&$1,&$2);  $1.ignore(); yyv_expression0 = $2;yylhs = YYMAKE_TREE(RETURN, yylhs.all_values ()); } 
 | 
#line 247 "apyc.hn"
 "break"
                    { YYCTLPA($$,0,1,&$1);  $1.ignore();yylhs = YYMAKE_TREE(BREAK); } 
 | 
#line 249 "apyc.hn"
 "continue"
                    { YYCTLPA($$,0,1,&$1);  $1.ignore();yylhs = YYMAKE_TREE(CONTINUE); } 
;



control_structure : 
#line 253 "apyc.hn"

      for_loop { YYCTLPA($$,0,1,&$1);  yyv_for_loop = $1; }
 | 
#line 255 "apyc.hn"
 while_loop { YYCTLPA($$,0,1,&$1);  yyv_while_loop = $1; }
 | 
#line 256 "apyc.hn"
 if_stmt { YYCTLPA($$,0,1,&$1);  yyv_if_stmt = $1; }
;



semi_stmt_list : 
#line 259 "apyc.hn"

      statement __26 __19
                      { YYCTLA($$,0,3,&$1,&$2,&$3); yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); } 
;



for_loop : 
#line 264 "apyc.hn"

      "for" target_list  "in" tuple_ext_expr  ':' semi_stmt_list  NEWLINE
                    { YYCTLPA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $1.ignore(); $3.ignore(); $5.ignore(); $7.ignore(); yyv_T = $2; yyv_target_list = $2; yyv_E = $4; yyv_tuple_ext_expr = $4; yyv_S = $6; yyv_semi_stmt_list = $6; yyv_NEWLINE = $7;yylhs = YYMAKE_TREE(FOR,yyv_T,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); } 
 | 
#line 267 "apyc.hn"
 "for" target_list  "in" tuple_ext_expr  ':' NEWLINE INDENT stmt_list0  DEDENT
                    { YYCTLPA($$,0,9,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $7.ignore(); $9.ignore(); yyv_T = $2; yyv_target_list = $2; yyv_E = $4; yyv_tuple_ext_expr = $4; yyv_NEWLINE = $6; yyv_INDENT = $7; yyv_S = $8; yyv_stmt_list0 = $8; yyv_DEDENT = $9;yylhs = YYMAKE_TREE(FOR,yyv_T,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); } 
 | 
#line 269 "apyc.hn"
 "for" target_list  "in" tuple_ext_expr  ':' NEWLINE INDENT stmt_list0  DEDENT else_stmt 
                    { YYCTLPA($$,0,10,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9,&$10);  $1.ignore(); $3.ignore(); $5.ignore(); $6.ignore(); $7.ignore(); $9.ignore(); yyv_T = $2; yyv_target_list = $2; yyv_E = $4; yyv_tuple_ext_expr = $4; yyv_NEWLINE = $6; yyv_INDENT = $7; yyv_S1 = $8; yyv_stmt_list0 = $8; yyv_DEDENT = $9; yyv_S2 = $10; yyv_else_stmt = $10;yylhs = YYMAKE_TREE(FOR,yyv_T,yyv_E,yyv_S1,yyv_S2); } 
;



while_loop : 
#line 273 "apyc.hn"

      "while" expression  ':' semi_stmt_list  NEWLINE
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $3.ignore(); $5.ignore(); yyv_E = $2; yyv_expression = $2; yyv_S = $4; yyv_semi_stmt_list = $4; yyv_NEWLINE = $5;yylhs = YYMAKE_TREE(WHILE,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); } 
 | 
#line 276 "apyc.hn"
 "while" expression  ':' NEWLINE INDENT stmt_list0  DEDENT
                    { YYCTLPA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $1.ignore(); $3.ignore(); $4.ignore(); $5.ignore(); $7.ignore(); yyv_E = $2; yyv_expression = $2; yyv_NEWLINE = $4; yyv_INDENT = $5; yyv_S = $6; yyv_stmt_list0 = $6; yyv_DEDENT = $7;yylhs = YYMAKE_TREE(WHILE,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); } 
 | 
#line 278 "apyc.hn"
 "while" expression  ':' NEWLINE INDENT stmt_list0  DEDENT else_stmt 
                    { YYCTLPA($$,0,8,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8);  $1.ignore(); $3.ignore(); $4.ignore(); $5.ignore(); $7.ignore(); yyv_E = $2; yyv_expression = $2; yyv_NEWLINE = $4; yyv_INDENT = $5; yyv_S1 = $6; yyv_stmt_list0 = $6; yyv_DEDENT = $7; yyv_S2 = $8; yyv_else_stmt = $8;yylhs = YYMAKE_TREE(WHILE,yyv_E,yyv_S1,yyv_S2); } 
;



if_stmt : 
#line 282 "apyc.hn"

      "if" expression  ':' semi_stmt_list  NEWLINE
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $3.ignore(); $5.ignore(); yyv_E = $2; yyv_expression = $2; yyv_S = $4; yyv_semi_stmt_list = $4; yyv_NEWLINE = $5;yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S, YYMAKE_TREE(EMPTY)); } 
 | 
#line 285 "apyc.hn"
 "if" expression  ':' semi_stmt_list  NEWLINE elif_stmts 
                    { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $1.ignore(); $3.ignore(); $5.ignore(); yyv_E = $2; yyv_expression = $2; yyv_S = $4; yyv_semi_stmt_list = $4; yyv_NEWLINE = $5; yyv_S1 = $6; yyv_elif_stmts = $6;yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S, yyv_S1); } 
 | 
#line 287 "apyc.hn"
 "if" expression  ':' NEWLINE INDENT  stmt_list0  DEDENT 
                    { YYCTLPA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $1.ignore(); $3.ignore(); $4.ignore(); $5.ignore(); $7.ignore(); yyv_E = $2; yyv_expression = $2; yyv_NEWLINE = $4; yyv_I = $5; yyv_INDENT = $5; yyv_S1 = $6; yyv_stmt_list0 = $6; yyv_D = $7; yyv_DEDENT = $7;yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S1, YYMAKE_TREE(EMPTY)); } 
 | 
#line 289 "apyc.hn"
 "if" expression  ':' NEWLINE INDENT stmt_list0  DEDENT elif_stmts 
                    { YYCTLPA($$,0,8,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8);  $1.ignore(); $3.ignore(); $4.ignore(); $5.ignore(); $7.ignore(); yyv_E = $2; yyv_expression = $2; yyv_NEWLINE = $4; yyv_INDENT = $5; yyv_S1 = $6; yyv_stmt_list0 = $6; yyv_DEDENT = $7; yyv_S2 = $8; yyv_elif_stmts = $8;yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S1, yyv_S2); } 
;



elif_stmts : 
#line 293 "apyc.hn"
 else_stmt 
                    { YYCTLPA($$,0,1,&$1);  yyv_S = $1; yyv_else_stmt = $1;yylhs = yyv_S; } 
 | 
#line 296 "apyc.hn"
 "elif" expression  ':' semi_stmt_list  NEWLINE
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $3.ignore(); $5.ignore(); yyv_E = $2; yyv_expression = $2; yyv_S = $4; yyv_semi_stmt_list = $4; yyv_NEWLINE = $5;yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S, YYMAKE_TREE(EMPTY)); } 
 | 
#line 298 "apyc.hn"
 "elif" expression  ':' semi_stmt_list  NEWLINE elif_stmts 
                    { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $1.ignore(); $3.ignore(); $5.ignore(); yyv_E = $2; yyv_expression = $2; yyv_S1 = $4; yyv_semi_stmt_list = $4; yyv_NEWLINE = $5; yyv_S2 = $6; yyv_elif_stmts = $6;yylhs =  YYMAKE_TREE(IF, yyv_E, YYMAKE_TREE(STMT_LIST, yyv_S1), yyv_S2); } 
 | 
#line 300 "apyc.hn"
 "elif" expression  ':' NEWLINE INDENT stmt_list0  DEDENT elif_stmts 
                    { YYCTLPA($$,0,8,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8);  $1.ignore(); $3.ignore(); $4.ignore(); $5.ignore(); $7.ignore(); yyv_E = $2; yyv_expression = $2; yyv_NEWLINE = $4; yyv_INDENT = $5; yyv_S1 = $6; yyv_stmt_list0 = $6; yyv_DEDENT = $7; yyv_S2 = $8; yyv_elif_stmts = $8;yylhs =  YYMAKE_TREE(IF, yyv_E, yyv_S1, yyv_S2); } 
 | 
#line 302 "apyc.hn"
 "elif" expression  ':' NEWLINE INDENT stmt_list0  DEDENT
                    { YYCTLPA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $1.ignore(); $3.ignore(); $4.ignore(); $5.ignore(); $7.ignore(); yyv_E = $2; yyv_expression = $2; yyv_NEWLINE = $4; yyv_INDENT = $5; yyv_S1 = $6; yyv_stmt_list0 = $6; yyv_DEDENT = $7;yylhs =  YYMAKE_TREE(IF, yyv_E, yyv_S1, YYMAKE_TREE(EMPTY)); } 
;



else_stmt : 
#line 306 "apyc.hn"

      "else" ':' semi_stmt_list  NEWLINE
                    { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $2.ignore(); $4.ignore(); yyv_B = $3; yyv_semi_stmt_list = $3; yyv_NEWLINE = $4;yylhs =  YYMAKE_TREE(STMT_LIST, yyv_B); } 
 | 
#line 309 "apyc.hn"
 "else" ':' NEWLINE INDENT stmt_list0  DEDENT
                    { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $1.ignore(); $2.ignore(); $3.ignore(); $4.ignore(); $6.ignore(); yyv_NEWLINE = $3; yyv_INDENT = $4; yyv_S = $5; yyv_stmt_list0 = $5; yyv_DEDENT = $6;yylhs =  yyv_S; } 
;



native_stmt : 
#line 313 "apyc.hn"

      "native" STRING
                    { YYCTLPA($$,0,2,&$1,&$2);  $1.ignore(); yyv_STRING = $2;yylhs = YYMAKE_TREE(NATIVE, yylhs.all_values ()); } 
;



print_stmt : 
#line 318 "apyc.hn"

      "print" ">>" expression
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $2.ignore(); yyv_expression = $3;yylhs = YYMAKE_TREE(PRINTLN, yyv_expression, YYMAKE_TREE(EXPR_LIST)); } 
 | 
#line 321 "apyc.hn"
 "print" ">>" expression ',' expression_list
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $2.ignore(); $4.ignore(); yyv_expression = $3; yyv_expression_list = $5;yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); } 
 | 
#line 323 "apyc.hn"
 "print" ">>" expression ',' plist
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $2.ignore(); $4.ignore(); yyv_expression = $3; yyv_plist = $5;yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); } 
 | 
#line 325 "apyc.hn"
 "print" expression_list0
                    { YYCTLPA($$,0,2,&$1,&$2);  $1.ignore(); yyv_expression_list0 = $2;yylhs = YYMAKE_TREE(PRINTLN, YYMAKE_TREE(EMPTY), yylhs.all_values ()); } 
 | 
#line 327 "apyc.hn"
 "print" plist
                    { YYCTLPA($$,0,2,&$1,&$2);  $1.ignore(); yyv_plist = $2;yylhs = YYMAKE_TREE(PRINT, YYMAKE_TREE(EMPTY), yylhs.all_values ()); } 
;



assign : 
#line 331 "apyc.hn"

      target_list '=' right_side
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_target_list = $1; yyv_right_side = $3;yylhs = YYMAKE_TREE(ASSIGN, yylhs.all_values ()); } 
;



target_list : 
#line 336 "apyc.hn"

      target { YYCTLPA($$,0,1,&$1);  yyv_target = $1; }
 | 
#line 338 "apyc.hn"
 target ','
                    { YYCTLPA($$,0,2,&$1,&$2);  $2.ignore(); yyv_target = $1;yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); } 
 | 
#line 340 "apyc.hn"
 tlist { YYCTLPA($$,0,1,&$1);  yyv_tlist = $1; }
 | 
#line 341 "apyc.hn"
 target __9
                    { YYCTLA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); } 
 | 
#line 343 "apyc.hn"
 '(' target_list ')' { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_target_list = $2; }
 | 
#line 344 "apyc.hn"
 target_list_br { YYCTLPA($$,0,1,&$1);  yyv_target_list_br = $1; }
;



target_list_br : 
#line 347 "apyc.hn"

      '[' tlist ']' { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_tlist = $2; }
 | 
#line 349 "apyc.hn"
 '[' target __32 ']'
                    { YYCTLA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $4.ignore();yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); } 
 | 
#line 351 "apyc.hn"
 '[' target __10 ']'
                    { YYCTLA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $4.ignore();yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); } 
;



tlist : 
#line 355 "apyc.hn"

      target __9 ','
                    { YYCTLA($$,0,3,&$1,&$2,&$3);  $3.ignore();yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); } 
;



// TYPES

typed_id : 
#line 362 "apyc.hn"

      ID "::" type
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_ID = $1; yyv_type = $3;yylhs = YYMAKE_TREE(TYPED_ID, yyv_ID, yyv_type); } 
;



type : 
#line 367 "apyc.hn"

      type_id { YYCTLPA($$,0,1,&$1);  yyv_type_id = $1; }
 | 
#line 369 "apyc.hn"
 type_var { YYCTLPA($$,0,1,&$1);  yyv_type_var = $1; }
 | 
#line 370 "apyc.hn"
 '(' type_list0 ')' "->" type
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $3.ignore(); $4.ignore(); yyv_type_list0 = $2; yyv_type = $5;yylhs = YYMAKE_TREE(FUNCT_TYPE, yyv_type, yyv_type_list0); } 
 | 
#line 372 "apyc.hn"
 '(' ')' "->" type
                    { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $2.ignore(); $3.ignore(); yyv_type = $4;yylhs = YYMAKE_TREE(FUNCT_TYPE, yyv_type, YYMAKE_TREE(TYPE_LIST)); } 
;



type_id0 : 
#line 376 "apyc.hn"

      ID "of" '[' type_list0 ']'
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $2.ignore(); $3.ignore(); $5.ignore(); yyv_ID = $1; yyv_type_list0 = $4;yylhs = YYMAKE_TREE(TYPE, yyv_ID, yyv_type_list0); } 
 | 
#line 379 "apyc.hn"
 ID "of" type_list1
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_ID = $1; yyv_type_list1 = $3;yylhs = YYMAKE_TREE(TYPE, yyv_ID, yyv_type_list1); } 
;



type_id : 
#line 383 "apyc.hn"

      type_id0 { YYCTLPA($$,0,1,&$1);  yyv_type_id0 = $1; }
 | 
#line 385 "apyc.hn"
 ID
                    { YYCTLPA($$,0,1,&$1);  yyv_ID = $1;yylhs = YYMAKE_TREE(TYPE, yyv_ID, YYMAKE_TREE(TYPE_LIST)); } 
;



type_var : 
#line 389 "apyc.hn"

      TYPE_VAR
                    { YYCTLPA($$,0,1,&$1);  yyv_TYPE_VAR = $1;yylhs = yyv_TYPE_VAR; } 
;



type_list0 : 
#line 394 "apyc.hn"

      type __27
                    { YYCTLA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); } 
;



type_list1 : 
#line 399 "apyc.hn"

      type
                    { YYCTLPA($$,0,1,&$1);  yyv_type = $1;yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); } 
;



// Assignment

target : 
#line 406 "apyc.hn"

      simple_target { YYCTLPA($$,0,1,&$1);  yyv_simple_target = $1; }
 | 
#line 408 "apyc.hn"
 typed_id { YYCTLPA($$,0,1,&$1);  yyv_typed_id = $1; }
;



right_side : 
#line 411 "apyc.hn"

      tuple_ext_expr { YYCTLPA($$,0,1,&$1);  yyv_tuple_ext_expr = $1; }
 | 
#line 413 "apyc.hn"
 assign { YYCTLPA($$,0,1,&$1);  yyv_assign = $1; }
;



/* EXPRESSIONS */

plist : 
#line 418 "apyc.hn"

      expression __25 ','
                      { YYCTLA($$,0,3,&$1,&$2,&$3);  $3.ignore();yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); } 
;



expression_list0 : 
#line 423 "apyc.hn"

      expression_list { YYCTLPA($$,0,1,&$1);  yyv_expression_list = $1; }
 | 
#line 425 "apyc.hn"
/* empty */  /* empty */     { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(EXPR_LIST); } 
;



expression_list : 
#line 428 "apyc.hn"

      expression __25
                      { YYCTLA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); } 
;



tuple_ext_expr : 
#line 433 "apyc.hn"

      expression { YYCTLPA($$,0,1,&$1);  yyv_expression = $1; }
 | 
#line 435 "apyc.hn"
 expression ',' __30 __20
                      { YYCTLA($$,0,4,&$1,&$2,&$3,&$4);  $2.ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); } 
;



expression0 : 
#line 439 "apyc.hn"

      expression { YYCTLPA($$,0,1,&$1);  yyv_expression = $1; }
 | 
#line 441 "apyc.hn"
/* empty */  /* empty */     { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(EMPTY); } 
;



expression : 
#line 444 "apyc.hn"

      root_expr { YYCTLPA($$,0,1,&$1);  yyv_root_expr = $1; }
;



function_call : 
#line 448 "apyc.hn"

      type_id0 '(' expression_list0 ')'
                      { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $2.ignore(); $4.ignore(); yyv_type_id0 = $1; yyv_expression_list0 = $3;yylhs = YYMAKE_TREE(CALL,yyv_type_id0,yyv_expression_list0); } 
 | 
#line 451 "apyc.hn"
 type_id0 '(' expression_list0  ',' ')'
                      { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $2.ignore(); $4.ignore(); $5.ignore(); yyv_type_id0 = $1; yyv_expression_list0 = $3;yylhs = YYMAKE_TREE(CALL,yyv_type_id0,yyv_expression_list0); } 
 | 
#line 453 "apyc.hn"
 primary_expr '(' expression_list0 ')'
                      { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $2.ignore(); $4.ignore(); yyv_primary_expr = $1; yyv_expression_list0 = $3;yylhs = YYMAKE_TREE(CALL,yyv_primary_expr,yyv_expression_list0); } 
 | 
#line 455 "apyc.hn"
 primary_expr '(' expression_list0 ',' ')'
                      { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $2.ignore(); $4.ignore(); $5.ignore(); yyv_primary_expr = $1; yyv_expression_list0 = $3;yylhs = YYMAKE_TREE(CALL,yyv_primary_expr,yyv_expression_list0); } 
;



root_expr : 
#line 459 "apyc.hn"

      if_expr { YYCTLPA($$,0,1,&$1);  yyv_if_expr = $1; }
 | 
#line 461 "apyc.hn"
 boolean_expr { YYCTLPA($$,0,1,&$1);  yyv_boolean_expr = $1; }
;



if_expr : 
#line 464 "apyc.hn"
 boolean_expr  "if" root_expr  "else" root_expr 
                    { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $2.ignore(); $4.ignore(); yyv_E0 = $1; yyv_boolean_expr = $1; yyv_T = $3; yyv_root_expr = $3; yyv_E1 = $5; yyv_root_expr = $5;yylhs = YYMAKE_TREE(IF_EXPR, yyv_T, yyv_E0, yyv_E1); } 
;



boolean_expr : 
#line 469 "apyc.hn"

      arith_expr { YYCTLPA($$,0,1,&$1);  yyv_arith_expr = $1; }
 | 
#line 471 "apyc.hn"
 compare_expr { YYCTLPA($$,0,1,&$1);  yyv_compare_expr = $1; }
 | 
#line 472 "apyc.hn"
 boolean_expr "and"  boolean_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_boolean_expr = $1; yyv_type = $2; yyv_boolean_expr = $3;int token_id = yyv_type.value()->as_string().compare("and") == 0 ? AND : OR;
                      yylhs = YYMAKE_TREE(token_id, yylhs.all_values ()); } 
 | 
#line 472 "apyc.hn"
 boolean_expr "or"  boolean_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_boolean_expr = $1; yyv_type = $2; yyv_boolean_expr = $3;int token_id = yyv_type.value()->as_string().compare("and") == 0 ? AND : OR;
                      yylhs = YYMAKE_TREE(token_id, yylhs.all_values ()); } 
;



compare_expr : 
#line 478 "apyc.hn"

      lcompare_expr '<' arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 478 "apyc.hn"

      lcompare_expr '>' arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 478 "apyc.hn"

      lcompare_expr "<=" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 478 "apyc.hn"

      lcompare_expr ">=" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 478 "apyc.hn"

      lcompare_expr "==" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 478 "apyc.hn"

      lcompare_expr "!=" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 478 "apyc.hn"

      lcompare_expr "in" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 478 "apyc.hn"

      lcompare_expr "is" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 481 "apyc.hn"
 lcompare_expr ISNOT arith_expr
                     { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_ISNOT = $2; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
 | 
#line 483 "apyc.hn"
 lcompare_expr NOTIN arith_expr
                     { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_NOTIN = $2; yyv_arith_expr = $3;yylhs = make_expr(COMPARE, yylhs.all_values ()); } 
;



lcompare_expr : 
#line 487 "apyc.hn"

     arith_expr { YYCTLPA($$,0,1,&$1);  yyv_arith_expr = $1; }
 | 
#line 489 "apyc.hn"
 lcompare_expr '<' arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 489 "apyc.hn"
 lcompare_expr '>' arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 489 "apyc.hn"
 lcompare_expr "<=" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 489 "apyc.hn"
 lcompare_expr ">=" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 489 "apyc.hn"
 lcompare_expr "==" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 489 "apyc.hn"
 lcompare_expr "!=" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 489 "apyc.hn"
 lcompare_expr "in" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 489 "apyc.hn"
 lcompare_expr "is" arith_expr
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 491 "apyc.hn"
 lcompare_expr ISNOT arith_expr
                     { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_ISNOT = $2; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
 | 
#line 493 "apyc.hn"
 lcompare_expr NOTIN arith_expr
                     { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_lcompare_expr = $1; yyv_NOTIN = $2; yyv_arith_expr = $3;yylhs = make_expr(LCOMPARE, yylhs.all_values ()); } 
;



arith_expr : 
#line 497 "apyc.hn"

      unary_expr { YYCTLPA($$,0,1,&$1);  yyv_unary_expr = $1; }
 | 
#line 499 "apyc.hn"
 arith_expr '+' arith_expr
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_arith_expr = $1; yyv_arith_expr = $3;yylhs = make_binop(yylhs.all_values ()); } 
 | 
#line 499 "apyc.hn"
 arith_expr '-' arith_expr
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_arith_expr = $1; yyv_arith_expr = $3;yylhs = make_binop(yylhs.all_values ()); } 
 | 
#line 499 "apyc.hn"
 arith_expr '*' arith_expr
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_arith_expr = $1; yyv_arith_expr = $3;yylhs = make_binop(yylhs.all_values ()); } 
 | 
#line 499 "apyc.hn"
 arith_expr '/' arith_expr
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_arith_expr = $1; yyv_arith_expr = $3;yylhs = make_binop(yylhs.all_values ()); } 
 | 
#line 499 "apyc.hn"
 arith_expr "//" arith_expr
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_arith_expr = $1; yyv_arith_expr = $3;yylhs = make_binop(yylhs.all_values ()); } 
 | 
#line 499 "apyc.hn"
 arith_expr '%' arith_expr
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_arith_expr = $1; yyv_arith_expr = $3;yylhs = make_binop(yylhs.all_values ()); } 
;



unary_expr : 
#line 503 "apyc.hn"

      expo_expr { YYCTLPA($$,0,1,&$1);  yyv_expo_expr = $1; }
 | 
#line 505 "apyc.hn"
 '+' unary_expr
                      { YYCTLPA($$,0,2,&$1,&$2);  yyv_unary_expr = $2;yylhs = make_unop(yylhs.all_values ()); } 
 | 
#line 505 "apyc.hn"
 '-' unary_expr
                      { YYCTLPA($$,0,2,&$1,&$2);  yyv_unary_expr = $2;yylhs = make_unop(yylhs.all_values ()); } 
 | 
#line 505 "apyc.hn"
 "not" unary_expr
                      { YYCTLPA($$,0,2,&$1,&$2);  yyv_unary_expr = $2;yylhs = make_unop(yylhs.all_values ()); } 
;



expo_expr : 
#line 509 "apyc.hn"

      primary_expr { YYCTLPA($$,0,1,&$1);  yyv_primary_expr = $1; }
 | 
#line 511 "apyc.hn"
 expo_expr EXPO expo_expr
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expo_expr = $1; yyv_EXPO = $2; yyv_expo_expr = $3;yylhs = make_binop(yylhs.all_values ()); } 
;



primary_expr : 
#line 515 "apyc.hn"

      INT_LITERAL { YYCTLPA($$,0,1,&$1);  yyv_INT_LITERAL = $1; }
 | 
#line 517 "apyc.hn"
 simple_target { YYCTLPA($$,0,1,&$1);  yyv_simple_target = $1; }
 | 
#line 518 "apyc.hn"
 str_expr { YYCTLPA($$,0,1,&$1);  yyv_str_expr = $1; }
 | 
#line 519 "apyc.hn"
 dict { YYCTLPA($$,0,1,&$1);  yyv_dict = $1; }
 | 
#line 520 "apyc.hn"
 '(' ')'
                      { YYCTLPA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(TUPLE); } 
 | 
#line 522 "apyc.hn"
 '[' ']'
                      { YYCTLPA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(LIST); } 
 | 
#line 524 "apyc.hn"
 '(' expression ',' __33 __22 ')'
                      { YYCTLA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $1.ignore(); $3.ignore(); $6.ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); } 
 | 
#line 526 "apyc.hn"
 '[' expression __31 __21 ']'
                      { YYCTLA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $5.ignore();yylhs = YYMAKE_TREE(LIST, yylhs.all_values ()); } 
 | 
#line 528 "apyc.hn"
 '(' root_expr ')' { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_root_expr = $2; }
 | 
#line 529 "apyc.hn"
 function_call { YYCTLPA($$,0,1,&$1);  yyv_function_call = $1; }
;



simple_target : 
#line 532 "apyc.hn"

      ID { YYCTLPA($$,0,1,&$1);  yyv_ID = $1; }
 | 
#line 534 "apyc.hn"
 primary_expr '.' ID
                    { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_primary_expr = $1; yyv_ID = $3;yylhs = YYMAKE_TREE(ATTR_REF, yylhs.all_values ()); } 
 | 
#line 536 "apyc.hn"
 primary_expr '[' tuple_ext_expr ']'
                    { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $2.ignore(); $4.ignore(); yyv_primary_expr = $1; yyv_tuple_ext_expr = $3;yylhs = YYMAKE_TREE(SUBSCRIPTION, yylhs.all_values ()); } 
 | 
#line 538 "apyc.hn"
 primary_expr '[' expression0 ':' expression0 ']'
                    { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $2.ignore(); $4.ignore(); $6.ignore(); yyv_primary_expr = $1; yyv_expression0 = $3; yyv_expression0 = $5;yylhs = YYMAKE_TREE(SLICING, yylhs.all_values ()); } 
;



pair : 
#line 542 "apyc.hn"
 expression  ':' expression 
                      { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_P1 = $1; yyv_expression = $1; yyv_P2 = $3; yyv_expression = $3;yylhs = YYMAKE_TREE(PAIR,yyv_P1,yyv_P2); } 
;



dict : 
#line 547 "apyc.hn"

      '{' __24 __17 '}'
                      { YYCTLA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $4.ignore();yylhs = YYMAKE_TREE(DICT, yylhs.all_values ()); } 
;



str_expr : 
#line 552 "apyc.hn"

      STRING { YYCTLPA($$,0,1,&$1);  yyv_STRING = $1; }
 | 
#line 554 "apyc.hn"
 RAWSTRING { YYCTLPA($$,0,1,&$1);  yyv_RAWSTRING = $1; }
 | 
#line 555 "apyc.hn"
 str_expr RAWSTRING 
                      { YYCTLPA($$,0,2,&$1,&$2);  yyv_str_expr = $1; yyv_S = $2; yyv_RAWSTRING = $2;string s = ((AST_Token *) yyv_S.value().data())->string_text();
                        ((AST_Token *) yyv_str_expr.value().data())->append_text(s);
                        yylhs = yyv_str_expr.value(); } 
 | 
#line 555 "apyc.hn"
 str_expr STRING 
                      { YYCTLPA($$,0,2,&$1,&$2);  yyv_str_expr = $1; yyv_S = $2; yyv_STRING = $2;string s = ((AST_Token *) yyv_S.value().data())->string_text();
                        ((AST_Token *) yyv_str_expr.value().data())->append_text(s);
                        yylhs = yyv_str_expr.value(); } 
;

 __0 : 
#line 548 "apyc.hn"
 pair NEWLINE ',' { YYCTLC($$,2,5,&$-1,&$0,&$1,&$2,&$3);  $2.ignore(); $3.ignore(); yyv_pair = $1; yyv_NEWLINE = $2; }
 | 
#line 548 "apyc.hn"
 pair ',' __23 { YYCTLC($$,2,5,&$-1,&$0,&$1,&$2,&$3);  $2.ignore(); }
;

 __1 : 
#line 167 "apyc.hn"
 statement __11 { YYCTLC($$,1,3,&$0,&$1,&$2);  }
 | 
#line 167 "apyc.hn"
 control_structure { YYCTLC($$,1,2,&$0,&$1);  yyv_control_structure = $1; }
 | 
#line 167 "apyc.hn"
 definition { YYCTLC($$,1,2,&$0,&$1);  yyv_definition = $1; }
 | 
#line 167 "apyc.hn"
 classdef { YYCTLC($$,1,2,&$0,&$1);  yyv_classdef = $1; }
 | 
#line 167 "apyc.hn"
 NEWLINE { YYCTLC($$,1,2,&$0,&$1);  $1.ignore(); yyv_NEWLINE = $1; }
;

 __2 : 
#line 230 "apyc.hn"
 statement __11 { YYCTLC($$,1,3,&$0,&$1,&$2);  }
 | 
#line 230 "apyc.hn"
 control_structure { YYCTLC($$,1,2,&$0,&$1);  yyv_control_structure = $1; }
 | 
#line 230 "apyc.hn"
 definition { YYCTLC($$,1,2,&$0,&$1);  yyv_definition = $1; }
 | 
#line 230 "apyc.hn"
 NEWLINE { YYCTLC($$,1,2,&$0,&$1);  $1.ignore(); yyv_NEWLINE = $1; }
;

 __3 : 
#line 173 "apyc.hn"
 statement __11 { YYCTLC($$,1,3,&$0,&$1,&$2);  }
 | 
#line 173 "apyc.hn"
 control_structure { YYCTLC($$,1,2,&$0,&$1);  yyv_control_structure = $1; }
 | 
#line 173 "apyc.hn"
 NEWLINE { YYCTLC($$,1,2,&$0,&$1);  $1.ignore(); yyv_NEWLINE = $1; }
;

 __4 : 
#line 167 "apyc.hn"
 statement __12 { YYCTLC($$,0,2,&$1,&$2);  }
 | 
#line 167 "apyc.hn"
 control_structure { YYCTLPC($$,0,1,&$1);  yyv_control_structure = $1; }
 | 
#line 167 "apyc.hn"
 definition { YYCTLPC($$,0,1,&$1);  yyv_definition = $1; }
 | 
#line 167 "apyc.hn"
 classdef { YYCTLPC($$,0,1,&$1);  yyv_classdef = $1; }
 | 
#line 167 "apyc.hn"
 NEWLINE { YYCTLPC($$,0,1,&$1);  $1.ignore(); yyv_NEWLINE = $1; }
;

 __5 : 
#line 230 "apyc.hn"
 statement __12 { YYCTLC($$,0,2,&$1,&$2);  }
 | 
#line 230 "apyc.hn"
 control_structure { YYCTLPC($$,0,1,&$1);  yyv_control_structure = $1; }
 | 
#line 230 "apyc.hn"
 definition { YYCTLPC($$,0,1,&$1);  yyv_definition = $1; }
 | 
#line 230 "apyc.hn"
 NEWLINE { YYCTLPC($$,0,1,&$1);  $1.ignore(); yyv_NEWLINE = $1; }
;

 __6 : 
#line 173 "apyc.hn"
 statement __12 { YYCTLC($$,0,2,&$1,&$2);  }
 | 
#line 173 "apyc.hn"
 control_structure { YYCTLPC($$,0,1,&$1);  yyv_control_structure = $1; }
 | 
#line 173 "apyc.hn"
 NEWLINE { YYCTLPC($$,0,1,&$1);  $1.ignore(); yyv_NEWLINE = $1; }
;

 __7 : 
#line 223 "apyc.hn"
 typed_id { YYCTLC($$,3,4,&$-2,&$-1,&$0,&$1);  yyv_typed_id = $1; }
 | 
#line 223 "apyc.hn"
 ID { YYCTLC($$,3,4,&$-2,&$-1,&$0,&$1);  yyv_ID = $1; }
;

 __8 : 
#line 223 "apyc.hn"
 typed_id { YYCTLPC($$,0,1,&$1);  yyv_typed_id = $1; }
 | 
#line 223 "apyc.hn"
 ID { YYCTLPC($$,0,1,&$1);  yyv_ID = $1; }
;

 __9 : 
#line 341 "apyc.hn"
 ',' target { YYCTLPC($$,1,3,&$0,&$1,&$2);  $1.ignore(); yyv_target = $0; yyv_target = $2; }
 | 
#line 341 "apyc.hn"
 __9 ',' target { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_target = $3; }
;

 __10 : 
#line 351 "apyc.hn"
 ',' target { YYCTLPC($$,2,4,&$-1,&$0,&$1,&$2);  $1.ignore(); yyv_target = $0; yyv_target = $2; }
 | 
#line 351 "apyc.hn"
 __10 ',' target { YYCTLC($$,2,5,&$-1,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_target = $3; }
;

 __11 : 
#line 167 "apyc.hn"
 NEWLINE { YYCTLC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); yyv_statement = $0; yyv_NEWLINE = $1; }
 | 
#line 167 "apyc.hn"
 ';' { YYCTLC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); yyv_statement = $0; }
;

 __12 : 
#line 167 "apyc.hn"
 NEWLINE { YYCTLPC($$,1,2,&$0,&$1);  $1.ignore(); yyv_statement = $0; yyv_NEWLINE = $1; }
 | 
#line 167 "apyc.hn"
 ';' { YYCTLPC($$,1,2,&$0,&$1);  $1.ignore(); yyv_statement = $0; }
;

 __13 : 
#line 167 "apyc.hn"
 __4 { YYCTLC($$,0,1,&$1);  }
 | 
#line 167 "apyc.hn"
 __13 __1 { YYCTLC($$,0,2,&$1,&$2);  }
;

 __14 : 
#line 230 "apyc.hn"
 __5 { YYCTLC($$,0,1,&$1);  }
 | 
#line 230 "apyc.hn"
 __14 __2 { YYCTLC($$,0,2,&$1,&$2);  }
;

 __15 : 
#line 173 "apyc.hn"
 __6 { YYCTLC($$,0,1,&$1);  }
 | 
#line 173 "apyc.hn"
 __15 __3 { YYCTLC($$,0,2,&$1,&$2);  }
;

 __16 : /* empty */  { YYCTLC($$,1,1,&$0);  }
 | 
#line 223 "apyc.hn"
 __16 ',' __7 { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); }
;

 __17 : /* empty */  { YYCTLC($$,2,2,&$-1,&$0);  }
 | 
#line 548 "apyc.hn"
 pair { YYCTLC($$,2,3,&$-1,&$0,&$1);  yyv_pair = $1; }
;

 __18 : /* empty */  { YYCTLC($$,2,2,&$-1,&$0);  }
 | 
#line 223 "apyc.hn"
 ',' { YYCTLC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); }
;

 __19 : /* empty */  { YYCTLC($$,2,2,&$-1,&$0);  }
 | 
#line 236 "apyc.hn"
 ';' { YYCTLC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); }
;

 __20 : /* empty */  { YYCTLC($$,3,3,&$-2,&$-1,&$0);  }
 | 
#line 435 "apyc.hn"
 expression { YYCTLC($$,3,4,&$-2,&$-1,&$0,&$1);  yyv_expression = $1; }
;

 __21 : /* empty */  { YYCTLC($$,3,3,&$-2,&$-1,&$0);  }
 | 
#line 526 "apyc.hn"
 ',' { YYCTLC($$,3,4,&$-2,&$-1,&$0,&$1);  $1.ignore(); }
;

 __22 : /* empty */  { YYCTLC($$,4,4,&$-3,&$-2,&$-1,&$0);  }
 | 
#line 524 "apyc.hn"
 expression { YYCTLC($$,4,5,&$-3,&$-2,&$-1,&$0,&$1);  yyv_expression = $1; }
;

 __23 : /* empty */  { YYCTLC($$,4,4,&$-3,&$-2,&$-1,&$0);  yyv_pair = $-1; }
 | 
#line 548 "apyc.hn"
 NEWLINE { YYCTLC($$,4,5,&$-3,&$-2,&$-1,&$0,&$1);  $1.ignore(); yyv_pair = $-1; yyv_NEWLINE = $1; }
;

 __24 : /* empty */  { YYCTLPC($$,1,1,&$0);  }
 | 
#line 548 "apyc.hn"
 __24 __0 { YYCTLC($$,1,3,&$0,&$1,&$2);  }
;

 __25 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_expression = $0; }
 | 
#line 419 "apyc.hn"
 __25 ',' expression { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_expression = $3; }
;

 __26 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_statement = $0; }
 | 
#line 236 "apyc.hn"
 __26 ';' statement { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_statement = $3; }
;

 __27 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_type = $0; }
 | 
#line 395 "apyc.hn"
 __27 ',' type { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_type = $3; }
;

 __28 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_type_var = $0; }
 | 
#line 197 "apyc.hn"
 __28 ',' type_var { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_type_var = $3; }
;

 __29 : /* empty */  { YYCTLPC($$,11,11,&$-10,&$-9,&$-8,&$-7,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0);  yyv_ID = $-9; yyv_formals = $-7; yyv_type = $-4; yyv_NEWLINE = $-2; yyv_INDENT = $-1; yyv_native_stmt = $0; }
 | 
#line 218 "apyc.hn"
 ';' { YYCTLPC($$,11,12,&$-10,&$-9,&$-8,&$-7,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0,&$1);  $1.ignore(); yyv_ID = $-9; yyv_formals = $-7; yyv_type = $-4; yyv_NEWLINE = $-2; yyv_INDENT = $-1; yyv_native_stmt = $0; }
;

 __30 : /* empty */  { YYCTLPC($$,2,2,&$-1,&$0);  yyv_expression = $-1; }
 | 
#line 435 "apyc.hn"
 __30 expression ',' { YYCTLC($$,2,5,&$-1,&$0,&$1,&$2,&$3);  $3.ignore(); yyv_expression = $2; }
;

 __31 : /* empty */  { YYCTLPC($$,2,2,&$-1,&$0);  yyv_expression = $0; }
 | 
#line 526 "apyc.hn"
 __31 ',' expression { YYCTLC($$,2,5,&$-1,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_expression = $3; }
;

 __32 : /* empty */  { YYCTLPC($$,2,2,&$-1,&$0);  yyv_target = $0; }
 | 
#line 349 "apyc.hn"
 ',' { YYCTLPC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); yyv_target = $0; }
;

 __33 : /* empty */  { YYCTLPC($$,3,3,&$-2,&$-1,&$0);  yyv_expression = $-1; }
 | 
#line 524 "apyc.hn"
 __33 expression ',' { YYCTLC($$,3,6,&$-2,&$-1,&$0,&$1,&$2,&$3);  $3.ignore(); yyv_expression = $2; }
;

 __34 : /* empty */  { YYCTLPC($$,7,7,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0);  yyv_ID = $-5; yyv_formals = $-3; yyv_native_stmt = $0; }
 | 
#line 212 "apyc.hn"
 ';' { YYCTLPC($$,7,8,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0,&$1);  $1.ignore(); yyv_ID = $-5; yyv_formals = $-3; yyv_native_stmt = $0; }
;

 __35 : /* empty */  { YYCTLPC($$,9,9,&$-8,&$-7,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0);  yyv_ID = $-7; yyv_formals = $-5; yyv_NEWLINE = $-2; yyv_INDENT = $-1; yyv_native_stmt = $0; }
 | 
#line 214 "apyc.hn"
 ';' { YYCTLPC($$,9,10,&$-8,&$-7,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0,&$1);  $1.ignore(); yyv_ID = $-7; yyv_formals = $-5; yyv_NEWLINE = $-2; yyv_INDENT = $-1; yyv_native_stmt = $0; }
;

 __36 : /* empty */  { YYCTLPC($$,9,9,&$-8,&$-7,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0);  yyv_ID = $-7; yyv_formals = $-5; yyv_type = $-2; yyv_native_stmt = $0; }
 | 
#line 216 "apyc.hn"
 ';' { YYCTLPC($$,9,10,&$-8,&$-7,&$-6,&$-5,&$-4,&$-3,&$-2,&$-1,&$0,&$1);  $1.ignore(); yyv_ID = $-7; yyv_formals = $-5; yyv_type = $-2; yyv_native_stmt = $0; }
;




#line 1499 "apyc-parser.y"

%%


#line 779 "apyc.hn"


bool debugParser;

static AST_Ptr
make_unop (const List_Ptr& operands)
{
    return YYMAKE_TREE (UNOP, make_id (operands->at (0)), operands->at (1));
}

static AST_Ptr
make_binop (const List_Ptr& operands)
{
    return YYMAKE_TREE (BINOP, operands->at (0), make_id (operands->at (1)),
                        operands->at (2));
}

static AST_Ptr
make_id (AST_Ptr& token)
{
    AST_Ptr result = AST::make_token (ID, token->text_size (),
                                      token->as_chars (), false);
    result->set_loc (token->loc ());
    return result;
}

static AST_Ptr
make_expr (const int KEY, const List_Ptr& operands)
{
    return YYMAKE_TREE (KEY, operands->at (0), make_id (operands->at (1)),
                        operands->at (2));
}


int
AST::lineNumber ()
{
    return yylocation_line (loc ());
}

void
parse (FILE* f, const string& name)
{
    if (debugParser)
        yydebug = 1;
    yypush_lexer (f, name);
    theTree = NULL;
    yyparse ();
    if (theTree != NULL) {
        theTree->print (cout, 0);
    }
}

static int
count_leading_whitespaces (const char* text, const int text_size)
{
  int spaces = 0;
  for (int i = 0; i < text_size; i++) {
    if (text[i] == ' ')
      spaces++;
    else // replacing tab with the appropriate number of spaces.
      spaces += 8 - (spaces % 8);
  }
  return spaces;
}


#line 1572 "apyc-parser.y"

const char* 
yyexternal_token_name (int syntax)
{
    int internal_num = YYTRANSLATE (syntax);
    return yytname[internal_num];
}

#include "apyc-lexer.cc"

YYNAMESPACE_CLOSE

template <class Type>
Type Simple_Value_Semantics<Type>::default_make_token (int syn,
						       size_t len,
						       const char* text)
{
    return YY_DEFAULT_MAKE_TOKEN(syn, len, text);
}
