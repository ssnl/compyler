# basic call type chained: tests that types of chained function calls are resolved correctly
def foo(x):
    return foo

a =foo(5)("hi")(4)
