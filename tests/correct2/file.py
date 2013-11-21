# basic file print: tests printing to files
f::file = sys.stdout
g = sys.stdout
print >> f, "Hi",
print >> g, "bye."
print sys.stdout, "why?"
