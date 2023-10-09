#include <iostream>
using namespace std;
#define SIZE 100

class Stack {
    int stack[SIZE];
    int top;

public:
    Stack() : top(-1) {}
    void push(int x) {
        if (top >= SIZE - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return stack[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top >= (SIZE - 1));
    }
    int tos() {
        return stack[top];
    }

    void display() {
        for (int i = 0; i <= top; i++)
            cout << stack[i] << "\t";
        cout << endl;
    }
};
int main(){
Stack s;
s.push(5);
s.push(6);
s.push(7);
s.push(8);
s.display();
s.pop();
s.pop();
s.display();

}