/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library */

/* Authors:  YOUR NAMES HERE */

#include "runtime.h"

using namespace std;

// Used to store frames during runtime
const vector<Frame> STACK;

// Used to store references to objects allocated during runtime
const vector<void*> HEAP;

// Our runtime stack machine
const vector<void*> SM;

// Used to store the current environment (frame) of execution
Frame currFrame;

// Used to store function pointer when popped from SM
FuncDesc* call;

// Used to store assignment destination in "dst = src"
void* dst;

// Used to store assignment source in "dst = src"
void* src;

// Used to store temp reference to allocated object
void* tmp_alloc;
