# basic allocator init: test allocator of class with __init__ of more than one parameter
class A:
	def __init__(self, x, y):
		pass
	def foo(self, x, y):
		pass

x = A(3, "hi")
y = A("hi", 1)
