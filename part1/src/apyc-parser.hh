/* A Bison parser, made by GNU Bison 3.0.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_YY_APYC_PARSER_HH_INCLUDED
# define YY_YY_APYC_PARSER_HH_INCLUDED
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
    ID = 258,
    PRINTLN = 259,
    EMPTY = 260,
    EXPR_LIST = 261,
    MODULE = 262,
    BINOP = 263,
    UNOP = 264,
    INDENT = 265,
    DEDENT = 266,
    STMT_LIST = 267,
    PRINT = 268,
    RETURN = 269,
    BREAK = 270,
    CONTINUE = 271,
    NATIVE = 272,
    IF = 273,
    FOR = 274,
    WHILE = 275,
    BLOCK = 276,
    ASSIGN = 277,
    TARGET_LIST = 278,
    ATTR_REF = 279,
    SUBSCRIPTION = 280,
    SLICING = 281,
    TYPE = 282,
    TYPED_ID = 283,
    TYPE_VAR = 284,
    TYPE_LIST = 285,
    TYPE_FORMALS_LIST = 286,
    FORMALS_LIST = 287,
    FUNCT_TYPE = 288,
    DEFINITION = 289,
    CLASS = 290,
    COMPARE = 291,
    LCOMPARE = 292,
    AND = 293,
    OR = 294,
    IF_EXPR = 295,
    TUPLE = 296,
    LIST = 297,
    DICT = 298,
    PAIR = 299,
    CALL = 300,
    EXPO = 301,
    ISNOT = 302,
    NOTIN = 303,
    _TOK_23 = 306,
    _TOK_17 = 307,
    _TOK_25 = 308,
    _TOK_3 = 309,
    _TOK_20 = 310,
    _TOK_22 = 311,
    _TOK_21 = 312,
    _TOK_16 = 313,
    _TOK_18 = 314,
    _TOK_6 = 315,
    _TOK_0 = 316,
    _TOK_7 = 317,
    _TOK_2 = 318,
    _TOK_12 = 319,
    _TOK_13 = 320,
    _TOK_8 = 321,
    _TOK_11 = 322,
    _TOK_9 = 323,
    _TOK_24 = 324,
    _TOK_14 = 325,
    _TOK_26 = 326,
    _TOK_1 = 327,
    _TOK_19 = 328,
    _TOK_4 = 329,
    _TOK_15 = 330,
    _TOK_5 = 331,
    _TOK_10 = 332,
    BADSTRING = 333,
    BLANK_LINE = 334,
    END_OF_FILE = 335,
    INDENTATION = 336,
    INT_LITERAL = 337,
    NEWLINE = 338,
    RAWSTRING = 339,
    STRING = 340,
    UNUSED_KEYWORD = 341
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_APYC_PARSER_HH_INCLUDED  */
