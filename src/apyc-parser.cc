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
#line 215 "apyc-parser.y" /* glr.c:207  */


#define YY_PARSER_2
#include "horn-parse-lex.cc"

#line 265 "apyc-parser.y" /* glr.c:207  */

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
#define YYLAST   855

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
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
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    56,     2,     2,
      57,    58,    59,    60,    61,    62,    64,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    68,
      69,    71,    73,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,     2,    88,     2,     2,     2,     2,
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
      55,    63,    67,    70,    72,    74,    75,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    89,    90
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   345,   345,   352,   355,   355,   355,   358,   358,   358,
     362,   363,   367,   368,   375,   376,   383,   384,   388,   392,
     396,   399,   403,   404,   405,   406,   407,   411,   413,   417,
     424,   431,   432,   435,   437,   441,   447,   451,   455,   460,
     461,   461,   462,   467,   472,   477,   478,   483,   484,   488,
     490,   492,   497,   499,   501,   505,   507,   512,   513,   515,
     517,   517,   517,   517,   517,   517,   517,   524,   525,   526,
     527,   528,   529,   530,   533,   537,   539,   544,   545,   546,
     547,   548,   549,   555,   554,   556,   561,   562,   564,   565,
     566,   569,   574,   576,   578,   580,   582,   586,   590,   593,
     597,   598,   599,   600,   601,   605,   606,   607,   608,   612,
     615,   615,   619,   624,   623,   631,   633,   638,   639,   644,
     646,   643,   653,   655,   652,   662,   661,   675,   676,   677,
     682,   687,   688,   693,   694,   697,   700,   699,   706,   711,
     714,   718,   719,   723,   724,   726,   727,   733,   737,   741,
     745,   750,   751,   756,   488,   488,   488,   488,   488,   488,
     488,   488,   478,   478,   606,   606,   384,   384,   554,   554,
     384,   384,   741,   741,   345,   345,   348,   478,   481,   396,
     399,   619,   622,   688,   691,   384,   387,   688,   691,   345,
     348,   441,   444,   472,   475,   746,   749,   706,   709,   384,
     387,   388,   391,   392,   395,   441,   444,   396,   399,   619,
     622,   388,   391,   706,   711
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "ID", "\"@unop\"",
  "\"//\"", "\"**\"", "\"and\"", "\"@assign\"", "\"@attributeref\"",
  "\"@binop\"", "\"@block\"", "\"break\"", "\"@call\"", "\"@@block\"",
  "\"@compare\"", "\"@left_compare\"", "\"continue\"", "DEDENT", "\"def\"",
  "\"@dict_display\"", "EMPTY", "\"@expr_list\"", "\"for\"",
  "\"@formals_list\"", "\"@function_type\"", "\"if\"", "\"@if_expr\"",
  "INDENT", "\"@int_literal\"", "\"@list_display\"", "\"@def\"",
  "\"@module\"", "\"native\"", "\"not\"", "\"or\"", "\"@pair\"",
  "\"@print\"", "\"@println\"", "\"@slicing\"", "\"@@slicing\"",
  "\"@stmt_list\"", "STRING_LITERAL", "\"@subscription\"",
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

