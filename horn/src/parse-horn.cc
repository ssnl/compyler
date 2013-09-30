/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 3 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"

/* Horn Grammar Parser: A Front End for Bison

   Copyright (C) 2010 by Paul N. Hilfinger and the Regents of the
   University of California.
   Distributable under the terms of the original license, shown below.

*/


		/* Original Copyright and License Message */

/* Bison Grammar Parser                             -*- C -*-

   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

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


/* Line 268 of yacc.c  */
#line 163 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"

#include "horn.h"

/* Request detailed syntax error messages, and pass them to GRAM_ERROR.
   FIXME: depends on the undocumented availability of YYLLOC.  */
#undef  yyerror
#define yyerror(Msg) \
	complain_at (yylloc, " %s", Msg)
#define YYLLOC_DEFAULT(Current, Rhs, N)					     \
   do { 								     \
     if (N)								     \
         (Current) = YYRHSLOC(Rhs, 1);					     \
     else								     \
         (Current) = YYRHSLOC(Rhs, 0);					     \
   } while (0)

static int yylex ();
extern int gram_scan ();

static std::string strip_quotes (const std::string& s);

static void add_lexical_option (NodePtr);
static void make_plain_lexical_rule ();
static void make_lexical_rule (NodePtr, NodePtr);
static NodePtr make_rhses (NodePtr syms);
static NodePtr stripped (NodePtr action);

#define APPEND(L, Item)  ((L)->as_list ()->dadd (Item))

#define YYSTYPE NodePtr

static NodePtr theTree;
static NodePtr rule_annotations;
static bool expand_rule;
static bool preferred_lexical_rule;
static NodePtr lexical_lhs, lexical_rhs;

static void excluded_feature (const std::string& name);



