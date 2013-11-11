/* A Bison parser, made by GNU Bison 2.7.1131-17b8-dirty.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "2.7.1131-17b8-dirty"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:357  */

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

#line 178 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:357  */

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
        


#line 150 "parse-horn.cc" /* yacc.c:357  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse-horn.h".  */
#ifndef YY_YY_PARSE_HORN_H_INCLUDED
# define YY_YY_PARSE_HORN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_HORN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 320 "parse-horn.cc" /* yacc.c:376  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#ifdef __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   358

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "cf_symbol", "string_as_id", "epilogue.opt", "lexical_rule", "$@1",
  "$@2", "lexical_rhs", "lexical_rhs_no_rules", "lexical_rhs_primaries",
  "lexical_primaries", "lexical_term", "lexical_primary", "lexical_atom",
  "predefined_atoms", "char_range", "lexical_prefix", "lexical_suffix",
  "preferred.opt", "action", "bare_action.opt", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -210

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-210)))

#define YYTABLE_NINF -136

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
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

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
#line 239 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { theTree = TREE (GRAMMAR, TREE (PROLOGUE, (yyvsp[-3])),   
			  	          TREE (RULES, (yyvsp[-1])), (yyvsp[0])); }
#line 1761 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 3:
#line 241 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { theTree = TREE (NONE); }
#line 1767 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 4:
#line 250 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; }
#line 1773 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 5:
#line 252 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 1779 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 6:
#line 254 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = (yyvsp[-2]); }
#line 1785 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 7:
#line 255 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; }
#line 1791 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 11:
#line 263 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { set_lexical_convention((symbol_convention)
			   (as_convention ((yyvsp[-1])->text ()) * 4 +
			    as_convention ((yyvsp[0])->text ())));
    (yyval) = EMPTY; }
#line 1800 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 12:
#line 267 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { 
  	 std::string variable = (yyvsp[-1])->as_string ();
	 std::string content = strip_quotes ((yyvsp[0])->as_string ());
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
	     (yyval) = LIST ((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));  }
#line 1849 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 14:
#line 312 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1855 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 16:
#line 314 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1861 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 17:
#line 315 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1867 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 18:
#line 316 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; 
  	    			     excluded_feature ("%file-prefix"); }
#line 1874 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 20:
#line 319 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (SYNC); 
  				     interactive_parser = true; }
#line 1881 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 21:
#line 321 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1887 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 22:
#line 322 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1893 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 23:
#line 323 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1899 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 26:
#line 326 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; 
  	    			     excluded_feature ("%output"); }
#line 1906 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 27:
#line 328 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1912 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 28:
#line 329 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1918 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 29:
#line 330 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1924 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 34:
#line 338 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1930 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 38:
#line 350 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1936 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 39:
#line 352 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1942 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 40:
#line 354 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1948 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 43:
#line 357 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1954 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 44:
#line 358 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1960 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 45:
#line 369 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (NONE); }
#line 1966 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 47:
#line 374 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY;
    	   	      		    excluded_feature ("%union"); }
#line 1973 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 48:
#line 379 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; excluded_feature ("%nterm"); }
#line 1979 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 49:
#line 380 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 1985 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 50:
#line 381 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; excluded_feature ("%type"); }
#line 1991 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 51:
#line 386 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1997 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 56:
#line 397 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (NONE); }
#line 2003 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 57:
#line 398 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (NONE);
  				    excluded_feature ("<...> tagging"); }
#line 2010 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 59:
#line 405 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2016 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 61:
#line 410 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); }
#line 2022 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 63:
#line 416 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2028 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 65:
#line 422 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2034 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 70:
#line 434 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = (yyvsp[0]); (yyvsp[0])->add_explicit_token (); }
#line 2040 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 71:
#line 435 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = (yyvsp[0]); (yyvsp[0])->add_explicit_token (); }
#line 2046 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 72:
#line 436 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); 
     				    (yyvsp[-1])->add_explicit_token ();}
#line 2053 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 73:
#line 438 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); 
     				    (yyvsp[-1])->add_explicit_token ((yyvsp[0])); }
#line 2060 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 74:
#line 440 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-1]), (yyvsp[0])); 
     				    (yyvsp[-1])->add_explicit_token ((yyvsp[0])); }
#line 2067 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 75:
#line 442 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = LIST ((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); 
     	 			    (yyvsp[-2])->add_explicit_token ((yyvsp[0])); }
#line 2074 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 76:
#line 444 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { excluded_feature ("<...> tagging"); 
  				    (yyval) = TREE (NONE); }
