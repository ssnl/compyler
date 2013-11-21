# basic function call overload: tests that calls to overloaded functions are resolved properly
def f(x):
    pass

def f(x,y):
    pass

f(1)
f(2,3)
