# print file: test printing to a file
f = open("random_file", "w+")
print >> f, "Hello",
close(f)
f = open("random_file", "r")
x = read(f)
print x, 1
