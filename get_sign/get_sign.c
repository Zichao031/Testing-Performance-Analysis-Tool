/*
 * First KLEE tutorial: testing a small function
 */

#include <klee/klee.h>
#include <stdio.h>

int get_sign(int x) {
  if (x == 0)
     return 0;
  
  if (x < 0)
     return -1;
  else 
     return 1;
} 

int main() {
  int a = -100;
  klee_make_symbolic(&a, sizeof(a), "a");
  int result = get_sign(a);
  printf("Result: %d\n", result);
  return get_sign(a);
} 