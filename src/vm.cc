/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

/* virtualmachine.cc: Virtual stack machine. */

#include <string>
#include <iostream>
#include <sstream>
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
static const int NATIVE = 12;

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
VirtualMachine::emit (int instr)
{
    gcstring s1, s2, rlabel;
    switch (instr) {

        // e.g. call = (FuncDesc*) SM.pop();
        //      currFrame = call.frame;
        //      RETURN_ADDR.push(&&__R__15);
        //      goto **(call.label);
        //  __R__15:
        case CALL:
            numRetLabels++;
            comment("calling function");
            rlabel = "__R__" + numRetLabels;
            code("call = (FuncDesc*) SM.pop();");
            code("currFrame.return_addr = " + rlabel);
            code("tmp_slink = &call.frame;");
            code("goto *(call.label);");
            code(rlabel + ":", 0);
        break;

        // e.g. dst = SM.pop();
        //      src = SM.pop();
        //      *dst = *src;
        case MOVE:
            comment("moving second in stack to first in stack");;
            code("dst = SM.pop();");
            code("src = SM.pop();");
            code("*dst = *src;");
        break;

        case COMPL:
            comment("comparing (<)");;
            code("cmp1 = ($ObjectBase*) SM.pop();");
            code("cmp2 = ($ObjectBase*) SM.pop();");
            code("tmp_alloc = new $Integer(*cmp1.compareTo(*cmp2) < 0);");
            code("HEAP.push(&tmp_alloc);");
            code("SM.push(&tmp_alloc);");
        break;

        case COMPG:
            comment("comparing (>)");;
            code("cmp1 = ($ObjectBase*) SM.pop();");
            code("cmp2 = ($ObjectBase*) SM.pop();");
            code("tmp_alloc = new $Integer(*cmp1.compareTo(*cmp2) > 0);");
            code("HEAP.push(&tmp_alloc);");
            code("SM.push(&tmp_alloc);");
        break;

        case COMPLE:
            comment("comparing (<=)");;
            code("cmp1 = ($ObjectBase*) SM.pop();");
            code("cmp2 = ($ObjectBase*) SM.pop();");
            code("tmp_alloc = new $Integer(*cmp1.compareTo(*cmp2) <= 0);");
            code("HEAP.push(&tmp_alloc);");
            code("SM.push(&tmp_alloc);");
        break;

        case COMPGE:
            comment("comparing (>=)");;
            code("cmp1 = ($ObjectBase*) SM.pop();");
            code("cmp2 = ($ObjectBase*) SM.pop();");
            code("tmp_alloc = new $Integer(*cmp1.compareTo(*cmp2) >= 0);");
            code("HEAP.push(&tmp_alloc);");
            code("SM.push(&tmp_alloc);");
        break;

        case COMPE:
            comment("comparing (==)");
            code("cmp1 = ($ObjectBase*) SM.pop();");
            code("cmp2 = ($ObjectBase*) SM.pop();");
            code("tmp_alloc = new $Integer(*cmp1.compareTo(*cmp2) == 0);");
            code("HEAP.push(&tmp_alloc);");
            code("SM.push(&tmp_alloc);");
        break;

        case COMPNE:
            comment("comparing (!=)");
            code("cmp1 = ($ObjectBase*) SM.pop();");
            code("cmp2 = ($ObjectBase*) SM.pop();");
            code("tmp_alloc = new $Integer(*cmp1.compareTo(*cmp2) != 0);");
            code("HEAP.push(&tmp_alloc);");
            code("SM.push(&tmp_alloc);");
        break;

        default:
            comment("compilation error: argument mismatch in \
                VirtualMachine::emit(int)");
        break;
    }
}

void
VirtualMachine::emit (int instr, gcstring* arg)
{
    gcstring str = arg->c_str();
    switch (instr) {

        // arg: the name of the label to jump to
        // e.g. goto __L__16;
        case GOTO:
            comment("jumping to label " + str);
            code("goto " + str + ";");
        break;

        // arg: gcstring*, the name of the label to jump to
        // e.g. cmp = (int*) SM.pop();
        //      if (*(cmp)==0) goto __L__16;
        case GTZ:
            comment("jumping to label " + str + " if top is 0");
            code("cmp = ($Integer*) SM.pop();");
            // Don't want to initialize a new $Integer(0) every time just for
            // this purpose; instead make a constant $ZERO = new $Integer(0).
            code("if (*(cmp).compareTo($ZERO)) { goto " + str + "; }");
        break;

        // arg: gcstring*, the data to push onto the stack.
        // if NULL, pushes the top of HEAP
        // e.g. SM.push(&currFrame.x);
        case PUSH:
            if (str == NULL) {
                comment("pushing first in HEAP onto SM");
                code("SM.push(HEAP[HEAP.size()-1]);");
            } else {
                comment("pushing " + str + " onto SM");
                code("SM.push(&(" + str + "));");
            }
        break;

        // arg: gcstring*, the creation of a new object
        // e.g. tmp_alloc = new $Integer(5);
        //      HEAP.push(&tmp_alloc);
        case ALLOC:
            comment("allocating memory for: " + str);
            code("tmp_alloc = " + str + ";");
            code("HEAP.push(&tmp_alloc);");
        break;

        default:
            comment("compilation error: argument mismatch in \
                VirtualMachine::emit(int, gcstring)");
        break;
    }
}

void
VirtualMachine::emit (int instr, gcstring* arg, int arity)
{
    gcstring str = arg->c_str();
    gcstring argliststr = "";
    gcstring argstr;

    switch (instr) {

        // arg: gcstring*, the name of the native function
        // arity: int, the number of params the native function takes
        case NATIVE:
            for (int i = 0; i < arity; i++) {
                argstr = "tmp_arg" + tostr(i);
                code(argstr + " = SM.pop();");
                if (i == arity-1) {
                    argliststr += argstr;
                } else {
                    argliststr += (argstr + ",");
                }
            }
            code("SM.push(" + str + "(" + argliststr + "));");
        break;

        default:
            comment("compilation error: argument mismatch in \
                VirtualMachine::emit(int, gcstring, int)");
        break;
    }
}

void
VirtualMachine::emitPrologue () 
{
    code("tmp_frame = new Frame;");
    code("tmp_frame.sl = tmp_slink;");
    code("currFrame = tmp_frame;");
    code("STACK.push(&tmp_frame);");
}

void
VirtualMachine::emitEpilogue () 
{
    code("delete STACK.pop();");
    code("currFrame = STACK[STACK.size() - 1];");
    code("goto *(currFrame.return_addr);");
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

gcstring
VirtualMachine::tostr (int val) {
    stringstream sts;
    sts << val;
    return gcstring(sts.str());
}
