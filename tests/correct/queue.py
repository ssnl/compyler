class Queue of [$Type]:
   L:: list of $Type = []
   def add(self, x:: $Type):
       self.L.append(x)
   def remove(self)::$Type:
       r = self.L[0]
       self.L[0:1] = []
       return r

p:: Queue of Int = Queue of Int()

p.add(3)
p.add(5)
