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
#define YYERROR_FUNCTION_NAME parse_error

# define YY_PARSER_1
# include "horn-parse-lex.cc"

#line 60 "apyc-parser.cc" /* glr.c:189  */




/* First part of user declarations.  */
#line 14 "apyc-parser.y" /* glr.c:207  */


    YYNAMESPACE_OPEN

#line 13 "apyc.hn" /* glr.c:207  */

    #include <string>
    #include "apyc.h"
    #include "ast.h"

    using namespace std;

    static GCINIT _gcdummy;

    static AST_Ptr theTree;

    static const char* last_source_loc;

    /** Report an error (same arguments as error) at LOC, or the end of the
     *  last file if LOC is unknown. */
    static void parse_error (const char* loc, const char* format, ...);

    /** Assuming that TEXT is the whitespace at the beginning of a line, returns
     *  or queues the indicated INDENT and DEDENT tokens. */
    static int do_indent(const char* text);

    /** Nesting level of current source position in '[', '(', and '{'
     *  brackets. */
    static int bracket_depth;
    /** Current nesting depth within "if", "while", and "for" statements. */
    static int control_depth;
    /** Current nesting depth within "def" and "class" statements. */
    static int defn_depth;
    /** Current loop depth within "while" and "for" statements. */
    static int loop_depth;
    /** Current nesting depth within "def" statements (functions). */
    static int func_depth;

    /** Output an error message if a "def" statement is not permitted
     *  at the current source position. */
    static void check_def_placement ();
    /** Output an error message if a "class" statement is not permitted
     *  at the current source position. */
    static void check_class_placement ();
    /** Output an error message TEXT is not in the required range for
     *  integer numerals.  It is assumed to have the form of a valid
     *  numeral otherwise. */
    static void check_numeral (const char* text);
    /** Output an error message if not nested in the main body of a loop (
     *  (not including its "else" clause). */
    static void check_in_loop ();
    /** Output an error message if not nested inside a function definition. */
    static void check_in_func ();

    /** Finish processing the current source file, and return to the
     *  previous one.  Returns true iff there is a previous source
     *  file and false if at the end of input. */
    static bool pop_source_file ();

    /** Create a "unop" node out of OPERANDS. */
    static AST_Ptr make_unop (const List_Ptr& operands);
    /** Create a comparison or binop node out of operator OP (an integer
     *  token value), and OPERANDS. */
    static AST_Ptr make_binop (const List_Ptr& operands, int op);

    /** Create an id out of the text and location of TOKEN, which must be a
     *  token. */
    static AST_Ptr make_id (AST_Ptr& token);
    /** Create an id out of the text and location of (*OPERAND)[0]. OPERAND
     *  must be a singleton list containing a token. */
    static AST_Ptr make_id (const List_Ptr& operand);

    /** Increment COUNT. */
    static inline void
    incr (int& count)
    {
        count += 1;
    }

    /** Decrement COUNT, but no further than 0. */
    static inline void
    decr (int& count)
    {
        count -= 1;
        if (count < 0)
            count = 0;
    }
#line 216 "apyc-parser.y" /* glr.c:207  */


#define YY_PARSER_2
#include "horn-parse-lex.cc"

#line 266 "apyc-parser.y" /* glr.c:207  */

static yyvar yyv_DEDENT;
static yyvar yyv_ID;
static yyvar yyv_INDENT;
static yyvar yyv_INT_LITERAL;
static yyvar yyv_NEWLINE;
static yyvar yyv_RAWSTRING;
static yyvar yyv_STRING;
static yyvar yyv_TYPE_VAR;
static yyvar yyv_argument_list;
static yyvar yyv_assignment_stmt;
static yyvar yyv_atom;
static yyvar yyv_attributeref;
static yyvar yyv_bound;
static yyvar yyv_break_stmt;
static yyvar yyv_call;
static yyvar yyv_classbody;
static yyvar yyv_classdef;
static yyvar yyv_comp_operator;
static yyvar yyv_compound_stmt;
static yyvar yyv_cond;
static yyvar yyv_conditional_expression;
static yyvar yyv_continue_stmt;
static yyvar yyv_dict_display;
static yyvar yyv_elifs;
static yyvar yyv_else_clause;
static yyvar yyv_elsepart;
static yyvar yyv_empty;
static yyvar yyv_enclosure;
static yyvar yyv_error;
static yyvar yyv_expr1;
static yyvar yyv_expr2;
static yyvar yyv_expr3;
static yyvar yyv_expression;
static yyvar yyv_expression_list0_no_comma;
static yyvar yyv_expression_list_no_comma;
static yyvar yyv_expression_or_list;
static yyvar yyv_expression_or_list0;
static yyvar yyv_expression_stmt;
static yyvar yyv_for_stmt;
static yyvar yyv_funcbody;
static yyvar yyv_funcdef;
static yyvar yyv_funcname;
static yyvar yyv_identifier;
static yyvar yyv_if_stmt;
static yyvar yyv_key_datum;
static yyvar yyv_key_datum_list;
static yyvar yyv_left;
static yyvar yyv_left_compare;
static yyvar yyv_list_display;
static yyvar yyv_literal;
static yyvar yyv_name;
static yyvar yyv_native;
static yyvar yyv_op;
static yyvar yyv_opt_type_annotation;
static yyvar yyv_parameter;
static yyvar yyv_parameter_list;
static yyvar yyv_parameterized_type;
static yyvar yyv_parenth_form;
static yyvar yyv_pass_stmt;
static yyvar yyv_primary;
static yyvar yyv_print_stmt;
static yyvar yyv_return_stmt;
static yyvar yyv_right;
static yyvar yyv_simple_stmt;
static yyvar yyv_slicing;
static yyvar yyv_statement;
static yyvar yyv_stmt_list;
static yyvar yyv_stmts;
static yyvar yyv_string_piece;
static yyvar yyv_stringliteral;
static yyvar yyv_subscription;
static yyvar yyv_suite;
static yyvar yyv_target;
static yyvar yyv_target_list;
static yyvar yyv_target_list1;
static yyvar yyv_thenpart;
static yyvar yyv_type;
static yyvar yyv_type_annotation;
static yyvar yyv_type_formals;
static yyvar yyv_type_list;
static yyvar yyv_type_params;
static yyvar yyv_type_var;
static yyvar yyv_types;
static yyvar yyv_while_stmt;


#line 248 "apyc-parser.cc" /* glr.c:207  */

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

