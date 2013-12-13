x::int = 10
if 1 > 0:
  print "pass if"
  while 5 > x:
    print "fail"
  else:
    print "pass while"
    for i in [1,2,3]:
      print x + i
      if x > 12:
        print "fail inner if"
      for j in [5,6,7]:
        print i,j
    else:
      print "fail for"
else:
  print "fail if"
