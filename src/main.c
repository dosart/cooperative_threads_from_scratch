#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "thread_pool.h"

static const size_t num_threads = 4;
static const size_t num_items = 100;

void worker(void *arg) {
  int *val = arg;
  int old = *val;

  *val += 1000;
  pthread_t tid = pthread_self();

  printf("tid=%ld, old=%d, val=%d\n", tid, old, *val);

  if (*val % 2)
    usleep(100000);
}

int main() {
  tpool_t *tm;
  size_t *vals;
  size_t i;

  tm = tpool_create(num_threads);
  vals = calloc(num_items, sizeof(*vals));

  for (i = 0; i < num_items; i++) {
    vals[i] = i;
    tpool_add_work(tm, worker, vals + i);
  }

  tpool_wait(tm);

  for (i = 0; i < num_items; i++) {
    printf("%ld\n", vals[i]);
  }

  free(vals);
  tpool_destroy(tm);
  return 0;
}