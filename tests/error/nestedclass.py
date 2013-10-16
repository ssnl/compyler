class A:
	def __init__(self,x):
		self.y = 10 + x
	class B:
		print "this should cause an error"
		def foo(self):
			return "bar"
	def baz(self,x):
		return self.y - x

def somefunc(): 
	x = 10 + 2
	y = (1,2,3)
	class C:
		def __init__(self):
			print "This should also cause an error"
