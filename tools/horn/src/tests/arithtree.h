/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

#ifndef _ARITHTREE_H_
#define _ARITHTREE_H_

#include "horn-common.h"

class Token;
class Tree;

class Node : public CommonNode <Node, Token, Tree> {
public:
    virtual void print (std::ostream&) = 0;
};

std::ostream& 
operator<< (std::ostream& os, const Node::NodePtr& x)
{
    x->print(os);
    return os;
}

std::ostream& 
operator<< (std::ostream& os, Node* x)
{
    x->print(os);
    return os;
}

class Tree : public CommonTree<Node, Token, Tree> {
public: 

    void print (std::ostream& os) {
	os << "\"" << oper() << "\"(";
	if (arity () > 0) {
	    os << child(0);
	    for (size_t i = 1; i < arity (); i += 1) {
		os << ",";
		os << child (i);
	    }
	    os << ")";
	}
    }
	
    typedef CommonTree<Node, Token, Tree> Parent;
    NODE_BASE_CONSTRUCTORS (Tree, Parent);

};

class Token : public CommonToken<Node, Token, Tree> {
    typedef CommonToken<Node, Token, Tree> Parent;
public:
    TOKEN_CONSTRUCTORS (Token, Parent);

    void print (std::ostream& os) {
	os << as_string ();
    }

};

#endif
