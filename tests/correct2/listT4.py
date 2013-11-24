# basic list type: check if lists resolve properly with functions
def foo(x, y):
  pass
def bar(x, y):
  pass

t = [foo, bar]
print t[0](0,1)
