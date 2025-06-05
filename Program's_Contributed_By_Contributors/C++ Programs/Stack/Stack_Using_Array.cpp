#include <iostream>
#include<stdlib.h>
using namespace std;

class Stack
{
    int top;
    int *arr;
    int size;

public:
    Stack(int n)
    {
        size = n;
        arr = (int *)malloc(size * sizeof(int));
        top = -1;
    }
    bool isEmpty()
    {
        if (top < 0)
            return true;
        else
            return false;
    }

    void push()
    {
        int element;
        cout << "Enter the element you want to push" << endl;
        cin >> element;
            arr[++top] = element;
            cout << "element pushed into the stack" << endl;
       
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack Underflow" << endl;
        else
        {
            int x = arr[top];
            top--;
            cout << "Element popped is : " << x << endl;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return ;
        }
        else
        {
            cout << "Element at top is " << arr[top] << endl;
        }
    }

    void display()
    {
        for (int i = 0; i <=top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n, choice;
    cout << "enter the size of the stack " << endl;
    cin >> n;
    Stack s(n);
    
    do
    {
        cout << "1.Insert Elemnt in the stack\n2.Get the top element of stack \n3.Pop element from the stack" << endl;
        cout << "4.Display the elemnets of the stack \n Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.peek();
            break;
        case 3:
            s.pop();
            break;
        case 4:
            s.display();
            break;
        default:
            cout << "You have entered wrong choice " << endl;
            break;
        }
    } while (1);

    return 0;
}