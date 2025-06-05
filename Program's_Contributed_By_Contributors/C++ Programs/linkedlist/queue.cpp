#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Linked
{
public:
    Node *front, *rear;
    Linked()
    {

        front = NULL;
        rear = NULL;
    }
    Node *create_node(int val)
    {
        Node *ptr;
        ptr = new Node;
        ptr->data = val;
        ptr->next = NULL;
        return ptr;
    }
    void push(int x)
    {
        Node *ptr;
        ptr = create_node(x);

        if (front == NULL && rear == NULL)
        {
            front = ptr;
            rear = ptr;
        }

        rear->next = ptr;
        rear = ptr;
    }
    void pop()
    {
        Node *ptr;
        if (rear == NULL || front > rear)
        {
            cout << "no item to pop " << endl;
        }
        else
        {

            ptr = front;
            front = front->next;
            cout << "Deleted item :" << ptr->data << endl;
            delete ptr;
        }
    }
    void display()
    {

        Node *ptr;
        ptr = front;
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    Linked l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.pop();
    l.display();
}