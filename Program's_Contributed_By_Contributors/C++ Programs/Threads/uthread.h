#ifndef UTHREAD_H
#define UTHREAD_H


#include <ucontext.h>
#include <signal.h>
#include <semaphore.h>

#define STACK_SIZE 8192

typedef struct uthread_t {
    int id;
    ucontext_t context;
    void* retval;
    /* Ready: 0, Running: 1, Blocked: 2 */
    int state;
} uthread_t;

typedef struct uthread_mutext_t {
    int locked;
    sem_t = sem;
} uthread_mutext_t;

typedef struct uthread_barrier_t {
    int count;
    int limit;
    sem_t = sem;
} uthread_barrier_t;

void uthread_create(uthread_t* thread, void* (*start_routine)(void*), void* arg);
void uthread_yield();
void uthread_mutex_init(uthread_mutex_t* mutex);
void uthread_mutex_lock(uthread_mutex_t* mutex);
void uthread_mutex_unlock(uthread_mutex_t* mutex);
void uthread_join(uthread_t* thread, void** retval);
void uthread_barrier_init(uthread_barrier_t* barrier, int count);
void uthread_barrier_wait(uthread_barrier_t* barrier);
void timer_handler(int sig);
void sigusr1_handler(int sig);
void sigusr2_handler(int sig);
void uthread_init();

#endif