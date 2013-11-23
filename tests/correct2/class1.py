# basic class scope: instance variable scoping within a class
x = 1
class Foo:
	x = 5
	def __init__(self):
		print x

f = Foo()
