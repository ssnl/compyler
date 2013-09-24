/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* apyc: A PYthon Compiler. */

/* Authors:  YOUR NAMES HERE */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdarg>
#include "apyc.h"

using namespace std;

int err_count;
static string file_name;

void
error (const char* loc, const char* format, ...)
{
    va_list ap;
    va_start (ap, format);
    fprintf (stderr, "%s: ", yyprinted_location (loc).c_str ());
    vfprintf (stderr, format, ap);
    va_end (ap);
    fprintf (stderr, "\n");
    err_count += 1;
}

void
error_no_file (const char* format, ...) 
{
    va_list ap;
    va_start (ap, format);
    vfprintf (stderr, format, ap);
    va_end (ap);
    fprintf (stderr, "\n");
    err_count += 1;
}

static void
Usage ()
{
    fprintf (stderr, "\
Usage: apyc --phase=1 [ -dp ] DIR/BASE.py ...\n\
       apyc --phase=1 [ -dp ] -o OUTFILE DIR/BASE.py\n");
    exit (1);
}

static void
compile (const string& input, const string& output)
{
    if (freopen (output.c_str (), "w", stdout) == NULL) {
        error_no_file ("Could not open %s", output.c_str ());
        return; 
    }
    file_name = input;
    FILE* inFile = fopen (input.c_str (), "r");
    if (inFile == NULL) {
        error_no_file ("Could not open %s", input.c_str ());
        return; 
    }
    parse (inFile, input);
    fclose (inFile);
    fclose (stdout);
}

int
main (int argc, char* argv[])
{
    int i;
    int phase;
    char* outfile;
    phase = -1;
    outfile = NULL;
    for (i = 1; i < argc; i += 1) {
        string opt = argv[i];
        if (opt == "-o" && i < argc-1) {
            outfile = argv[i+1];
            i += 1;
        } else if (opt.compare (0, 8, "--phase=") == 0)
            phase = atoi(opt.c_str () + 8);
        else if (opt == "-dp") 
            debugParser = true;
        else if (opt.size () == 0 || opt[0] == '-')
            Usage();
        else
            break;
    }
    if (i >= argc || phase != 1)
        Usage ();
    err_count = 0;
    if (outfile == NULL) {
        while (i < argc) {
            string infile = argv[i];
            if (infile.size () < 4 
                || infile.compare (infile.size ()-3, 3, ".py") != 0) {
                error_no_file ("Unknown file type: %s\n", argv[i]);
                exit (1);
            }
            compile (infile, string(infile, 0, infile.size ()-3) + ".ast");
            i += 1;
        }
    } else if (i + 1 < argc)
        Usage ();
    else {
        string infile = argv[i];
        if (infile.size () <= 4 
            || infile.compare (infile.size ()-3, 3, ".py") != 0) {
            error_no_file ("Unknown file type: %s\n", argv[i]);
            exit (1);
        }
        compile (infile, outfile);
    }
    exit (err_count == 0 ? 0 : 1);
}
