
for i in (0,1,2,3,4,5,6,7,8,9):
	j = 0
	while j < 10:
		j = j + 1
		if (i + j) % 10 == 0:
			print i,j
	else:
		print "while loop complete"
else:
	print "for loop complete"
