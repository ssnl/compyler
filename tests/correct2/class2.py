# basic class method type: tests typed instance methods within a class
class Foo of [$T]:
	def __init__(self,t::$T):
		print t

Foo of int(5)
