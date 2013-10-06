
CXXFLAGS = -g

default: test

test: test-parser.o
	g++ -g -o $@ $<

test-parser.o: test-parser.cc

test-parser.cc : test.hn
	horn test.hn

clean:
	rm -f *.o *~ 
	rm -f test test.cc test.output horn-common.h horn-parse-lex.cc test-*


