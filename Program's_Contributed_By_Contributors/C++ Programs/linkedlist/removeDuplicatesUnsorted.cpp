#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *newNode = new Node(d);
        // newNode->next = head;
        head = newNode;
    }

    else
    {
        Node *newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }
}

Node *removeDuplicates(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }
    unordered_map<int, bool> visited;
    Node *prev = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited.find(temp->data) != visited.end())
        {
            prev->next = temp->next;
            delete (temp);
        }
        else
        {
            // traverse
            visited[temp->data] = true;
            prev = temp;
        }
        temp = prev->next;
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    Node *head = NULL;

    insertAtHead(head, 8);
    insertAtHead(head, 9);
    insertAtHead(head, 4);
    insertAtHead(head, 8);
    insertAtHead(head, 9);
    insertAtHead(head, 7);
    cout << "LinkedList before :";
    print(head);

    cout << "LinkedList after removing duplicates : ";
    removeDuplicates(head);

    print(head);

    return 0;
}