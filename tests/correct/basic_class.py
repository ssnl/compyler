class MyClass:
	def __init__(self):
		self.x = 5
		self.y = 2
	print "Defined MyClass"

class AnotherClass of [$Type1,$Type2]:
	def __init__(self):
		self.p = 27

class A of [$T]:
        def __init__(self, val):
          print "A made with " + val
	def foo(self, s::str):
		return 0
	k = 10
	for i in range(10):
		print i,
        print k

a = A of int("string")
a.foo(None)

b = MyClass()
print b.x
print b.y

c = AnotherClass()
print c.p

