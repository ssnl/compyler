# basic function type: tests returning a function within its own declaration
def foo(x):
  return foo
print foo(1)(2) is foo("hi")(5)
