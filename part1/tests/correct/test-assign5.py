# Assign to target list (1)

a = (1, 2, 3, 4, 5)

b, c, d, e, f = a
print b, c, d, e, f

c, d, e, f, b = a
print b, c, d, e, f

a = (1, (2, 3), 4, 5)
g, hi, j, k = a
h, i = hi
print g, h, i, j, k

a = [42]
b = a
c, = a
(d,) = a
print b, c, d
[e] = a
print e
