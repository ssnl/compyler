# basic nested call type: tests that calls to nested function resolve properly
def foo(x):
    def bar(y):
        return x, y
    return bar

a = foo(1)(3)
b = foo(2)(2)
print a, b
