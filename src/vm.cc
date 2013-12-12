/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

/* virtualmachine.cc: Virtual stack machine. */

#include <string>
#include <iostream>
#include <sstream>
#include "apyc.h"

using namespace std;

static const bool DEBUG_OUT = false;

VirtualMachine::VirtualMachine (ostream& _out)
    : out(_out)
{
}

void
VirtualMachine::emit (const int& instr)
{
    gcstring rlabel;

    newline();
    switch (instr) {
        case POP:
            comment("popping top of SM");
            code("SM.pop_back();");
            break;

        case PUSH:
            comment("pushing top of HEAP onto SM");
            code("SM.push_back( HEAP[HEAP.size()-1] );");
            break;

        case FCALL:
            comment("calling function");
            rlabel = newLabel("R");
            code("call = (FuncDesc*) (SM.back()->get());");
            code("SM.pop_back();");
            code("cf->ra = &&" + rlabel + ";");
            code("static_link = call->sl;");
            code("goto *(call->label);");
            newline();
            code(rlabel + ":", 0);
            break;

        case MOVE:
            comment("moving second in stack to first in stack");
            code("dst = SM.back();");
            code("SM.pop_back();");
            code("src = SM.back();");
            code("SM.pop_back();");
            code("dst->set(src->get());");
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
            comment("jumping to " + arg);
            code("goto " + arg + ";");
            break;

        case GTZ:
            comment("jumping to " + arg + " if top is 0");
            code("cmp = ((int_0$*) SM.back()->get());");
            code("SM.pop_back();");
            // Don't want to initialize a new int_0$(0) every time just for
            // this purpose; instead make a constant __ZERO__ = new int_0$(0).
            code("if (cmp->getValue() == __ZERO__->getValue()) { goto " +
                arg + "; }");
            break;

        case PUSH:
            comment("pushing " + arg + " onto SM");
            code("SM.push_back( &" + arg + " );");
            break;

        case ALLOC:
            comment("allocating memory for: " + arg);
            code("tmp_alloc = new $Reference(" + arg + ");");
            code("HEAP.push_back(tmp_alloc);");
            break;

        case SETSL:
            comment("setting up static link for FuncDesc");
            code("((FuncDesc*)(SM[SM.size() - 1]->get()))->sl = " + arg + ";");
            break;

        case SETLBL:
            comment("setting up label for FuncDesc");
            code("((FuncDesc*)(SM[SM.size() - 1]->get()))->label = &&"
                + arg + ";");
            break;

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int, gcstring)"));
            break;
    }
}

void
VirtualMachine::emit (const int& instr, int arg)
{
    newline();
    switch (instr) {

        case EXPAND:
            comment("expanding tuple into " + tostr(arg) + " elements");
            code("tmp_tup = (tuple_0$*) SM.back()->get();");
            code("SM.pop_back();");
            code("for (int i = " + tostr(arg) + " - 1; i >= 0; i--) {");
            code("SM.push_back( tmp_tup->getItem(i) );", 8);
            code("}");
            break;

        case PRNT:
            comment("Printing to standard output");
            code("tmp_ss.str(\"\");");
            code("if (" + tostr(arg) + " > 0) {");
            code("tmp_ss << SM.back()->get()->toString();", 8);
            code("SM.pop_back();", 8);
            code("}");
            code("for (int i = 1; i < " + tostr(arg) + "; i++) {");
            code("tmp_ss << \" \" << SM.back()->get()->toString();", 8);
            code("SM.pop_back();", 8);
            code("}");
            code("cout << tmp_ss.str();");
            break;

        case PRNTFILE:
            comment("Printing to file");
            code("tmp_file = (file_0*) *(SM.back()->get());");
            code("SM.pop_back();");
            code("tmp_ss.str(\"\");");
            code("if (" + tostr(arg) + " > 0) {");
            code("tmp_ss << SM.back()->get()->toString();", 8);
            code("SM.pop_back();", 8);
            code("}");
            code("for (int i = 1; i < " + tostr(arg) + "; i++) {");
            code("tmp_ss << \" \" << SM.back()->get()->toString();", 8);
            code("SM.pop_back();", 8);
            code("}");
            code("fprintf(tmp_file->getValue(), tmp_ss.str().c_str());");
            break;

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int, int)"));
            break;

    }
}

