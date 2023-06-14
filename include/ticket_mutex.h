#ifndef _TICKET_MUTEX_H
#define _TICKET_MUTEX_H

#include <stdatomic.h>


typedef struct __ticket_mutex_t {
    atomic_uint ticket;
    atomic_uint turn;
} ticket_mutex_t;

void ticket_mutex_init(ticket_mutex_t* mutex);

void ticket_mutex_lock(ticket_mutex_t* mutex);

void ticket_mutex_unlock(ticket_mutex_t* mutex);



#endif //_TICKET_MUTEX_H