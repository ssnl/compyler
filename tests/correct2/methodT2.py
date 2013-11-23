# basic overload method type: test that overloaded method type is resolved properly
class A:
  def foo(self):
    pass
  def foo(self, x):
    pass
  def foo(self, x, y):
    pass
x = A()
x.foo()
x.foo(3)
x.foo("hi", 3)
