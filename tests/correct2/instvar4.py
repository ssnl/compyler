# basic instance variable class: tests chained attributes
class A:
	x = B()

class B:
	y = 5

A().x.y
