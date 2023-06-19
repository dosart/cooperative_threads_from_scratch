#include "thread_pool.h"

typedef struct __tpool_work {
  thread_func_t func;
  void *arg;
  struct tpool_work *next;
} tpool_work_t;

static tpool_work_t *tpool_work_create(thread_func_t func, void *arg) {
  tpool_work_t *work;

  if (func == NULL)
    return NULL;

  work = malloc(sizeof(*work));
  work->func = func;
  work->arg = arg;
  work->next = NULL;
  return work;
}

static void tpool_work_destroy(tpool_work_t *work) {
  if (work == NULL)
    return;
  free(work);
}
