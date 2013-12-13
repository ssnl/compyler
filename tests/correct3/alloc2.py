# alloc: test basic allocators
class A:
  x = 2
a = A()
b = A()
print a.x, b.x
a.x = 3
print a.x, b.x
