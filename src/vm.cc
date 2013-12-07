/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

/* virtualmachine.cc: Virtual stack machine. */

#include <string>
#include <iostream>
#include "apyc.h"

using namespace std;

static const bool DEBUG_OUT = true;

/** Virtual machine instructions indicating which of command to emit. */
static const int CALL = 0;
static const int GOTO = 1;
static const int GTZ = 2;
static const int PUSH = 3;
static const int MOVE = 4;
static const int ALLOC = 5;
static const int COMPL = 6;
static const int COMPG = 7;
static const int COMPLE = 8;
static const int COMPGE = 9;
static const int COMPE = 10;
static const int COMPNE = 11;

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
	switch (type) {

		// e.g. call = (FuncDesc*) SM.pop();
		//		cf = call.frame;
		//      RETURN_ADDR.push(&&__R__15);
		//		goto **(call.label);
		//	__R__15:
		case CALL:
			numRetLabels++;
            emitComment("calling function");
			gcstring rlabel = "__R__" + numRetLabels;
			out << "    call = (FuncDesc*) SM.pop();" << endl;
			out << "    cf = call.frame;" << endl;
			out << "    RETURN_ADDR.push(&&" << rlabel << ");" << endl;
			out << "    goto **(call.label);" << endl;
			out << rlabel << ":" << endl;
			break;

		// arg: the name of the label to jump to
		// e.g. goto __L__16;
		case GOTO:
            emitComment("jumping to label " + arg);
			out << "    goto " << arg << ";" << endl;
			break;

		// arg: the name of the label to jump to
		// e.g. cmp = (int*) SM.pop();
		//		if (*(cmp)==0) goto __L__16;
		case GTZ:
            emitComment("jumping to label " + arg + " if top is 0");
			out << "    cmp = (int*) SM.pop();" << endl;
			out << "    if (*(cmp)==0) goto " << arg << ";" << endl;
			break;

		// arg: the data to push onto the stack. If 0, pushes the top of HEAP
		// e.g. SM.push(&cf.x);
		case PUSH:
			if arg == 0:
				emitComment("pushing first in HEAP onto SM");
				out << "    SM.push(HEAP[HEAP.size()-1]);" << endl;
			else:
				emitComment("pushing " + arg + " onto SM");
				out << "    SM.push(&(" << arg << "));" << endl;
			break;

		// arg: gcstring denoting the type of the value to be assigned
		// e.g. dst = SM.pop();
		// 		src = SM.pop();
		//		*(dst) = (src&1==1) ? src>>1 : src;
		case MOVE:
			// we'll have to use vartype at some point, I think
			// gcstring* vartype = (gcstring*)arg;
			emitComment("moving second in stack to first in stack");
			out << "    dst = SM.pop();" << endl;
			out << "    src = SM.pop();" << endl;
			out << "    *dst = *src;" << endl;
			break;

		// arg: gcstring denoting the creation of a new object
		// e.g. tmp_alloc = new $int(5);
		// 		HEAP.push(&tmp_alloc);
		case ALLOC:
			emitComment("allocating memory for: " + arg);
			out << "    tmp_alloc = " << arg << ";" << endl;
			out << "    HEAP.push(&tmp_alloc);" << endl;
			break;

		case COMPL:
			emitComment("comparing (<)");
			out << "    cmp1 = ($int*) SM.pop();" << endl;
			out << "    cmp2 = ($int*) SM.pop();" << endl;
			gcstring s1 = " *(cmp1).value() ";
			gcstring s2 = " *(cmp2).value() ";
			out << "    SM.push((" << s1 << "<" << s2 << "? 1 : 0);" << endl;
			break;

		case COMPG:
			emitComment("comparing (>)");
			out << "    cmp1 = ($int*) SM.pop();" << endl;
			out << "    cmp2 = ($int*) SM.pop();" << endl;
			gcstring s1 = " *(cmp1).value() ";
			gcstring s2 = " *(cmp2).value() ";
			out << "    SM.push((" << s1 << ">" << s2 << "? 1 : 0);" << endl;
			break;

		case COMPLE:
			emitComment("comparing (<=)");
			out << "    cmp1 = ($int*) SM.pop();" << endl;
			out << "    cmp2 = ($int*) SM.pop();" << endl;
			gcstring s1 = " *(cmp1).value() ";
			gcstring s2 = " *(cmp2).value() ";
			out << "    SM.push((" << s1 << "<=" << s2 << "? 1 : 0);" << endl;
			break;

		case COMPGE:
			emitComment("comparing (>=)");
			out << "    cmp1 = ($int*) SM.pop();" << endl;
			out << "    cmp2 = ($int*) SM.pop();" << endl;
			gcstring s1 = " *(cmp1).value() ";
			gcstring s2 = " *(cmp2).value() ";
			out << "    SM.push((" << s1 << ">=" << s2 << "? 1 : 0);" << endl;
			break;

		case COMPE:
			emitComment("comparing (==)");
			out << "    cmp1 = ($int*) SM.pop();" << endl;
			out << "    cmp2 = ($int*) SM.pop();" << endl;
			gcstring s1 = " *(cmp1).value() ";
			gcstring s2 = " *(cmp2).value() ";
			out << "    SM.push((" << s1 << "==" << s2 << "? 1 : 0);" << endl;
			break;

		case COMPNE:
			emitComment("comparing (!=)");
			out << "    cmp1 = ($int*) SM.pop();" << endl;
			out << "    cmp2 = ($int*) SM.pop();" << endl;
			gcstring s1 = " *(cmp1).value() ";
			gcstring s2 = " *(cmp2).value() ";
			out << "    SM.push((" << s1 << "!=" << s2 << "? 1 : 0);" << endl;
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
	cout << "    void* rtn_label = RETURN_ADDR.pop();" << endl;
	cout << "    goto **(rtn_label);" << endl;
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

void
VirtualMachine::emitComment (gcstring s)
{
	out << "/* " << s << " */" << endl;
}
