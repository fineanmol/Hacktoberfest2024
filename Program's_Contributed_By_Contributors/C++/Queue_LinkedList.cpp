#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head=NULL;

bool isEmpty()
{
    if(head==NULL)
    return true;
    return false;
}

void enqueue()
{
    node *ptr=head;

    int n;
    cout<<"Enter the number to be enqueued: "<<endl;
    cin>>n;


    node *newnode=new node;
    newnode->data=n;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(ptr->next!=NULL)
        ptr=ptr->next;
        ptr->next=newnode;
        
    }

    
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty!! UNDERFLOW!!"<<endl;
        return;
    }
    cout<<"Dequeued "<<head->data<<endl;
    head=head->next;
}

void print()
{
    cout<<"----------THE QUEUE----------"<<endl;
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    int ch;
    while (true)
    {
        cout << "Enter:\n1: to enqueue\n2: to dequeue\n3: to print the stack" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print();
            break;
        default:
            exit(0);
            break;
        }
    }
}
