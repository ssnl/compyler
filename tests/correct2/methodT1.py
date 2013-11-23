# basic method type: checks that method types are resolved properly
class A:
  def foo(self, x):
    pass

x = A()
x.foo(3)
