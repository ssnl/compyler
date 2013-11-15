x = 15
s = 'Kevin is fat'
def foo(x, y, z):
  print x
  x = 5
  y, z = x, s
  return x, y, z
  print x, y, z
def bar(z):
  z = x
  def baz(a):
    z = a
    print z
    print s
    print y
    x = 10
    print x
  y = 15
