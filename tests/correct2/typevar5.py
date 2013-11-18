# basic nested typevar: tests if a typevar inside a nested function resolves properly
def foo(x::$A):
  def bar():
    y::$A = 3
