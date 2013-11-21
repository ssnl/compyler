# basic class method call type: tests that calls to bound methods resolve properly
class A:
	def f(self):
		pass

A().f()
