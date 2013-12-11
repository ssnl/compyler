#include "runtime.h"


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
    d = __dict__str__(x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
    success = (d->toString() == "{\"One\": 1, \"Two\": 2}") ? success : false;
    x->setValue(1);
    d = __dict__int__(x, new int_0$(1), new int_0$(1));
    success = (d->toString() == "{1: 1}") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "\nTesting miscellaneous runtime routines:" << endl;
    cout << "    __donotcall___:  ";
    try {
        void* x = 0;
        __donotcall__(x);
        cout << "failed" << endl;
        failures++;
    } catch (...) {
        cout << "passes" << endl;
    }


    cout << "    __None__:  ";
    success = true;
    success = (__None__()->getValue() == 0) ? success : false;
    success = (__None__()->className() == "int") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __is__:  ";
    success = true;
    success = (__is__(new int_0$(2), new int_0$(2))->getValue() == true) ? success : false;
    success = (__is__(new int_0$(2), new int_0$(3))->getValue() == false) ? success : false;
    success = (__is__(new str_0$("hi"), new str_0$("hi"))->getValue() == true) ? success : false;
    success = (__is__(new str_0$("hi"), new str_0$("hello"))->getValue() == false) ? success : false;
    success = (__is__(new bool_0$(true), new bool_0$(true))->getValue() == true) ? success : false;
    success = (__is__(new bool_0$(true), new bool_0$(false))->getValue() == false) ? success : false;
    success = (__is__(new list_0$(), new list_0$())->getValue() == false) ? success : false;
    l->clear();
    list_0$* l2 = l;
    success = (__is__(l, l2)->getValue() == true) ? success : false;
    x->setValue(10);
    l->push(x);
    l2 = new list_0$();
    l2->push(x);
    success = (__is__(l, l2)->getValue() == false) ? success : false;
    l2->clear();
    l2->push(new int_0$(10));
    success = (__is__(l, l2)->getValue() == false) ? success : false;
    l2->push(new int_0$(2));
    x->setValue(1);
    success = (__is__(__getitem__list__(l2, x), __getitem__list__(l2, x))->getValue() == true) ? success : false;
    success = (__is__(__getitem__list__(l2, x), __getitem__list__(l2, new int_0$(1)))->getValue() == true) ? success : false;
    x->setValue(0);
    y->setValue(2);
    success = (__is__(__getslice__list__(l2, x, y), __getslice__list__(l2, x, y))->getValue() == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __isnot__:  ";
    success = true;
    success = (__isnot__(new int_0$(2), new int_0$(2))->getValue() == false) ? success : false;
    success = (__isnot__(new int_0$(2), new int_0$(3))->getValue() == true) ? success : false;
    success = (__isnot__(new str_0$("hi"), new str_0$("hi"))->getValue() == false) ? success : false;
    success = (__isnot__(new str_0$("hi"), new str_0$("hello"))->getValue() == true) ? success : false;
    success = (__isnot__(new bool_0$(true), new bool_0$(true))->getValue() == false) ? success : false;
    success = (__isnot__(new bool_0$(true), new bool_0$(false))->getValue() == true) ? success : false;
    success = (__isnot__(new list_0$(), new list_0$())->getValue() == true) ? success : false;
    l->clear();
    l2 = l;
    success = (__isnot__(l, l2)->getValue() == false) ? success : false;
    x->setValue(10);
    l->push(x);
    l2 = new list_0$();
    l2->push(x);
    success = (__isnot__(l, l2)->getValue() == true) ? success : false;
    l2->clear();
    l2->push(new int_0$(10));
    success = (__isnot__(l, l2)->getValue() == true) ? success : false;
    l2->push(new int_0$(2));
    x->setValue(1);
    success = (__isnot__(__getitem__list__(l2, x), __getitem__list__(l2, x))->getValue() == false) ? success : false;
    success = (__isnot__(__getitem__list__(l2, x), __getitem__list__(l2, new int_0$(1)))->getValue() == false) ? success : false;
    x->setValue(0);
    y->setValue(2);
    success = (__isnot__(__getslice__list__(l2, x, y), __getslice__list__(l2, x, y))->getValue() == true) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "\nTesting runtime routines for bool:" << endl;

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


    cout << "\nTesting runtime routines for int:" << endl;

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

    cout << "    __tostr__:  ";
    success = true;
    x->setValue(100);
    success = (__tostr__(x)->getValue() == "100") ? success : false;
    a->setValue("World");
    success = (__tostr__(a)->getValue() == "World") ? success : false;
    l->clear();
    l->push(new int_0$(1));
    l->push(new int_0$(2));
    l->push(new int_0$(3));
    success = (__tostr__(l)->getValue() == "[1, 2, 3]") ? success : false;
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
    d = __dict__str__(x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
    success = (__getitem__dict__str__(d, new str_0$("Two"))->toString() == "2") ? success : false;
    x->setValue(3);
    d = __dict__int__(x, new int_0$(1), new int_0$(1), new int_0$(2), new int_0$(2), new int_0$(3), new int_0$(3));
    success = (__getitem__dict__int__(d, new int_0$(2))->toString() == "2") ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __len__dict__:  ";
    success = true;
    x->setValue(2);
    d = __dict__str__(x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
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
    d = __dict__int__(x, new int_0$(1), new int_0$(1), new int_0$(2), new int_0$(2));
    success = (__contains__dict__(new int_0$(1), d)->getValue() == true) ? success : false;
    success = (__contains__dict__(new int_0$(-1), d)->getValue() == false) ? success : false;
    x->setValue(1);
    d = __dict__bool__(x, new bool_0$(false), new int_0$(1));
    success = (__contains__dict__(new bool_0$(false), d)->getValue() == true) ? success : false;
    success = (__contains__dict__(new bool_0$(true), d)->getValue() == false) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __notcontains__dict__:  ";
    success = true;
    x->setValue(2);
    d = __dict__str__(x, new str_0$("One"), new int_0$(1), new str_0$("Two"), new int_0$(2));
    success = (__notcontains__dict__(new str_0$("Two"), d)->getValue() == false) ? success : false;
    success = (__notcontains__dict__(new str_0$("Three"), d)->getValue() == true) ? success : false;
    x->setValue(2);
    d = __dict__int__(x, new int_0$(1), new int_0$(1), new int_0$(2), new int_0$(2));
    success = (__notcontains__dict__(new int_0$(1), d)->getValue() == false) ? success : false;
    success = (__notcontains__dict__(new int_0$(-1), d)->getValue() == true) ? success : false;
    x->setValue(1);
    d = __dict__bool__(x, new bool_0$(false), new int_0$(1));
    success = (__notcontains__dict__(new bool_0$(false), d)->getValue() == false) ? success : false;
    success = (__notcontains__dict__(new bool_0$(true), d)->getValue() == true) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;


    cout << "\nTesting runtime routines for file:" << endl;
    cout << "    __open1__, __open2__, __readline__, and __read__:  ";
    success = true;
    file_0$* f;
    FILE* fp;
    a->setValue("aTest.txt");
    b->setValue("w");
    f = __open2__(a, b);
    fp = f->getValue();
    fputs("Hello World,\nI am penguin.\nThis is Earth.\nHappy times.", fp);
    __close__(f);
    f = __open1__(a);
    success = (__readline__(f)->getValue() == "Hello World,") ? success : false;
    success = (__readline__(f)->getValue() == "I am penguin.") ? success : false;
    success = (__read__(f)->getValue() == "This is Earth.\nHappy times.") ? success : false;
    success = (__readline__(f)->getValue() == "") ? success : false;
    success = (__read__(f)->getValue() == "") ? success : false;
    __close__(f);
    b->setValue("r+");
    f = __open1__(a);
    success = (__readline__(f)->getValue() == "Hello World,") ? success : false;
    __close__(f);
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    cout << "    __standard_file__:  ";
    success = true;
    x->setValue(0);
    success = (__standard_file__(x)->getValue() == stdin) ? success : false;
    x->setValue(1);
    success = (__standard_file__(x)->getValue() == stdout) ? success : false;
    x->setValue(2);
    success = (__standard_file__(x)->getValue() == stderr) ? success : false;
    cout << (success ? "passes" : "failed") << endl;
    failures += (success) ? 0 : 1;

    if (failures == 0)
        cout << "\nAll tests passed, HORAY" << endl;
    else
        cout << "\n" << failures << " tests failed, BOO" << endl;

    return 0;
}