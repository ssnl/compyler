/* Declaration for error-reporting function for Bison.

   Copyright (C) 2000, 2001, 2002, 2004, 2005, 2006, 2009, 2010 Free
   Software Foundation, Inc.

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

/* Based on error.c and error.h,
   written by David MacKenzie <djm@gnu.ai.mit.edu>.  */

#include <ctime>
#include <fstream>
#include "horn.h"

using namespace std;

bool complaint_issued;
static unsigned *indent_ptr = 0;
int warnings_flag;
location current_complaint_location;



/** Report an error message.
 *
 * \param loc     the location, defaulting to the current file,
 *                or the program name.
 * \param prefix  put before the message (e.g., "warning").
 * \param message the error message, a printf format string.  Iff it
 *                ends with ": ", then no trailing newline is printed,
 *                and the caller should print the remaining
 *                newline-terminated message to stderr.
 * \param args    the arguments of the format string.
 */
static
void
error_message (location *loc,
	       const char *prefix,
	       const char *message, va_list args)
{
  unsigned pos = 0;

  if (loc)
    pos += location_print (stderr, *loc);
  else
    pos += fprintf(stderr, "%s", 
		   current_file.empty ()
		   ? program_name.c_str ()
		   : current_file.c_str ());
  pos += fprintf(stderr, ": ");

  if (indent_ptr)
    {
      if (!*indent_ptr)
        *indent_ptr = pos;
      else if (*indent_ptr > pos)
        fprintf (stderr, "%*s", *indent_ptr - pos, "");
      indent_ptr = 0;
    }

  if (prefix)
    fprintf (stderr, "%s: ", prefix);

  vfprintf (stderr, message, args);
  {
    size_t l = strlen (message);
    if (l < 2 || message[l-2] != ':' || message[l-1] != ' ') {
      putc ('\n', stderr);
      fflush (stderr);
    }
  }
}

/** Wrap error_message() with varargs handling. */
#define ERROR_MESSAGE(Loc, Prefix, Message)	\
{						\
  va_list args;					\
  va_start (args, Message);			\
  error_message (Loc, Prefix, Message, args);	\
  va_end (args);				\
}


/*--------------------------------.
| Report a warning, and proceed.  |
`--------------------------------*/

static void
set_warning_issued (void)
{
  static bool warning_issued = false;
  if (!warning_issued && (warnings_flag & warnings_error))
    {
      fprintf (stderr, "%s: warnings being treated as errors\n",
	       program_name.c_str ());
      complaint_issued = true;
    }
  warning_issued = true;
}

void
warn_at (location loc, const char *message, ...)
{
  set_warning_issued ();
  ERROR_MESSAGE (&loc, _("warning"), message);
}

void
warn_at_indent (location loc, unsigned *indent,
                const char *message, ...)
{
  set_warning_issued ();
  indent_ptr = indent;
  ERROR_MESSAGE (&loc, _("warning"), message);
}

void
warn (const char *message, ...)
{
  set_warning_issued ();
  ERROR_MESSAGE (&current_complaint_location, _("warning"), message);
}


/*-----------------------------------------------------------.
| An error has occurred, but we can proceed, and die later.  |
`-----------------------------------------------------------*/

void
complain_at (location loc, const char *message, ...)
{
  ERROR_MESSAGE (&loc, NULL, message);
  complaint_issued = true;
}

void
complain_at_indent (location loc, unsigned *indent,
                    const char *message, ...)
{
  indent_ptr = indent;
  ERROR_MESSAGE (&loc, NULL, message);
  complaint_issued = true;
}

void
complain (const char *message, ...)
{
  ERROR_MESSAGE (&current_complaint_location, NULL, message);
  complaint_issued = true;
}


void
error (int status, int, const char* msg_format, ...)
{
    va_list args;
    va_start (args, msg_format);
    vfprintf (stderr, msg_format, args);
    va_end (args);
    if (status != 0)
	exit (status);
}

/*-------------------------------------------------.
| A severe error has occurred, we cannot proceed.  |
`-------------------------------------------------*/

void
fatal_at (location loc, const char *message, ...)
{
  ERROR_MESSAGE (&loc, _("fatal error"), message);
  exit (1);
}

