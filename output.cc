#include "runtime.h"

struct __None___0$ {
};

template <class T_0>
struct truth_0$ {
    T_0 x_0$;
};

template <class T_0>
struct __not___0$ {
    T_0 x_1$;
};

struct __add___0$ {
    int_0$ x_2$;
    int_0$ y_0$;
};

struct __sub___0$ {
    int_0$ x_3$;
    int_0$ y_1$;
};

struct __mul___0$ {
    int_0$ x_4$;
    int_0$ y_2$;
};

struct __floordiv___0$ {
    int_0$ x_5$;
    int_0$ y_3$;
};

struct __mod___0$ {
    int_0$ x_6$;
    int_0$ y_4$;
};

struct __pow___0$ {
    int_0$ x_7$;
    int_0$ y_5$;
};

struct __neg___0$ {
    int_0$ x_8$;
};

struct __pos___0$ {
    int_0$ x_9$;
};

struct __lt___0$ {
    int_0$ x_10$;
    int_0$ y_6$;
};

struct __gt___0$ {
    int_0$ x_11$;
    int_0$ y_7$;
};

struct __le___0$ {
    int_0$ x_12$;
    int_0$ y_8$;
};

struct __ge___0$ {
    int_0$ x_13$;
    int_0$ y_9$;
};

struct __eq___0$ {
    int_0$ x_14$;
    int_0$ y_10$;
};

struct __ne___0$ {
    int_0$ x_15$;
    int_0$ y_11$;
};

struct toint_0$ {
    str_0$ x_16$;
};

struct __add___1$ {
    str_0$ x_17$;
    str_0$ y_12$;
};

struct __mul___1$ {
    str_0$ x_18$;
    int_0$ y_13$;
};

struct __mul___2$ {
    int_0$ x_19$;
    str_0$ y_14$;
};

struct __lt___1$ {
    str_0$ x_20$;
    str_0$ y_15$;
};

struct __gt___1$ {
    str_0$ x_21$;
    str_0$ y_16$;
};

struct __le___1$ {
    str_0$ x_22$;
    str_0$ y_17$;
};

struct __ge___1$ {
    str_0$ x_23$;
    str_0$ y_18$;
};

struct __eq___1$ {
    str_0$ x_24$;
    str_0$ y_19$;
};

struct __ne___1$ {
    str_0$ x_25$;
    str_0$ y_20$;
};

struct __getitem___0$ {
    str_0$ S_0$;
    int_0$ k_0$;
};

struct __getslice___0$ {
    str_0$ S_1$;
    int_0$ L_0$;
    int_0$ U_0$;
};

struct len_0$ {
    str_0$ S_2$;
};

template <class T_0>
struct tostr_0$ {
    T_0 x_26$;
};

struct foo_0$ {
    int_0$ a;
    int_0$ b;
};

struct __main__ {
    FuncDesc __None___0$;
    FuncDesc truth_0$;
    FuncDesc __not___0$;
    bool_0$ True_0$;
    bool_0$ False_0$;
    FuncDesc __add___0$;
    FuncDesc __sub___0$;
    FuncDesc __mul___0$;
    FuncDesc __floordiv___0$;
    FuncDesc __mod___0$;
    FuncDesc __pow___0$;
    FuncDesc __neg___0$;
    FuncDesc __pos___0$;
    FuncDesc __lt___0$;
    FuncDesc __gt___0$;
    FuncDesc __le___0$;
    FuncDesc __ge___0$;
    FuncDesc __eq___0$;
    FuncDesc __ne___0$;
    FuncDesc toint_0$;
    FuncDesc __add___1$;
    FuncDesc __mul___1$;
    FuncDesc __mul___2$;
    FuncDesc __lt___1$;
    FuncDesc __gt___1$;
    FuncDesc __le___1$;
    FuncDesc __ge___1$;
    FuncDesc __eq___1$;
    FuncDesc __ne___1$;
    FuncDesc __getitem___0$;
    FuncDesc __getslice___0$;
    FuncDesc len_0$;
    FuncDesc tostr_0$;
    FuncDesc foo_0$;
    int_0$ x;
    int_0$ y;
    int_0$ z;
};



