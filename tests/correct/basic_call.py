class A:
	def foo(self):
		return "test"

class B:
	def __init__(self):
		self.x = 10
		self.y = 5
		self.a = A()

b = B()
print b.x
print b.y
print b.a.foo()

def increment(x):
	print x + 1
	return x + 1

print increment(5)

class C of [$TYPE]:
	def __init__(self,a,b):
		print "hi"
		print a + b

C of [int](5,7)
