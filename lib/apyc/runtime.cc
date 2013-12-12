/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library */

/* Authors:  YOUR NAMES HERE */

#include "runtime.h"

using namespace std;

/** Stores the number of arguments passed to the generated program. */
int argcount;
/** Stores the arguments passed to the generated program. */
char** args;

/** Stores frames during runtime. */
vector<Frame*> STACK;
/** Stores references to objects allocated during runtime. */
vector<$Object*> HEAP;
/** Our runtime stack machine. */
vector<$Object**> SM;

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
$Object** dst;
/** Stores assignment source in "dst = src". */
$Object** src;
/** Stores temp reference to allocated object. */
$Object* tmp_alloc;
/** Stores the result of a native call. */
$Object* tmp_res;
/** Stores a tuple to be expanded. */
$Object* tmp_tup;

/** Stores the constant Integer value of 0. */
int_0$* __ZERO__ = new int_0$(0);




/* Class $Object */

string
$Object::toString(bool contained) {return "";}


/* Class bool_0$ */

bool_0$**
bool_0$::operator+ (bool_0$ y) {
    bool_0$* res = new bool_0$(value + y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator- (bool_0$ y) {
    bool_0$* res = new bool_0$(value - y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator* (bool_0$ y) {
    bool_0$* res = new bool_0$(value * y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator/ (bool_0$ y) {
    bool_0$* res = new bool_0$(value / y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator% (bool_0$ y) {
    bool_0$* res = new bool_0$(value % y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator- () {
    bool_0$* res = new bool_0$(-value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator! () {
    bool_0$* res = new bool_0$(!value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator< (bool_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator> (bool_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator<= (bool_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator>= (bool_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator== (bool_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
bool_0$::operator!= (bool_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

string
bool_0$::toString(bool contained) {
    return (value) ? "True" : "False";
}

bool
bool_0$::equals(void* other) {
    if ((($Object*) other)->className() != "bool")
        return false;
    else
        return getValue() == ((bool_0$*) other)->getValue();
}

/* Class int_0$ */

int_0$**
int_0$::operator+ (int_0$ y) {
    int_0$* res = new int_0$(value + y.value);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

int_0$**
int_0$::operator- (int_0$ y) {
    int_0$* res = new int_0$(value - y.value);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

int_0$**
int_0$::operator* (int_0$ y) {
    int_0$* res = new int_0$(value * y.value);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

str_0$**
int_0$::operator* (str_0$ y) {
    int count = value;
    str_0$* res;
    if (count <= 0) {
        res = new str_0$();
        HEAP.push_back(res);
        return (str_0$**) &HEAP[HEAP.size()-1];
    }
    string s = y.getValue();
    for (int i = 0; i < count - 1; i++)
        s = s + y.getValue();
    res = new str_0$(s);
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size()-1];
}

int_0$**
int_0$::operator/ (int_0$ y) {
    int_0$* res = new int_0$(value / y.value);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

int_0$**
int_0$::operator% (int_0$ y) {
    int_0$* res = new int_0$(value % y.value);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

int_0$**
int_0$::operator- () {
    int_0$* res = new int_0$(-value);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

int_0$**
int_0$::operator+ () {
    int_0$* res = new int_0$(value);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
int_0$::operator< (int_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
int_0$::operator> (int_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
int_0$::operator<= (int_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
int_0$::operator>= (int_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
int_0$::operator== (int_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
int_0$::operator!= (int_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

string
int_0$::toString(bool contained) {
    stringstream ss;
    ss << value;
    return ss.str();
}

bool
int_0$::equals(void* other) {
    if ((($Object*) other)->className() != "int")
        return false;
    else
        return getValue() == ((int_0$*) other)->getValue();
}


/* Class str_0$ */

str_0$**
str_0$::operator* (int_0$ y) {
    int count = y.getValue();
    str_0$* res;
    if (count <= 0) {
        res = new str_0$();
        HEAP.push_back(res);
        return (str_0$**) &HEAP[HEAP.size()-1];
    }
    string s = value;
    for (int i = 0; i < count - 1; i++)
        s = s + value;
    res = new str_0$(s);
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size()-1];
}

str_0$**
str_0$::operator+ (str_0$ y) {
    str_0$* res = new str_0$(value + y.value);
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
str_0$::operator< (str_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
str_0$::operator> (str_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
str_0$::operator<= (str_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
str_0$::operator>= (str_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
str_0$::operator== (str_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
str_0$::operator!= (str_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

int
str_0$::size() {
    return value.length();
}

str_0$**
str_0$::getSlice(int startIndex, int endIndex) {
    string str = getValue();
    int strLen = str.length();
    if (endIndex < 0) {
        endIndex += strLen;
    }
    if (startIndex >= strLen || startIndex < -strLen) {
        throw "IndexError: string index out of range";
    } else if (startIndex < 0) {
        startIndex += strLen;
    }
    int s = endIndex - startIndex;
    if (endIndex < 0 || s < 0) {
        s = 0;
    }
    str_0$* res = new str_0$(str.substr(startIndex, s));
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size()-1];
}

string
str_0$::toString(bool contained) {
    if (contained)
        return "\"" + value + "\"";
    else
        return value;
}

bool
str_0$::equals(void* other) {
    if ((($Object*) other)->className() != "str")
        return false;
    else
        return getValue() == ((str_0$*) other)->getValue();
}

/* Class range_0$ */

string
range_0$::toString(bool contained) {
    stringstream ss;
    ss << "range(";
    if (start == 0)
        ss << end;
    else
        ss << start << ", " << end;
    ss << ")";
    return ss.str();
}

bool
range_0$::equals(void* other) {
    return this == other;
}

/* Class list_0$ */

$Object**
list_0$::getItem(int k) {
    int s = size();
    if (k < -s || k >= s)
        throw "IndexError: list index out of range";
    else if (k < 0)
        k += s;
    return &value[k];
}

list_0$**
list_0$::getSlice(int L, int U) {
    int s = size();
    list_0$* res;
    if (L >= U || L >= s) {
        res = new list_0$();
        HEAP.push_back(res);
        return (list_0$**) &HEAP[HEAP.size()-1];
    }
    if (L < -s) {
        L = 0;
    } else if (L < 0) {
        L += s;
    }
    if (U < -s) {
        U = 0;
    } else if (U < 0) {
        U += s;
    }
    if (U > s) {
        U = s;
    }
    res = new list_0$();
    for (int i = L; i < U; i++) {
        res->push(*getItem(i));
    }
    HEAP.push_back(res);
    return (list_0$**) &HEAP[HEAP.size()-1];
}

string
list_0$::toString(bool contained) {
    stringstream ss;
    ss << "[";
    int s = size();
    for (int i = 0; i < s - 1; i++) {
        ss << (*getItem(i))->toString(true) << ", ";
    }
    if (s > 0)
        ss << (*getItem(s-1))->toString(true);
    ss << "]";
    return ss.str();
}

bool
list_0$::equals(void* other) {
    return this == other;
}

/* Class tuple_0$ */

string
tuple_0$::toString(bool contained) {
    int s = size();
    stringstream ss;
    ss << "(";
    if (s == 1)
        ss << (*getItem(0))->toString(true) << ",";
    else if (s > 1)
        ss << (*getItem(0))->toString(true);
    for (int i = 1; i < s; i++) {
        ss << ", "<< (*getItem(i))->toString(true);
    }
    ss << ")";
    return ss.str();
}

bool
tuple_0$::equals(void* other) {
    return this == other;
}

/* Class dict_0$ and its subclasses */

bool
dict_0$::equals(void* other) {
    return this == other;
}

// dict with int as key
$Object**
dict_int_0$::get(void* dictKey) {
    int key = ((int_0$*) dictKey)->getValue();
    return &value[key];
}

void
dict_int_0$::set(void* dictKey, $Object* item) {
    int key = ((int_0$*) dictKey)->getValue();
    value[key] = item;
}

bool
dict_int_0$::contains(void* dictKey) {
    int key = ((int_0$*) dictKey)->getValue();
    if (value.find(key) != value.end()) {
        return true;
    }
    return false;
}

string
dict_int_0$::toString(bool contained) {
    int s = size();
    stringstream ss;
    ss << "{";
    int count = 0;
    for (map<int, $Object*>::iterator it = value.begin();
                it != value.end(); it++) {
        count++;
        ss << it->first << ": " << it->second->toString(true);
        if (count < s)
            ss << ", ";
    }
    ss << "}";
    return ss.str();
}


// dict with string as key
$Object**
dict_str_0$::get(void* dictKey) {
    string key = ((str_0$*) dictKey)->getValue();
    return &value[key];
}

void
dict_str_0$::set(void* dictKey, $Object* item) {
    string key = ((str_0$*) dictKey)->getValue();
    value[key] = item;
}

bool
dict_str_0$::contains(void* dictKey) {
    string key = ((str_0$*) dictKey)->getValue();
    if (value.find(key) != value.end()) {
        return true;
    }
    return false;
}

string
dict_str_0$::toString(bool contained) {
    int s = size();
    stringstream ss;
    ss << "{";
    int count = 0;
    for (map<string, $Object*>::iterator it = value.begin();
                it != value.end(); it++) {
        count++;
        ss << "\"" << it->first << "\": " << it->second->toString(true);
        if (count < s)
            ss << ", ";
    }
    ss << "}";
    return ss.str();
}

// dict with bool as key
$Object**
dict_bool_0$::get(void* dictKey) {
    bool key = ((bool_0$*) dictKey)->getValue();
    return &value[key];
}

void
dict_bool_0$::set(void* dictKey, $Object* item) {
    bool key = ((bool_0$*) dictKey)->getValue();
    value[key] = item;
}

bool
dict_bool_0$::contains(void* dictKey) {
    bool key = ((bool_0$*) dictKey)->getValue();
    if (value.find(key) != value.end()) {
        return true;
    }
    return false;
}

string
dict_bool_0$::toString(bool contained) {
    int s = size();
    stringstream ss;
    ss << "{";
    int count = 0;
    for (map<bool, $Object*>::iterator it = value.begin();
                it != value.end(); it++) {
        count++;
        ss << (it->first ? "True" : "False");
        ss << ": " << it->second->toString(true);
        if (count < s)
            ss << ", ";
    }
    ss << "}";
    return ss.str();
}


/* Class file */

string
file_0$::toString() {
    stringstream ss;
    ss << this;
    return ss.str();
}

bool
file_0$::equals(void* other) {
    return this == other;
}



/* Allocators for list_0$, tuple_0$, and dict_0$ */
tuple_0$*
__tuple0__() {
    tuple_0$* res = new tuple_0$();
    HEAP.push_back(res);
    return res;
}

tuple_0$*
__tuple1__(void* x) {
    tuple_0$* res = new tuple_0$(1);
    res->push(($Object*)x);
    HEAP.push_back(res);
    return res;
}

tuple_0$*
__tuple2__(void* x, void* y) {
    tuple_0$* res = new tuple_0$(2);
    res->push(($Object*)x);
    res->push(($Object*)y);
    HEAP.push_back(res);
    return res;
}

tuple_0$*
__tuple3__(void* x, void* y, void* z) {
    tuple_0$* res = new tuple_0$(3);
    res->push(($Object*)x);
    res->push(($Object*)y);
    res->push(($Object*)z);
    HEAP.push_back(res);
    return res;
}

list_0$*
__list__empty__() {
    list_0$* res = new list_0$();
    HEAP.push_back(res);
    return res;
}

list_0$*
__list__(void* count, void* x, ...) {
    int argcount = ((int_0$*) count)->getValue();
    list_0$* res = new list_0$();

    va_list arguments;
    va_start (arguments, x);

    res->push(($Object*) x);
    for (int i = 0; i < argcount; i++) {
        res->push(va_arg (arguments, $Object*));
    }

    va_end (arguments);
    HEAP.push_back(res);
    return res;
}

dict_int_0$*
__dict__empty__int__() {
    dict_int_0$* res = new dict_int_0$();
    HEAP.push_back(res);
    return res;
}

dict_str_0$*
__dict__empty__str__() {
    dict_str_0$* res = new dict_str_0$();
    HEAP.push_back(res);
    return res;
}

dict_bool_0$*
__dict__empty__bool__() {
    dict_bool_0$* res = new dict_bool_0$();
    HEAP.push_back(res);
    return res;
}

dict_int_0$*
__dict__int__(void* count, ...) {
    int argcount = ((int_0$*) count)->getValue();
    dict_int_0$* res = new dict_int_0$();

    va_list arguments;
    va_start (arguments, count);

    int_0$* key;

    for (int i = 0; i < argcount; i++) {
        key = va_arg(arguments, int_0$*);
        res->set(key, va_arg (arguments, $Object*));
    }

    va_end (arguments);
    HEAP.push_back(res);
    return res;
}

dict_str_0$*
__dict__str__(void* count, ...) {
    int argcount = ((int_0$*) count)->getValue();
    dict_str_0$* res = new dict_str_0$();

    va_list arguments;
    va_start (arguments, count);

    str_0$* key;

    for (int i = 0; i < argcount; i++) {
        key = va_arg(arguments, str_0$*);
        res->set(key, va_arg (arguments, $Object*));
    }

    va_end (arguments);
    HEAP.push_back(res);
    return res;
}

dict_bool_0$*
__dict__bool__(void* count, ...) {
    int argcount = ((int_0$*) count)->getValue();
    dict_bool_0$* res = new dict_bool_0$();

    va_list arguments;
    va_start (arguments, count);

    bool_0$* key;

    for (int i = 0; i < argcount; i++) {
        key = va_arg(arguments, bool_0$*);
        res->set(key, va_arg (arguments, $Object*));
    }

    va_end (arguments);
    HEAP.push_back(res);
    return res;
}

/* Runtime routines */

// Miscellaneous

void
__donotcall__(void* x) {
    throw "Call to unimplemented function.";
}

int_0$**
__None__() {
    int_0$* res = new int_0$(0);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
__is__(void* x, void* y) {
    bool b = (($Object*) x)->equals(y);
    bool_0$* res = new bool_0$(b);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
__isnot__(void* x, void* y) {
    bool b = (($Object*) x)->equals(y);
    bool_0$* res = new bool_0$((b ? false : true));
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}


// Type bool

bool_0$**
__truth__(void* x) {
    bool Bool = (($Object*) x)->asBool();
    bool_0$* res = new bool_0$(Bool);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}

bool_0$**
__not__(void* x) {
    bool Bool = ((($Object*) x)->asBool());
    bool_0$* res = new bool_0$((Bool ? false : true));
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size()-1];
}


// Type range

range_0$**
__xrange__(void* low, void* high) {
    int start = ((int_0$*)low)->getValue();
    int end = ((int_0$*)high)->getValue();
    if (end < start)
        end = start;
    range_0$* res = new range_0$(start, end);
    HEAP.push_back(res);
    return (range_0$**) &HEAP[HEAP.size()-1];
}

int_0$**
__len__range__(void* r) {
    int rLen = ((range_0$*) r)->size();
    int_0$* res = new int_0$(rLen);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size()-1];
}


// Type int

int_0$**
__add__int__(void* x, void* y){
    return *(int_0$*)x + *(int_0$*)y;
}

int_0$**
__sub__int__(void* x, void* y){
    return *(int_0$*)x - *(int_0$*)y;
}

int_0$**
__mul__int__(void* x, void* y){
    return *(int_0$*)x * *(int_0$*)y;
}

int_0$**
__floordiv__int__(void* x, void* y){
    return *(int_0$*)x / *(int_0$*)y;
}

int_0$**
__mod__int__(void* x, void* y) {
    return *(int_0$*)x % *(int_0$*)y;
}

int_0$**
__pow__int__(void* x, void* y) {
    int t = pow(((int_0$*)x)->getValue(), ((int_0$*)y)->getValue());
    int_0$* res = new int_0$(t);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size() - 1];
}

int_0$**
__neg__int__(void* x) {
    return -(*(int_0$*)x);
}

int_0$**
__pos__int__(void* x) {
    return +(*(int_0$*)x);
}

bool_0$**
__lt__int__(void* x, void* y) {
    return *(int_0$*)x < *(int_0$*)y;
}

bool_0$**
__gt__int__(void* x, void* y) {
    return *(int_0$*)x > *(int_0$*)y;
}

bool_0$**
__le__int__(void* x, void* y) {
    return *(int_0$*)x <= *(int_0$*)y;
}

bool_0$**
__ge__int__(void* x, void* y) {
    return *(int_0$*)x >= *(int_0$*)y;
}

bool_0$**
__eq__int__(void* x, void* y) {
    return *(int_0$*)x == *(int_0$*)y;
}

bool_0$**
__ne__int__(void* x, void* y) {
    return *(int_0$*)x != *(int_0$*)y;
}

int_0$**
__toint__str__(void* x) {
    int_0$* res = new int_0$(atoi(((str_0$*)x)->getValue().c_str()));
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size() - 1];
}

// Type string

str_0$**
__add__str__(void* x, void* y) {
    return *(str_0$*)x + *(str_0$*)y;
}

str_0$**
__lmul__str__(void* x, void* y) {
    return *(str_0$*)x * *(int_0$*)y;
}

str_0$**
__rmul__str__(void* x, void* y) {
    return *(int_0$*)x * *(str_0$*)y;
}

bool_0$**
__lt__str__(void* x, void* y) {
    return *(str_0$*)x < *(str_0$*)y;
}

bool_0$**
__gt__str__(void* x, void* y) {
    return *(str_0$*)x > *(str_0$*)y;
}

bool_0$**
__le__str__(void* x, void* y) {
    return *(str_0$*)x <= *(str_0$*)y;
}

bool_0$**
__ge__str__(void* x, void* y) {
    return *(str_0$*)x >= *(str_0$*)y;
}

bool_0$**
__eq__str__(void* x, void* y) {
    return *(str_0$*)x == *(str_0$*)y;
}

bool_0$**
__ne__str__(void* x, void* y) {
    return *(str_0$*)x != *(str_0$*)y;
}

str_0$**
__getitem__str__(void* s, void* k) {
    string str = ((str_0$*)s)->getValue();
    int index = ((int_0$*)k)->getValue();
    int strLen = str.length();
    if (index >= strLen || index < -strLen) {
        throw "IndexError: string index out of range";
    } else if (index < 0) {
        index += strLen;
    }
    str_0$* res = new str_0$(str.substr(index, 1));
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size()-1];
}

str_0$**
__getslice__str__(void* s, void* start) {
    string str = ((str_0$*)s)->getValue();
    int strLen = str.length();
    int startIndex = ((int_0$*)start)->getValue();
    int endIndex = strLen;
    return ((str_0$*) s)->getSlice(startIndex, endIndex);
}

str_0$**
__getslice__str__(void* s, void* start, void* end) {
    int startIndex = ((int_0$*)start)->getValue();
    int endIndex = ((int_0$*)end)->getValue();
    return ((str_0$*) s)->getSlice(startIndex, endIndex);
}

int_0$**
__len__str__(void* s) {
    int_0$* res = new int_0$(((str_0$*) s)->size());
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size() - 1];
}

str_0$**
__tostr__(void* x) {
    string str = (($Object*)x)->toString();
    str_0$* res = new str_0$(str);
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size() - 1];
}


// Type list

$Object**
__getitem__list__(void* S, void* k) {
    int index = ((int_0$*) k)->getValue();
    return ((list_0$*) S)->getItem(index);
}

list_0$**
__getslice__list__(void* S, void* L) {
    int l = ((int_0$*) L)->getValue();
    int u = ((list_0$*) S)->size();
    return ((list_0$*) S)->getSlice(l, u);
}

list_0$**
__getslice__list__(void* S, void* L, void* U) {
    int l = ((int_0$*) L)->getValue();
    int u = ((int_0$*) U)->getValue();
    return ((list_0$*) S)->getSlice(l, u);
}

int_0$**
__len__list__(void* S) {
    int s = ((list_0$*) S)->size();
    int_0$* res = new int_0$(s);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size() - 1];
}

list_0$**
__argv__() {
    list_0$* res = new list_0$();
    for (int i = 0; i < argcount; i++) {
        res->push(new str_0$(args[i]));
    }
    HEAP.push_back(res);
    return (list_0$**) &HEAP[HEAP.size() - 1];
}


// Type dict

$Object**
__getitem__dict__int__(void* D, void* x) {
    return ((dict_int_0$*) D)->get(x);
}

$Object**
__getitem__dict__str__(void* D, void* x) {
    return ((dict_str_0$*) D)->get(x);
}

$Object**
__getitem__dict__bool__(void* D, void* x) {
    return ((dict_bool_0$*) D)->get(x);
}

int_0$**
__len__dict__(void* D) {
    int s = ((dict_0$*) D)->size();
    int_0$* res = new int_0$(s);
    HEAP.push_back(res);
    return (int_0$**) &HEAP[HEAP.size() - 1];
}

bool_0$**
__contains__dict__(void* x, void* D) {
    bool b = ((dict_0$*) D)->contains(x);
    bool_0$* res = new bool_0$(b);
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size() - 1];
}

bool_0$**
__notcontains__dict__(void* x, void* D) {
    bool b = ((dict_0$*) D)->contains(x);
    bool_0$* res = new bool_0$((b ? false : true));
    HEAP.push_back(res);
    return (bool_0$**) &HEAP[HEAP.size() - 1];
}


// Type file

file_0$**
__open1__(void* name) {
    string fName = ((str_0$*) name)->getValue();
    FILE* f;
    f = fopen(fName.c_str(), "r");
    if (f == NULL) {
        stringstream ss;
        ss << "IOError: file \"" << fName << "\" cannot be opened";
        throw ss.str();
    }
    file_0$* res = new file_0$(f);
    HEAP.push_back(res);
    return (file_0$**) &HEAP[HEAP.size() - 1];
}

file_0$**
__open2__(void* name, void* mode) {
    string fName = ((str_0$*) name)->getValue();
    string fMode = ((str_0$*) mode)->getValue();
    FILE* f;
    f = fopen(fName.c_str(), fMode.c_str());
    if (f == NULL) {
        stringstream ss;
        ss << "IOError: file \"" << fName << "\" cannot be opened";
        throw ss.str();
    }
    file_0$* res = new file_0$(f);
    HEAP.push_back(res);
    return (file_0$**) &HEAP[HEAP.size() - 1];
}

void
__close__(void* file) {
    ((file_0$*) file)->close();
}

str_0$**
__readline__(void* file) {
    FILE* f = ((file_0$*) file)->getValue();
    char c;
    stringstream ss;
    ss.str("");
    c = (char) fgetc(f);
    while (c != '\n' && c != EOF) {
        ss << c;
        c = (char) fgetc(f);
    }
    str_0$* res = new str_0$(ss.str());
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size() - 1];
}

str_0$**
__read__(void* file) {
    FILE* f = ((file_0$*) file)->getValue();
    char c;
    stringstream ss;
    ss.str("");
    c = (char) fgetc(f);
    while (c != EOF) {
        ss << c;
        c = (char) fgetc(f);
    }
    str_0$* res = new str_0$(ss.str());
    HEAP.push_back(res);
    return (str_0$**) &HEAP[HEAP.size() - 1];
}

// The file wrappers for stdin, stdout, and stderr.
file_0$ f1(stdin), f2(stdout), f3(stderr);
file_0$* STDIN = &f1;
file_0$* STDOUT = &f2;
file_0$* STDERR = &f3;

file_0$**
__standard_file__(void* K) {
    int k = ((int_0$*) K)->getValue();
    if (k == 0)
        return &STDIN;
    else if (k == 1)
        return &STDOUT;
    else
        return &STDERR;
}

