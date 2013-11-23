# auto scope: failed autograder test for scoping
x = 5
class A:
    x = 1
    def f(self):
        print x, self.x
q::A = A()
q.f()
