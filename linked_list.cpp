// implement linked list and insert and delete an element in the linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *start = NULL; // suppose initially linked list is empty

void insertAtBeginning(int new_data)
{
    // struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = start;
    start = new_node;
}
void insert_at_last(int last_Element)
{
    Node *new_Node = new Node;
    new_Node->data = last_Element;
    new_Node->next = NULL;
    if (start == NULL)
    {
        start = new_Node;
    }
    else
    {
        Node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_Node;
    }
}
void insert_at_any_given_position(int position, int number)
{
    Node *new_node = new Node;
    new_node->data = number;

    Node *temp = start;
    if (position == 1)
    {
        insertAtBeginning(number);
    }
    else
    {
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int delete_at_first()
{
    if (start == NULL)
    {
        return 0;
    }
    else
    {
        Node *locP = new Node;
        locP = start;
        Node *loc = new Node;
        loc = locP->next;
        start = loc;
        return 1;
    }
}
// function for delete at given position
void dlt_at_given_postion(int position)
{
    if (position == 1)
    {
        delete_at_first();
    }
    else
    {
        Node *temp = new Node;
        temp = start;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        Node *temp_next = temp->next;
        temp->next = temp_next->next;
    }
}
void display()
{
    Node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int N;
    cout << "how many numbers you want to insert at beginning";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int inserting;
        cout << "enter the " << i + 1 << " number"
             << " that you want to insert = ";
        cin >> inserting;
        insertAtBeginning(inserting);
    }
    cout << "The linked list is: ";
    display();

    // inserting at the end of the linked list

    int last_Element;
    cout << endl
         << " enter the element which you want to insert at the end = ";
    cin >> last_Element;
    insert_at_last(last_Element);
    cout
        << endl
        << "The linked list is: ";
    display();

    // insert at the given position
    int position, number_at_given_position;
    cout << "\n"
         << "enter the postion where you want to insert the  element = ";
    cin >> position;
    cout << "enter the number you want to print at that position = ";
    cin >> number_at_given_position;
    insert_at_any_given_position(position, number_at_given_position);
    display();

    // delete at first
    int k = delete_at_first();
    if (k == 0)
    {
        cout << "unhderflow";
    }
    else
    {
        cout << "\n\n";
        display();
    }

    // delete at given position
    int delete_position;

    cout << "\n"
         << " enter the position you want to delete = ";
    cin >> delete_position;
    dlt_at_given_postion(delete_position);
    display();
    return 0;
}
