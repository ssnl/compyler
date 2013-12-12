/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library Headers */

/* Authors:  YOUR NAMES HERE */

#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdarg>
#include <map>
#include <stdio.h>

// To use pow()
#include <math.h>

using namespace std;

class $Object;
class bool_0$;
class int_0$;
class str_0$;
class range_0$;
class list_0$;
class tuple_0$;
class dict_0$;
class dict_int_0$;
class dict_str_0$;
class dict_bool_0$;
class file_0$;

class FuncDesc;

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
extern $Object* tmp_tup;

extern int_0$* __ZERO__;

/** The base class for all primitive and user-defined classes in this dialect.*/
class $Object {
public:
    $Object () {}

    /** Return a string representation of THIS.*/
    virtual string toString(bool contained=false);

    /** Return a boolean value that represents THIS. */
    virtual bool asBool() {return true;}

    /** Return the class name. Helper method for equals(). */
    virtual string className() {return "Object";}

    /** Check equality between THIS and OTHER. */
    virtual bool equals(void* other) {return this == other;}

    /** If applicable, return the size of THIS. */
    virtual int size() {return 0;}

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

    string toString(bool contained=false);

    string className() {return "bool";}

    bool equals(void* other);

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

    string toString(bool contained=false);

    string className() {return "int";}

    bool equals(void* other);

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

    str_0$* getSlice(int start, int end);

    string toString(bool contained=false);

    string className() {return "str";}

    bool equals(void* other);

    bool asBool() {return ((value != "") ? true : false);}

    int size();
};


/** The wrapper class for primitive type range.*/
class range_0$: public $Object {
protected:
    int start, end;
public:
    range_0$ () : start(0), end(0) {}

    range_0$ (int high) : start(0), end(high) {}

    range_0$ (int low, int high) : start(low), end(high) {}

    void setLow(int low) {start = low;}

    void setHigh(int high) {end = high;}

    int getLow() {return start;}

    int getHigh() {return end;}

    int size() { return end - start;}

    string toString(bool contained=false);

    string className() {return "range";}

    bool equals(void* other);

    bool asBool() {return ((start == 0 && end == 0) ? false : true);}
};

/** The wrapper class for primitive type list.*/
class list_0$: public $Object {
protected:
    vector<$Object*> value;
public:
    list_0$ () : value() {}

    vector<$Object*> getValue() {return value;}

    void push($Object* item) {value.push_back(item);}

    void setItem(int k, $Object* item) {value[k] = item;}

    $Object* getItem(int k);

    list_0$* getSlice(int L, int U);

    void clear() {value.clear();}

    string toString(bool contained=false);

    int size() {return value.size();}

    string className() {return "list";}

    bool equals(void* other);

    bool asBool() {return ((value.size() != 0) ? true : false);}

};

/** The wrapper class for primitive type tuple0.*/
class tuple_0$: public $Object {
protected:
    vector<$Object*> value;
    int tupleSize;
public:
    tuple_0$ () : tupleSize(0) {}

    tuple_0$ (int s) : tupleSize(s) {}

    void push($Object* item) {value.push_back(item);}

    $Object* getItem(int k) {return value[k];}

    int size() {return tupleSize;}

    string toString(bool contained=false);

    string className() {return "tuple";}

    bool equals(void* other);

    bool asBool() {return ((size() != 0) ? true : false);}
};

/** Base class wrapper for primitive type dict. */
class dict_0$: public $Object {
protected:
    map<int, $Object*> value;
public:
    dict_0$ () : value() {}

    virtual $Object* get(void* key) {return this;}

    virtual void set(void* key, $Object* item) {}

    virtual bool contains(void* key) {return false;}

    bool equals(void* other);

    string className() {return "dict";}

};

/** The wrapper class for primitive type dict with key type int.*/
class dict_int_0$: public dict_0$ {
protected:
    map<int, $Object*> value;
public:
    dict_int_0$ () : value() {}

    $Object* get(void* key);

    void set(void* key, $Object* item);

    bool contains(void* key);

