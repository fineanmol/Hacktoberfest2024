#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>
#include <ucontext.h>


#define STACK_SIZE 32768
#define MAX_THREADS 128

unthread_t threads[MAX_THREADS];
current_thread = -1;
int num_threads = 0;

typedef struct {
    int id;
    ucontext_t context;
    void* stack;
    int state;
    int joinable;
} uthread_t;

typedef struct {
    sem_t lock;
    uthread_t* owner;
    int count;
} uthread_mutex_t;

typedef struct {
    sem_t lock;
    sem_t barrier;
    int count;
} unthread_barrier_t;

/* Global Vatiables */
uthread_t* current_thread;
uthread_t* threads[MAX_THREADS];
int next_thread_id = 0;
int num_threads = 0;
int thread_count = 0;
int initialized = 0;
sem_t thread_count_sem;

/* Function Prototypes for UTHREAD */
void uthread_init();
void uthread_create(uthread_t* thread, void* (*start_routine)(void*), void* arg);
void uthread_yield();
void uthread_mutex_init(uthread_mutex_t* mutex);
void uthread_mutex_lock(uthread_mutex_t* mutex);
void uthread_mutex_unlock(uthread_mutex_t* mutex);
void uthread_join(uthread_t* thread, void** retval);
void uthread_barrier_init(uthread_barrier_t* barrier, int count);
void uthread_barrier_wait(uthread_barrier_t* barrier);

/* Function Prototypes for SIGUSR */
void timer_handler(int sig);
void sigusr1_handler(int sig);
void sigusr2_handler(int sig);

/* ? Testing */
void* worker(void* arg) {
    int id = *(int *)arg;
    printf("Worker %d started \n", id);

    for(int i = 0; i < 5; i++) {
        printf("Worker %d is working \n", id);
        uthread_yield();
    }

    printf("Worker %d finished \n", id);
    return NULL;
}

/* Driver Code */
int main(int argc, char** argv) {
    uthread_init();

    /* Main Thread Code Here */
    uthread_t thread[3];
    int ids[] = {1, 2, 3};

    for(int i = 0; i < 3; i++) {
        uthread_create(&thread[i], worker, &ids[i]);
    }

    for(int i = 0; i < 3; i++) {
        uthread_join(&thread[i], NULL);
    }

    printf("All workers finished \n");

    return 0;
}

/* Prototypes Function Implementation */
void uthread_create(uthread_t* thread, void* (*start_routine)(void*), void* arg) {
    /* Allocate a new uthread_tcb struct for the new thread */
    uthread_tcb* new_tcb = (uthread_tcb*)malloc(sizeof(uthread_tcb));

    if(!new_tcb -> stack) {
        fprintf(stderr, "Error: Could not allocate stack for new thread\n");
        exit(1);
    }

    /* Initialize the new thread's context */
    new_tcb -> stack = (char*)malloc(UTHREAD_STACK_SIZE);
    if(!new_tcb -> stack) {
        fprintf(stderr, "Error: Could not allocate stack for new thread\n");
        exit(1);
    }

    new_tcb -> state = READY;
    new_tcb -> joined = NULL;
    new_tcb -> retval = NULL;
    new_tcb -> waiting_on = NULL;
    new_tcb -> context.uc_stack.ss_sp = new_tcb -> stack;
    new_tcb -> context.uc_stack.ss_size = UTHREAD_STACK_SIZE;
    new_tcb -> context.uc_link = NULL;

    /* Create the context for the new thread */
    makecontext(&new_tcb -> context, (void (*)(void))uthread_start, 3, start_routine, arg, new_tcb);

    /* Add the new tcb to the ready queue */
    uthread_equeue_ready(new_tcb);

    /* Set the thread id and return */
    *thread = new_tcb -> tid;
}

void uthread_yield() {
    uthread_tcb* cur_tcb = uthread_current();

    /* If the current thread is not blocked or joined, add it back to the ready queue */
    if(cur_tcb -> state == RUNNING) {
        cur_tcb -> state = READY;
        uthread_equeue_ready(cur_tcb);
    }

    /* Get the next ready thread from the queue */
    uthread_tcb* next_tcb = uthread_dequeue_ready();

    if(next_tcb) {
        /* Update the current and next thread states */
        next_tcb -> state = RUNNING;
        cur_tcb -> state = READY;

        /* Switch the context to the next thread */
        uthread_swapcontext(&cur_tcb -> context, &next_tcb -> context);
    }
}