/* Line 268 of yacc.c  */
#line 148 "parse-horn.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     GRAM_EOF = 0,
     STRING = 258,
     INT = 259,
     PERCENT_TOKEN = 260,
     PERCENT_NTERM = 261,
     PERCENT_TYPE = 262,
     PERCENT_DESTRUCTOR = 263,
     PERCENT_PRINTER = 264,
     PERCENT_LEFT = 265,
     PERCENT_RIGHT = 266,
     PERCENT_NONASSOC = 267,
     PERCENT_PRECEDENCE = 268,
     PERCENT_PREC = 269,
     PERCENT_DPREC = 270,
     PERCENT_MERGE = 271,
     PERCENT_CODE = 272,
     PERCENT_DEFAULT_PREC = 273,
     PERCENT_DEFINE = 274,
     PERCENT_DEFINES = 275,
     PERCENT_ERROR_VERBOSE = 276,
     PERCENT_EXPECT = 277,
     PERCENT_EXPECT_RR = 278,
     PERCENT_FLAG = 279,
     PERCENT_FILE_PREFIX = 280,
     PERCENT_GLR_PARSER = 281,
     PERCENT_INTERACTIVE = 282,
     PERCENT_INITIAL_ACTION = 283,
     PERCENT_LANGUAGE = 284,
     PERCENT_NAME_PREFIX = 285,
     PERCENT_NO_DEFAULT_PREC = 286,
     PERCENT_NO_LINES = 287,
     PERCENT_NONDETERMINISTIC_PARSER = 288,
     PERCENT_OUTPUT = 289,
     PERCENT_REQUIRE = 290,
     PERCENT_SKELETON = 291,
     PERCENT_START = 292,
     PERCENT_TOKEN_TABLE = 293,
     PERCENT_VERBOSE = 294,
     PERCENT_YACC = 295,
     PERCENT_EXPAND = 296,
     PERCENT_PREFER = 297,
     PERCENTS = 298,
     ANY = 299,
     BOL = 300,
     EOL = 301,
     ENDFILE = 302,
     BRACED_CODE = 303,
     BRACED_PREDICATE = 304,
     CHAR = 305,
     DOTDOT = 306,
     EPILOGUE = 307,
     ID = 308,
     UPPER_ID = 309,
     LOWER_ID = 310,
     UNDERSCORE_ID = 311,
     OTHER_ID = 312,
     PERCENT_PERCENT = 313,
     PLUS_EQ = 314,
     PROLOGUE = 315,
     TAG = 316,
     TAG_ANY = 317,
     TAG_NONE = 318,
     PERCENT_PARAM = 319,
     NONE = 320,
     GRAMMAR = 321,
     RULES = 322,
     RULE = 323,
     GRAMMAR_DECLARATION = 324,
     RHS_CHOICES = 325,
     RHS_ANNOTATIONS = 326,
     RHS = 327,
     GENERATED_RULE = 328,
     ACTION = 329,
     TOKEN_TAG = 330,
     LIST_TAG = 331,
     LEX_GROUP = 332,
     LEX_OPT = 333,
     LEX_PHRASE = 334,
     LEX_PLUS = 335,
     LEX_SET = 336,
     LEX_SUB = 337,
     LEX_RULE = 338,
     LEX_RULE_PREFERRED = 339,
     LEX_STAR = 340,
     LEX_SUBRULE = 341,
     LEX_STRING = 342,
     LEX_REF = 343,
     SYNC = 344,
     PERCENT_UNION = 345
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 294 "parse-horn.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNRULES -- Number of states.  */
#define YYNSTATES  243

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,     2,     2,     2,
      64,    65,    67,    68,     2,    69,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    66,
       2,    54,     2,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    62,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    52,    53,    55,    56,
      57,    58,    59,    60,    61,    63,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    10,    11,    14,    18,    20,    22,
      24,    26,    30,    32,    35,    37,    40,    43,    46,    48,
      50,    53,    56,    59,    61,    63,    66,    69,    72,    75,
      77,    79,    81,    83,    86,    88,    90,    92,    95,    99,
     103,   105,   107,   110,   114,   115,   117,   121,   124,   127,
     131,   135,   137,   139,   141,   143,   144,   146,   148,   151,
     153,   156,   158,   161,   163,   166,   168,   170,   172,   174,
     176,   178,   181,   184,   187,   191,   193,   196,   200,   202,
     205,   207,   210,   212,   215,   218,   223,   225,   227,   231,
     233,   235,   238,   241,   244,   247,   250,   251,   254,   256,
     259,   262,   265,   267,   270,   273,   277,   279,   283,   287,
     290,   293,   296,   298,   300,   302,   303,   305,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   336,   339,   340,   346,   347,   353,   358,
     363,   368,   370,   374,   376,   380,   385,   391,   393,   396,
     398,   402,   404,   406,   409,   412,   415,   417,   421,   423,
     425,   427,   431,   432,   434,   436,   440,   444,   445,   447,
     449,   451
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,   105,    60,   121,   140,    -1,     1,    -1,
      -1,   105,   106,    -1,   105,   106,     1,    -1,     1,    -1,
     108,    -1,    63,    -1,    24,    -1,    19,   132,   133,    -1,
      20,    -1,    20,     3,    -1,    21,    -1,    22,     4,    -1,
      23,     4,    -1,    25,     3,    -1,    26,    -1,    27,    -1,
      28,    48,    -1,    29,     3,    -1,    30,     3,    -1,    32,
      -1,    33,    -1,    34,     3,    -1,    76,   107,    -1,    35,
       3,    -1,    36,     3,    -1,    38,    -1,    39,    -1,    40,
      -1,    66,    -1,   107,    48,    -1,    48,    -1,   111,    -1,
     110,    -1,    37,   137,    -1,     8,    48,   117,    -1,     9,
      48,   117,    -1,    18,    -1,    31,    -1,    17,   134,    -1,
      17,   135,   134,    -1,    -1,   135,    -1,   102,   109,   134,
      -1,     6,   120,    -1,     5,   120,    -1,     7,    73,   116,
      -1,   112,   113,   114,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    -1,    73,    -1,   115,    -1,   114,   115,
      -1,   137,    -1,   137,     4,    -1,   137,    -1,   116,   137,
      -1,   118,    -1,   117,   118,    -1,   137,    -1,    73,    -1,
      74,    -1,    75,    -1,    56,    -1,    50,    -1,    56,     4,
      -1,    56,   139,    -1,    50,   139,    -1,    56,     4,   139,
      -1,    73,    -1,    50,     4,    -1,    50,     4,   139,    -1,
     119,    -1,   120,   119,    -1,   122,    -1,   121,   122,    -1,
     123,    -1,   108,    66,    -1,     1,    66,    -1,    57,    51,
     124,    66,    -1,   141,    -1,   125,    -1,   124,    62,   125,
      -1,   127,    -1,   126,    -1,   128,   127,    -1,   155,   127,
      -1,   128,   126,    -1,   155,   126,    -1,   131,   126,    -1,
      -1,   131,   127,    -1,   129,    -1,   129,    70,    -1,   129,
      67,    -1,   129,    68,    -1,   130,    -1,   130,    71,    -1,
     130,    72,    -1,    64,   124,    65,    -1,   138,    -1,   135,
      54,   138,    -1,   135,    61,   138,    -1,    14,   137,    -1,
      15,     4,    -1,    16,    73,    -1,    41,    -1,   135,    -1,
      59,    -1,    -1,   135,    -1,     3,    -1,    48,    -1,    56,
      -1,    57,    -1,    58,    -1,   135,    -1,    50,    -1,   136,
      -1,   139,    -1,    56,    -1,    57,    -1,    50,    -1,   139,
      -1,    58,    -1,     3,    -1,    -1,    60,    53,    -1,    -1,
      56,    51,   142,   144,    66,    -1,    -1,    67,    51,   143,
     144,    66,    -1,    58,    51,   145,    66,    -1,     3,    51,
     155,    66,    -1,    50,    51,   155,    66,    -1,   146,    -1,
     144,    62,   146,    -1,   147,    -1,   145,    62,   147,    -1,
     152,   147,   153,   156,    -1,   152,   154,    47,   154,   156,
      -1,   148,    -1,   147,   148,    -1,   149,    -1,   148,    69,
     149,    -1,   150,    -1,   151,    -1,   150,    67,    -1,   150,
      68,    -1,   150,    70,    -1,    58,    -1,    64,   145,    65,
      -1,    50,    -1,     3,    -1,    44,    -1,    50,    52,    50,
      -1,    -1,    45,    -1,   154,    -1,   154,    46,   154,    -1,
     154,    47,   154,    -1,    -1,    42,    -1,    48,    -1,    48,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   213,   213,   216,   225,   226,   228,   230,   234,   235,
     236,   237,   281,   282,   283,   284,   285,   286,   288,   289,
     291,   292,   293,   294,   295,   296,   298,   299,   300,   301,
     302,   303,   304,   308,   309,   318,   319,   320,   321,   323,
     325,   326,   327,   328,   339,   340,   344,   349,   350,   351,
     355,   360,   361,   362,   363,   367,   368,   374,   375,   379,
     380,   385,   386,   390,   391,   396,   397,   398,   399,   404,
     405,   406,   408,   410,   412,   414,   416,   419,   425,   426,
     435,   436,   443,   444,   445,   449,   452,   456,   457,   461,
     462,   466,   467,   468,   469,   470,   474,   475,   479,   480,
     481,   482,   486,   487,   491,   493,   497,   498,   499,   503,
     505,   507,   508,   516,   517,   522,   523,   524,   533,   542,
     543,   544,   548,   549,   553,   554,   558,   559,   560,   562,
     564,   574,   578,   579,   587,   587,   589,   589,   591,   598,
     600,   605,   606,   610,   611,   617,   626,   633,   634,   638,
     639,   645,   646,   647,   648,   649,   653,   654,   655,   656,
     657,   665,   669,   670,   674,   675,   676,   679,   681,   685,
     690,   691
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"",
  "\"%precedence\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
  "\"%glr-parser\"", "\"%interactive\"", "\"%initial-action\"",
  "\"%language\"", "\"%name-prefix\"", "\"%no-default-prec\"",
  "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
  "\"%require\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
  "\"%verbose\"", "\"%yacc\"", "\"%expand\"", "\"%prefer\"", "PERCENTS",
  "\"_ANY\"", "\"_BOL\"", "\"_EOL\"", "\"_EOF\"", "\"{...}\"",
  "\"%?{...}\"", "\"char\"", "\":\"", "\"..\"", "\"epilogue\"", "\"=\"",
  "ID", "UPPER_ID", "LOWER_ID", "UNDERSCORE_ID", "OTHER_ID", "\"%%\"",
  "\"+=\"", "\"|\"", "\"%{...%}\"", "\"(\"", "\")\"", "\";\"", "\"*\"",
  "\"+\"", "\"-\"", "\"?\"", "\"^\"", "\"!\"", "\"<tag>\"", "\"<*>\"",
  "\"<>\"", "\"%param\"", "\"*none*\"", "\"*grammar*\"", "\"*rules*\"",
  "\"*rule*\"", "\"*grammar_declaration*\"", "\"*rhs_choices*\"",
  "\"*rhs_annotations*\"", "\"*rhs*\"", "\"*generated-rule*\"",
  "\"*action*\"", "\"*token*\"", "\"*list*\"", "LEX_GROUP", "LEX_OPT",
  "LEX_PHRASE", "LEX_PLUS", "LEX_SET", "LEX_SUB", "LEX_RULE",
  "LEX_RULE_PREFERRED", "LEX_STAR", "LEX_SUBRULE", "LEX_STRING", "LEX_REF",
  "SYNC", "\"%union\"", "$accept", "input", "prologue_declarations",
  "prologue_declaration", "params", "grammar_declaration", "union_name",
  "symbol_declaration", "precedence_declaration", "precedence_declarator",
  "tag.opt", "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
  "rules_or_grammar_declaration", "rules", "rhses", "rhs", "rhs.1",
  "rhs.2", "rhs.primary", "rhs.atom", "augmented_symbol", "annotation",
  "variable", "content.opt", "braceless", "any_id", "id", "symbol",
  "cf_symbol", "string_as_id", "epilogue.opt", "lexical_rule", "$@1",
  "$@2", "lexical_rhs", "lexical_rhs_no_rules", "lexical_rhs_primaries",
  "lexical_primaries", "lexical_term", "lexical_primary", "lexical_atom",
  "char_range", "lexical_prefix", "lexical_suffix", "preferred.opt",
  "action", "bare_action.opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    58,   306,   307,    61,   308,   309,   310,   311,   312,
     313,   314,   124,   315,    40,    41,    59,    42,    43,    45,
      63,    94,    33,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   108,   110,   110,   110,
     111,   112,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   127,   127,   128,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   130,   131,
     131,   131,   131,   132,   132,   133,   133,   133,   134,   135,
     135,   135,   136,   136,   137,   137,   138,   138,   138,   138,
     138,   139,   140,   140,   142,   141,   143,   141,   141,   141,
     141,   144,   144,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   149,   149,   149,   150,   150,   150,   150,
     150,   151,   152,   152,   153,   153,   153,   154,   154,   155,
     156,   156
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     2,     3,     1,     1,     1,
       1,     3,     1,     2,     1,     2,     2,     2,     1,     1,
       2,     2,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     2,     3,     3,
       1,     1,     2,     3,     0,     1,     3,     2,     2,     3,
       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     2,     4,     1,     1,     3,     1,
       1,     2,     2,     2,     2,     2,     0,     2,     1,     2,
       2,     2,     1,     2,     2,     3,     1,     3,     3,     2,
       2,     2,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     5,     0,     5,     4,     4,
       4,     1,     3,     1,     3,     4,     5,     1,     2,     1,
       3,     1,     1,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     0,     1,     1,     3,     3,     0,     1,     1,
       1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     1,     0,     0,     0,     0,     0,
      51,    52,    53,    54,     0,    40,     0,    12,    14,     0,
       0,    10,     0,    18,    19,     0,     0,     0,    41,    23,
      24,     0,     0,     0,     0,    29,    30,    31,     0,     9,
      32,     0,    44,     0,     8,    36,    35,    55,    70,    69,
      75,    78,    48,    47,     0,     0,     0,   118,   119,   120,
     121,    42,     0,   114,   115,   113,    13,    15,    16,    17,
      20,    21,    22,    25,    27,    28,   131,   123,   122,   124,
      37,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    82,    86,    34,    26,     0,    45,     6,    56,
       0,    76,    73,    71,    72,    79,    49,    61,    66,    67,
      68,    38,    63,    65,    39,    43,   117,    11,   116,    84,
       0,     0,   134,    96,     0,   136,    83,     0,    81,     2,
      33,    46,    50,    57,    59,    77,    74,    62,    64,   169,
       0,     0,   162,     0,     0,     0,   112,   128,   126,   127,
     130,    96,     0,    87,    90,    89,    96,    98,   102,    96,
       0,   106,   129,    96,   159,   160,   158,   156,     0,     0,
     143,   147,   149,   151,   152,   162,   133,    58,    60,   139,
     140,   163,     0,   141,   167,   109,   110,   111,     0,    96,
      85,    93,    91,   100,   101,    99,   103,   104,    95,    97,
       0,     0,    94,    92,     0,     0,     0,   138,   148,     0,
     153,   154,   155,     0,   162,   135,   168,   167,     0,   105,
      88,   126,   127,   130,   107,   108,   161,   157,   144,   150,
     137,   142,   171,   164,   167,   170,   145,   167,   167,   171,
     165,   166,   146
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    43,    95,    89,    96,    45,    46,    47,
     100,   132,   133,   106,   111,   112,    51,    52,    90,    91,
      92,   152,   153,   154,   155,   156,   157,   158,   159,    64,
     117,    61,    78,    79,   113,   161,    81,   129,    93,   142,
     175,   182,   169,   183,   170,   171,   172,   173,   174,   184,
     232,   218,   163,   236
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -191
static const yytype_int16 yypact[] =
{
     159,    19,    24,   371,  -191,   -30,   -30,   -40,    18,    41,
    -191,  -191,  -191,  -191,   -19,  -191,    95,    56,  -191,    87,
      99,  -191,   113,  -191,  -191,    83,   145,   154,  -191,  -191,
    -191,   199,   212,   213,    67,  -191,  -191,  -191,   285,  -191,
    -191,   169,    82,   245,  -191,  -191,  -191,   147,   170,   202,
    -191,  -191,   -30,   -30,    67,    27,    27,  -191,  -191,  -191,
    -191,  -191,   173,  -191,    37,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,   152,   172,   175,   176,   177,   178,   179,   158,
       5,  -191,  -191,  -191,  -191,   183,   173,  -191,  -191,  -191,
      67,   229,  -191,   229,  -191,  -191,    67,  -191,  -191,  -191,
    -191,    27,  -191,  -191,    27,  -191,  -191,  -191,  -191,  -191,
     185,   185,  -191,    72,    77,  -191,  -191,   181,  -191,  -191,
    -191,  -191,    67,  -191,   232,  -191,  -191,  -191,  -191,  -191,
     171,   174,   193,    67,   235,   168,  -191,  -191,   -29,    -9,
      43,    72,    46,  -191,  -191,  -191,    72,     1,   136,    72,
      44,  -191,  -191,    72,  -191,  -191,   190,  -191,    77,    53,
      77,   180,  -191,    91,  -191,   193,  -191,  -191,  -191,  -191,
    -191,  -191,    81,  -191,    32,  -191,  -191,  -191,   -11,    72,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
      76,    76,  -191,  -191,   194,   138,    77,  -191,   180,    77,
    -191,  -191,  -191,    84,   193,  -191,  -191,    32,   196,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,    77,  -191,
    -191,  -191,   197,   116,   205,  -191,  -191,   205,   205,   197,
    -191,  -191,  -191
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,  -191,  -191,  -191,   256,  -191,  -191,  -191,  -191,
    -191,  -191,   128,  -191,   192,    90,   157,   281,  -191,   209,
    -191,   149,   100,  -110,   -99,  -191,  -191,  -191,  -191,  -191,
    -191,   -55,   -14,  -191,   -33,    11,   -45,  -191,  -191,  -191,
    -191,   126,   139,    92,  -175,  -136,   101,  -191,  -191,  -191,
    -191,  -190,    93,    65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -133
static const yytype_int16 yytable[] =
{
      62,    80,    65,   102,   104,  -132,    82,   115,    83,   217,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -3,
      48,   107,    14,    15,     4,  -119,    49,   233,    97,    57,
      76,   228,  -119,    54,   208,   164,    28,    58,    59,    60,
     116,   131,    34,    50,   239,  -120,   191,   240,   241,   198,
     118,   189,  -120,   202,   219,    84,   135,   192,   136,    66,
     199,    85,    86,    87,   203,   127,    55,   134,   193,   194,
      76,   195,    88,   137,   216,    76,   165,    77,   162,    76,
     164,   208,   166,    58,    59,    60,   143,   144,   145,    56,
     167,    67,   208,    58,    59,    60,   168,  -121,   200,   134,
     108,   109,   110,    68,  -121,   201,   162,    42,   189,   160,
     185,   162,   190,   146,   162,   206,    69,    77,   162,   207,
     139,   165,   147,    58,    59,    60,   147,   166,   148,   149,
     150,    70,   221,   222,   223,   167,   151,   160,    58,    59,
      60,   168,   160,   214,   162,   160,   214,   215,    71,   160,
     230,    58,    59,    60,    63,   162,   162,    72,   210,   211,
       1,   212,   237,   238,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    76,   101,   160,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
     206,   138,    73,   227,   138,    76,   103,   196,   197,   105,
     105,   224,   225,   140,   141,    74,    75,    94,   119,    -4,
      99,    57,    -4,   120,   126,    -4,   121,   122,   123,   124,
     125,   130,    76,   139,   176,    -4,   178,   179,   181,   186,
     180,   187,   204,   234,   226,   235,    98,   216,   114,   209,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    44,
     177,    -4,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    82,    53,    83,   220,
       5,     6,     7,     8,     9,    10,    11,    12,    13,   128,
     188,   213,    14,    15,   242,    -5,   231,   205,    -5,     0,
     229,    -5,     0,     0,     0,     0,    28,     0,     0,     0,
       0,    -5,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,    85,    86,    87,     0,     0,     0,    -5,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,    42,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,    39,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-191))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      14,    34,    16,    48,    49,     0,     1,    62,     3,   184,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      50,    54,    17,    18,     0,    54,    56,   217,    42,    48,
       3,   206,    61,    73,   170,     3,    31,    56,    57,    58,
       3,    96,    37,    73,   234,    54,   156,   237,   238,   159,
      64,    62,    61,   163,    65,    50,   101,   156,   103,     3,
     159,    56,    57,    58,   163,    60,    48,   100,    67,    68,
       3,    70,    67,   106,    42,     3,    44,    50,   123,     3,
       3,   217,    50,    56,    57,    58,    14,    15,    16,    48,
      58,     4,   228,    56,    57,    58,    64,    54,    54,   132,
      73,    74,    75,     4,    61,    61,   151,   102,    62,   123,
     143,   156,    66,    41,   159,    62,     3,    50,   163,    66,
      48,    44,    50,    56,    57,    58,    50,    50,    56,    57,
      58,    48,    56,    57,    58,    58,    64,   151,    56,    57,
      58,    64,   156,    62,   189,   159,    62,    66,     3,   163,
      66,    56,    57,    58,    59,   200,   201,     3,    67,    68,
       1,    70,    46,    47,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     3,     4,   189,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      62,   111,     3,    65,   114,     3,     4,    71,    72,    52,
      53,   200,   201,   120,   121,     3,     3,    48,    66,    60,
      73,    48,    63,    51,    66,    66,    51,    51,    51,    51,
      51,    48,     3,    48,    53,    76,     4,    66,    45,     4,
      66,    73,    52,    47,    50,    48,     1,    42,    56,    69,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
     132,   102,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     1,     6,     3,   189,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    90,
     151,   175,    17,    18,   239,    60,   214,   168,    63,    -1,
     209,    66,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    76,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,   102,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    63,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   104,   105,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    60,    63,
      66,    76,   102,   106,   108,   110,   111,   112,    50,    56,
      73,   119,   120,   120,    73,    48,    48,    48,    56,    57,
      58,   134,   135,    59,   132,   135,     3,     4,     4,     3,
      48,     3,     3,     3,     3,     3,     3,    50,   135,   136,
     137,   139,     1,     3,    50,    56,    57,    58,    67,   108,
     121,   122,   123,   141,    48,   107,   109,   135,     1,    73,
     113,     4,   139,     4,   139,   119,   116,   137,    73,    74,
      75,   117,   118,   137,   117,   134,     3,   133,   135,    66,
      51,    51,    51,    51,    51,    51,    66,    60,   122,   140,
      48,   134,   114,   115,   137,   139,   139,   137,   118,    48,
     155,   155,   142,    14,    15,    16,    41,    50,    56,    57,
      58,    64,   124,   125,   126,   127,   128,   129,   130,   131,
     135,   138,   139,   155,     3,    44,    50,    58,    64,   145,
     147,   148,   149,   150,   151,   143,    53,   115,     4,    66,
      66,    45,   144,   146,   152,   137,     4,    73,   124,    62,
      66,   126,   127,    67,    68,    70,    71,    72,   126,   127,
      54,    61,   126,   127,    52,   145,    62,    66,   148,    69,
      67,    68,    70,   144,    62,    66,    42,   147,   154,    65,
     125,    56,    57,    58,   138,   138,    50,    65,   147,   149,
      66,   146,   153,   154,    47,    48,   156,    46,    47,   154,
     154,   154,   156
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
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
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 214 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { theTree = TREE (GRAMMAR, TREE (PROLOGUE, (yyvsp[(1) - (4)])),   
			  	          TREE (RULES, (yyvsp[(3) - (4)])), (yyvsp[(4) - (4)])); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 216 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { theTree = TREE (NONE); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 225 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 227 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 229 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 230 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 237 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { 
  	 std::string variable = (yyvsp[(2) - (3)])->as_string ();
	 std::string content = strip_quotes ((yyvsp[(3) - (3)])->as_string ());
         if (variable == "api.namespace") {
	     api_namespace = content;
	     (yyval) = TREE (SYNC);
	 } else if (variable == "semantic_type") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_type = content;
		 (yyval) = TREE (SYNC);
             }
	 } else if (variable == "semantic_tree_type") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_type = content;
		 producing_trees = true;
		 (yyval) = TREE (SYNC);
             }
	 } else if (variable == "semantics") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_params = content;
    	         (yyval) = TREE (SYNC);
             }
	 } else if (variable == "tree_semantics") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_params = content;
		 producing_trees = true;
    	         (yyval) = TREE (SYNC);
             }
	 } else if (variable == "token_factory") {
	     token_factory = content;
             (yyval) = TREE (SYNC);
	 } else if (variable == "error_function") {
	     error_function_name = content;
	     (yyval) = TREE (SYNC);
         } else
	     (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));  }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 282 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 284 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 285 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 286 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; 
  	    			     excluded_feature ("%file-prefix"); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 289 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (SYNC); 
  				     interactive_parser = true; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 291 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 292 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 293 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 296 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; 
  	    			     excluded_feature ("%output"); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 298 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 299 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 300 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 308 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 320 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 322 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 324 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 327 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 328 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 339 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (NONE); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 344 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY;
    	   	      		    excluded_feature ("%union"); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 349 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; excluded_feature ("%nterm"); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 350 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 351 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; excluded_feature ("%type"); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 356 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 367 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (NONE); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 368 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (NONE);
  				    excluded_feature ("<...> tagging"); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 375 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 380 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 386 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 392 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 404 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_explicit_token (); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 405 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_explicit_token (); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 406 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); 
     				    (yyvsp[(1) - (2)])->add_explicit_token ();}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 408 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); 
     				    (yyvsp[(1) - (2)])->add_explicit_token ((yyvsp[(2) - (2)])); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 410 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); 
     				    (yyvsp[(1) - (2)])->add_explicit_token ((yyvsp[(2) - (2)])); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 412 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); 
     	 			    (yyvsp[(1) - (3)])->add_explicit_token ((yyvsp[(3) - (3)])); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 414 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { excluded_feature ("<...> tagging"); 
  				    (yyval) = TREE (NONE); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 416 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { complain ("Attempt to redefine value of "
                                              "character token.");
                                    (yyval) = TREE (NONE); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 419 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { complain ("Attempt to redefine value of "
                                              "character token.");
                                    (yyval) = TREE (NONE); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 426 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 437 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 444 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (GRAMMAR_DECLARATION, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 445 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; yyerrok; }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 450 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (RULE, (yyvsp[(1) - (4)]), 
				               TREE (RHS_CHOICES, (yyvsp[(3) - (4)]))); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 452 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 456 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = make_rhses ((yyvsp[(1) - (1)])); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 457 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (3)]), make_rhses ((yyvsp[(3) - (3)]))); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 466 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 467 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 468 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 469 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 470 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 474 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 475 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 480 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE ('?', (yyvsp[(1) - (2)])); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 481 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE ('*', (yyvsp[(1) - (2)])); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 482 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE ('+', (yyvsp[(1) - (2)])); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 488 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { if (!producing_trees) 
                     complain ("Must declare tree type to use '^'");
		  (yyval) = TREE ('^', (yyvsp[(1) - (2)])); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 492 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE ('!', (yyvsp[(1) - (2)])); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 493 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE ('(', TREE (RHS_CHOICES, (yyvsp[(2) - (3)]))); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 498 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 499 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 503 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[(1) - (2)])), (yyvsp[(2) - (2)])); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 505 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[(1) - (2)])), (yyvsp[(2) - (2)])); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 507 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { excluded_feature ("%merge"); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 508 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { expand_rule = true; }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 522 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = No_Token; }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 561 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_implicit_token (); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 563 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_implicit_token (); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 565 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { complain_at (yylloc, 
      		   "lexical subrule (%s) not allowed in context-free rule",
		   (yyvsp[(1) - (1)])->as_string ().c_str ());
      YYERROR; 
    }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 578 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (EPILOGUE); }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 579 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (EPILOGUE, (yyvsp[(2) - (2)])); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 587 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { lexical_lhs = (yyvsp[(1) - (2)]); lexical_rhs = EMPTY; }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 588 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { make_plain_lexical_rule (); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 589 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { lexical_lhs = NULL; lexical_rhs = EMPTY; }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 590 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { make_plain_lexical_rule (); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 592 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { NodePtr subrule;
		  if ((yyvsp[(3) - (4)])->arity () > 1)
		     subrule = TREE (LEX_SUBRULE, (yyvsp[(1) - (4)]), TREE (LEX_GROUP, (yyvsp[(3) - (4)])));
		  else
		     subrule = TREE (LEX_SUBRULE, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
		  Node::lexical_subrules.push_back (subrule); }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 599 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyvsp[(1) - (4)])->add_implicit_token ((yyvsp[(3) - (4)])); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 601 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyvsp[(1) - (4)])->add_implicit_token ((yyvsp[(3) - (4)])); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 610 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_PHRASE, (yyvsp[(1) - (1)])); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 612 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (3)]), 
				                  TREE (LEX_PHRASE, (yyvsp[(3) - (3)]))); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 618 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { if ((yyvsp[(1) - (4)])->is_empty_list () && (yyvsp[(3) - (4)])->is_empty_list () && 
		      (yyvsp[(4) - (4)]) == NULL && !preferred_lexical_rule) {
		          add_lexical_option ((yyvsp[(2) - (4)]));
	          } else {
		      make_plain_lexical_rule ();
                      make_lexical_rule (LIST ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)])), (yyvsp[(4) - (4)])); 
		  }
		}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 627 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { make_plain_lexical_rule ();
                  make_lexical_rule (LIST ((yyvsp[(1) - (5)]), TREE (ENDFILE)), (yyvsp[(5) - (5)])); 
		}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 634 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 640 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_SUB, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
                             (yyval)->set_loc ((yyvsp[(2) - (3)])->get_loc ()); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 647 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_STAR, (yyvsp[(1) - (2)])); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 648 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_PLUS, (yyvsp[(1) - (2)])); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 649 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_OPT, (yyvsp[(1) - (2)])); }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 653 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_REF, (yyvsp[(1) - (1)])); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 654 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_GROUP, (yyvsp[(2) - (3)])); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 655 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_SET, (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)])); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 656 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_STRING, (yyvsp[(1) - (1)])); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 658 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_SET, 
                  new Token (lstring ("'\\001'", 6), lstring ("", 0), CHAR),
                  new Token (lstring ("'\\376'", 6), lstring ("", 0), CHAR));
     }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 665 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (LEX_SET, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 669 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 670 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (BOL); }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 674 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = EMPTY; }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 675 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (EOL); }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 676 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (ENDFILE); }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 681 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { preferred_lexical_rule = true; }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 685 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = TREE (ACTION, stripped ((yyvsp[(1) - (1)]))); 
  				     delete (yyvsp[(1) - (1)]); }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 690 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = stripped ((yyvsp[(1) - (1)])); }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 691 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"
    { (yyval) = NULL; }
    break;



