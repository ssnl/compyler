# basic function type: tests returning a function within its own declaration
def foo(x::$A)::$A:
  return foo
