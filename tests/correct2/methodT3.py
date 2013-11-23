# basic method type: test assigning unbound method
class A:
  def foo(self, x):
    return 1

x = A.foo
y = x(A(), 1)
