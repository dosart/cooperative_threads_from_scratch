#include "thread.h"

void switch_threads(thread_t *from, thread_t *to) {
  void __switch_threads(void **prev, void *next);

  __switch_threads(&from->context, to->context);
}

thread_t *__create_thread(size_t stack_size, void (*entry)(void)) {
  const size_t size = stack_size + sizeof(thread_t);
  switch_frame_t frame;
  thread_t *thread = malloc(size);

  if (!thread)
    return thread;

  memset(&frame, 0, sizeof(frame));
  frame.rip = (uint64_t)entry;

  thread->context = (char *)thread + size - sizeof(frame);
  memcpy(thread->context, &frame, sizeof(frame));
  return thread;
}

thread_t *create_thread(void (*entry)(void)) {
  const size_t default_stack_size = 4096;

  return __create_thread(default_stack_size, entry);
}

void destroy_thread(thread_t *thread) { free(thread); }