def x(a::$X, b::int):
	pass
	print a, b

x(1, 2);
i::int = 5
x(i, 2)

j::$A = "test"; x(j, 2)
f = list
g = list
h = dict
z = f of int()
l = g of int()
d = h of [int, string]()

z.extend([1, 2, 3])
l.extend([1, 2, 3])

for key::int in range(len(z)):
	pass
	print z[key] == l[key],
pass
print

d[3] = "elem"
pass
print d[3]
print l[:]

def run(a::(int, int)->int)::None:
	pass
	x::int = 3
	y::str = 2
	a(x, y)

run(x)

def incr(i, n::int)::int:
	pass
	return n+1

print incr("uselssvar", 3)

class aclass of [$T, $X, $Z]:
        def test(self): print 5;
	def foot(self, m::int): native "incr"
	def boop(self):
         pass; return 3

a::int = aclass()

print a.foot(3)

def f(n):
	i::int = 2
	while i <= n:
		if 1 < i % 7 <= 2:
			print i,
                        i = i * 7
			pass
        else:
		pass
		s = i + 2; pass; t = 3; t = t + s ** 2
		print "s =", s, "t =", t

f(3); f(4); f(5);

# Random comment

""" More Random
comments that span the space
of time where we eat
french fries and roast
human pigflesh
and squash them with our boom boxes.
Then the flies go waaa and we create
new crates of lines that wars with other
ants.
"""
pass
if True:
	if True:
		pass
		if True:
			pass
			if True:
				x::string = 42
				if True:
					if True:
						if True:
							x = "you are the man"
							if False:
								pass
							elif True:
								pass
								print "badabomp boomp born CHAIRHAIR"
							else:
								pass
								print "NOOOOOOOOO mushrooom couch"
						pass
				print x
	for i in ["wat", "fat", "mat"]:
		pass
		print i
	while (False):
		pass
		print "NEVER said the wise cornflake"
	else:
		print "I am a pillow mushgrew"