#define YYPACT_NINF -237
#define YYTABLE_NINF -188

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
    -237,    45,   539,  -237,  -237,  -237,  -237,  -237,    77,    28,
     159,  -237,   159,   159,    21,   650,   650,   479,    77,  -237,
      14,   159,   159,  -237,  -237,   289,  -237,  -237,  -237,  -237,
      19,  -237,  -237,  -237,    -9,   253,   274,   288,  -237,    35,
    -237,    32,  -237,  -237,    84,   713,  -237,  -237,  -237,    23,
    -237,    44,  -237,  -237,  -237,  -237,  -237,  -237,  -237,    18,
    -237,  -237,  -237,  -237,  -237,    -6,   159,  -237,  -237,    69,
      -9,    55,   159,   159,    46,  -237,  -237,  -237,    72,  -237,
      78,    -8,    97,     4,   103,   154,   154,  -237,    92,   -14,
      93,    88,   159,   159,  -237,  -237,  -237,  -237,  -237,   108,
      87,    38,   168,  -237,  -237,  -237,  -237,   159,    77,   159,
    -237,   159,   159,   159,    95,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,   141,   650,  -237,   650,   650,   650,   650,   650,
     650,   650,   650,   111,   609,   137,   119,  -237,   159,    77,
     122,  -237,   179,   159,  -237,  -237,  -237,   159,   126,  -237,
    -237,  -237,  -237,   130,  -237,  -237,  -237,   117,   134,  -237,
     143,  -237,   144,  -237,  -237,   156,   159,  -237,  -237,    38,
      46,  -237,  -237,  -237,    38,  -237,   157,  -237,  -237,  -237,
     136,    -7,   145,  -237,  -237,    37,   209,  -237,  -237,   743,
     154,   154,   154,   154,    65,    65,   154,   773,   629,  -237,
    -237,  -237,  -237,   137,  -237,   172,  -237,  -237,   173,    77,
     160,   497,   497,  -237,   159,  -237,   159,  -237,   180,  -237,
     159,   177,  -237,   159,  -237,  -237,  -237,   176,   178,  -237,
      10,  -237,   181,   159,  -237,   159,  -237,  -237,  -237,   166,
     166,   182,  -237,  -237,   210,  -237,    48,   163,   165,  -237,
    -237,  -237,  -237,   497,  -237,   194,   159,  -237,   193,    38,
    -237,   159,  -237,   183,  -237,  -237,  -237,   195,  -237,  -237,
     257,  -237,   497,   401,   159,   197,  -237,  -237,  -237,  -237,
     184,    42,  -237,  -237,   204,  -237,  -237,    38,  -237,  -237,
    -237,  -237,  -237,   616,   246,   203,   497,  -237,   180,  -237,
    -237,   461,   184,  -237,  -237,  -237,   497,  -237,  -237,    19,
     244,  -237,  -237,  -237,  -237,    48,    33,   357,  -237,  -237,
     255,  -237
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
    -237,  -237,    -2,  -237,  -237,  -237,   -26,   -33,  -237,  -237,
    -237,  -237,    54,    -4,     0,    25,    47,    50,  -237,   142,
     175,  -237,     1,    59,  -237,   -18,  -237,   236,  -237,  -237,
      20,    89,  -237,   152,   279,    63,     5,  -237,  -237,  -237,
    -237,  -237,  -237,  -215,  -204,    -1,    16,  -237,  -237,   -20,
    -236,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
     -15,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -164,  -237,
     -73,  -188,   -81,  -237,  -237,   129,   -10,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -134,  -237,  -237,   155,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -153,
    -237,  -237,  -237,  -237,  -233
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
     173,   173,    89,     4,   232,     4,     5,    36,   171,   175,
     252,   224,     4,     5,    36,    85,    86,     4,   282,    36,
     294,   111,    36,     5,   297,     3,   111,   135,   107,    37,
     146,   138,    11,   147,   110,   108,    37,    12,   139,    11,
     112,    37,   151,   155,    37,   135,   314,   109,   291,   113,
     -45,   259,   125,   126,   113,   266,   269,    82,    72,   -83,
      88,    15,     5,    16,   294,    14,   311,   260,   173,    92,
     168,   182,   307,   173,   134,   169,   110,    73,   262,   170,
     170,   284,   315,   298,    17,   135,   179,   137,    22,    24,
     308,    24,   184,   185,   186,    22,   200,   235,    24,   299,
     114,   127,   319,    24,   128,   210,   142,   274,   275,   102,
     131,    70,    25,    25,    35,    35,   143,   206,   144,   115,
     202,     4,     5,   189,   145,   190,   191,   192,   193,   194,
     195,   196,   197,   116,   117,   150,   118,   119,   120,    36,
      36,   152,   126,     4,     5,   121,   122,   170,    11,   154,
     156,   157,   170,     5,   166,   167,   187,   188,   173,   198,
     203,    37,    37,   207,  -186,    78,   288,   214,    80,    81,
      11,   216,    87,   218,    72,    12,    25,    99,    35,    70,
     219,    25,   233,    35,   220,   222,   173,   240,   237,    25,
      25,    35,    35,    73,   300,   231,    72,   223,   111,    15,
     168,    16,   234,    36,    22,   169,   242,    24,    36,   268,
     238,   239,   168,   101,   258,    73,    36,    36,   256,   259,
     273,   140,   261,   270,   174,    37,    22,    81,    87,    24,
      37,    25,   278,    35,   279,   285,   287,   170,    37,    37,
     289,   290,  -187,   296,   275,   256,   305,   160,   161,   306,
      25,    25,    35,    35,   317,   321,   316,   257,    36,   255,
     205,   132,   177,   263,   181,   170,   201,   236,    71,    59,
     106,    25,   304,    35,    25,   318,    35,    36,    36,    25,
      37,    35,   320,   230,    25,     0,    35,     0,   217,    59,
       0,   -23,     0,   177,   -23,    25,     0,    35,    36,    37,
      37,    36,   213,     0,   -88,     0,    36,     0,     0,     0,
     -23,    36,   -24,    59,   -23,   -24,     0,     0,     0,     0,
      37,   225,    36,    37,     0,   -89,   -25,    -4,    37,   -25,
      -4,   -24,     0,    37,     0,   -24,   101,     0,   243,   -90,
     -86,     4,     5,     0,    37,   -25,    -4,     0,     0,   -25,
      -4,     6,   102,     0,     0,     0,     7,     0,     8,     0,
       0,     0,     9,     0,     0,    10,     0,     0,    11,   250,
       0,   251,   309,    12,     0,   254,     0,     0,    99,     0,
       0,     0,   243,     0,     0,     4,     5,     0,   264,     0,
     265,    13,     0,     0,    14,     6,     0,    15,     0,    16,
       7,     0,     8,     0,     0,     0,     9,     0,   -83,    10,
       0,   286,    11,    17,     0,    18,   286,    12,     0,     0,
       0,    19,    20,    21,    22,     0,     0,    24,     0,   295,
       0,     0,     0,     0,     0,    13,     0,     0,    14,     0,
       0,    15,   243,    16,     0,     4,     5,     0,     0,     0,
       0,     0,   -83,     0,     0,     6,     0,    17,     0,    18,
       7,     0,     0,     4,     5,    19,    20,    21,    22,     0,
       0,    24,    11,     0,     0,     0,   309,    12,   243,     0,
       0,     4,     5,     0,     0,     0,     0,     0,     0,     0,
      11,     6,     0,     0,     0,    12,     7,     0,    14,     0,
       0,    15,     0,    16,     0,     0,     0,     0,    11,     0,
       0,     0,   -83,    12,     0,     0,    72,    17,     0,    15,
       0,    16,     0,     4,     5,    19,    20,    21,    22,     0,
     310,    24,     0,     6,    14,    73,   -83,    15,     7,    16,
       8,     0,     0,     0,     9,     0,    22,    10,   -83,    24,
      11,     0,     0,    17,     0,    12,     0,     0,     0,     0,
       0,    19,    20,    21,    22,     0,   244,    24,     0,     0,
       0,     0,     0,    13,     0,     0,    14,     0,     0,    15,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
     -83,     0,     0,     4,     5,    17,     0,    18,     0,     0,
       4,     5,     0,    19,    20,    21,    22,     0,    23,    24,
       6,     0,     0,     4,     5,     7,   303,     8,     0,     0,
      11,     9,     0,     6,    10,    12,     0,    11,     7,     0,
       0,     0,    12,     0,     4,     5,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    12,    14,     0,     0,    15,
      13,    16,     0,    14,     0,     0,    15,     0,    16,     0,
       0,    11,     0,     0,     0,    17,    14,     0,     0,    15,
       0,    16,    17,     0,    18,     0,    22,     0,     0,    24,
      19,    20,    21,    22,     0,    17,    24,    72,     0,     0,
      15,     0,    16,    19,    20,    21,    22,     0,  -181,    24,
     125,   126,     0,     0,     0,     0,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   127,
       0,     0,   128,   129,     0,   130,     0,     0,   131,   -56,
     125,   126,   116,   117,     0,   118,   119,   120,     0,     0,
       0,     0,     0,     0,   121,   122,     0,     0,   -56,   127,
       0,     0,   128,   129,     0,   130,     0,     0,   131,   -55,
       0,     0,   -56,   -56,     0,   -56,   -56,   -56,     0,     0,
       0,     0,     0,     0,   -56,   -56,     0,     0,   -55,   127,
       0,     0,   128,   129,     0,   130,     0,     0,   131,     0,
       0,     0,   -55,   -55,     0,   -55,   -55,   -55,     0,     0,
       0,     0,     0,     0,   -55,   -55
};

