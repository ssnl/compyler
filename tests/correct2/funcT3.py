# basic nested function type: tests if nested functions type properly
def foo(x):
  def bar():
    y::int = x
    print y
  return bar

print foo(5)()

