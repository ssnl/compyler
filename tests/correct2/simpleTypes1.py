# basic rewrite simpletype allocator: tests if simple types in an allocator are rewritten as calls
class A:
  def __init__(self, x):
    print x
x = A(3)
