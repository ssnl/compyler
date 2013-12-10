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

        // e.g. call = (FuncDesc*) SM.back();
        //      SM.pop_back();
        //      cf->ra = __R__15;
        //      static_link = call.frame;
        //      goto **(call.label);
        //  __R__15:
        case CALL:
            numRetLabels++;
            comment("calling function");
            rlabel = "__R__" + tostr(numRetLabels);
            code("call = (FuncDesc*) SM.back();");
            code("SM.pop_back();");
            code("cf->ra = &&" + rlabel + ";");
            code("static_link = call->sl;");
            code("goto *(call->label);");
            code(rlabel + ":", 0);
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
        // e.g. cmp = (int*) SM.back();
        //      SM.pop_back();
        //      if (*(cmp)==0) goto __L__16;
        case GTZ:
            comment("jumping to label " + arg + " if top is 0");
            code("cmp = (int_0$*) SM.back();");
            code("SM.pop_back();");
            // Don't want to initialize a new int_0$(0) every time just for
            // this purpose; instead make a constant __ZERO__ = new int_0$(0).
            code("if ((*cmp).compareTo(__ZERO__)) { goto " + arg + "; }");
            break;

        // arg: gcstring, the data to push onto the stack.
        // if NULL, pushes the top of HEAP
        // e.g. SM.push_back(((<Type> *) cf->locals)->x);
        case PUSH:
            comment("pushing " + arg + " onto SM");
            code("SM.push_back(&" + arg + ");");
            break;

        // arg: gcstring, the type of dst
        // e.g. dst = SM.back();
        //      SM.pop_back();
        //      src = SM.back();
        //      SM.pop_back();
        //      *((int_0$*)dst) = *((int_0$*)src);
        case MOVE:
            comment("moving second in stack to first in stack");
            code("dst = SM.back();");
            code("SM.pop_back();");
            code("src = SM.back();");
            code("SM.pop_back();");
            code("*((" + arg + "*)dst) = *((" + arg + "*)src);");
            break;

        // arg: gcstring, the creation of a new object
        // e.g. tmp_alloc = new int_0$(5);
        //      HEAP.push_back(tmp_alloc);
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
VirtualMachine::emit (const int& instr, gcstring arg1, int arg2)
{
    newline();
    gcstring argliststr = "";
    gcstring argstr;

    switch (instr) {

        // arg1: gcstring*, the name of the native function
        // arg2: int, the number of params the native function takes
        case NATIVE:
            comment("calling " + arg1 + " (" + tostr(arg2) + " params)");
            for (int i = 0; i < arg2; i++) {
                argstr = "tmp_arg" + tostr(i);
                code(argstr + " = SM.back();");
                code("SM.pop_back();");
                if (i == arg2-1) {
                    argliststr += argstr;
                } else {
                    argliststr += (argstr + ", ");
                }
            }
            code("SM.push_back(" + arg1 + "(" + argliststr + "));");
            break;

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int, gcstring, int)"));
            break;
    }
}

void
VirtualMachine::emitDefPrologue (gcstring name)
{
    newline();
    comment("function prologue for " + name);
    code("tmp_frame = new Frame;");
    code("tmp_frame->sl = static_link;");
    code("tmp_frame->locals = new " + name + ";");
    code("cf = tmp_frame;");
    code("STACK.push_back(tmp_frame);");
}

void
VirtualMachine::emitDefEpilogue (gcstring name)
{
    newline();
    comment("emitting function epilogue for " + name);
    code("tmp_frame = STACK.back();");
    code("STACK.pop_back();");
    code("delete ((" + name + "*) tmp_frame->locals);");
    code("delete tmp_frame;");
    code("cf = STACK[STACK.size() - 1];");
    code("goto *(cf->ra);");
}

VMLabel
VirtualMachine::newLabel ()
{
    numLabels++;
    return VMLabel("__L__" + tostr(numLabels));
}

VMLabel
VirtualMachine::newLabel (gcstring s)
{
    return VMLabel(s);
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
    comment("runtime prologue: set up __main__ frame");
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
    VMLabel exitLabel = newLabel("__EXIT__");
    placeLabel(exitLabel);
    code("for (int i = 0; i < HEAP.size(); i++) {");
    code("// delete HEAP[i];", 8); // TODO cast to base object ptr
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
    stringstream ss;
    ss << val;
    return gcstring(ss.str());
}

void
VirtualMachine::__test_codegen()
{
    newline(2);
    comment("x = 5");
    emit(ALLOC, "new int_0$(5)");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->x");
    emit(MOVE, "int_0$");

    newline(2);
    comment("y = x + 3");
    emit(ALLOC, "new int_0$(3)");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->x");
    emit(NATIVE, "__add__int__", 2);
    emit(PUSH, "((__main__*) cf->locals)->y");
    emit(MOVE, "int_0$");

    newline(2);
    comment("def foo(a, b):");
    comment("    return a + b");
    comment("z = foo(x, y)");
    emit(PUSH, "((__main__*) cf->locals)->y");
    emit(PUSH, "((__main__*) cf->locals)->x");
    emit(ALLOC, "new FuncDesc(((__main__*) cf->locals)->foo_0$)");
    emit(PUSH);
    emit(SETSL, "cf");
    emit(CALL);
    emit(PUSH, "((__main__*) cf->locals)->z");
    emit(MOVE, "int_0$");
    emit(GOTO, "__EXIT__");
    newline();
    comment("function def for foo(a,b)");
    VMLabel foo = newLabel();
    placeLabel(foo);
    emitDefPrologue("foo_0$");
    emit(PUSH, "((foo_0$*) cf->locals)->a");
    emit(MOVE, "int_0$");
    emit(PUSH, "((foo_0$*) cf->locals)->b");
    emit(MOVE, "int_0$");
    emit(PUSH, "((foo_0$*) cf->locals)->a");
    emit(PUSH, "((foo_0$*) cf->locals)->b");
    emit(NATIVE, "__add__int__", 2);
    emitDefEpilogue("foo_0$");
}
