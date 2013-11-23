# basic typevar: tests if a typevar of an instance variable resolves properly
class A of [$T]:
  y::$T = 3

a = A of int(4)
print a.y
