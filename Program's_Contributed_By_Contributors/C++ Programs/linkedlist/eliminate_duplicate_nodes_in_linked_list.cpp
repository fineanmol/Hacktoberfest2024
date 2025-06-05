#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;
/*
void removeduplicate(node *head)
{
    node *ptr1 = NULL;
    node *ptr2 = NULL;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL && ptr2->data == ptr1->data)
        {
            node *p = ptr2;
            ptr2 = ptr2->next;
            delete p;
        }
        ptr1->next = ptr2;
        ptr1 = ptr2;
    }
}
*/
void removeduplicates(node *head)
{
    /* Pointer to traverse the linked list */
    node *current = head;

    /* Pointer to store the next pointer of a node to be deleted*/
    node *next_next;

    /* do nothing if the list is empty */
    if (current == NULL)
        return;

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
        /* Compare current node with next node */
        if (current->data == current->next->data)
        {
            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else /* This is tricky: only advance if no deletion */
        {
            current = current->next;
        }
    }
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void push(node **head, int data)
{
    node *newnode = (node *)malloc(1 * sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if ((*head) == NULL)
    {
        (*head) = newnode;
        return;
    }
    node *p2 = (*head);
    while (p2->next != NULL)
    {
        p2 = p2->next;
    }
    p2->next = newnode;
    /* allocate node
    node *new_node = new node();

    new_node->data = new_data;


    new_node->next = (*head_ref);


    (*head_ref) = new_node;
    */
}

int main()
{
    node *head1 = NULL;

    int n, data;
    cin >> n;

    while (n--)
    {
        cin >> data;
        push(&head1, data);
    }

    removeduplicates(head1);

    print(head1);
}