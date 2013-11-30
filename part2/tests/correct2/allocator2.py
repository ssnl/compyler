# basic allocator: test simple allocator call of class with typed parameter
class A of [$T]:
	pass
x = A of [int]()
y = A of [str]()
