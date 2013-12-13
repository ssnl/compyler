# logical: testing basic combination of logical expressions
x = 1 and 3 or 4 and 2
y = (2 and 5 or 0) and 2
z = x or y and y or x and 2

a = "hi" and "bye" or "" and "sight"
b = "why" or ("kite" or "night" and "fight")

print x, y, z,
print a, b