static const short int yycheck[] =
{
       2,     2,     2,    21,    30,     9,     8,     9,   212,     9,
      20,    21,    14,    12,    14,    17,    18,    17,     2,    14,
     101,   102,    17,     4,   177,     4,     5,     2,   101,   102,
     218,   165,     4,     5,     9,    15,    16,     4,   253,    14,
     273,     9,    17,     5,   280,     0,     9,    61,    57,     2,
      58,    57,    31,    61,    61,    64,     9,    36,    64,    31,
      28,    14,    58,    77,    17,    61,   302,    76,   272,    37,
      77,    61,     7,     8,    37,   239,   240,    14,    57,    58,
      17,    60,     5,    62,   317,    57,   301,    77,   169,    75,
      52,   109,   296,   174,    71,    57,    61,    76,   232,   101,
     102,   254,   306,    61,    76,    61,   108,    89,    87,    90,
     298,    90,   111,   112,   113,    87,   134,    80,    90,    77,
      36,    56,    89,    90,    59,   143,    57,    79,    80,    83,
      65,   135,   134,   135,   134,   135,    81,   139,    66,    55,
     135,     4,     5,   123,    66,   125,   126,   127,   128,   129,
     130,   131,   132,    69,    70,    58,    72,    73,    74,   134,
     135,    58,     8,     4,     5,    81,    82,   169,    31,    77,
      77,    83,   174,     5,    66,    88,    81,    36,   259,    68,
      61,   134,   135,    61,     5,    10,   259,    61,    13,    14,
      31,    61,    17,    76,    57,    36,   198,    22,   198,   203,
      66,   203,    66,   203,    61,    61,   287,   209,   203,   211,
     212,   211,   212,    76,   287,    58,    57,    61,     9,    60,
      52,    62,    77,   198,    87,    57,    66,    90,   203,   239,
      58,    58,    52,    67,    58,    76,   211,   212,    61,    61,
      30,    66,    61,    61,    76,   198,    87,    72,    73,    90,
     203,   253,    89,   253,    89,    61,    63,   259,   211,   212,
      77,    66,     5,    66,    80,    61,    20,    92,    93,    66,
     272,   273,   272,   273,    30,    20,   309,   223,   253,   220,
     138,    45,   107,   233,   109,   287,   134,   198,     9,   273,
     316,   293,   293,   293,   296,   315,   296,   272,   273,   301,
     253,   301,   317,   174,   306,    -1,   306,    -1,   153,   293,
      -1,    58,    -1,   138,    61,   317,    -1,   317,   293,   272,
     273,   296,   147,    -1,    71,    -1,   301,    -1,    -1,    -1,
      77,   306,    58,   317,    81,    61,    -1,    -1,    -1,    -1,
     293,   166,   317,   296,    -1,    71,    58,    58,   301,    61,
      61,    77,    -1,   306,    -1,    81,    67,    -1,     1,    71,
      71,     4,     5,    -1,   317,    77,    77,    -1,    -1,    81,
      81,    14,    83,    -1,    -1,    -1,    19,    -1,    21,    -1,
      -1,    -1,    25,    -1,    -1,    28,    -1,    -1,    31,   214,
      -1,   216,    35,    36,    -1,   220,    -1,    -1,   223,    -1,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,   233,    -1,
     235,    54,    -1,    -1,    57,    14,    -1,    60,    -1,    62,
      19,    -1,    21,    -1,    -1,    -1,    25,    -1,    71,    28,
      -1,   256,    31,    76,    -1,    78,   261,    36,    -1,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    90,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,
      -1,    60,     1,    62,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    14,    -1,    76,    -1,    78,
      19,    -1,    -1,     4,     5,    84,    85,    86,    87,    -1,
      -1,    90,    31,    -1,    -1,    -1,    35,    36,     1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    14,    -1,    -1,    -1,    36,    19,    -1,    57,    -1,
      -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    71,    36,    -1,    -1,    57,    76,    -1,    60,
      -1,    62,    -1,     4,     5,    84,    85,    86,    87,    -1,
      89,    90,    -1,    14,    57,    76,    77,    60,    19,    62,
      21,    -1,    -1,    -1,    25,    -1,    87,    28,    71,    90,
      31,    -1,    -1,    76,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,     4,     5,    76,    -1,    78,    -1,    -1,
       4,     5,    -1,    84,    85,    86,    87,    -1,    89,    90,
      14,    -1,    -1,     4,     5,    19,    20,    21,    -1,    -1,
      31,    25,    -1,    14,    28,    36,    -1,    31,    19,    -1,
      -1,    -1,    36,    -1,     4,     5,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    57,    -1,    -1,    60,
      54,    62,    -1,    57,    -1,    -1,    60,    -1,    62,    -1,
      -1,    31,    -1,    -1,    -1,    76,    57,    -1,    -1,    60,
      -1,    62,    76,    -1,    78,    -1,    87,    -1,    -1,    90,
      84,    85,    86,    87,    -1,    76,    90,    57,    -1,    -1,
      60,    -1,    62,    84,    85,    86,    87,    -1,    89,    90,
       7,     8,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    59,    60,    -1,    62,    -1,    -1,    65,    36,
       7,     8,    69,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    55,    56,
      -1,    -1,    59,    60,    -1,    62,    -1,    -1,    65,    36,
      -1,    -1,    69,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    55,    56,
      -1,    -1,    59,    60,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    92,   182,     0,     4,     5,    14,    19,    21,    25,
      28,    31,    36,    54,    57,    60,    62,    76,    78,    84,
      85,    86,    87,    89,    90,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   104,   105,   106,   107,   109,   111,
     112,   113,   116,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   136,   137,
     138,   142,   145,   148,   155,   163,   169,   175,    93,   154,
     104,   125,    57,    76,    93,   105,   106,   107,   111,   113,
     111,   111,   126,   127,   187,   121,   121,   111,   126,   127,
     188,    93,    75,   167,   116,   117,   167,   102,   103,   111,
     189,    67,    83,   159,   164,   174,    97,    57,    64,    76,
      61,     9,    28,    37,    36,    55,    69,    70,    72,    73,
      74,    81,    82,   118,   168,     7,     8,    56,    59,    60,
      62,    65,   118,   192,    71,    61,   172,    89,    57,    64,
     111,   176,    57,    81,    66,    66,    58,    61,   171,   173,
      58,    58,    58,   193,    77,    77,    77,    83,   157,   186,
     111,   111,   114,   115,   184,   191,    66,    88,    52,    57,
      93,   161,   162,   163,    76,   161,   110,   111,   183,    93,
     108,   111,   116,   167,   113,   113,   113,    81,    36,   121,
     121,   121,   121,   121,   121,   121,   121,   121,    68,   178,
     116,   124,   127,    61,   177,   110,    93,    61,   152,   181,
     116,   139,   143,   111,    61,   180,    61,   180,    76,    66,
      61,   190,    61,    61,   177,   111,   161,   165,   166,   185,
     166,    58,   190,    66,    77,    80,   122,   127,    58,    58,
      93,   153,    66,     1,    89,   134,   135,   137,   195,   135,
     111,   111,   162,   156,   111,   114,    61,   103,    58,    61,
      77,    61,   177,   108,   111,   111,   159,   160,   167,   159,
      61,   179,   146,    30,    79,    80,   140,   141,    89,    89,
     144,   194,   134,   158,   190,    61,   111,    63,   161,    77,
      66,   135,   136,   170,   195,   111,    66,   141,    61,    77,
     161,   149,   147,    20,   136,    20,    66,   135,   162,    35,
      89,   134,   150,   151,   141,   135,    98,    30,   140,    89,
     151,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    91,    92,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   101,
     102,   103,   104,   104,   104,   104,   104,   105,   105,   106,
     107,   108,   108,   109,   109,   110,   111,   112,   112,   113,
     113,   113,   113,   114,   115,   116,   116,   117,   117,   118,
     118,   118,   119,   119,   119,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   127,   127,   127,   127,
     127,   128,   129,   129,   129,   129,   129,   130,   131,   132,
     133,   133,   133,   133,   133,   134,   134,   134,   134,   135,
     136,   136,   137,   139,   138,   140,   140,   141,   141,   143,
     144,   142,   146,   147,   145,   149,   148,   150,   150,   150,
     151,   152,   152,   153,   153,   154,   156,   155,   157,   158,
     159,   160,   160,   161,   161,   161,   161,   162,   163,   164,
     165,   166,   166,   167,   168,   168,   168,   168,   168,   168,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   176,   176,   177,   177,
     178,   178,   179,   179,   180,   180,   181,   181,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
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
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,    21,     0,    19,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     5,     0,    31,
       7,    25,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     9,     0,     0,    35,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
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
#line 346 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE (MODULE, yylhs.all_values ());
                  yylhs.set_loc (NULL);
                  theTree = yylhs.value (); }
