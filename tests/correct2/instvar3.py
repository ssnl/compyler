# basic instance variable class: tests that instance variables and method calls are resolved
class A:
	def f(self):
		return self.y
	y::int = 10

a::A = A()
a.f()
