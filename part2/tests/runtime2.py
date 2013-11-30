# Implementations of native functions.

# Use this file as a prefix to pyunparsed files.  The files must be alpha
# converted (--alpha) to avoid name clashes.


import sys

def __donotcall__(*x):
    raise RuntimeError("Call to unimplemented function.")

def __None__():
    return None

def __truth__(x):
    return bool(x)

def __not__(x):
    return not x

def __xrange__(low, high):
    return xrange(low, high)

def __len__range__(r):
    return len(r)

def __add__int__(x, y):
    return x+y

def __sub__int__(x, y):
    return x-y

def __mul__int__(x, y):
    return x*y

def __floordiv__int__(x, y):
    return x//y

def __mod__int__(x, y):
    return x%y

def __pow__int__(x, y):
    return x**y

def __neg__int__(x):
    return -x

def __pos__int__(x):
    return x

def __lt__int__(x, y):
    return x<y

def __gt__int__(x, y):
    return x>y

def __le__int__(x, y):
    return x<=y

def __ge__int__(x, y):
    return x>=y

def __eq__int__(x, y):
    return x==y

def __ne__int__(x, y):
    return x != y

def __toint__str__(x):
    return int(x)

# Type str

def __add__str__(x, y):
    return x+y

def __mul__str__(x, y):
    return x*y

def __rmul__str__(x, y):
    return x * y

def __lt__str__(x, y):
    return x<y

def __gt__str__(x, y):
    return x>y

def __le__str__(x, y):
    return x<=y

def __ge__str__(x, y):
    return x>=y

def __eq__str__(x, y):
    return x==y

def __ne__str__(x, y):
    return x!=y

def __getitem__str__(S, k):
    return S[k]

def __getslice__str__(S, L, U):
    return S[L:U]

def __len__str__(S):
    return len(S)

def __tostr__(x):
    return str(x)

# Type list

def __getitem__list__(S, k):
    return S[k]

def __getslice__list__(S, L, U):
    return S[L:U]

def __len__list__(S):
    return len(S)

def __argv__():
    return sys.argv

# Type file

def __open1__(name):
    return open(name)

def __open2__(name, mode):
    return open(name, mode)

def __close__(f):
    f.close()

def __readline__(f):
    return f.readline()

def __read__(f):
    return f.read()

def __standard_file__(k):
    return sys.stdin if k == 0 else sys.stdout if k == 1 else sys.stderr

# Type dict

def __getitem__dict__(D, x):
    return D[x]

def __len__dict__(D):
    return len(D)

# Backwards from regular Python
def __contains__dict__(x, D):
    return x in D

# Backwards from regular Python
def __notcontains__dict__(x, D):
    return x not in D


# General

def __is__(x, y):
    return x is y

def __isnot__(x, y):
    return x is not y
