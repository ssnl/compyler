# return def call: tests return on function call
z = 4
def foo(x::int):
    def bar(y::int):
        return y
    return x + bar(5)
print foo(5)
print foo(z)
