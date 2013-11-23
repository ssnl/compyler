# basic typevar: tests if typevars resolve properly
def foo(x::$A):
  y::$A = 3

print foo(2)
