/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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
     PERCENT_CONVENTION = 296,
     PERCENT_EXPAND = 297,
     PERCENT_PREFER = 298,
     PERCENTS = 299,
     ANY = 300,
     UPPER = 301,
     LOWER = 302,
     LETTER = 303,
     DIGIT = 304,
     HEX = 305,
     ALNUM = 306,
     SPACE = 307,
     BLANK = 308,
     CONTROL = 309,
     GRAPHIC = 310,
     PRINTABLE = 311,
     PUNCTUATION = 312,
     BOL = 313,
     EOL = 314,
     ENDFILE = 315,
     BRACED_CODE = 316,
     BRACED_PREDICATE = 317,
     CHAR = 318,
     DOTDOT = 319,
     EPILOGUE = 320,
     ID = 321,
     TERM_ID = 322,
     NONTERM_ID = 323,
     UNDERSCORE_ID = 324,
     OTHER_ID = 325,
     PERCENT_PERCENT = 326,
     PLUS_EQ = 327,
     PROLOGUE = 328,
     TAG = 329,
     TAG_ANY = 330,
     TAG_NONE = 331,
     PERCENT_PARAM = 332,
     NONE = 333,
     GRAMMAR = 334,
     RULES = 335,
     RULE = 336,
     GRAMMAR_DECLARATION = 337,
     RHS_CHOICES = 338,
     RHS_ANNOTATIONS = 339,
     RHS = 340,
     GENERATED_RULE = 341,
     ACTION = 342,
     TOKEN_TAG = 343,
     LIST_TAG = 344,
     LEX_GROUP = 345,
     LEX_OPT = 346,
     LEX_PHRASE = 347,
     LEX_PLUS = 348,
     LEX_SET = 349,
     LEX_SUB = 350,
     LEX_RULE = 351,
     LEX_RULE_PREFERRED = 352,
     LEX_STAR = 353,
     LEX_SUBRULE = 354,
     LEX_STRING = 355,
     LEX_REF = 356,
     SYNC = 357,
     PERCENT_UNION = 358
   };
#endif
/* Tokens.  */
#define GRAM_EOF 0
#define STRING 258
#define INT 259
#define PERCENT_TOKEN 260
#define PERCENT_NTERM 261
#define PERCENT_TYPE 262
#define PERCENT_DESTRUCTOR 263
#define PERCENT_PRINTER 264
#define PERCENT_LEFT 265
#define PERCENT_RIGHT 266
#define PERCENT_NONASSOC 267
#define PERCENT_PRECEDENCE 268
#define PERCENT_PREC 269
#define PERCENT_DPREC 270
#define PERCENT_MERGE 271
#define PERCENT_CODE 272
#define PERCENT_DEFAULT_PREC 273
#define PERCENT_DEFINE 274
#define PERCENT_DEFINES 275
#define PERCENT_ERROR_VERBOSE 276
#define PERCENT_EXPECT 277
#define PERCENT_EXPECT_RR 278
#define PERCENT_FLAG 279
#define PERCENT_FILE_PREFIX 280
#define PERCENT_GLR_PARSER 281
#define PERCENT_INTERACTIVE 282
#define PERCENT_INITIAL_ACTION 283
#define PERCENT_LANGUAGE 284
#define PERCENT_NAME_PREFIX 285
#define PERCENT_NO_DEFAULT_PREC 286
#define PERCENT_NO_LINES 287
#define PERCENT_NONDETERMINISTIC_PARSER 288
#define PERCENT_OUTPUT 289
#define PERCENT_REQUIRE 290
#define PERCENT_SKELETON 291
#define PERCENT_START 292
#define PERCENT_TOKEN_TABLE 293
#define PERCENT_VERBOSE 294
#define PERCENT_YACC 295
#define PERCENT_CONVENTION 296
#define PERCENT_EXPAND 297
#define PERCENT_PREFER 298
#define PERCENTS 299
#define ANY 300
#define UPPER 301
#define LOWER 302
#define LETTER 303
#define DIGIT 304
#define HEX 305
#define ALNUM 306
#define SPACE 307
#define BLANK 308
#define CONTROL 309
#define GRAPHIC 310
#define PRINTABLE 311
#define PUNCTUATION 312
#define BOL 313
#define EOL 314
#define ENDFILE 315
#define BRACED_CODE 316
#define BRACED_PREDICATE 317
#define CHAR 318
#define DOTDOT 319
#define EPILOGUE 320
#define ID 321
#define TERM_ID 322
#define NONTERM_ID 323
#define UNDERSCORE_ID 324
#define OTHER_ID 325
#define PERCENT_PERCENT 326
#define PLUS_EQ 327
#define PROLOGUE 328
#define TAG 329
#define TAG_ANY 330
#define TAG_NONE 331
#define PERCENT_PARAM 332
#define NONE 333
#define GRAMMAR 334
#define RULES 335
#define RULE 336
#define GRAMMAR_DECLARATION 337
#define RHS_CHOICES 338
#define RHS_ANNOTATIONS 339
#define RHS 340
#define GENERATED_RULE 341
#define ACTION 342
#define TOKEN_TAG 343
#define LIST_TAG 344
#define LEX_GROUP 345
#define LEX_OPT 346
#define LEX_PHRASE 347
#define LEX_PLUS 348
#define LEX_SET 349
#define LEX_SUB 350
#define LEX_RULE 351
#define LEX_RULE_PREFERRED 352
#define LEX_STAR 353
#define LEX_SUBRULE 354
#define LEX_STRING 355
#define LEX_REF 356
#define SYNC 357
#define PERCENT_UNION 358




