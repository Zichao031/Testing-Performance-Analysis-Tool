#include <stdio.h>
#include <stdlib.h>

void execute_path(int args[5], int path_id) {
    printf("Path %d executed with arguments: ", path_id);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", args[i]);
    }
    printf("\n");
}

int algorithm(int args[5]) {
    
    if (args[0] > 0) {
        if (args[1] > 0) {
            if (args[2] > 0) {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 1);  // Path 1
                    } else {
                        execute_path(args, 2);  // Path 2
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 3);  // Path 3
                    } else {
                        execute_path(args, 4);  // Path 4
                    }
                }
            } else {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 5);  // Path 5
                    } else {
                        execute_path(args, 6);  // Path 6
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 7);  // Path 7
                    } else {
                        execute_path(args, 8);  // Path 8
                    }
                }
            }
        } else {
            if (args[2] > 0) {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 9);  // Path 9
                    } else {
                        execute_path(args, 10);  // Path 10
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 11);  // Path 11
                    } else {
                        execute_path(args, 12);  // Path 12
                    }
                }
            } else {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 13);  // Path 13
                    } else {
                        execute_path(args, 14);  // Path 14
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 15);  // Path 15
                    } else {
                        execute_path(args, 16);  // Path 16
                    }
                }
            }
        }
    } else {
        if (args[1] > 0) {
            if (args[2] > 0) {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 17);  // Path 17
                    } else {
                        execute_path(args, 18);  // Path 18
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 19);  // Path 19
                    } else {
                        execute_path(args, 20);  // Path 20
                    }
                }
            } else {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 21);  // Path 21
                    } else {
                        execute_path(args, 22);  // Path 22
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 23);  // Path 23
                    } else {
                        execute_path(args, 24);  // Path 24
                    }
                }
            }
        } else {
            if (args[2] > 0) {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 25);  // Path 25
                    } else {
                        execute_path(args, 26);  // Path 26
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 27);  // Path 27
                    } else {
                        execute_path(args, 28);  // Path 28
                    }
                }
            } else {
                if (args[3] > 0) {
                    if (args[4] > 0) {
                        execute_path(args, 29);  // Path 29
                    } else {
                        execute_path(args, 30);  // Path 30
                    }
                } else {
                    if (args[4] > 0) {
                        execute_path(args, 31);  // Path 31
                    } else {
                        execute_path(args, 32);  // Path 32
                    }
                }
            }
        }
    }

    return 0;
}