import threading

NUM_PHILOSOPHERS = 5

# Create a list of locks, one for each fork
forks = [threading.Lock() for _ in range(NUM_PHILOSOPHERS)]

def philosopher(id):
    left_fork = forks[id]
    right_fork = forks[(id + 1) % NUM_PHILOSOPHERS]

    while True:
        # Think (philosopher is not eating)
        print(f"Philosopher {id} is thinking")

        # Pick up forks
        left_fork.acquire()
        right_fork.acquire()

        # Eat (philosopher is eating)
        print(f"Philosopher {id} is eating")

        # Release forks when done eating
        left_fork.release()
        right_fork.release()

if __name__ == "__main__":
    philosophers = []

    for i in range(NUM_PHILOSOPHERS):
        philosopher_thread = threading.Thread(target=philosopher, args=(i,))
        philosophers.append(philosopher_thread)
        philosopher_thread.start()

    for philosopher_thread in philosophers:
        philosopher_thread.join()