/* Copy the first part of user declarations.  */
#line 3 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"

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

#line 178 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"

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
static symbol_convention as_convention(const lstring& conv);

#define O_RANGE(Low, High)                                                   \
        new Token (lstring ("'\\" #Low "'", 6), lstring ("", 0), CHAR),      \
        new Token (lstring ("'\\" #High "'", 6), lstring ("", 0), CHAR)

#define RANGE(Low, High)                                                     \
        new Token (lstring (#Low, 3), lstring ("", 0), CHAR),        \
        new Token (lstring (#High, 3), lstring ("", 0), CHAR)
        



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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


/* Line 216 of yacc.c.  */
#line 410 "parse-horn.cc"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   550

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  116
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNRULES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   358

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,     2,     2,     2,     2,     2,     2,
      77,    78,    80,    81,     2,    82,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    79,
       2,    67,     2,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    75,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    65,
      66,    68,    69,    70,    71,    72,    73,    74,    76,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    10,    11,    14,    18,    20,    22,
      24,    26,    30,    34,    36,    39,    41,    44,    47,    50,
      52,    54,    57,    60,    63,    65,    67,    70,    73,    76,
      79,    81,    83,    85,    87,    90,    92,    94,    96,    99,
     103,   107,   109,   111,   114,   118,   119,   121,   125,   128,
     131,   135,   139,   141,   143,   145,   147,   148,   150,   152,
     155,   157,   160,   162,   165,   167,   170,   172,   174,   176,
     178,   180,   182,   185,   188,   191,   195,   197,   200,   204,
     206,   209,   211,   214,   216,   219,   222,   227,   229,   231,
     235,   237,   239,   242,   245,   248,   251,   254,   255,   258,
     260,   263,   266,   269,   271,   274,   277,   281,   283,   287,
     291,   294,   297,   300,   303,   306,   308,   310,   312,   313,
     315,   317,   319,   321,   323,   325,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   346,   349,   350,   356,
     357,   363,   368,   373,   378,   380,   384,   386,   390,   395,
     401,   403,   406,   408,   412,   414,   416,   419,   422,   425,
     427,   431,   433,   435,   437,   439,   441,   443,   445,   447,
     449,   451,   453,   455,   457,   459,   461,   463,   467,   468,
     470,   472,   476,   480,   481,   483,   485,   487
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     117,     0,    -1,   118,    73,   134,   153,    -1,     1,    -1,
      -1,   118,   119,    -1,   118,   119,     1,    -1,     1,    -1,
     121,    -1,    76,    -1,    24,    -1,    41,   148,   148,    -1,
      19,   145,   146,    -1,    20,    -1,    20,     3,    -1,    21,
      -1,    22,     4,    -1,    23,     4,    -1,    25,     3,    -1,
      26,    -1,    27,    -1,    28,    61,    -1,    29,     3,    -1,
      30,     3,    -1,    32,    -1,    33,    -1,    34,     3,    -1,
      89,   120,    -1,    35,     3,    -1,    36,     3,    -1,    38,
      -1,    39,    -1,    40,    -1,    79,    -1,   120,    61,    -1,
      61,    -1,   124,    -1,   123,    -1,    37,   150,    -1,     8,
      61,   130,    -1,     9,    61,   130,    -1,    18,    -1,    31,
      -1,    17,   147,    -1,    17,   148,   147,    -1,    -1,   148,
      -1,   115,   122,   147,    -1,     6,   133,    -1,     5,   133,
      -1,     7,    86,   129,    -1,   125,   126,   127,    -1,    10,
      -1,    11,    -1,    12,    -1,    13,    -1,    -1,    86,    -1,
     128,    -1,   127,   128,    -1,   150,    -1,   150,     4,    -1,
     150,    -1,   129,   150,    -1,   131,    -1,   130,   131,    -1,
     150,    -1,    86,    -1,    87,    -1,    88,    -1,    69,    -1,
      63,    -1,    69,     4,    -1,    69,   152,    -1,    63,   152,
      -1,    69,     4,   152,    -1,    86,    -1,    63,     4,    -1,
      63,     4,   152,    -1,   132,    -1,   133,   132,    -1,   135,
      -1,   134,   135,    -1,   136,    -1,   121,    79,    -1,     1,
      79,    -1,    70,    64,   137,    79,    -1,   154,    -1,   138,
      -1,   137,    75,   138,    -1,   140,    -1,   139,    -1,   141,
     140,    -1,   169,   140,    -1,   141,   139,    -1,   169,   139,
      -1,   144,   139,    -1,    -1,   144,   140,    -1,   142,    -1,
     142,    83,    -1,   142,    80,    -1,   142,    81,    -1,   143,
      -1,   143,    84,    -1,   143,    85,    -1,    77,   137,    78,
      -1,   151,    -1,   148,    67,   151,    -1,   148,    74,   151,
      -1,    14,   150,    -1,    15,     4,    -1,    22,     4,    -1,
      23,     4,    -1,    16,    86,    -1,    42,    -1,   148,    -1,
      72,    -1,    -1,   148,    -1,     3,    -1,    61,    -1,    69,
      -1,    70,    -1,    71,    -1,   148,    -1,    63,    -1,   149,
      -1,   152,    -1,    69,    -1,    70,    -1,    63,    -1,   152,
      -1,    71,    -1,     3,    -1,    -1,    73,    66,    -1,    -1,
      69,    64,   155,   157,    79,    -1,    -1,    80,    64,   156,
     157,    79,    -1,    71,    64,   158,    79,    -1,     3,    64,
     169,    79,    -1,    63,    64,   169,    79,    -1,   159,    -1,
     157,    75,   159,    -1,   160,    -1,   158,    75,   160,    -1,
     166,   160,   167,   170,    -1,   166,   168,    60,   168,   170,
      -1,   161,    -1,   160,   161,    -1,   162,    -1,   161,    82,
     162,    -1,   163,    -1,   165,    -1,   163,    80,    -1,   163,
      81,    -1,   163,    83,    -1,    71,    -1,    77,   158,    78,
      -1,    63,    -1,     3,    -1,   164,    -1,    45,    -1,    46,
      -1,    47,    -1,    48,    -1,    49,    -1,    50,    -1,    51,
      -1,    52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,
      -1,    57,    -1,    63,    65,    63,    -1,    -1,    58,    -1,
     168,    -1,   168,    59,   168,    -1,   168,    60,   168,    -1,
      -1,    43,    -1,    61,    -1,    61,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   238,   238,   241,   250,   251,   253,   255,   259,   260,
     261,   262,   267,   311,   312,   313,   314,   315,   316,   318,
     319,   321,   322,   323,   324,   325,   326,   328,   329,   330,
     331,   332,   333,   334,   338,   339,   348,   349,   350,   351,
     353,   355,   356,   357,   358,   369,   370,   374,   379,   380,
     381,   385,   390,   391,   392,   393,   397,   398,   404,   405,
     409,   410,   415,   416,   420,   421,   426,   427,   428,   429,
     434,   435,   436,   438,   440,   442,   444,   446,   449,   455,
     456,   465,   466,   473,   474,   475,   479,   482,   486,   487,
     491,   492,   496,   497,   498,   499,   500,   504,   505,   509,
     510,   511,   512,   516,   517,   521,   523,   527,   528,   529,
     533,   535,   537,   539,   541,   542,   550,   551,   556,   557,
     558,   567,   576,   577,   578,   582,   583,   587,   588,   592,
     593,   594,   596,   598,   608,   612,   613,   621,   621,   623,
     623,   625,   632,   634,   639,   640,   644,   645,   651,   660,
     667,   668,   672,   673,   679,   680,   681,   682,   683,   687,
     688,   689,   690,   691,   695,   696,   697,   698,   699,   700,
     702,   704,   707,   708,   709,   710,   711,   716,   720,   721,
     725,   726,   727,   730,   732,   736,   741,   742
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
  "\"%verbose\"", "\"%yacc\"", "\"%convention\"", "\"%expand\"",
  "\"%prefer\"", "PERCENTS", "\"_ANY\"", "\"_UPPER\"", "\"_LOWER\"",
  "\"_LETTER\"", "\"_DIGIT\"", "\"_HEX\"", "\"_ALNUM\"", "\"_SPACE\"",
  "\"_BLANK\"", "\"_CONTROL\"", "\"_GRAPHIC\"", "\"_PRINTABLE\"",
  "\"_PUNCTUATION\"", "\"_BOL\"", "\"_EOL\"", "\"_EOF\"", "\"{...}\"",
  "\"%?{...}\"", "\"char\"", "\":\"", "\"..\"", "\"epilogue\"", "\"=\"",
  "ID", "TERM_ID", "NONTERM_ID", "UNDERSCORE_ID", "OTHER_ID", "\"%%\"",
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
  "cf_symbol", "string_as_id", "epilogue.opt", "lexical_rule", "@1", "@2",
  "lexical_rhs", "lexical_rhs_no_rules", "lexical_rhs_primaries",
  "lexical_primaries", "lexical_term", "lexical_primary", "lexical_atom",
  "predefined_atoms", "char_range", "lexical_prefix", "lexical_suffix",
  "preferred.opt", "action", "bare_action.opt", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    58,   319,   320,    61,   321,   322,
     323,   324,   325,   326,   327,   124,   328,    40,    41,    59,
      42,    43,    45,    63,    94,    33,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   116,   117,   117,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   122,   122,   121,   123,   123,
     123,   124,   125,   125,   125,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   139,   139,   139,   140,   140,   141,
     141,   141,   141,   142,   142,   142,   142,   143,   143,   143,
     144,   144,   144,   144,   144,   144,   145,   145,   146,   146,
     146,   147,   148,   148,   148,   149,   149,   150,   150,   151,
     151,   151,   151,   151,   152,   153,   153,   155,   154,   156,
     154,   154,   154,   154,   157,   157,   158,   158,   159,   159,
     160,   160,   161,   161,   162,   162,   162,   162,   162,   163,
     163,   163,   163,   163,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   165,   166,   166,
     167,   167,   167,   168,   168,   169,   170,   170
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     2,     3,     1,     1,     1,
       1,     3,     3,     1,     2,     1,     2,     2,     2,     1,
       1,     2,     2,     2,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     3,
       3,     1,     1,     2,     3,     0,     1,     3,     2,     2,
       3,     3,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     2,     4,     1,     1,     3,
       1,     1,     2,     2,     2,     2,     2,     0,     2,     1,
       2,     2,     2,     1,     2,     2,     3,     1,     3,     3,
       2,     2,     2,     2,     2,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     5,     0,
       5,     4,     4,     4,     1,     3,     1,     3,     4,     5,
       1,     2,     1,     3,     1,     1,     2,     2,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     3,     3,     0,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     1,     0,     0,     0,     0,     0,
      52,    53,    54,    55,     0,    41,     0,    13,    15,     0,
       0,    10,     0,    19,    20,     0,     0,     0,    42,    24,
      25,     0,     0,     0,     0,    30,    31,    32,     0,     0,
       9,    33,     0,    45,     0,     8,    37,    36,    56,    71,
      70,    76,    79,    49,    48,     0,     0,     0,   121,   122,
     123,   124,    43,     0,   117,   118,   116,    14,    16,    17,
      18,    21,    22,    23,    26,    28,    29,   134,   126,   125,
     127,    38,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    83,    87,    35,    27,     0,    46,
       6,    57,     0,    77,    74,    72,    73,    80,    50,    62,
      67,    68,    69,    39,    64,    66,    40,    44,   120,    12,
     119,    11,    85,     0,     0,   137,    97,     0,   139,    84,
       0,    82,     2,    34,    47,    51,    58,    60,    78,    75,
      63,    65,   185,     0,     0,   178,     0,     0,     0,     0,
       0,   115,   131,   129,   130,   133,    97,     0,    88,    91,
      90,    97,    99,   103,    97,     0,   107,   132,    97,   162,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   161,   159,     0,     0,   146,   150,   152,
     154,   163,   155,   178,   136,    59,    61,   142,   143,   179,
       0,   144,   183,   110,   111,   114,   112,   113,     0,    97,
      86,    94,    92,   101,   102,   100,   104,   105,    96,    98,
       0,     0,    95,    93,     0,     0,     0,   141,   151,     0,
     156,   157,   158,     0,   178,   138,   184,   183,     0,   106,
      89,   129,   130,   133,   108,   109,   177,   160,   147,   153,
     140,   145,   187,   180,   183,   186,   148,   183,   183,   187,
     181,   182,   149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    44,    97,    91,    98,    46,    47,    48,
     102,   135,   136,   108,   113,   114,    52,    53,    92,    93,
      94,   157,   158,   159,   160,   161,   162,   163,   164,    65,
     119,    62,    79,    80,   115,   166,    82,   132,    95,   145,
     193,   200,   186,   201,   187,   188,   189,   190,   191,   192,
     202,   252,   238,   168,   256
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -210
static const yytype_int16 yypact[] =
{
     179,     1,    19,   418,  -210,   -43,   -43,   -59,    -6,    11,
    -210,  -210,  -210,  -210,    -7,  -210,    58,    57,  -210,    88,
     107,  -210,   110,  -210,  -210,    64,   130,   140,  -210,  -210,
    -210,   150,   154,   155,    27,  -210,  -210,  -210,    13,   319,
    -210,  -210,    98,    13,   278,  -210,  -210,  -210,    74,    34,
     120,  -210,  -210,   -43,   -43,    27,    18,    18,  -210,  -210,
    -210,  -210,  -210,   100,  -210,    38,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,    13,    83,   101,   102,   103,   104,   105,
     106,    85,     5,  -210,  -210,  -210,  -210,   111,   100,  -210,
    -210,  -210,    27,   168,  -210,   168,  -210,  -210,    27,  -210,
    -210,  -210,  -210,    18,  -210,  -210,    18,  -210,  -210,  -210,
    -210,  -210,  -210,   112,   112,  -210,   473,   415,  -210,  -210,
     113,  -210,  -210,  -210,  -210,    27,  -210,   172,  -210,  -210,
    -210,  -210,  -210,    99,   114,   119,    27,   177,    96,   190,
     217,  -210,  -210,   -34,    -1,     3,   473,   -23,  -210,  -210,
    -210,   473,    51,    61,   473,    12,  -210,  -210,   473,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,   157,  -210,   415,    -8,   415,   142,  -210,
      55,  -210,  -210,   119,  -210,  -210,  -210,  -210,  -210,  -210,
      16,  -210,   180,  -210,  -210,  -210,  -210,  -210,   -28,   473,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
      31,    31,  -210,  -210,   175,    41,   415,  -210,   142,   415,
    -210,  -210,  -210,    42,   119,  -210,  -210,   180,   181,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,   415,  -210,
    -210,  -210,   178,    80,   197,  -210,  -210,   197,   197,   178,
    -210,  -210,  -210
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,  -210,  -210,   239,  -210,  -210,  -210,  -210,
    -210,  -210,   109,  -210,   188,    28,    95,   240,  -210,   156,
    -210,    91,    40,  -129,  -103,  -210,  -210,  -210,  -210,  -210,
    -210,   -54,   -14,  -210,    -9,   -69,   -46,  -210,  -210,  -210,
    -210,    60,    65,    20,  -195,  -134,    30,  -210,  -210,  -210,
    -210,  -210,  -209,    32,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -136
static const yytype_int16 yytable[] =
{
      63,    -3,    66,   104,   106,  -135,    84,   237,    85,   117,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     4,
      49,    77,    14,    15,    83,    81,    50,    55,   253,    99,
      77,   248,   211,  -122,    77,   218,    28,    77,   103,   222,
    -122,   118,    34,    51,   134,   259,   109,   209,   260,   261,
     239,   120,   209,   228,    58,    56,   210,   138,   212,   139,
      67,   219,    59,    60,    61,   223,  -123,   226,    86,   121,
    -124,   227,    57,  -123,    87,    88,    89,  -124,   130,   220,
     167,    78,    59,    60,    61,    90,   221,    59,    60,    61,
      78,   234,    68,   137,   152,   235,    59,    60,    61,   140,
     241,   242,   243,   228,   110,   111,   112,    59,    60,    61,
     167,    69,   165,    70,   228,   167,   226,   234,   167,   247,
      43,   250,   167,    77,   105,    71,   137,    59,    60,    61,
      64,   213,   214,    72,   215,   230,   231,   203,   232,   257,
     258,   141,   165,    73,   141,   216,   217,   165,   107,   107,
     165,   244,   245,    74,   165,   143,   144,    75,    76,    96,
     101,    58,   122,   167,   129,   123,   124,   125,   126,   127,
     128,    77,   133,   142,   167,   167,   196,   199,   197,   194,
       1,   204,   205,   169,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,   198,   206,   165,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,   207,   224,   236,   229,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   246,   255,
     236,   254,    45,   183,   195,   116,    54,   208,   131,   240,
     225,   184,    -4,   233,   251,    -4,   262,   185,    -4,   249,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,     0,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,     0,     0,    -4,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      84,     0,    85,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    -5,     0,     0,    -5,     0,    34,    -5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,     0,     0,     0,     0,    87,    88,
      89,     0,     0,    -5,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,    43,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,     0,     0,     0,    77,     0,   183,     0,
       0,     0,     0,     0,     0,     0,   184,   146,   147,   148,
       0,    39,   185,     0,    40,   149,   150,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,   142,     0,   152,     0,     0,     0,
       0,     0,   153,   154,   155,     0,     0,     0,     0,     0,
     156
};

static const yytype_int16 yycheck[] =
{
      14,     0,    16,    49,    50,     0,     1,   202,     3,    63,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      63,     3,    17,    18,    38,    34,    69,    86,   237,    43,
       3,   226,   161,    67,     3,   164,    31,     3,     4,   168,
      74,     3,    37,    86,    98,   254,    55,    75,   257,   258,
      78,    65,    75,   187,    61,    61,    79,   103,   161,   105,
       3,   164,    69,    70,    71,   168,    67,    75,    63,    83,
      67,    79,    61,    74,    69,    70,    71,    74,    73,    67,
     126,    63,    69,    70,    71,    80,    74,    69,    70,    71,
      63,    75,     4,   102,    63,    79,    69,    70,    71,   108,
      69,    70,    71,   237,    86,    87,    88,    69,    70,    71,
     156,     4,   126,     3,   248,   161,    75,    75,   164,    78,
     115,    79,   168,     3,     4,    61,   135,    69,    70,    71,
      72,    80,    81,     3,    83,    80,    81,   146,    83,    59,
      60,   113,   156,     3,   116,    84,    85,   161,    53,    54,
     164,   220,   221,     3,   168,   123,   124,     3,     3,    61,
      86,    61,    79,   209,    79,    64,    64,    64,    64,    64,
      64,     3,    61,    61,   220,   221,     4,    58,    79,    66,
       1,     4,    86,     3,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    79,     4,   209,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     4,    65,    43,    82,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    63,    61,
      43,    60,     3,    63,   135,    57,     6,   156,    92,   209,
     185,    71,    73,   193,   234,    76,   259,    77,    79,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,   115,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    73,    -1,    -1,    76,    -1,    37,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,   115,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,     3,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    14,    15,    16,
      -1,    73,    77,    -1,    76,    22,    23,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      77
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   117,   118,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    73,
      76,    79,    89,   115,   119,   121,   123,   124,   125,    63,
      69,    86,   132,   133,   133,    86,    61,    61,    61,    69,
      70,    71,   147,   148,    72,   145,   148,     3,     4,     4,
       3,    61,     3,     3,     3,     3,     3,     3,    63,   148,
     149,   150,   152,   148,     1,     3,    63,    69,    70,    71,
      80,   121,   134,   135,   136,   154,    61,   120,   122,   148,
       1,    86,   126,     4,   152,     4,   152,   132,   129,   150,
      86,    87,    88,   130,   131,   150,   130,   147,     3,   146,
     148,   148,    79,    64,    64,    64,    64,    64,    64,    79,
      73,   135,   153,    61,   147,   127,   128,   150,   152,   152,
     150,   131,    61,   169,   169,   155,    14,    15,    16,    22,
      23,    42,    63,    69,    70,    71,    77,   137,   138,   139,
     140,   141,   142,   143,   144,   148,   151,   152,   169,     3,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    63,    71,    77,   158,   160,   161,   162,
     163,   164,   165,   156,    66,   128,     4,    79,    79,    58,
     157,   159,   166,   150,     4,    86,     4,     4,   137,    75,
      79,   139,   140,    80,    81,    83,    84,    85,   139,   140,
      67,    74,   139,   140,    65,   158,    75,    79,   161,    82,
      80,    81,    83,   157,    75,    79,    43,   160,   168,    78,
     138,    69,    70,    71,   151,   151,    63,    78,   160,   162,
      79,   159,   167,   168,    60,    61,   170,    59,    60,   168,
     168,   168,   170
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
  yylloc.first_column = yylloc.last_column = 0;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 239 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { theTree = TREE (GRAMMAR, TREE (PROLOGUE, (yyvsp[(1) - (4)])),   
			  	          TREE (RULES, (yyvsp[(3) - (4)])), (yyvsp[(4) - (4)])); ;}
    break;

  case 3:
#line 241 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { theTree = TREE (NONE); ;}
    break;

  case 4:
#line 250 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; ;}
    break;

  case 5:
#line 252 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 6:
#line 254 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 7:
#line 255 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; ;}
    break;

  case 11:
#line 263 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { set_lexical_convention((symbol_convention)
			   (as_convention ((yyvsp[(2) - (3)])->text ()) * 4 +
			    as_convention ((yyvsp[(3) - (3)])->text ())));
    (yyval) = EMPTY; ;}
    break;

  case 12:
#line 267 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
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
	     (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));  ;}
    break;

  case 14:
#line 312 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 16:
#line 314 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 17:
#line 315 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 18:
#line 316 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; 
  	    			     excluded_feature ("%file-prefix"); ;}
    break;

  case 20:
#line 319 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (SYNC); 
  				     interactive_parser = true; ;}
    break;

  case 21:
#line 321 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 22:
#line 322 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 23:
#line 323 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 26:
#line 326 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; 
  	    			     excluded_feature ("%output"); ;}
    break;

  case 27:
#line 328 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 28:
#line 329 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 29:
#line 330 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 34:
#line 338 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 38:
#line 350 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 39:
#line 352 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 40:
#line 354 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 43:
#line 357 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 44:
#line 358 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 45:
#line 369 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (NONE); ;}
    break;

  case 47:
#line 374 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY;
    	   	      		    excluded_feature ("%union"); ;}
    break;

  case 48:
#line 379 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; excluded_feature ("%nterm"); ;}
    break;

  case 49:
#line 380 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 50:
#line 381 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; excluded_feature ("%type"); ;}
    break;

  case 51:
#line 386 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 56:
#line 397 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (NONE); ;}
    break;

  case 57:
#line 398 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (NONE);
  				    excluded_feature ("<...> tagging"); ;}
    break;

  case 59:
#line 405 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 61:
#line 410 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 63:
#line 416 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 65:
#line 422 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 70:
#line 434 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_explicit_token (); ;}
    break;

  case 71:
#line 435 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_explicit_token (); ;}
    break;

  case 72:
#line 436 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); 
     				    (yyvsp[(1) - (2)])->add_explicit_token ();;}
    break;

  case 73:
#line 438 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); 
     				    (yyvsp[(1) - (2)])->add_explicit_token ((yyvsp[(2) - (2)])); ;}
    break;

  case 74:
#line 440 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); 
     				    (yyvsp[(1) - (2)])->add_explicit_token ((yyvsp[(2) - (2)])); ;}
    break;

  case 75:
#line 442 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = LIST ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); 
     	 			    (yyvsp[(1) - (3)])->add_explicit_token ((yyvsp[(3) - (3)])); ;}
    break;

  case 76:
#line 444 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { excluded_feature ("<...> tagging"); 
  				    (yyval) = TREE (NONE); ;}
    break;

  case 77:
#line 446 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { complain ("Attempt to redefine value of "
                                              "character token.");
                                    (yyval) = TREE (NONE); ;}
    break;

  case 78:
#line 449 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { complain ("Attempt to redefine value of "
                                              "character token.");
                                    (yyval) = TREE (NONE); ;}
    break;

  case 80:
#line 456 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 82:
#line 467 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 84:
#line 474 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (GRAMMAR_DECLARATION, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 85:
#line 475 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; yyerrok; ;}
    break;

  case 86:
#line 480 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (RULE, (yyvsp[(1) - (4)]), 
				               TREE (RHS_CHOICES, (yyvsp[(3) - (4)]))); ;}
    break;

  case 87:
