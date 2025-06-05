#include <iostream>
using namespace std;
#define SIZE 10


class Deque {
    int front, rear;
    int arr[SIZE];

public:
    Deque() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (front == rear + 1) || ((front == 0) && (rear == SIZE - 1));
    }

    void addFront(int x) {
        if (isFull()) {
            cout << "Overflow"<<endl;
            return;
        }
        if ((front == -1) && (rear == -1))
            front = rear = 0;
        else if (front == 0)
            front = SIZE - 1;
        else
            front--;
        arr[front] = x;
        
    }

    void addRear(int x) {
        if (isFull()) {
            cout << "Overflow \n";
            return;
        }
        if ((front == -1) && (rear == -1))
            front = rear = 0;
        else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;
        arr[rear] = x;
       
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Underflow<<endl";
            return;
        }
        int item = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == (SIZE - 1))
            front = 0;
        else
            front++;
        cout << "Deleted:  " << item << endl;
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Underflow";
            return;
        }
        int item = arr[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0)
            rear = SIZE - 1;
        else
            rear--;
        cout << "Deleted:  " << item << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return;
        }
        
        int i = front;
        for (; i != rear; i = (i + 1) % SIZE)
            cout << arr[i] << ' ';
        cout << arr[i] << endl;
    }
};

int main() {
    Deque  q;
    
    q.addFront(1);
    q.addFront(2);
    q.addFront(3);
    q.addRear(34);
    q.addRear(45);
    q.addRear(56);
    q.display();
    q.addFront(0);
    q.removeFront();
    q.removeRear();
    q.addFront(5);
    q.display();
}