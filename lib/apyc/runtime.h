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

class $Reference;
class Frame;
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


extern vector<Frame*> STACK;
extern vector<$Reference*> HEAP;
extern vector<$Reference*> SM;

extern Frame* cf;
extern Frame* static_link;
extern Frame* tmp_frame;
extern FuncDesc* call;
extern $Reference* dst;
extern $Reference* src;

extern $Reference* tmp_alloc;
extern $Reference* tmp_res;
extern $Reference* tmp_cmp;
extern tuple_0$* tmp_tup;
extern file_0$* tmp_file;
extern stringstream tmp_ss;

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

    /** Return the Kth elementh. Should only be used for appropriate objects.
    */
    virtual $Reference* getElement(int k) {return NULL;}

    /** Check equality between THIS and OTHER. */
    virtual bool equals(void* other) {return this == other;}

    /** If applicable, return the size of THIS. */
    virtual int size() {return 0;}

    void incrCounter () { _counter += 1; }

    void decrCounter () { _counter -= 1; }

    int getCounter () { return _counter; }

private:

    int _counter;

};


/** A wrapper class that represents a reference to a $Object. */
class $Reference {
private:
    $Object* _obj;
public:
    $Reference () { _obj = NULL; }

    $Reference ($Object* obj) : _obj(obj) {
        _obj->incrCounter ();
    }

    void set ($Object* obj) {
        if (_obj != NULL)
            _obj->decrCounter ();
        _obj = obj;
        obj->incrCounter ();

    }

    $Object* get () { return _obj; }

    ~$Reference () {
        if (_obj != NULL) {
            _obj->decrCounter();
            if ( _obj->getCounter() == 0 )
                delete _obj;
        }
    }
};


/** A stack frame class that refers to a stack frame on the stack. Locals points
 *  to a structure containing all the local variables in the frame during
 *  runtime. */
class Frame: public $Object {
public:
    Label ra;
    Frame* sl;
    void* locals;
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
    $Reference* operator+ (bool_0$ y);

    /** Boolean subtraction */
    $Reference* operator- (bool_0$ y);

    /** Boolean multiplication */
    $Reference* operator* (bool_0$ y);

    /** Boolean division */
    $Reference* operator/ (bool_0$ y);

    /** Boolean modulus */
    $Reference* operator% (bool_0$ y);

    $Reference* operator- ();

    /** Negation */
    $Reference* operator! ();

    /** Comparison */

    $Reference* operator< (bool_0$ y);

    $Reference* operator> (bool_0$ y);

    $Reference* operator<= (bool_0$ y);

    $Reference* operator>= (bool_0$ y);

    $Reference* operator== (bool_0$ y);

    $Reference* operator!= (bool_0$ y);

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
    $Reference* operator+ (int_0$ y);

    /** Integer subtraction */
    $Reference* operator- (int_0$ y);

    /** Integer multiplication */
    $Reference* operator* (int_0$ y);

    /** Return a str wrapper that is Y repeated THIS times */
    $Reference* operator* (str_0$ y);

    /** Integer division */
    $Reference* operator/ (int_0$ y);

    /** Integer modulus */
    $Reference* operator% (int_0$ y);

    /** Negation */
    $Reference* operator- ();

    $Reference* operator+ ();

    /** Comparison */

    $Reference* operator< (int_0$ y);

    $Reference* operator> (int_0$ y);

    $Reference* operator<= (int_0$ y);

    $Reference* operator>= (int_0$ y);

    $Reference* operator== (int_0$ y);

    $Reference* operator!= (int_0$ y);

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

    $Reference* getElement(int k);

    /** String addition */
    $Reference* operator+ (str_0$ y);

    /** Return a str wrapper that is THIS repeated Y times */
    $Reference* operator* (int_0$ y);

    /** Comparison */

    $Reference* operator< (str_0$ y);

    $Reference* operator> (str_0$ y);

    $Reference* operator<= (str_0$ y);

    $Reference* operator>= (str_0$ y);

    $Reference* operator== (str_0$ y);

    $Reference* operator!= (str_0$ y);

    $Reference* getSlice(int start, int end);

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

    $Reference* getElement(int k);

    int size() { return end - start;}

    string toString(bool contained=false);

    string className() {return "range";}

    bool equals(void* other);

    bool asBool() {return ((start == 0 && end == 0) ? false : true);}
};

/** The wrapper class for primitive type list.*/
class list_0$: public $Object {
protected:
    vector<$Reference*> value;
public:
    list_0$ () : value() {}

    vector<$Reference*> getValue() {return value;}

    void push($Reference* item) {value.push_back(item);}

    void setItem(int k, $Reference* item) {value[k] = item;}

    $Reference* getItem(int k);

    $Reference* getSlice(int L, int U);

    $Reference* getElement(int k);

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
    vector<$Reference*> value;
    int tupleSize;
public:
    tuple_0$ () : tupleSize(0) {}

    tuple_0$ (int s) : tupleSize(s) {}

    void push($Reference* item) {value.push_back(item);}

    $Reference* getItem(int k) {return value[k];}

    int size() {return tupleSize;}

    string toString(bool contained=false);

    string className() {return "tuple";}

    bool equals(void* other);

    bool asBool() {return ((size() != 0) ? true : false);}
};

/** Base class wrapper for primitive type dict. */
class dict_0$: public $Object {
protected:
    map<int, $Reference*> value;
public:
    dict_0$ () : value() {}

    virtual $Reference* get(void* key);

    virtual void set(void* key, $Reference* item) {}

    virtual bool contains(void* key) {return false;}

    bool equals(void* other);

    string className() {return "dict";}

};

