#include <stdio.h>

int algorithm(int arg1, int arg2, int arg3, int arg4) {
    if (arg1 > 0) {
        if (arg2 > 0) {
            if (arg3 > 0) {
                if (arg4 > 0) {
                    printf("Path 1: All arguments are positive\n");
                } else {
                    printf("Path 2: First three arguments are positive, fourth is non-positive\n");
                }
            } else {
                if (arg4 > 0) {
                    printf("Path 3: arg1, arg2 positive; arg3 non-positive; arg4 positive\n");
                } else {
                    printf("Path 4: arg1, arg2 positive; arg3, arg4 non-positive\n");
                }
            }
        } else {
            if (arg3 > 0) {
                if (arg4 > 0) {
                    printf("Path 5: arg1 positive; arg2 non-positive; arg3, arg4 positive\n");
                } else {
                    printf("Path 6: arg1, arg3 positive; arg2, arg4 non-positive\n");
                }
            } else {
                if (arg4 > 0) {
                    printf("Path 7: arg1, arg4 positive; arg2, arg3 non-positive\n");
                } else {
                    printf("Path 8: arg1 positive; arg2, arg3, arg4 non-positive\n");
                }
            }
        }
    } else {
        if (arg2 > 0) {
            if (arg3 > 0) {
                if (arg4 > 0) {
                    printf("Path 9: arg1 non-positive; arg2, arg3, arg4 positive\n");
                } else {
                    printf("Path 10: arg2, arg3 positive; arg1, arg4 non-positive\n");
                }
            } else {
                if (arg4 > 0) {
                    printf("Path 11: arg2, arg4 positive; arg1, arg3 non-positive\n");
                } else {
                    printf("Path 12: arg2 positive; arg1, arg3, arg4 non-positive\n");
                }
            }
        } else {
            if (arg3 > 0) {
                if (arg4 > 0) {
                    printf("Path 13: arg3, arg4 positive; arg1, arg2 non-positive\n");
                } else {
                    printf("Path 14: arg3 positive; arg1, arg2, arg4 non-positive\n");
                }
            } else {
                if (arg4 > 0) {
                    printf("Path 15: arg4 positive; arg1, arg2, arg3 non-positive\n");
                } else {
                    printf("Path 16: All arguments are non-positive\n");
                }
            }
        }
    }

    // Continuing with more paths
    // ...
    return 0;
}

