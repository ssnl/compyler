def swap(ls, i1, i2):
  tmp = ls[i1]
  ls[i1] = ls[i2]
  ls[i2] = tmp

def quicksort(ls):
  def partition(ls, start, length):
    end = start + length
    val = ls[end-1]
    store = start

    for i in range(start, end - 1, 1):
      if ls[i] < val:
        swap(ls, store, i)
        store = store + 1
    swap(ls, end - 1, store)
    return store

  def quicksort_helper(ls, start, length):
    if length <= 1:
      return
    key = partition(ls, start, length)
    quicksort_helper(ls, start, key - start)
    quicksort_helper(ls, key + 1, length - key + start - 1)

  quicksort_helper(ls, 0, len(ls))

ls1 = [123, 124, 12, 435, 1234, 123, 0x2341, 023424]
ls2 = [1, 5, 123, 41, 125, 123, 1521, 0x123, 0x1121, 01233, 023345]
ls3 = ["asdf", "wenson", "fugly", "here", "bios", "computer"]

quicksort(ls1)
quicksort(ls2)
quicksort(ls3)

print ls1
print ls2
print ls3
