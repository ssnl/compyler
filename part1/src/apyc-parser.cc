/* A Bison parser, made by GNU Bison 3.0.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0


/* "%code top" blocks.  */
#line 4 "apyc-parser.y" /* glr.c:189  */


#define YYPARAM Tree_Semantics< AST >
#define YYPRODUCING_TREES
#define YYERROR_FUNCTION_NAME error

# define YY_PARSER_1
# include "horn-parse-lex.cc"

#line 60 "apyc-parser.cc" /* glr.c:189  */




/* First part of user declarations.  */
#line 14 "apyc-parser.y" /* glr.c:207  */


    YYNAMESPACE_OPEN

#line 9 "apyc.hn" /* glr.c:207  */

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

#line 186 "apyc-parser.y" /* glr.c:207  */


#define YY_PARSER_2
#include "horn-parse-lex.cc"

#line 254 "apyc-parser.y" /* glr.c:207  */

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


#line 194 "apyc-parser.cc" /* glr.c:207  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "apyc-parser.hh"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */

#line 222 "apyc-parser.cc" /* glr.c:230  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify clang.  */
# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  87
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  246
/* YYNRULES -- Number of states.  */
#define YYNSTATES  396
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 14
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 11

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      59,    60,    54,    51,    61,    52,    63,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    67,
      49,    69,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,     2,    95,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    56,    57,    58,    62,    64,    66,
      68,    70,    71,    72,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    96,    97,    98,    99,   100,   101,   102,
     103,   104
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   163,   163,   167,   169,   173,   175,   180,   186,   188,
     190,   192,   197,   204,   206,   208,   210,   212,   214,   216,
     218,   223,   226,   230,   232,   236,   241,   242,   243,   244,
     245,   247,   249,   254,   255,   256,   260,   265,   267,   269,
     274,   276,   278,   283,   285,   287,   289,   293,   296,   298,
     300,   302,   307,   309,   314,   319,   321,   323,   325,   327,
     332,   337,   338,   340,   341,   343,   344,   348,   349,   351,
     356,   363,   368,   369,   370,   372,   377,   379,   384,   385,
     390,   395,   400,   407,   408,   412,   413,   419,   424,   425,
     429,   434,   435,   440,   441,   445,   449,   451,   453,   455,
     460,   461,   464,   470,   471,   472,   472,   479,   479,   479,
     479,   479,   479,   479,   479,   481,   483,   488,   489,   489,
     489,   489,   489,   489,   489,   489,   491,   493,   498,   499,
     499,   499,   499,   499,   499,   504,   505,   505,   505,   510,
     511,   516,   517,   518,   519,   520,   522,   524,   526,   528,
     529,   533,   534,   536,   538,   542,   548,   553,   554,   555,
     555,   548,   548,   167,   167,   167,   167,   167,   230,   230,
     230,   230,   173,   173,   173,   167,   167,   167,   167,   167,
     230,   230,   230,   230,   173,   173,   173,   223,   223,   223,
     223,   341,   341,   351,   351,   167,   167,   167,   167,   167,
     167,   230,   230,   173,   173,   176,   223,   226,   548,   551,
     223,   226,   236,   239,   435,   438,   526,   529,   524,   527,
     548,   551,   548,   551,   419,   422,   236,   239,   395,   398,
     197,   200,   218,   221,   435,   438,   526,   529,   349,   352,
     524,   527,   212,   215,   214,   217,   216
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "\"@println\"", "EMPTY",
  "\"@expr_list\"", "\"@module\"", "\"@binop\"", "\"@unop\"", "INDENT",
  "DEDENT", "\"@stmt_list\"", "\"@print\"", "\"@return\"", "\"@break\"",
  "\"@continue\"", "\"@native\"", "\"@if\"", "\"@for\"", "\"@while\"",
  "\"@block\"", "\"@assign\"", "\"@target_list\"", "\"@attributeref\"",
  "\"@subscription\"", "\"@slicing\"", "\"@type\"", "\"@typed_id\"",
  "\"@type_var\"", "\"@type_list\"", "\"@type_formals_list\"",
  "\"@formals_list\"", "\"@function_type\"", "\"@def\"", "\"@class\"",
  "\"@compare\"", "\"@left_compare\"", "\"@and\"", "\"@or\"",
  "\"@if_expr\"", "\"@tuple\"", "\"@list_display\"", "\"@dict_display\"",
  "\"@pair\"", "\"@call\"", "\"**\"", "ISNOT", "NOTIN", "\"<\"", "\">\"",
  "\"+\"", "\"-\"", "\"%\"", "\"*\"", "\"/\"", "\"&&\"", "\"||\"",
  "\"!=\"", "\"(\"", "\")\"", "\",\"", "\"->\"", "\".\"", "\"//\"",
  "\":\"", "\"::\"", "\";\"", "\"<=\"", "\"=\"", "\"==\"", "\">=\"",
  "\">>\"", "\"[\"", "\"]\"", "\"and\"", "\"break\"", "\"class\"",
  "\"continue\"", "\"def\"", "\"elif\"", "\"else\"", "\"for\"", "\"if\"",
  "\"in\"", "\"is\"", "\"native\"", "\"not\"", "\"of\"", "\"or\"",
  "\"pass\"", "\"print\"", "\"return\"", "\"while\"", "\"{\"", "\"}\"",
  "BADSTRING", "BLANK_LINE", "END_OF_FILE", "INDENTATION", "INT_LITERAL",
  "NEWLINE", "RAWSTRING", "STRING", "UNUSED_KEYWORD", "$accept", "program",
  "stmt_list", "stmt_list0", "statement", "classdef", "type_formals",
  "definition", "formals", "block", "semi_block", "basic_statement",
  "control_structure", "semi_stmt_list", "for_loop", "while_loop",
  "if_stmt", "elif_stmts", "else_stmt", "native_stmt", "print_stmt",
  "assign", "target_list", "target_list_br", "tlist", "typed_id", "type",
  "type_id0", "type_id", "type_var", "type_list0", "type_list1", "target",
  "right_side", "plist", "expression_list0", "expression_list",
  "tuple_ext_expr", "expression0", "expression", "function_call",
  "root_expr", "if_expr", "boolean_expr", "compare_expr", "lcompare_expr",
  "arith_expr", "unary_expr", "expo_expr", "primary_expr", "simple_target",
  "pair", "dict", "str_expr", "__0", "__1", "__2", "__3", "__4", "__5",
  "__6", "__7", "__8", "__9", "__10", "__11", "__12", "__13", "__14",
  "__15", "__16", "__17", "__18", "__19", "__20", "__21", "__22", "__23",
  "__24", "__25", "__26", "__27", "__28", "__29", "__30", "__31", "__32",
  "__33", "__34", "__35", "__36", YY_NULL
};
#endif

