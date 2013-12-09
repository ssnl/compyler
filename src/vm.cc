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
static const int NATIVE = 6;
static const int SETSL = 7;

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

        // e.g. call = (FuncDesc*) SM.pop_back();
        //      cf->return_addr = __R__15;
        //      static_link = call.frame;
        //      goto **(call.label);
        //  __R__15:
        case CALL:
            numRetLabels++;
            comment("calling function");
            rlabel = "__R__" + tostr(numRetLabels);
            code("call = (FuncDesc*) SM.pop_back();");
            code("cf->return_addr = " + rlabel);
            code("static_link = call->frame;");
            code("goto *(call->label);");
            code(rlabel + ":", 0);
            break;

        // e.g. dst = SM.pop_back();
        //      src = SM.pop_back();
        //      *dst = *src;
        case MOVE:
            comment("moving second in stack to first in stack");;
            code("dst = SM.pop_back();");
            code("src = SM.pop_back();");
            code("*dst = *src;");
            break;

        case PUSH:
            comment("pushing first in HEAP onto SM");
            code("SM.push_back(HEAP[HEAP.size()-1]);");
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
        // e.g. cmp = (int*) SM.pop_back();
        //      if (*(cmp)==0) goto __L__16;
        case GTZ:
            comment("jumping to label " + arg + " if top is 0");
            code("cmp = ($Integer*) SM.pop_back();");
            // Don't want to initialize a new $Integer(0) every time just for
            // this purpose; instead make a constant __ZERO__ = new $Integer(0).
            code("if (*(cmp).compareTo(__ZERO__)) { goto " + arg + "; }");
            break;

        // arg: gcstring, the data to push onto the stack.
        // if NULL, pushes the top of HEAP
        // e.g. SM.push_back(((<Type> *) cf->locals)->x);
        case PUSH:
            comment("pushing " + arg + " onto SM");
            code("SM.push_back(" + arg + ");");
            break;

        // arg: gcstring, the creation of a new object
        // e.g. tmp_alloc = new $Integer(5);
        //      HEAP.push_back(&tmp_alloc);
        case ALLOC:
            comment("allocating memory for: " + arg);
            code("tmp_alloc = " + arg + ";");
            code("HEAP.push_back(tmp_alloc);");
            break;

        case SETSL:
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
                code(argstr + " = SM.pop_back();");
                if (i == arity-1) {
                    argliststr += argstr;
                } else {
                    argliststr += (argstr + ", ");
                }
            }
            code("SM.push_back(" + arg + "(" + argliststr + "));");
            break;

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int, gcstring, int)"));
            break;
    }
}

void
VirtualMachine::emitDefPrologue (const gcstring& name)
{
    newline();
    comment(" ~~~ function prologue ~~~ ");
    code("tmp_frame = new Frame;");
    code("tmp_frame->sl = static_link;");
    code("tmp_frame->locals = new " + name + ";");
    code("cf = tmp_frame;");
    code("STACK.push_back(tmp_frame);");
}

void
VirtualMachine::emitDefEpilogue ()
{
    newline();
    comment(" ~~~ function epilogue ~~~ ");
    code("tmp_frame = STACK.pop_back();");
    code("delete tmp_frame->locals;");
    code("delete tmp_frame;");
    code("cf = STACK[STACK.size() - 1];");
    code("goto *(cf->return_addr);");
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
    newline(2);
    code("int main (int argc, char *argv[]) {", 0);
    emitMainPrologue();
    // main body begins here:
    __test_codegen();
    emitMainEpilogue();
    code("}", 0);
}

void
VirtualMachine::emitMainPrologue ()
{
    newline();
    comment(" ~~~ main prologue ~~~ ");
    code("tmp_frame = new Frame;");
    code("tmp_frame->locals = new __main__;");
    code("cf = tmp_frame;");
    code("STACK.push_back(tmp_frame);");
}

void
VirtualMachine::emitMainEpilogue ()
{
    newline(2);
    comment("runtime epilogue: deleting objects stored on heap");
    code("for (int i = 0; i < HEAP.size(); i++) {");
    code("delete HEAP[i];", 8);
    code("}");
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
    emit(ALLOC, "new int_0$(5)");
    emit(PUSH);
    emit(PUSH, "((__main__ *) cf->locals)->x");
    emit(MOVE);

    newline(2);
    comment("y = x + 3");
    emit(ALLOC, "new int_0$(3)");
    emit(PUSH);
    emit(PUSH, "((__main__ *) cf->locals)->x");
    emit(NATIVE, "__add__int__", 2);
    emit(PUSH, "((__main__ *) cf->locals)->y");
    emit(MOVE);

    newline(2);
    comment("def foo(a, b):");
    comment("    return a + b");
    comment("z = foo(x, y)");
    emit(PUSH, "((__main__ *) cf->locals)->y");
    emit(PUSH, "((__main__ *) cf->locals)->x");
    emit(ALLOC, "new FuncDesc(((__main__ *) cf->locals)->foo)");
    emit(PUSH);
    emit(SETSL, "cf");
    emit(CALL);
    emit(PUSH, "(__main__ *) cf->locals)->z");
    emit(MOVE);
    newline();
    comment("function def for foo(a,b)");
    VMLabel foo = newLabel();
    placeLabel(foo);
    emitDefPrologue("foo_0$");
    emit(PUSH, "((foo_0$ *) cf->locals)->a");
    emit(MOVE);
    emit(PUSH, "((foo_0$ *) cf->locals)->b");
    emit(MOVE);
    emit(PUSH, "((foo_0$ *) cf->locals)->a");
    emit(PUSH, "((foo_0$ *) cf->locals)->b");
    emit(NATIVE, "__add__int__", 2);
    emitDefEpilogue();
}
