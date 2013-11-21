# basic method class unbound: test that unbound methods can be saved
class A:
	def f(self):
		return 10

umthd::(A)->int = A.f
a::A = A()
umthd(a)
lst = [A.f,]
umthd = lst[0]