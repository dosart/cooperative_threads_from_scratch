#ifndef _SEMAPHORE_
#define _SEMAPHORE_

#include <pthread.h>

typedef struct __mutex_t {
  int value;
  pthread_cond_t cond;
  pthread_mutex_t lock;
} semaphore_t;

void semaphore_init(semaphore_t *semaphore, int value);

void semaphore_wait(semaphore_t *semaphore);

void semaphore_post(semaphore_t *semaphore);

#endif