/* -*- C++ -*- */

#ifndef ARITH_H_
#define ARITH_H_

#include <cstdlib>
#include <string>
#include "horn-common.h"

class Arith_Token;
class Arith_Tree;

class Arith_Node : public CommonNode<Arith_Node, Arith_Token, Arith_Tree> {
public:
    virtual double eval (); 
    virtual void print (std::ostream& os);
};

class Arith_Tree : public CommonTree<Arith_Node, Arith_Token, Arith_Tree> {
public: 

    typedef CommonTree<Arith_Node, Arith_Token, Arith_Tree> Parent;
    NODE_BASE_CONSTRUCTORS (Arith_Tree, Parent);
                            
};

class Arith_Token : public CommonToken<Arith_Node, Arith_Token, Arith_Tree> {
public:
    Arith_Token (int syntax, const char* text, size_t len, bool owner = false);
    Arith_Token (int syntax, const std::string& text, bool owner);

    double eval ();
    void print (std::ostream& os);

private:
    double _value;
};

/** Extend << operator on streams to include Arith_Nodes. */
std::ostream& operator<< (std::ostream& os, const Arith_Node::NodePtr& val);
/** Extend << operator on streams to include Arith_Nodes. */
std::ostream& operator<< (std::ostream& os, Arith_Node* val);

#endif
