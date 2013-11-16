import os, argparse
from sys import argv

def collectTests(args):
  tdir = args.dir
  key = args.key
  tests = os.listdir(tdir)
  tnames,descriptions = [],[]

  for test in tests:
    fpath = tdir + test
    if ".py" == test[-3:]:
      desc = checkDescr(fpath, key)
      if desc:
        tnames.append(test[:-3])
        descriptions.append(desc)
  for tn,desc in zip(tnames,descriptions):
    print "\n"
    print "================== TESTING: " + tn + "=================="
    print desc
    os.system("runtest -v " + tn)

def checkDescr(fpath, word):
  f = open(fpath)
  desc = f.readline()
  if word in desc.lower():
    return desc
  else:
    return None

if __name__ == '__main__':
  HOME = os.environ["HOME"]
  desc = "Run multiple tests at once using a key."
  parser = argparse.ArgumentParser(description=desc)
  parser.add_argument("-d", "--dir",
    help="The directory to search for tests.",
    default=HOME+"/tests/correct2/")
  parser.add_argument("key",
    help="The key to search for")
  args = parser.parse_args()

  collectTests(args)
