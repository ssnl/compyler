/* -*- mode: fundamental; c-file-style: "stroustrup"; -*- */

%{
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

%}

%debug
%verbose
%defines
%locations
%expect 0

/* Define the tokens together with their human representation.  */
%token GRAM_EOF 0 "end of file"
%token STRING     "string"
%token INT        "integer"

%token PERCENT_TOKEN       "%token"
%token PERCENT_NTERM       "%nterm"

%token PERCENT_TYPE        "%type"
%token PERCENT_DESTRUCTOR  "%destructor"
%token PERCENT_PRINTER     "%printer"

%token PERCENT_LEFT        "%left"
%token PERCENT_RIGHT       "%right"
%token PERCENT_NONASSOC    "%nonassoc"
%token PERCENT_PRECEDENCE  "%precedence"

%token PERCENT_PREC          "%prec"
%token PERCENT_DPREC         "%dprec"
%token PERCENT_MERGE         "%merge"

/*----------------------.
| Global Declarations.  |
`----------------------*/

%token
  PERCENT_CODE            "%code"
  PERCENT_DEFAULT_PREC    "%default-prec"
  PERCENT_DEFINE          "%define"
  PERCENT_DEFINES         "%defines"
  PERCENT_ERROR_VERBOSE   "%error-verbose"
  PERCENT_EXPECT          "%expect"
  PERCENT_EXPECT_RR       "%expect-rr"
  PERCENT_FLAG            "%<flag>"
  PERCENT_FILE_PREFIX     "%file-prefix"
  PERCENT_GLR_PARSER      "%glr-parser"
  PERCENT_INTERACTIVE     "%interactive"
  PERCENT_INITIAL_ACTION  "%initial-action"
  PERCENT_LANGUAGE        "%language"
  PERCENT_NAME_PREFIX     "%name-prefix"
  PERCENT_NO_DEFAULT_PREC "%no-default-prec"
  PERCENT_NO_LINES        "%no-lines"
  PERCENT_NONDETERMINISTIC_PARSER
                          "%nondeterministic-parser"
  PERCENT_OUTPUT          "%output"
  PERCENT_REQUIRE         "%require"
  PERCENT_SKELETON        "%skeleton"
  PERCENT_START           "%start"
  PERCENT_TOKEN_TABLE     "%token-table"
  PERCENT_VERBOSE         "%verbose"
  PERCENT_YACC            "%yacc"

  PERCENT_CONVENTION      "%convention"
  PERCENT_EXPAND          "%expand"
  PERCENT_PREFER          "%prefer"
  PERCENTS

  ANY                     "_ANY"
  UPPER                   "_UPPER"
  LOWER                   "_LOWER"
  LETTER                  "_LETTER"
  DIGIT                   "_DIGIT"
  HEX                     "_HEX"
  ALNUM                   "_ALNUM"
  SPACE                   "_SPACE"
  BLANK                   "_BLANK"
  CONTROL                 "_CONTROL"
  GRAPHIC                 "_GRAPHIC"
  PRINTABLE               "_PRINTABLE"
  PUNCTUATION             "_PUNCTUATION"

  BOL			  "_BOL"
  EOL			  "_EOL"
  ENDFILE		  "_EOF"
;

%token BRACED_CODE     "{...}"
%token BRACED_PREDICATE "%?{...}"
%token CHAR            "char"
%token ':'             ":"
%token DOTDOT          ".."
%token EPILOGUE        "epilogue"
%token '='             "="
%token ID
%token TERM_ID
%token NONTERM_ID      
%token UNDERSCORE_ID
%token OTHER_ID
%token PERCENT_PERCENT "%%"
%token PLUS_EQ         "+="
%token '|'             "|"
%token PROLOGUE        "%{...%}"
%token '('             "("
%token ')'             ")"
%token ';'             ";"
%token '*'             "*"
%token '+'             "+"
%token '-'             "-"
%token '?'             "?"
%token '^'	       "^"
%token '!'	       "!"
%token TAG             "<tag>"
%token TAG_ANY         "<*>"
%token TAG_NONE        "<>"

%token PERCENT_PARAM "%param";

%token NONE "*none*" 
%token GRAMMAR "*grammar*" 
%token RULES "*rules*"
%token RULE "*rule*"
%token GRAMMAR_DECLARATION "*grammar_declaration*"
%token RHS_CHOICES  "*rhs_choices*"
%token RHS_ANNOTATIONS "*rhs_annotations*"
%token RHS "*rhs*"
%token GENERATED_RULE "*generated-rule*"
%token ACTION "*action*" 
%token TOKEN_TAG "*token*"
%token LIST_TAG "*list*"

