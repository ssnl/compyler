y = 4; x = 6
while x > y: x = x - 1; print x
y = 4; x = 6
while x > y:
  x = x - 1
  print x

y = 4; x = 6
while x > y:
  x = x - 1
  print x
else: y = y + 1; print y

y = 4; x = 6
while x > y:
  if x % 2:
    break
  x = x - 1
else:
  print 17

y = 4; x = 6
while x > y:
  x = x - 1
  if x % 2:
    continue
  print x
else:
  print 17
