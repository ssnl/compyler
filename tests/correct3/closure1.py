# closure: test basic function closure
def foo(x):
  def bar():
    x = x + 1
    return x
  return bar

a = foo(10)
print a()
print a()
