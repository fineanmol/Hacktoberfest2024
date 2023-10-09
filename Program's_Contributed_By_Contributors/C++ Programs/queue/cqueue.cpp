#include <iostream>
using namespace std;
#define SIZE 10


class cQueue {
    int front, rear;
    int arr[SIZE];

public:
    cQueue() {
        front = rear = 0;
    }

    void enqueue(int x) {
        if (front == (rear + 1) % SIZE) {
            cout << "cQueue is full" << endl;
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % SIZE;
    }

    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return front == (rear + 1) % SIZE;
    }

    int dequeue() {
        if (front == rear) {
            cout << "cQueue is empty" << endl;
            exit(0);
        }
        int item = arr[front];
        front = (front + 1) % SIZE;
        return item;
    }

    void display() {
        if (front == rear) {
            cout << "cQueue is empty" << endl;
            return;
        }
   
        for (int i = front; i != rear; i = (i + 1) % SIZE)
            cout << arr[i] << ' ';
        cout << endl;
    }

    // display from index 0 to last
    void show() {
        for (int i = 0; i < SIZE; i++)
            cout << arr[i] << ' ';
    }
};

int main() {
    cQueue q;
    
    for (int i = 0; i < 5; i++)
        q.enqueue(i);
    q.display();
   
    while (!q.isEmpty())
        cout <<"Deleted: "<< q.dequeue() << endl;
}
  