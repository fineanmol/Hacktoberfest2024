#include<iostream>
using namespace std;

// Creating the list node class
class node
{
    public:
        int data;
        node *next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};

// Auxiliary display function for the list
void display(node *head)
{
    if(head == NULL)    // Returns if the list is empty
        return;
    
    node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

// Auxiliary insertion function for the list
void insert(node* &head, int val)
{
    node *n = new node(val);
    if(head == NULL)    // If the list is empty
    {
        head = n;
        return;
    }

    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

// Function to delete a node holding a particular value
void delAtVal(node* &head, int val)
{
    if(head == NULL)    // Returns if the list is empty
        return;
    
    node *temp = head;
    while(temp->next->data != val)
        temp = temp->next;
    if(temp->next == NULL)
        return;
    node *toDel = temp->next;
    temp->next = temp->next->next;
    delete toDel;
}

// Function to delete only the head node
void delAtHead(node* &head)
{
    if(head == NULL)    // Returns if the list is empty
        return;
    
    node *toDel = head;
    head = head->next;
    delete toDel;
}

int main()
{
    node *head = NULL;
    for(int i = 10; i<100; i+=10)   // Inserting some values into the list
        insert(head, i);
    display(head);

    // Demo of the deletion function
    delAtVal(head, 50);
    display(head);

    // Demo of the deletion-at-head function
    delAtHead(head);
    display(head);

    return 0;
}