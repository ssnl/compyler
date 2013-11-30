# basic overload function type: check if overloaded functions throw error if unresolved
def f(x::int, y::str):
  pass
def f(x::str, y::int):
  pass
f(3, 2)
