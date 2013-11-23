# basic attrref type: checks if attribute references resolves types properly
class A:
  a = 5
  b = 3
x = A.a
x = A.b
y = A.a
x = y
