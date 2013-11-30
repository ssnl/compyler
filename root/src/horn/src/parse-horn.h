/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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
