memo = {}
def fib(x):
	it = 0
	if x == 0:
		return 0
	elif x == 1:
		return 1
	elif x in memo:
		return memo[x]
	else:
		res = fib(x-1) + fib(x-2)
		memo[x] = res
		return res

print fib(5)
print fib(6)
print fib(7)
print fib(8)
print fib(9)
print fib(10)
print "Memo:"
print memo
