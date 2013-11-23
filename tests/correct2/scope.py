# auto scoping: failed scoping test from autograder
x = 3
y = 2

def f ():
    x = 1
    z = 1
    while z != 3:
        if z == 2:
           print x, y
           z = 3
        else:
           y = 5
           z = 2

x = 12

f()
