# Make and call a nested function definition
def foo(x::int):
  y = x + 1
  def bar(z::str):
    print z
    return y
  return bar

foo(5)