#define YYPACT_NINF -308
#define YYTABLE_NINF -194

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
     310,   -37,   273,   273,    71,   862,  -308,    42,  -308,    74,
     107,   273,   273,  -308,   872,   273,   273,  -308,  -308,  -308,
    -308,  -308,    80,  -308,   -35,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,  -308,   -27,  -308,  -308,  -308,    53,    60,
    -308,  -308,  -308,  -308,    26,  -308,  1259,   984,  -308,    82,
     -19,    45,  -308,     1,  -308,   347,    40,    23,    36,    75,
     917,  -308,  -308,  -308,  -308,   103,    85,   108,  -308,    93,
     115,  -308,   -16,   123,   100,   -19,   120,  -308,   273,  -308,
    -308,  -308,  -308,  -308,  -308,   121,   273,  -308,  -308,  -308,
    -308,   927,   273,   169,   126,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   360,   273,   185,   273,  -308,  -308,
    -308,   -33,  -308,  -308,  -308,  -308,    36,  -308,    38,  -308,
    -308,  -308,  -308,    40,  -308,  -308,  -308,  -308,  -308,  -308,
     169,   126,    18,   116,   130,   634,   122,   190,   273,   654,
     133,   136,   691,   138,   -30,  -308,   109,  -308,  -308,  -308,
     137,    56,  -308,  -308,   169,  -308,   125,   140,  1009,  1034,
    1059,  1084,  1109,  1134,  1159,  1184,  1209,  1234,   106,   106,
    -308,  -308,  -308,  -308,    82,    78,  -308,   134,   148,   -26,
    -308,  -308,  -308,   149,  -308,   156,   143,   273,    39,   169,
    -308,  -308,   273,   144,   211,  -308,   128,   193,   158,   167,
    -308,  -308,   165,   221,  -308,   131,   273,   273,   223,   145,
     273,   147,   173,  -308,  -308,  -308,   175,   176,  -308,   273,
    -308,   184,  -308,   273,    40,   186,   187,  -308,   194,   196,
    -308,  -308,  -308,   429,   191,  -308,   188,  -308,    77,   199,
     711,   503,   191,    73,  -308,  -308,  -308,   503,  -308,  -308,
    -308,  -308,  -308,   273,  -308,   273,  -308,  -308,   200,  -308,
      40,    40,  -308,  -308,  -308,   -35,  -308,   250,  -308,  -308,
     466,   825,  -308,   202,   203,   577,    40,   262,  -308,   260,
     172,  -308,   264,   -35,  -308,  -308,   540,  -308,   273,   212,
    -308,  -308,   267,   218,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,   -33,  -308,  -308,  -308,  -308,   748,   193,   181,   278,
     189,   224,   227,   158,  -308,  -308,   503,  -308,    73,  -308,
    -308,   -33,  -308,  -308,   228,   768,   213,  -308,  -308,   285,
     198,  -308,  -308,   392,  -308,  -308,   201,   597,   286,  -308,
    -308,   805,   290,   205,  -308,   429,  -308,   292,   237,  -308,
     297,   207,   242,   213,   300,   210,   503,  -308,   301,  -308,
    -308,   214,   392,  -308,  -308,   216,  -308,   503,    73,   303,
    -308,   308,   309,   254,  -308,   311,  -308,  -308,  -308,  -308,
    -308,   222,    73,   316,  -308,  -308
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const unsigned char yydefact[] =
{
       4,   151,     0,     0,     0,     0,    31,     0,    32,     0,
       0,     0,     0,    29,    89,    94,     0,   221,   141,   179,
     158,   157,     0,     2,     0,   178,   177,     7,   176,    33,
      34,    35,    26,    27,     0,    66,    63,    84,     0,    61,
      28,   150,    95,   100,   101,   104,     0,   103,   128,   135,
     139,   142,   144,   143,   199,     3,     0,     0,   151,     0,
       0,   136,   142,   137,   145,     0,     0,    95,   146,     0,
     237,   235,     0,     0,     0,     0,     0,   138,     0,    59,
      58,    88,   223,    30,    93,     0,   207,     1,   198,   197,
     175,     0,    89,    62,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,    94,   159,   160,
     167,     0,   166,   165,   164,   200,    79,    80,     0,    71,
      78,    72,    73,     0,    82,    77,    65,   239,   149,    67,
     238,     0,     0,     0,   215,     0,     0,    22,     0,     0,
      55,    90,     0,     0,   208,   222,     0,    86,    60,    85,
      91,     0,   223,   191,    70,   105,     0,   106,   115,   116,
     107,   108,   112,   109,   111,   110,   113,   114,   129,   130,
     134,   131,   132,   133,   140,     0,   152,     0,     0,    91,
     196,   195,   163,     0,   227,     0,     0,   217,   191,     0,
      69,    68,   216,     0,     0,   225,     0,     0,   190,     0,
     189,   205,     0,     0,   225,     0,     0,    87,     0,     0,
       0,   219,     0,   156,   233,    96,     0,    90,   192,     0,
      98,     0,   153,    94,     0,    81,     0,    76,   218,     0,
     194,   236,   148,    24,   211,    11,     0,   229,     0,   209,
       0,     6,   211,    43,    57,    56,   224,     6,    40,   155,
     220,   162,   161,   213,    97,     0,   102,    99,     0,    75,
       0,     0,   240,   147,   183,     0,   182,     0,   181,   201,
      23,   212,    25,     0,    12,     0,     0,   210,    21,     0,
       0,   186,     0,     0,   185,   203,     5,    36,     0,     0,
      44,    47,     0,   214,    92,   154,   228,    74,   180,     9,
     171,     0,   170,   169,   202,   226,     0,     0,     0,     0,
       0,   241,     0,   188,   187,   206,     6,    37,    45,   184,
     174,     0,   173,   204,     0,     0,    41,   234,   168,     0,
       0,   230,    54,    24,    16,   242,     0,     0,     0,    46,
     172,     0,     0,     0,    42,    24,    10,     0,   243,    17,
       0,     0,   245,    38,     0,     0,     6,    52,     0,    14,
     244,     0,    24,    15,   246,     0,    39,     6,    48,     0,
       8,     0,     0,   231,    19,     0,    49,    53,    18,    13,
     232,     0,    51,     0,    50,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -308,  -308,  -308,  -241,     2,   274,  -308,     6,  -308,  -307,
    -257,  -308,     9,  -139,  -308,  -308,  -308,  -305,  -303,  -297,
    -308,   239,   146,  -308,   326,  -146,   -32,   -45,  -308,  -185,
     204,  -308,    15,  -308,   117,   -62,   118,   -90,   -96,     3,
    -308,    11,  -308,    86,  -308,  -308,  1247,    35,   225,    -7,
       0,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,   266,  -308,  -255,  -191,  -308,  -308,  -308,
    -308,  -308,  -308,    88,  -308,  -308,  -308,  -308,  -308,   179,
     124,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,
    -308
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,    22,    23,   292,   214,    25,   246,   276,   209,   277,
     206,    27,   294,   215,    29,    30,    31,   300,   301,   321,
      32,    33,    34,    35,    36,    37,   194,    38,   131,   132,
     195,   135,    39,   158,    79,    80,    81,   159,    83,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      62,   154,    52,    53,   155,   125,   314,   333,    54,   279,
     295,   325,   211,    94,   142,   192,    90,    55,   280,   296,
     249,   156,   288,   282,   304,   203,   239,   261,    86,   151,
     244,   235,   284,   391,   263,   144,   143,   197,   346,   371,
     375
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const short int yytable[] =
{
      51,   210,    24,    75,    51,    51,    26,    66,    71,    28,
      51,   130,   130,   219,    76,    67,   302,    82,    84,    85,
      70,   188,   247,   349,   129,   134,   126,   187,   320,    56,
     161,   221,    88,   354,   190,   224,   357,    61,    63,   -93,
     115,   126,    91,   126,   116,    72,   358,    77,   368,   145,
     362,    57,   127,   185,   117,    51,   338,   121,   212,   340,
     376,   123,    66,    71,   124,   382,    89,   127,   191,   127,
      67,   222,   146,   386,     1,   383,   350,    73,    58,   199,
      87,   150,   128,   130,   308,   348,    75,   394,   130,   153,
     361,    51,   200,    51,   160,   162,   133,   128,   193,   128,
    -191,    95,   329,   118,   119,   -83,   -83,   166,   163,    96,
       1,   290,    92,  -193,   -83,    97,   225,   226,   162,   -83,
     189,    93,     2,     3,    57,   379,     2,     3,   114,   -83,
       4,    64,   341,    75,    59,    64,   385,   268,   230,   231,
      51,   324,   285,   286,     5,    51,   137,   205,    60,    51,
      65,   160,    51,   298,   299,   198,    74,    75,    12,   110,
     111,   112,    12,   136,    51,    17,     4,   139,   138,    17,
     113,    18,     1,    20,    21,    18,   140,    20,    21,   228,
       5,   165,   147,   167,   148,   149,   152,   164,   186,   130,
     201,   202,    75,   208,   216,   207,   353,   217,   224,    51,
     238,    17,   269,   220,   223,   241,   229,    18,   232,    20,
      21,   234,   365,   233,   240,    95,   236,   237,   242,    82,
     256,   243,   127,   259,    56,   130,   130,   248,    59,   245,
     250,   251,   253,   257,   262,   264,    84,   265,   306,   307,
     266,   130,    60,    51,   267,   275,   258,   270,   260,   271,
      51,    51,   278,   293,   322,   272,   273,    51,   281,   293,
     287,   309,   283,    17,   317,   323,   303,   316,   256,    18,
     326,    20,    21,   327,   305,   328,    58,   335,   336,   337,
      51,    51,   311,   315,   342,    51,   312,   205,   343,   313,
     344,   345,   347,   351,   299,   355,    51,   363,   331,   356,
     366,   334,   359,   369,   370,   332,   367,   372,   373,   374,
     377,   378,   380,     1,   387,   381,    51,   384,   205,   388,
     389,   390,   392,   393,     2,     3,    51,   395,   293,   122,
     157,    69,    59,   254,   255,    51,   141,   196,   252,   184,
     297,   227,     0,    51,     0,   275,    60,    51,     0,   205,
       1,    51,   278,     0,     0,    51,     0,   275,     0,     0,
      12,     2,     3,    58,   278,     0,    51,    17,   293,     4,
       0,     0,    51,    18,   275,    20,    21,    51,     0,   293,
       0,   278,     0,     5,     0,     0,     6,     7,     8,     9,
       0,     0,    10,    11,     0,     1,     0,    12,     2,     3,
      13,    14,    15,    16,    17,     0,     4,     0,     0,     0,
      18,    19,    20,    21,     0,     0,     0,     0,     0,    59,
       5,     0,     0,     6,     7,     8,     9,     0,     0,    10,
      11,     0,     1,    60,    12,     0,     0,    13,    14,    15,
      16,    17,     0,     2,     3,     0,     0,    18,   120,    20,
      21,     4,     0,     0,    17,     0,     0,     0,     0,     0,
      18,     0,    20,    21,     0,     5,     0,     0,     6,     1,
       8,     9,     0,     0,    10,    11,     0,     0,   318,    12,
       2,     3,    13,    14,    15,    16,    17,     0,     4,     0,
       0,     0,    18,   274,    20,    21,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     6,     1,     8,     9,     0,
       0,    10,    11,     0,     0,     0,    12,     2,     3,    13,
      14,    15,    16,    17,     0,     4,     0,     0,     0,    18,
     274,    20,    21,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     6,     1,     8,     9,     0,     0,    10,    11,
       0,     0,     0,    12,     2,     3,    13,    14,    15,    16,
      17,     0,     4,     0,     0,     0,    18,   310,    20,    21,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     6,
       1,     8,     0,     0,     0,    10,    11,     0,     0,     0,
      12,     2,     3,    13,    14,    15,    16,    17,     0,     4,
       1,     0,     0,    18,   291,    20,    21,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     6,     0,     8,     0,
       0,     0,    10,    11,     0,     0,     0,    12,     2,     3,
      13,    14,    15,    16,    17,     0,     4,     1,     0,     0,
      18,   330,    20,    21,     0,     0,     0,     0,     2,     3,
       5,     0,     0,     6,     0,     8,     4,     1,     0,     0,
       0,     0,     0,   318,    12,     0,     0,    13,    14,    15,
       5,    17,     0,     6,     0,     8,     0,    18,   319,    20,
      21,     0,     0,   318,    12,     2,     3,    13,    14,    15,
       0,    17,     0,     4,     1,     0,     0,    18,   360,    20,
      21,     0,     0,     0,     0,     2,     3,     5,     0,     0,
       6,     0,     8,     4,     1,     0,     0,     0,     0,     0,
       0,    12,     0,     0,    13,    14,    15,     5,    17,     0,
       6,     0,     8,     0,    18,   204,    20,    21,     0,     0,
       0,    12,     2,     3,    13,    14,    15,     0,    17,     0,
       4,     1,     0,     0,    18,   213,    20,    21,     0,     0,
       0,     0,     2,     3,     5,     0,     0,     6,     0,     8,
       4,     1,     0,     0,     0,     0,     0,     0,    12,     0,
       0,    13,    14,    15,     5,    17,     0,     6,     0,     8,
       0,    18,   218,    20,    21,     0,     0,     0,    12,     2,
       3,    13,    14,    15,     0,    17,     0,     4,     1,     0,
       0,    18,   289,    20,    21,     0,     0,     0,     0,     2,
       3,     5,     0,     0,     6,     0,     8,     4,     1,     0,
       0,     0,     0,     0,     0,    12,     0,     0,    13,    14,
      15,     5,    17,     0,     6,     0,     8,     0,    18,   339,
      20,    21,     0,     0,     0,    12,     2,     3,    13,    14,
      15,     0,    17,     0,     4,     1,     0,     0,    18,   352,
      20,    21,     0,     0,     0,    58,     2,     3,     5,     0,
       0,     6,     0,     8,     4,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,    13,    14,    15,     5,    17,
       0,     6,     0,     8,     0,    18,   364,    20,    21,     0,
       0,     0,    12,     2,     3,    13,    14,    15,     0,    17,
      58,    59,     0,     2,     3,    18,     0,    20,    21,     0,
       1,    59,     0,     0,     0,    60,    68,     0,     0,     0,
       0,     0,     0,     0,    78,    60,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,    17,     0,     0,    12,
       0,     0,    18,     0,    20,    21,    17,     0,     2,     3,
       0,     0,    18,     0,    20,    21,    59,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
      60,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,    17,     0,     0,    12,     0,     0,    18,     0,    20,
      21,    17,     0,     0,     0,     0,     0,    18,     0,    20,
      21,  -117,  -117,  -117,  -117,   108,   109,   110,   111,   112,
       0,     0,  -117,     0,     0,     0,     0,     0,   113,     0,
       0,     0,  -117,     0,  -117,  -117,  -126,  -126,  -126,  -126,
     108,   109,   110,   111,   112,     0,     0,  -126,  -117,  -117,
       0,     0,     0,   113,     0,     0,     0,  -126,     0,  -126,
    -126,  -127,  -127,  -127,  -127,   108,   109,   110,   111,   112,
       0,     0,  -127,  -126,  -126,     0,     0,     0,   113,     0,
       0,     0,  -127,     0,  -127,  -127,  -118,  -118,  -118,  -118,
     108,   109,   110,   111,   112,     0,     0,  -118,  -127,  -127,
       0,     0,     0,   113,     0,     0,     0,  -118,     0,  -118,
    -118,  -119,  -119,  -119,  -119,   108,   109,   110,   111,   112,
       0,     0,  -119,  -118,  -118,     0,     0,     0,   113,     0,
       0,     0,  -119,     0,  -119,  -119,  -123,  -123,  -123,  -123,
     108,   109,   110,   111,   112,     0,     0,  -123,  -119,  -119,
       0,     0,     0,   113,     0,     0,     0,  -123,     0,  -123,
    -123,  -120,  -120,  -120,  -120,   108,   109,   110,   111,   112,
       0,     0,  -120,  -123,  -123,     0,     0,     0,   113,     0,
       0,     0,  -120,     0,  -120,  -120,  -122,  -122,  -122,  -122,
     108,   109,   110,   111,   112,     0,     0,  -122,  -120,  -120,
       0,     0,     0,   113,     0,     0,     0,  -122,     0,  -122,
    -122,  -121,  -121,  -121,  -121,   108,   109,   110,   111,   112,
       0,     0,  -121,  -122,  -122,     0,     0,     0,   113,     0,
       0,     0,  -121,     0,  -121,  -121,  -124,  -124,  -124,  -124,
     108,   109,   110,   111,   112,     0,     0,  -124,  -121,  -121,
       0,     0,     0,   113,     0,     0,     0,  -124,     0,  -124,
    -124,  -125,  -125,  -125,  -125,   108,   109,   110,   111,   112,
       0,     0,  -125,  -124,  -124,     0,     0,     0,   113,     0,
       0,     0,  -125,     0,  -125,  -125,    98,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,   102,  -125,  -125,
       0,     0,     0,     0,     0,     0,     0,   103,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183
};

static const short int yycheck[] =
{
       0,   147,     0,    10,     4,     5,     0,     4,     5,     0,
      10,    56,    57,   152,    11,     4,   257,    14,    15,    16,
       5,   117,   207,   328,    56,    57,     3,   117,   285,    66,
      92,    61,    67,   336,    67,    61,   343,     2,     3,    65,
      59,     3,    69,     3,    63,     3,   343,    12,   355,    65,
     347,    88,    29,   115,    73,    55,   311,    55,   148,   316,
     363,    55,    59,    60,    55,   372,   101,    29,   101,    29,
      59,   101,    88,   378,     3,   372,   331,     3,     3,    61,
       0,    78,    59,   128,   275,   326,    93,   392,   133,    86,
     347,    91,    74,    93,    91,    92,    73,    59,    60,    59,
      61,    75,   293,   102,   103,    60,    61,    96,    93,    83,
       3,   250,    59,    74,    69,    89,    60,    61,   115,    74,
     117,    61,    51,    52,    88,   366,    51,    52,    46,    84,
      59,    60,   317,   140,    59,    60,   377,   233,    60,    61,
     140,   287,    65,    66,    73,   145,    61,   145,    73,   149,
       4,   148,   152,    80,    81,   140,    10,   164,    87,    53,
      54,    55,    87,    60,   164,    94,    59,    74,    60,    94,
      64,   100,     3,   102,   103,   100,    61,   102,   103,   164,
      73,    95,    59,    97,    84,    65,    65,    61,     3,   234,
      74,    61,   199,     3,    61,    73,   335,    61,    61,   199,
     197,    94,   234,    65,    95,   202,    81,   100,    74,   102,
     103,    62,   351,    65,   199,    75,    60,    74,    74,   216,
     217,    10,    29,   220,    66,   270,   271,    60,    59,   101,
      65,    10,   101,    10,    61,    60,   233,    61,   270,   271,
     229,   286,    73,   243,    60,   243,   101,    61,   101,    62,
     250,   251,   243,   251,   286,    61,    60,   257,    67,   257,
      61,    11,    74,    94,    61,     3,   263,    65,   265,   100,
      10,   102,   103,   101,    74,    11,     3,    65,    11,    61,
     280,   281,   280,   281,   103,   285,   280,   285,    10,   280,
     101,    67,    65,    65,    81,    10,   296,    11,   296,   101,
      10,   298,   101,    11,    67,   296,   101,    10,   101,    67,
      10,   101,    11,     3,    11,   101,   316,   101,   316,    11,
      11,    67,    11,   101,    51,    52,   326,    11,   326,    55,
      91,     5,    59,   216,   216,   335,    70,   133,   214,   114,
     252,   162,    -1,   343,    -1,   343,    73,   347,    -1,   347,
       3,   351,   343,    -1,    -1,   355,    -1,   355,    -1,    -1,
      87,    51,    52,     3,   355,    -1,   366,    94,   366,    59,
      -1,    -1,   372,   100,   372,   102,   103,   377,    -1,   377,
      -1,   372,    -1,    73,    -1,    -1,    76,    77,    78,    79,
      -1,    -1,    82,    83,    -1,     3,    -1,    87,    51,    52,
      90,    91,    92,    93,    94,    -1,    59,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    59,
      73,    -1,    -1,    76,    77,    78,    79,    -1,    -1,    82,
      83,    -1,     3,    73,    87,    -1,    -1,    90,    91,    92,
      93,    94,    -1,    51,    52,    -1,    -1,   100,   101,   102,
     103,    59,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,
     100,    -1,   102,   103,    -1,    73,    -1,    -1,    76,     3,
      78,    79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,
      51,    52,    90,    91,    92,    93,    94,    -1,    59,    -1,
      -1,    -1,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    76,     3,    78,    79,    -1,
      -1,    82,    83,    -1,    -1,    -1,    87,    51,    52,    90,
      91,    92,    93,    94,    -1,    59,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    76,     3,    78,    79,    -1,    -1,    82,    83,
      -1,    -1,    -1,    87,    51,    52,    90,    91,    92,    93,
      94,    -1,    59,    -1,    -1,    -1,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,
       3,    78,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
      87,    51,    52,    90,    91,    92,    93,    94,    -1,    59,
       3,    -1,    -1,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    78,    -1,
      -1,    -1,    82,    83,    -1,    -1,    -1,    87,    51,    52,
      90,    91,    92,    93,    94,    -1,    59,     3,    -1,    -1,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    51,    52,
      73,    -1,    -1,    76,    -1,    78,    59,     3,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    90,    91,    92,
      73,    94,    -1,    76,    -1,    78,    -1,   100,   101,   102,
     103,    -1,    -1,    86,    87,    51,    52,    90,    91,    92,
      -1,    94,    -1,    59,     3,    -1,    -1,   100,   101,   102,
     103,    -1,    -1,    -1,    -1,    51,    52,    73,    -1,    -1,
      76,    -1,    78,    59,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    90,    91,    92,    73,    94,    -1,
      76,    -1,    78,    -1,   100,   101,   102,   103,    -1,    -1,
      -1,    87,    51,    52,    90,    91,    92,    -1,    94,    -1,
      59,     3,    -1,    -1,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    51,    52,    73,    -1,    -1,    76,    -1,    78,
      59,     3,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    90,    91,    92,    73,    94,    -1,    76,    -1,    78,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,    87,    51,
      52,    90,    91,    92,    -1,    94,    -1,    59,     3,    -1,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,    -1,    51,
      52,    73,    -1,    -1,    76,    -1,    78,    59,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,
      92,    73,    94,    -1,    76,    -1,    78,    -1,   100,   101,
     102,   103,    -1,    -1,    -1,    87,    51,    52,    90,    91,
      92,    -1,    94,    -1,    59,     3,    -1,    -1,   100,   101,
     102,   103,    -1,    -1,    -1,     3,    51,    52,    73,    -1,
      -1,    76,    -1,    78,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    90,    91,    92,    73,    94,
      -1,    76,    -1,    78,    -1,   100,   101,   102,   103,    -1,
      -1,    -1,    87,    51,    52,    90,    91,    92,    -1,    94,
       3,    59,    -1,    51,    52,   100,    -1,   102,   103,    -1,
       3,    59,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    87,
      -1,    -1,   100,    -1,   102,   103,    94,    -1,    51,    52,
      -1,    -1,   100,    -1,   102,   103,    59,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    87,    -1,    -1,   100,    -1,   102,
     103,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    71,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    84,    85,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      71,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    84,    85,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    71,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    84,    85,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      71,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    84,    85,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    71,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    84,    85,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      71,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    84,    85,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    71,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    84,    85,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      71,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    84,    85,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    71,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    84,    85,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      71,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    84,    85,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    71,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    51,    52,    59,    73,    76,    77,    78,    79,
      82,    83,    87,    90,    91,    92,    93,    94,   100,   101,
     102,   103,   106,   107,   109,   110,   112,   116,   117,   119,
     120,   121,   125,   126,   127,   128,   129,   130,   132,   137,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   157,   158,   163,   172,    66,    88,     3,    59,
      73,   152,   155,   152,    60,   127,   144,   146,    74,   129,
     137,   144,     3,     3,   127,   154,   144,   152,    72,   139,
     140,   141,   144,   143,   144,   144,   183,     0,    67,   101,
     171,    69,    59,    61,   168,    75,    83,    89,    47,    48,
      49,    50,    58,    68,    70,    71,    84,    85,    51,    52,
      53,    54,    55,    64,    46,    59,    63,    73,   102,   103,
     101,   109,   110,   112,   117,   160,     3,    29,    59,   131,
     132,   133,   134,    73,   131,   136,    60,    61,    60,    74,
      61,   168,   169,   191,   190,    65,    88,    59,    84,    65,
     144,   184,    65,   144,   156,   159,   176,   126,   138,   142,
     144,   140,   144,   137,    61,   148,   146,   148,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   153,   140,     3,   142,   143,   144,
      67,   101,   170,    60,   131,   135,   135,   192,   137,    61,
      74,    74,    61,   180,   101,   109,   115,    73,     3,   113,
     130,   167,   142,   101,   109,   118,    61,    61,   101,   118,
      65,    61,   101,    95,    61,    60,    61,   184,   137,    81,
      60,    61,    74,    65,    62,   186,    60,    74,   144,   181,
     137,   144,    74,    10,   185,   101,   111,   134,    60,   175,
      65,    10,   185,   101,   139,   141,   144,    10,   101,   144,
     101,   182,    61,   189,    60,    61,   146,    60,   143,   131,
      61,    62,    61,    60,   101,   109,   112,   114,   117,   164,
     173,    67,   178,    74,   187,    65,    66,    61,   177,   101,
     118,   101,   108,   109,   117,   165,   174,   178,    80,    81,
     122,   123,   108,   144,   179,    74,   131,   131,   171,    11,
     101,   109,   112,   117,   161,   109,    65,    61,    86,   101,
     115,   124,   131,     3,   130,   166,    10,   101,    11,   171,
     101,   109,   117,   162,   144,    65,    11,    61,   170,   101,
     115,   134,   103,    10,   101,    67,   193,    65,   108,   122,
     170,    65,   101,   118,   123,    10,   101,   114,   124,   101,
     101,   115,   124,    11,   101,   118,    10,   101,   114,    11,
      67,   194,    10,   101,    67,   195,   123,    10,   101,   108,
      11,   101,   114,   124,   101,   108,   122,    11,    11,    11,
      67,   188,    11,   101,   122,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   105,   106,   107,   107,   108,   108,   109,   110,   110,
     110,   110,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   115,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   118,   119,   119,   119,
     120,   120,   120,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   123,   123,   124,   125,   125,   125,   125,   125,
     126,   127,   127,   127,   127,   127,   127,   128,   128,   128,
     129,   130,   131,   131,   131,   131,   132,   132,   133,   133,
     134,   135,   136,   137,   137,   138,   138,   139,   140,   140,
     141,   142,   142,   143,   143,   144,   145,   145,   145,   145,
     146,   146,   147,   148,   148,   148,   148,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   152,   152,   152,   152,   153,
     153,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   155,   155,   155,   155,   156,   157,   158,   158,   158,
     158,   159,   159,   160,   160,   160,   160,   160,   161,   161,
     161,   161,   162,   162,   162,   163,   163,   163,   163,   163,
     164,   164,   164,   164,   165,   165,   165,   166,   166,   167,
     167,   168,   168,   169,   169,   170,   170,   171,   171,   172,
     172,   173,   173,   174,   174,   175,   175,   176,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182,   183,   183,   184,   184,   185,   185,   186,   186,   187,
     187,   188,   188,   189,   189,   190,   190,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     0,     1,     0,     1,    11,     7,
       9,     5,     2,    12,    10,    10,     8,     9,    12,    11,
      14,     3,     0,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     7,     9,    10,
       5,     7,     8,     5,     6,     7,     8,     1,     5,     6,
       8,     7,     4,     6,     2,     3,     5,     5,     2,     2,
       3,     1,     2,     1,     2,     3,     1,     3,     4,     4,
       3,     3,     1,     1,     5,     4,     5,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     1,     4,     1,     0,     1,     4,     5,     4,     5,
       1,     1,     5,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     2,     1,
       3,     1,     1,     1,     1,     2,     2,     6,     5,     3,
       1,     1,     3,     4,     6,     3,     4,     1,     1,     2,
       2,     3,     3,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     1,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     2,     0,     3,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     2,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     1,     0,     3,     0,     3,     0,     1,     0,
       3,     0,     1,     0,     1,     0,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     1,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   142,     0,   142,     0,   142,     0,   142,     0,   193,
       0,    90,     0
};

/* Error token number */
#define YYTERROR 1



YYSTYPE yylval;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YYDPRINTF(Args)                        \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
  } while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YYFPRINTF (stderr, "%s ", Title);                               \
        yy_symbol_print (stderr, Type, Value);        \
        YYFPRINTF (stderr, "\n");                                       \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (struct yyGLRStack* yystackp)
  __attribute__ ((__unused__));

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static void yyFail (yyGLRStack* yystackp, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULL)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystackp)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULL;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     __attribute__ ((__unused__));
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp)
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == YY_NULL);
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
        case 2:
#line 163 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);theTree = YYMAKE_TREE(MODULE, yylhs.all_values ()); yylhs = NULL; }
#line 1625 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 3:
#line 168 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); }
#line 1631 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 4:
#line 169 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(STMT_LIST); }
#line 1637 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 5:
#line 174 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); }
#line 1643 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 6:
#line 175 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(STMT_LIST); }
#line 1649 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 7:
#line 180 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_basic_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1655 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 8:
#line 187 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,11,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval); yyv_type_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CLASS,yyv_ID,yyv_type_formals,yyv_block); }
#line 1661 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 9:
#line 189 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CLASS,yyv_ID,YYMAKE_TREE(TYPE_FORMALS_LIST),yyv_block); }
#line 1667 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 10:
#line 191 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval); yyv_type_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_semi_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CLASS,yyv_ID,yyv_type_formals,yyv_semi_block); }
#line 1673 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 11:
#line 193 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_semi_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CLASS,yyv_ID,YYMAKE_TREE(TYPE_FORMALS_LIST),yyv_semi_block); }
#line 1679 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 12:
#line 198 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_FORMALS_LIST,yylhs.all_values ()); }
#line 1685 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 13:
#line 205 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,12,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,yyv_type,yyv_block); }
#line 1691 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 14:
#line 207 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,10,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,YYMAKE_TREE(EMPTY),yyv_block); }
#line 1697 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 15:
#line 209 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,10,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_semi_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,yyv_type,yyv_semi_block); }
#line 1703 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 16:
#line 211 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,8,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_semi_block = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION,yyv_ID,yyv_formals,YYMAKE_TREE(EMPTY),yyv_semi_block); }
#line 1709 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 17:
#line 213 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, YYMAKE_TREE(EMPTY), YYMAKE_TREE(BLOCK, yyv_native_stmt)); }
#line 1715 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 18:
#line 215 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,12,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, YYMAKE_TREE(EMPTY), YYMAKE_TREE(BLOCK, yyv_native_stmt)); }
#line 1721 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 19:
#line 217 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,11,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, yyv_type, YYMAKE_TREE(BLOCK, yyv_native_stmt)); }
#line 1727 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 20:
#line 219 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,14,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-13)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-12)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-13)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(DEFINITION, yyv_ID, yyv_formals, yyv_type, YYMAKE_TREE(BLOCK, yyv_native_stmt)); }
#line 1733 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 21:
#line 224 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(FORMALS_LIST,yylhs.all_values ()); }
#line 1739 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 22:
#line 226 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(FORMALS_LIST); }
#line 1745 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 23:
#line 231 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 1751 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 24:
#line 232 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(BLOCK); }
#line 1757 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 25:
#line 237 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 1763 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 26:
#line 241 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_print_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1769 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 27:
#line 242 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_assign = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1775 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 28:
#line 243 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1781 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 29:
#line 244 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 1787 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 30:
#line 246 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(RETURN, yylhs.all_values ()); }
#line 1793 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 31:
#line 248 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(BREAK); }
#line 1799 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 32:
#line 250 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(CONTINUE); }
#line 1805 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 33:
#line 254 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_for_loop = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1811 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 34:
#line 255 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_while_loop = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1817 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 35:
#line 256 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_if_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1823 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 36:
#line 261 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); }
#line 1829 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 37:
#line 266 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_T = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_tuple_ext_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_semi_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FOR,yyv_T,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); }
#line 1835 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 38:
#line 268 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_T = (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_tuple_ext_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FOR,yyv_T,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); }
#line 1841 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 39:
#line 270 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,10,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_T = (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_tuple_ext_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_else_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FOR,yyv_T,yyv_E,yyv_S1,yyv_S2); }
#line 1847 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 40:
#line 275 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_semi_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(WHILE,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); }
#line 1853 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 41:
#line 277 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(WHILE,yyv_E,yyv_S,YYMAKE_TREE(EMPTY)); }
#line 1859 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 42:
#line 279 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,8,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_else_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(WHILE,yyv_E,yyv_S1,yyv_S2); }
#line 1865 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 43:
#line 284 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_semi_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S, YYMAKE_TREE(EMPTY)); }
#line 1871 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 44:
#line 286 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_semi_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_elif_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S, yyv_S1); }
#line 1877 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 45:
#line 288 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_I = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_D = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S1, YYMAKE_TREE(EMPTY)); }
#line 1883 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 46:
#line 290 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,8,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_elif_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S1, yyv_S2); }
#line 1889 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 47:
#line 294 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_else_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = yyv_S; }
#line 1895 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 48:
#line 297 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_semi_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF, yyv_E, yyv_S, YYMAKE_TREE(EMPTY)); }
#line 1901 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 49:
#line 299 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_semi_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_elif_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs =  YYMAKE_TREE(IF, yyv_E, YYMAKE_TREE(STMT_LIST, yyv_S1), yyv_S2); }
#line 1907 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 50:
#line 301 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,8,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_elif_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs =  YYMAKE_TREE(IF, yyv_E, yyv_S1, yyv_S2); }
#line 1913 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 51:
#line 303 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_E = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_S1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs =  YYMAKE_TREE(IF, yyv_E, yyv_S1, YYMAKE_TREE(EMPTY)); }
#line 1919 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 52:
#line 308 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_B = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_semi_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs =  YYMAKE_TREE(STMT_LIST, yyv_B); }
#line 1925 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 53:
#line 310 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_stmt_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs =  yyv_S; }
#line 1931 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 54:
#line 315 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_STRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(NATIVE, yylhs.all_values ()); }
#line 1937 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 55:
#line 320 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yyv_expression, YYMAKE_TREE(EXPR_LIST)); }
#line 1943 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 56:
#line 322 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); }
#line 1949 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 57:
#line 324 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_plist = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); }
#line 1955 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 58:
#line 326 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, YYMAKE_TREE(EMPTY), yylhs.all_values ()); }
#line 1961 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 59:
#line 328 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_plist = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, YYMAKE_TREE(EMPTY), yylhs.all_values ()); }
#line 1967 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 60:
#line 333 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_right_side = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(ASSIGN, yylhs.all_values ()); }
#line 1973 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 61:
#line 337 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1979 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 62:
#line 339 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
#line 1985 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 63:
#line 340 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_tlist = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1991 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 64:
#line 342 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
#line 1997 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 65:
#line 343 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2003 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 66:
#line 344 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_target_list_br = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2009 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 67:
#line 348 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_tlist = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2015 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 68:
#line 350 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
#line 2021 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 69:
#line 352 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
#line 2027 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 70:
#line 357 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
#line 2033 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 71:
#line 364 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPED_ID, yyv_ID, yyv_type); }
#line 2039 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 72:
#line 368 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_id = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2045 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 73:
#line 369 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2051 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 74:
#line 371 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FUNCT_TYPE, yyv_type, yyv_type_list0); }
#line 2057 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 75:
#line 373 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FUNCT_TYPE, yyv_type, YYMAKE_TREE(TYPE_LIST)); }
#line 2063 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 76:
#line 378 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_type_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yyv_ID, yyv_type_list0); }
#line 2069 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 77:
#line 380 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yyv_ID, yyv_type_list1); }
#line 2075 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 78:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_id0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2081 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 79:
#line 386 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yyv_ID, YYMAKE_TREE(TYPE_LIST)); }
#line 2087 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 80:
#line 391 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_TYPE_VAR = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = yyv_TYPE_VAR; }
#line 2093 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 81:
#line 396 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
#line 2099 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 82:
#line 401 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
#line 2105 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 83:
#line 407 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_simple_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2111 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 84:
#line 408 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_typed_id = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2117 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 85:
#line 412 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_tuple_ext_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2123 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 86:
#line 413 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_assign = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2129 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 87:
#line 420 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 2135 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 88:
#line 424 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2141 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 89:
#line 425 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(EXPR_LIST); }
#line 2147 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 90:
#line 430 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 2153 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 91:
#line 434 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2159 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 92:
#line 436 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
#line 2165 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 93:
#line 440 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2171 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 94:
#line 441 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(EMPTY); }
#line 2177 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 95:
#line 445 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_root_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2183 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 96:
#line 450 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_type_id0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL,yyv_type_id0,yyv_expression_list0); }
#line 2189 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 97:
#line 452 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_type_id0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_expression_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL,yyv_type_id0,yyv_expression_list0); }
#line 2195 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 98:
#line 454 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL,yyv_primary_expr,yyv_expression_list0); }
#line 2201 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 99:
#line 456 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_expression_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL,yyv_primary_expr,yyv_expression_list0); }
#line 2207 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 100:
#line 460 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_if_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2213 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 101:
#line 461 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_boolean_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2219 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 102:
#line 465 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_E0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_boolean_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_T = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_root_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_E1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_root_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF_EXPR, yyv_T, yyv_E0, yyv_E1); }
#line 2225 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 103:
#line 470 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2231 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 104:
#line 471 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_compare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2237 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 105:
#line 473 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_boolean_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_boolean_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);int token_id = yyv_type.value()->as_string().compare("and") == 0 ? AND : OR;
                      yylhs = YYMAKE_TREE(token_id, yylhs.all_values ()); }