%token LEX_GROUP
%token LEX_OPT
%token LEX_PHRASE
%token LEX_PLUS
%token LEX_SET
%token LEX_SUB
%token LEX_RULE
%token LEX_RULE_PREFERRED
%token LEX_STAR
%token LEX_SUBRULE
%token LEX_STRING
%token LEX_REF

%token SYNC

%{
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
        

%}

%token-table


                     /*==========\
                     | Grammar.  |
                     \==========*/
%%

input:
  prologue_declarations "%%" grammar epilogue.opt 
  			{ theTree = TREE (GRAMMAR, TREE (PROLOGUE, $1),   
			  	          TREE (RULES, $3), $4); }
| error                 { theTree = TREE (NONE); }
;


	/*------------------------------------.
	| Declarations: before the first %%.  |
	`------------------------------------*/

prologue_declarations:
  /* Nothing */         { $$ = EMPTY; }
| prologue_declarations prologue_declaration
  			{ $$ = APPEND ($1, $2); }
| prologue_declarations prologue_declaration error
                        { $$ = $1; }
| error                 { $$ = EMPTY; }
;

prologue_declaration:
  grammar_declaration
| "%{...%}"
| "%<flag>"
| "%convention" any_id any_id
  { set_lexical_convention((symbol_convention)
			   (as_convention ($2->text ()) * 4 +
			    as_convention ($3->text ())));
    $$ = EMPTY; }
| "%define" variable content.opt   { 
  	 std::string variable = $2->as_string ();
	 std::string content = strip_quotes ($3->as_string ());
         if (variable == "api.namespace") {
	     api_namespace = content;
	     $$ = TREE (SYNC);
	 } else if (variable == "semantic_type") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_type = content;
		 $$ = TREE (SYNC);
             }
	 } else if (variable == "semantic_tree_type") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_type = content;
		 producing_trees = true;
		 $$ = TREE (SYNC);
             }
	 } else if (variable == "semantics") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_params = content;
    	         $$ = TREE (SYNC);
             }
	 } else if (variable == "tree_semantics") {
	     if (!semantic_params.empty () || !semantic_type.empty ()) 
	         complain ("Multiple definitions of semantic type");
             else {
	         semantic_params = content;
		 producing_trees = true;
    	         $$ = TREE (SYNC);
             }
	 } else if (variable == "token_factory") {
	     token_factory = content;
             $$ = TREE (SYNC);
	 } else if (variable == "error_function") {
	     error_function_name = content;
	     $$ = TREE (SYNC);
         } else
	     $$ = LIST ($1, $2, $3);  }
| "%defines"
| "%defines" STRING	           { $$ = LIST ($1, $2); }
| "%error-verbose"
| "%expect" INT                    { $$ = LIST ($1, $2); }
| "%expect-rr" INT		   { $$ = LIST ($1, $2); }
| "%file-prefix" STRING            { $$ = EMPTY; 
  	    			     excluded_feature ("%file-prefix"); }
| "%glr-parser"
| "%interactive"		   { $$ = TREE (SYNC); 
  				     interactive_parser = true; }
| "%initial-action" "{...}"	   { $$ = LIST ($1, $2); }
| "%language" STRING		   { $$ = LIST ($1, $2); }
| "%name-prefix" STRING            { $$ = LIST ($1, $2); }
| "%no-lines"      
| "%nondeterministic-parser"
| "%output" STRING                 { $$ = EMPTY; 
  	    			     excluded_feature ("%output"); }
| "%param" params                  { $$ = LIST ($1, $2); }
| "%require" STRING                { $$ = LIST ($1, $2); }
| "%skeleton" STRING               { $$ = LIST ($1, $2); }
| "%token-table"
| "%verbose"
| "%yacc"
| ";"
;

params:
   params "{...}"                  { $$ = LIST ($1, $2); }
| "{...}"
;


/*----------------------.
| grammar_declaration.  |
`----------------------*/

grammar_declaration:
  precedence_declaration
| symbol_declaration
| "%start" symbol                 { $$ = LIST ($1, $2); }
| "%destructor" "{...}" generic_symlist
				  { $$ = LIST ($1, $2, $3); }
| "%printer" "{...}" generic_symlist
				  { $$ = LIST ($1, $2, $3); }
