#include <iostream>
#include <cstdio>
#include <cstdlib>


YYNAMESPACE_CLOSE

using namespace std;

int
main (int argc, char* argv[])
{
    if (argc > 1) {
	FILE* inp = fopen (argv[1], "r");
	if (inp == NULL) {
	    fprintf (stderr, "could not open %s\n", argv[1]);
	    exit (1);
	}
	YYNAMESPACE::yypush_lexer (inp, argv[1]);
    } else
	YYNAMESPACE::yypush_lexer (stdin, "<stdin>");
    return YYNAMESPACE::yyparse ();
}
YYNAMESPACE_OPEN
