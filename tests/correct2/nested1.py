# adv nested: tests nested definitions and control structures
class A:
    def f(self,x):
        def g():
            for y in [1,2]:
                if self:
                    pass
        print x
a = A()
a.f(5)
