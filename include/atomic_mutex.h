#ifndef _ATOMIC_MUTEX_H
#define _ATOMIC_MUTEX_H

#include <stdatomic.h>

#define LOCKED 1
#define UNLOCKED 0

typedef struct __atomic_mutex_t {
  atomic_int flag;
} atomic_mutex_t;

void atomic_mutex_init(atomic_mutex_t *mutex);

void atomic_mutex_lock(atomic_mutex_t *mutex);

void atomic_mutex_unlock(atomic_mutex_t *mutex);

#endif // MUTEX_ATOMIC_MUTEX_H
