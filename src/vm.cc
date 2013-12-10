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
static const int POP = 4;
static const int MOVE = 5;
static const int ALLOC = 6;
static const int NATIVE = 7;
static const int SETSL = 8;
static const int SETLBL = 9;

VirtualMachine::VirtualMachine (ostream& _out)
    : out(_out)
{
}

void
VirtualMachine::emit (const int& instr)
{
    newline();
    switch (instr) {


        case POP:
            comment("popping first in SM");
            code("SM.pop_back();");
            break;

        case PUSH:
            comment("pushing first in HEAP onto SM");
            code("SM.push_back( &HEAP[HEAP.size()-1] );");
            break;

        case MOVE:
            comment("moving second in stack to first in stack");
            code("dst = SM.back();");
            code("SM.pop_back();");
            code("src = SM.back();");
            code("SM.pop_back();");
            code("*dst = *src;");
            code("SM.push_back(dst);");
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
    gcstring rlabel;

    newline();
    switch (instr) {

        case GOTO:
            comment("jumping to label " + arg);
            code("goto " + arg + ";");
            break;

        case GTZ:
            comment("jumping to label " + arg + " if top is 0");
            code("cmp = (int_0$*) SM.back();");
            code("SM.pop_back();");
            // Don't want to initialize a new int_0$(0) every time just for
            // this purpose; instead make a constant __ZERO__ = new int_0$(0).
            code("if ((*cmp).compareTo(__ZERO__)) { goto " + arg + "; }");
            break;

        case PUSH:
            comment("pushing " + arg + " onto SM");
            code("SM.push_back( &" + arg + " );");
            break;

        case CALL:
            comment("calling function");
            rlabel = newLabel("R");
            code("call = (FuncDesc*) (*SM.back());");
            code("SM.pop_back();");
            code("cf->ra = &&" + rlabel + ";");
            code("static_link = call->sl;");
            code("goto " + asLabel(arg) + ";");
            newline();
            code(rlabel + ":", 0);
            break;

        case ALLOC:
            comment("allocating memory for: " + arg);
            code("tmp_alloc = " + arg + ";");
            code("HEAP.push_back(tmp_alloc);");
            break;

        case SETSL:
            comment("setting up static link for FuncDesc");
            code("((FuncDesc*)(*SM[SM.size() - 1]))->sl = " + arg + ";");
            break;

        case SETLBL:
            comment("setting up label for FuncDesc");
            code("((FuncDesc*)(*SM[SM.size() - 1]))->label = &&" +
                asLabel(arg) + ";");
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
    switch (instr) {

        case NATIVE:
            comment("calling " + arg1 + " (" + tostr(arg2) + " params)");
            code("tmp_res = " + arg1 + "(");
            for (int i = 1; i <= arg2; i++) {
                if (i != arg2) {
                    code("*SM[SM.size()-" + tostr(i) + "],", 8);
                } else {
                    code("*SM[SM.size()-" + tostr(i) + "]);", 8);
                }
            }
            for (int _ = 0; _ < arg2; _++) {
                code("SM.pop_back();");
            }
            code("SM.push_back( &tmp_res );");
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
VirtualMachine::newLabel (gcstring id)
{
    numLabels++;
    return VMLabel(asLabel(id) + tostr(numLabels));
}

VMLabel
VirtualMachine::asLabel (gcstring s)
{
    return VMLabel("__" + s + "__");
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

    newline(2);
    emit(GOTO, asLabel("START"));
}

void
VirtualMachine::emitMainEpilogue ()
{
    newline(2);
    comment("runtime epilogue: deleting objects stored on heap");
    code("for (int i = 0; i < HEAP.size(); i++) {");
    code("delete (($Object*) HEAP[i]);", 8);
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
    comment("function def for foo(a,b)");
    VMLabel lbl = asLabel("foo_0$");
    placeLabel(lbl);
    emitDefPrologue("foo_0$");
    emit(PUSH, "((foo_0$*) cf->locals)->a");
    emit(MOVE);
    emit(POP);
    emit(PUSH, "((foo_0$*) cf->locals)->b");
    emit(MOVE);
    emit(POP);
    emit(PUSH, "((foo_0$*) cf->locals)->a");
    emit(PUSH, "((foo_0$*) cf->locals)->b");
    emit(NATIVE, "__add__int__", 2);
    emitDefEpilogue("foo_0$");

    newline(2);
    VMLabel startLbl = asLabel("START");
    placeLabel(startLbl);
    newline();
    comment("x = 5");
    emit(ALLOC, "new int_0$(5)");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->x");
    emit(MOVE);
    emit(POP);

    newline(2);
    comment("y = x + 3");
    emit(ALLOC, "new int_0$(3)");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->x");
    emit(NATIVE, "__add__int__", 2);
    emit(PUSH, "((__main__*) cf->locals)->y");
    emit(MOVE);
    emit(POP);


    newline(2);
    comment("def foo(a, b):");
    comment("    return a + b");
    emit(ALLOC, "new FuncDesc;");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->foo_0$");
    emit(MOVE);
    emit(SETLBL, "foo_0$");
    emit(POP);

    newline(2);
    comment("z = foo(x, y)");
    emit(PUSH, "((__main__*) cf->locals)->y");
    emit(PUSH, "((__main__*) cf->locals)->x");
    emit(ALLOC, "new FuncDesc( ((FuncDesc*)((__main__*) cf->locals)->foo_0$) )");
    emit(PUSH);
    emit(SETSL, "cf");
    emit(CALL, "foo_0$");
    emit(PUSH, "((__main__*) cf->locals)->z");
    emit(MOVE);
    emit(POP);
}
