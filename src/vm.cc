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
    gcstring s1, s2, rlabel, str;

    switch (instr) {

        // e.g. call = (FuncDesc*) SM.pop();
        //      currFrame = call.frame;
        //      RETURN_ADDR.push(&&__R__15);
        //      goto **(call.label);
        //  __R__15:
        case CALL:
            numRetLabels++;
            emitComment("calling function", 4);
            rlabel = "__R__" + numRetLabels;
            write("call = (FuncDesc*) SM.pop();", 4);
            write("currFrame = call.frame;", 4);
            write("goto **(call.label);", 4);
            write(rlabel + ":", 0);
        break;


        // arg: the name of the label to jump to
        // e.g. goto __L__16;
        case GOTO:
            str = *((gcstring*)arg);
            emitComment("jumping to label " + str, 4);
            write("goto " + str + ";", 4);
        break;


        // arg: gcstring*, the name of the label to jump to
        // e.g. cmp = (int*) SM.pop();
        //      if (*(cmp)==0) goto __L__16;
        case GTZ:
            str = *((gcstring*)arg);
            emitComment("jumping to label " + str +
                " if top is 0", 4);;
            write("cmp = (int*) SM.pop();", 4);
            write("if (*(cmp)==0) goto " + str + ";", 4);
        break;


        // arg: gcstring*, the data to push onto the stack.
        // if NULL, pushes the top of HEAP
        // e.g. SM.push(&currFrame.x);
        case PUSH:
            if (arg == NULL) {
                emitComment("pushing first in HEAP onto SM", 4);;
                write("SM.push(HEAP[HEAP.size()-1]);", 4);
            } else {
                str = *((gcstring*)arg);
                emitComment("pushing " + str + " onto SM", 4);;
                write("SM.push(&(" + str + "));", 4);
            }
        break;


        // arg: gcstring denoting the type of the value to be assigned
        // e.g. dst = SM.pop();
        //      src = SM.pop();
        //      *dst = *src;
        case MOVE:
            // we'll have to use vartype at some point, I think
            // gcstring* vartype = (gcstring*)arg;
            emitComment("moving second in stack to first in stack", 4);;
            write("dst = SM.pop();", 4);
            write("src = SM.pop();", 4);
            write("*dst = *src;", 4);
        break;


        // arg: gcstring denoting the creation of a new object
        // e.g. tmp_alloc = new $int(5);
        //      HEAP.push(&tmp_alloc);
        case ALLOC:
            str = *((gcstring*)arg);
            emitComment("allocating memory for: " + str, 4);
            write("tmp_alloc = " + str + ";", 4);
            write("HEAP.push(&tmp_alloc);", 4);
        break;


        case COMPL:
            emitComment("comparing (<)", 4);;
            write("cmp1 = ($int*) SM.pop();", 4);
            write("cmp2 = ($int*) SM.pop();", 4);
            write("tmp_alloc = new int(*cmp1.compareTo(*cmp2) < 0);", 4);
            write("HEAP.push(&tmp_alloc);", 4);
            write("SM.push(&tmp_alloc);", 4);
        break;


        case COMPG:
            emitComment("comparing (>)", 4);;
            write("cmp1 = ($int*) SM.pop();", 4);
            write("cmp2 = ($int*) SM.pop();", 4);
            write("tmp_alloc = new int(*cmp1.compareTo(*cmp2) > 0);", 4);
            write("HEAP.push(&tmp_alloc);", 4);
            write("SM.push(&tmp_alloc);", 4);
        break;


        case COMPLE:
            emitComment("comparing (<=)", 4);;
            write("cmp1 = ($int*) SM.pop();", 4);
            write("cmp2 = ($int*) SM.pop();", 4);
            write("tmp_alloc = new int(*cmp1.compareTo(*cmp2) <= 0);", 4);
            write("HEAP.push(&tmp_alloc);", 4);
            write("SM.push(&tmp_alloc);", 4);
        break;

        case COMPGE:
            emitComment("comparing (>=)", 4);;
            write("cmp1 = ($int*) SM.pop();", 4);
            write("cmp2 = ($int*) SM.pop();", 4);
            write("tmp_alloc = new int(*cmp1.compareTo(*cmp2) >= 0);", 4);
            write("HEAP.push(&tmp_alloc);", 4);
            write("SM.push(&tmp_alloc);", 4);
        break;


        case COMPE:
            emitComment("comparing (==)", 4);;
            write("cmp1 = ($int*) SM.pop();", 4);
            write("cmp2 = ($int*) SM.pop();", 4);
            write("tmp_alloc = new int(*cmp1.compareTo(*cmp2) == 0);", 4);
            write("HEAP.push(&tmp_alloc);", 4);
            write("SM.push(&tmp_alloc);", 4);
        break;


        case COMPNE:
            emitComment("comparing (!=)", 4);;
            write("cmp1 = ($int*) SM.pop();", 4);
            write("cmp2 = ($int*) SM.pop();", 4);
            write("tmp_alloc = new int(*cmp1.compareTo(*cmp2) != 0);", 4);
            write("HEAP.push(&tmp_alloc);", 4);
            write("SM.push(&tmp_alloc);", 4);
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
    write("goto **(currFrame.sl.return_addr);", 4);;
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
    write(label + ":", 0);
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
VirtualMachine::emitComment (gcstring s, int indent)
{
    string indentstr = "";
    if (DEBUG_OUT) {
        for (int i = 0; i < indent; i++) {
            indentstr += " ";
        }
        out << indentstr << "/* " << s << " */" << endl;
    }
}

void
VirtualMachine::write (gcstring s, int indent) {
    string indentstr = "";
    for (int i = 0; i < indent; i++) {
        indentstr += " ";
    }
    out << indentstr << s << endl;
}
