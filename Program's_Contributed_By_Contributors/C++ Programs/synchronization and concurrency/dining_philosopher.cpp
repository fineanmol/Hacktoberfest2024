#include <iostream>
#include <thread>
#include <mutex>

const int NUM_PHILOSOPHERS = 5;

std::mutex forks[NUM_PHILOSOPHERS];

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    std::unique_lock<std::mutex> left_lock(forks[left_fork]);
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate thinking
    std::unique_lock<std::mutex> right_lock(forks[right_fork]);

    std::cout << "Philosopher " << id << " is eating." << std::endl;

    right_lock.unlock();
    left_lock.unlock();
}

int main() {
    std::thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = std::thread(philosopher, i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}
