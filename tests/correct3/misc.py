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
print "leo is a maniac"
def man(x):
  if x:
    print 4
def foo():
  def bar():
    man(3)
  man(2)
  man(0)
  bar()
foo()
