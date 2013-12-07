/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

/* virtualmachine.cc: Virtual stack machine. */

#include <string>
#include <iostream>
#include "apyc.h"

using namespace std;

/** Virtual machine instructions indicating which of command to emit. */
static const int CALL = 0;
static const int GOTO = 1;
static const int GTZ = 2;
static const int PUSH = 3;
static const int MOVE = 4;
static const int COMPL = 5;
static const int COMPG = 6;
static const int COMPLE = 7;
static const int COMPGE = 8;
static const int COMPE = 9;

VirtualMachine::VirtualMachine (ostream& _out)
	: out(_out)
{
}

void
VirtualMachine::emit (int instr, void* arg)
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
