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
static const int COMPNE = 10;

/** Constants corresponding to runtime data structure variable names. */
static const gcstring STACK = "STACK";
static const gcstring HEAP = "HEAP";
static const gcstring SM = "SM";
static const gcstring CURR_FRAME = "curr_frame";

VirtualMachine::VirtualMachine (ostream& _out)
    : out(_out)
{
}

void
VirtualMachine::emit (int instr, void* arg)
{
	// out <<  << endl;
	switch (type) {

		/** CALL **/
		case CALL:
			numRetLabels++;
			out << "CallDesc* func = (CallDesc*) STACK.pop();" << endl;
			out << "cf = func.frame;" << endl;
			out << "goto **(func.label);" << endl;
			out << "__R__" + numRetLabels << ":" << endl;
			break;

		/** GOTO **/
		// arg: the name of the label to jump to
		case GOTO:
			out << "goto " << arg << ";" << endl;
			break;

		/** GTZ **/
		// arg: the name of the label to jump to
		case GTZ:
			out << "cmp = (int) STACK.pop();" << endl;
			out << "if (cmp==0) goto " << arg << ";" << endl;
			break;

		/** PUSH **/
		// arg: the data to push onto the stack
		case PUSH:
			out << "STACK.push(" << arg << ");" << endl;
			break;

		/** MOVE **/
		// arg: gcstring denoting the type of the value to be assigned
		case MOVE:
			// we'll have to use vartype at some point, I think
			// gcstring* vartype = (gcstring*)arg;
			out << "dst = STACK.pop();" << endl;
			out << "itm = STACK.pop();" << endl;
			out << "*(dst) = ((itm&1==1) ? itm>>1 : itm);" << endl;
			break;

		/** COMPL **/
		case COMPL:
			out << "cmp1 = (int) STACK.pop();" << endl;
			out << "cmp2 = (int) STACK.pop();" << endl;
			out << "STACK.push((cmp1 < cmp2) ? 1 : 0);" << endl;
			break;

		/** COMPG **/
		case COMPG:
			out << "cmp1 = (int) STACK.pop();" << endl;
			out << "cmp2 = (int) STACK.pop();" << endl;
			out << "STACK.push((cmp1 > cmp2) ? 1 : 0);" << endl;
			break;

		/** COMPLE **/
		case COMPLE:
			out << "cmp1 = (int) STACK.pop();" << endl;
			out << "cmp2 = (int) STACK.pop();" << endl;
			out << "STACK.push((cmp1 <= cmp2) ? 1 : 0);" << endl;
			break;

		/** COMPGE **/
		case COMPGE:
			out << "cmp1 = (int) STACK.pop();" << endl;
			out << "cmp2 = (int) STACK.pop();" << endl;
			out << "STACK.push((cmp1 >= cmp2) ? 1 : 0);" << endl;
			break;

		/** COMPE **/
		case COMPE:
			out << "cmp1 = (int) STACK.pop();" << endl;
			out << "cmp2 = (int) STACK.pop();" << endl;
			out << "STACK.push((cmp1 == cmp2) ? 1 : 0);" << endl;
			break;

		/** COMPNE **/
		case COMPNE:
			out << "cmp1 = (int) STACK.pop();" << endl;
			out << "cmp2 = (int) STACK.pop();" << endl;
			out << "STACK.push((cmp1 != cmp2) ? 1 : 0);" << endl;
			break;
	}
}

void
VirtualMachine::emitPrologue () 
{
}

void
VirtualMachine::emitEpilogue () 
{
	cout << "goto __R__" + numRetLabels << ";" << endl;
}

VMLabel
VirtualMachine::newLabel () 
{
	numLabels++;
	return VMLabel("__L__" + numLabels);
}

void
VirtualMachine::placeLabel (VMLabel label) 
{
	out << label << ":" << endl;
}

void
VirtualMachine::emitRuntime () 
{
    out << "#include \"runtime.h\"\n"
        << "int main(int argc, char* argv[]) {\n"
        << "    cout << \"Hello, world!\" << endl;\n"
        << "}\n";
}
