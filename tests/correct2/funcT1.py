# basic type function: tests type inference on function with typed parameters
def foo(x::int, y::str):
  return 1

print foo(1,"hi")

