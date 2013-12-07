
from sys import argv

def Usage():
	pass

"""
Cleans the prelude AST and Decls from the output of apyc, printing the cleaned
AST.
"""
def outputCleanedAST(fname):
	inp = open(fname)
	raw = inp.read().split("\n")
	mod_end = 1 + indexOf(raw,["(string_literal","\"__isnot__\"))))"])
	raw = raw[:1] + raw[mod_end:]
	decl_start = indexOf(raw,["(moduledecl 0 __main__"])
	decl_end = 9 + indexOf(raw,["(funcdecl","__isnot__ 0  (function_type 0"])
	ast_out = raw[:decl_start]
	decl_out = raw[decl_end:]
	print ast_out[0]
	print "          ..."
	print "     ----------- "
	print "     prelude AST "
	print "     ----------- "
	print "          ..."
	for line in ast_out[1:]:
		print line
	print "          ..."
	print "     ------------- "
	print "     prelude Decls "
	print "     ------------- "
	print "          ..."
	for line in decl_out:
		print line

def outputCleanedSource(fname):
	inp = open(fname)
	raw = inp.read().split("\n")
	start = 1+indexOf(raw,["return __isnot__("])
	raw = raw[start:]
	print "          ..."
	print "     -------------- "
	print "     prelude source "
	print "     -------------- "
	print "          ..."
	for line in raw[:-1]:
		print line
	if raw[-1]:
		print raw[-1],

def indexOf(lines,phrases):
	c = len(phrases)
	for k,line in enumerate(lines):
		if sum([(s in line) for s in phrases]) == c:
			return k
	return -1

if __name__ == "__main__":
	if len(argv) == 3:
		if argv[1] == "-a":
			outputCleanedAST(argv[2])
		elif argv[1] == "-p":
			outputCleanedSource(argv[2])
	else:
		Usage()