/* Line 1806 of yacc.c  */
#line 2747 "parse-horn.cc"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 694 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y"


#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

const char* parser_support_files[] = {
      "horn-common.h", "horn-parse-lex.cc", 0
};

static void 
excluded_feature (const string& feature_name)
{
    complain ("Bison feature %s is not part of the Horn dialect",
    	      feature_name.c_str ());
}

static string
strip_quotes (const string& s)
{
    if (s.empty () || s[0] != '"')
        return s;

    return s.substr (1, s.size () - 2);
}

const char*
tokenName (int syntax)
{
    return yytname[YYTRANSLATE (syntax)];
}

static int
yylex ()
{
    return gram_scan ();
}

static void 
add_lexical_option (NodePtr primaries)
{
    Node* new_option = TREE (LEX_PHRASE, primaries);
    lexical_rhs = APPEND (lexical_rhs, new_option);
}

static void 
make_plain_lexical_rule ()
{
    Node* new_rhs;

    if (lexical_rhs->oper () == _LIST && lexical_rhs->arity () > 1) {
	new_rhs = TREE (LEX_GROUP, lexical_rhs);
	delete lexical_rhs;
    } else if (lexical_rhs->oper () == _LIST && lexical_rhs->arity () == 0)
        return;
    else 
	new_rhs = lexical_rhs;

    Node* new_rule;
    if (lexical_lhs == NULL) {
	new_rule = TREE (LEX_RULE, No_Token, new_rhs, lex_action (NULL, NULL));
    } else {
	new_rule = 
	    TREE (LEX_RULE, lexical_lhs, new_rhs,
		  lex_action (lexical_lhs, NULL));
	Node::all_tokens.insert (make_pair (lexical_lhs->as_string (),
					    No_Token));
    }
    Node::lexical_rules.push_back (new_rule);

    lexical_rhs = EMPTY;
}