/** The wrapper class for primitive type dict with key type int.*/
class dict_int_0$: public dict_0$ {
protected:
    map<int, $Reference*> value;
public:
    dict_int_0$ () : value() {}

    $Reference* get(void* key);

    void set(void* key, $Reference* item);

    bool contains(void* key);

    int size() {return value.size();}

    string toString(bool contained=false);

    bool asBool() {return (value.empty()? false : true);}
};

/** The wrapper class for primitive type dict with key type string.*/
class dict_str_0$: public dict_0$ {
protected:
    map<string, $Reference*> value;
public:
    dict_str_0$ () : value() {}

    $Reference* get(void* key);

    void set(void* key, $Reference* item);

    bool contains(void* key);

    int size() {return value.size();}

    string toString(bool contained=false);

    bool asBool() {return (value.empty()? false : true);}
};

/** The wrapper class for primitive type dict with key type bool.*/
class dict_bool_0$: public dict_0$ {
protected:
    map<bool, $Reference*> value;
public:
    dict_bool_0$ () : value() {}

    $Reference* get(void* key);

    void set(void* key, $Reference* item);

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

extern bool_0$ $bool_0$;
extern int_0$ $int_0$;
extern str_0$ $str_0$;
extern range_0$ $range_0$;
extern list_0$ $list_0$;
extern tuple_0$ $tuple_0$;
extern dict_0$ $dict_0$;
extern file_0$ $file_0$;

// Standard input, output, and error
extern file_0$ $f1, $f2, $f3;
extern $Reference *STDIN, *STDOUT, *STDERR;

// Allocators for list_0$, tuple_0$, and dict_0$
$Reference* __tuple__();

$Reference* __tuple__($Reference* x);

$Reference* __tuple__($Reference* x, $Reference* y);

$Reference* __tuple__($Reference* x, $Reference* y, $Reference* z);

$Reference* __list__empty__();

$Reference* __list__($Reference* count, ...);

$Reference* __dict__empty__int__();

$Reference* __dict__empty__str__();

$Reference* __dict__empty__bool__();

$Reference* __dict__int__($Reference* count, ...);

$Reference* __dict__str__($Reference* count, ...);

$Reference* __dict__bool__($Reference* count, ...);


// Miscellaneous routines

void __donotcall__(void* x);

$Reference* __None__();

$Reference* __is__($Reference* x, $Reference* y);

$Reference* __isnot__($Reference* x, $Reference* y);

$Reference* __and__($Reference* x, $Reference* y);

$Reference* __or__($Reference* x, $Reference* y);

// Type bool
$Reference* __truth__($Reference* x);

$Reference* __not__($Reference* x);

// Type range
$Reference* __xrange__($Reference* low, $Reference* high);

$Reference* __len__range__($Reference* r);

// Type int
$Reference* __add__int__($Reference* x, $Reference* y);

$Reference* __sub__int__($Reference* x, $Reference* y);

$Reference* __mul__int__($Reference* x, $Reference* y);

$Reference* __floordiv__int__($Reference* x, $Reference* y);

$Reference* __mod__int__($Reference* x, $Reference* y);

$Reference* __pow__int__($Reference* x, $Reference* y);

$Reference* __neg__int__($Reference* x);

$Reference* __pos__int__($Reference* x);

$Reference* __lt__int__($Reference* x, $Reference* y);

$Reference* __gt__int__($Reference* x, $Reference* y);

$Reference* __le__int__($Reference* x, $Reference* y);

$Reference* __ge__int__($Reference* x, $Reference* y);

$Reference* __eq__int__($Reference* x, $Reference* y);

$Reference* __ne__int__($Reference* x, $Reference* y);

$Reference* __toint__str__($Reference* x);


// Type string

$Reference* __add__str__($Reference* x, $Reference* y);

$Reference* __lmul__str__($Reference* x, $Reference* y);

$Reference* __rmul__str__($Reference* x, $Reference* y);

$Reference* __lt__str__($Reference* x, $Reference* y);

$Reference* __gt__str__($Reference* x, $Reference* y);

$Reference* __le__str__($Reference* x, $Reference* y);

$Reference* __ge__str__($Reference* x, $Reference* y);

$Reference* __eq__str__($Reference* x, $Reference* y);

$Reference* __ne__str__($Reference* x, $Reference* y);

$Reference* __getitem__str__($Reference* s, $Reference* k);

$Reference* __getslice__str__($Reference* s, $Reference* start);

$Reference* __getslice__str__($Reference* s, $Reference* start, $Reference* end);

$Reference* __len__str__($Reference* s);

$Reference* __tostr__($Reference* x);


// Type list

$Reference* __getitem__list__($Reference* S, $Reference* k);

$Reference* __getslice__list__($Reference* S, $Reference* L);

$Reference* __getslice__list__($Reference* S, $Reference* L, $Reference* U);

$Reference* __len__list__($Reference* S);

$Reference* __argv__();


// Type dict

$Reference* __getitem__dict__int__($Reference* D, $Reference* x);

$Reference* __getitem__dict__bool__($Reference* D, $Reference* x);

$Reference* __getitem__dict__str__($Reference* D, $Reference* x);

$Reference* __len__dict__($Reference* D);

$Reference* __contains__dict__($Reference* x, $Reference* D);

$Reference* __notcontains__dict__($Reference* x, $Reference* D);


// Type file

$Reference* __open1__($Reference* name);

$Reference* __open2__($Reference* name, $Reference* mode);

void __close__($Reference* file);

$Reference* __readline__($Reference* file);

$Reference* __read__($Reference* file);

$Reference* __standard_file__($Reference* k);



#endif
