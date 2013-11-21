# basic instance variable class typed: tests that typed instance variables are properly resolved
class A:
	x::int = 5
	y::str = "hello"

a::A = A()
a.x
a.y
