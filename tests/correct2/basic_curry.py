
def foo(f,x):
	def bar(y):
		return f(x,y)
	return bar

def baz(a,b):
	return a+b

func = foo(baz,10)
print func(5)
