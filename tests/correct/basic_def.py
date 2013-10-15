def square(x,y):
	y = x * x
	print y
	return y

def square2(x::int)::int:
	print x * x

print square(2,"TEST")
square2(3)
