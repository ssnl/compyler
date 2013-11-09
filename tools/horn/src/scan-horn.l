/* -*- c-file-style: "stroustrup"; -*- */

/* Bison Grammar Scanner                             -*- C -*-

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

/* Copyright (C) 2010 by the Regents of the University of California. */

%option nodefault noinput nounput noyywrap never-interactive
%option prefix="gram_"

%{

#include <climits>
#include "horn.h"
#include "parse-horn.h"

using namespace std;

#define FLEX_PREFIX(Id) gram_ ## Id

static size_t no_cr_read (FILE *, char *, size_t);

static void handle_syncline (char *, location);
static void unexpected_eof (const char *, char const *);
static void unexpected_newline (const char *, char const *);

static int percent_percent_count;


%}
 /* Strings and characters in directives/rules. */
%x SC_ESCAPED_STRING SC_ESCAPED_CHARACTER
 /* A complex tag, with nested angles brackets. */
%x SC_TAG

 /* Four types of user code:
    - prologue (code between `%{' `%}' in the first section, before %%);
    - actions, printers, union, etc, (between braced in the middle section);
    - epilogue (everything after the second %%). 
    - predicate (code between `%?{' and `{' in middle section); */
%x SC_PROLOGUE SC_BRACED_CODE SC_EPILOGUE SC_PREDICATE
 /* C and C++ comments in code. */
%x SC_COMMENT SC_LINE_COMMENT
 /* Strings and characters in code. */
%x SC_STRING SC_CHARACTER

upper_letter [A-Z]
lower_letter [a-z]

letter	  "_"|{upper_letter}|{lower_letter}
id_tail   ({letter}|[0-9])*
upper_id  {upper_letter}{id_tail}
lower_id  {lower_letter}{id_tail}
underscore_id "_"{id_tail}
id	  {letter}({letter}|[0-9])*
directive %{id}
int	  [0-9]+

/* POSIX says that a tag must be both an id and a C union member, but
   historically almost any character is allowed in a tag.  We disallow
   NUL, as this simplifies our implementation.  We disallow angle
   bracket to match them in nested pairs: several languages use them
   for generics/template types.  */
tag	 [^\0<>]+

/* Zero or more instances of backslash-newline.  Following GCC, allow
   white space between the backslash and the newline.  */
splice	 (\\[ \f\t\v]*\n)*

ccomment ("/*"([^*]|"*"+[^*/])*"*"+"/")
ws       ({splice}|[ \f\n\t\v]|"//".*|{ccomment})*

%%
%{
  /* Nesting level.  Either for nested braces, or nested angle brackets
     (but not mixed).  */
  int nesting;

  /* Parent context state, when applicable.  */
  int context_state;

%}


  /*-----------------------.
  | Scanning white space.  |
  `-----------------------*/

<INITIAL>
{
  /* Comments and white space.  */
  ","	       warn_at (yytext, _("stray `,' treated as white space"));
  {ws}         { }

  ^"#line "{int}" \"".*"\"\n" {
    handle_syncline (yytext + sizeof "#line " - 1, yytext);
  }
}


  /*----------------------------.
  | Scanning Bison directives.  |
  `----------------------------*/

  /* For directives that are also command line options, the regex must be
	"%..."
     after "[-_]"s are removed, and the directive must match the --long
     option name, with a single string argument.  Otherwise, add exceptions
     to ../build-aux/cross-options.pl.  */