| "%default-prec"
| "%no-default-prec"
| "%code" braceless		  { $$ = LIST ($1, $2); }
| "%code" any_id braceless        { $$ = LIST ($1, $2, $3); }
;


/*---------.
| %union.  |
`---------*/

%token PERCENT_UNION "%union";

union_name:
  /* Nothing. */		  { $$ = TREE (NONE); }
| any_id
;

grammar_declaration:
  "%union" union_name braceless   { $$ = EMPTY;
    	   	      		    excluded_feature ("%union"); }
;

symbol_declaration:
  "%nterm" symbol_defs.1	  { $$ = EMPTY; excluded_feature ("%nterm"); }
| "%token" symbol_defs.1	  { $$ = LIST ($1, $2); }
| "%type" TAG symbols.1		  { $$ = EMPTY; excluded_feature ("%type"); }
;

precedence_declaration:
  precedence_declarator tag.opt symbols.prec
    				  { $$ = LIST ($1, $2, $3); }
;

precedence_declarator:
  "%left"
| "%right"
| "%nonassoc"
| "%precedence"
;

tag.opt:
  /* Nothing. */		  { $$ = TREE (NONE); }
| TAG	      			  { $$ = TREE (NONE);
  				    excluded_feature ("<...> tagging"); }
;

/* Just like symbols.1 but accept INT for the sake of POSIX.  */
symbols.prec:
  symbol.prec
| symbols.prec symbol.prec	  { $$ = APPEND ($1, $2); }
;

symbol.prec:
  symbol
| symbol INT			  { $$ = LIST ($1, $2); }
  ;

/* One or more symbols to be %typed. */
symbols.1:
  symbol
| symbols.1 symbol		  { $$ = APPEND ($1, $2); }
;

generic_symlist:
  generic_symlist_item
| generic_symlist generic_symlist_item
				  { $$ = APPEND ($1, $2); }
;

generic_symlist_item:
  symbol
| TAG
| "<*>"
| "<>"
;

/* One token definition.  */
symbol_def:
  TERM_ID			  { $$ = $1; $1->add_explicit_token (); }
| CHAR                            { $$ = $1; $1->add_explicit_token (); }
| TERM_ID INT			  { $$ = LIST ($1, $2); 
     				    $1->add_explicit_token ();}
| TERM_ID string_as_id		  { $$ = LIST ($1, $2); 
     				    $1->add_explicit_token ($2); }
| CHAR string_as_id		  { $$ = LIST ($1, $2); 
     				    $1->add_explicit_token ($2); }
| TERM_ID INT string_as_id	  { $$ = LIST ($1, $2, $3); 
     	 			    $1->add_explicit_token ($3); }
| TAG				  { excluded_feature ("<...> tagging"); 
  				    $$ = TREE (NONE); }
| CHAR INT                        { complain ("Attempt to redefine value of "
                                              "character token.");
                                    $$ = TREE (NONE); }
| CHAR INT string_as_id           { complain ("Attempt to redefine value of "
                                              "character token.");
                                    $$ = TREE (NONE); }
;

symbol_defs.1:
  symbol_def
| symbol_defs.1 symbol_def	  { $$ = APPEND ($1, $2); }
;


	/*------------------------------------------.
	| The grammar section: between the two %%.  |
	`------------------------------------------*/

grammar:
  rules_or_grammar_declaration
| grammar rules_or_grammar_declaration
				  { $$ = APPEND ($1, $2); }
;

/* As a Bison extension, one can use the grammar declarations in the
   body of the grammar.  */
rules_or_grammar_declaration:
  rules
| grammar_declaration ";"	  { $$ = TREE (GRAMMAR_DECLARATION, $1, $2); }
| error ";"	      		  { $$ = EMPTY; yyerrok; }
;

rules:
  NONTERM_ID ":" rhses ";"
                                  { $$ = TREE (RULE, $1, 
				               TREE (RHS_CHOICES, $3)); }
| lexical_rule                    { $$ = EMPTY; }
;

rhses:
  rhs				  { $$ = make_rhses ($1); }
| rhses "|" rhs			  { $$ = APPEND ($1, make_rhses ($3)); }
;

rhs:
  rhs.2
| rhs.1
;

rhs.1:
  rhs.primary rhs.2		  { $$ = APPEND ($1, $2); }
