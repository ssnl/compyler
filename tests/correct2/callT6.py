# adv call type chained: tests that types of chained function calls are resolved correctly
def foo(x):
	print x
    return foo

def bar(x,y):
	print x,y
    return foo

bar("hi", "bye")("hi")(3)