<INITIAL>
{
  "%code"                           return PERCENT_CODE;
  "%debug"                          return PERCENT_FLAG;
  "%default"[-_]"prec"              return PERCENT_DEFAULT_PREC;
  "%define"                         return PERCENT_DEFINE;
  "%defines"                        return PERCENT_DEFINES;
  "%destructor"                     return PERCENT_DESTRUCTOR;
  "%dprec"                          return PERCENT_DPREC;
  "%error"[-_]"verbose"             return PERCENT_ERROR_VERBOSE;
  "%expect"                         return PERCENT_EXPECT;
  "%expect"[-_]"rr"                 return PERCENT_EXPECT_RR;
  "%file-prefix"                    return PERCENT_FILE_PREFIX;
  "%fixed"[-_]"output"[-_]"files"   return PERCENT_YACC;
  "%initial-action"                 return PERCENT_INITIAL_ACTION;
  "%glr-parser"                     return PERCENT_GLR_PARSER;
  "%interactive"                    return PERCENT_INTERACTIVE;
  "%language"                       return PERCENT_LANGUAGE;
  "%left"                           return PERCENT_LEFT;
  "%lex-param"                      return PERCENT_PARAM;
  "%locations"                      return PERCENT_FLAG;
  "%merge"                          return PERCENT_MERGE;
  "%name"[-_]"prefix"               return PERCENT_NAME_PREFIX;
  "%no"[-_]"default"[-_]"prec"      return PERCENT_NO_DEFAULT_PREC;
  "%no"[-_]"lines"                  return PERCENT_NO_LINES;
  "%nonassoc"                       return PERCENT_NONASSOC;
  "%nondeterministic-parser"        return PERCENT_NONDETERMINISTIC_PARSER;
  "%nterm"                          return PERCENT_NTERM;
  "%output"                         return PERCENT_OUTPUT;
  "%param"                          return PERCENT_PARAM;
  "%parse-param"                    return PERCENT_PARAM;
  "%prec"                           return PERCENT_PREC;
  "%precedence"                     return PERCENT_PRECEDENCE;
  "%printer"                        return PERCENT_PRINTER;
  "%pure"[-_]"parser"               return PERCENT_FLAG;
  "%require"                        return PERCENT_REQUIRE;
  "%right"                          return PERCENT_RIGHT;
  "%skeleton"                       return PERCENT_SKELETON;
  "%start"                          return PERCENT_START;
  "%term"                           return PERCENT_TOKEN;
  "%token"                          return PERCENT_TOKEN;
  "%token"[-_]"table"               return PERCENT_TOKEN_TABLE;
  "%type"                           return PERCENT_TYPE;
  "%union"                          return PERCENT_UNION;
  "%verbose"                        return PERCENT_VERBOSE;
  "%yacc"                           return PERCENT_YACC;

  "%expand"                         return PERCENT_EXPAND;
  "%prefer"                         return PERCENT_PREFER;

  "_ANY"                            return ANY;
  "_BOL"                            return BOL;
  "_EOL"                            return EOL;
  "_EOF"                            return ENDFILE;

  {directive} {
    complain_at (yytext, _("invalid directive: '%s'"), yytext);
  }

  [-+*?=|;():^!]                    return yytext[0];
  "+="                              return PLUS_EQ;

  ".."                              return DOTDOT;

  {underscore_id}                   return UNDERSCORE_ID;
  {upper_id}                        return UPPER_ID;
  {lower_id}                        return LOWER_ID;
  ({letter}|".")+                   return OTHER_ID;

  {int}				     |
  0[xX][0-9abcdefABCDEF]+ 	     return INT;

  /* Identifiers may not start with a digit.  Yet, don't silently
     accept "1FOO" as "1 FOO".  */
  {int}{id} {
    complain_at (yytext, _("invalid identifier: '%s'"), yytext);
  }

  /* Characters.  */
  "'"	      { BEGIN SC_ESCAPED_CHARACTER; yymore (); }

  /* Strings. */
  "\""	      { BEGIN SC_ESCAPED_STRING; yymore (); }

  /* Prologue. */
  "%{"        { BEGIN SC_PROLOGUE; yymore (); }

  /* Code in between braces.  */
  "{" {
    nesting = 0;
    BEGIN SC_BRACED_CODE;
    yymore ();
  }

  /* Semantic predicate. */
  "%?"[ \f\n\t\v]*"{" {
    nesting = 0;
    BEGIN SC_PREDICATE;
    yymore ();
  }

  /* A type. */
  "<*>"       return TAG_ANY;
  "<>"        return TAG_NONE;
  "<"{tag}">" return TAG;
  "<"         {
    nesting = 0;
    BEGIN SC_TAG;
    yymore ();
  }

  "%%" {
    if ((percent_percent_count += 1) == 2)
      BEGIN SC_EPILOGUE;
    return PERCENT_PERCENT;
  }

  . {
    complain_at (yytext, _("invalid character: '%s'"), yytext);
  }

  <<EOF>> {
    while (yyleng > 0 && yytext[yyleng-1] == '\0')
        yyleng -= 1;
    yyterminate ();
  }
}


  /*--------------------------------------------------------------.
  | Supporting \0 complexifies our implementation for no expected |
  | added value.                                                  |
  `--------------------------------------------------------------*/

