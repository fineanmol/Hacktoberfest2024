#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Stack
{
public:
    Node *topEl = NULL;
    void push(int data)
    {
        Node *temp = new Node(data);
        if (top() == -1)
        {
            temp->next = NULL;
            topEl = temp;
            /* code */
        }
        else
        {
            temp->next = topEl;
            topEl = temp;
        }
    }
    void pop()
    {
        if (top() == -1)
        {
            cout << "No element to pop!";
            /* code */
        }
        else
        {
            topEl = topEl->next;
        }
    }
    int top()
    {
        if (topEl == NULL)
        {
            return -1;
        }
        else
        {
            return topEl->data;
        }
    }
    void print(){
        Node* temp = topEl;
        while(temp!=NULL){
            cout<<temp->data<<" "<<endl;
            temp= temp->next;
        }

    }
};
int main()
{
    Stack stack;
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.print();
    return 0;
}