#line 276 "apyc-parser.cc" /* glr.c:230  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   845

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  214
/* YYNRULES -- Number of states.  */
#define YYNSTATES  322
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 3

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    57,     2,     2,
      58,    59,    60,    61,    62,    63,    65,    66,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    69,
      70,    72,    74,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,     2,    89,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    64,    68,    71,    73,    75,    76,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    90,    91
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   346,   346,   353,   356,   356,   356,   359,   359,   359,
     363,   364,   368,   369,   376,   377,   384,   385,   389,   393,
     397,   400,   404,   405,   406,   407,   408,   412,   414,   418,
     425,   432,   433,   436,   438,   442,   448,   452,   456,   461,
     462,   462,   463,   468,   473,   478,   479,   484,   485,   489,
     491,   493,   498,   500,   502,   506,   508,   513,   514,   516,
     518,   518,   518,   518,   518,   518,   518,   525,   526,   527,
     528,   529,   530,   531,   534,   538,   540,   545,   546,   547,
     548,   549,   550,   556,   555,   557,   562,   563,   565,   566,
     567,   570,   575,   577,   579,   581,   583,   587,   591,   594,
     598,   599,   600,   601,   602,   606,   607,   608,   609,   613,
     616,   616,   620,   625,   624,   632,   634,   639,   640,   645,
     647,   644,   654,   656,   653,   663,   662,   676,   677,   678,
     683,   688,   689,   694,   695,   698,   701,   700,   707,   712,
     715,   719,   720,   724,   725,   727,   728,   734,   738,   742,
     746,   751,   752,   757,   489,   489,   489,   489,   489,   489,
     489,   489,   479,   479,   607,   607,   385,   385,   555,   555,
     385,   385,   742,   742,   346,   346,   349,   479,   482,   397,
     400,   620,   623,   689,   692,   385,   388,   689,   692,   346,
     349,   442,   445,   473,   476,   747,   750,   707,   710,   385,
     388,   389,   392,   393,   396,   442,   445,   397,   400,   620,
     623,   389,   392,   707,   712
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "ID", "\"@unop\"",
  "\"//\"", "\"**\"", "\"and\"", "\"@assign\"", "\"@attributeref\"",
  "\"@binop\"", "\"@block\"", "\"break\"", "\"@call\"", "\"@class\"",
  "\"@@block\"", "\"@compare\"", "\"@left_compare\"", "\"continue\"",
  "DEDENT", "\"def\"", "\"@dict_display\"", "EMPTY", "\"@expr_list\"",
  "\"for\"", "\"@formals_list\"", "\"@function_type\"", "\"if\"",
  "\"@if_expr\"", "INDENT", "\"@int_literal\"", "\"@list_display\"",
  "\"@def\"", "\"@module\"", "\"native\"", "\"not\"", "\"or\"",
  "\"@pair\"", "\"@print\"", "\"@println\"", "\"@slicing\"",
  "\"@@slicing\"", "\"@stmt_list\"", "STRING_LITERAL", "\"@subscription\"",
  "\"@@subscription\"", "\"@target_list\"", "\"@type_formals_list\"",
  "\"@tuple\"", "\"@type\"", "\"@type_list\"", "\"@type_var\"",
  "\"@typed_id\"", "\"while\"", "\"!=\"", "\"%\"", "\"(\"", "\")\"",
  "\"*\"", "\"+\"", "\",\"", "\"-\"", "\"->\"", "\".\"", "\"/\"", "\":\"",
  "\"::\"", "\";\"", "\"<\"", "\"<=\"", "\"=\"", "\"==\"", "\">\"",
  "\">=\"", "\">>\"", "\"[\"", "\"]\"", "\"class\"", "\"elif\"",
  "\"else\"", "\"in\"", "\"is\"", "\"of\"", "\"pass\"", "\"print\"",
  "\"return\"", "\"{\"", "\"}\"", "NEWLINE", "RAWSTRING", "$accept",
  "program", "identifier", "atom", "enclosure", "literal", "string_piece",
  "stringliteral", "parenth_form", "list_display", "dict_display",
  "key_datum_list", "key_datum", "primary", "attributeref", "subscription",
  "slicing", "bound", "call", "argument_list", "expression",
  "conditional_expression", "expr1", "expression_list_no_comma",
  "expression_list0_no_comma", "expression_or_list", "expression_or_list0",
  "comp_operator", "expr2", "left_compare", "expr3", "simple_stmt",
  "expression_stmt", "assignment_stmt", "target_list", "target_list1",
  "target", "pass_stmt", "print_stmt", "return_stmt", "break_stmt",
  "continue_stmt", "compound_stmt", "stmts", "suite", "statement",
  "stmt_list", "if_stmt", "@1", "elifs", "else_clause", "while_stmt", "@2",
  "@3", "for_stmt", "@4", "@5", "funcdef", "@6", "funcbody", "native",
  "parameter_list", "parameter", "funcname", "classdef", "@7",
  "type_formals", "classbody", "type_annotation", "opt_type_annotation",
  "type", "type_var", "parameterized_type", "type_params", "type_list",
  "types", "empty", "__0", "__1", "__2", "__3", "__4", "__5", "__6", "__7",
  "__8", "__9", "__10", "__11", "__12", "__13", "__14", "__15", "__16",
  "__17", "__18", "__19", "__20", "__21", "__22", "__23", "__24", "__25",
  "__26", "__error__", YY_NULL
};
#endif

