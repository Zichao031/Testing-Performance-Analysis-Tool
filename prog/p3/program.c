#include <klee/klee.h>
#include <stdio.h>
#include "algorithm.c"


int main() {
    int arg1 = -100;
    klee_make_symbolic(&arg1, sizeof(arg1), "arg1");
    int arg2 = -100;
    klee_make_symbolic(&arg2, sizeof(arg2), "arg2");
    int arg3 = -100;
    klee_make_symbolic(&arg3, sizeof(arg3), "arg3");
    int arg4 = -100;
    klee_make_symbolic(&arg4, sizeof(arg4), "arg4");
    int arg5 = -100;
    klee_make_symbolic(&arg5, sizeof(arg5), "arg5"); 
    int args[5] = {arg1, arg2, arg3, arg4, arg5};
    return algorithm(args[5]);
}
