#include <algorithm>
#include "horn.h"

using namespace std;

const lstring NULL_LS;

#define member text_buffer::

inline void member
check_include (const char *str, size_t len) const
{
#ifndef NDEBUG
    if (str != NULL
	&& ! (str >= &_data[0] && str + len <= &_data[0] + _data.size ())) 
	throw range_error ("reference outside of text buffer");
#endif    
}

inline void member
check_include (lstring s) const
{
    check_include (s.start, s.len);
}


inline void member
check_include1 (const char *str, size_t len) const
{
#ifndef NDEBUG
    if (str == NULL
	|| ! (str >= &_data[0] && str + len <= &_data[0] + _data.size ())) 
	throw range_error ("reference outside of text buffer");
#endif    
}

inline void member
check_include1 (lstring s) const
{
    check_include1 (s.start, s.len);
}


/** An empty text file. */
member
text_buffer () : _size (0) 
{ }

/** Release all dynamic data, invalidating contents. */
member
~text_buffer ()
{
}

/** The total length of text in THIS, accounting for annotations. */
size_t  member
size () const
{
    return _size;
}

/** The length of text in data () (not accounting for annotations). */
size_t member
data_size () const
{
    return _data.size ();
}

/** The data in THIS. */
char* member
data ()
{
    static char empty_chars[] = "";
    if (_data.size () == 0)
	return empty_chars;
    else
	return &_data[0];
}

/** True iff there have been modifications posted against data
 *  since the last clear () or append (). */
int member
num_modifications () const
{
    return _annotations.size ();
}

lstring member
substr (const char* start, size_t len)
{
    check_include (start, len);
    return lstring (start, len);
}

lstring member
join (lstring s0, lstring s1)
{
    check_include (s0);
    check_include (s1);

    if (s0.is_null ())
	return s1;
    if (s1.is_null ())
	return s0;

    const char* start = (s0.start < s1.start) ? s0.start : s1.start;
    const char* end = (s0.start + s0.len > s1.start + s1.len) 
	? s0.start + s0.len : s1.start + s1.len;
    return lstring (start, end-start);
}

lstring member
left_join (lstring s0, lstring s1)
{
    check_include (s0);
    check_include (s1);

    if (s0.is_null ())
	return s1;
    if (s1.is_null ())
	return s0;

    if (s0.start > s1.start) {
	lstring t = s0;	s0 = s1; s1 = t;
    }

    if (s0.start + s0.len >= s1.start)
	return join (s0, s1);
    else
	return s0;
}

void member
clear ()
{
    _data.clear ();
    _annotations.clear ();
    _size = 0;
}

/** Append STR[0 .. LEN-1] to end of THIS.  Invalidates prior
 *  value of data (). */
void member
append (const char *str, size_t len)
{
    _data.append (str, len);
    _size += len;
}

/** Append STR to end of THIS.  Invalidates prior value of data (). */
void member
append (const std::string& str)
{
    _data.append (str);
    _size += str.size ();
}

/** Annotate to insert TEXT[0 .. LEN-1] before POSN, which must be within
 *  data ().  Does not change contents of data ().  [4 variants] */
void member
insert (const char* posn, const char* text, size_t len)
{
    check_include1 (posn, 0);
    if (len == 0)
	return;
    _annotations.push_back (make_pair (lstring (posn, 0), string(text, len)));
    _size += len;
}

void  member
insert (lstring& posn, const char* text, size_t len)
{
    check_include1 (posn.start, 0);
    if (len == 0)
	return;
    _annotations.push_back (make_pair (lstring (posn.start, 0), 
				       string(text, len)));
    _size += len;
}

void  member
insert (const char* posn, const std::string& text)
{
    check_include1 (posn, 0);
    if (text.size () == 0)
	return;
    _annotations.push_back (make_pair (lstring (posn, 0), text));
    _size += text.size ();
}

void member
insert (lstring& posn, const std::string& text)
{
    check_include1 (posn.start, 0);
    if (text.size () == 0)
	return;
    _annotations.push_back (make_pair (lstring (posn.start, 0), text));
    _size += text.size ();
}
    