#define YYPACT_NINF -236
#define YYTABLE_NINF -188

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
    -236,    48,   556,  -236,  -236,  -236,  -236,  -236,    41,   489,
     362,  -236,   362,   362,   158,   454,   454,    78,    41,  -236,
       2,   362,   362,  -236,  -236,   287,  -236,  -236,  -236,  -236,
      28,  -236,  -236,  -236,    46,   -12,    -7,   102,  -236,    14,
    -236,    34,  -236,  -236,   762,   686,  -236,  -236,  -236,     9,
    -236,    33,  -236,  -236,  -236,  -236,  -236,  -236,  -236,    17,
    -236,  -236,  -236,  -236,  -236,   -14,   362,  -236,  -236,    50,
      46,    38,   362,   362,    43,  -236,  -236,  -236,    42,  -236,
      62,    -5,    71,    18,    94,   146,   146,  -236,    79,    -9,
      80,    81,   362,   362,  -236,  -236,  -236,  -236,  -236,   101,
      82,    36,    21,  -236,  -236,  -236,  -236,   362,    41,   362,
    -236,   362,   362,   362,    88,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,   136,   454,  -236,   454,   454,   454,   454,   454,
     454,   454,   454,   106,   369,   599,   114,  -236,   362,    41,
     115,  -236,   174,   362,  -236,  -236,  -236,   362,   121,  -236,
    -236,  -236,  -236,   125,  -236,  -236,  -236,   116,   124,  -236,
     132,  -236,   138,  -236,  -236,   140,   362,  -236,  -236,    36,
      43,  -236,  -236,  -236,    36,  -236,   145,  -236,  -236,  -236,
     148,    60,   127,  -236,  -236,    24,   204,  -236,  -236,   721,
     146,   146,   146,   146,    30,    30,   146,   756,   647,  -236,
    -236,  -236,  -236,   599,  -236,   159,  -236,  -236,   161,    41,
     155,   536,   536,  -236,   362,  -236,   362,  -236,   171,  -236,
     362,   163,  -236,   362,  -236,  -236,  -236,   167,   165,  -236,
      64,  -236,   168,   362,  -236,   362,  -236,  -236,  -236,   164,
     164,   169,  -236,  -236,   202,  -236,   -22,   144,   149,  -236,
    -236,  -236,  -236,   536,  -236,   176,   362,  -236,   178,    36,
    -236,   362,  -236,   162,  -236,  -236,  -236,   177,  -236,  -236,
     238,  -236,   536,   447,   362,   185,  -236,  -236,  -236,  -236,
     173,    66,  -236,  -236,   193,  -236,  -236,    36,  -236,  -236,
    -236,  -236,  -236,   634,   235,   194,   536,  -236,   171,  -236,
    -236,   467,   173,  -236,  -236,  -236,   536,  -236,  -236,    28,
     229,  -236,  -236,  -236,  -236,   -22,    27,   356,  -236,  -236,
     241,  -236
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const unsigned char yydefact[] =
{
     188,     0,     2,     1,    12,     3,    98,    99,     0,    83,
       0,    11,     0,     0,    83,     0,     0,    83,     0,    91,
     153,   153,   202,   174,    13,     4,    22,     6,     5,    14,
      10,     7,     8,     9,    57,    23,    24,    25,    26,    45,
      36,    38,    74,    39,     0,    54,   208,    67,    68,     0,
      79,    77,    69,    70,    71,    72,    73,   111,   175,     0,
     100,   101,   102,   103,   104,     0,   176,   189,   135,     0,
       0,     0,   198,   200,     4,    23,    24,    25,     0,    42,
       0,     0,     0,     0,     0,    59,    58,   210,     0,     0,
       0,   196,     0,   192,    47,    97,    48,   203,   206,     0,
       0,     0,     0,    87,   148,   149,    15,   190,     0,   153,
     162,     0,     0,     0,     0,   159,   154,   157,   156,   155,
     158,   161,   160,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,   180,    83,    85,   178,   110,   190,     0,
     177,    46,   131,     0,   113,   119,    16,   170,   184,   199,
      80,    78,    17,   184,    81,    82,    18,     0,     0,   138,
      93,   204,     0,    92,    44,   178,     0,    19,   147,   194,
     144,   140,   145,   143,     0,   173,     0,   204,    35,    27,
       0,    31,     0,    32,    41,     0,    40,    51,    50,    52,
      64,    66,    65,    62,    60,    61,    63,    53,    83,   112,
      75,    76,   168,   179,    84,     0,    28,   163,     0,     0,
       0,     0,     0,   166,   185,   171,   185,   201,     0,   136,
       0,   193,    95,   179,    20,    21,   151,     0,   195,   150,
       0,    33,   178,   153,    29,     0,   209,   169,    34,   153,
     133,   182,   122,   214,     0,   109,   117,     0,     0,   120,
     167,   211,   212,     0,   204,    94,     0,   207,     0,     0,
     172,   179,   191,     0,    31,    37,   141,     0,   142,   134,
     183,   132,     0,     0,     0,     0,   114,   116,   105,   107,
     117,     0,   139,   137,    43,    96,   205,     0,   152,    30,
     125,   123,   164,    83,     0,     0,     0,   121,     0,   197,
     146,     0,   117,   106,   165,   108,     0,   118,   213,     0,
       0,   127,   126,   128,   124,   117,     0,     0,   115,   130,
       0,   129
};

  /* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -236,  -236,    -2,  -236,  -236,  -236,   -26,   -46,  -236,  -236,
    -236,  -236,    51,    -4,     0,    25,    47,    31,  -236,   128,
     175,  -236,     1,    45,  -236,   -18,  -236,   224,  -236,  -236,
      20,    77,  -236,   142,   268,   107,     5,  -236,  -236,  -236,
    -236,  -236,  -236,  -228,  -204,    -1,    16,  -236,  -236,   -36,
    -235,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
     -37,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -154,  -236,
     -73,  -195,   -81,  -236,  -236,   109,   -10,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,  -135,  -236,  -236,   133,
    -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -153,
    -236,  -236,  -236,  -236,  -233
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,     1,    74,    26,    27,    28,    29,    30,    31,    32,
      33,    97,    98,    34,    75,    76,    77,   180,    38,   176,
      39,    40,    41,   162,   163,    42,    95,   123,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   245,   246,   292,   247,    60,   211,   276,
     277,    61,   212,   280,    62,   272,   302,    63,   301,   312,
     313,   208,   241,    69,    64,   253,   158,   283,   103,   267,
     226,   172,    65,   104,   227,   228,   183,   124,    66,   293,
     148,   136,   149,   105,    67,   141,   204,   199,   271,   215,
     209,     2,   178,   164,   229,   159,    84,    90,   100,   221,
     165,   133,   153,   281,   248
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const short int yytable[] =
{
      25,    58,    35,    94,   106,    70,    68,    25,   249,    35,
      93,    96,    25,    79,    35,    25,    91,    35,    59,    83,
     173,   173,    89,   252,   232,   282,     5,    36,   171,   175,
     224,     4,     4,   111,    36,    85,    86,   125,   126,    36,
     294,     5,    36,   111,   138,   297,     5,   -23,     3,    37,
     -23,   139,   -24,   135,   146,   -24,    37,   147,   274,   275,
     -88,    37,   113,   112,    37,   -89,   -23,   314,   291,   155,
     -23,   -24,   113,   311,   168,   -24,   110,   151,    92,   169,
     135,   134,     4,     5,   294,   266,   269,   127,   173,   168,
     128,   182,   307,   173,   169,   135,   131,   262,   174,   170,
     170,   284,   315,   308,   107,   235,   179,   137,   142,   144,
      11,   108,   184,   185,   186,    12,   200,   319,    24,    24,
     143,    82,   110,   109,    88,   210,   259,   102,   298,   145,
     150,    70,    25,    25,    35,    35,    72,   206,   -45,    15,
     202,    16,   260,   189,   299,   190,   191,   192,   193,   194,
     195,   196,   197,   152,   126,    73,   -83,   154,   156,    36,
      36,   -25,     4,     5,   -25,   157,    22,   170,   166,    24,
     187,   167,   170,   188,   -90,   198,   203,   207,   173,  -186,
     -25,    37,    37,   214,   -25,    78,   288,   216,    80,    81,
      11,   219,    87,   218,   220,    12,    25,    99,    35,    70,
     222,    25,   223,    35,   231,   234,   173,   240,   237,    25,
      25,    35,    35,   111,   300,   233,    72,   -83,   238,    15,
     239,    16,   242,    36,   168,   256,   258,   259,    36,   268,
     261,   270,   101,   273,   278,    73,    36,    36,   285,   279,
     289,   140,   287,  -187,   290,    37,    22,    81,    87,    24,
      37,    25,   296,    35,   275,   256,   305,   170,    37,    37,
     317,   306,   321,   316,   263,   255,   205,   160,   161,   132,
      25,    25,    35,    35,   257,   236,   201,    71,    36,   318,
     320,     0,   177,   230,   181,   170,   217,     0,     0,    59,
     106,    25,   304,    35,    25,     0,    35,    36,    36,    25,
      37,    35,     0,     0,    25,     0,    35,     0,     0,    59,
       0,     0,     0,   177,     0,    25,     0,    35,    36,    37,
      37,    36,   213,     0,     0,     0,    36,     0,     0,     0,
       0,    36,     0,    59,     0,     0,     0,     0,     0,     0,
      37,   225,    36,    37,     0,     0,    -4,     0,    37,    -4,
       0,     0,     0,    37,     0,   101,     0,   243,     0,   -86,
       4,     5,     0,     0,    37,    -4,     4,     5,     0,    -4,
       6,   102,     0,     4,     5,     0,     7,     0,     8,     0,
       0,     0,     9,     0,     0,    10,     0,     0,    11,   250,
       0,   251,   309,    12,    11,   254,     0,     0,    99,    12,
       0,    11,     0,     0,     0,     0,    12,     0,   264,     0,
     265,    13,     0,     0,    14,     0,     0,    15,     0,    16,
      72,     0,     0,    15,     0,    16,     0,    14,   -83,     0,
      15,   286,    16,    17,     0,    18,   286,     0,     0,    73,
       0,    19,    20,    21,    22,     0,    17,    24,   243,   295,
      22,     4,     5,    24,     0,     0,     0,    22,     4,     5,
      24,     6,     0,     0,     0,     0,     0,     7,   243,     8,
       0,     4,     5,     9,     0,     0,    10,     0,     0,    11,
       0,     6,     0,     0,    12,     0,    11,     7,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     0,     0,    11,
       0,     0,    13,   309,    12,    14,     0,     0,    15,     0,
      16,     0,    72,     0,     0,    15,     0,    16,     0,   -83,
       0,    11,     0,     0,    17,    14,    18,     0,    15,     0,
      16,    73,    19,    20,    21,    22,     0,   243,    24,   -83,
       4,     5,    22,     0,    17,    24,     0,    14,     0,     0,
       6,     0,    19,    20,    21,    22,     7,   310,    24,     0,
       4,     5,     0,     0,     0,     0,    17,     0,    11,     0,
       6,     0,     0,    12,     0,     0,     7,    22,     8,     0,
      24,     0,     9,     0,     0,    10,     0,     0,    11,     0,
       0,     0,     0,    12,    14,     0,     0,    15,     0,    16,
       0,     0,     0,     4,     5,     0,     0,     0,   -83,     0,
       0,    13,     0,    17,    14,     0,     0,    15,     0,    16,
       0,    19,    20,    21,    22,     0,   244,    24,   -83,     0,
       0,    11,     0,    17,     0,    18,     0,     0,     4,     5,
       0,    19,    20,    21,    22,     0,    23,    24,     6,     0,
       0,     4,     5,     0,     7,   303,     8,    72,     0,     0,
       9,     6,     0,    10,     0,     0,    11,     7,     0,     0,
       0,    12,     0,     0,     0,     0,    73,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,    22,     0,    13,
      24,     0,    14,   125,   126,    15,     0,    16,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    15,     0,
      16,    17,     0,    18,     0,     0,     0,     0,     0,    19,
      20,    21,    22,   114,    17,    24,     0,     0,   125,   126,
       0,     0,    19,    20,    21,    22,     0,  -181,    24,     0,
       0,     0,   115,   127,     0,     0,   128,   129,     0,   130,
       0,     0,   131,     0,     0,     0,   116,   117,   -56,   118,
     119,   120,     0,   125,   126,     0,     0,     0,   121,   122,
       0,     0,     0,     0,     0,     0,     0,   -56,   127,     0,
       0,   128,   129,     0,   130,     0,     0,   131,     0,     0,
       0,   -56,   -56,   -55,   -56,   -56,   -56,     0,     0,   114,
       0,     0,     0,   -56,   -56,     0,     0,     0,     0,     0,
       0,     0,   -55,   127,     0,     0,   128,   129,   115,   130,
       0,     0,   131,     0,     0,     0,   -55,   -55,     0,   -55,
     -55,   -55,   116,   117,     0,   118,   119,   120,   -55,   -55,
       0,     0,     0,     0,   121,   122
};

static const short int yycheck[] =
{
       2,     2,     2,    21,    30,     9,     8,     9,   212,     9,
      20,    21,    14,    12,    14,    17,    18,    17,     2,    14,
     101,   102,    17,   218,   177,   253,     5,     2,   101,   102,
     165,     4,     4,     9,     9,    15,    16,     7,     8,    14,
     273,     5,    17,     9,    58,   280,     5,    59,     0,     2,
      62,    65,    59,    62,    59,    62,     9,    62,    80,    81,
      72,    14,    38,    29,    17,    72,    78,   302,   272,    78,
      82,    78,    38,   301,    53,    82,    62,    59,    76,    58,
      62,    72,     4,     5,   317,   239,   240,    57,   169,    53,
      60,   109,   296,   174,    58,    62,    66,   232,    77,   101,
     102,   254,   306,   298,    58,    81,   108,    90,    58,    67,
      32,    65,   111,   112,   113,    37,   134,    90,    91,    91,
      82,    14,    62,    77,    17,   143,    62,    84,    62,    67,
      59,   135,   134,   135,   134,   135,    58,   139,    78,    61,
     135,    63,    78,   123,    78,   125,   126,   127,   128,   129,
     130,   131,   132,    59,     8,    77,    78,    78,    78,   134,
     135,    59,     4,     5,    62,    84,    88,   169,    67,    91,
      82,    89,   174,    37,    72,    69,    62,    62,   259,     5,
      78,   134,   135,    62,    82,    10,   259,    62,    13,    14,
      32,    67,    17,    77,    62,    37,   198,    22,   198,   203,
      62,   203,    62,   203,    59,    78,   287,   209,   203,   211,
     212,   211,   212,     9,   287,    67,    58,    59,    59,    61,
      59,    63,    67,   198,    53,    62,    59,    62,   203,   239,
      62,    62,    68,    31,    90,    77,   211,   212,    62,    90,
      78,    66,    64,     5,    67,   198,    88,    72,    73,    91,
     203,   253,    67,   253,    81,    62,    21,   259,   211,   212,
      31,    67,    21,   309,   233,   220,   138,    92,    93,    45,
     272,   273,   272,   273,   223,   198,   134,     9,   253,   315,
     317,    -1,   107,   174,   109,   287,   153,    -1,    -1,   273,
     316,   293,   293,   293,   296,    -1,   296,   272,   273,   301,
     253,   301,    -1,    -1,   306,    -1,   306,    -1,    -1,   293,
      -1,    -1,    -1,   138,    -1,   317,    -1,   317,   293,   272,
     273,   296,   147,    -1,    -1,    -1,   301,    -1,    -1,    -1,
      -1,   306,    -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,
     293,   166,   317,   296,    -1,    -1,    59,    -1,   301,    62,
      -1,    -1,    -1,   306,    -1,    68,    -1,     1,    -1,    72,
       4,     5,    -1,    -1,   317,    78,     4,     5,    -1,    82,
      14,    84,    -1,     4,     5,    -1,    20,    -1,    22,    -1,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,   214,
      -1,   216,    36,    37,    32,   220,    -1,    -1,   223,    37,
      -1,    32,    -1,    -1,    -1,    -1,    37,    -1,   233,    -1,
     235,    55,    -1,    -1,    58,    -1,    -1,    61,    -1,    63,
      58,    -1,    -1,    61,    -1,    63,    -1,    58,    72,    -1,
      61,   256,    63,    77,    -1,    79,   261,    -1,    -1,    77,
      -1,    85,    86,    87,    88,    -1,    77,    91,     1,   274,
      88,     4,     5,    91,    -1,    -1,    -1,    88,     4,     5,
      91,    14,    -1,    -1,    -1,    -1,    -1,    20,     1,    22,
      -1,     4,     5,    26,    -1,    -1,    29,    -1,    -1,    32,
      -1,    14,    -1,    -1,    37,    -1,    32,    20,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    55,    36,    37,    58,    -1,    -1,    61,    -1,
      63,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,    72,
      -1,    32,    -1,    -1,    77,    58,    79,    -1,    61,    -1,
      63,    77,    85,    86,    87,    88,    -1,     1,    91,    72,
       4,     5,    88,    -1,    77,    91,    -1,    58,    -1,    -1,
      14,    -1,    85,    86,    87,    88,    20,    90,    91,    -1,
       4,     5,    -1,    -1,    -1,    -1,    77,    -1,    32,    -1,
      14,    -1,    -1,    37,    -1,    -1,    20,    88,    22,    -1,
      91,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    37,    58,    -1,    -1,    61,    -1,    63,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    72,    -1,
      -1,    55,    -1,    77,    58,    -1,    -1,    61,    -1,    63,
      -1,    85,    86,    87,    88,    -1,    90,    91,    72,    -1,
      -1,    32,    -1,    77,    -1,    79,    -1,    -1,     4,     5,
      -1,    85,    86,    87,    88,    -1,    90,    91,    14,    -1,
      -1,     4,     5,    -1,    20,    21,    22,    58,    -1,    -1,
      26,    14,    -1,    29,    -1,    -1,    32,    20,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    77,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    88,    -1,    55,
      91,    -1,    58,     7,     8,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
      63,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    37,    77,    91,    -1,    -1,     7,     8,
      -1,    -1,    85,    86,    87,    88,    -1,    90,    91,    -1,
      -1,    -1,    56,    57,    -1,    -1,    60,    61,    -1,    63,
      -1,    -1,    66,    -1,    -1,    -1,    70,    71,    37,    73,
      74,    75,    -1,     7,     8,    -1,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,
      -1,    60,    61,    -1,    63,    -1,    -1,    66,    -1,    -1,
      -1,    70,    71,    37,    73,    74,    75,    -1,    -1,    37,
      -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    -1,    -1,    60,    61,    56,    63,
      -1,    -1,    66,    -1,    -1,    -1,    70,    71,    -1,    73,
      74,    75,    70,    71,    -1,    73,    74,    75,    82,    83,
      -1,    -1,    -1,    -1,    82,    83
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    93,   183,     0,     4,     5,    14,    20,    22,    26,
      29,    32,    37,    55,    58,    61,    63,    77,    79,    85,
      86,    87,    88,    90,    91,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   105,   106,   107,   108,   110,   112,
     113,   114,   117,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   137,   138,
     139,   143,   146,   149,   156,   164,   170,   176,    94,   155,
     105,   126,    58,    77,    94,   106,   107,   108,   112,   114,
     112,   112,   127,   128,   188,   122,   122,   112,   127,   128,
     189,    94,    76,   168,   117,   118,   168,   103,   104,   112,
     190,    68,    84,   160,   165,   175,    98,    58,    65,    77,
      62,     9,    29,    38,    37,    56,    70,    71,    73,    74,
      75,    82,    83,   119,   169,     7,     8,    57,    60,    61,
      63,    66,   119,   193,    72,    62,   173,    90,    58,    65,
     112,   177,    58,    82,    67,    67,    59,    62,   172,   174,
      59,    59,    59,   194,    78,    78,    78,    84,   158,   187,
     112,   112,   115,   116,   185,   192,    67,    89,    53,    58,
      94,   162,   163,   164,    77,   162,   111,   112,   184,    94,
     109,   112,   117,   168,   114,   114,   114,    82,    37,   122,
     122,   122,   122,   122,   122,   122,   122,   122,    69,   179,
     117,   125,   128,    62,   178,   111,    94,    62,   153,   182,
     117,   140,   144,   112,    62,   181,    62,   181,    77,    67,
      62,   191,    62,    62,   178,   112,   162,   166,   167,   186,
     167,    59,   191,    67,    78,    81,   123,   128,    59,    59,
      94,   154,    67,     1,    90,   135,   136,   138,   196,   136,
     112,   112,   163,   157,   112,   115,    62,   104,    59,    62,
      78,    62,   178,   109,   112,   112,   160,   161,   168,   160,
      62,   180,   147,    31,    80,    81,   141,   142,    90,    90,
     145,   195,   135,   159,   191,    62,   112,    64,   162,    78,
      67,   136,   137,   171,   196,   112,    67,   142,    62,    78,
     162,   150,   148,    21,   137,    21,    67,   136,   163,    36,
      90,   135,   151,   152,   142,   136,    99,    31,   141,    90,
     152,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    92,    93,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   102,
     103,   104,   105,   105,   105,   105,   105,   106,   106,   107,
     108,   109,   109,   110,   110,   111,   112,   113,   113,   114,
     114,   114,   114,   115,   116,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   124,   125,   125,   126,   126,   126,
     126,   126,   126,   127,   127,   127,   128,   128,   128,   128,
     128,   129,   130,   130,   130,   130,   130,   131,   132,   133,
     134,   134,   134,   134,   134,   135,   135,   135,   135,   136,
     137,   137,   138,   140,   139,   141,   141,   142,   142,   144,
     145,   143,   147,   148,   146,   150,   149,   151,   151,   151,
     152,   153,   153,   154,   154,   155,   157,   156,   158,   159,
     160,   161,   161,   162,   162,   162,   162,   163,   164,   165,
     166,   167,   167,   168,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   180,   180,   181,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   186,   186,   187,   187,   188,   188,
     189,   189,   190,   190,   191,   191,   192,   192,   193,   193,
     194,   194,   195,   195,   196
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     3,     4,
       6,     1,     1,     4,     4,     1,     1,     5,     1,     1,
       3,     3,     2,     2,     1,     1,     2,     1,     1,     1,
       2,     2,     3,     3,     1,     3,     3,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     1,
       3,     3,     3,     0,     3,     2,     1,     2,     1,     1,
       1,     1,     3,     3,     5,     4,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     2,     4,     1,
       2,     1,     3,     0,     6,     5,     1,     0,     3,     0,
       0,     7,     0,     0,     9,     0,     9,     1,     1,     4,
       3,     0,     3,     1,     2,     1,     0,     6,     1,     1,
       2,     1,     1,     1,     1,     1,     5,     1,     2,     1,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     2,     3,     2,     3,
       1,     2,     4,     2,     1,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     3,     0,     2,
       0,     3,     0,     2,     0,     1,     0,     5,     0,     2,
       0,     3,     0,     1,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     1
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
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
      15,     0,    21,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
      19,    25,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       0,    29,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,    11,
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
       0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   198,     0,   200,     0,    86,     0,    86,     0,    86,
       0,    86,     0,    88,     0,    88,     0,    88,     0,    88,
       0,    89,     0,    89,     0,    89,     0,    89,     0,    90,
       0,    90,     0,    90,     0,    90,     0,    43,     0,    43,
       0
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
#line 347 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE (MODULE, yylhs.all_values ());
                  yylhs.set_loc (NULL);
                  theTree = yylhs.value (); }
#line 1491 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 3:
#line 353 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1497 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 4:
#line 356 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1503 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 5:
#line 356 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_literal = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1509 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 6:
#line 356 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_enclosure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1515 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 7:
#line 359 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_parenth_form = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1521 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 8:
#line 359 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_list_display = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1527 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 9:
#line 359 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_dict_display = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1533 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 10:
#line 363 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1539 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 11:
#line 364 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_INT_LITERAL = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1545 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 12:
#line 368 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_STRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1551 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 13:
#line 369 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_RAWSTRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1557 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 14:
#line 376 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_string_piece = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1563 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 15:
#line 378 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_string_piece = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yyv_stringliteral.value()->as_token()
                     ->append_text(yyv_string_piece.value()->as_token()
                                   ->string_text());
                  yylhs = yyv_stringliteral; }
#line 1572 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 16:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1578 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 17:
#line 386 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
#line 1584 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 18:
#line 390 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(LIST_DISPLAY, yylhs.all_values ()); }
#line 1590 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 19:
#line 394 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(DICT_DISPLAY, yylhs.all_values ()); }
#line 1596 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 20:
#line 397 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 1602 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 21:
#line 401 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PAIR, yylhs.all_values ()); }
#line 1608 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 22:
#line 404 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_atom = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1614 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 23:
#line 405 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_attributeref = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1620 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 24:
#line 406 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_subscription = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1626 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 25:
#line 407 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_slicing = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1632 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 26:
#line 408 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_call = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1638 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 27:
#line 413 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(ATTRIBUTEREF, yylhs.all_values ()); }
#line 1644 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 28:
#line 415 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(ATTRIBUTEREF, yylhs.all_values ()); }
#line 1650 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 29:
#line 419 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (SUBSCRIPTION, yyv_primary.value (),
                           yyv_expression_or_list.value (),
                           make_id ("__getitem__", yyv_expression_or_list.loc ())); }
#line 1658 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 30:
#line 426 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_left = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_bound = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_right = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_bound = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (SLICING, yyv_primary.value (),
                           yyv_left.value (), yyv_right.value (),
                           make_id ("__getslice__", yyv_left.loc ())); }
#line 1666 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 31:
#line 432 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1672 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 32:
#line 433 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1678 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 33:
#line 437 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_argument_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); }
#line 1684 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 34:
#line 439 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_argument_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); }
#line 1690 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 35:
#line 444 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 1696 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 36:
#line 448 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_conditional_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1702 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 37:
#line 453 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_thenpart = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_cond = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_elsepart = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF_EXPR, yyv_cond.value(), yyv_thenpart.value (),
                          yyv_elsepart.value ()); }
#line 1709 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 38:
#line 456 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1715 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 39:
#line 461 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1721 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 40:
#line 462 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).mark_tree_op (); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1727 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 41:
#line 462 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).mark_tree_op (); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1733 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 42:
#line 464 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
#line 1739 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 43:
#line 469 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 1745 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 44:
#line 474 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 1751 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 45:
#line 478 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1757 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 46:
#line 480 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
#line 1763 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 47:
#line 484 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1769 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 48:
#line 485 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1775 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 49:
#line 490 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = make_id(yylhs.all_values ()); }
#line 1781 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 50:
#line 492 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_op = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = make_id("isnot", yyv_op.loc()); }
#line 1787 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 51:
#line 494 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_op = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = make_id("notin", yyv_op.loc()); }
#line 1793 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 52:
#line 499 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_left_compare = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), COMPARE); }
#line 1799 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 53:
#line 501 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), COMPARE); }
#line 1805 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 54:
#line 502 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1811 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 55:
#line 507 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), LEFT_COMPARE); }
#line 1817 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 56:
#line 509 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_left_compare = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), LEFT_COMPARE); }
#line 1823 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 57:
#line 513 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1829 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 58:
#line 515 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
#line 1835 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 59:
#line 517 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
#line 1841 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 60:
#line 520 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1847 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 61:
#line 520 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1853 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 62:
#line 520 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1859 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 63:
#line 520 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1865 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 64:
#line 520 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1871 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 65:
#line 520 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1877 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 66:
#line 520 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1883 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 67:
#line 525 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1889 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 68:
#line 526 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_assignment_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1895 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 69:
#line 527 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_pass_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1901 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 70:
#line 528 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_print_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1907 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 71:
#line 529 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_return_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1913 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 72:
#line 530 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_break_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1919 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 73:
#line 531 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_continue_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1925 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 74:
#line 534 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1931 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 75:
#line 539 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); }
#line 1937 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 76:
#line 541 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_assignment_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); }
#line 1943 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 77:
#line 545 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1949 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 78:
#line 546 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1955 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 79:
#line 547 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1961 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 80:
#line 548 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1967 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 81:
#line 549 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1973 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 82:
#line 551 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (TARGET_LIST, yylhs.all_values ()); }
#line 1979 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 83:
#line 556 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0);  }
#line 1985 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 84:
#line 556 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
#line 1991 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 85:
#line 558 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TARGET_LIST, yyv_target.value ()); }
#line 1997 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 86:
#line 562 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2003 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 87:
#line 564 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); }
#line 2009 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 88:
#line 565 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_attributeref = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2015 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 89:
#line 566 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_subscription = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2021 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 90:
#line 567 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_slicing = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2027 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 91:
#line 571 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(STMT_LIST); }
#line 2033 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 92:
#line 576 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expression_list0_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); }
#line 2039 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 93:
#line 578 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yyv_expression.value (), YYMAKE_TREE(EXPR_LIST)); }
#line 2045 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 94:
#line 580 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); }
#line 2051 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 95:
#line 582 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); }
#line 2057 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 96:
#line 584 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); }
#line 2063 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 97:
#line 588 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).mark_tree_op (); yyv_expression_or_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);check_in_func (); }
#line 2069 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 98:
#line 591 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).mark_tree_op ();check_in_loop (); }
#line 2075 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 99:
#line 594 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).mark_tree_op ();check_in_loop (); }
#line 2081 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 100:
#line 598 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_if_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2087 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 101:
#line 599 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_while_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2093 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 102:
#line 600 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_for_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2099 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 103:
#line 601 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_funcdef = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2105 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 104:
#line 602 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_classdef = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2111 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 105:
#line 606 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2117 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 106:
#line 607 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2123 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 107:
#line 608 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2129 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 108:
#line 609 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2135 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 109:
#line 613 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); }
#line 2141 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 110:
#line 616 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2147 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 111:
#line 616 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_compound_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2153 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 112:
#line 620 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2159 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 113:
#line 625 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);incr (control_depth); }
#line 2165 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 114:
#line 628 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_elifs = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (control_depth); }
#line 2171 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 115:
#line 633 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_elifs = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (IF, yylhs.all_values ()); }
#line 2177 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 116:
#line 634 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2183 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 117:
#line 639 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(STMT_LIST); }
#line 2189 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 118:
#line 640 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2195 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 119:
#line 645 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);incr (control_depth); incr (loop_depth); }
#line 2201 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 120:
#line 647 "apyc.hn" /* glr.c:788  */
    { YYCTL(((*yyvalp)), 0, 0);  yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (loop_depth); }