int main (int argc, char *argv[]) {

    /* runtime prologue: set up __main__ frame */
    tmp_frame = new Frame;
    tmp_frame->locals = new __main__;
    cf = tmp_frame;
    STACK.push_back(tmp_frame);


    /* x = 5 */

    /* allocating memory for: new int_0$(5) */
    tmp_alloc = new int_0$(5);
    HEAP.push_back(tmp_alloc);

    /* pushing first in HEAP onto SM */
    SM.push_back(HEAP[HEAP.size()-1]);

    /* pushing ((__main__*) cf->locals)->x onto SM */
    SM.push_back(&((__main__*) cf->locals)->x);

    /* moving second in stack to first in stack */
    dst = SM.back();
    SM.pop_back();
    src = SM.back();
    SM.pop_back();
    *(($Object*) dst) = *(($Object*) src);


    /* y = x + 3 */

    /* allocating memory for: new int_0$(3) */
    tmp_alloc = new int_0$(3);
    HEAP.push_back(tmp_alloc);

    /* pushing first in HEAP onto SM */
    SM.push_back(HEAP[HEAP.size()-1]);

    /* pushing ((__main__*) cf->locals)->x onto SM */
    SM.push_back(&((__main__*) cf->locals)->x);

    /* calling __add__int__ (2 params) */
    tmp_res = __add__int__(
        SM[SM.size()-1],
        SM[SM.size()-2]);
    SM.pop_back();
    SM.pop_back();
    SM.push_back(tmp_res);

    /* pushing ((__main__*) cf->locals)->y onto SM */
    SM.push_back(&((__main__*) cf->locals)->y);

    /* moving second in stack to first in stack */
    dst = SM.back();
    SM.pop_back();
    src = SM.back();
    SM.pop_back();
    *(($Object*) dst) = *(($Object*) src);


    /* def foo(a, b): */
    /*     return a + b */
    /* z = foo(x, y) */

    /* pushing ((__main__*) cf->locals)->y onto SM */
    SM.push_back(&((__main__*) cf->locals)->y);

    /* pushing ((__main__*) cf->locals)->x onto SM */
    SM.push_back(&((__main__*) cf->locals)->x);

    /* allocating memory for: new FuncDesc(((__main__*) cf->locals)->foo_0$) */
    tmp_alloc = new FuncDesc(((__main__*) cf->locals)->foo_0$);
    HEAP.push_back(tmp_alloc);

    /* pushing first in HEAP onto SM */
    SM.push_back(HEAP[HEAP.size()-1]);

    /* setting up static link for FuncDesc */
    ((FuncDesc*)SM[SM.size() - 1])->sl = cf;

    /* calling function */
    call = (FuncDesc*) SM.back();
    SM.pop_back();
    cf->ra = &&__R__1;
    static_link = call->sl;
    goto __foo_0$__;

__R__1:

    /* pushing ((__main__*) cf->locals)->z onto SM */
    SM.push_back(&((__main__*) cf->locals)->z);

    /* moving second in stack to first in stack */
    dst = SM.back();
    SM.pop_back();
    src = SM.back();
    SM.pop_back();
    *(($Object*) dst) = *(($Object*) src);

    cout << "TESTING: src := " << (($int_0$*)src)->value << endl;

    /* jumping to label __EXIT__ */
    goto __EXIT__;

    /* function def for foo(a,b) */
__foo_0$__:

    /* function prologue for foo_0$ */
    tmp_frame = new Frame;
    tmp_frame->sl = static_link;
    tmp_frame->locals = new foo_0$;
    cf = tmp_frame;
    STACK.push_back(tmp_frame);

    /* pushing ((foo_0$*) cf->locals)->a onto SM */
    SM.push_back(&((foo_0$*) cf->locals)->a);

    /* moving second in stack to first in stack */
    dst = SM.back();
    SM.pop_back();
    src = SM.back();
    SM.pop_back();
    *(($Object*) dst) = *(($Object*) src);

    /* pushing ((foo_0$*) cf->locals)->b onto SM */
    SM.push_back(&((foo_0$*) cf->locals)->b);

    /* moving second in stack to first in stack */
    dst = SM.back();
    SM.pop_back();
    src = SM.back();
    SM.pop_back();
    *(($Object*) dst) = *(($Object*) src);

    /* pushing ((foo_0$*) cf->locals)->a onto SM */
    SM.push_back(&((foo_0$*) cf->locals)->a);

    /* pushing ((foo_0$*) cf->locals)->b onto SM */
    SM.push_back(&((foo_0$*) cf->locals)->b);

    /* calling __add__int__ (2 params) */
    tmp_res = __add__int__(
        SM[SM.size()-1],
        SM[SM.size()-2]);
    SM.pop_back();
    SM.pop_back();
    SM.push_back(tmp_res);

    /* emitting function epilogue for foo_0$ */
    tmp_frame = STACK.back();
    STACK.pop_back();
    delete ((foo_0$*) tmp_frame->locals);
    delete tmp_frame;
    cf = STACK[STACK.size() - 1];
    goto *(cf->ra);


    /* runtime epilogue: deleting objects stored on heap */
__EXIT__:
    for (int i = 0; i < HEAP.size(); i++) {
        delete (($Object*) HEAP[i]);
    }
}
