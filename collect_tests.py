
import os
from sys import argv
TDIR = "tests/correct2/"
tests = os.listdir(TDIR)

key = argv[1] if len(argv) > 1 else ""

def checkDescr(fpath,word):
	f = open(fpath)
	desc = f.readline()
	if word in desc.lower():
		return desc
	else:
		return None

if __name__ == '__main__':
	tnames,descriptions = [],[]
	for test in tests:
		fpath = TDIR + test
		if ".py" == test[-3:]:
			desc = checkDescr(fpath,key)
			if desc:
				tnames.append(test[:-3])
				descriptions.append(desc)
	for tn,desc in zip(tnames,descriptions):
		print "\n\n\n================== TESTING: " + tn + "=================="
		print desc + "\n"
		instr = "cat -n " + tn # placeholder for ./test [...]
		r = os.system(instr)
