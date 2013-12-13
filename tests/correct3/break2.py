# break while: tests if we break properly out of a while loop
i = 0
while True:
  print i
  i = i + 1
  if i > 5:
    break
