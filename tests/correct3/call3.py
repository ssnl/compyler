# basic def call: basic def call with nested functions
def foo (x::int):
  def bar (y::str):
    print y
  print x
  bar("hi")
foo(5)
