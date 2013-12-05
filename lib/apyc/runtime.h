/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library Headers */

/* Authors:  YOUR NAMES HERE */

#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/* Runtime Data Structures */

/** A label represents the address of a label that can be used to goto the
 *  label at runtime. */
typedef void* Label;

/** A stack frame struct that refers to a stack frame on the stack. Locals points
 *  to a structure containing all the local variables in the frame during
 *  runtime. */
typedef struct Frame {
    Frame* SL;
    Frame* DL;
    void* locals;
} Frame;

/** A call description struct that refers to a call descriptor. Contains the
 *  static link for the call as well as the label to jump to. */
typedef struct {
    Frame* SL;
    Label label;
} CallDesc;

extern const vector<Frame> STACK;
extern const vector<void*> HEAP;
extern const vector<void*> VM;
extern const Frame curr_frame;

#endif