void
fatal (const char *message, ...)
{
  ERROR_MESSAGE (NULL, _("fatal error"), message);
  exit (1);
}

				/* Strings */

string 
format_string (const char* message, ...)
{
    va_list args;
    char buffer[1024];
    va_start (args, message);
    int n = vsnprintf (buffer, sizeof (buffer), message, args);
    va_end (args);
    if (n+1 >= (int) sizeof (buffer))
	warn ("message too long; truncated");
    return string (buffer, n);
}
	       

/*-------------------------------------.
| Return an "interned" version of STR. |
`-------------------------------------*/

typedef const char* cstring;

struct cstring_less {
    bool operator() (const cstring& x, const cstring& y) const
	{ return strcmp (x, y) < 0; }
};

map<cstring, cstring, cstring_less> interned_strings;

const char *
uniqstr_new (const char *str)
{
    cstring& val = interned_strings[str];
    if (val == NULL)
	val = strdup (str);
    return val;
}

/*-----------------------------------------------------.
|  A timestamp indicating a file generated from NAME   |
`-----------------------------------------------------*/

string
gen_timestamp (const string& name)
{
    time_t now_time = time (NULL);
    string now;
    now = asctime (gmtime (&now_time));
    now.erase (now.size () - 1);

    return string ("/* Generated from ") + name + " at " + now + " GMT. */";
}

				/* Files */

size_t
newline_count (const char* L, size_t length)
{
    int n;
    n = 0;
    for (size_t i = 0; i < length; i += 1)
	if (L[i] == '\n')
	    n += 1;
    return n;
}

void
copy_subst_file (ostream& out, const char* infile_name, 
		 map<string, string>& dict,
		 const char* outfile_name)
{
    stringstream file_content;
    size_t newlines;

    copy_file (file_content, infile_name);
    string buffer;
    buffer = file_content.str ();
    newlines = 1;

    for (size_t p = 0, next; p < buffer.size (); p = next) {
	next = buffer.find ("@@@", p);
	if (next == string::npos) {
	    out.write (&buffer[p], buffer.size () - p);
	    break;
	} else {
	    newlines += newline_count (&buffer[p], next - p);
	    out.write (&buffer[p], next-p);
	}

	size_t delim = buffer.find ("@@@", next+3);

	if (buffer.compare (next+3, 8, "include:") == 0)
	    copy_file (out, 
		       (data_dir +
			buffer.substr (next+11, delim-next-11)).c_str (),
		       &newlines);
	else if (buffer.compare (next+3, 8, "*RESYNC*") == 0
		 && outfile_name != NULL)
	    out << "#line " << (newlines+1) << " \"" << outfile_name << "\"";
	else {
	    string repl(dict[buffer.substr (next+3, delim - next - 3)]);
	    newlines += newline_count (repl.data (), repl.size ());
	    out.write (repl.data (), repl.size ());
	}
	next = delim+3;
    }
}

void
copy_file (ostream& out, const char* infile_name, size_t* newline_countp)
{
    char* buffer;

    ifstream inp (infile_name, ifstream::in);
    if (inp.fail ())
	fatal ("could not read %s", infile_name);
    
    inp.seekg (0, ios::end);
    size_t length = inp.tellg ();
    inp.seekg (0, ios::beg);

    buffer = new char [length];

    inp.read (buffer, length);
    inp.close();

    out.write (buffer, length);

    if (newline_countp != NULL)
	*newline_countp += newline_count (buffer, length);

    delete[] buffer;
}

void
copy_file_if_needed (const string& newfile_name, const string& infile_name)
{
    string old_text;
    ifstream old (newfile_name.c_str ());
    if (!old.fail ()) {
        stringstream old_stream;
        old.close ();
        copy_file (old_stream, newfile_name.c_str (), NULL);
        old_text = old_stream.str ();
    }
	    
    stringstream new_stream;
    copy_file (new_stream, infile_name.c_str (), NULL);
    string new_text = new_stream.str ();
    if (new_text != old_text) {
        ofstream out (newfile_name.c_str ());
        if (out.fail ()) 
            fatal ("could not open %s for output", newfile_name.c_str ());
        out << new_text;
	out.close ();
    }
}
