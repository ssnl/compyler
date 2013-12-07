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
            comment("calling function", 4);
            rlabel = "__R__" + numRetLabels;
            code("call = (FuncDesc*) SM.pop();", 4);
            code("currFrame = call.frame;", 4);
            code("goto **(call.label);", 4);
            code(rlabel + ":", 0);
        break;


        // arg: the name of the label to jump to
        // e.g. goto __L__16;
        case GOTO:
            str = *((gcstring*)arg);
            comment("jumping to label " + str, 4);
            code("goto " + str + ";", 4);
        break;


        // arg: gcstring*, the name of the label to jump to
        // e.g. cmp = (int*) SM.pop();
        //      if (*(cmp)==0) goto __L__16;
        case GTZ:
            str = *((gcstring*)arg);
            comment("jumping to label " + str + " if top is 0", 4);
            code("cmp = ($int*) SM.pop();", 4);
            // I don't want to initialize a new $int(0) every time just for this
            // purpose, we I'm making a constant ZERO = new $int(0).
            code("if (*(cmp).compareTo(ZERO)) goto " + str + ";", 4);
        break;


        // arg: gcstring*, the data to push onto the stack.
        // if NULL, pushes the top of HEAP
        // e.g. SM.push(&currFrame.x);
        case PUSH:
            if (arg == NULL) {
                comment("pushing first in HEAP onto SM", 4);
                code("SM.push(HEAP[HEAP.size()-1]);", 4);
            } else {
                str = *((gcstring*)arg);
                comment("pushing " + str + " onto SM", 4);
                code("SM.push(&(" + str + "));", 4);
            }
        break;


        // arg: gcstring denoting the type of the value to be assigned
        // e.g. dst = SM.pop();
        //      src = SM.pop();
        //      *dst = *src;
        case MOVE:
            // we'll have to use vartype at some point, I think
            // gcstring* vartype = (gcstring*)arg;
            comment("moving second in stack to first in stack", 4);;
            code("dst = SM.pop();", 4);
            code("src = SM.pop();", 4);
            code("*dst = *src;", 4);
        break;


        // arg: gcstring denoting the creation of a new object
        // e.g. tmp_alloc = new $int(5);
        //      HEAP.push(&tmp_alloc);
        case ALLOC:
            str = *((gcstring*)arg);
            comment("allocating memory for: " + str, 4);
            code("tmp_alloc = " + str + ";", 4);
            code("HEAP.push(&tmp_alloc);", 4);
        break;


        case COMPL:
            comment("comparing (<)", 4);;
            code("cmp1 = ($ObjectBase*) SM.pop();", 4);
            code("cmp2 = ($ObjectBase*) SM.pop();", 4);
            code("tmp_alloc = new $int(*cmp1.compareTo(*cmp2) < 0);", 4);
            code("HEAP.push(&tmp_alloc);", 4);
            code("SM.push(&tmp_alloc);", 4);
        break;


        case COMPG:
            comment("comparing (>)", 4);;
            code("cmp1 = ($ObjectBase*) SM.pop();", 4);
            code("cmp2 = ($ObjectBase*) SM.pop();", 4);
            code("tmp_alloc = new $int(*cmp1.compareTo(*cmp2) > 0);", 4);
            code("HEAP.push(&tmp_alloc);", 4);
            code("SM.push(&tmp_alloc);", 4);
        break;


        case COMPLE:
            comment("comparing (<=)", 4);;
            code("cmp1 = ($ObjectBase*) SM.pop();", 4);
            code("cmp2 = ($ObjectBase*) SM.pop();", 4);
            code("tmp_alloc = new $int(*cmp1.compareTo(*cmp2) <= 0);", 4);
            code("HEAP.push(&tmp_alloc);", 4);
            code("SM.push(&tmp_alloc);", 4);
        break;

        case COMPGE:
            comment("comparing (>=)", 4);;
            code("cmp1 = ($ObjectBase*) SM.pop();", 4);
            code("cmp2 = ($ObjectBase*) SM.pop();", 4);
            code("tmp_alloc = new $int(*cmp1.compareTo(*cmp2) >= 0);", 4);
            code("HEAP.push(&tmp_alloc);", 4);
            code("SM.push(&tmp_alloc);", 4);
        break;


        case COMPE:
            comment("comparing (==)", 4);;
            code("cmp1 = ($ObjectBase*) SM.pop();", 4);
            code("cmp2 = ($ObjectBase*) SM.pop();", 4);
            code("tmp_alloc = new $int(*cmp1.compareTo(*cmp2) == 0);", 4);
            code("HEAP.push(&tmp_alloc);", 4);
            code("SM.push(&tmp_alloc);", 4);
        break;


        case COMPNE:
            comment("comparing (!=)", 4);;
            code("cmp1 = ($ObjectBase*) SM.pop();", 4);
            code("cmp2 = ($ObjectBase*) SM.pop();", 4);
            code("tmp_alloc = new $int(*cmp1.compareTo(*cmp2) != 0);", 4);
            code("HEAP.push(&tmp_alloc);", 4);
            code("SM.push(&tmp_alloc);", 4);
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
    code("goto **(currFrame.sl.return_addr);", 4);;
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
    code(label + ":", 0);
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
VirtualMachine::comment (gcstring s, int indent)
{
    if (DEBUG_OUT) {
        string indentstr = "";
        for (int i = 0; i < indent; i++) {
            indentstr += " ";
        }
        out << indentstr << "/* " << s << " */" << endl;
        delete &indentstr;
    }
}

void
VirtualMachine::code (gcstring s, int indent) {
    string indentstr = "";
    for (int i = 0; i < indent; i++) {
        indentstr += " ";
    }
    out << indentstr << s << endl;
}
