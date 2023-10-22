#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    // Push element onto the stack
    void push(int x) {
        // Add the element to queue1
        queue1.push(x);
        
        // Move all elements from queue2 to queue1
        while (!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
        
        // Swap the names of queue1 and queue2
        std::swap(queue1, queue2);
    }

    // Remove the element on the top of the stack
    void pop() {
        if (!empty()) {
            queue2.pop();
        }
    }

    // Get the top element of the stack
    int top() {
        return queue2.front();
    }

    // Check if the stack is empty
    bool empty() {
        return queue2.empty();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top: " << stack.top() << std::endl; // Output: 3

    stack.pop();
    std::cout << "Top: " << stack.top() << std::endl; // Output: 2

    stack.pop();
    std::cout << "Top: " << stack.top() << std::endl; // Output: 1

    stack.pop();
    if (stack.empty()) {
        std::cout << "Stack is empty" << std::endl; // Output: Stack is empty
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    return 0;
}