#line 2244 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 106:
#line 473 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_boolean_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_boolean_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);int token_id = yyv_type.value()->as_string().compare("and") == 0 ? AND : OR;
                      yylhs = YYMAKE_TREE(token_id, yylhs.all_values ()); }
#line 2251 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 107:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2257 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 108:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2263 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 109:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2269 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 110:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2275 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 111:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2281 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 112:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2287 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 113:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2293 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 114:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2299 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 115:
#line 482 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_ISNOT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2305 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 116:
#line 484 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_NOTIN = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(COMPARE, yylhs.all_values ()); }
#line 2311 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 117:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2317 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 118:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2323 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 119:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2329 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 120:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2335 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 121:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2341 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 122:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2347 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 123:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2353 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 124:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2359 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 125:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2365 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 126:
#line 492 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_ISNOT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2371 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 127:
#line 494 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_lcompare_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_NOTIN = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_expr(LCOMPARE, yylhs.all_values ()); }
#line 2377 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 128:
#line 498 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_unary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2383 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 129:
#line 500 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop(yylhs.all_values ()); }
#line 2389 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 130:
#line 500 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop(yylhs.all_values ()); }
#line 2395 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 131:
#line 500 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop(yylhs.all_values ()); }
#line 2401 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 132:
#line 500 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop(yylhs.all_values ()); }
#line 2407 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 133:
#line 500 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop(yylhs.all_values ()); }
#line 2413 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 134:
#line 500 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_arith_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop(yylhs.all_values ()); }
#line 2419 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 135:
#line 504 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expo_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2425 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 136:
#line 506 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_unary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop(yylhs.all_values ()); }
#line 2431 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 137:
#line 506 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_unary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop(yylhs.all_values ()); }
#line 2437 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 138:
#line 506 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_unary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop(yylhs.all_values ()); }
#line 2443 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 139:
#line 510 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_primary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2449 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 140:
#line 512 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expo_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_EXPO = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expo_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop(yylhs.all_values ()); }
#line 2455 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 141:
#line 516 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_INT_LITERAL = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2461 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 142:
#line 517 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_simple_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2467 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 143:
#line 518 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_str_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2473 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 144:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_dict = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2479 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 145:
#line 521 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TUPLE); }
#line 2485 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 146:
#line 523 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(LIST); }
#line 2491 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 147:
#line 525 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
#line 2497 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 148:
#line 527 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(LIST, yylhs.all_values ()); }
#line 2503 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 149:
#line 528 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_root_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2509 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 150:
#line 529 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_function_call = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2515 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 151:
#line 533 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2521 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 152:
#line 535 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_primary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(ATTR_REF, yylhs.all_values ()); }
#line 2527 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 153:
#line 537 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_tuple_ext_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(SUBSCRIPTION, yylhs.all_values ()); }
#line 2533 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 154:
#line 539 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_expression0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(SLICING, yylhs.all_values ()); }
#line 2539 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 155:
#line 543 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_P1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_P2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PAIR,yyv_P1,yyv_P2); }
#line 2545 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 156:
#line 549 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(DICT, yylhs.all_values ()); }
#line 2551 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 157:
#line 553 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_STRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2557 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 158:
#line 554 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_RAWSTRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2563 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 159:
#line 556 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_str_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_RAWSTRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);string s = ((AST_Token *) yyv_S.value().data())->string_text();
                        ((AST_Token *) yyv_str_expr.value().data())->append_text(s);
                        yylhs = yyv_str_expr.value(); }
