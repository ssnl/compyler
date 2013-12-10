/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library Headers */

/* Authors:  YOUR NAMES HERE */

#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

// To use pow()
#include <math.h>

using namespace std;


class bool_0$;
class int_0$;
class str_0$;

/* Runtime Data Structures */

/** A label represents the address of a label that can be used to goto the
 *  label at runtime. */
typedef void* Label;

/** A stack frame struct that refers to a stack frame on the stack. Locals points
 *  to a structure containing all the local variables in the frame during
 *  runtime. */
typedef struct Frame {
    Label ra;
    Frame* sl;
    void* locals;
} Frame;
// typedef struct {
//     Frame* sl;
//     Label label;
// } FuncDesc;

/** The base class for all primitive and user-defined classes in this dialect.*/
class $Object {
public:
    $Object () {}

    /** Return a string representation of THIS.*/
    virtual string toString();

    /** Return a boolean value that represents THIS */
    virtual bool asBool() {return true;}

};

/** A call description struct that refers to a call descriptor. Contains the
 *  static link for the call as well as the label to jump to. */
class FuncDesc: public $Object {
public:
    Frame* sl;
    Label label;

    FuncDesc () {
        sl = NULL;
        label = NULL;
    }

    FuncDesc (FuncDesc* fd) {
        sl = fd->sl;
        label = fd->label;
    }

    string toString() { return string("<function>"); };
    bool asBool() {return true;}
};

/** The wrapper class for primitive type bool.*/
class bool_0$: public $Object {
protected:
    bool value;
public:
    bool_0$ () {value = false;}

    bool_0$ (bool val) {value = val;}

    bool getValue() {return value;}

    void setValue(bool val) {value = val;}

    /** Boolean addition */
    bool_0$* operator+ (bool_0$ y);

    /** Boolean subtraction */
    bool_0$* operator- (bool_0$ y);

    /** Boolean multiplication */
    bool_0$* operator* (bool_0$ y);

    /** Boolean division */
    bool_0$* operator/ (bool_0$ y);

    /** Boolean modulus */
    bool_0$* operator% (bool_0$ y);

    bool_0$* operator- ();

    /** Negation */
    bool_0$* operator! ();

    /** Comparison */

    bool_0$* operator< (bool_0$ y);

    bool_0$* operator> (bool_0$ y);

    bool_0$* operator<= (bool_0$ y);

    bool_0$* operator>= (bool_0$ y);

    bool_0$* operator== (bool_0$ y);

    bool_0$* operator!= (bool_0$ y);

    string toString();

    bool asBool() {return value;}
};


/** The wrapper class for primitive type int.*/
class int_0$: public $Object {
protected:
    int value;
public:
    int_0$ () {value = 0;}

    int_0$ (int val) {value = val;}

    int getValue() {return value;}

    void setValue(int val) {value = val;}

    /** Integer addition */
    int_0$* operator+ (int_0$ y);

    /** Integer subtraction */
    int_0$* operator- (int_0$ y);

    /** Integer multiplication */
    int_0$* operator* (int_0$ y);

    /** Return a str wrapper that is Y repeated THIS times */
    str_0$* operator* (str_0$ y);

    /** Integer division */
    int_0$* operator/ (int_0$ y);

    /** Integer modulus */
    int_0$* operator% (int_0$ y);

    /** Negation */
    int_0$* operator- ();

    /** Comparison */

    bool_0$* operator< (int_0$ y);

    bool_0$* operator> (int_0$ y);

    bool_0$* operator<= (int_0$ y);

    bool_0$* operator>= (int_0$ y);

    bool_0$* operator== (int_0$ y);

    bool_0$* operator!= (int_0$ y);

    string toString();

    bool asBool() {return (value != 0) ? true : false;}
};

/** The wrapper class for primitive type str.*/
class str_0$: public $Object {
protected:
    string value;
public:
    str_0$ () {value = "";}

    str_0$ (string val) {value = val;}

    string getValue() {return value;}

    void setValue(string val) {value = val;}

    /** String addition */
    str_0$* operator+ (str_0$ y);

    /** Return a str wrapper that is THIS repeated Y times */
    str_0$* operator* (int_0$ y);

    /** Comparison */

    bool_0$* operator< (str_0$ y);

    bool_0$* operator> (str_0$ y);

    bool_0$* operator<= (str_0$ y);

    bool_0$* operator>= (str_0$ y);

    bool_0$* operator== (str_0$ y);

    bool_0$* operator!= (str_0$ y);

    string toString() {return value;}

    bool asBool() {return ((value != "") ? true : false);}
};


extern vector<Frame*> STACK;
extern vector<$Object*> HEAP;
extern vector<$Object**> SM;

extern Frame* cf;
extern Frame* static_link;
extern Frame* tmp_frame;
extern FuncDesc* call;
extern $Object** dst;
extern $Object** src;

extern $Object* tmp_alloc;
extern $Object* tmp_res;

extern int_0$* __ZERO__;


extern bool_0$ $bool_0$;
extern int_0$ $int_0$;
extern str_0$ $str_0$;


void __donotcall__(void* x);

int_0$* __None__();


// type bool
bool_0$* __truth__(void* x);

bool_0$* __not__(void* x);

// __xrange__

// __len__range__

int_0$* __add__int__(void* x, void* y);

int_0$* __sub__int__(void* x, void* y);

int_0$* __mul__int__(void* x, void* y);

int_0$* __floordiv__int__(void* x, void* y);

int_0$* __mod__int__(void* x, void* y);

int_0$* __pow__int__(void* x, void* y);

int_0$* __neg__int__(void* x);

int_0$* __pos__int__(void* x);

bool_0$* __lt__int__(void* x, void* y);

bool_0$* __gt__int__(void* x, void* y);

bool_0$* __le__int__(void* x, void* y);

bool_0$* __ge__int__(void* x, void* y);

bool_0$* __eq__int__(void* x, void* y);

bool_0$* __ne__int__(void* x, void* y);

int_0$* __toint__str__(void* x);


// Type string

str_0$* __add__str__(void* x, void* y);

str_0$* __lmul__str__(void* x, void* y);

str_0$* __rmul__str__(void* x, void* y);

bool_0$* __lt__str__(void* x, void* y);

bool_0$* __gt__str__(void* x, void* y);

bool_0$* __le__str__(void* x, void* y);

bool_0$* __ge__str__(void* x, void* y);

bool_0$* __eq__str__(void* x, void* y);

bool_0$* __ne__str__(void* x, void* y);

str_0$* __getitem__str__(void* s, void* k);

str_0$* __getslice__str__(void* s, void* start, void* end);

int_0$* __len__str__(void* s);

str_0$* __tostr__(void* x);

#endif
