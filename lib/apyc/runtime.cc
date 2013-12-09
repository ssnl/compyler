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
