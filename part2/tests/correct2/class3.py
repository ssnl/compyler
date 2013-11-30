# basic class rewrite init: rewriting AST for classes with no init method
class Gru:
  x = 1
  def bar(self):
    pass

g = Gru()
print g.x
