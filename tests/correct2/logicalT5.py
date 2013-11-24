# basic logical type: tests if logical expressions resolve types properly
def foo(x):
  return True
def bar(y):
  return False
print foo(5) and bar(6)
print bar(10) or foo(1)