<SC_ESCAPED_CHARACTER,SC_ESCAPED_STRING,SC_TAG>
{
  \0	    complain_at (yytext, _("invalid null character"));
}


  /*------------------------------------------------------------.
  | Scanning a C comment.  The initial `/ *' is already eaten.  |
  `------------------------------------------------------------*/

<SC_COMMENT>
{
  "*"{splice}"/"  { yymore (); BEGIN context_state; }
  <<EOF>>	  unexpected_eof (yytext, "*/"); BEGIN context_state;
}


  /*--------------------------------------------------------------.
  | Scanning a line comment.  The initial `//' is already eaten.  |
  `--------------------------------------------------------------*/

<SC_LINE_COMMENT>
{
  "\n"		 { yymore (); BEGIN context_state; }
  {splice}	 yymore ();
  <<EOF>>	 { yymore (); BEGIN context_state; }
}


  /*------------------------------------------------.
  | Scanning a Bison string, including its escapes. |
  | The initial quote is already eaten.             |
  `------------------------------------------------*/

<SC_ESCAPED_STRING>
{
  "\""|"\n" {
    if (yytext[0] == '\n')
      unexpected_newline (yytext, "\"");
    BEGIN INITIAL;
    return STRING;
  }
  <<EOF>> {
    unexpected_eof (yytext, "\"");
    BEGIN INITIAL;
    return STRING;
  }
}

  /*------------------------------------.
  | Scanning a Bison character literal. |
  `------------------------------------*/

<SC_ESCAPED_CHARACTER>
{
  "'"|"\n" {
    if (yytext[0] == '\n')
      unexpected_newline (yytext, "'");
    BEGIN INITIAL;
    if (real_length (string (yytext+1, yyleng-2)) != 1)
        complain_at (yytext, 
                     "single-quoted literals must contain one character");
    return CHAR;
  }
  <<EOF>> {
    unexpected_eof (yytext, "'");
    BEGIN INITIAL;
    return CHAR;
  }
}

  /*-----------------------------------------------------------.
  | Scanning a Bison nested tag.  The initial angle bracket is |
  | already eaten.                                             |
  `-----------------------------------------------------------*/

<SC_TAG>
{
  ">" {
    --nesting;
    if (nesting < 0)
      {
        BEGIN INITIAL;
        return TAG;
      }
    yymore ();
  }

  [^<>]+ 	{ yymore (); }
  "<"           { nesting += 1; yymore (); }

  <<EOF>> {
    unexpected_eof (yytext, ">");
    BEGIN INITIAL;
    return TAG;
  }
}

  /*----------------------------.
  | Decode escaped characters.  |
  `----------------------------*/

<SC_ESCAPED_STRING,SC_ESCAPED_CHARACTER>
{
  \\X                   { complain_at (yytext, "invalid escape: \\X"); }
  \\x                   { complain_at (yytext, "invalid \\x escape"); }
  \\[0-7]{1,3} 		|
  \\x[0-9abcdefABCDEF]+ |
  \\[abfnrtv]		|
  \\("\""|"'"|"?"|"\\") |
  \\(.|\n)	        { yymore (); }

  \\(u|U[0-9abcdefABCDEF]{4})[0-9abcdefABCDEF]{4} {
                          complain_at (yytext, "Unicode escapes not currently supported."); }

}

  /*--------------------------------------------.
  | Scanning user-code characters and strings.  |
  `--------------------------------------------*/

<SC_CHARACTER,SC_STRING>
{
  {splice}|\\{splice}[^\n\[\]]	{ yymore (); }
}

<SC_CHARACTER>
{
  "'"		{ BEGIN context_state; yymore (); }
  \n		{ unexpected_newline (yytext, "'"); BEGIN context_state; }
  <<EOF>>	{ unexpected_eof (yytext, "'"); BEGIN context_state; }
}