static void
make_lexical_rule (NodePtr rhs, NodePtr action)
{
    int rule_tok = preferred_lexical_rule ? LEX_RULE_PREFERRED : LEX_RULE;
    Node* new_rule;
    Node* phrase = TREE (LEX_PHRASE, rhs);
    if (lexical_lhs == NULL) {
	new_rule = TREE (rule_tok, No_Token, phrase, lex_action (NULL, action));
    } else {
	new_rule = TREE (rule_tok, lexical_lhs, phrase, 
			 lex_action (lexical_lhs, action));
	Node::all_tokens.insert (make_pair (lexical_lhs->as_string (), 
					    No_Token));
    }
    Node::lexical_rules.push_back (new_rule);
    preferred_lexical_rule = false;
}

static void
make_rhses_1 (NodePtr result, NodePtr rhs_accum, NodePtr syms, int k, 
	      NodePtr annotations)
{
    if (k >= syms->arity ())
	result->add (TREE (RHS, rhs_accum, annotations)->normalize_action ());
    else {
	NodePtr child;
	child = syms->child (k);
	if (child->oper ()->syntax () == '(') {
	    child = child->child (0);
	    syms->replace (k, EMPTY);
	    
	    for (int i = 0; i < child->arity (); i += 1) {
		NodePtr new_syms = syms->copy ();
		new_syms->add (child->child (i)->extract_to_list (), k);
		make_rhses_1 (result, rhs_accum->copy (), new_syms, k,
			      annotations);
	    }
	} else
	    make_rhses_1 (result, rhs_accum->add (child), syms, k+1,
			  annotations);
    }
}
	