#line 1494 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 3:
#line 352 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1500 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 4:
#line 355 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1506 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 5:
#line 355 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_literal = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1512 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 6:
#line 355 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_enclosure = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1518 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 7:
#line 358 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_parenth_form = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1524 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 8:
#line 358 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_list_display = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1530 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 9:
#line 358 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_dict_display = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1536 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 10:
#line 362 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1542 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 11:
#line 363 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_INT_LITERAL = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1548 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 12:
#line 367 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_STRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1554 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 13:
#line 368 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_RAWSTRING = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1560 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 14:
#line 375 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_string_piece = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1566 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 15:
#line 377 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_string_piece = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yyv_stringliteral.value()->as_token()
                     ->append_text(yyv_string_piece.value()->as_token()
                                   ->string_text()); 
                  yylhs = yyv_stringliteral; }
#line 1575 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 16:
#line 383 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1581 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 17:
#line 385 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
#line 1587 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 18:
#line 389 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(LIST_DISPLAY, yylhs.all_values ()); }
#line 1593 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 19:
#line 393 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(DICT_DISPLAY, yylhs.all_values ()); }
#line 1599 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 20:
#line 396 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 1605 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 21:
#line 400 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PAIR, yylhs.all_values ()); }
#line 1611 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 22:
#line 403 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_atom = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1617 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 23:
#line 404 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_attributeref = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1623 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 24:
#line 405 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_subscription = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1629 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 25:
#line 406 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_slicing = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1635 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 26:
#line 407 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_call = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1641 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 27:
#line 412 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(ATTRIBUTEREF, yylhs.all_values ()); }
#line 1647 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 28:
#line 414 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(ATTRIBUTEREF, yylhs.all_values ()); }
#line 1653 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 29:
#line 418 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (SUBSCRIPTION, yyv_primary.value (),
                           yyv_expression_or_list.value (), 
                           make_id ("__getitem__", yyv_expression_or_list.loc ())); }