| action rhs.2		          { $$ = APPEND ($1, $2); }
| rhs.primary rhs.1		  { $$ = APPEND ($1, $2); }
| action rhs.1			  { $$ = APPEND ($1, $2); }
| annotation rhs.1		  { $$ = $2; }
;

rhs.2:
  /* empty */			  { $$ = EMPTY; }
| annotation rhs.2		  { $$ = $2; }
;

rhs.primary:
  rhs.atom
| rhs.atom "?"			  { $$ = TREE ('?', $1); }
| rhs.atom "*"			  { $$ = TREE ('*', $1); }
| rhs.atom "+"			  { $$ = TREE ('+', $1); }
;

rhs.atom:
  augmented_symbol
| augmented_symbol "^"
  		{ if (!producing_trees) 
                     complain ("Must declare tree type to use '^'");
		  $$ = TREE ('^', $1); }
| augmented_symbol "!"
  		{ $$ = TREE ('!', $1); }
| "(" rhses ")"			  { $$ = TREE ('(', TREE (RHS_CHOICES, $2)); }
;

augmented_symbol:
  cf_symbol
| any_id "=" cf_symbol		  { $$ = TREE ($2, $1, $3); }
| any_id "+=" cf_symbol		  { $$ = TREE ($2, $1, $3); }
;

annotation:
  "%prec" symbol	{ rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, $1), $2); }
| "%dprec" INT		{ rule_annotations = 
  	  		     APPEND (APPEND (rule_annotations, $1), $2); }
| "%expect" INT         { rule_annotations =
  	  		     APPEND (APPEND (rule_annotations, $1), $2); }
| "%expect-rr" INT      { rule_annotations =
  	  		     APPEND (APPEND (rule_annotations, $1), $2); }
| "%merge" TAG		{ excluded_feature ("%merge"); }
| "%expand"	        { expand_rule = true; }
;

/*---------------------------.
| variable and content.opt.  |
`---------------------------*/

variable:
  any_id
| OTHER_ID
;

/* Some content or empty by default. */
content.opt:
  /* Nothing. */		  { $$ = No_Token; }
| any_id
| STRING
;


/*------------.
| braceless.  |
`------------*/

braceless:
  "{...}"
;


/*--------------.
| Identifiers.  |
`--------------*/

any_id:
  TERM_ID
| NONTERM_ID
| UNDERSCORE_ID
;

id:
  any_id
| CHAR
;

symbol:
  id
| string_as_id
;

cf_symbol:
  TERM_ID
| NONTERM_ID
| CHAR
    { $$ = $1; $1->add_implicit_token (); }
| string_as_id
    { $$ = $1; $1->add_implicit_token (); }
| UNDERSCORE_ID         
    { complain_at (yylloc, 
      		   "lexical subrule (%s) not allowed in context-free rule",
		   $1->as_string ().c_str ());
      YYERROR; 
    }
;

/* A string used as an ID: quote it.  */
string_as_id:
  STRING
;

epilogue.opt:
  /* Nothing.  */		   { $$ = TREE (EPILOGUE); }
| "%%" EPILOGUE			   { $$ = TREE (EPILOGUE, $2); }
;

/*----------------.
| Lexical rules.  |
`----------------*/

lexical_rule:
  TERM_ID ":" { lexical_lhs = $1; lexical_rhs = EMPTY; } lexical_rhs ";"
  	       { make_plain_lexical_rule (); }
| "*" ":"      { lexical_lhs = NULL; lexical_rhs = EMPTY; } lexical_rhs ";"
  	       { make_plain_lexical_rule (); }
| UNDERSCORE_ID ":" lexical_rhs_no_rules ";"
  		{ NodePtr subrule;
		  if ($3->arity () > 1)
		     subrule = TREE (LEX_SUBRULE, $1, TREE (LEX_GROUP, $3));
		  else
		     subrule = TREE (LEX_SUBRULE, $1, $3);
		  Node::lexical_subrules.push_back (subrule); }
| STRING ":" action ";"
  	        { $1->add_implicit_token ($3); }
| CHAR ":" action ";"
  	        { $1->add_implicit_token ($3); }
;

lexical_rhs:
  lexical_rhs_primaries
| lexical_rhs "|" lexical_rhs_primaries
;

lexical_rhs_no_rules:
  lexical_primaries		   { $$ = TREE (LEX_PHRASE, $1); }
| lexical_rhs_no_rules "|" lexical_primaries
				   { $$ = APPEND ($1, 
				                  TREE (LEX_PHRASE, $3)); }