#line 482 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; ;}
    break;

  case 88:
#line 486 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = make_rhses ((yyvsp[(1) - (1)])); ;}
    break;

  case 89:
#line 487 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (3)]), make_rhses ((yyvsp[(3) - (3)]))); ;}
    break;

  case 92:
#line 496 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 93:
#line 497 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 94:
#line 498 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 95:
#line 499 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 96:
#line 500 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 97:
#line 504 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; ;}
    break;

  case 98:
#line 505 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 100:
#line 510 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE ('?', (yyvsp[(1) - (2)])); ;}
    break;

  case 101:
#line 511 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE ('*', (yyvsp[(1) - (2)])); ;}
    break;

  case 102:
#line 512 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE ('+', (yyvsp[(1) - (2)])); ;}
    break;

  case 104:
#line 518 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { if (!producing_trees) 
                     complain ("Must declare tree type to use '^'");
		  (yyval) = TREE ('^', (yyvsp[(1) - (2)])); ;}
    break;

  case 105:
#line 522 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE ('!', (yyvsp[(1) - (2)])); ;}
    break;

  case 106:
#line 523 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE ('(', TREE (RHS_CHOICES, (yyvsp[(2) - (3)]))); ;}
    break;

  case 108:
#line 528 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 109:
#line 529 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 110:
#line 533 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[(1) - (2)])), (yyvsp[(2) - (2)])); ;}
    break;

  case 111:
