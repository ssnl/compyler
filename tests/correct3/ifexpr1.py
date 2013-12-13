# ifexpr: testing if simple if expressions work
x = "hi" if 1 else "bye"
y = x if 0 else "why?"
z = 0 if y else 3
print x, y, z