static NodePtr
make_rhses (NodePtr syms)
{
    NodePtr result;

    if (rule_annotations->arity () != 0)
	rule_annotations = TREE (PERCENTS, rule_annotations);

    if (expand_rule) {
        result = EMPTY;
        make_rhses_1 (result, EMPTY, syms, 0, rule_annotations);
    } else
    	result = TREE (RHS, syms, rule_annotations)->normalize_action ();
    expand_rule = false;
    rule_annotations = EMPTY;
    
    return result;
}
	   
/** The action token TOK, but with the outer '{}' and any initial or 
    trailing whitespace removed from its text. */
static NodePtr
stripped (NodePtr tok)
{
    const lstring text = tok->text ();
    const char* s;
    const char* e;
    size_t len;
    s = text.start + 1;
    len = text.len - 2;
    while (len > 0 && isspace (*s)) {
        s += 1; len -= 1;
    }
    e = s + len - 1;
    while (len > 0 && isspace (*e)) {
        e -= 1; len -= 1;
    }
    return new Token (lstring (s, len), tok->preceding_ws (), tok->syntax ());
}

static void
Usage ()
{
    fprintf (stderr, "Usage: hornpp [ --datadir=DIR ] [ -o OUTFILE[.y] ] [ INFILE ]\n");
    exit (1);
}

