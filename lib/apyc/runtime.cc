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

    cout << "\nTesting runtime routines for bool, int, and string:" << endl;
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

    if (failures == 0)
        cout << "\nAll tests passed, HORAY" << endl;
    else
        cout << "\n" << failures << " tests failed, BOO" << endl;

    return 0;
}