<SC_STRING>
{
  "\""		{ BEGIN context_state; yymore (); }
  \n		{ unexpected_newline (yytext, "\""); BEGIN context_state; }
  <<EOF>>	{ unexpected_eof (yytext, "\""); BEGIN context_state; }
}


  /*---------------------------------------------------.
  | Strings, comments etc. can be found in user code.  |
  `---------------------------------------------------*/

<SC_BRACED_CODE,SC_PROLOGUE,SC_EPILOGUE,SC_PREDICATE>
{
  "'" {
    context_state = YY_START;
    yymore ();
    BEGIN SC_CHARACTER;
  }
  "\"" {
    context_state = YY_START;
    yymore ();
    BEGIN SC_STRING;
  }
  "/"{splice}"*" {
    context_state = YY_START;
    yymore ();
    BEGIN SC_COMMENT;
  }
  "/"{splice}"/" {
    context_state = YY_START;
    yymore ();
    BEGIN SC_LINE_COMMENT;
  }
}



  /*----------------------------------------------------.
  | Scanning some code in braces (actions, predicates). |
  `----------------------------------------------------*/

<SC_BRACED_CODE,SC_PREDICATE>
{
  "{"|"<"{splice}"%"  { nesting++; yymore (); }
  "%"{splice}">"      { nesting--; yymore (); }

  "<"{splice}"<"      { yymore (); }

  <<EOF>> {
    int token = (YY_START == SC_BRACED_CODE) ? BRACED_CODE : BRACED_PREDICATE;
    unexpected_eof (yytext, "}");
    BEGIN INITIAL;
    return token;
  }
}

<SC_BRACED_CODE>
{
  "}" {
    --nesting;
    if (nesting < 0)
      {
	BEGIN INITIAL;
	return BRACED_CODE;
      }
    else
      yymore ();
  }
}

<SC_PREDICATE>
{
  "}" {
    --nesting;
    if (nesting < 0)
      {
	BEGIN INITIAL;
	return BRACED_PREDICATE;
      }
    else
      yymore ();
  }
}

  /*--------------------------------------------------------------.
  | Scanning some prologue: from "%{" (already scanned) to "%}".  |
  `--------------------------------------------------------------*/

<SC_PROLOGUE>
{
  "%}" {
    BEGIN INITIAL;
    return PROLOGUE;
  }

  <<EOF>> {
    unexpected_eof (yytext, "%}");
    BEGIN INITIAL;
    return PROLOGUE;
  }
}


  /*---------------------------------------------------------------.
  | Scanning the epilogue (everything after the second "%%", which |
  | has already been eaten).                                       |
  `---------------------------------------------------------------*/

<SC_EPILOGUE>
{
  <<EOF>> {
    BEGIN INITIAL;
    while (yyleng > 0 && yytext[yyleng-1] == '\0')
        yyleng -= 1;
    return EPILOGUE;
  }
}


<SC_COMMENT,SC_LINE_COMMENT,SC_BRACED_CODE,SC_PREDICATE,SC_PROLOGUE,SC_EPILOGUE,SC_STRING,SC_CHARACTER,SC_ESCAPED_STRING,SC_ESCAPED_CHARACTER>.	|
  <SC_COMMENT,SC_BRACED_CODE,SC_PREDICATE,SC_PROLOGUE,SC_EPILOGUE>\n	yymore ();

%%

string current_file;
string program_name;

text_buffer input_buffer;
static const char *last_token_end;

lstring last_skipped_text;


/* Read bytes from FP into buffer BUF of size SIZE.  Return the
   number of bytes read.  Remove '\r' from input, treating \r\n
   and isolated \r as \n.  */

static size_t
no_cr_read (FILE *fp, char *buf, size_t size)
{
  size_t bytes_read = fread (buf, 1, size, fp);
  if (bytes_read)
    {
      char *w = (char*) memchr (buf, '\r', bytes_read);
      if (w)
	{
	  char const *r = ++w;
	  char const *lim = buf + bytes_read;

	  for (;;)
	    {
	      /* Found an '\r'.  Treat it like '\n', but ignore any
		 '\n' that immediately follows.  */
	      w[-1] = '\n';
	      if (r == lim)
		{
		  int ch = getc (fp);
		  if (ch != '\n' && ungetc (ch, fp) != ch)
		    break;
		}
	      else if (*r == '\n')
		r++;

	      /* Copy until the next '\r'.  */
	      do
		{
		  if (r == lim)
		    return w - buf;
		}
	      while ((*w++ = *r++) != '\r');
	    }

	  return w - buf;
	}
    }

  return bytes_read;
}

