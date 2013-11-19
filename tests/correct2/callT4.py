# basic nested call type: tests that calls to nested function resolve properly
def foo(x):
    def bar(y):
        return 3
    return bar

a = foo(1)
b = a(2)
