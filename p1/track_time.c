#include <stdio.h>
#include <time.h>
#include "algorithm.c"

int main(int argc, char *argv[]) {
    argc = 2;

    clock_t start = clock();
    algorithm(*argv[0]-'0', *argv[1]-'0');
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution Time:%f\n", time_spent);
    return 0;
}