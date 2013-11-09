/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

#ifndef _SIMPLETREE_H_
#define _SIMPLETREE_H_

#include "horn-common.h"

class Simple_Token;
class Simple_Tree;

class Simple_Node : public CommonNode <Simple_Node, Simple_Token, Simple_Tree> {
};

class Simple_Tree : public CommonTree<Simple_Node, Simple_Token, Simple_Tree> {
public: 
   /** An internal node with operator OPER (which must be a token),
     *  and the children between iterators BEGIN (inclusive) and END 
     *  (exclusive). */
    template <class InputIterator>
    Simple_Tree (Simple_Node::NodePtr oper, 
		 InputIterator begin, InputIterator end) 
	: CommonTree<Simple_Node, Simple_Token, Simple_Tree>(oper, begin, end) { }

    template <class InputIterator>
    Simple_Tree (int syntax, InputIterator begin, InputIterator end) 
	: CommonTree<Simple_Node, Simple_Token, Simple_Tree>(syntax, begin, end) { }

};

class Simple_Token : public CommonToken<Simple_Node, Simple_Token, Simple_Tree> {
public:
    Simple_Token (int syntax, const char* text, size_t len, bool owner = false)
	: CommonToken<Simple_Node, Simple_Token, Simple_Tree> (syntax, text, len, owner) { }

    Simple_Token (int syntax, const std::string& text, bool owner)
        : CommonToken<Simple_Node, Simple_Token, Simple_Tree> (syntax, text, owner) { }
};

typedef Tree_Semantics<Simple_Node> Simple_Tree_Semantics;

#endif
