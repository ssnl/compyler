# adv call type chained: tests that types of chained function calls are resolved correctly
def foo(x):
    return foo

def bar(x,y):
    return foo

a = bar("hi", "bye")("hi")(3)
