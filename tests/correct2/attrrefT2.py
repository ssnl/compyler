# basic attrref type: checks if attribute references resolves types properly
class A:
  def foo(self):
    pass
  def bar(self):
    pass
  def gru(self, x):
    pass
x = A.bar
