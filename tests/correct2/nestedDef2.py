x = 10
def foo():
  def bar():
    print x
    x = y
  y = 3