#line 2571 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 160:
#line 556 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_str_expr = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_S = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_STRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);string s = ((AST_Token *) yyv_S.value().data())->string_text();
                        ((AST_Token *) yyv_str_expr.value().data())->append_text(s);
                        yylhs = yyv_str_expr.value(); }
#line 2579 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 161:
#line 548 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_pair = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2585 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 162:
#line 548 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); }
#line 2591 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 163:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2597 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 164:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_control_structure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2603 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 165:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_definition = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2609 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 166:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_classdef = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2615 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 167:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2621 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 168:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2627 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 169:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_control_structure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2633 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 170:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_definition = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2639 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 171:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2645 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 172:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2651 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 173:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_control_structure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2657 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 174:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2663 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 175:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2669 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 176:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_control_structure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2675 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 177:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_definition = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2681 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 178:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_classdef = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2687 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 179:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2693 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 180:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2699 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 181:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_control_structure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2705 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 182:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_definition = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2711 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 183:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2717 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 184:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2723 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 185:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_control_structure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2729 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 186:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2735 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 187:
#line 223 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_typed_id = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2741 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 188:
#line 223 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2747 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 189:
#line 223 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_typed_id = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2753 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 190:
#line 223 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2759 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 191:
#line 341 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2765 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 192:
#line 341 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2771 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 193:
#line 351 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2777 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 194:
#line 351 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2783 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 195:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2789 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 196:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2795 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 197:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2801 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 198:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2807 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 199:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2813 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 200:
#line 167 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2819 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 201:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2825 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 202:
#line 230 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2831 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 203:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2837 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 204:
#line 173 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2843 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 205:
#line 176 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2849 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 206:
#line 223 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); }
#line 2855 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 207:
#line 226 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2861 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 208:
#line 548 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_pair = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2867 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 209:
#line 551 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2873 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 210:
#line 223 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2879 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 211:
#line 226 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2885 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 212:
#line 236 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2891 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 213:
#line 239 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2897 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 214:
#line 435 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2903 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 215:
#line 438 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2909 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 216:
#line 526 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2915 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 217:
#line 529 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),4,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2921 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 218:
#line 524 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),4,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2927 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 219:
#line 527 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),4,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_pair = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval); }
#line 2933 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 220:
#line 548 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),4,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_pair = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2939 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 221:
#line 551 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2945 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 222:
#line 548 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2951 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 223:
#line 551 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2957 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 224:
#line 419 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2963 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 225:
#line 422 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2969 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 226:
#line 236 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2975 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 227:
#line 239 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2981 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 228:
#line 395 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2987 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 229:
#line 398 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2993 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 230:
#line 197 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2999 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 231:
#line 200 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),11,11,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-10) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-9) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-8) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-9) - (0))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (0))].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (0))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 3005 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 232:
#line 218 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),11,12,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-10) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-9) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-8) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-9) - (1))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (1))].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (1))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 3011 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 233:
#line 221 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval); }
#line 3017 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 234:
#line 435 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 3023 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 235:
#line 438 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 3029 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 236:
#line 526 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 3035 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 237:
#line 529 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 3041 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 238:
#line 349 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 3047 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 239:
#line 352 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval); }
#line 3053 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 240:
#line 524 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 3059 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 241:
#line 527 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),7,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (0))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (0))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 3065 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 242:
#line 212 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),7,8,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (1))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (1))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 3071 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 243:
#line 215 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),9,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-8) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (0))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (0))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 3077 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 244:
#line 214 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),9,10,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-8) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (1))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (1))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 3083 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 245:
#line 217 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),9,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-8) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (0))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (0))].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 3089 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 246:
#line 216 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),9,10,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-8) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-6) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-4) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-3) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-7) - (1))].yystate.yysemantics.yysval); yyv_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-5) - (1))].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval); yyv_native_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 3095 "apyc-parser.cc" /* glr.c:788  */
    break;


