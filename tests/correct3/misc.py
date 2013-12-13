# class A:
#   x = 3
#   def foo(self):
#     pass
#
# y = A.x # rewritten to simply x
# a = A()
# a.x = 5
# y = a.x     # just a normal attrref
# a.foo() # rewritten as a call
# A.foo   # rewritten to simply foo
x, y = (3, 1) if 0 else (1 or 2, 0 and 3)

if x:
  if x:
    y = 3
    print y, "bye", "fight!"
  elif 0:
    print 3
  else:
    print "hi"