#line 1661 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 30:
#line 425 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_left = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_bound = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_right = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_bound = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (SLICING, yyv_primary.value (), 
                           yyv_left.value (), yyv_right.value (), 
                           make_id ("__getslice__", yyv_left.loc ())); }
#line 1669 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 31:
#line 431 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1675 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 32:
#line 432 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1681 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 33:
#line 436 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_argument_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); }
#line 1687 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 34:
#line 438 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_argument_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); }
#line 1693 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 35:
#line 443 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 1699 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 36:
#line 447 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_conditional_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1705 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 37:
#line 452 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_thenpart = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval); yyv_cond = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_elsepart = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF_EXPR, yyv_cond.value(), yyv_thenpart.value (), 
                          yyv_elsepart.value ()); }
#line 1712 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 38:
#line 455 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1718 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 39:
#line 460 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr2 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1724 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 40:
#line 461 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).mark_tree_op (); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1730 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 41:
#line 461 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).mark_tree_op (); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1736 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 42:
#line 463 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
#line 1742 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 43:
#line 468 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 1748 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 44:
#line 473 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
#line 1754 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 45:
#line 477 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1760 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 46:
#line 479 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
#line 1766 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 47:
#line 483 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1772 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 48:
#line 484 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1778 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 49:
#line 489 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = make_id(yylhs.all_values ()); }
#line 1784 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 50:
#line 491 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_op = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = make_id("isnot", yyv_op.loc()); }
#line 1790 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 51:
#line 493 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_op = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = make_id("notin", yyv_op.loc()); }
#line 1796 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 52:
#line 498 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_left_compare = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), COMPARE); }
#line 1802 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 53:
#line 500 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), COMPARE); }
#line 1808 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 54:
#line 501 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1814 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 55:
#line 506 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), LEFT_COMPARE); }
#line 1820 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 56:
#line 508 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_left_compare = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), LEFT_COMPARE); }
#line 1826 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 57:
#line 512 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1832 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 58:
#line 514 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
#line 1838 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 59:
#line 516 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
#line 1844 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 60:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1850 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 61:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1856 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 62:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1862 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 63:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1868 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 64:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1874 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 65:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1880 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 66:
#line 519 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values (), BINOP); }
#line 1886 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 67:
#line 524 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1892 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 68:
#line 525 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_assignment_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1898 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 69:
#line 526 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_pass_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1904 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 70:
#line 527 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_print_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1910 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 71:
#line 528 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_return_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1916 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 72:
#line 529 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_break_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1922 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 73:
#line 530 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_continue_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1928 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 74:
#line 533 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1934 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 75:
#line 538 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); }
#line 1940 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 76:
#line 540 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_assignment_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); }
#line 1946 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 77:
#line 544 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1952 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 78:
#line 545 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1958 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 79:
#line 546 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 1964 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 80:
#line 547 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1970 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 81:
#line 548 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 1976 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 82:
#line 550 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (TARGET_LIST, yylhs.all_values ()); }
#line 1982 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 83:
#line 555 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0);  }
#line 1988 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 84:
#line 555 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
#line 1994 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 85:
#line 557 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TARGET_LIST, yyv_target.value ()); }
#line 2000 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 86:
#line 561 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2006 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 87:
#line 563 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); }
#line 2012 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 88:
#line 564 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_attributeref = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2018 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 89:
#line 565 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_subscription = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2024 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 90:
#line 566 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_slicing = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2030 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 91:
#line 570 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(STMT_LIST); }
#line 2036 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 92:
#line 575 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_expression_list0_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); }
#line 2042 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 93:
#line 577 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yyv_expression.value (), YYMAKE_TREE(EXPR_LIST)); }
#line 2048 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 94:
#line 579 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); }
#line 2054 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 95:
#line 581 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); }
#line 2060 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 96:
#line 583 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); }
#line 2066 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 97:
#line 587 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).mark_tree_op (); yyv_expression_or_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);check_in_func (); }
#line 2072 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 98:
#line 590 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).mark_tree_op ();check_in_loop (); }
#line 2078 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 99:
#line 593 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).mark_tree_op ();check_in_loop (); }
#line 2084 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 100:
#line 597 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_if_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2090 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 101:
#line 598 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_while_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2096 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 102:
#line 599 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_for_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2102 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 103:
#line 600 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_funcdef = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2108 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 104:
#line 601 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_classdef = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2114 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 105:
#line 605 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2120 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 106:
#line 606 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2126 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 107:
#line 607 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2132 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 108:
#line 608 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2138 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 109:
#line 612 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); }
#line 2144 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 110:
#line 615 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2150 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 111:
#line 615 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_compound_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2156 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 112:
#line 619 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2162 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 113:
#line 624 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);incr (control_depth); }
#line 2168 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 114:
#line 627 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_elifs = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (control_depth); }
#line 2174 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 115:
#line 632 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_elifs = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (IF, yylhs.all_values ()); }
#line 2180 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 116:
#line 633 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2186 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 117:
#line 638 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(STMT_LIST); }
#line 2192 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 118:
#line 639 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2198 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 119:
#line 644 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);incr (control_depth); incr (loop_depth); }
#line 2204 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 120:
#line 646 "apyc.hn" /* glr.c:788  */
    { YYCTL(((*yyvalp)), 0, 0);  yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (loop_depth); }
