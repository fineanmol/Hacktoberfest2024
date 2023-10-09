#include <iostream>
using namespace std;

// creating a default node : like struct
class Node
{
public:
    int data;
    Node *next;
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
            Node *ptr, *prev;
            ptr = start;
            prev = start;

            while (ptr->data != x)
            {
                prev = ptr;
                ptr = ptr->next;
            }

            prev->next = temp;
            temp->next = ptr;
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
           
           
            cout << "Data deleted after: " << x << " is: " << temptr->data << endl;

            delete temptr;
        }
    }void delete_data(int x)
    {
        Node *ptr, *temptr;
        ptr = start;
     
        if (ptr == NULL)
        {
            cout << "NO data available";
        }
        else if (ptr->data == x)
        {
            start = ptr->next;
            cout<<"yeha aayo hai! "<<endl;
            delete ptr;
        }        
    
        else
        {
            while (ptr->data != x)
            {
                temptr=ptr;
                ptr = ptr->next;
         
            }
             temptr->next=ptr->next;
          
           
            cout << "Data deleted : " << x << " is: " << ptr->data << endl;

            delete ptr;
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
    l.add_before_specific(1, 0);
    l.add_after_specific(2, 3);
    l.display();
    l.delete_beg();
    l.delete_end();

    l.delete_after_specific(0);
    l.display();
    l.delete_data(3);
     l.display();
    return 0;
}