# basic def call: multiple nested functions
def foo(x::int):
  def bar(y::int):
    def baz(z::int):
      print z
    print y
    baz(5)
  print x
  bar(4)
foo(3)
