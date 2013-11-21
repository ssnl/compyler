# basic scope function while: tests scoping rules on function
x = 3
y = 1
def f():
	x = 1
	z = 5
	while z:
		if z:
			print x,y
		else:
			y = 7
		z = 0
x = 12

f()
