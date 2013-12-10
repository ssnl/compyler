/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library */

/* Authors:  YOUR NAMES HERE */

#include "runtime.h"

using namespace std;

/** Stores frames during runtime. */
vector<Frame*> STACK;
/** Stores references to objects allocated during runtime. */
vector<void*> HEAP;
/** Our runtime stack machine. */
vector<void*> SM;

/* Temporaries */

/** Stores the current environment (frame) of execution. */
Frame* cf;
/** Stores the static link of a called function. */
Frame* static_link;
/** Stores newly created frame when calling function. */
Frame* tmp_frame;
/** Stores function pointer when popped from SM. */
FuncDesc* call;

/** Stores assignment destination in "dst = src". */
void* dst;
/** Stores assignment source in "dst = src". */
void* src;
/** Stores temp reference to allocated object. */
void* tmp_alloc;
/** Stores arguments of native calls. */
void* tmp_arg0;
void* tmp_arg1;
void* tmp_arg2;
void* tmp_arg3;

/** Stores the constant Integer value of 0. */
int_0$* __ZERO__ = new int_0$(0);

/* Class $Object */

string
$Object::toString() {return "";}


/* Class bool_0$ */

bool_0$*
bool_0$::operator+ (bool_0$ y) {
    bool_0$* res = new bool_0$(value + y.value);
    return res;
}

bool_0$*
bool_0$::operator- (bool_0$ y) {
    bool_0$* res = new bool_0$(value - y.value);
    return res;
}

bool_0$*
bool_0$::operator* (bool_0$ y) {
    bool_0$* res = new bool_0$(value * y.value);
    return res;
}

bool_0$*
bool_0$::operator/ (bool_0$ y) {
    bool_0$* res = new bool_0$(value / y.value);
    return res;
}

bool_0$*
bool_0$::operator% (bool_0$ y) {
    bool_0$* res = new bool_0$(value % y.value);
    return res;
}

bool_0$*
bool_0$::operator- () {
    bool_0$* res = new bool_0$(-value);
    return res;
}

bool_0$*
bool_0$::operator! () {
    bool_0$* res = new bool_0$(!value);
    return res;
}

bool_0$*
bool_0$::operator< (bool_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    return res;
}

bool_0$*
bool_0$::operator> (bool_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    return res;
}

bool_0$*
bool_0$::operator<= (bool_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    return res;
}

bool_0$*
bool_0$::operator>= (bool_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    return res;
}

bool_0$*
bool_0$::operator== (bool_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    return res;
}

bool_0$*
bool_0$::operator!= (bool_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    return res;
}

string
bool_0$::toString() {
    return (value) ? "True" : "False";
}

/* Class int_0$ */

int_0$*
int_0$::operator+ (int_0$ y) {
    int_0$* res = new int_0$(value + y.value);
    return res;
}

int_0$*
int_0$::operator- (int_0$ y) {
    int_0$* res = new int_0$(value - y.value);
    return res;
}

int_0$*
int_0$::operator* (int_0$ y) {
    int_0$* res = new int_0$(value * y.value);
    return res;
}

str_0$*
int_0$::operator* (str_0$ y) {
    int count = value;
    if (count <= 0)
        return new str_0$();
    string s = y.getValue();
    for (int i = 0; i < count - 1; i++)
        s = s + y.getValue();
    str_0$* res = new str_0$(s);
    return res;
}

int_0$*
int_0$::operator/ (int_0$ y) {
    int_0$* res = new int_0$(value / y.value);
    return res;
}

int_0$*
int_0$::operator% (int_0$ y) {
    int_0$* res = new int_0$(value % y.value);
    return res;
}

int_0$*
int_0$::operator- () {
    int_0$* res = new int_0$(-value);
    return res;
}

bool_0$*
int_0$::operator< (int_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    return res;
}

bool_0$*
int_0$::operator> (int_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    return res;
}

bool_0$*
int_0$::operator<= (int_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    return res;
}

bool_0$*
int_0$::operator>= (int_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    return res;
}

bool_0$*
int_0$::operator== (int_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    return res;
}

bool_0$*
int_0$::operator!= (int_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    return res;
}

string
int_0$::toString() {
    stringstream ss;
    ss << value;
    return ss.str();
}



/* Class str_0$ */

str_0$*
str_0$::operator* (int_0$ y) {
    int count = y.getValue();
    if (count <= 0)
        return new str_0$();
    string s = value;
    for (int i = 0; i < count - 1; i++)
        s = s + value;
    str_0$* res = new str_0$(s);
    return res;
}

str_0$*
str_0$::operator+ (str_0$ y) {
    str_0$* res = new str_0$(value + y.value);
    return res;
}

bool_0$*
str_0$::operator< (str_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    return res;
}

bool_0$*
str_0$::operator> (str_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    return res;
}vr

bool_0$*
str_0$::operator<= (str_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    return res;
}

bool_0$*
str_0$::operator>= (str_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    return res;
}

