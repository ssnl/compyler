# basic attrref type: checks if attribute references resolves types properly
class A:
  def foo(self):
    pass
  def foo(self, x):
    pass
x = A.foo
x(A(), 3)