void  member
insert_after (lstring& posn, const char* text, size_t len)
{
    check_include1 (posn);
    if (len == 0)
	return;
    insert ((char*) posn.start + posn.len, text, len);
}

void member
insert_after (lstring& posn, const std::string& text)
{
    check_include1 (posn);
    if (text.size () == 0)
	return;
    insert ((char*) posn.start + posn.len, text);
}

/** Annotate to remove TEXT[0 .. LEN-1], which must be within data ().
 *  Does not change contents of data (). [2 variants] */
void  member
erase (const char* text, size_t len)
{
    check_include1 (text, len);
    if (len == 0)
	return;
    _annotations.push_back (make_pair (lstring (text, len), string()));
    _size -= len;
}

void  member
erase (lstring& text)
{
    check_include1 (text.start, text.len);
    if (text.len == 0)
	return;
    _annotations.push_back (make_pair (text, string()));
    _size -= text.len;
}

/** Annotate to replace TEXT[0 .. LEN-1], which must be within
 *  data (), with REPL[0 .. RLEN-1].  TEXT is not modified.
 *  [4 variants].  */
void  member
replace (char* text, size_t len, const char* repl, size_t rlen)
{
    replace (lstring (text, len), string (repl, rlen));
}

void  member
replace (char* text, size_t len, const std::string& repl)
{
    replace (lstring (text, len), repl);
}

void  member
replace (const lstring& text, const char* repl, size_t rlen)
{
    replace (text, string (repl, rlen));
}

void  member
replace (const lstring& text, const std::string& repl)
{
    check_include1 (text.start, text.len);
    _annotations.push_back (make_pair (text, repl));
    _size += repl.size () - text.len;
}


/** Write current contents, as modified by annotations, to OUT.
 *  Returns true iff successful.  */
void member
fwrite (FILE* out)
{
    char* buffer = new char[size ()];
    write (buffer, size ());
    ::fwrite (buffer, size (), 1, out);
    delete [] buffer;
}

/** Return current contents, as modified by annotations, as a
 *  string. */
string member
as_string ()
{
    string result;
    write (result);
    return result;
}

string* member
as_string_ptr ()
{
    string* result = new string;
    write (*result);
    return result;
}

/** Return current contents, as modified by annotations, in OUT. */
void  member
write (std::string& out)
{
    size_t size0 = out.size ();
    out.reserve (size0 + size () + 1);
    out.resize (size0 + size ());
    write (&out[size0], size ());
}

class annotation_compare {
public:
    bool operator() (text_buffer::annotation x, 
		   text_buffer::annotation y) const {
	return x.first.start < y.first.start || 
	    (x.first.start == y.first.start && x.first.len < y.first.len);
    }
};

void member
check_annotations () const
{
#ifndef NDEBUG
    const char* s;
    s = _data.data ();
    for_each (i, annotation, _annotations) {
	if (s > i.first.start)
	    throw domain_error ("annotations overlap illegally");
	s = i.first.start + i.first.len;
    } end_for;
#endif
}

/** Return up to SIZE characters of contents, as modified by annotations,
 *  in OUT.  Returns the number of characters transferred, which
 *  is always min(SIZE, size()). */
size_t  member
write (char* out, size_t size)
{
    stringstream str;
    write (str);
    string s = str.str ();
    size_t len = size > s.size () ? s.size () : size;
    memcpy (out, s.data (), len);
    return len;
}

void member
write (ostream& out)
{
    stable_sort (_annotations.begin (), _annotations.end (),
		 annotation_compare ());
    check_annotations ();

    char* s = data ();
    size_t len = data_size ();
    for_each (i, annotation, _annotations) {
	size_t n;

	if (s < i.first.start) {
	    n = i.first.start - s;
	    out.write (s, n);
	    s += n; len -= n; 
	}
	
	n = i.second.size ();
	out.write (i.second.data (), n);
	s += i.first.len; len -= i.first.len;
    } end_for;
    if (len > 0)
	out.write (s, len);
}