#line 2207 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 121:
#line 649 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (control_depth); }
#line 2213 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 122:
#line 654 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);incr (control_depth); incr (loop_depth); }
#line 2219 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 123:
#line 656 "apyc.hn" /* glr.c:788  */
    { YYCTL(((*yyvalp)), 0, 0);  yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (loop_depth); }
#line 2225 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 124:
#line 658 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (control_depth); }
#line 2231 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 125:
#line 663 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_funcname = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_parameter_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_opt_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);check_def_placement ();
                  incr (defn_depth); incr (func_depth); }
#line 2238 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 126:
#line 666 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_funcbody = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (defn_depth); decr (func_depth);
		  if (func_depth != 0 || defn_depth != 1)
		      yylhs = YYMAKE_TREE (DEF, yylhs.all_values ());
		  else
		      yylhs = YYMAKE_TREE (METHOD, yylhs.all_values ()); }
#line 2248 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 127:
#line 676 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 2254 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 128:
#line 677 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_native = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 2260 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 129:
#line 679 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_native = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 2266 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 130:
#line 683 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2272 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 131:
#line 688 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(FORMALS_LIST); }
#line 2278 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 132:
#line 690 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(FORMALS_LIST, yylhs.all_values ()); }
#line 2284 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 133:
#line 694 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2290 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 134:
#line 695 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); }
#line 2296 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 135:
#line 698 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2302 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 136:
#line 701 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);check_class_placement (); incr (defn_depth); }
#line 2308 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 137:
#line 703 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_classbody = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (defn_depth); yylhs = YYMAKE_TREE(CLASS, yylhs.all_values ()); }
#line 2314 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 138:
#line 708 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_FORMALS_LIST, yylhs.all_values ()); }
#line 2320 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 139:
#line 712 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CLASS_BLOCK, yylhs.all_values ()); }
#line 2326 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 140:
#line 715 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2332 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 141:
#line 719 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2338 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 142:
#line 720 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2344 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 143:
#line 724 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2350 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 144:
#line 726 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yyv_identifier, YYMAKE_TREE(TYPE_LIST)); }
#line 2356 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 145:
#line 727 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2362 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 146:
#line 729 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FUNCTION_TYPE,
                          yyv_type.value (), yyv_type_list.value ()); }
