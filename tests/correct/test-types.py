x::Int = 3
print x

def incr(y::Int)::(Int)->Int:
  def h(a:: Int)::Int:
    return y+a
  return h

def decr(y::Int)::Int:
  return y - 1

def three():
  return 3

def add(x::Int, y::Int)::Int:
  return x + y

f::()->Int = three
g::(Int)->Int = decr
h::(Int, Int)->Int = add

p::(Int)->(Int)->Int = incr

print f(), g(42), h(7,9), p(2)(19)
