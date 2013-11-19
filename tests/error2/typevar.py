# basic nested typevar: tests if typevar nested inside an instance method properly errors
class A of [$T]:
  def __init__(self):
    x::$T = 3