#line 2210 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 121:
#line 648 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (control_depth); }
#line 2216 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 122:
#line 653 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);incr (control_depth); incr (loop_depth); }
#line 2222 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 123:
#line 655 "apyc.hn" /* glr.c:788  */
    { YYCTL(((*yyvalp)), 0, 0);  yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (loop_depth); }
#line 2228 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 124:
#line 657 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (control_depth); }
#line 2234 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 125:
#line 662 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_funcname = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval); yyv_parameter_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_opt_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);check_def_placement (); 
                  incr (defn_depth); incr (func_depth); }
#line 2241 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 126:
#line 665 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_funcbody = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (defn_depth); decr (func_depth); 
		  if (func_depth != 0 || defn_depth != 1)
		      yylhs = YYMAKE_TREE (DEF, yylhs.all_values ()); 
		  else
		      yylhs = YYMAKE_TREE (METHOD, yylhs.all_values ()); }
#line 2251 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 127:
#line 675 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 2257 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 128:
#line 676 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_native = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 2263 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 129:
#line 678 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_native = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
#line 2269 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 130:
#line 682 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2275 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 131:
#line 687 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(FORMALS_LIST); }
#line 2281 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 132:
#line 689 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(FORMALS_LIST, yylhs.all_values ()); }
#line 2287 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 133:
#line 693 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2293 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 134:
#line 694 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); }
#line 2299 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 135:
#line 697 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2305 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 136:
#line 700 "apyc.hn" /* glr.c:788  */
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval);check_class_placement (); incr (defn_depth); }
#line 2311 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 137:
#line 702 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); yyv_classbody = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);decr (defn_depth); }
#line 2317 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 138:
#line 707 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_FORMALS_LIST, yylhs.all_values ()); }
#line 2323 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 139:
#line 711 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CLASS_BLOCK, yylhs.all_values ()); }
#line 2329 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 140:
#line 714 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2335 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 141:
#line 718 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2341 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 142:
#line 719 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2347 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 143:
#line 723 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2353 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 144:
#line 725 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yyv_identifier, YYMAKE_TREE(TYPE_LIST)); }
#line 2359 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 145:
#line 726 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2365 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 146:
#line 728 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FUNCTION_TYPE, 
                          yyv_type.value (), yyv_type_list.value ()); }
