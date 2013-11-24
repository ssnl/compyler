# adv nested function type: tests if nested functions type properly
def foo(x):
  def bar():
    y = z
    print y
  z::str = x
  return bar

foo("hi")()

