# closure:
def foo(x, y, z):
  def bar():
    return x+1
  def baz():
    return y+1
  def boo():
    return z+1
  return [bar, baz, boo]
x = foo(0,1,2)
print x[0](), x[1](), x[2]()