void
VirtualMachine::emit (const int& instr, gcstring arg1, int arg2)
{
    newline();
    switch (instr) {

        case NTV:
            comment("calling " + arg1 + " (" + tostr(arg2) + " params)");
            code("tmp_res = " + arg1 + "(");
            for (int i = 1; i <= arg2; i++) {
                if (i != arg2) {
                    code("SM[SM.size()-" + tostr(i) + "],", 8);
                } else {
                    code("SM[SM.size()-" + tostr(i) + "]);", 8);
                }
            }
            for (int _ = 0; _ < arg2; _++) {
                code("SM.pop_back();");
            }
            code("SM.push_back( tmp_res );");
            break;

        default:
            comment("compilation error: argument mismatch in" +
                string("VirtualMachine::emit(int, gcstring, int)"));
            break;
    }
}

void
VirtualMachine::emit (const int& instr, gcstring arg1, gcstring arg2)
{
    newline();
    switch (instr) {

        case FIELD:
            comment("getting field " + arg2 + " for instance of type " + arg1);
            code("tmp_res = ((" + arg1 + "*)(*SM[SM.size() - 1]))->" + arg2);
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
    emitMainPrologue();
    // main body begins here:
    __test_codegen();
    emitMainEpilogue();
}

void
VirtualMachine::emitMainPrologue ()
{
    code("int main (int argc, char *argv[]) {", 0);
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
    if (DEBUG_OUT) {
       code("cout << \"Heap size: \" << HEAP.size() << endl;");
    }
    code("for (int i = 0; i < HEAP.size(); i++) {");
    code("HEAP[i]->clean();", 8);
    code("delete HEAP[i];", 8);
    code("}");
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
VirtualMachine::staticLinkStr (int depth1, int depth2)
{
    if (depth1 <= depth2) {
        stringstream res;
        res << "cf";
        for (int i = depth1; i < depth2; i++) {
            res << "->sl";
        }
        return res.str();
    } else {
        return "you dun goofed, depth1 > depth2";
    }
}

gcstring
VirtualMachine::fieldAccessStr (gcstring expr, gcstring field, gcstring acc)
{
    return expr + acc + field;
}

gcstring
VirtualMachine::typeCastStr (gcstring type, gcstring expr)
{
    return "((" + type + ") " + expr + ")";
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
    emit(GOTO, asLabel("START"));
    comment("function def for foo(a,b)");
    VMLabel lbl = asLabel("foo_0$");
    placeLabel(lbl);
    emitDefPrologue("foo_0$");
    emit(PUSH, "((foo_0$*) cf->locals)->a_0$");
    emit(MOVE);
    emit(POP);
    emit(PUSH, "((foo_0$*) cf->locals)->b_0$");
    emit(MOVE);
    emit(POP);
    emit(PUSH, "((foo_0$*) cf->locals)->a_0$");
    emit(PUSH, "((foo_0$*) cf->locals)->b_0$");
    emit(NTV, "__add__int__", 2);
    emitDefEpilogue("foo_0$");

    newline(2);
    VMLabel startLbl = asLabel("START");
    placeLabel(startLbl);
    newline();
    comment("x = 5");
    emit(ALLOC, "new int_0$(5)");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->x_0$");
    emit(MOVE);
    emit(POP);

    newline(2);
    comment("y = x + 3");
    emit(ALLOC, "new int_0$(3)");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->x_0$");
    emit(NTV, "__add__int__", 2);
    emit(PUSH, "((__main__*) cf->locals)->y_0$");
    emit(MOVE);
    emit(POP);

    newline(2);
    comment("def foo(a, b):");
    comment("    return a + b");
    emit(ALLOC, "new FuncDesc");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->foo_0$");
    emit(MOVE);
    emit(SETLBL, asLabel("foo_0$"));
    emit(POP);

    newline(2);
    comment("z = foo(x, y) + 5 + 5 + 5");
    emit(ALLOC, "new int_0$(5)");
    emit(PUSH);
    emit(ALLOC, "new int_0$(5)");
    emit(PUSH);
    emit(ALLOC, "new int_0$(5)");
    emit(PUSH);
    emit(PUSH, "((__main__*) cf->locals)->y_0$");
    emit(PUSH, "((__main__*) cf->locals)->x_0$");
    emit(ALLOC, "new FuncDesc( ((FuncDesc*)((__main__*) cf->locals)->foo_0$.get()) )");
    emit(PUSH);
    emit(SETSL, "cf");
    emit(FCALL);
    emit(NTV, "__add__int__", 2);
    emit(NTV, "__add__int__", 2);
    emit(NTV, "__add__int__", 2);
    emit(PUSH, "((__main__*) cf->locals)->z_0$");
    emit(MOVE);
    emit(POP);
}