#line 3099 "apyc-parser.cc" /* glr.c:788  */
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* ID  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3147 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 4: /* "@println"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3153 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 5: /* EMPTY  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3159 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 6: /* "@expr_list"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3165 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 7: /* "@module"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3171 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 8: /* "@binop"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3177 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 9: /* "@unop"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3183 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 10: /* INDENT  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3189 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 11: /* DEDENT  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3195 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 12: /* "@stmt_list"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3201 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 13: /* "@print"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3207 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 14: /* "@return"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3213 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 15: /* "@break"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3219 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 16: /* "@continue"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3225 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 17: /* "@native"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3231 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 18: /* "@if"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3237 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 19: /* "@for"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3243 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 20: /* "@while"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3249 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 21: /* "@block"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3255 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 22: /* "@assign"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3261 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 23: /* "@target_list"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3267 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 24: /* "@attributeref"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3273 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 25: /* "@subscription"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3279 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 26: /* "@slicing"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3285 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 27: /* "@type"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3291 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 28: /* "@typed_id"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3297 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 29: /* "@type_var"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3303 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 30: /* "@type_list"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3309 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 31: /* "@type_formals_list"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3315 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 32: /* "@formals_list"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3321 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 33: /* "@function_type"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3327 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 34: /* "@def"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3333 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 35: /* "@class"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3339 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 36: /* "@compare"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3345 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 37: /* "@left_compare"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3351 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 38: /* "@and"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3357 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 39: /* "@or"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3363 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 40: /* "@if_expr"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3369 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 41: /* "@tuple"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3375 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 42: /* "@list_display"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3381 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 43: /* "@dict_display"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3387 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 44: /* "@pair"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3393 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 45: /* "@call"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3399 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 46: /* "**"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3405 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 47: /* ISNOT  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3411 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 48: /* NOTIN  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3417 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 49: /* "<"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3423 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 50: /* ">"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3429 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 51: /* "+"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3435 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 52: /* "-"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3441 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 53: /* "%"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3447 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 54: /* "*"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3453 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 55: /* "/"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3459 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 56: /* "&&"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3465 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 57: /* "||"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3471 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 58: /* "!="  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3477 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 59: /* "("  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3483 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 60: /* ")"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3489 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 61: /* ","  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3495 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 62: /* "->"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3501 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 63: /* "."  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3507 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 64: /* "//"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3513 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 65: /* ":"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3519 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 66: /* "::"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3525 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 67: /* ";"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3531 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 68: /* "<="  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3537 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 69: /* "="  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3543 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 70: /* "=="  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3549 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 71: /* ">="  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3555 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 72: /* ">>"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3561 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 73: /* "["  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3567 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 74: /* "]"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3573 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 75: /* "and"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3579 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 76: /* "break"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3585 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 77: /* "class"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3591 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 78: /* "continue"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3597 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 79: /* "def"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3603 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 80: /* "elif"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3609 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 81: /* "else"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3615 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 82: /* "for"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3621 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 83: /* "if"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3627 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 84: /* "in"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3633 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 85: /* "is"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3639 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 86: /* "native"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3645 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 87: /* "not"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3651 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 88: /* "of"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3657 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 89: /* "or"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3663 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 90: /* "pass"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3669 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 91: /* "print"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3675 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 92: /* "return"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3681 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 93: /* "while"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3687 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 94: /* "{"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3693 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 95: /* "}"  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3699 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 96: /* BADSTRING  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3705 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 97: /* BLANK_LINE  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3711 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 98: /* END_OF_FILE  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3717 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 99: /* INDENTATION  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3723 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 100: /* INT_LITERAL  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3729 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 101: /* NEWLINE  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3735 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 102: /* RAWSTRING  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3741 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 103: /* STRING  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3747 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 104: /* UNUSED_KEYWORD  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3753 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 106: /* program  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3759 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 107: /* stmt_list  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3765 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 108: /* stmt_list0  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3771 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 109: /* statement  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3777 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 110: /* classdef  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3783 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 111: /* type_formals  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3789 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 112: /* definition  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3795 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 113: /* formals  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3801 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 114: /* block  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3807 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 115: /* semi_block  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3813 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 116: /* basic_statement  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3819 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 117: /* control_structure  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3825 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 118: /* semi_stmt_list  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3831 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 119: /* for_loop  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3837 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 120: /* while_loop  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3843 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 121: /* if_stmt  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3849 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 122: /* elif_stmts  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3855 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 123: /* else_stmt  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3861 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 124: /* native_stmt  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3867 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 125: /* print_stmt  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3873 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 126: /* assign  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3879 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 127: /* target_list  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3885 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 128: /* target_list_br  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3891 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 129: /* tlist  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3897 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 130: /* typed_id  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3903 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 131: /* type  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3909 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 132: /* type_id0  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3915 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 133: /* type_id  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3921 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 134: /* type_var  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3927 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 135: /* type_list0  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3933 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 136: /* type_list1  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3939 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 137: /* target  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3945 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 138: /* right_side  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3951 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 139: /* plist  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3957 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 140: /* expression_list0  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3963 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 141: /* expression_list  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3969 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 142: /* tuple_ext_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3975 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 143: /* expression0  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3981 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 144: /* expression  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3987 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 145: /* function_call  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3993 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 146: /* root_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3999 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 147: /* if_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4005 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 148: /* boolean_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4011 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 149: /* compare_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4017 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 150: /* lcompare_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4023 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 151: /* arith_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4029 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 152: /* unary_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4035 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 153: /* expo_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4041 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 154: /* primary_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4047 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 155: /* simple_target  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4053 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 156: /* pair  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4059 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 157: /* dict  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4065 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 158: /* str_expr  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4071 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 159: /* __0  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4077 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 160: /* __1  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4083 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 161: /* __2  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4089 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 162: /* __3  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4095 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 163: /* __4  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4101 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 164: /* __5  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4107 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 165: /* __6  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4113 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 166: /* __7  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4119 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 167: /* __8  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4125 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 168: /* __9  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4131 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 169: /* __10  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4137 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 170: /* __11  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4143 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 171: /* __12  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4149 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 172: /* __13  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4155 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 173: /* __14  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4161 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 174: /* __15  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4167 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 175: /* __16  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4173 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 176: /* __17  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4179 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 177: /* __18  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4185 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 178: /* __19  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4191 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 179: /* __20  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4197 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 180: /* __21  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4203 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 181: /* __22  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4209 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 182: /* __23  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4215 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 183: /* __24  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4221 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 184: /* __25  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4227 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 185: /* __26  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4233 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 186: /* __27  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4239 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 187: /* __28  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4245 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 188: /* __29  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4251 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 189: /* __30  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4257 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 190: /* __31  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4263 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 191: /* __32  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4269 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 192: /* __33  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4275 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 193: /* __34  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4281 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 194: /* __35  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4287 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 195: /* __36  */
#line 252 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 4293 "apyc-parser.cc" /* glr.c:818  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved ", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete ", yymsg);
          yy_symbol_print (stderr, yystos[yys->yylrState],
                           YY_NULL);
          YYFPRINTF (stderr, "\n");
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-308)))

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) \
  0

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
{
  int yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULL;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULL)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULL)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULL)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULL)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                 yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULL)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULL;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULL)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
                                              );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YYFPRINTF (stderr, " (unresolved)");
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULL)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp);
    }
  else
    {
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULL)
    {
      YYRESULTTAG yyflag;
      YYSTYPE yysval;

      yyflag = yydoAction (yystackp, yyk, yyrule, &yysval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULL)
        {
          YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                     (unsigned long int) yyk, yyrule - 1));
        }
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  "
                  "Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULL)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULL;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULL)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULL)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULL)
                break;
              else if (*yyz0p == YY_NULL)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULL)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]),
                       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULL; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULL;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULL)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULL;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;

  while (yyr != YY_NULL)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULL)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YYDPRINTF ((stderr,
                          "Stack %lu dies "
                          "(predicate failure or explicit user error).\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken;
          int yyaction;
          const short int* yyconflicts;

          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
          if (yychar == YYEMPTY)
            {
              YYDPRINTF ((stderr, "Reading a token: "));
              yychar = yylex ();
            }

          if (yychar <= YYEOF)
            {
              yychar = yytoken = YYEOF;
              YYDPRINTF ((stderr, "Now at end of input.\n"));
            }
          else
            {
              yytoken = YYTRANSLATE (yychar);
              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
            }

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr, "Stack %lu dies.\n",
                              (unsigned long int) yynewStack));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr,
                              "Stack %lu dies "
                              "(predicate failure or explicit user error).\n",
                              (unsigned long int) yyk));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULL, yytokenName (yytoken));
  size_t yysize = yysize0;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULL;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                {
                  size_t yysz = yysize + yytnamerr (YY_NULL, yytokenName (yyx));
                  yysize_overflow |= yysz < yysize;
                  yysize = yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    size_t yysz = yysize + strlen (yyformat);
    yysize_overflow |= yysz < yysize;
    yysize = yysz;
  }

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              yyp++;
              yyformat++;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULL);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = yylex ();
        if (yychar <= YYEOF)
          {
            yychar = yytoken = YYEOF;
            YYDPRINTF ((stderr, "Now at end of input.\n"));
          }
        else
          {
            yytoken = YYTRANSLATE (yychar);
            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
          }
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULL)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, YY_NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULL)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULL)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULL)
    yyFail (yystackp, YY_NULL);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yySymbol yytoken;
              if (yychar == YYEMPTY)
                {
                  YYDPRINTF ((stderr, "Reading a token: "));
                  yychar = yylex ();
                }

              if (yychar <= YYEOF)
                {
                  yychar = yytoken = YYEOF;
                  YYDPRINTF ((stderr, "Now at end of input.\n"));
                }
              else
                {
                  yytoken = YYTRANSLATE (yychar);
                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
                }

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                  if (yys->yypred != YY_NULL)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULL)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif

#undef yylval
#undef yychar
#undef yynerrs



#line 1500 "apyc-parser.y" /* glr.c:2549  */



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
