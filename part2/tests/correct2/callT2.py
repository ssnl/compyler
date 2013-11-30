# basic call type overload: tests that calls are typed correctly in overloaded functions
def foo(x::int,y::int):
    return 1

def foo(x::str,y):
    return 2

def foo(x::str,y::str):
    return 3

print foo("hi",2)