#line 2372 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 147:
#line 733 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_TYPE_VAR = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE_VAR, yylhs.all_values ()); }
#line 2378 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 148:
#line 737 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_type_params = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yylhs.all_values ()); }
#line 2384 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 149:
#line 742 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
#line 2390 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 150:
#line 745 "apyc.hn" /* glr.c:788  */
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
#line 2396 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 151:
#line 750 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2402 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 152:
#line 751 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2408 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 153:
#line 756 "apyc.hn" /* glr.c:788  */
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(EMPTY); yylhs.set_loc (yysource_location ()); }
#line 2414 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 154:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2420 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 155:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2426 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 156:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2432 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 157:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2438 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 158:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2444 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 159:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2450 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 160:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2456 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 161:
#line 488 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2462 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 162:
#line 478 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2468 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 163:
#line 478 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2474 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 164:
#line 606 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2480 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 165:
#line 606 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2486 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 166:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2492 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 167:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2498 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 168:
#line 554 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2504 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 169:
#line 554 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2510 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 170:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2516 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 171:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2522 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 172:
#line 741 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2528 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 173:
#line 741 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2534 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 174:
#line 345 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2540 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 175:
#line 345 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2546 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 176:
#line 348 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2552 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 177:
#line 478 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2558 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 178:
#line 481 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2564 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 179:
#line 396 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2570 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 180:
#line 399 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2576 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 181:
#line 619 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2582 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 182:
#line 622 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2588 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 183:
#line 688 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2594 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 184:
#line 691 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2600 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 185:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2606 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 186:
#line 387 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2612 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 187:
#line 688 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval); }
#line 2618 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 188:
#line 691 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2624 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 189:
#line 345 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2630 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 190:
#line 348 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2636 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 191:
#line 441 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2642 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 192:
#line 444 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2648 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 193:
#line 472 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2654 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 194:
#line 475 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2660 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 195:
#line 746 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2666 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 196:
#line 749 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),0,0);  }
#line 2672 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 197:
#line 706 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval).ignore(); }
#line 2678 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 198:
#line 709 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2684 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 199:
#line 384 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2690 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 200:
#line 387 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2696 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 201:
#line 388 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2702 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 202:
#line 391 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  }
#line 2708 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 203:
#line 392 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_key_datum_list = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2714 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 204:
#line 395 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2720 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 205:
#line 441 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2726 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 206:
#line 444 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_key_datum = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2732 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 207:
#line 396 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_key_datum = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2738 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 208:
#line 399 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_simple_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2744 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 209:
#line 619 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_simple_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2750 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 210:
#line 622 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2756 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 211:
#line 388 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2762 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 212:
#line 391 "apyc.hn" /* glr.c:788  */
    { YYCTLPC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2768 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 213:
#line 706 "apyc.hn" /* glr.c:788  */
    { YYCTLC(((*yyvalp)),3,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval).ignore(); yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval); }
#line 2774 "apyc-parser.cc" /* glr.c:788  */
    break;

  case 214:
#line 711 "apyc.hn" /* glr.c:788  */
    { ((*yyvalp))._clear (); }
#line 2780 "apyc-parser.cc" /* glr.c:788  */
    break;


