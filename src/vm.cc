/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

/* virtualmachine.cc: Virtual stack machine. */

#include <string>
#include <iostream>
#include "apyc.h"

using namespace std;

/** Virtual machine flags indicating which types of commands to emit. */
#define CALL 0;
#define GOTO 1;
#define GTZ 2;
#define PUSH 3;
#define MOVE 4;
#define COMPL 5;
#define COMPG 6;
#define COMPLE 7;
#define COMPGE 8;
#define COMPE 9;


VirtualMachine::VirtualMachine (ostream& _out)
	: out(_out)
{
}

void
VirtualMachine::emit (int type, void* arg) 
{
}

void
VirtualMachine::emitPrologue () 
{
}

void
VirtualMachine::emitEpilogue () 
{
}

Label
VirtualMachine::newLabel () 
{
	return NULL;
}

void
VirtualMachine::placeLabel (Label label) 
{
}

void
VirtualMachine::emitRuntime () 
{
}
