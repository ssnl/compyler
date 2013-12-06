/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library */

/* Authors:  YOUR NAMES HERE */

#include "runtime.h"

using namespace std;

// Stores frames during runtime
const vector<Frame> STACK;
// Stores references to objects allocated during runtime
const vector<void*> HEAP;
// Our runtime stack machine
const vector<void*> SM;

// Stores the current environment (frame) of execution
Frame cf;
// Stores the static link of a called function
Frame tmp_slink;
// Stores newly created frame when calling function
Frame tmp_frame;
// Stores function pointer when popped from SM
FuncDesc* call;

// Stores assignment destination in "dst = src"
void* dst;
// Stores assignment source in "dst = src"
void* src;
// Stores temp reference to allocated object
void* tmp_alloc;
// Stores arguments of native calls
void* tmp_arg0, tmp_arg1, tmp_arg2, tmp_arg3;

// Stores the constant Integer value of 0
$Integer __ZERO__ = new $Integer(0);

void __donotcall__(void* x) {
    throw "Call to unimplemented function.";
}

int __None__() {
    return 0;
}

bool __truth__(bool x) {
    return x;
}

bool __not__(bool x) {
    return !x;
}

int __add__int__(int x, int y){
    return x + y;
}

int __sub__int__(int x, int y){
    return x - y;
}

int __mul__int__(int x, int y){
    return x * y;
}

int __floordiv__int__(int x, int y){
    return x / y;
}

int __mod__int__(int x, int y) {
    return x % y;
}

int __pow__int__(int x, int y) {
    return (int) pow(x, y);
}

int __neg__int__(int x) {
    return -x;
}

int __pos__int__(int x) {
    return x;
}

bool __lt__int__(int x, int y) { 
    return x < y;
}

bool __gt__int__(int x, int y) { 
    return x > y;
}

bool __le__int__(int x, int y) { 
    return x <= y;
}

bool __ge__int__(int x, int y) { 
    return x >= y;
}

bool __eq__int__(int x, int y) { 
    return x == y;
}

bool __ne__int__(int x, int y) { 
    return x != y;
}

int __toint__str__(string x) {
    return atoi(x.c_str());
}





// For testing if the runtime rotines work correctly.
int main()
{
    int failures = 0;
    bool success;
    cout << "Testing runtime routines for int and miscellaneous:" << endl;
    cout << "    __donotcall___:  ";
    try {
        void* x = 0;
        __donotcall__(x);
        cout << "failed" << endl;
        failures++;
    } catch (...) {
        cout << "passes" << endl;
    }

    cout << "    __truth__:  ";
    success = true;
    success = (__truth__(true)) ? success : false;
    success = (__truth__(false) == false) ? success : false;
    success = (__truth__(1)) ? success : false;
    success = (__truth__(0) == false) ? success : false;
    success = (__truth__("Hi")) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __not__:  ";
    success = true;
    success = (__not__(true) == false) ? success : false;
    success = (__not__(false)) ? success : false;
    success = (__not__(1) == false) ? success : false;
    success = (__not__(0)) ? success : false;
    success = (__not__("Hi") == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __floordiv__int__:  ";
    success = true;
    success = (__floordiv__int__(5, 2) == 2) ? success : false;
    success = (__floordiv__int__(10, 2) == 5) ? success : false;
    success = (__floordiv__int__(11, 3) == 3) ? success : false;
    success = (__floordiv__int__(15, 9) == 1) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __toint__str__:  ";
    success = true;
    success = (__toint__str__("125") == 125) ? success : false;
    success = (__toint__str__("0") == 0) ? success : false;
    success = (__toint__str__("10") == 10) ? success : false;
    success = (__toint__str__("895629") == 895629) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    if (failures == 0)
        cout << "\nAll tests passed, HORAY" << endl;
    else
        cout << "\n" << failures << " tests failed, BOO" << endl;

    return 0;
}


