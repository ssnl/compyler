# alloc: tests basic allocators
class A:
  x = 1
  def __init__(self, y):
    self.x = y
a = A(1)
b = A(15)
print a.x, b.x
