import os, argparse
from sys import argv

def collectTests(args):
  tdir = args.dir
  if args.keys:
    tests = os.listdir(tdir)
    keys = dict()
    for test in tests:
      if test[-3:] == ".py":
        fpath = tdir + test
        desc = getDescr(fpath)
        colidx = desc.find(":")
        if colidx != -1:
          keywords = desc[:colidx].split(" ")[1:]
          for kw in keywords:
            if kw in keys:
              keys[kw] += 1
            else:
              keys[kw] = 1
    for k in sorted(keys):
      print k + " (" + str(keys[k]) + ")"
  else:
    key = args.key
    tnames,descriptions = findTests(tdir,key)
    for tn,desc in zip(tnames,descriptions):
      print "\n"
      print "================== TESTING: " + tn + " =================="
      print desc
      os.system("runtest -v " + tn)

def findTests(tdir,key):
  tests = os.listdir(tdir)
  tnames,descriptions = [],[]
  for test in tests:
    fpath = tdir + test
    if ".py" == test[-3:]:
      desc = checkDescr(fpath, key)
      if desc:
        tnames.append(test[:-3])
        descriptions.append(desc)
  return tnames,descriptions

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
  if colidx == -1:
    return None
  else:
    wset = set(desc[:colidx].split(" ")[1:])
    for k in key:
      if k not in wset:
        return None
    return desc

if __name__ == '__main__':
  HOME = os.environ["HOME"]
  desc = "Run multiple tests at once using a key."
  parser = argparse.ArgumentParser(description=desc)
  parser.add_argument("-d", "--dir",
    help="The directory to search for tests.",
    default=HOME+"tests/correct2/")
  parser.add_argument("key",
    help="The key to search for",
    nargs="*")
  parser.add_argument("-k","--keys",
    help="List and count all keywords.",
    action="store_true")
  args = parser.parse_args()
  collectTests(args)
