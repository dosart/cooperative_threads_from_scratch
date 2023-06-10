#include "compare_and_swap"

char compare_and_swap(int *ptr, int old, int new) {
  unsigned char ret;

  asm volatile("lock\n"
               "cmpxchgl %2, %1\n"
               "sete %0\n"
               : "= q"(ret), "= m"(*ptr)

               : "r"(new), "m"(*ptr), "a"(old)

               : "memory");
  return ret;
}