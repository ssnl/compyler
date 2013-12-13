# and: testing simple and expression that evaulates to false
x = 1 and 0 and 3 and 5
y = x and 2
z = x and y and 3

a = "hi" and "" and "bye"
b = a and "why" and a
print x, y, z, a, b