#line 2081 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 77:
#line 446 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { complain ("Attempt to redefine value of "
                                              "character token.");
                                    (yyval) = TREE (NONE); }
#line 2089 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 78:
#line 449 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { complain ("Attempt to redefine value of "
                                              "character token.");
                                    (yyval) = TREE (NONE); }
#line 2097 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 80:
#line 456 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2103 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 82:
#line 467 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2109 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 84:
#line 474 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (GRAMMAR_DECLARATION, (yyvsp[-1]), (yyvsp[0])); }
#line 2115 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 85:
#line 475 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; yyerrok; }
#line 2121 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 86:
#line 480 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (RULE, (yyvsp[-3]), 
				               TREE (RHS_CHOICES, (yyvsp[-1]))); }
#line 2128 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 87:
#line 482 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; }
#line 2134 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 88:
#line 486 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = make_rhses ((yyvsp[0])); }
#line 2140 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 89:
#line 487 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-2]), make_rhses ((yyvsp[0]))); }
#line 2146 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 92:
#line 496 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2152 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 93:
#line 497 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2158 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 94:
#line 498 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2164 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 95:
#line 499 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2170 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 96:
#line 500 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = (yyvsp[0]); }
#line 2176 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 97:
#line 504 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; }
#line 2182 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 98:
#line 505 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = (yyvsp[0]); }
#line 2188 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 100:
#line 510 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE ('?', (yyvsp[-1])); }
#line 2194 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 101:
#line 511 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE ('*', (yyvsp[-1])); }
#line 2200 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 102:
#line 512 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE ('+', (yyvsp[-1])); }
#line 2206 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 104:
#line 518 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { if (!producing_trees) 
                     complain ("Must declare tree type to use '^'");
		  (yyval) = TREE ('^', (yyvsp[-1])); }
#line 2214 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 105:
#line 522 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE ('!', (yyvsp[-1])); }
#line 2220 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 106:
#line 523 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE ('(', TREE (RHS_CHOICES, (yyvsp[-1]))); }
#line 2226 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 108:
#line 528 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE ((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2232 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 109:
#line 529 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE ((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2238 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 110:
#line 533 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[-1])), (yyvsp[0])); }
#line 2245 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 111:
#line 535 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[-1])), (yyvsp[0])); }
#line 2252 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 112:
#line 537 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { rule_annotations =
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[-1])), (yyvsp[0])); }
#line 2259 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 113:
#line 539 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { rule_annotations =
  	  		     APPEND (APPEND (rule_annotations, (yyvsp[-1])), (yyvsp[0])); }
#line 2266 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 114:
#line 541 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { excluded_feature ("%merge"); }
#line 2272 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 115:
#line 542 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { expand_rule = true; }
#line 2278 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 118:
#line 556 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = No_Token; }
#line 2284 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 131:
#line 595 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = (yyvsp[0]); (yyvsp[0])->add_implicit_token (); }
#line 2290 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 132:
#line 597 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = (yyvsp[0]); (yyvsp[0])->add_implicit_token (); }
#line 2296 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 133:
#line 599 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { complain_at (yylloc, 
      		   "lexical subrule (%s) not allowed in context-free rule",
		   (yyvsp[0])->as_string ().c_str ());
      YYERROR; 
    }
#line 2306 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 135:
#line 612 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (EPILOGUE); }
#line 2312 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 136:
#line 613 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (EPILOGUE, (yyvsp[0])); }
#line 2318 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 137:
#line 621 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { lexical_lhs = (yyvsp[-1]); lexical_rhs = EMPTY; }
#line 2324 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 138:
#line 622 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { make_plain_lexical_rule (); }
#line 2330 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 139:
#line 623 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { lexical_lhs = NULL; lexical_rhs = EMPTY; }
#line 2336 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 140:
#line 624 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { make_plain_lexical_rule (); }
#line 2342 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 141:
#line 626 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { NodePtr subrule;
		  if ((yyvsp[-1])->arity () > 1)
		     subrule = TREE (LEX_SUBRULE, (yyvsp[-3]), TREE (LEX_GROUP, (yyvsp[-1])));
		  else
		     subrule = TREE (LEX_SUBRULE, (yyvsp[-3]), (yyvsp[-1]));
		  Node::lexical_subrules.push_back (subrule); }
