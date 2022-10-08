#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head=NULL;

void print()
{
    if(head !=NULL)
    {
        node *ptr=head->next;
        cout<<head->data<<" ";
        while(ptr!=head)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }   
    else
    cout<<"Circular Linked list is empty"<<endl;
}

void create()
{
    int n;
    cout<<"Enter element to init linked list: "<<endl;
    cin>>n;

    node *ptr= new node;
    ptr->data=n;
    ptr->next=NULL;

    head=ptr;
    ptr->next=head;

}

void insertb()
{
    if(head==NULL)
    {
        cout<<"Creating a linked list: "<<endl;
        create();
    }
    else{
        int ele;
        cout<<"Enter the element: ";
        cin>>ele;

        node *newnode=new node;
        newnode->data=ele;
        newnode->next=head;
        head=newnode;
        newnode->next->next=head;
        
    }
    print();

}

void inserte()
{
    int n;
    cout<<"Enter element: "<<endl;
    cin>>n;

    node *ptr= new node;
    ptr->data= n;
    ptr->next=head;

    node *temp=head;

    while(temp->next!=head)
    temp=temp->next;

    temp->next=ptr;
    temp->next->next=head;
    print();
}

void insertp()
{
    if(head==NULL)
    create();
    else
    {
        int pos=0;
        int ele=0;
        cout<<"Enter the position where the element is to be inserted: ";
        cin>>pos;
        cout<<"Enter the element: ";
        cin>>ele;

        node *newnode=new node;
        newnode->data=ele;
        newnode->next=NULL;

        node *ptr=head;
        int f=0;
        while(f<pos-1)
        {
            ptr=ptr->next;
            f++;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;

        print();

    }
}

void deleteb()
{
    if(head==NULL)
    cout<<"No element in the Linked list"<<endl;
    else
    {
        node *ptr= head;
        node *temp=head->next;
        while(ptr->next!=head)
        ptr=ptr->next;

        ptr->next->next=temp;
        head=temp;
    }
    print();
}

void deletee()
{
    if(head==NULL)
    cout<<"No element in the Linked list"<<endl;
    else
    {
        node *ptr= head;
        while(ptr->next->next!=head)
        ptr=ptr->next;

        ptr->next=head;
    }
    print();
}

int main()
{
    int ch;
    while(true)
    {
        cout<<"\n1:Insert at beginning\n2:Insert at end\n3:Insert at position\n4:Delete from beginning\n5:Delete from end\n6:Delete from given position\n7:Find Length\n8:Print\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            insertb();
            break;
            case 2:
            inserte();
            break;
            case 3:
            insertp();
            break;
            case 4:
            deleteb();
            break;
            case 5:
            deletee();
            break;
            // case 6:
            // deletep();
            // break;
            // case 7:
            // length();
            // break;
            case 8:
            print();
            break;
            case 9:
            exit(0);
            break;
        }
    }
}
