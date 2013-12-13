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
vector<$Reference*> HEAP;
/** Our runtime stack machine. */
vector<$Reference*> SM;

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
$Reference* dst;
/** Stores assignment source in "dst = src". */
$Reference* src;
/** Stores temp reference to allocated object. */
$Reference* tmp_alloc;
/** Stores the result of a native call. */
$Reference* tmp_res;
/** Stores a temp reference to the result of a comparison. */
$Reference* tmp_cmp;
/** Stores a temp reference to the result of a left comparison. */
$Reference* tmp_left;
$Reference* tmp_right;
/** Stores a tuple to be expanded. */
tuple_0$* tmp_tup;
/** Stores a file to be printed to. */
file_0$* tmp_file;
/** Used to combine strings. */
stringstream tmp_ss;

/** Stores the constant integer value of 0. */
int_0$* __ZERO__ = new int_0$(0);
/** Stores the constant boolean value of False. */
bool_0$* __FALSE__ = new bool_0$(false);

void runtimeErrorHandler( int signum ) {
    cout << "Runtime Exception (" << signum << ") received.\n";
   exit(1);
}

/* Class $Object */

string
$Object::toString(bool contained) {return "";}


/* Class bool_0$ */

$Reference*
bool_0$::operator+ (bool_0$ y) {
    bool_0$* res = new bool_0$(value + y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator- (bool_0$ y) {
    bool_0$* res = new bool_0$(value - y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator* (bool_0$ y) {
    bool_0$* res = new bool_0$(value * y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator/ (bool_0$ y) {
    bool_0$* res = new bool_0$(value / y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator% (bool_0$ y) {
    bool_0$* res = new bool_0$(value % y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator- () {
    bool_0$* res = new bool_0$(-value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator! () {
    bool_0$* res = new bool_0$(!value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator< (bool_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator> (bool_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator<= (bool_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator>= (bool_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator== (bool_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
bool_0$::operator!= (bool_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
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

$Reference*
int_0$::operator+ (int_0$ y) {
    int_0$* res = new int_0$(value + y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator- (int_0$ y) {
    int_0$* res = new int_0$(value - y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator* (int_0$ y) {
    int_0$* res = new int_0$(value * y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator* (str_0$ y) {
    int count = value;
    str_0$* res;
    $Reference* ref;
    if (count <= 0) {
        res = new str_0$();
        ref = new $Reference(res);
        HEAP.push_back(ref);
        return ref;
    }
    string s = y.getValue();
    for (int i = 0; i < count - 1; i++)
        s = s + y.getValue();
    res = new str_0$(s);
    ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator/ (int_0$ y) {
    int_0$* res = new int_0$(value / y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator% (int_0$ y) {
    int_0$* res = new int_0$(value % y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator- () {
    int_0$* res = new int_0$(-value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator+ () {
    int_0$* res = new int_0$(value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator< (int_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator> (int_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator<= (int_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator>= (int_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator== (int_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
int_0$::operator!= (int_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
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

$Reference*
str_0$::operator* (int_0$ y) {
    int count = y.getValue();
    str_0$* res;
    $Reference* ref;
    if (count <= 0) {
        res = new str_0$();
        ref = new $Reference(res);
        HEAP.push_back(ref);
        return ref;
    }
    string s = value;
    for (int i = 0; i < count - 1; i++)
        s = s + value;
    res = new str_0$(s);
    ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::operator+ (str_0$ y) {
    str_0$* res = new str_0$(value + y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::operator< (str_0$ y) {
    bool_0$* res = new bool_0$(value < y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::operator> (str_0$ y) {
    bool_0$* res = new bool_0$(value > y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::operator<= (str_0$ y) {
    bool_0$* res = new bool_0$(value <= y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::operator>= (str_0$ y) {
    bool_0$* res = new bool_0$(value >= y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::operator== (str_0$ y) {
    bool_0$* res = new bool_0$(value == y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::operator!= (str_0$ y) {
    bool_0$* res = new bool_0$(value != y.value);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

int
str_0$::size() {
    return value.length();
}

$Reference*
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
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
str_0$::getElement(int k) {
    str_0$* res = new str_0$(value.substr(k, 1));
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

string
str_0$::toString(bool contained) {
    if (contained)
        return "\'" + value + "\'";
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

$Reference*
range_0$::getElement(int k) {
    int_0$* res = new int_0$(start + k);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

bool
range_0$::equals(void* other) {
    return this == other;
}

/* Class list_0$ */

$Reference*
list_0$::getItem(int k) {
    int s = size();
    if (k < -s || k >= s)
        throw "IndexError: list index out of range";
    else if (k < 0)
        k += s;
    return value[k];
}

$Reference*
list_0$::getElement(int k) {
    return getItem(k);
}

$Reference*
list_0$::getSlice(int L, int U) {
    int s = size();
    list_0$* res;
    $Reference* ref;
    if (L >= U || L >= s) {
        res = new list_0$();
        ref = new $Reference(res);
        HEAP.push_back(ref);
        return ref;
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
        res->push(getItem(i));
    }
    ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

string
list_0$::toString(bool contained) {
    stringstream ss;
    ss << "[";
    int s = size();
    for (int i = 0; i < s - 1; i++) {
        ss << getItem(i)->get()->toString(true) << ", ";
    }
    if (s > 0)
        ss << getItem(s-1)->get()->toString(true);
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
        ss << getItem(0)->get()->toString(true) << ",";
    else if (s > 1)
        ss << getItem(0)->get()->toString(true);
    for (int i = 1; i < s; i++) {
        ss << ", "<< getItem(i)->get()->toString(true);
    }
    ss << ")";
    return ss.str();
}

bool
tuple_0$::equals(void* other) {
    return this == other;
}

/* Class dict_0$ and its subclasses */

$Reference*
dict_0$::get(void* dictKey) {
    int key = ((int_0$*) dictKey)->getValue();
    return value[key];
}

// dict with int as key
$Reference*
dict_int_0$::get(void* dictKey) {
    int key = ((int_0$*) dictKey)->getValue();
    return value[key];
}

void
dict_int_0$::set(void* dictKey, $Reference* item) {
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
    for (map<int, $Reference*>::iterator it = value.begin();
                it != value.end(); it++) {
        count++;
        ss << it->first << ": " << it->second->get()->toString(true);
        if (count < s)
            ss << ", ";
    }
    ss << "}";
    return ss.str();
}

/* class dict_0$ and its subclasses */
bool
dict_0$::equals(void* other) {
    return this == other;
}

// dict with string as key
$Reference*
dict_str_0$::get(void* dictKey) {
    string key = ((str_0$*) dictKey)->getValue();
    return value[key];
}

void
dict_str_0$::set(void* dictKey, $Reference* item) {
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
    for (map<string, $Reference*>::iterator it = value.begin();
                it != value.end(); it++) {
        count++;
        ss << "\'" << it->first << "\': " << it->second->get()->toString(true);
        if (count < s)
            ss << ", ";
    }
    ss << "}";
    return ss.str();
}

// dict with bool as key
$Reference*
dict_bool_0$::get(void* dictKey) {
    bool key = ((bool_0$*) dictKey)->getValue();
    return value[key];
}

void
dict_bool_0$::set(void* dictKey, $Reference* item) {
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
    for (map<bool, $Reference*>::iterator it = value.begin();
                it != value.end(); it++) {
        count++;
        ss << (it->first ? "True" : "False");
        ss << ": " << it->second->get()->toString(true);
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
$Reference*
__tuple__() {
    tuple_0$* res = new tuple_0$();
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__tuple__($Reference* x) {
    $Reference* tmp = new $Reference(x->get());
    HEAP.push_back(tmp);
    tuple_0$* res = new tuple_0$(1);
    res->push(tmp);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__tuple__($Reference* x, $Reference* y) {
    $Reference* tmp1 = new $Reference(x->get());
    $Reference* tmp2 = new $Reference(y->get());
    HEAP.push_back(tmp1);
    HEAP.push_back(tmp2);
    tuple_0$* res = new tuple_0$(2);
    res->push(tmp1);
    res->push(tmp2);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__tuple__($Reference* x, $Reference* y, $Reference* z) {
    $Reference* tmp1 = new $Reference(x->get());
    $Reference* tmp2 = new $Reference(y->get());
    $Reference* tmp3 = new $Reference(z->get());
    HEAP.push_back(tmp1);
    HEAP.push_back(tmp2);
    HEAP.push_back(tmp3);
    tuple_0$* res = new tuple_0$(3);
    res->push(tmp1);
    res->push(tmp2);
    res->push(tmp3);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__list__empty__() {
    list_0$* res = new list_0$();
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__list__($Reference* count, ...) {
    int argcount = ((int_0$*) count->get())->getValue();
    list_0$* res = new list_0$();

    va_list arguments;
    va_start (arguments, count);

    $Reference* tmp;

    for (int i = 0; i < argcount; i++) {
        tmp = new $Reference(va_arg (arguments, $Reference*)->get());
        res->push(tmp);
        HEAP.push_back(tmp);
    }

    va_end (arguments);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__dict__empty__int__() {
    dict_int_0$* res = new dict_int_0$();
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__dict__empty__str__() {
    dict_str_0$* res = new dict_str_0$();
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__dict__empty__bool__() {
    dict_bool_0$* res = new dict_bool_0$();
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__dict__int__($Reference* count, ...) {
    int argcount = ((int_0$*) count->get())->getValue();
    dict_int_0$* res = new dict_int_0$();

    va_list arguments;
    va_start (arguments, count);

    int_0$* key;

    $Reference *tmp;

    for (int i = 0; i < argcount; i++) {
        key = (int_0$*) va_arg(arguments, $Reference*)->get();
        tmp = new $Reference(va_arg (arguments, $Reference*)->get());
        res->set(key, tmp);
        HEAP.push_back(tmp);
    }

    va_end (arguments);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__dict__str__($Reference* count, ...) {
    int argcount = ((int_0$*) count->get())->getValue();
    dict_str_0$* res = new dict_str_0$();

    va_list arguments;
    va_start (arguments, count);

    str_0$* key;

    $Reference *tmp;

    for (int i = 0; i < argcount; i++) {
        key = (str_0$*) va_arg(arguments, $Reference*)->get();
        tmp = new $Reference(va_arg (arguments, $Reference*)->get());
        res->set(key, tmp);
        HEAP.push_back(tmp);
    }

    va_end (arguments);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__dict__bool__($Reference* count, ...) {
    int argcount = ((int_0$*) count->get())->getValue();
    dict_bool_0$* res = new dict_bool_0$();

    va_list arguments;
    va_start (arguments, count);

    bool_0$* key;

    $Reference *tmp;

    for (int i = 0; i < argcount; i++) {
        key = (bool_0$*) va_arg(arguments, $Reference*)->get();
        tmp = new $Reference(va_arg (arguments, $Reference*)->get());
        res->set(key, tmp);
        HEAP.push_back(tmp);
    }

    va_end (arguments);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

/* Runtime routines */

// Miscellaneous

void
__donotcall__(void* x) {
    throw "Call to unimplemented function.";
}

$Reference*
__None__() {
    int_0$* res = new int_0$(0);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__is__($Reference* x, $Reference* y) {
    bool b = (($Object*) x->get())->equals(y->get());
    bool_0$* res = new bool_0$(b);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__isnot__($Reference* x, $Reference* y) {
    bool b = (($Object*) x->get())->equals(y->get());
    bool_0$* res = new bool_0$(!b);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__and__($Reference* x, $Reference* y) {
    bool left = (($Object*) x->get())->asBool();
    if (left == false)
        return x;
    else
        return y;
}

$Reference*
__or__($Reference* x, $Reference* y) {
    bool left = (($Object*) x->get())->asBool();
    if (left == false)
        return y;
    else
        return x;
}

// Type bool

$Reference*
__truth__($Reference* x) {
    bool Bool = (($Object*) x->get())->asBool();
    bool_0$* res = new bool_0$(Bool);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__not__($Reference* x) {
    bool Bool = ((($Object*) x->get())->asBool());
    bool_0$* res = new bool_0$(!Bool);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}


// Type range

$Reference*
__xrange__($Reference* low, $Reference* high) {
    int start = ((int_0$*)low->get())->getValue();
    int end = ((int_0$*)high->get())->getValue();
    if (end < start)
        end = start;
    range_0$* res = new range_0$(start, end);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__len__range__($Reference* r) {
    int rLen = ((range_0$*) r->get())->size();
    int_0$* res = new int_0$(rLen);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}


// Type int

$Reference*
__add__int__($Reference* x, $Reference* y){
    return *((int_0$*)x->get()) + *((int_0$*)y->get());
}

$Reference*
__sub__int__($Reference* x, $Reference* y){
    return *((int_0$*)x->get()) - *((int_0$*)y->get());
}

$Reference*
__mul__int__($Reference* x, $Reference* y){
    return *((int_0$*)x->get()) * *((int_0$*)y->get());
}

$Reference*
__floordiv__int__($Reference* x, $Reference* y){
    return *((int_0$*)x->get()) / *((int_0$*)y->get());
}

$Reference*
__mod__int__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) % *((int_0$*)y->get());
}

$Reference*
__pow__int__($Reference* x, $Reference* y) {
    int X = ((int_0$*)x->get())->getValue();
    int Y = ((int_0$*)y->get())->getValue();
    int t = pow(X, Y);
    int_0$* res = new int_0$(t);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__neg__int__($Reference* x) {
    return -(*((int_0$*)x->get()));
}

$Reference*
__pos__int__($Reference* x) {
    return +(*((int_0$*)x->get()));
}

$Reference*
__lt__int__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) < *((int_0$*)y->get());
}

$Reference*
__gt__int__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) > *((int_0$*)y->get());
}

$Reference*
__le__int__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) <= *((int_0$*)y->get());
}

$Reference*
__ge__int__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) >= *((int_0$*)y->get());
}

$Reference*
__eq__int__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) == *((int_0$*)y->get());
}

$Reference*
__ne__int__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) != *((int_0$*)y->get());
}

$Reference*
__toint__str__($Reference* x) {
    int_0$* res = new int_0$(atoi( ((str_0$*) x->get())->getValue().c_str() ));
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

// Type string

$Reference*
__add__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) + *((str_0$*)y->get());
}

$Reference*
__lmul__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) * *((int_0$*)y->get());
}

$Reference*
__rmul__str__($Reference* x, $Reference* y) {
    return *((int_0$*)x->get()) * *((str_0$*)y->get());
}

$Reference*
__lt__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) < *((str_0$*)y->get());
}

$Reference*
__gt__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) > *((str_0$*)y->get());
}

$Reference*
__le__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) <= *((str_0$*)y->get());
}

$Reference*
__ge__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) >= *((str_0$*)y->get());
}

$Reference*
__eq__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) == *((str_0$*)y->get());
}

$Reference*
__ne__str__($Reference* x, $Reference* y) {
    return *((str_0$*)x->get()) != *((str_0$*)y->get());
}

$Reference*
__getitem__str__($Reference* s, $Reference* k) {
    string str = ((str_0$*)s->get())->getValue();
    int index = ((int_0$*)k->get())->getValue();
    int strLen = str.length();
    if (index >= strLen || index < -strLen) {
        throw "IndexError: string index out of range";
    } else if (index < 0) {
        index += strLen;
    }
    str_0$* res = new str_0$(str.substr(index, 1));
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__getslice__str__($Reference* s, $Reference* start) {
    string str = ((str_0$*) s->get())->getValue();
    int strLen = str.length();
    int startIndex = ((int_0$*)start->get())->getValue();
    int endIndex = strLen;
    return ((str_0$*) s->get())->getSlice(startIndex, endIndex);
}

$Reference*
__getslice__str__($Reference* s, $Reference* start, $Reference* end) {
    int startIndex = ((int_0$*)start->get())->getValue();
    int endIndex = ((int_0$*)end->get())->getValue();
    return ((str_0$*) s->get())->getSlice(startIndex, endIndex);
}

$Reference*
__len__str__($Reference* s) {
    int_0$* res = new int_0$(((str_0$*) s->get())->size());
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__tostr__($Reference* x) {
    string str = (($Object*)x->get())->toString();
    str_0$* res = new str_0$(str);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}


// Type list

$Reference*
__getitem__list__($Reference* S, $Reference* k) {
    int index = ((int_0$*) k->get())->getValue();
    return ((list_0$*) S->get())->getItem(index);
}

$Reference*
__getslice__list__($Reference* S, $Reference* L) {
    int l = ((int_0$*) L->get())->getValue();
    int u = ((list_0$*) S->get())->size();
    return ((list_0$*) S->get())->getSlice(l, u);
}

$Reference*
__getslice__list__($Reference* S, $Reference* L, $Reference* U) {
    int l = ((int_0$*) L->get())->getValue();
    int u = ((int_0$*) U->get())->getValue();
    return ((list_0$*) S->get())->getSlice(l, u);
}

$Reference*
__len__list__($Reference* S) {
    int s = ((list_0$*) S->get())->size();
    int_0$* res = new int_0$(s);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__argv__() {
    list_0$* res = new list_0$();
    for (int i = 0; i < argcount; i++) {
        res->push(new $Reference(new str_0$(args[i])));
    }
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}


// Type dict

$Reference*
__getitem__dict__int__($Reference* D, $Reference* x) {
    return ((dict_int_0$*) D->get())->get(x->get());
}

$Reference*
__getitem__dict__str__($Reference* D, $Reference* x) {
    return ((dict_str_0$*) D->get())->get(x->get());
}

$Reference*
__getitem__dict__bool__($Reference* D, $Reference* x) {
    return ((dict_bool_0$*) D->get())->get(x->get());
}

$Reference*
__len__dict__($Reference* D) {
    int s = ((dict_0$*) D->get())->size();
    int_0$* res = new int_0$(s);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__contains__dict__($Reference* x, $Reference* D) {
    bool b = ((dict_0$*) D->get())->contains(x);
    bool_0$* res = new bool_0$(b);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__notcontains__dict__($Reference* x, $Reference* D) {
    bool b = ((dict_0$*) D->get())->contains(x);
    bool_0$* res = new bool_0$((b ? false : true));
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}


// Type file

$Reference*
__open1__($Reference* name) {
    string fName = ((str_0$*) name->get())->getValue();
    FILE* f;
    f = fopen(fName.c_str(), "r");
    if (f == NULL) {
        stringstream ss;
        ss << "IOError: file \'" << fName << "\' cannot be opened";
        throw ss.str();
    }
    file_0$* res = new file_0$(f);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__open2__($Reference* name, $Reference* mode) {
    string fName = ((str_0$*) name->get())->getValue();
    string fMode = ((str_0$*) mode->get())->getValue();
    FILE* f;
    f = fopen(fName.c_str(), fMode.c_str());
    if (f == NULL) {
        stringstream ss;
        ss << "IOError: file \'" << fName << "\' cannot be opened";
        throw ss.str();
    }
    file_0$* res = new file_0$(f);
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

void
__close__($Reference* file) {
    ((file_0$*) file->get())->close();
}

$Reference*
__readline__($Reference* file) {
    FILE* f = ((file_0$*) file->get())->getValue();
    char c;
    stringstream ss;
    ss.str("");
    c = (char) fgetc(f);
    while (c != '\n' && c != EOF) {
        ss << c;
        c = (char) fgetc(f);
    }
    str_0$* res = new str_0$(ss.str());
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

$Reference*
__read__($Reference* file) {
    FILE* f = ((file_0$*) file->get())->getValue();
    char c;
    stringstream ss;
    ss.str("");
    c = (char) fgetc(f);
    while (c != EOF) {
        ss << c;
        c = (char) fgetc(f);
    }
    str_0$* res = new str_0$(ss.str());
    $Reference* ref = new $Reference(res);
    HEAP.push_back(ref);
    return ref;
}

// The file wrappers for stdin, stdout, and stderr.
file_0$ f1(stdin), f2(stdout), f3(stderr);
$Reference* STDIN = new $Reference(&f1);
$Reference* STDOUT = new $Reference(&f2);
$Reference* STDERR = new $Reference(&f3);

$Reference*
__standard_file__($Reference* K) {
    int k = ((int_0$*) K->get())->getValue();
    if (k == 0)
        return STDIN;
    else if (k == 1)
        return STDOUT;
    else
        return STDERR;
}

/** Garbage collection sweep routine. Every $Object's reference counter is
 *  either reset to zero after execution if it has 0 or 1 references, otherwise
 *  it is removed from the HEAP and reclaimed. */
void
__gc__() {
    for (int i = 0; i < SM.size(); i++)
        SM[i]->get()->incrCounter();
    for (int i = 0; i < HEAP.size(); i++) {
        if (HEAP[i]->get()->getCounter() == 1) {
            delete HEAP[i];
            HEAP.erase(HEAP.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < SM.size(); i++)
        SM[i]->get()->decrCounter();
}