    int size() {return value.size();}

    string toString(bool contained=false);

    bool asBool() {return (value.empty()? false : true);}
};

/** The wrapper class for primitive type dict with key type string.*/
class dict_str_0$: public dict_0$ {
protected:
    map<string, $Object*> value;
public:
    dict_str_0$ () : value() {}

    $Object* get(void* key);

    void set(void* key, $Object* item);

    bool contains(void* key);

    int size() {return value.size();}

    string toString(bool contained=false);

    bool asBool() {return (value.empty()? false : true);}
};

/** The wrapper class for primitive type dict with key type bool.*/
class dict_bool_0$: public dict_0$ {
protected:
    map<bool, $Object*> value;
public:
    dict_bool_0$ () : value() {}

    $Object* get(void* key);

    void set(void* key, $Object* item);

    bool contains(void* key);

    int size() {return value.size();}

    string toString(bool contained=false);

    bool asBool() {return (value.empty()? false : true);}
};

/** The wrapper class for primitive type file.*/
class file_0$: public $Object {
protected:
    FILE* value;
public:
    file_0$ () {}

    file_0$ (FILE* f) : value(f) {}

    FILE* getValue() {return value;}

    void close() {fclose(value);}

    int size() {return -1;}

    string toString();

    string className() {return "file";}

    bool asBool() {return true;}

    bool equals(void* other);
};

//extern bool_0$ $bool_0$;
extern int_0$ $int_0$;
//extern str_0$ $str_0$;
//extern range_0$ $range_0$;
//extern list_0$ $list_0$;
//extern tuple_0$ $tuple_0$;
//extern dict_0$ $dict_0$;
//extern file_0$ $file_0$;

// Standard input, output, and error
extern file_0$ STDIN, STDOUT, STDERR;

// Allocators for list_0$, tuple_0$, and dict_0$
tuple_0$* __tuple0__();

tuple_0$* __tuple1__(void* x);

tuple_0$* __tuple2__(void* x, void* y);

tuple_0$* __tuple3__(void* x, void* y, void* z);

list_0$* __list__empty__();

list_0$* __list__(void* count, void* x, ...);

dict_int_0$* __dict__empty__int__();

dict_str_0$* __dict__empty__str__();

dict_bool_0$* __dict__empty__bool__();

/** Allocator for dict. The x is not used, the key-value pairs should be
  * in the variable list.
  */
dict_int_0$* __dict__int__(void* count, ...);

dict_str_0$* __dict__str__(void* count, ...);

dict_bool_0$* __dict__bool__(void* count, ...);

// Miscellaneous routines

void __donotcall__(void* x);

int_0$* __None__();

bool_0$* __is__(void* x, void* y);

bool_0$* __isnot__(void* x, void* y);


// Type bool
bool_0$* __truth__(void* x);

bool_0$* __not__(void* x);

// Type range
range_0$* __xrange__(void* low, void* high);

int_0$* __len__range__(void* r);

// Type int
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

str_0$* __getslice__str__(void* s, void* start);

str_0$* __getslice__str__(void* s, void* start, void* end);

int_0$* __len__str__(void* s);

str_0$* __tostr__(void* x);


// Type list

$Object* __getitem__list__(void* S, void* k);

list_0$* __getslice__list__(void* S, void* L);

list_0$* __getslice__list__(void* S, void* L, void* U);

int_0$* __len__list__(void* S);

list_0$* __argv__();


// Type dict

$Object* __getitem__dict__int__(void* D, void* x);

$Object* __getitem__dict__bool__(void* D, void* x);

$Object* __getitem__dict__str__(void* D, void* x);

int_0$* __len__dict__(void* D);

bool_0$* __contains__dict__(void* x, void* D);

bool_0$* __notcontains__dict__(void* x, void* D);


// Type file

file_0$* __open1__(void* name);

file_0$* __open2__(void* name, void* mode);

void __close__(void* file);

str_0$* __readline__(void* file);

str_0$* __read__(void* file);

file_0$* __standard_file__(void* k);



#endif
