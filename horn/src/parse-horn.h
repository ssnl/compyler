/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;

