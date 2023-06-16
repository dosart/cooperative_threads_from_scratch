#include "semaphore.h"

void semaphore_init(semaphore_t *semaphore, int value) {
  semaphore->value = value;
  pthread_cond_init(&semaphore->cond, NULL);
  pthread_mutex_init(&semaphore->lock, NULL);
}

void semaphore_wait(semaphore_t *semaphore) {
  pthread_mutex_lock(&semaphore->lock);

  while (semaphore->value <= 0)
    pthread_cond_wait(&semaphore->cond, &semaphore->lock);

  semaphore->value--;

  pthread_mutex_unlock(&semaphore->lock);
}

void semaphore_post(semaphore_t *semaphore) {
  pthread_mutex_lock(&semaphore->lock);

  semaphore->value--;

  pthread_cond_signal(&semaphore->cond);
  pthread_mutex_unlock(&semaphore->lock);
}