#line 535 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[(1) - (2)])), (yyvsp[(2) - (2)])); ;}
    break;

  case 112:
#line 537 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { rule_annotations =
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[(1) - (2)])), (yyvsp[(2) - (2)])); ;}
    break;

  case 113:
#line 539 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { rule_annotations =
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[(1) - (2)])), (yyvsp[(2) - (2)])); ;}
    break;

  case 114:
#line 541 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { excluded_feature ("%merge"); ;}
    break;

  case 115:
#line 542 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { expand_rule = true; ;}
    break;

  case 118:
#line 556 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = No_Token; ;}
    break;

  case 131:
#line 595 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_implicit_token (); ;}
    break;

  case 132:
#line 597 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->add_implicit_token (); ;}
    break;

  case 133:
#line 599 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { complain_at (yylloc, 
      		   "lexical subrule (%s) not allowed in context-free rule",
		   (yyvsp[(1) - (1)])->as_string ().c_str ());
      YYERROR; 
    ;}
    break;

  case 135:
#line 612 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (EPILOGUE); ;}
    break;

  case 136:
#line 613 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (EPILOGUE, (yyvsp[(2) - (2)])); ;}
    break;

  case 137:
#line 621 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { lexical_lhs = (yyvsp[(1) - (2)]); lexical_rhs = EMPTY; ;}
    break;

  case 138:
