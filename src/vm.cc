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
// static const int COMPL = 6;
// static const int COMPG = 7;
// static const int COMPLE = 8;
// static const int COMPGE = 9;
// static const int COMPE = 10;
// static const int COMPNE = 11;
static const int NATIVE = 6;
static const int SETUP_FUNCTION = 7;

static gcstring HEAP_TOP = gcstring("");

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
VirtualMachine::emit (const int& instr)
{
    newline();
    gcstring s1, s2, rlabel;
    switch (instr) {

        // e.g. call = (FuncDesc*) SM.pop();
        //      cf.return_addr = __R__15;
        //      tmp_slink = call.frame;
        //      goto **(call.label);
        //  __R__15:
        case CALL:
            numRetLabels++;
            comment("calling function");
            rlabel = "__R__" + tostr(numRetLabels);
            code("call = (FuncDesc*) SM.pop();");
            code("cf.return_addr = " + rlabel);
            code("tmp_slink = call.frame;");
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

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int)"));
        break;
    }
}

void
VirtualMachine::emit (const int& instr, gcstring arg)
{
    newline();
    switch (instr) {

        // arg: the name of the label to jump to
        // e.g. goto __L__16;
        case GOTO:
            comment("jumping to label " + arg);
            code("goto " + arg + ";");
        break;

        // arg: gcstring, the name of the label to jump to
        // e.g. cmp = (int*) SM.pop();
        //      if (*(cmp)==0) goto __L__16;
        case GTZ:
            comment("jumping to label " + arg + " if top is 0");
            code("cmp = ($Integer*) SM.pop();");
            // Don't want to initialize a new $Integer(0) every time just for
            // this purpose; instead make a constant __ZERO__ = new $Integer(0).
            code("if (*(cmp).compareTo(__ZERO__)) { goto " + arg + "; }");
        break;

        // arg: gcstring, the data to push onto the stack.
        // if NULL, pushes the top of HEAP
        // e.g. SM.push(&cf.x);
        case PUSH:
            if (arg.length()) {
                comment("pushing " + arg + " onto SM");
                code("SM.push(&(" + arg + "));");
            } else {
                comment("pushing first in HEAP onto SM");
                code("SM.push(HEAP[HEAP.size()-1]);");
            }
        break;

        // arg: gcstring, the creation of a new object
        // e.g. tmp_alloc = new $Integer(5);
        //      HEAP.push(&tmp_alloc);
        case ALLOC:
            comment("allocating memory for: " + arg);
            code("tmp_alloc = " + arg + ";");
            code("HEAP.push(&tmp_alloc);");
        break;

        case SETUP_FUNCTION:
            comment("setting up static link for FuncDesc");
            code("((FuncDesc*)SM[SM.size() - 1])->sl = " + arg + ";");
        break;

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int, gcstring)"));
        break;
    }
}

void
VirtualMachine::emit (const int& instr, gcstring arg, int arity)
{
    newline();
    gcstring argliststr = "";
    gcstring argstr;

    switch (instr) {

        // arg: gcstring*, the name of the native function
        // arity: int, the number of params the native function takes
        case NATIVE:
            comment("calling " + arg + " (" + tostr(arity) + " params)");
            for (int i = 0; i < arity; i++) {
                argstr = "tmp_arg" + tostr(i);
                code(argstr + " = SM.pop();");
                if (i == arity-1) {
                    argliststr += argstr;
                } else {
                    argliststr += (argstr + ", ");
                }
            }
            code("SM.push(" + arg + "(" + argliststr + "));");
        break;

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int, gcstring, int)"));
        break;
    }
}

void
VirtualMachine::emitPrologue () 
{
    newline();
    comment(" ~~~ function prologue ~~~ ");
    code("tmp_frame = new Frame;");
    code("tmp_frame.sl = tmp_slink;");
    code("cf = tmp_frame;");
    code("STACK.push(&tmp_frame);");
}

void
VirtualMachine::emitEpilogue () 
{
    newline();
    comment(" ~~~ function epilogue ~~~ ");
    code("delete STACK.pop();");
    code("cf = STACK[STACK.size() - 1];");
    code("goto *(cf.return_addr);");
}

VMLabel
VirtualMachine::newLabel () 
{
    numLabels++;
    return VMLabel("__L__" + tostr(numLabels));
}

void
VirtualMachine::placeLabel (VMLabel label) 
{
    code(label + ":", 0);
}

void
VirtualMachine::emitRuntime ()
{
    code("#include <runtime.h>", 0);
    newline(2);
    code(gcstring("int main (int argc, char *argv[]) {"), 0);
    // main body begins here:
    __test_codegen();
    code("}", 0);
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
VirtualMachine::newline (int num)
{
    for (int i = 0; i < num; i++) {
        code("", 0);
    }
}

void
VirtualMachine::code (gcstring s, int indent)
{
    string indentstr = "";
    for (int i = 0; i < indent; i++) {
        indentstr += " ";
    }
    out << indentstr << s << endl;
}

gcstring
VirtualMachine::tostr (int val)
{
    stringstream sts;
    sts << val;
    return gcstring(sts.str());
}

void
VirtualMachine::__test_codegen()
{
    newline(2);
    comment("x = 5");
    emit(ALLOC, "new $Integer(5)");
    emit(PUSH, HEAP_TOP);
    emit(PUSH, "cf.locals.x");
    emit(MOVE);

    newline(2);
    comment("y = x + 3");
    emit(PUSH, "cf.locals.x");
    emit(ALLOC, "new $Integer(3)");
    emit(PUSH, HEAP_TOP);
    emit(NATIVE, "add_int", 2);
    emit(PUSH, "cf.locals.y");
    emit(MOVE);

    newline(2);
    comment("def foo(a, b):");
    comment("    return a + b");
    comment("z = foo(x, y)");
    emit(PUSH, "cf.locals.x");
    emit(PUSH, "cf.locals.y");
    emit(PUSH, "cf.locals.foo"); // Yea, I don't know about this
    emit(SETUP_FUNCTION, "cf");
    emit(CALL);
    emit(PUSH, "cf.locals.z");
    emit(MOVE);
    newline();
    comment("function def for foo(a,b)");
    VMLabel foo = newLabel();
    placeLabel(foo);
    emitPrologue();
    emit(PUSH, "cf.locals.a");
    emit(MOVE);
    emit(PUSH, "cf.locals.b");
    emit(MOVE);
    emit(PUSH, "cf.locals.a");
    emit(PUSH, "cf.locals.b");
    emit(NATIVE, "add_int", 2);
    emitEpilogue();
}
