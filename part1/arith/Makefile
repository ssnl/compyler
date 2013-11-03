
CXX = g++

CXXFLAGS = -g -Wall

.PHONY: clean

arith : exprs-parser.o arith.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lm

exprs-parser.cc exprs-lexer.cc horn-common.h exprs-parser.hh : exprs.hn
	horn $<

exprs-parser.o : exprs-parser.cc exprs-lexer.cc horn-common.h exprs-parser.hh \
		 arith.h

arith.o : horn-common.h exprs-parser.hh arith.h

clean:
	$(RM) *.o *~ *-parser* *-lexer* *.hh horn-common.h arith
