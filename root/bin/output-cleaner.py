
from sys import argv

'''
Cleans the prelude AST and Decls from the output of apyc, printing
the cleaned AST.
'''
def outputCleanedAST(fname):
	inp = open(fname)
	raw = inp.read().split("\n")
	raw = raw[:1] + raw[1282:]
	decl_start = indexOf(raw,"(moduledecl 0 __main__")
	ast_out = raw[:decl_start]
	decl_out = raw[decl_start+474:]
	print ast_out[0]
	print "          ."
	print "          ."
	print "          ."
	print "    <<prelude AST>>"
	print "          ."
	print "          ."
	print "          ."
	for line in ast_out[1:]:
		print line
	print "          ."
	print "          ."
	print "          ."
	print "   <<prelude Decls>>"
	print "          ."
	print "          ."
	print "          ."
	for line in decl_out:
		print line

def outputCleanedSource(fname):
	inp = open(fname)
	raw = inp.read().split("\n")
	raw = raw[157:]
	print "          ."
	print "          ."
	print "          ."
	print "  <<prelude source>>"
	print "          ."
	print "          ."
	print "          ."
	for line in raw:
		print line

def indexOf(lines,s):
	for k,line in enumerate(lines):
		if s in line:
			return k
	return -1

if __name__ == "__main__":
	if len(argv) == 3:
		if argv[1] == "-a":
			outputCleanedAST(argv[2])
		elif argv[1] == "-p":
			outputCleanedSource(argv[2])
