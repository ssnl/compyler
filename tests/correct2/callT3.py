# basic call type chained: tests that types of chained function calls are resolved correctly
def foo(x):
    return foo

foo(5)("hi")(4)
