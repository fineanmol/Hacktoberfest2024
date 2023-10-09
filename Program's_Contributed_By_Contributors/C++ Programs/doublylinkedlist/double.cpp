//doubly linkedlist
#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

// creating new node
Node *create_node(int value)
{
    Node *ptr;
    ptr = new Node;
    if (ptr == NULL)
    {
        cout << "No allocation of memory" << endl;
        return NULL;
    }
    else
    {

        ptr->data = value;
        ptr->next = NULL;
        ptr->prev = NULL;
        return ptr;
    }
}

// forming list
class Linked
{
public:
    Node *start, *ptr, *temp;

    Linked()
    {
        start = NULL;
    }

    void add_beg(int x)
    {
        Node *ptr;
        ptr = create_node(x);
        if (start == NULL)
        {
            start = ptr;
        }
        else
        {

            ptr->next = start;
            ptr->prev=NULL;
            start = ptr;
        }
        // cout << "Sucessfully added: " << x << endl;
    }
    void add_last(int x)
    {

        temp = create_node(x);
        if (start == NULL)
        {
            start = ptr;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = temp;
            temp->prev=ptr;
            temp->next = NULL;
        }
        // cout << "Sucessfully added: " << x << endl;
    }
    void add_after_specific(int x, int y)
    {
        Node *ptr, *temp;
        temp = create_node(y);
        if (ptr == NULL)
        {
            cout << "Empty list" << endl;
            start = ptr;
        }
        else
        {
            ptr = start;
            while (ptr->data != x)
            {
                ptr = ptr->next;
            }

            temp->next = ptr->next;
            temp->prev=ptr;
            ptr->next->prev=temp;
            ptr->next = temp;
        }
    }
    void add_before_specific(int x, int y)
    {
        temp = create_node(y);
        if (start == NULL)
        {
            cout << "Empty list" << endl;
            start = ptr;
        }
        else
        {
            Node *ptr, *previous;
            ptr = start;
            previous = start;

            while (ptr->data != x)
            {
                previous = ptr;
                ptr = ptr->next;
            }
            temp->next=ptr;
            temp->prev=previous;
            previous->next=temp;
            ptr->prev=temp;

            
        }
    }
    void delete_beg()
    {

        ptr = start;
        if (ptr == NULL)
        {
            cout << "NO data available";
        }
        else
        {

            start = start->next;
            start->prev=NULL;
            cout << "Data deleted is: " << ptr->data << endl;
            delete ptr;
        }
    }
    void delete_end()
    {
        ptr = start;
        temp = start;
        if (ptr == NULL)
        {
            cout << "NO data available";
        }
        else
        {

            while (ptr->next != NULL)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            cout << "Data deleted is:" << ptr->data << endl;
            temp->next = NULL;
            delete ptr;
        }
    }
    void delete_after_specific(int x)
    {
        Node *ptr, *temptr;
        ptr = start;
     
        if (ptr == NULL)
        {
            cout << "NO data available";
        }
        else
        {
            while (ptr->data != x)
            {
               
                ptr = ptr->next;
            }
             temptr=ptr->next;

            ptr->next = temptr->next;
            temptr->next->prev=ptr;

           
         cout << "Data deleted after: " << x << " is: " << temptr->data << endl;

            delete temptr;
        }
    }
    void delete_before_specific(int x)
    {
        Node *ptr, *temptr;
        ptr = start;
     
        if (ptr == NULL)
        {
            cout << "NO data available";
        }
        else
        {
            while (ptr->data != x)
            {
               
                ptr = ptr->next;
            }
             temptr=ptr->prev;
             ptr->prev=temptr->prev;
            temptr->prev->next=ptr;



           
         cout << "Data deleted before: " << x << " is: " << temptr->data << endl;

            delete temptr;
        }
    }
    void display()
    {
        Node *ptr;
        ptr = start;

        while (ptr != NULL)
        {
            cout << ptr->data << '\t';
            ptr = ptr->next;
        }
        cout << endl;
    }
};
int main()
{
    Linked l;

    l.add_beg(1);
    l.add_beg(2);
    l.add_last(4);
    l.add_last(5);
    l.display();
    l.add_before_specific(1, 0);
    l.add_after_specific(2, 3);
    l.display();
    l.delete_beg();
    l.delete_end();
    l.delete_after_specific(0);
    l.display();
    l.delete_before_specific(4);
    l.display();
    return 0;
}