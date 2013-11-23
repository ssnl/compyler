# basic ifexpr type: checks if an if expression throws an error with improper types
def foo():
  pass
foo if True else "hi"
