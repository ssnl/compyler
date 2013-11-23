# basic none function type: test if the return type of a function is resolved to none
def f():
	pass
def g():
	return

print f() is g()
print g() is None
print f() is None
