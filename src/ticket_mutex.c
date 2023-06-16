#include "ticket_mutex.h"

void ticket_mutex_init(ticket_mutex_t *mutex) {
  mutex->ticket = 0;
  mutex->turn = 0;
}

void ticket_mutex_lock(ticket_mutex_t *mutex) {
  unsigned int my_turn = atomic_fetch_and(&mutex->ticket, 1);
  while (atomic_load(&mutex->turn) != my_turn)
    ;
}

void ticket_mutex_unlock(ticket_mutex_t *mutex) {
  atomic_fetch_and(&mutex->turn, 1);
}