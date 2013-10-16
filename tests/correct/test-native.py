def atoi(S):
  native "native_atoi"

def atol(S): native "native_atol"

def native_atoi(S):
  print 'Called native method "atoi"'

def native_atol(S):
  print 'Called native method "atol"'

atoi(5)
atol(7)
