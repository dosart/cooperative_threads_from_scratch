#include "mutex.h"
#include "compare_and_swap.h"

void init(mutex_t *mutex) { mutex->flag = 0; }

void lock(mutex_t *mutex) {
  while (compare_and_swap(&mutex->flag, 0, 1) == 1)
    ;
}

void unlock(mutex_t *mutex) { mutex->flag = 0; }