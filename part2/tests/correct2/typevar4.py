# basic nested typevar: tests if typevars in nested functions resolve properly
def foo(x::$A):
  def bar(y::$A):
    pass
