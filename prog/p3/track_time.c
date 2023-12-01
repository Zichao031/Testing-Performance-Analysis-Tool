#include <stdio.h>
#include <time.h>
#include "algorithm.c"

int main(int argc, char *argv[]) {
    argc = 5;
    int args[5];
    for (int i = 0; i < argc; i++) {
        args[i] = *argv[i]-'0';
    }
    clock_t start = clock();
    algorithm(args);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution Time:%f\n", time_spent);
    return 0;
}
