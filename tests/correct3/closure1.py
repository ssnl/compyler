# closure: test basic function closure
def foo(x):
  def bar(y::int):
    return x + y
  return bar

a = foo(10)
print a(3)
print a(5)