string grammar_outfile;
string lexical_outfile;
string lex_generated_file;
string infile;
string file_root;

string data_dir;
string parser_template_file;
string directory_separator;

string api_namespace;

static string file_dir;

static void
process_args (int argc, char* argv[])
{
    file_root = "";
    lexical_outfile = "";
    infile = "";
    token_factory = "";
    
    int i;
    for (i = 1; i < argc; i += 1) {
	if (string("-o") == argv[i] && i < argc-1) {
	    file_root = argv[i+1];
	    i += 1;
	} else if (string(argv[i]).compare(0, 10, "--datadir=") == 0)
	    data_dir = argv[i]+10;
	else if (argv[i][0] == '-')
	    Usage ();
	else
	    break;
    }

    if (i < argc-1)
	Usage ();
    else if (i == argc-1)
	infile = argv[i];

    if (data_dir == "")
	directory_separator = "/";
    else {
	size_t sep_loc = data_dir.find_first_of ("/\\");
	if (sep_loc == string::npos)
	    directory_separator = "/";
	else
	    directory_separator = data_dir[sep_loc];
    }
    if (data_dir[data_dir.size ()-1] != directory_separator[0])
	data_dir += directory_separator;

    parser_template_file = data_dir + PARSER_TEMPLATE_FILE_TAIL;

    if (file_root == "" && infile == "")
	file_root = "yy";
    else if (file_root == "") {
	file_root = infile;
	size_t tail = file_root.rfind (directory_separator);
	if (tail == string::npos)
	    tail = 0;
	size_t ext = file_root.find ('.', tail);
	if (ext != string::npos) 
	    file_root.erase (ext, string::npos);
    }

    {
	file_dir = file_root;
	size_t tail = file_dir.rfind (directory_separator);
	if (tail == string::npos)
	    file_dir = ".";
	else
	    file_dir.erase (tail, string::npos);
    }

    grammar_outfile = file_root + "-parser.y";
    lexical_outfile = file_root + "-lexer.l";
    lex_generated_file = file_root + "-lexer.cc";

}

