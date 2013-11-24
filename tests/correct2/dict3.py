# adv dict: tests if dictionaries are recognized
class A:
  x = 1
  def __init__(self, x):
    self.x = x
  def getX(self):
    return self.x

x = {True:A(3), False:A(2)}
y = x[False].getX()

print y
