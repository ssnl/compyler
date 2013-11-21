# basic function type: tests if function return types resolve properly
def foo(x::str):
  return "hi"

def bar(x::str)::str:
  return "hi"
