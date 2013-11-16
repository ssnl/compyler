# basic class scope: instance variable scoping within a class
x = 1
class Foo:
	x = 5
	def f(self):
		print x
