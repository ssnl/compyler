/* A Bison parser, made by GNU Bison 2.7.1131-17b8-dirty.  */

/* Bison interface for Yacc-like parsers in C

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
