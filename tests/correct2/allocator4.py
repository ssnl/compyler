# basic overload allocator init: test allocator of class with overloaded __init__
class A:
  def __init__(self):
    pass
  def __init__(self, x):
    pass

x = A()
y = A(3)

