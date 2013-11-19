# adv call type chained: tests that types of chained function calls are resolved correctly
def foo(x):
    return bar

def bar(x,y):
    return foo

foo(5)("hi","bye")("baz")(6,7)
