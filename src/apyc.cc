/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* apyc: A PYthon Compiler. */

/* Authors: Kevin Wu, Wenson Hsieh, Leo Kam */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdarg>
#include "apyc.h"

using namespace std;

bool GCINIT::initialized = false;
static GCINIT _gcdummy;

const char* PRELUDE_NAME = "prelude.py";

int errCount;
int maxPhase;

void
error (const char* loc, const char* format, ...)
{
    va_list ap;
    va_start (ap, format);
    fprintf (stderr, "%s: ", yyprinted_location (loc).c_str ());
    vfprintf (stderr, format, ap);
    va_end (ap);
    fprintf (stderr, "\n");
    errCount += 1;
}

void
error_no_file (const char* format, ...)
{
    va_list ap;
    va_start (ap, format);
    vfprintf (stderr, format, ap);
    va_end (ap);
    fprintf (stderr, "\n");
    errCount += 1;
}

static void
Usage ()
{
    fprintf (stderr, "\
Usage: apyc --phase=(1 | 2) [ -dp ] [ -o OUTFILE ] DIR/BASE.py\n");
    exit (1);
}

static void
printTree (AST_Ptr tree, const gcstring& output)
{
    if (freopen (output.c_str (), "w", stdout) == NULL) {
	error_no_file ("Could not open %s", output.c_str ());
	return;
    }
    tree->print (cout, 0);
}

int
main (int argc, char* argv[])
{
    int i;
    char* outfile;
    maxPhase = -1;
    outfile = NULL;
    for (i = 1; i < argc; i += 1) {
	string opt = argv[i];
	if (opt == "-o" && i < argc-1) {
	    outfile = argv[i+1];
	    i += 1;
	} else if (opt.compare (0, 8, "--phase=") == 0)
	    maxPhase = atoi(opt.c_str () + 8);
	else if (opt == "-dp")
	    debugParser = true;
	else if (opt.size () == 0 || opt[0] == '-')
	    Usage();
	else
	    break;
    }
    if (i != argc-1 || maxPhase < 1 || maxPhase > 2)
	Usage ();
    errCount = 0;
    string infile = argv[i];

    if (infile.size () < 4
        || infile.compare (infile.size ()-3, 3, ".py") != 0) {
        error_no_file ("Unknown file type: %s\n", argv[i]);
        exit (1);
    }

    string outfileStr;
    if (outfile == NULL)
        outfileStr = string(infile, 0, infile.size ()-3)
            + (maxPhase == 1 ? ".ast" : ".dast");
    else
        outfileStr = outfile;

    parse_init ();
    add_source_file (infile);
    if (maxPhase > 1) {
        string prelude = argv[0];
        size_t lastSeg = prelude.find_last_of ("/\\");
        prelude.erase (lastSeg == string::npos ? 0 : lastSeg+1);
        prelude += PRELUDE_NAME;
        add_source_file (prelude);
    }

    AST_Ptr tree = parse ();

    if (maxPhase >= 2 && tree != NULL && errCount == 0)
        tree = tree->doOuterSemantics ();
    if (errCount == 0) {
        printTree (tree, outfileStr);
        printf("\n");
        outputDecls ();
    }

    exit (errCount == 0 ? 0 : 1);
}

/* Debugging routines.  These are never called in the skeleton.  They
 * are intended to be called from GDB, as in
 *     (gdb) call DB(aTree)
 */

void
DB(const AST_Ptr& x)
{
    AST::dump(x, cerr);
    cerr << endl;
}
void
DB(const Type_Ptr& x)
{
    AST::dump(x, cerr);
    cerr << endl;
}
void
DB(AST* x)
{
    AST::dump(x, cerr);
    cerr << endl;
}
void
DB(Type* x)
{
    AST::dump(x, cerr);
    cerr << endl;
}
