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

/** Stores the constant Integer value of 0. */
int_0$* __ZERO__ = new int_0$(0);

/* Class $Object */

string
$Object::toString(bool contained) {return "";}


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
bool_0$::toString(bool contained) {
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
int_0$::toString(bool contained) {
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
}

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

int
str_0$::size() {
    return value.length();
}

string
str_0$::toString(bool contained) {
    if (contained)
        return "\"" + value + "\"";
    else
        return value;
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

/* Class list_0$ */

$Object*
list_0$::getItem(int k) {
    int s = size();
    if (k < -s || k >= s)
        throw "IndexError: list index out of range";
    else if (k < 0)
        k += s;
    return value[k];
}

list_0$*
list_0$::getSlice(int L, int U) {
    int s = size();
    if (L >= U || L >= s) {
        return new list_0$();
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
    list_0$* res = new list_0$();
    for (int i = L; i < U; i++) {
        res->push(getItem(i));
    }
    return res;
}

string
list_0$::toString(bool contained) {
    stringstream ss;
    ss << "[";
    int s = size();
    for (int i = 0; i < s - 1; i++) {
        ss << getItem(i)->toString(true) << ", ";
    }
    if (s > 0)
        ss << getItem(s-1)->toString(true);
    ss << "]";
    return ss.str();
}


/* Class tuple_0$ */

string
tuple_0$::className() {
    stringstream ss;
    ss << "tuple";
    ss << size();
    return ss.str();
}

string
tuple_0$::toString(bool contained) {
    int s = size();
    stringstream ss;
    ss << "(";
    if (s == 1)
        ss << getItem(0)->toString(true) << ",";
    else if (s > 1)
        ss << getItem(0)->toString(true);
    for (int i = 1; i < s; i++) {
        ss << ", "<< getItem(i)->toString(true);
    }
    ss << ")";
    return ss.str();
}

/* Class dict_0$ and its subclasses */

// dict with int as key
$Object*
dict_int_0$::get(void* dictKey) {
    int key = ((int_0$*) dictKey)->getValue();
    return value[key];
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
$Object*
dict_str_0$::get(void* dictKey) {
    string key = ((str_0$*) dictKey)->getValue();
    return value[key];
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
$Object*
dict_bool_0$::get(void* dictKey) {
    bool key = ((bool_0$*) dictKey)->getValue();
    return value[key];
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


/* Allocators for list_0$, tuple_0$, and dict_0$ */
tuple_0$*
__tuple0__() {
    return new tuple_0$();
}

tuple_0$*
__tuple1__(void* x) {
    tuple_0$* res = new tuple_0$(1);
    res->push(($Object*)x);
    return res;
}

tuple_0$*
__tuple2__(void* x, void* y) {
    tuple_0$* res = new tuple_0$(2);
    res->push(($Object*)x);
    res->push(($Object*)y);
    return res;
}

tuple_0$*
__tuple3__(void* x, void* y, void* z) {
    tuple_0$* res = new tuple_0$(3);
    res->push(($Object*)x);
    res->push(($Object*)y);
    res->push(($Object*)z);
    return res;
}

list_0$*
__list__empty__() {
    return new list_0$();
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
    return res;
}

dict_int_0$*
__dict__empty__int__() {
    return new dict_int_0$();
}

dict_str_0$*
__dict__empty__str__() {
    return new dict_str_0$();
}

dict_bool_0$*
__dict__empty__bool__() {
    return new dict_bool_0$();
}

dict_int_0$*
__dict__int__(void* count, void* x, ...) {
    int argcount = ((int_0$*) count)->getValue();
    dict_int_0$* res = new dict_int_0$();

    va_list arguments;
    va_start (arguments, x);

    int_0$* key;

    for (int i = 0; i < argcount; i++) {
        key = va_arg(arguments, int_0$*);
        res->set(key, va_arg (arguments, $Object*));
    }

    va_end (arguments);
    return res;
}

dict_str_0$*
__dict__str__(void* count, void* x, ...) {
    int argcount = ((int_0$*) count)->getValue();
    dict_str_0$* res = new dict_str_0$();

    va_list arguments;
    va_start (arguments, x);

    str_0$* key;

    for (int i = 0; i < argcount; i++) {
        key = va_arg(arguments, str_0$*);
        res->set(key, va_arg (arguments, $Object*));
    }

    va_end (arguments);
    return res;
}

dict_bool_0$*
__dict__bool__(void* count, void* x, ...) {
    int argcount = ((int_0$*) count)->getValue();
    dict_bool_0$* res = new dict_bool_0$();

    va_list arguments;
    va_start (arguments, x);

    bool_0$* key;

    for (int i = 0; i < argcount; i++) {
        key = va_arg(arguments, bool_0$*);
        res->set(key, va_arg (arguments, $Object*));
    }

    va_end (arguments);
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

range_0$*
__xrange__(void* low, void* high) {
    int start = ((int_0$*)low)->getValue();
    int end = ((int_0$*)high)->getValue();
    if (end < start)
        end = start;
    return new range_0$(start, end);
}

int_0$*
__len__range__(void* r) {
    int rLen = ((range_0$*) r)->size();
    return new int_0$(rLen);
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
    return new int_0$(((str_0$*) s)->size());
}

str_0$*
__tostr__(void* x) {
    string str = (($Object*)x)->toString();
    return new str_0$();
}


// Type list

$Object*
__getitem__list__(void* S, void* k) {
    int index = ((int_0$*) k)->getValue();
    return ((list_0$*) S)->getItem(index);
}

list_0$*
__getslice__list__(void* S, void* L, void* U) {
    int l = ((int_0$*) L)->getValue();
    int u = ((int_0$*) U)->getValue();
    return ((list_0$*) S)->getSlice(l, u);
}

int_0$*
__len__list__(void* S) {
    int s = ((list_0$*) S)->size();
    return new int_0$(s);
}

list_0$*
__argv__() {
    list_0$* res = new list_0$();
    for (int i = 0; i < argcount; i++) {
        res->push(new str_0$(args[i]));
    }
    return res;
}


// Type dict

$Object*
__getitem__dict__int__(void* D, void* x) {
    return ((dict_int_0$*) D)->get(x);
}

$Object*
__getitem__dict__str__(void* D, void* x) {
    return ((dict_str_0$*) D)->get(x);
}

$Object*
__getitem__dict__bool__(void* D, void* x) {
    return ((dict_bool_0$*) D)->get(x);
}

int_0$*
__len__dict__(void* D) {
    int s = ((dict_0$*) D)->size();
    return new int_0$(s);
}

bool_0$*
__contains__dict__(void* x, void* D) {
    bool b = ((dict_0$*) D)->contains(x);
    return new bool_0$(b);
}

bool_0$*
__notcontains__dict__(void* x, void* D) {
    bool b = ((dict_0$*) D)->contains(x);
    return new bool_0$((b ? false : true));
}


int main()
{
    int failures = 0;
    bool success;

    cout << "Testing classes:" << endl;

    cout << "    class bool_0$: ";
    bool_0$ BoolT(true);
    bool_0$* Bool = &BoolT;
    success = true;
    success = (Bool->toString() == "True") ? success : false;
    Bool->setValue(false);
    success = (Bool->toString() == "False") ? success : false;
    success = (Bool->getValue() == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    class int_0$: ";
    int_0$ xT(12), yT;
    int_0$* x = &xT;
    int_0$* y = &yT;
    success = true;
    success = (x->getValue() == 12) ? success : false;
    success = (y->getValue() == 0) ? success : false;
    y->setValue(100);
    success = (y->toString() == "100") ? success: false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    class str_0$: ";
    str_0$ aT("Hello"), bT;
    str_0$* a = &aT;
    str_0$* b = &bT;
    success = true;
    success = (a->getValue() == "Hello") ? success : false;
    success = (b->getValue() == "") ? success : false;
    b->setValue("lol");
    success = (b->toString() == "lol") ? success: false;
    success = (a->toString() == "Hello") ? success: false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    class range_0$: ";
    range_0$ rT;
    range_0$* r = &rT;
    success = true;
    success = (r->getLow() == 0 && r->getHigh() == 0) ? success : false;
    success = (r->toString() == "range(0)") ? success : false;
    r->setHigh(10);
    success = (r->getLow() == 0 && r->getHigh() == 10) ? success : false;
    success = (r->toString() == "range(10)") ? success : false;
    r->setLow(1);
    success = (r->getLow() == 1 && r->getHigh() == 10) ? success : false;
    success = (r->toString() == "range(1, 10)") ? success : false;
    r->setLow(10);
    success = (r->getLow() == 10 && r->getHigh() == 10) ? success : false;
    success = (r->toString() == "range(10, 10)") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    class list_0$: ";
    list_0$ lT;
    list_0$* l = &lT;
    success = true;
    success = (l->size() == 0) ? success : false;
    success = (l->toString() == "[]") ? success : false;
    l->push(new int_0$(1));
    success = (l->toString() == "[1]") ? success : false;
    l->push(new int_0$(2));
    success = (l->toString() == "[1, 2]") ? success : false;
    l->push(new int_0$(3));
    success = (l->size() == 3) ? success : false;
    success = (l->toString() == "[1, 2, 3]") ? success : false;
    success = (((int_0$*)l->getItem(0))->getValue() == 1) ? success : false;
    success = (((int_0$*)l->getItem(1))->getValue() == 2) ? success : false;
    success = (((int_0$*)l->getItem(2))->getValue() == 3) ? success : false;
    success = (((int_0$*)l->getItem(-2))->getValue() == 2) ? success : false;
    l->setItem(1, new int_0$(10));
    success = (((int_0$*)l->getItem(1))->getValue() == 10) ? success : false;
    success = (l->toString() == "[1, 10, 3]") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    class tuple_0$: ";
    tuple_0$ t0T, t1T(1), t3T(3);
    tuple_0$* t0 = &t0T;
    tuple_0$* t1 = &t1T;
    tuple_0$* t3 = &t3T;
    success = true;
    success = (t0->size() == 0) ? success : false;
    success = (t0->toString() == "()") ? success : false;
    t1->push(new str_0$("1-element tuple"));
    success = (t1->size() == 1) ? success : false;
    success = (t1->toString() == "(\"1-element tuple\",)") ? success : false;
    t3->push(new str_0$("Hi"));
    t3->push(new int_0$(15));
    l->clear();
    l->push(new int_0$(1));
    l->push(new int_0$(2));
    t3->push(l);
    success = (t3->size() == 3) ? success : false;
    success = (t3->toString() == "(\"Hi\", 15, [1, 2])") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    class dict_0$: ";
    dict_int_0$ diT;
    dict_0$* d = &diT;
    success = true;
    success = (d->toString() == "{}") ? success : false;
    success = (d->size() == 0) ? success : false;
    d->set(new int_0$(1), new str_0$("hi"));
    d->set(new int_0$(2), new str_0$("hello"));
    success = (d->size() == 2) ? success : false;
    success = (d->toString() == "{1: \"hi\", 2: \"hello\"}") ? success : false;
    success = ((d->get(new int_0$(2)))->toString() == "hello") ? success : false;
    dict_str_0$ dsT;
    d = &dsT;
    success = (d->toString() == "{}") ? success : false;
    success = (d->size() == 0) ? success : false;
    d->set(new str_0$("hi"), new bool_0$(true));
    success = (d->toString() == "{\"hi\": True}") ? success : false;
    success = (d->size() == 1) ? success : false;
    success = ((d->get(new str_0$("hi")))->toString() == "True") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;
    cout << "\nTesting allocators for list, tuple, and dict:" << endl;
    cout << "    allocator for tuple: ";
    success = true;
    success = (__tuple0__()->size() == 0) ? success : false;
    x->setValue(15);
    success = (__tuple1__(x)->toString() == "(15,)") ? success : false;
    a->setValue("LOL");
    Bool->setValue(true);
    success = (__tuple3__(x, a, Bool)->toString() == "(15, \"LOL\", True)") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    allocator for list: ";
    success = true;
    success = (__list__empty__()->size() == 0) ? success : false;
    success = (__list__empty__()->toString() == "[]") ? success : false;
    x->setValue(0);
    success = (__list__(x, x)->toString() == "[0]") ? success : false;
    x->setValue(2);
    a->setValue("LOL");
    b->setValue("Hi");
    success = (__list__(x, a, b, new str_0$("yes"))->toString() == "[\"LOL\", \"Hi\", \"yes\"]") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    allocator for dict: ";
    success = true;
    success = (__dict__empty__int__()->size() == 0) ? success : false;
    success = (__dict__empty__int__()->toString() == "{}") ? success : false;
    success = (__dict__empty__str__()->size() == 0) ? success : false;
    success = (__dict__empty__str__()->toString() == "{}") ? success : false;
    success = (__dict__empty__bool__()->size() == 0) ? success : false;
    success = (__dict__empty__bool__()->toString() == "{}") ? success : false;
    d = __dict__empty__bool__();
    d->set(new bool_0$(false), new int_0$(9));
    success = (d->toString() == "{False: 9}") ? success : false;
    x->setValue(2);
    d = __dict__str__(x, x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
    success = (d->toString() == "{\"One\": 1, \"Two\": 2}") ? success : false;
    x->setValue(1);
    d = __dict__int__(x, x, new int_0$(1), new int_0$(1));
    success = (d->toString() == "{1: 1}") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "\nTesting runtime routines for bool, int, and misc.:" << endl;
    cout << "    __donotcall___:  ";
    try {
        void* x = 0;
        __donotcall__(x);
        cout << "failed" << endl;
        failures++;
    } catch (...) {
        cout << "passes" << endl;
    }


    cout << "    __truth__:  ";
    Bool->setValue(true);
    success = true;
    success = (__truth__(Bool)->getValue()) ? success : false;
    Bool->setValue(false);
    success = (__truth__(Bool)->getValue() == false) ? success : false;
    x->setValue(1);
    success = (__truth__(x)->getValue()) ? success : false;
    x->setValue(0);
    success = (__truth__(x)->getValue() == false) ? success : false;
    a->setValue("Hi");
    success = (__truth__(a)->getValue()) ? success : false;
    a->setValue("");
    success = (__truth__(a)->getValue() == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __not__:  ";
    Bool->setValue(true);
    success = true;
    success = (__not__(Bool)->getValue() == false) ? success : false;
    Bool->setValue(false);
    success = (__not__(Bool)->getValue()) ? success : false;
    x->setValue(1);
    success = (__not__(x)->getValue() == false) ? success : false;
    x->setValue(0);
    success = (__not__(x)->getValue()) ? success : false;
    a->setValue("Hi");
    success = (__not__(a)->getValue() == false) ? success : false;
    a->setValue("");
    success = (__not__(a)->getValue()) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __add__int__: ";
    success = true;
    x->setValue(1);
    y->setValue(2);
    success = (__add__int__(x, y)->getValue() == 3) ? success : false;
    success = (__add__int__(y, y)->getValue() == 4) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __sub__int__: ";
    success = true;
    x->setValue(10);
    y->setValue(8);
    success = (__sub__int__(x, y)->getValue() == 2) ? success : false;
    success = (__sub__int__(y, y)->getValue() == 0) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __mul__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__mul__int__(x, y)->getValue() == 20) ? success : false;
    success = (__mul__int__(y, y)->getValue() == 16) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __floordiv__int__:  ";
    success = true;
    x->setValue(5);
    y->setValue(2);
    success = (__floordiv__int__(x, y)->getValue() == 2) ? success : false;
    x->setValue(10);
    y->setValue(2);
    success = (__floordiv__int__(x, y)->getValue() == 5) ? success : false;
    x->setValue(11);
    y->setValue(3);
    success = (__floordiv__int__(x, y)->getValue() == 3) ? success : false;
    x->setValue(15);
    y->setValue(9);
    success = (__floordiv__int__(x, y)->getValue() == 1) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __mod__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__mod__int__(x, y)->getValue() == 1) ? success : false;
    success = (__mod__int__(y, y)->getValue() == 0) ? success : false;
    x->setValue(38);
    y->setValue(7);
    success = (__mod__int__(x, y)->getValue() == 3) ? success : false;
    success = (__mod__int__(y, x)->getValue() == 7) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __pow__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__pow__int__(x, y)->getValue() == 625) ? success : false;
    success = (__pow__int__(y, y)->getValue() == 256) ? success : false;
    x->setValue(2);
    y->setValue(3);
    success = (__pow__int__(x, y)->getValue() == 8) ? success : false;
    success = (__pow__int__(y, x)->getValue() == 9) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __neg__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__neg__int__(x)->getValue() == -5) ? success : false;
    success = (__neg__int__(y)->getValue() == -4) ? success : false;
    x->setValue(-10);
    y->setValue(-3);
    success = (__neg__int__(x)->getValue() == 10) ? success : false;
    success = (__neg__int__(y)->getValue() == 3) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __pos__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__pos__int__(x)->getValue() == 5) ? success : false;
    success = (__pos__int__(y)->getValue() == 4) ? success : false;
    x->setValue(-10);
    y->setValue(-3);
    success = (__pos__int__(x)->getValue() == -10) ? success : false;
    success = (__pos__int__(y)->getValue() == -3) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __lt__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__lt__int__(x, y)->getValue() == false) ? success : false;
    success = (__lt__int__(y, y)->getValue() == false) ? success : false;
    success = (__lt__int__(y, x)->getValue() == true) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __ge__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__ge__int__(x, y)->getValue() == true) ? success : false;
    success = (__ge__int__(y, y)->getValue() == true) ? success : false;
    success = (__ge__int__(y, x)->getValue() == false) ? success : false;
    x->setValue(10);
    y->setValue(10);
    success = (__ge__int__(x, y)->getValue() == true) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __eq__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__eq__int__(x, y)->getValue() == false) ? success : false;
    success = (__eq__int__(y, y)->getValue() == true) ? success : false;
    y->setValue(5);
    success = (__eq__int__(y, x)->getValue() == true) ? success : false;
    success = (__eq__int__(x, y)->getValue() == true) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __ne__int__: ";
    success = true;
    x->setValue(5);
    y->setValue(4);
    success = (__ne__int__(x, y)->getValue() == true) ? success : false;
    success = (__ne__int__(y, y)->getValue() == false) ? success : false;
    y->setValue(5);
    success = (__ne__int__(y, x)->getValue() == false) ? success : false;
    success = (__ne__int__(x, y)->getValue() == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "    __toint__str__:  ";
    success = true;
    a->setValue("125");
    success = (__toint__str__(a)->getValue() == 125) ? success : false;
    a->setValue("0");
    success = (__toint__str__(a)->getValue() == 0) ? success : false;
    a->setValue("10");
    success = (__toint__str__(a)->getValue() == 10) ? success : false;
    a->setValue("895629");
    success = (__toint__str__(a)->getValue() == 895629) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "\nTesting runtime routines for string:" << endl;

    cout << "    __add__str__:  ";
    success = true;
    a->setValue("hi");
    b->setValue(" you");
    success = (__add__str__(a, b)->getValue() == "hi you") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "    __lmul__str__:  ";
    success = true;
    a->setValue("hi");
    x->setValue(3);
    success = (__lmul__str__(a, x)->getValue() == "hihihi") ? success : false;
    x->setValue(2);
    success = (__lmul__str__(a, x)->getValue() == "hihi") ? success : false;
    x->setValue(6);
    success = (__lmul__str__(a, x)->getValue() == "hihihihihihi") ? success : false;
    x->setValue(1);
    success = (__lmul__str__(a, x)->getValue() == "hi") ? success : false;
    x->setValue(0);
    success = (__lmul__str__(a, x)->getValue() == "") ? success : false;
    x->setValue(1);
    success = (__lmul__str__(a, -(*x))->getValue() == "") ? success : false;
    x->setValue(6);
    success = (__lmul__str__(a, -(*x))->getValue() == "") ? success : false;
    a->setValue("you ");
    x->setValue(3);
    success = (__lmul__str__(a, x)->getValue() == "you you you ") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __rmul__str__:  ";
    success = true;
    a->setValue("hi");
    x->setValue(3);
    success = (__rmul__str__(x, a)->getValue() == "hihihi") ? success : false;
    x->setValue(2);
    success = (__rmul__str__(x, a)->getValue() == "hihi") ? success : false;
    x->setValue(6);
    success = (__rmul__str__(x, a)->getValue() == "hihihihihihi") ? success : false;
    x->setValue(1);
    success = (__rmul__str__(x, a)->getValue() == "hi") ? success : false;
    x->setValue(0);
    success = (__rmul__str__(x, a)->getValue() == "") ? success : false;
    x->setValue(1);
    success = (__rmul__str__(-(*x), a)->getValue() == "") ? success : false;
    x->setValue(6);
    success = (__rmul__str__(-(*x), a)->getValue() == "") ? success : false;
    a->setValue("you ");
    x->setValue(3);
    success = (__rmul__str__(x, a)->getValue() == "you you you ") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __eq__str__: ";
    success = true;
    a->setValue("Hi");
    b->setValue("Hello");
    success = (__eq__str__(a, b)->getValue() == false) ? success : false;
    success = (__eq__str__(b, b)->getValue() == true) ? success : false;
    b->setValue("Hi");
    success = (__eq__str__(b, a)->getValue() == true) ? success : false;
    success = (__eq__str__(a, b)->getValue() == true) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __ne__str__: ";
    success = true;
    a->setValue("Hi");
    b->setValue("Hello");
    success = (__ne__str__(a, b)->getValue() == true) ? success : false;
    success = (__ne__str__(b, b)->getValue() == false) ? success : false;
    b->setValue("Hi");
    success = (__ne__str__(b, a)->getValue() == false) ? success : false;
    success = (__ne__str__(a, b)->getValue() == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __getitem__str__: ";
    success = true;
    a->setValue("abcdefg");
    x->setValue(0);
    success = (__getitem__str__(a, x)->getValue() == "a") ? success : false;
    x->setValue(1);
    success = (__getitem__str__(a, x)->getValue() == "b") ? success : false;
    x->setValue(6);
    success = (__getitem__str__(a, x)->getValue() == "g") ? success : false;
    x->setValue(-1);
    success = (__getitem__str__(a, x)->getValue() == "g") ? success : false;
    x->setValue(-3);
    success = (__getitem__str__(a, x)->getValue() == "e") ? success : false;
    x->setValue(-7);
    success = (__getitem__str__(a, x)->getValue() == "a") ? success : false;
    try {
        x->setValue(7);
        __getitem__str__(a, x);
        success = false;
    }  catch (...) {}
    try {
        x->setValue(-8);
        __getitem__str__(a, x);
        success = false;
    }  catch (...) {}
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __getslice__str__: ";
    success = true;
    a->setValue("abcdefg");
    x->setValue(0);
    y->setValue(1);
    success = (__getslice__str__(a, x, y)->getValue() == "a") ? success : false;
    y->setValue(2);
    success = (__getslice__str__(a, x, y)->getValue() == "ab") ? success : false;
    y->setValue(7);
    success = (__getslice__str__(a, x, y)->getValue() == "abcdefg") ? success : false;
    y->setValue(-1);
    success = (__getslice__str__(a, x, y)->getValue() == "abcdef") ? success : false;
    y->setValue(6);
    success = (__getslice__str__(a, x, y)->getValue() == "abcdef") ? success : false;
    x->setValue(2);
    y->setValue(5);
    success = (__getslice__str__(a, x, y)->getValue() == "cde") ? success : false;
    y->setValue(-3);
    success = (__getslice__str__(a, x, y)->getValue() == "cd") ? success : false;
    y->setValue(9);
    success = (__getslice__str__(a, x, y)->getValue() == "cdefg") ? success : false;
    y->setValue(2);
    success = (__getslice__str__(a, x, y)->getValue() == "") ? success : false;
    y->setValue(1);
    success = (__getslice__str__(a, x, y)->getValue() == "") ? success : false;
    y->setValue(0);
    success = (__getslice__str__(a, x, y)->getValue() == "") ? success : false;
    y->setValue(-6);
    success = (__getslice__str__(a, x, y)->getValue() == "") ? success : false;
    y->setValue(-7);
    success = (__getslice__str__(a, x, y)->getValue() == "") ? success : false;
    y->setValue(-8);
    success = (__getslice__str__(a, x, y)->getValue() == "") ? success : false;
    try {
        x->setValue(7);
        __getslice__str__(a, x, y);
        success = false;
    }  catch (...) {}
    try {
        x->setValue(-8);
        __getslice__str__(a, x, y);
        success = false;
    }  catch (...) {}
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __len__str__:  ";
    success = true;
    a->setValue("hi");
    success = (__len__str__(a)->getValue() == 2) ? success : false;
    a->setValue("ABCDEFG");
    success = (__len__str__(a)->getValue() == 7) ? success : false;
    a->setValue("");
    success = (__len__str__(a)->getValue() == 0) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "\nTesting runtime routines for range:" << endl;

    cout << "    __xrange__:  ";
    success = true;
    x->setValue(0);
    y->setValue(0);
    success = (__xrange__(x, y)->toString() == "range(0)") ? success : false;
    y->setValue(10);
    success = (__xrange__(x, y)->toString() == "range(10)") ? success : false;
    x->setValue(2);
    success = (__xrange__(x, y)->toString() == "range(2, 10)") ? success : false;
    y->setValue(1);
    success = (__xrange__(x, y)->toString() == "range(2, 2)") ? success : false;
    x->setValue(0);
    y->setValue(-1);
    success = (__xrange__(x, y)->toString() == "range(0)") ? success : false;
    x->setValue(-6);
    y->setValue(-1);
    success = (__xrange__(x, y)->toString() == "range(-6, -1)") ? success : false;
    y->setValue(-10);
    success = (__xrange__(x, y)->toString() == "range(-6, -6)") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;    


    cout << "    __len__range__:  ";
    success = true;
    r->setLow(0);
    r->setHigh(0);
    success = (__len__range__(r)->getValue() == 0) ? success : false;
    r->setHigh(7);
    success = (__len__range__(r)->getValue() == 7) ? success : false;
    r->setLow(7);
    success = (__len__range__(r)->getValue() == 0) ? success : false;
    r->setLow(-3);
    r->setHigh(0);
    success = (__len__range__(r)->getValue() == 3) ? success : false;
    r->setHigh(-1);
    success = (__len__range__(r)->getValue() == 2) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;



    cout << "\nTesting runtime routines for list:" << endl;

    cout << "    __len__list__:  ";
    success = true;
    l->clear();
    success = (__len__list__(l)->getValue() == 0) ? success : false;
    l->push(new str_0$());
    l->push(new str_0$("Hi"));
    success = (__len__list__(l)->getValue() == 2) ? success : false;
    l->push(new str_0$("Hello"));
    success = (__len__list__(l)->getValue() == 3) ? success : false;
    success = (l->toString() == "[\"\", \"Hi\", \"Hello\"]") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __getitem__list__:  ";
    success = true;
    x->setValue(0);
    success = (((str_0$*)__getitem__list__(l, x))->getValue() == "") ? success : false;
    x->setValue(1);
    success = (((str_0$*)__getitem__list__(l, x))->getValue() == "Hi") ? success : false;
    x->setValue(-1);
    success = (((str_0$*)__getitem__list__(l, x))->getValue() == "Hello") ? success : false;
    x->setValue(-3);
    success = (((str_0$*)__getitem__list__(l, x))->getValue() == "") ? success : false;
    try {
        x->setValue(-4);
        __getitem__list__(l, x);
        success = false;
    } catch (...) {}
    try {
        x->setValue(3);
        __getitem__list__(l, x);
        success = false;
    } catch (...) {}
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __getslice__list__:  ";
    success = true;
    l->clear();
    l->push(new int_0$(1));
    l->push(new int_0$(2));
    l->push(new int_0$(3));
    l->push(new int_0$(4));
    l->push(new int_0$(5));
    x->setValue(0);
    y->setValue(2);
    success = (l->size() == 5) ? success : false;
    success = ((__getslice__list__(l, x, y))->size() == 2) ? success : false;
    success = ((__getslice__list__(l, x, y))->toString() == "[1, 2]") ? success : false;
    x->setValue(-5);
    success = ((__getslice__list__(l, x, y))->toString() == "[1, 2]") ? success : false;
    x->setValue(-6);
    success = ((__getslice__list__(l, x, y))->toString() == "[1, 2]") ? success : false;
    y->setValue(-2);
    success = ((__getslice__list__(l, x, y))->toString() == "[1, 2, 3]") ? success : false;
    x->setValue(2);
    y->setValue(3);
    success = ((__getslice__list__(l, x, y))->toString() == "[3]") ? success : false;
    y->setValue(2);
    success = ((__getslice__list__(l, x, y))->toString() == "[]") ? success : false;
    y->setValue(1);
    success = ((__getslice__list__(l, x, y))->toString() == "[]") ? success : false;
    x->setValue(5);
    y->setValue(6);
    success = ((__getslice__list__(l, x, y))->toString() == "[]") ? success : false;
    x->setValue(7);
    y->setValue(10);
    success = ((__getslice__list__(l, x, y))->toString() == "[]") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;



    cout << "\nTesting runtime routines for list:" << endl;

    cout << "    __getitem__dict__:  ";
    success = true;
    x->setValue(2);
    d = __dict__str__(x, x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
    success = (__getitem__dict__str__(d, new str_0$("Two"))->toString() == "2") ? success : false;
    x->setValue(3);
    d = __dict__int__(x, x, new int_0$(1), new int_0$(1), new int_0$(2), new int_0$(2), new int_0$(3), new int_0$(3));
    success = (__getitem__dict__int__(d, new int_0$(2))->toString() == "2") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __len__dict__:  ";
    success = true;
    x->setValue(2);
    d = __dict__str__(x, x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
    success = (__len__dict__(d)->getValue() == 2) ? success : false;
    d->set(new str_0$(""), new int_0$(0));
    success = (__len__dict__(d)->getValue() == 3) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "    __contains__dict__:  ";
    success = true;
    success = (__contains__dict__(new str_0$("Two"), d)->getValue() == true) ? success : false;
    success = (__contains__dict__(new str_0$("Three"), d)->getValue() == false) ? success : false;
    x->setValue(2);
    d = __dict__int__(x, x, new int_0$(1), new int_0$(1), new int_0$(2), new int_0$(2));
    success = (__contains__dict__(new int_0$(1), d)->getValue() == true) ? success : false;
    success = (__contains__dict__(new int_0$(-1), d)->getValue() == false) ? success : false;
    x->setValue(1);
    d = __dict__bool__(x, x, new bool_0$(false), new int_0$(1));
    success = (__contains__dict__(new bool_0$(false), d)->getValue() == true) ? success : false;
    success = (__contains__dict__(new bool_0$(true), d)->getValue() == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __notcontains__dict__:  ";
    success = true;
    x->setValue(2);
    d = __dict__str__(x, x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
    success = (__notcontains__dict__(new str_0$("Two"), d)->getValue() == false) ? success : false;
    success = (__notcontains__dict__(new str_0$("Three"), d)->getValue() == true) ? success : false;
    x->setValue(2);
    d = __dict__int__(x, x, new int_0$(1), new int_0$(1), new int_0$(2), new int_0$(2));
    success = (__notcontains__dict__(new int_0$(1), d)->getValue() == false) ? success : false;
    success = (__notcontains__dict__(new int_0$(-1), d)->getValue() == true) ? success : false;
    x->setValue(1);
    d = __dict__bool__(x, x, new bool_0$(false), new int_0$(1));
    success = (__notcontains__dict__(new bool_0$(false), d)->getValue() == false) ? success : false;
    success = (__notcontains__dict__(new bool_0$(true), d)->getValue() == true) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    if (failures == 0)
        cout << "\nAll tests passed, HORAY" << endl;
    else
        cout << "\n" << failures << " tests failed, BOO" << endl;

    return 0;
}

