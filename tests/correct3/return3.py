# return def call: tests return on function call
y,z = 10,15
def foo(x::int):
    return x + y

def bar(x::int):
    return x + z

print foo(1), bar(2)