bool init_phase_done = false;

int
main (int argc, char* argv[])
{
    init_phase_done = true;
    process_args (argc, argv);

    if (infile == "")
	infile = "stdin";
    else if (freopen (infile.c_str (), "r", stdin) == NULL) 
	fatal ("could not read %s", infile.c_str ());

    gram_scanner_initialize (stdin, infile);

    theTree = TREE (NONE);
    rule_annotations = EMPTY;
    expand_rule = false;
    preferred_lexical_rule = false;
    interactive_parser = false;
    Node::lexical_rules.clear ();
    Node::lexical_subrules.clear ();

    yyparse ();
    if (complaint_issued)
        exit (1);

    {	
	stringstream out;
	theTree->process (out);
	if (complaint_issued)
	    exit (1);

	ofstream grammar_out;
	grammar_out.open (grammar_outfile.c_str ());
	if (grammar_out.fail ()) {
	    fatal ("could not open %s for output", grammar_outfile.c_str ());
	    exit (1);
	}
	grammar_out << out.str ();
	grammar_out.close ();
    }

    { 
	stringstream out;
	Node::process_lexical (infile, out);
	if (complaint_issued)
	    exit (1);

	ofstream lexer_out;
	lexer_out.open (lexical_outfile.c_str ());
	if (lexer_out.fail ()) {
	    fatal ("could not open %s for output", lexical_outfile.c_str ());
	    exit (1);
	}
	lexer_out << out.str ();
	lexer_out.close ();
    }

    for (int i = 0; parser_support_files[i] != NULL; i += 1)
        copy_file_if_needed (file_dir + directory_separator 
                             + parser_support_files[i],
                             data_dir + parser_support_files[i]);

    exit (0);
}

