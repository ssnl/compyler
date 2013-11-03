# Test trailing comma in parameter list.

def f1(x,):
    print x

def f2(x, y,):
    print x + y

f1(14)
f2(39, 3)