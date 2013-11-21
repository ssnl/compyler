# adv instance variable class typed: tests that typed instance variables are properly resolved
class A:
	x::int = 5
	y::B = B()

class B:
	x = 2
	y::int = 4

a::A = A()
b = B()
print a.x
print a.y.x
print a.y.y
