# Test various ways lines may be continued.

should_see_this_identifier = 42

# This is a comment, so the continuation should not count\
print should_see_this_identifier

# Likewise, this is a non-continued comment (with open brackets
print should_see_this_identifier

y = 16

print y \
  + 2

print (3, 17)

print [3, (2, 1),
      18]

print { 3: (2 ,[1,
            9],
          4),
        10
        : 1}

print 3 .__add__(
    19
    )
