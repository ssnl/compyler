# basic call type scope: tests that function in correct scope is called
def foo(x::int):
    def bar(y):
        pass
    return bar

def bar(x::int):
    return 2

print bar(10)