#line 2369 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 147:
#line 734 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_TYPE_VAR = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE_VAR, yylhs.all_values ()); }
#line 2375 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 148:
#line 738 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_type_params = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yylhs.all_values ()); }
#line 2381 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 149:
#line 743 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
#line 2387 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 150:
#line 746 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
#line 2393 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 151:
#line 751 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2399 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 152:
#line 752 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2405 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 153:
#line 757 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(EMPTY); yylhs.set_loc (yysource_location ()); }
#line 2411 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 154:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2417 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 155:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2423 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 156:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2429 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 157:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2435 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 158:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2441 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 159:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2447 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 160:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2453 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 161:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2459 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 162:
#line 479 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2465 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 163:
#line 479 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2471 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 164:
#line 607 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2477 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 165:
#line 607 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2483 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 166:
#line 385 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2489 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 167:
#line 385 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2495 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 168:
#line 555 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2501 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 169:
#line 555 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2507 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 170:
#line 385 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2513 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 171:
#line 385 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2519 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 172:
#line 742 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2525 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 173:
#line 742 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2531 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 174:
#line 346 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2537 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 175:
#line 346 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2543 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 176:
#line 349 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2549 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 177:
#line 479 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2555 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 178:
#line 482 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2561 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 179:
#line 397 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2567 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 180:
#line 400 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2573 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 181:
#line 620 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2579 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 182:
#line 623 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2585 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 183:
#line 689 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2591 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 184:
#line 692 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2597 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 185:
#line 385 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2603 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 186:
#line 388 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2609 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 187:
#line 689 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2615 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 188:
#line 692 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2621 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 189:
#line 346 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2627 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 190:
#line 349 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2633 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 191:
#line 442 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2639 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 192:
#line 445 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2645 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 193:
#line 473 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2651 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 194:
#line 476 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2657 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 195:
#line 747 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2663 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 196:
#line 750 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2669 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 197:
#line 707 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2675 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 198:
#line 710 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2681 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 199:
#line 385 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2687 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 200:
#line 388 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2693 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 201:
#line 389 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2699 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 202:
#line 392 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2705 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 203:
#line 393 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_key_datum_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2711 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 204:
#line 396 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2717 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 205:
#line 442 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2723 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 206:
#line 445 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_key_datum = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2729 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 207:
#line 397 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_key_datum = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2735 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 208:
#line 400 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_simple_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2741 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 209:
#line 620 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_simple_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2747 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 210:
#line 623 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2753 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 211:
#line 389 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2759 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 212:
#line 392 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2765 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 213:
#line 707 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2771 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 214:
#line 712 "apyc.hn" /* glr.c:788  */
    { ((*yyvalp))._clear (); }
