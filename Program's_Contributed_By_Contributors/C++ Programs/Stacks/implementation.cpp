#include <iostream>
#include <stack>

using namespace std;

class MyStack {
public:
    void push(int x) {
        data.push(x);
    }

    int pop() {
        if (!data.empty()) {
            int topElement = data.top();
            data.pop();
            return topElement;
        } else {
            // Handle empty stack
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Return a sentinel value
        }
    }

    int top() {
        if (!data.empty()) {
            return data.top();
        } else {
            // Handle empty stack
            cout << "Stack is empty. No top element." << endl;
            return -1; // Return a sentinel value
        }
    }

    bool isEmpty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }

private:
    stack<int> data;
};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl; // 3
    cout << "Stack size: " << stack.size() << endl; // 3

    while (!stack.isEmpty()) {
        cout << "Popped: " << stack.pop() << endl;
    }

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}