void uthread_mutex_init(uthread_mutex_t* mutex) {
    mutex -> lock = 0;
    mutex -> owner = NULL;
    mutex -> wait_queue = NULL;
}

void uthread_mutex_lock(uthread_mutex_t* mutex) {
    while(__sync_lock_test_and_set(&mutex -> lock, 1)) {
        /* The lock is already taken, so add ourselves to the wait queue */
        uthread_t* self = uthread_self();
        self -> state = UTHREAD_STATE_BLOCKED;
        mutex -> wait_queue = self;

        /* Yield the CPU to give another thread a chance to run */
        uthread_yield();
    }
    /* The lock is our, so update the owner field */
    mutex -> owner = uthread_self();
}

void uthread_mutex_unlock(uthread_mutex_t* mutex) {
    /* Only the owner of the lock can unlock it */
    if(mutex -> owner != uthread_self()) {
        fprintf(stderr, "Error: Attempt to unlock a mutex that is not owned by the current thread.\n");
        exit(1);
    }

    /* Clear the owner field and release the lock */
    mutex -> owner = NULL;
    __sync_lock_release(&mutex -> lock);

    /* Wake up the first thread in the wait queue, if any */
    if(mutex -> wait_queue != NULL) {
        uthread_t* thread = mutex -> wait_queue;
        mutex -> wait_queue = thread -> next;
        thread -> state = UTHREAD_STATE_READY;
        uthread_make_ready(thread);
    }
}

void uthread_join(uthread_t* thread, void** retval) {
    uthread_tcb_t* tcb = thread -> tcb;

    /* Lock the Schedular */
    uthread_mutex_lock(&scheduler_mutex);

    while(tcb -> state != TERMINATED) {
        /* Wait for thread to terminate */
        uthread_cond_wait(&Scheduler_cond, &scheduler_mutex);
    }
    /* Unlock the schedular */
    uthread_mutex_unlock(&scheduler_mutex);

    if(retval != NULL) {
        /* Get the return value if requested */
        *retval = tcb -> ret_val;
    }

    /* Free the thread's stack */
    free(tcb -> stack);
    /* Free the thread TCB */
    free(tcb);
}

void uthread_barrier_init(uthread_barrier_t* barrier, int count) {
    barrier -> count = count;
    barrier -> remaining = count;
    uthread_mutex_init(&barrier -> mutex);
    uthread_cond_init(&barrier -> cond);
}

void uthread_barrier_wait(uthread_barrier_t* barrier) {
    uthread_mutex_lock(&barrier -> mutex);
    barrier -> remaining--;

    if(barrier -> remaining == 0) {
        uthread_cond_broadcast(&barrier -> cond);
    } else {
        uthread_cond_wait(&barrier -> cond, &barrier -> mutex);
    }
    uthread_mutex_unlock(&barrier -> mutex);
}

void uthread_init() {
    struct sigaction sa;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = timer_handler;
    sigfillset(&sa.sa_mask);

    if(sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("Unable to install SIGALRM handler");
        exit(1);
    }

    sa.sa_handler = sigusr1_handler;
    if(sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Unable to install SIGUSR1 handler");
        exit(1);
    }

    sa.sa_handler = sigusr2_handler;
    if(sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("Unable to install SIGUSR2 handler");
        exit(1);
    }

    ualarm(50000, 50000);

    uthread_t* main_thread = &threads[num_threads++];
    main_thread -> state = RUNNING;
    current_thread = 0;
}

void timer_handler(int sig) {
    if(current_thread == -1 || num_threads < 2) return;

    uthread_yield();
}

void sigusr1_handler(int sig) {
    if(current_thread == -1) return;

    uthread_t* thread = &threads[current_thread];

    if(thread -> state == RUNNING) {
        thread -> state = BLOCKED;
        uthread_yield();
    }
}

void sigusr2_handler(int sig) {
    if(current_thread == -1) return;

    uthread_t* thread = &threads[current_thread];

    if(thread -> state == BLOCKED) {
        thread -> state = READY;
    }
}
