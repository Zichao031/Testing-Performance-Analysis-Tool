#include <stdio.h>
#include <time.h>

int algorithm(int x, int y) {
    if (x == 0 && y == 0)
        return 0;
    
    else if (x < 0 || y < 0)
        return -1;
    else if (x > 0 || y > 0)
        return 1;
    else if (x < 0) {
        return x;
    }
    else {
        return y;
    }
} 

int main(int argc, char *argv[]) {
    argc = 2;

    clock_t start = clock();
    algorithm(*argv[0]-'0', *argv[1]-'0');
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
    return 0;
}
