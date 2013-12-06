/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library Headers */

/* Authors:  YOUR NAMES HERE */

#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <cstdlib>
#include <iostream>
#include <vector>

// To use pow()
#include <math.h>

using namespace std;

/* Runtime Data Structures */

/** A label represents the address of a label that can be used to goto the
 *  label at runtime. */
typedef void* Label;

/** A stack frame struct that refers to a stack frame on the stack. Locals points
 *  to a structure containing all the local variables in the frame during
 *  runtime. */
typedef struct Frame {
    Frame* sl;
    void* locals;
} Frame;

/** A call description struct that refers to a call descriptor. Contains the
 *  static link for the call as well as the label to jump to. */
typedef struct {
    Frame* sl;
    Label label;
} FuncDesc;

extern const vector<Frame> STACK;
extern const vector<void*> HEAP;
extern const vector<void*> SM;
extern const Frame cf;

// Type int and misc

void __donotcall__(void* x);

int __None__();

bool __truth__(bool x);

bool __not__(bool x);

// __xrange__

// __len__range__

int __add__int__(int x, int y);

int __sub__int__(int x, int y);

int __mul__int__(int x, int y);

int __floordiv__int__(int x, int y);

int __mod__int__(int x, int y);

int __pow__int__(int x, int y);

int __neg__int__(int x);

int __pos__int__(int x);

bool __lt__int__(int x, int y);

bool __gt__int__(int x, int y);

bool __le__int__(int x, int y);

bool __ge__int__(int x, int y);

bool __eq__int__(int x, int y);

bool __ne__int__(int x, int y);

int __toint__str__(string x);


// Type string

#endif
