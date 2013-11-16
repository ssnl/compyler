# Basic scope instance variable method: test class scoping
x = 1
class Foo:
	x = 5
	def f(self):
		print x
