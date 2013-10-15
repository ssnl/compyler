def square(x,y):
	y = x * x
	print y
	return y
def square2(x::int)::int:
	print x * x
def square3(x::int):
	native "C_PROGRAM"