#line 622 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { make_plain_lexical_rule (); ;}
    break;

  case 139:
#line 623 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { lexical_lhs = NULL; lexical_rhs = EMPTY; ;}
    break;

  case 140:
#line 624 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { make_plain_lexical_rule (); ;}
    break;

  case 141:
#line 626 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { NodePtr subrule;
		  if ((yyvsp[(3) - (4)])->arity () > 1)
		     subrule = TREE (LEX_SUBRULE, (yyvsp[(1) - (4)]), TREE (LEX_GROUP, (yyvsp[(3) - (4)])));
		  else
		     subrule = TREE (LEX_SUBRULE, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
		  Node::lexical_subrules.push_back (subrule); ;}
    break;

  case 142:
#line 633 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyvsp[(1) - (4)])->add_implicit_token ((yyvsp[(3) - (4)])); ;}
    break;

  case 143:
#line 635 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyvsp[(1) - (4)])->add_implicit_token ((yyvsp[(3) - (4)])); ;}
    break;

  case 146:
#line 644 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_PHRASE, (yyvsp[(1) - (1)])); ;}
    break;

  case 147:
#line 646 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (3)]), 
				                  TREE (LEX_PHRASE, (yyvsp[(3) - (3)]))); ;}
    break;

  case 148:
#line 652 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { if ((yyvsp[(1) - (4)])->is_empty_list () && (yyvsp[(3) - (4)])->is_empty_list () && 
		      (yyvsp[(4) - (4)]) == NULL && !preferred_lexical_rule) {
		          add_lexical_option ((yyvsp[(2) - (4)]));
	          } else {
		      make_plain_lexical_rule ();
                      make_lexical_rule (LIST ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)])), (yyvsp[(4) - (4)])); 
		  }
		;}
    break;

  case 149:
#line 661 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { make_plain_lexical_rule ();
                  make_lexical_rule (LIST ((yyvsp[(1) - (5)]), TREE (ENDFILE)), (yyvsp[(5) - (5)])); 
		;}
    break;

  case 151:
#line 668 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = APPEND ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 153:
#line 674 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SUB, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
                             (yyval)->set_loc ((yyvsp[(2) - (3)])->get_loc ()); ;}
    break;

  case 156:
#line 681 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_STAR, (yyvsp[(1) - (2)])); ;}
    break;

  case 157:
#line 682 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_PLUS, (yyvsp[(1) - (2)])); ;}
    break;

  case 158:
#line 683 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_OPT, (yyvsp[(1) - (2)])); ;}
    break;

  case 159:
#line 687 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_REF, (yyvsp[(1) - (1)])); ;}
    break;

  case 160:
#line 688 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_GROUP, (yyvsp[(2) - (3)])); ;}
    break;

  case 161:
#line 689 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)])); ;}
    break;

  case 162:
#line 690 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_STRING, (yyvsp[(1) - (1)])); ;}
    break;

  case 164:
#line 695 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, O_RANGE(001, 376));  ;}
    break;

  case 165:
#line 696 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE('A', 'Z')); ;}
    break;

  case 166:
#line 697 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE('a', 'z')); ;}
    break;

  case 167:
#line 698 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE('A', 'Z'), RANGE('a', 'z')); ;}
    break;

  case 168:
#line 699 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE('0', '9')); ;}
    break;

  case 169:
#line 700 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE('0', '9'), 
                              RANGE('a', 'f'), RANGE('A', 'F')); ;}
    break;

  case 170:
#line 702 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE(0, 9), 
                              RANGE('A', 'Z'), RANGE('a', 'z')); ;}
    break;

  case 171:
#line 704 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE(' ', ' '), RANGE('\t', '\t'),
                              RANGE('\n', '\n'), RANGE('\r', '\r'),
                              RANGE('\f', '\f'), RANGE('\v', '\v')); ;}
    break;

  case 172:
#line 707 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE(' ', ' '), RANGE('\t', '\t')); ;}
    break;

  case 173:
#line 708 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, O_RANGE(001, 037), O_RANGE(177, 177)); ;}
    break;

  case 174:
#line 709 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE('!', '~')); ;}
    break;

  case 175:
#line 710 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE(' ', '~')); ;}
    break;

  case 176:
#line 711 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, RANGE('!', '/'), RANGE(':', '@'), 
                              RANGE('[', '`'), RANGE('{', '~')); ;}
    break;

  case 177:
#line 716 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (LEX_SET, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 178:
#line 720 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; ;}
    break;

  case 179:
#line 721 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (BOL); ;}
    break;

  case 180:
#line 725 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = EMPTY; ;}
    break;

  case 181:
#line 726 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (EOL); ;}
    break;

  case 182:
#line 727 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (ENDFILE); ;}
    break;

  case 184:
#line 732 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { preferred_lexical_rule = true; ;}
    break;

  case 185:
#line 736 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = TREE (ACTION, stripped ((yyvsp[(1) - (1)]))); 
  				     delete (yyvsp[(1) - (1)]); ;}
    break;

  case 186:
#line 741 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = stripped ((yyvsp[(1) - (1)])); ;}
    break;

  case 187:
#line 742 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"
    { (yyval) = NULL; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2707 "parse-horn.cc"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
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


#line 745 "/Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/root/src/horn/src/parse-horn.y"


#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

static void 
excluded_feature (const string& feature_name)
{
    complain ("Bison feature %s is not part of the Horn dialect",
    	      feature_name.c_str ());
}

static symbol_convention
as_convention(const lstring& sym)
{
    if (sym.compare_folded ("ANY") == 0)
      return ANYSYM;
    if (sym.compare_folded ("LOW") == 0)
      return LOWSYM;
    if (sym.compare_folded ("CAP") == 0)
      return CAPSYM;
    if (sym.compare_folded ("ALLCAP") == 0)
      return ALLCAPSYM;
    else {
        complain ("Unknown symbol capitalization convention");
        return CAP_LOW;
    }
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

    if (lexical_rhs->is_list () && lexical_rhs->arity () > 1) {
	new_rhs = TREE (LEX_GROUP, lexical_rhs);
	delete lexical_rhs;
    } else if (lexical_rhs->is_list () && lexical_rhs->arity () == 0)
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
	result->add (TREE (RHS, rhs_accum->copy (), annotations)
        ->normalize_action ());
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
	} else if (child->oper ()->syntax () == '?') {
            syms->replace (k, EMPTY);
            NodePtr new_syms = syms->copy ();
            new_syms->add (child->child (0), k);
            make_rhses_1 (result, rhs_accum->copy (), new_syms, k,
                          annotations);
            make_rhses_1 (result, rhs_accum->copy (), syms->copy(), 
	                  k, annotations);
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

string api_namespace;

static string file_dir;

static void
set_data_dir(const char* dir)
{
    const char* dirSep = DIRECTORY_SEPARATOR;
    const int sepLen = sizeof(dirSep) - 1;
    data_dir = dir;
    while (sepLen < data_dir.size()
           && data_dir.compare (data_dir.size() - sepLen, sepLen, dirSep)
           == 0) {
        data_dir.erase (data_dir.size() - sepLen);
    }
    data_dir += dirSep;
}

static void
process_args (int argc, char* argv[])
{
    file_root = "";
    lexical_outfile = "";
    infile = "";
    token_factory = "";
    set_data_dir(DATA_DIR);
    
    int i;
    for (i = 1; i < argc; i += 1) {
	if (string("-o") == argv[i] && i < argc-1) {
	    file_root = argv[i+1];
	    i += 1;
        } else if (string(argv[i]).compare(0, 10, "--datadir=") == 0) {
	    set_data_dir(argv[i]+10);
	} else if (argv[i][0] == '-')
	    Usage ();
	else
	    break;
    }

    if (i < argc-1)
	Usage ();
    else if (i == argc-1)
	infile = argv[i];

    if (file_root == "" && infile == "")
	file_root = "yy";
    else if (file_root == "") {
	file_root = infile;
	size_t tail = file_root.rfind (DIRECTORY_SEPARATOR);
	if (tail == string::npos)
	    tail = 0;
	size_t ext = file_root.find ('.', tail);
	if (ext != string::npos) 
	    file_root.erase (ext, string::npos);
    }

    {
	file_dir = file_root;
	size_t tail = file_dir.rfind (DIRECTORY_SEPARATOR);
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

    exit (0);
}