#line 2777 "apyc-parser.cc" /* glr.c:788  */
    break;


#line 2781 "apyc-parser.cc" /* glr.c:788  */
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
          case 3: /* INT  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2829 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 4: /* STRING  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2835 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 5: /* ID  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2841 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 6: /* "@unop"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2847 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 7: /* "//"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2853 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 8: /* "**"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2859 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 9: /* "and"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2865 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 10: /* "@assign"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2871 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 11: /* "@attributeref"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2877 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 12: /* "@binop"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2883 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 13: /* "@block"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2889 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 14: /* "break"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2895 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 15: /* "@call"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2901 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 16: /* "@class"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2907 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 17: /* "@@block"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2913 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 18: /* "@compare"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2919 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 19: /* "@left_compare"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2925 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 20: /* "continue"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2931 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 21: /* DEDENT  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2937 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 22: /* "def"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2943 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 23: /* "@dict_display"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2949 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 24: /* EMPTY  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2955 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 25: /* "@expr_list"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2961 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 26: /* "for"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2967 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 27: /* "@formals_list"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2973 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 28: /* "@function_type"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2979 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 29: /* "if"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2985 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 30: /* "@if_expr"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2991 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 31: /* INDENT  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2997 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 32: /* "@int_literal"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3003 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 33: /* "@list_display"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3009 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 34: /* "@def"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3015 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 35: /* "@module"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3021 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 36: /* "native"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3027 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 37: /* "not"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3033 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 38: /* "or"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3039 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 39: /* "@pair"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3045 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 40: /* "@print"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3051 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 41: /* "@println"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3057 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 42: /* "@slicing"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3063 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 43: /* "@@slicing"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3069 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 44: /* "@stmt_list"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3075 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 45: /* STRING_LITERAL  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3081 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 46: /* "@subscription"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3087 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 47: /* "@@subscription"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3093 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 48: /* "@target_list"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3099 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 49: /* "@type_formals_list"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3105 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 50: /* "@tuple"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3111 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 51: /* "@type"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3117 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 52: /* "@type_list"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3123 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 53: /* "@type_var"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3129 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 54: /* "@typed_id"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3135 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 55: /* "while"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3141 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 56: /* "!="  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3147 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 57: /* "%"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3153 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 58: /* "("  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3159 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 59: /* ")"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3165 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 60: /* "*"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3171 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 61: /* "+"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3177 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 62: /* ","  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3183 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 63: /* "-"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3189 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 64: /* "->"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3195 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 65: /* "."  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3201 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 66: /* "/"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3207 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 67: /* ":"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3213 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 68: /* "::"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3219 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 69: /* ";"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3225 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 70: /* "<"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3231 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 71: /* "<="  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3237 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 72: /* "="  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3243 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 73: /* "=="  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3249 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 74: /* ">"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3255 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 75: /* ">="  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3261 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 76: /* ">>"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3267 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 77: /* "["  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3273 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 78: /* "]"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3279 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 79: /* "class"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3285 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 80: /* "elif"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3291 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 81: /* "else"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3297 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 82: /* "in"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3303 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 83: /* "is"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3309 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 84: /* "of"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3315 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 85: /* "pass"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3321 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 86: /* "print"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3327 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 87: /* "return"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3333 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 88: /* "{"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3339 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 89: /* "}"  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3345 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 90: /* NEWLINE  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3351 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 91: /* RAWSTRING  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3357 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 93: /* program  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3363 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 94: /* identifier  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3369 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 95: /* atom  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3375 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 96: /* enclosure  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3381 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 97: /* literal  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3387 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 98: /* string_piece  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3393 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 99: /* stringliteral  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3399 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 100: /* parenth_form  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3405 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 101: /* list_display  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3411 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 102: /* dict_display  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3417 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 103: /* key_datum_list  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3423 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 104: /* key_datum  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3429 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 105: /* primary  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3435 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 106: /* attributeref  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3441 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 107: /* subscription  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3447 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 108: /* slicing  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3453 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 109: /* bound  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3459 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 110: /* call  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3465 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 111: /* argument_list  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3471 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 112: /* expression  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3477 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 113: /* conditional_expression  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3483 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 114: /* expr1  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3489 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 115: /* expression_list_no_comma  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3495 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 116: /* expression_list0_no_comma  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3501 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 117: /* expression_or_list  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3507 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 118: /* expression_or_list0  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3513 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 119: /* comp_operator  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3519 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 120: /* expr2  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3525 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 121: /* left_compare  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3531 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 122: /* expr3  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3537 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 123: /* simple_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3543 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 124: /* expression_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3549 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 125: /* assignment_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3555 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 126: /* target_list  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3561 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 127: /* target_list1  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3567 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 128: /* target  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3573 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 129: /* pass_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3579 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 130: /* print_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3585 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 131: /* return_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3591 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 132: /* break_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3597 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 133: /* continue_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3603 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 134: /* compound_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3609 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 135: /* stmts  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3615 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 136: /* suite  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3621 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 137: /* statement  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3627 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 138: /* stmt_list  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3633 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 139: /* if_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3639 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 140: /* @1  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3645 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 141: /* elifs  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3651 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 142: /* else_clause  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3657 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 143: /* while_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3663 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 144: /* @2  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3669 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 145: /* @3  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3675 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 146: /* for_stmt  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3681 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 147: /* @4  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3687 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 148: /* @5  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3693 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 149: /* funcdef  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3699 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 150: /* @6  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3705 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 151: /* funcbody  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3711 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 152: /* native  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3717 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 153: /* parameter_list  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3723 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 154: /* parameter  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3729 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 155: /* funcname  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3735 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 156: /* classdef  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3741 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 157: /* @7  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3747 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 158: /* type_formals  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3753 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 159: /* classbody  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3759 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 160: /* type_annotation  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3765 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 161: /* opt_type_annotation  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3771 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 162: /* type  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3777 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 163: /* type_var  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3783 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 164: /* parameterized_type  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3789 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 165: /* type_params  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3795 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 166: /* type_list  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3801 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 167: /* types  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3807 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 168: /* empty  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3813 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 169: /* __0  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3819 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 170: /* __1  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3825 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 171: /* __2  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3831 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 172: /* __3  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3837 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 173: /* __4  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3843 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 174: /* __5  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3849 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 175: /* __6  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3855 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 176: /* __7  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3861 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 177: /* __8  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3867 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 178: /* __9  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3873 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 179: /* __10  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3879 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 180: /* __11  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3885 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 181: /* __12  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3891 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 182: /* __13  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3897 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 183: /* __14  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3903 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 184: /* __15  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3909 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 185: /* __16  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3915 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 186: /* __17  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3921 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 187: /* __18  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3927 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 188: /* __19  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3933 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 189: /* __20  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3939 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 190: /* __21  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3945 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 191: /* __22  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3951 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 192: /* __23  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3957 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 193: /* __24  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3963 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 194: /* __25  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3969 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 195: /* __26  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3975 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 196: /* __error__  */
