# basic function overload type: tests if function overloading errors when no overloading found
def f():
  pass
def f(x::int):
  pass
f("str")