bool_0$*
str_0$::operator== (str_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    return res;
}

bool_0$*
str_0$::operator!= (str_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    return res;
}

/* Runtime routines */

void
__donotcall__(void* x) {
    throw "Call to unimplemented function.";
}

int_0$*
__None__() {
    int_0$* res = new int_0$(0);
    return res;
}

bool_0$*
__truth__(void* x) {
    bool Bool = (($Object*) x)->asBool();
    return new bool_0$(Bool);
}

bool_0$*
__not__(void* x) {
    bool Bool = ((($Object*) x)->asBool());
    return new bool_0$((Bool ? false : true));
}

int_0$*
__add__int__(void* x, void* y){
    return *(int_0$*)x + *(int_0$*)y;
}

int_0$*
__sub__int__(void* x, void* y){
    return *(int_0$*)x - *(int_0$*)y;
}

int_0$*
__mul__int__(void* x, void* y){
    return *(int_0$*)x * *(int_0$*)y;
}

int_0$*
__floordiv__int__(void* x, void* y){
    return *(int_0$*)x / *(int_0$*)y;
}

int_0$*
__mod__int__(void* x, void* y) {
    return *(int_0$*)x % *(int_0$*)y;
}

int_0$*
__pow__int__(void* x, void* y) {
    int t = pow(((int_0$*)x)->getValue(), ((int_0$*)y)->getValue());
    int_0$* res = new int_0$(t);
    return res;
}

int_0$*
__neg__int__(void* x) {
    return -(*(int_0$*)x);
}

int_0$*
__pos__int__(void* x) {
    return (int_0$*)x;
}

bool_0$*
__lt__int__(void* x, void* y) {
    return *(int_0$*)x < *(int_0$*)y;
}

bool_0$*
__gt__int__(void* x, void* y) {
    return *(int_0$*)x > *(int_0$*)y;
}

bool_0$*
__le__int__(void* x, void* y) {
    return *(int_0$*)x <= *(int_0$*)y;
}

bool_0$*
__ge__int__(void* x, void* y) {
    return *(int_0$*)x >= *(int_0$*)y;
}

bool_0$*
__eq__int__(void* x, void* y) {
    return *(int_0$*)x == *(int_0$*)y;
}

bool_0$*
__ne__int__(void* x, void* y) {
    return *(int_0$*)x != *(int_0$*)y;
}

int_0$*
__toint__str__(void* x) {
    return new int_0$(atoi(((str_0$*)x)->getValue().c_str()));
}

// Type string

str_0$*
__add__str__(void* x, void* y) {
    return *(str_0$*)x + *(str_0$*)y;
}

str_0$*
__lmul__str__(void* x, void* y) {
    return *(str_0$*)x * *(int_0$*)y;
}

str_0$*
__rmul__str__(void* x, void* y) {
    return *(int_0$*)x * *(str_0$*)y;
}

bool_0$*
__lt__str__(void* x, void* y) {
    return *(str_0$*)x < *(str_0$*)y;
}

bool_0$*
__gt__str__(void* x, void* y) {
    return *(str_0$*)x > *(str_0$*)y;
}

bool_0$*
__le__str__(void* x, void* y) {
    return *(str_0$*)x <= *(str_0$*)y;
}

bool_0$*
__ge__str__(void* x, void* y) {
    return *(str_0$*)x >= *(str_0$*)y;
}

bool_0$*
__eq__str__(void* x, void* y) {
    return *(str_0$*)x == *(str_0$*)y;
}

bool_0$*
__ne__str__(void* x, void* y) {
    return *(str_0$*)x != *(str_0$*)y;
}

str_0$*
__getitem__str__(void* s, void* k) {
    string str = ((str_0$*)s)->getValue();
    int index = ((int_0$*)k)->getValue();
    int strLen = str.length();
    if (index >= strLen || index < -strLen) {
        throw "IndexError: string index out of range";
    } else if (index < 0) {
        index += strLen;
    }
    return new str_0$(str.substr(index, 1));
}

str_0$*
__getslice__str__(void* s, void* start, void* end) {
    string str = ((str_0$*)s)->getValue();
    int strLen = str.length();
    int startIndex = ((int_0$*)start)->getValue();
    int endIndex = ((int_0$*)end)->getValue();
    if (endIndex < 0) {
        endIndex += strLen;
    }
    if (startIndex >= strLen || startIndex < -strLen) {
        throw "IndexError: string index out of range";
    } else if (startIndex < 0) {
        startIndex += strLen;
    }
    int size = endIndex - startIndex;
    if (endIndex < 0 || size < 0) {
        size = 0;
    }
    return new str_0$(str.substr(startIndex, size));
}

int_0$*
__len__str__(void* s) {
    string str = ((str_0$*)s)->getValue();
    return new int_0$(str.length());
}

str_0$*
__tostr__(void* x) {
    string str = (($Object*)x)->toString();
    return new str_0$();
}