#line 264 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3981 "apyc-parser.cc" /* glr.c:818  */
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
  (!!((Yystate) == (-236)))

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



#line 1414 "apyc-parser.y" /* glr.c:2549  */



#line 760 "apyc.hn"


#include <stack>

static stack<int> indentation_stack;
bool debugParser;
static gcvector<FILE*> files;

/** A mapping from binary operators to corresponding method
 *  names (as tokens).  Initialized from BINOP_MAP_INIT. */
static gcmap<gcstring, const char*> binop_method_map;
/** A mapping from unary operators to corresponding method
 *  names (as tokens).  Initialized from UNOP_MAP_INIT. */
static gcmap<gcstring, const char*> unop_method_map;

static const char* BINOP_MAP_INIT[] = {
    "+", "__add__",  "-", "__sub__",  "*", "__mul__",  "//", "__floordiv__",
    "/", "__floordiv__",  "%", "__mod__",  "**", "__pow__",
    "in", "__contains__", "notin", "__notcontains__",
    "is", "__is__", "isnot", "__isnot__",
    "<", "__lt__", ">", "__gt__", "<=", "__le__", ">=", "__ge__",
    "==", "__eq__", "!=", "__ne__",
    0,  0
};

static const char* UNOP_MAP_INIT[] = {
    "-",  "__neg__", "+", "__pos__", "not", "__not__",
    0, 0
};

