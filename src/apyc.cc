/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* apyc: A PYthon Compiler. */

/* Authors:  YOUR NAMES HERE */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdarg>
#include <unistd.h>
#include "apyc.h"

using namespace std;

bool GCINIT::initialized = false;

static int errCount;
int maxPhase;
static gcstring execPrefix;

static GCINIT _gcdummy;

const gcstring LIB_SUFFIX = "/lib/apyc";

const gcstring PRELUDE_NAME = LIB_SUFFIX + "/prelude.py";
const gcstring RUNTIME = LIB_SUFFIX + "/runtime.cc";
const gcstring GCC = "g++";
/** The extension to be used for generated code.  The value here is
 *  for C++.  Change it to .s (assembler) or .c as appropriate. */
const gcstring CODE_SUFFIX = ".cc";

/** Template for the name of a temporary code file when executable
 *  code is produced. */
const gcstring TEMPORARY_TEMPLATE = "/tmp/apycXXXXXX";

void verror(const char* loc, const char* format, va_list ap)
{
    fprintf (stderr, "%s: ", yyprinted_location (loc).c_str ());
    vfprintf (stderr, format, ap);
    fprintf (stderr, "\n");
    errCount += 1;
}

void
error (const char* loc, const char* format, ...)
{
    va_list ap;
    va_start (ap, format);
    verror (loc, format, ap);
    va_end (ap);
}

void
error (AST_Ptr node, const char* format, ...)
{
    if (!node->errorReported ()) {
        node->recordError ();
        va_list ap;
        va_start (ap, format);
        verror (node->loc (), format, ap);
        va_end (ap);
    }
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

int
numErrors ()
{
    return errCount;
}

static void
Usage ()
{
    fprintf (stderr, "\
Usage: apyc --phase=(1 | 2) [ -dp ] [ -o OUTFILE ] DIR/BASE.py\n");
    exit (1);
}

static void
openStdout (const gcstring& output)
{
    if (freopen (output.c_str (), "w", stdout) == NULL) {
	error_no_file ("Could not open %s", output.c_str ());
	exit (1);
    }
}


static void
closeStdout ()
{
    cout.flush ();
    fclose (stdout);
}

static void
makeExecutable (const gcstring& source, const gcstring& executable)
{
    gcstring command = GCC + " -g -I " + execPrefix + LIB_SUFFIX +
        " -o " + executable + " " + execPrefix + RUNTIME
        + " -x c++ " + source;
    int code = system (command.c_str ());
    if (code != 0)
        error_no_file ("compilation command failed");
}

int
main (int argc, char* argv[])
{
    int i;
    char* outfile;
    maxPhase = 4;
    outfile = NULL;
    for (i = 1; i < argc; i += 1) {
	gcstring opt = argv[i];
	if (opt == "-o" && i < argc-1) {
	    outfile = argv[i+1];
	    i += 1;
	} else if (opt.compare (0, 8, "--phase=") == 0)
	    maxPhase = atoi(opt.c_str () + 8);
	else if (opt == "-dp")
	    debugParser = true;
        else if (opt == "-S")
            maxPhase = 3;
	else if (opt.size () == 0 || opt[0] == '-')
	    Usage();
	else
	    break;
    }
    if (i != argc-1 || maxPhase < 1 || maxPhase > 4)
	Usage ();
    errCount = 0;
    gcstring infile = argv[i];

    if (infile.size () < 4
        || infile.compare (infile.size ()-3, 3, ".py") != 0) {
        error_no_file ("Unknown file type: %s\n", argv[i]);
        exit (1);
    }

    gcstring coutName;
    gcstring executableName;
    gcstring prefix = gcstring(infile, 0, infile.size ()-3);

    execPrefix = argv[0];
    size_t lastSeg = execPrefix.find_last_of ("/\\");
    execPrefix.erase (lastSeg == gcstring::npos ? 0 : lastSeg+1);

    if (maxPhase <= 3) {
        if (outfile == NULL) {
            switch (maxPhase) {
            case 1:
                coutName = prefix + ".ast";
                break;
            case 2:
                coutName = prefix + ".dast";
                break;
            case 3:
                coutName = prefix + CODE_SUFFIX;
                break;
            }
        } else
            coutName = outfile;
    } else {
        coutName = TEMPORARY_TEMPLATE;
        coutName += '\0';
        int fd = mkstemp (&coutName[0]);
        close (fd);
        if (outfile == NULL)
            executableName = "a.out";
        else
            executableName = outfile;
    }

    parse_init ();
    add_source_file (infile);
    if (maxPhase > 1) {
        add_source_file (execPrefix + PRELUDE_NAME);
    }

    AST_Ptr tree = parse ();

    if (numErrors () == 0) {
        if (maxPhase >= 2 && tree != NULL)
            tree = tree->doOuterSemantics ();
        if (maxPhase <= 2) {
            openStdout (coutName);
            tree->print (cout, 0);
            cout << endl;
            outputDecls (cout);
            closeStdout ();
        } else {
            openStdout (coutName);
            tree->outerCodeGen (cout);
            if (maxPhase == 4) {
                closeStdout ();
                makeExecutable (coutName, executableName);
                unlink (coutName.c_str ());
            }
        }
    }

    exit (numErrors () == 0 ? 0 : 1);
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

void
DB(Decl* d)
{
    d->print(cerr);
}
