# ifexpr: testing if simple if chained expressions work
x = 1 if "hi" else 4 if "" else 2
y = x if "" else 7 if "" else 0
z = "?" if y else "fat" if x else "12"
print x, y, z