static const char*
get_unop_method (const gcstring& op)
{
    const char* result = unop_method_map[op];
    assert (result != NULL);
    return result;
}

static const char*
get_binop_method (const gcstring& op)
{
    const char* result = binop_method_map[op];
    assert (result != NULL);
    return result;
}

static void
check_def_placement ()
{
    if (control_depth > 0)
        error (yysource_location (), "illegally nested def statement");
}

static void
check_class_placement ()
{
    if (control_depth > 0 || defn_depth > 0)
        error (yysource_location (), "illegally nested class definition");
}

static void
check_in_loop ()
{
    if (loop_depth == 0)
        error (yysource_location (), "statement must be in a loop");
}

static void
check_in_func ()
{
    if (func_depth == 0)
        error (yysource_location (), "statement must be in a function body");
}

static void
check_numeral (const char* text)
{
    if (text[0] == '0' && (text[1] == 'x' || text[1] == 'X')) {
        text += 2;
        while (*text == '0')
            text += 1;
        if (strlen (text) > 8 ||
            (strlen (text) == 8 && strcmp (text, "80000000") > 0))
            error (yysource_location (), "hex numeral too large");
    } else if (text[0] == '0') {
        while (*text == '0')
            text += 1;
        if (strlen (text) > 11 ||
            (strlen (text) == 11 && strcmp (text, "20000000000") > 0))
            error (yysource_location (), "octal numeral too large");
    } else if (strlen (text) > 10 ||
            (strlen (text) == 10 && strcmp (text, "2147483648") > 0))
            error (yysource_location (), "decimal numeral too large");
}

/** The equivalent number of spaces to TEXT, a sequence of whitespace
 *  characters. */
static int
indent_length (const char* text)
{
    int n;
    n = 0;
    for (const char* p = text; *p != '\0'; p += 1) {
        if (*p == '\t')
            n = (n + 8) & ~7;
        else
            n += 1;
    }
    return n;
}

static int
do_indent (const char* text)
{
    int amount = indent_length (text);

    if (indentation_stack.empty())
        indentation_stack.push (0);

    if (amount > indentation_stack.top ()) {
        indentation_stack.push (amount);
        return INDENT;
    }

    if (amount < indentation_stack.top ()) {
        indentation_stack.pop ();
        while (amount < indentation_stack.top ()) {
            yyqueue_token (DEDENT, 0, 0, "", 8);
            indentation_stack.pop ();
        }
        if (amount != indentation_stack.top ()) {
            error (text, "improper indentation");
        }
        return DEDENT;
    }

    return -1;
}

static AST_Ptr
make_unop (const List_Ptr& operands)
{
    AST_Ptr op = operands->at (0);

    return YYMAKE_TREE (UNOP, make_id (op), operands->at (1),
                        make_id (get_unop_method(op->as_string ()),
                                 op->loc ()));
}

static AST_Ptr
make_binop (const List_Ptr& operands, int op = BINOP)
{
    AST_Ptr oper = operands->at (1);

    return YYMAKE_TREE (op, operands->at (0), make_id (oper), operands->at (2),
                        make_id (get_binop_method(oper->as_string ()),
                                 oper->loc ()));
}

static AST_Ptr
make_id (AST_Ptr& token)
{
    AST_Ptr result = AST::make_token (ID, token->text_size (),
                                      token->as_chars ());
    result->set_loc (token->loc ());
    return result;
}

static AST_Ptr
make_id (const List_Ptr& operands)
{
    return make_id (operands->at (0));
}

int
AST::lineNumber ()
{
    return yylocation_line (loc ());
}

static
bool pop_source_file ()
{
    last_source_loc = yysource_location ();
    fclose (files.back ());
    files.pop_back ();
    yypop_lexer ();
    return !files.empty ();
}

void
add_source_file (const gcstring& name)
{
    FILE* f = fopen (name.c_str (), "r");

    if (f == NULL)
        error_no_file ("Could not open %s", name.c_str ());
    files.push_back(f);
    yypush_lexer (f, name);
}

void
parse_error (const char* loc, const char* message, ...)
{
    if (loc == NULL)
        error (last_source_loc, message);
    else
        error (loc, message);
}

void
parse_init ()
{
    yypush_lexer ("", "<beginning of source>");
    for (size_t i = 0; BINOP_MAP_INIT[i] != NULL; i += 2)
	binop_method_map[BINOP_MAP_INIT[i]] =
	    BINOP_MAP_INIT[i+1];
    for (size_t i = 0; UNOP_MAP_INIT[i] != NULL; i += 2)
	unop_method_map[UNOP_MAP_INIT[i]] =
	    UNOP_MAP_INIT[i+1];
}

AST_Ptr
parse ()
{
    if (debugParser)
	yydebug = 1;
    last_source_loc = NULL;

    theTree = NULL;
    yyparse ();

    return theTree;
}


#line 1655 "apyc-parser.y"

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
