# gc: simple test of the garbage collector
for x in xrange(1, 10):
  if (x % 9 == 0):
    #__gc__()
    pass
  y = 1
print y