#line 2784 "apyc-parser.cc" /* glr.c:788  */
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
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2832 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 4: /* STRING  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2838 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 5: /* ID  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2844 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 6: /* "@unop"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2850 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 7: /* "//"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2856 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 8: /* "**"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2862 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 9: /* "and"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2868 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 10: /* "@assign"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2874 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 11: /* "@attributeref"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2880 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 12: /* "@binop"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2886 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 13: /* "@block"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2892 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 14: /* "break"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2898 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 15: /* "@call"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2904 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 16: /* "@@block"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2910 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 17: /* "@compare"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2916 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 18: /* "@left_compare"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2922 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 19: /* "continue"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2928 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 20: /* DEDENT  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2934 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 21: /* "def"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2940 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 22: /* "@dict_display"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2946 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 23: /* EMPTY  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2952 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 24: /* "@expr_list"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2958 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 25: /* "for"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2964 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 26: /* "@formals_list"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2970 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 27: /* "@function_type"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2976 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 28: /* "if"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2982 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 29: /* "@if_expr"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2988 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 30: /* INDENT  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 2994 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 31: /* "@int_literal"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3000 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 32: /* "@list_display"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3006 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 33: /* "@def"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3012 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 34: /* "@module"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3018 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 35: /* "native"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3024 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 36: /* "not"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3030 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 37: /* "or"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3036 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 38: /* "@pair"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3042 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 39: /* "@print"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3048 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 40: /* "@println"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3054 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 41: /* "@slicing"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3060 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 42: /* "@@slicing"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3066 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 43: /* "@stmt_list"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3072 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 44: /* STRING_LITERAL  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3078 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 45: /* "@subscription"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3084 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 46: /* "@@subscription"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3090 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 47: /* "@target_list"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3096 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 48: /* "@type_formals_list"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3102 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 49: /* "@tuple"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3108 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 50: /* "@type"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3114 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 51: /* "@type_list"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3120 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 52: /* "@type_var"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3126 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 53: /* "@typed_id"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3132 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 54: /* "while"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3138 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 55: /* "!="  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3144 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 56: /* "%"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3150 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 57: /* "("  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3156 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 58: /* ")"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3162 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 59: /* "*"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3168 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 60: /* "+"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3174 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 61: /* ","  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3180 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 62: /* "-"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3186 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 63: /* "->"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3192 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 64: /* "."  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3198 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 65: /* "/"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3204 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 66: /* ":"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3210 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 67: /* "::"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3216 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 68: /* ";"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3222 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 69: /* "<"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3228 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 70: /* "<="  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3234 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 71: /* "="  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3240 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 72: /* "=="  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3246 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 73: /* ">"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3252 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 74: /* ">="  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3258 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 75: /* ">>"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3264 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 76: /* "["  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3270 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 77: /* "]"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3276 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 78: /* "class"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3282 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 79: /* "elif"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3288 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 80: /* "else"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3294 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 81: /* "in"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3300 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 82: /* "is"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3306 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 83: /* "of"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3312 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 84: /* "pass"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3318 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 85: /* "print"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3324 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 86: /* "return"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3330 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 87: /* "{"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3336 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 88: /* "}"  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3342 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 89: /* NEWLINE  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3348 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 90: /* RAWSTRING  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3354 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 92: /* program  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3360 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 93: /* identifier  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3366 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 94: /* atom  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3372 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 95: /* enclosure  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3378 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 96: /* literal  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3384 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 97: /* string_piece  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3390 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 98: /* stringliteral  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3396 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 99: /* parenth_form  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3402 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 100: /* list_display  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3408 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 101: /* dict_display  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3414 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 102: /* key_datum_list  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3420 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 103: /* key_datum  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3426 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 104: /* primary  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3432 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 105: /* attributeref  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3438 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 106: /* subscription  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3444 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 107: /* slicing  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3450 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 108: /* bound  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3456 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 109: /* call  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3462 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 110: /* argument_list  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3468 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 111: /* expression  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3474 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 112: /* conditional_expression  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3480 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 113: /* expr1  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3486 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 114: /* expression_list_no_comma  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3492 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 115: /* expression_list0_no_comma  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3498 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 116: /* expression_or_list  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3504 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 117: /* expression_or_list0  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3510 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 118: /* comp_operator  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3516 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 119: /* expr2  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3522 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 120: /* left_compare  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3528 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 121: /* expr3  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3534 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 122: /* simple_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3540 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 123: /* expression_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3546 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 124: /* assignment_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3552 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 125: /* target_list  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3558 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 126: /* target_list1  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3564 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 127: /* target  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3570 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 128: /* pass_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3576 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 129: /* print_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3582 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 130: /* return_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3588 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 131: /* break_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3594 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 132: /* continue_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3600 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 133: /* compound_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3606 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 134: /* stmts  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3612 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 135: /* suite  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3618 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 136: /* statement  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3624 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 137: /* stmt_list  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3630 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 138: /* if_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3636 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 139: /* @1  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3642 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 140: /* elifs  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3648 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 141: /* else_clause  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3654 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 142: /* while_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3660 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 143: /* @2  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3666 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 144: /* @3  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3672 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 145: /* for_stmt  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3678 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 146: /* @4  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3684 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 147: /* @5  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3690 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 148: /* funcdef  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3696 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 149: /* @6  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3702 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 150: /* funcbody  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3708 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 151: /* native  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3714 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 152: /* parameter_list  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3720 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 153: /* parameter  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3726 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 154: /* funcname  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3732 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 155: /* classdef  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3738 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 156: /* @7  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3744 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 157: /* type_formals  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3750 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 158: /* classbody  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3756 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 159: /* type_annotation  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3762 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 160: /* opt_type_annotation  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3768 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 161: /* type  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3774 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 162: /* type_var  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3780 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 163: /* parameterized_type  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3786 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 164: /* type_params  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3792 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 165: /* type_list  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3798 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 166: /* types  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3804 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 167: /* empty  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3810 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 168: /* __0  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3816 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 169: /* __1  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3822 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 170: /* __2  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3828 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 171: /* __3  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3834 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 172: /* __4  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3840 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 173: /* __5  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3846 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 174: /* __6  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3852 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 175: /* __7  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3858 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 176: /* __8  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3864 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 177: /* __9  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3870 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 178: /* __10  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3876 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 179: /* __11  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3882 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 180: /* __12  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3888 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 181: /* __13  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3894 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 182: /* __14  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3900 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 183: /* __15  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3906 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 184: /* __16  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3912 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 185: /* __17  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3918 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 186: /* __18  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3924 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 187: /* __19  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3930 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 188: /* __20  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3936 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 189: /* __21  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3942 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 190: /* __22  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3948 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 191: /* __23  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3954 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 192: /* __24  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3960 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 193: /* __25  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3966 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 194: /* __26  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3972 "apyc-parser.cc" /* glr.c:818  */
        break;

    case 195: /* __error__  */
#line 263 "apyc-parser.y" /* glr.c:818  */
      { ((*yyvaluep))._destructor (); }
#line 3978 "apyc-parser.cc" /* glr.c:818  */
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
  (!!((Yystate) == (-237)))

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



#line 1413 "apyc-parser.y" /* glr.c:2549  */



#line 759 "apyc.hn"


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


#line 1654 "apyc-parser.y"

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