/*----------------------------------------------------------------.
| Handle `#line INT "FILE"'.  ARGS has already skipped `#line '.  |
`----------------------------------------------------------------*/

static void
handle_syncline (char *args, location loc)
{
  warn_at (yytext, _("#line directives are not supported"));
  return;
}


/*----------------------------------------------------------------.
| For a token or comment starting at START, report message MSGID, |
| which should say that an end marker was found before		  |
| the expected TOKEN_END.					  |
`----------------------------------------------------------------*/

static void
unexpected_end (const char* start, char const *msgid, char const *token_end)
{
  complain_at (start, _(msgid), token_end);
}


/*------------------------------------------------------------------------.
| Report an unexpected EOF in a token or comment starting at START.       |
| An end of file was encountered and the expected TOKEN_END was missing.  |
`------------------------------------------------------------------------*/

static void
unexpected_eof (const char* start, char const *token_end)
{
  unexpected_end (start, _("missing `%s' at end of file"), token_end);
}


/*----------------------------------------.
| Likewise, but for unexpected newlines.  |
`----------------------------------------*/

static void
unexpected_newline (const char* start, char const *token_end)
{
  unexpected_end (start, _("missing `%s' at end of line"), token_end);
}


/*---------------------------------------------------------------------------.
| Initialize the scanner to scan the contents of FILE, denoting it as NAME.  |
`---------------------------------------------------------------------------*/

void
gram_scanner_initialize (FILE *input, const string& name)
{
  char chunk[YY_BUF_SIZE];
  yy_size_t chunk_size;

  input_buffer.clear ();

  while ((chunk_size = no_cr_read (input, chunk, YY_BUF_SIZE)) > 0)
    input_buffer.append (chunk, chunk_size);

  input_buffer.append ("\000\000", 2);

  last_token_end = input_buffer.data ();
  yy_switch_to_buffer (yy_scan_buffer (input_buffer.data (), 
				       input_buffer.data_size ()));

  yylloc = input_buffer.data ();
  set_err_loc (yylloc);
  current_file = name;
  percent_percent_count = 0;
}


/*----------------------------------------.
 * The line number on which *TEXT occurs. |
 `---------------------------------------*/

int
location_line_number (location loc)
{
  /* NOTE: must compensate for case where the static initialization
   * of TOKEN_LIST_OBJ precedes that of std::string. */
  int line;
  if (!init_phase_done 
      || loc == NULL
      || input_buffer.data () > loc
      || loc > input_buffer.data () + input_buffer.size () - 2)
      return 0;
  line = 1;
  for (location p = strchr (input_buffer.data (), '\n'); 
       p < loc;
       p = strchr (p+1, '\n')) {
      if (p == NULL)
          break;
      line += 1;
  }
  return line;
}

/*------------------------------------------------------------------.
 * Print LOCATION (relative to input file) on FILE in Unix format.  |
`------------------------------------------------------------------*/

int
location_print (FILE* file, location loc)
{
  return fprintf (file, "%s:%d", current_file.c_str (),
                  location_line_number (loc));
}

/*---------------------------------------------------.
| Output final buffer contents, as modified, to OUT. |
`---------------------------------------------------*/

void
gram_scanner_write_file (FILE* out)
{
  input_buffer.erase (input_buffer.data () + input_buffer.data_size () - 2,
		      2);
  input_buffer.fwrite (out);
}

/*-----------------------------------------------.
| Free all the memory allocated to the scanner.  |
`-----------------------------------------------*/

void
gram_scanner_free ()
{
  yylex_destroy ();
}

/*------------------.
| Main entry point. |
`------------------*/

int
gram_scan ()
{
    yylval = NULL;
    int c = gram_lex ();
    if (yylval == NULL)
      yylval = new Token (lstring (yytext, yyleng),
			  lstring (last_token_end, yytext - last_token_end), 
			  c);
    last_token_end = yytext + yyleng;
    yylloc = yytext;
    set_err_loc (yylloc);
    return c;
}
