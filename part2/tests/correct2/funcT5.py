# basic function type: tests returning a function within its own declaration
def foo():
  return foo

print foo() is foo()()
