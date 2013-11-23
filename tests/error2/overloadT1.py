# basic function overload type: tests if function overloading errors when no overloading found
def f():
  pass
def f(x):
  pass
f(3, 2)
