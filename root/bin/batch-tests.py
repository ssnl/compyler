import os, argparse
from sys import argv
from collections import Counter

def batchTests(args):
  tdir = args.dir + "/"
  if args.keys:
    tests = os.listdir(tdir)
    keys = Counter()
    for test in tests:
      fpath = tdir + test
      if test[-3:] == ".py":
        desc = getDescr(fpath)
        colidx = desc.find(":")
        if desc[0] == "#" and colidx != -1:
          keywords = desc[:colidx].split(" ")[1:]
          for kw in keywords:
            keys[kw] += 1
    for k in sorted(keys):
      print "%-10s(%d)" %(k, keys[k])
  else:
    key = args.key
    tnames, descriptions = findTests(tdir, key)
    errors = 0
    failures = []
    success = []
    for tn, desc in zip(tnames, descriptions):
      print "\n",
      print "================== TESTING: " + tn + " =================="
      print "Description:" + desc[desc.find(":") + 1:]
      r = os.system("runtest -v -d %s %s" %(tdir, tn))
      if r != 0:
        errors += 1
        failures.append(tn)
      else:
        success.append(tn)
      if not args.force:
        raw_input("Press enter to continue...")
    print "------------------------------------"
    print "Number of Tests Run: " + str(len(tnames))
    print "Total Errors       : " + str(errors)
    print "Successful tests   :",
    for k, tn in enumerate(success):
      if k == len(success) - 1: print tn,
      else: print tn + ", ",
    print "\n",
    print "Failed tests       :",
    for k, tn in enumerate(failures):
      if k == len(failures) - 1: print tn,
      else: print tn + ", ",
    print "\n",


def findTests(tdir,key):
  tests = os.listdir(tdir)
  tnames, descriptions = [],[]
  for test in tests:
    fpath = tdir + test
    if ".py" == test[-3:]:
      desc = checkDescr(fpath, key)
      if desc:
        tnames.append(test[:-3])
        descriptions.append(desc)
  return tnames, descriptions

def getDescr(fpath):
  f = open(fpath)
  desc = f.readline().lower()
  f.close()
  return desc

def checkDescr(fpath, key):
  if type(key) is str:
    key = [key,]
  desc = getDescr(fpath)
  colidx = desc.find(":")
  if colidx == -1 or desc[0] != "#":
    return None
  else:
    wset = set(desc[:colidx].split(" ")[1:])
    for k in key:
      if k not in wset:
        return None
    return desc

if __name__ == '__main__':
  base = os.getcwd()
  desc = "Run multiple tests at once using a key."
  parser = argparse.ArgumentParser(description=desc)
  parser.add_argument("-d", "--dir",
    help="The directory to search for tests.",
    default=base+"/tests/correct3")
  parser.add_argument("key",
    help="The key to search for.",
    nargs="*")
  parser.add_argument("-k","--keys",
    help="List and count all keywords, ignores other arguments.",
    action="store_true")
  parser.add_argument("-f", "--force",
    help="Run tests associated with the key without pausing.",
    action="store_true")
  args = parser.parse_args()
  batchTests(args)
