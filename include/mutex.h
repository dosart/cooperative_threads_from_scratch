#ifndef _MUTEX_
#define _MUTEX_

typedef struct __mutex_t {
  int flag;
} mutex_t;

void init(mutex_t *mutex);

void lock(mutex_t *mutex);

void unlock(mutex_t *mutex);

#endif