;

lexical_rhs_primaries:
  lexical_prefix lexical_primaries lexical_suffix bare_action.opt
		{ if ($1->is_empty_list () && $3->is_empty_list () && 
		      $4 == NULL && !preferred_lexical_rule) {
		          add_lexical_option ($2);
	          } else {
		      make_plain_lexical_rule ();
                      make_lexical_rule (LIST ($1, $2, $3), $4); 
		  }
		}
| lexical_prefix preferred.opt "_EOF" preferred.opt bare_action.opt
		{ make_plain_lexical_rule ();
                  make_lexical_rule (LIST ($1, TREE (ENDFILE)), $5); 
		}
;

lexical_primaries:
  lexical_term
| lexical_primaries lexical_term { $$ = APPEND ($1, $2); }
;

lexical_term:
  lexical_primary
| lexical_term "-" lexical_primary
                           { $$ = TREE (LEX_SUB, $1, $3); 
                             $$->set_loc ($2->get_loc ()); }
;

lexical_primary:
  lexical_atom
| char_range
| lexical_atom "*"	   { $$ = TREE (LEX_STAR, $1); }
| lexical_atom "+"	   { $$ = TREE (LEX_PLUS, $1); }
| lexical_atom "?"	   { $$ = TREE (LEX_OPT, $1); }
;

lexical_atom:
  UNDERSCORE_ID			   { $$ = TREE (LEX_REF, $1); }
| "(" lexical_rhs_no_rules ")"	   { $$ = TREE (LEX_GROUP, $2); }
| CHAR                             { $$ = TREE (LEX_SET, $1, $1); }
| STRING                           { $$ = TREE (LEX_STRING, $1); }
| predefined_atoms
;

predefined_atoms:
  "_ANY"         { $$ = TREE (LEX_SET, O_RANGE(001, 376));  }
| "_UPPER"       { $$ = TREE (LEX_SET, RANGE('A', 'Z')); }
| "_LOWER"       { $$ = TREE (LEX_SET, RANGE('a', 'z')); }
| "_LETTER"      { $$ = TREE (LEX_SET, RANGE('A', 'Z'), RANGE('a', 'z')); }
| "_DIGIT"       { $$ = TREE (LEX_SET, RANGE('0', '9')); }
| "_HEX"         { $$ = TREE (LEX_SET, RANGE('0', '9'), 
                              RANGE('a', 'f'), RANGE('A', 'F')); }
| "_ALNUM"       { $$ = TREE (LEX_SET, RANGE(0, 9), 
                              RANGE('A', 'Z'), RANGE('a', 'z')); }
| "_SPACE"       { $$ = TREE (LEX_SET, RANGE(' ', ' '), RANGE('\t', '\t'),
                              RANGE('\n', '\n'), RANGE('\r', '\r'),
                              RANGE('\f', '\f'), RANGE('\v', '\v')); }
| "_BLANK"       { $$ = TREE (LEX_SET, RANGE(' ', ' '), RANGE('\t', '\t')); }
| "_CONTROL"     { $$ = TREE (LEX_SET, O_RANGE(001, 037), O_RANGE(177, 177)); }
| "_GRAPHIC"     { $$ = TREE (LEX_SET, RANGE('!', '~')); }
| "_PRINTABLE"   { $$ = TREE (LEX_SET, RANGE(' ', '~')); }
| "_PUNCTUATION" { $$ = TREE (LEX_SET, RANGE('!', '/'), RANGE(':', '@'), 
                              RANGE('[', '`'), RANGE('{', '~')); }
; 
  
char_range:
  CHAR ".." CHAR		   { $$ = TREE (LEX_SET, $1, $3); }
;

lexical_prefix:
  /* empty */			   { $$ = EMPTY; }
| "_BOL"			   { $$ = TREE (BOL); }
;

lexical_suffix:
  preferred.opt			      { $$ = EMPTY; }
| preferred.opt "_EOL" preferred.opt  { $$ = TREE (EOL); }
| preferred.opt "_EOF" preferred.opt  { $$ = TREE (ENDFILE); }
;

preferred.opt:
  /* empty */
| "%prefer"			      { preferred_lexical_rule = true; }
;

action:
  "{...}"                          { $$ = TREE (ACTION, stripped ($1)); 
  				     delete $1; }
;

bare_action.opt:
  "{...}"			   { $$ = stripped ($1); }
| /* empty */			   { $$ = NULL; }
;

%%

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
