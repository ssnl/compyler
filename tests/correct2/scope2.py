# basic class scope instance variable: tests that instance variables are distinguished from globals
x = 4
class A:
	x = 8
	def f(self):
		print x
		print self.x
