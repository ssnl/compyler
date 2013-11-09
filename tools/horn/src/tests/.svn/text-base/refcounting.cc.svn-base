/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

#include "../data/horn-common.h"
#include <cstdlib>

class Tree;
typedef Pointer<Tree> TreePtr;
typedef Pointer<const Tree> ConstTreePtr;

class Tree : public RefCounted {
public:

    Tree (int label, const TreePtr& left, const TreePtr& right) 
	: left (left), right (right), label (label) { }

    TreePtr left, right;
    int label;

};

int
main ()
{
    TreePtr top = new Tree (100, NULL, NULL);
    top->left = new Tree (50, NULL, NULL);
    top->right = new Tree (150, NULL, NULL);
    top = NULL;
    ConstTreePtr top2 = new Tree (100, new Tree (50, NULL, NULL), 
				  new Tree (150, NULL, NULL));
    top2 = NULL;
}

    
	
