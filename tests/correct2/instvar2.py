# basic instance variable class: tests that instance variables are properly resolved
y = 1
class A:
	y = 3

A().y + y
