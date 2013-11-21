# basic function call overload: tests that calls to overloaded functions are resolved properly
def f(x):
	return x-1

def f(x):
	return "HAI " + x

f(3)
f("BAI")
