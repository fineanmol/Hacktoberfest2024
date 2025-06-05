// perform insertion and deletion in circular linked list

#include <iostream>
using namespace std;

// creating a default
class Node
{
public:
    int data;
    Node *next;
};

// creating new node
// forming list
class cLinked
{
public:
    Node *start, *ptr, *temp;

    cLinked()
    {
        start = NULL;
    }

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
            ptr->next = start;
            return ptr;
        }
    }

    void add_beg(int x)
    {
        Node *ptr;
        ptr = create_node(x);
        if (start == NULL)
        {
            start = ptr;
            start->next=start;
        }
        else
        {

            // ptr->next = start;
            // start = ptr;


            Node *temp = start;
			while (temp->next != start) 
            {
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = start;
			start = ptr;
        }

        // cout << "Sucessfully added: " << x << endl;
    }
    void add_last(int x)
    {
        Node *ptr, *temp;
        temp = create_node(x);

        if (start == NULL)
        {
            start = temp;
            start->next = start;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }

            ptr->next = temp;
            temp->next = start; // changed the line from null to make it circular
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

        Node *ptr, *temp;
        ptr = start;
        temp = start;
        while (temp->next != start) // changed the line from null to make it circular
        {
            temp = temp->next;
        }
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

        temp->next = start;
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

            while (ptr->next != start) // changed the line from null to make it circular
            {
                temp = ptr;
                ptr = ptr->next;
            }

            cout << "Data deleted is:" << ptr->data << endl;
            temp->next = start; // changed the line from null to make it circular
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
            temptr = ptr->next;
            ptr->next = temptr->next;

            cout << "Data deleted after: " << x << " is: " << temptr->data << endl;

            delete temptr;
        }
    }
    void display()
    {
        Node *ptr;
        ptr = start;

        while (ptr->next != start)
        {
            cout << ptr->data << '\t';
            ptr = ptr->next;
           
        }
        cout << ptr->data << endl;
    }
};
int main()
{
    cLinked l;

    l.add_beg(1);
    l.add_beg(2);
    l.add_beg(20);
     
    l.add_before_specific(1, 0); 
    l.add_last(4);
    l.add_last(5);
    l.display();
    l.delete_end();
    l.delete_beg();
    l.display();
    return 0;
}