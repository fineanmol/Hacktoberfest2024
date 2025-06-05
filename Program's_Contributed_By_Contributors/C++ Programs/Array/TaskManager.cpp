#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& description) : description(description), completed(false) {}
    
    void markComplete() {
        completed = true;
    }

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

private:
    std::string description;
    bool completed;
};

class TaskManager {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << std::endl;
    }

    void markTaskComplete(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].markComplete();
            std::cout << "Task marked as complete: " << tasks[taskIndex].getDescription() << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void listTasks() {
        std::cout << "Tasks:" << std::endl;
        for (int i = 0; i < tasks.size(); i++) {
            std::cout << (i + 1) << ". " << tasks[i].getDescription();
            if (tasks[i].isCompleted()) {
                std::cout << " (Completed)";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    TaskManager taskManager;
    int choice;

    while (true) {
        std::cout << "Task Management System Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Mark Task as Complete" << std::endl;
        std::cout << "3. List Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin.ignore(); // Clear newline character from previous input
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                taskManager.addTask(description);
                break;
            case 2:
                int taskIndex;
                std::cout << "Enter the index of the task to mark as complete: ";
                std::cin
