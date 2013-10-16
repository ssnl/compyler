print '''Here is
a multi line string'''
print ''' and here is a single liner'''
print "Parsing is 'Fun'"
print 'Yet another kind of "string"'
print "here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\"
print 'here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\'
print """here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\"""
print '''here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\'''
print """here are some escapes: "'\a\b\t\n\r\e\0\v\f\\"""
print '''here are some escapes: "'\a\b\t\n\r\e\0\v\f\\'''
print 'Unrecognized escapes: \c\e\,'
print "Unrecognized escapes: \c\e\,"

#Empty strings
print ''
print ""
print """"""
print ''''''
print '''''123'''

# Raw strings
print r'''Here is
a multi line string'''
print r''' and here is a single liner'''
print r"Parsing is 'Fun'"
print r'Yet another kind of "string"'
print r"here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\"
print r'here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\'
print r"""here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\"""
print r'''here are some escapes: \"\'\a\b\t\n\r\e\0\v\f\\'''
print r"""here are some escapes: "'\a\b\t\n\r\e\0\v\f\\"""
print r'''here are some escapes: "'\a\b\t\n\r\e\0\v\f\\'''
print r'Unrecognized escapes: \c\e\,'
print r"Unrecognized escapes: \c\e\,"
print r'''More unrecognized escapes: \X \
'''
print r''
print r""
print r""""""
print r''''''
print r'''''123'''

print "Hello, " "world"
print 'Hello,' " " r"world"
