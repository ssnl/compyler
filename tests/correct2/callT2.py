# basic call type overload: tests that calls are typed correctly in overloaded functions
def foo(x::int,y::int):
    pass

def foo(x::str,y):
    pass

def foo(x::str,y::str):
    pass

foo("hi",2)