#line 2353 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 142:
#line 633 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyvsp[-3])->add_implicit_token ((yyvsp[-1])); }
#line 2359 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 143:
#line 635 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyvsp[-3])->add_implicit_token ((yyvsp[-1])); }
#line 2365 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 146:
#line 644 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_PHRASE, (yyvsp[0])); }
#line 2371 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 147:
#line 646 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-2]), 
				                  TREE (LEX_PHRASE, (yyvsp[0]))); }
#line 2378 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 148:
#line 652 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { if ((yyvsp[-3])->is_empty_list () && (yyvsp[-1])->is_empty_list () && 
		      (yyvsp[0]) == NULL && !preferred_lexical_rule) {
		          add_lexical_option ((yyvsp[-2]));
	          } else {
		      make_plain_lexical_rule ();
                      make_lexical_rule (LIST ((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1])), (yyvsp[0])); 
		  }
		}
#line 2391 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 149:
#line 661 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { make_plain_lexical_rule ();
                  make_lexical_rule (LIST ((yyvsp[-4]), TREE (ENDFILE)), (yyvsp[0])); 
		}
#line 2399 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 151:
#line 668 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = APPEND ((yyvsp[-1]), (yyvsp[0])); }
#line 2405 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 153:
#line 674 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SUB, (yyvsp[-2]), (yyvsp[0])); 
                             (yyval)->set_loc ((yyvsp[-1])->get_loc ()); }
#line 2412 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 156:
#line 681 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_STAR, (yyvsp[-1])); }
#line 2418 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 157:
#line 682 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_PLUS, (yyvsp[-1])); }
#line 2424 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 158:
#line 683 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_OPT, (yyvsp[-1])); }
#line 2430 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 159:
#line 687 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_REF, (yyvsp[0])); }
#line 2436 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 160:
#line 688 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_GROUP, (yyvsp[-1])); }
#line 2442 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 161:
#line 689 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, (yyvsp[0]), (yyvsp[0])); }
#line 2448 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 162:
#line 690 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_STRING, (yyvsp[0])); }
#line 2454 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 164:
#line 695 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, O_RANGE(001, 376));  }
#line 2460 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 165:
#line 696 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE('A', 'Z')); }
#line 2466 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 166:
#line 697 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE('a', 'z')); }
#line 2472 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 167:
#line 698 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE('A', 'Z'), RANGE('a', 'z')); }
#line 2478 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 168:
#line 699 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE('0', '9')); }
#line 2484 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 169:
#line 700 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE('0', '9'), 
                              RANGE('a', 'f'), RANGE('A', 'F')); }
#line 2491 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 170:
#line 702 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE(0, 9), 
                              RANGE('A', 'Z'), RANGE('a', 'z')); }
#line 2498 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 171:
#line 704 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE(' ', ' '), RANGE('\t', '\t'),
                              RANGE('\n', '\n'), RANGE('\r', '\r'),
                              RANGE('\f', '\f'), RANGE('\v', '\v')); }
#line 2506 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 172:
#line 707 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE(' ', ' '), RANGE('\t', '\t')); }
#line 2512 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 173:
#line 708 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, O_RANGE(001, 037), O_RANGE(177, 177)); }
#line 2518 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 174:
#line 709 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE('!', '~')); }
#line 2524 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 175:
#line 710 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE(' ', '~')); }
#line 2530 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 176:
#line 711 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, RANGE('!', '/'), RANGE(':', '@'), 
                              RANGE('[', '`'), RANGE('{', '~')); }
#line 2537 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 177:
#line 716 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (LEX_SET, (yyvsp[-2]), (yyvsp[0])); }
#line 2543 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 178:
#line 720 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; }
#line 2549 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 179:
#line 721 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (BOL); }
#line 2555 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 180:
#line 725 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = EMPTY; }
#line 2561 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 181:
#line 726 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (EOL); }
#line 2567 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 182:
#line 727 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (ENDFILE); }
#line 2573 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 184:
#line 732 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { preferred_lexical_rule = true; }
#line 2579 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 185:
#line 736 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = TREE (ACTION, stripped ((yyvsp[0]))); 
  				     delete (yyvsp[0]); }
#line 2586 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 186:
#line 741 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = stripped ((yyvsp[0])); }
#line 2592 "parse-horn.cc" /* yacc.c:1669  */
    break;

  case 187:
#line 742 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1669  */
    { (yyval) = NULL; }
#line 2598 "parse-horn.cc" /* yacc.c:1669  */
    break;


#line 2602 "parse-horn.cc" /* yacc.c:1669  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 745 "/home/cs/hilfingr/work/grammars/horn/parse-horn.y" /* yacc.c:1929  */


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
