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
    Node *top;
    Linked()
    {
        top = NULL;
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
        Node *ptr, *temp;

        temp = create_node(x);
        if (top == NULL)
        {
            top = temp;
        }
        else
        {
            ptr = top;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = temp;
            temp->next = NULL;
        }
        // cout << "Sucessfully added: " << x << endl;
    }
    int pop()
    {
        int datas;
        Node *ptr;
        if (top == NULL)
        {
            cout << "No data to be deleted" << endl;
        }
        else
        {
            ptr = top;
            top = top->next;
            datas = ptr->data;
            delete ptr;
        }
        return datas;
    }
    void display(int n)
    {

        Node *ptr;
        ptr = top;
        int i=n;
        while (ptr != NULL)
        {
            
            cout << ptr->data << "x^" << i << " + " ;          
            ptr = ptr->next;
            i--;
        }
    }
};

int main()
{
    Linked l1, l2, add;
    int n, a, p, sum;
    cout << "Enter no of terms in 1st polynomial: ";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        cout << "enter term x^" << i << ": ";
        cin >> a;
        l1.push(a);
    }
    cout << "2nd polynomial: " << endl;

    for (int i = n; i > 0; i--)
    {
        cout << "enter term x^" << i << ": ";
        cin >> a;
        l2.push(a);
    }
 
    cout << "Result" << endl;
    for (int i = 0; i < n; i++)
    {
        sum = l1.pop() + l2.pop();
        add.push(sum);
    }
    add.display(n);


}