#include <iostream>
#include <stack>
using namespace std;
class QueueUsingOneStack {
private:
    stack<int> myStack;
public:
    // Function to enqueue an element
    void enqueue(int value) {
        myStack.push(value);
    }

    // Function to dequeue an element
    int dequeue() {
        if (myStack.empty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return a default value to indicate an empty queue
        }

        // If the stack has only one element, pop and return it
        if (myStack.size() == 1) {
            int front = myStack.top();
            myStack.pop();
            return front;
        }

        // Recursive call to pop elements from the top of the stack and enqueue them
        int front = myStack.top();
        myStack.pop();
        int result = dequeue(); //Recursive call-->tail recursion
        myStack.push(front);
        return result;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return myStack.empty();
    }
};

int main() {
    QueueUsingOneStack myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;

    myQueue.enqueue(4);
    myQueue.enqueue(5);

    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;

    return 0;
}

