#include <klee/klee.h>
#include <stdio.h>
#include "algorithm.c"
int main() {
    int a = -100;
    klee_make_symbolic(&a, sizeof(a), "a");
    int b = -100;
    klee_make_symbolic(&b, sizeof(b), "b");
    int result = algorithm(a, b);
    printf("Result: %d\n", result);
    return algorithm(a, b);
}
