#include "atomic_mutex.h"

void atomic_mutex_init(atomic_mutex_t *mutex) { mutex->flag = UNLOCKED; }

void atomic_mutex_lock(atomic_mutex_t *mutex) {
  while (atomic_exchange(&mutex->flag, LOCKED) == LOCKED)
    ;
}

void atomic_mutex_unlock(atomic_mutex_t *mutex) { mutex->flag = UNLOCKED; }
