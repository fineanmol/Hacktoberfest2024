// 450dsa q18 : Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void addAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

Node *reverse(Node *head)
{
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}
bool isPalindrome(Node *head)
{
    if (head->next == nullptr)
    {
        return true;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = reverse(slow->next);
    fast = head;
    while (slow != NULL)
    {
        if (slow->data != fast->data)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        addAtTail(head, ele);
    }
    cout << isPalindrome(head);
    return 0;
}