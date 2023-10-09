#include <iostream>
using namespace std;
#define SIZE 100


class Queue {
    int front, rear;
    int arr[SIZE];

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear >= SIZE - 1) {
            cout << "Overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }

    bool isEmpty() {
        return (front > rear);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow";
            return -1;
        }
        return arr[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
       
        for (int i = front; i <= rear; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
   cout<<"dequeued: "<<q.dequeue()<<endl;
    q.display();

}