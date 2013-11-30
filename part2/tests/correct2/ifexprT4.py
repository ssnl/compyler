# basic ifexpr type: tests if if-expressions resolve types properly
def foo(a, b):
  pass
def bar(x, y):
  pass
foo if True else bar
