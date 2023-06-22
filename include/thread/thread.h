#ifndef _THREAD_H
#define _THREAD_H

#include <stddef.h>
#include <stdint.h>

struct __switch_frame_t {
  uint64_t rflags;
  uint64_t r15;
  uint64_t r14;
  uint64_t r13;
  uint64_t r12;
  uint64_t rbp;
  uint64_t rbx;
  uint64_t rip;
} __attribute__((packed));

typedef struct __switch_frame_t switch_frame_t;

typedef struct __thread_t {
  void *context;
} thread_t;

void switch_threads(thread_t *from, thread_t *to);

thread_t *create_thread(void (*entry)(void));

void destroy_thread(thread_t *thread);

#endif