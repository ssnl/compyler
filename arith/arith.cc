#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include "arith.h"
#include "exprs-parser.hh"

using namespace std;

				/* Implementations for Arith_Node */

double
Arith_Node::eval ()
{
    return 0.0;
}

void
Arith_Node::print (ostream& os)
{
}

ostream&
operator<< (ostream& os, const Arith_Node::NodePtr& v)
{
    if (v != NULL)
	v->print(os);
    return os;
}

ostream&
operator<< (ostream& os, Arith_Node* v)
{
    if (v != NULL)
	v->print(os);
    return os;
}


				/* Implementations for Arith_Token */
Arith_Token::Arith_Token (int syntax, const char* text, size_t len, bool owner)
    : CommonToken<Arith_Node, Arith_Token, Arith_Tree> (syntax, text, 
							len, owner),
      _value (atof(std::string(text, len).c_str()))
{
}

Arith_Token::Arith_Token (int syntax, const std::string& text, bool owner)
    : CommonToken<Arith_Node, Arith_Token, Arith_Tree> (syntax, text,
    owner)
{
}

double
Arith_Token::eval () {
    return _value;
}

void
Arith_Token::print (ostream& os)
{
    os << _value;
}

class Add_Tree : public Arith_Tree {
public:

    double eval () {
        return child(0)->eval () + child(1)->eval ();
    }

    void print (ostream& os) {
	os << "(" << child(0) << "+" << child(1) << ")";
    }

protected:

    NODE_CONSTRUCTORS (Add_Tree, Arith_Tree);
};

NODE_FACTORY (Add_Tree, '+');

class Sub_Tree : public Arith_Tree {
public:
    double eval () {
        return child(0)->eval () - child(1)->eval ();
    }

    void print (ostream& os) {
	os << "(" << child(0) << "-" << child(1) << ")";
    }

private:

    NODE_CONSTRUCTORS (Sub_Tree, Arith_Tree);

};

NODE_FACTORY (Sub_Tree, '-');

class Mult_Tree : public Arith_Tree {
public:
    double eval () {
        return child(0)->eval () * child(1)->eval ();
    }

    void print (ostream& os) {
	os << "(" << child(0) << "*" << child(1) << ")";
    }

private:

    NODE_CONSTRUCTORS (Mult_Tree, Arith_Tree);
};

NODE_FACTORY (Mult_Tree, '*');

class Div_Tree : public Arith_Tree {
public:
    double eval () {
        return child(0)->eval () / child(1)->eval ();
    }

    void print (ostream& os) {
	os << "(" << child(0) << "/" << child(1) << ")";
    }

private:
    NODE_CONSTRUCTORS (Div_Tree, Arith_Tree);

};

NODE_FACTORY (Div_Tree, '/');

class Expo_Tree : public Arith_Tree {
public:
    double eval () {
	return pow(child(0)->eval(), child(1)->eval());
    }

    void print (ostream& os) {
	os << "(" << child(0) << "**" << child(1) << ")";
    }

private:
    NODE_CONSTRUCTORS (Expo_Tree, Arith_Tree);

};

NODE_FACTORY (Expo_Tree, EXPO);
