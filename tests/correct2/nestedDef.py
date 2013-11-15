x = 10
y = "LOL"
def foo(a):
  x = a
  def bar(a, b):
    a, b = x, y
    print a, b
