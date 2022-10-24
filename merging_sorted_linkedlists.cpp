// C++ program to merge two sorted 
// linked lists in-place.
#include <bits/stdc++.h>
using namespace std;
  
struct Node 
{
    int data;
    struct Node* next;
};
  
// Function to create newNode in 
// a linkedlist
struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
  
// A utility function to print 
// linked list
void printList(struct Node* node)
{
    while (node != NULL) 
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
  
// Merges two lists with headers as h1 
// and h2. It assumes that h1's data is 
// smaller than or equal to h2's data.
struct Node* mergeUtil(struct Node* h1,
                       struct Node* h2)
{
    // If only one node in first list
    // simply point its head to second list
    if (!h1->next) 
    {
        h1->next = h2;
        return h1;
    }
  
    // Initialize current and next pointers 
    // of both lists
    struct Node *curr1 = h1, 
                *next1 = h1->next;
    struct Node *curr2 = h2, 
                *next2 = h2->next;
  
    while (next1 && curr2) 
    {
        // if curr2 lies in between curr1 
        // and next1 then do curr1->curr2->next1
        if ((curr2->data) >= (curr1->data) && 
            (curr2->data) <= (next1->data)) 
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
  
            // now let curr1 and curr2 to point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else 
        {
            // if more nodes in first list
            if (next1->next) 
            {
                next1 = next1->next;
                curr1 = curr1->next;
            }
  
            // else point the last node of 
            // first list to the remaining 
            // nodes of second list
            else 
            {
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}
  
// Merges two given lists in-place. 
// This function mainly compares head 
// nodes and calls mergeUtil()
struct Node* merge(struct Node* h1,
                   struct Node* h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;
  
    // start with the linked list
    // whose head data is the least
    if (h1->data < h2->data)
        return mergeUtil(h1, h2);
    else
        return mergeUtil(h2, h1);
}
  
// Driver code
int main()
{
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
  
    // 1->3->5 LinkedList created
    struct Node* head2 = newNode(0);
    head2->next = newNode(2);
    head2->next->next = newNode(4);
  
    // 0->2->4 LinkedList created
    struct Node* mergedhead = merge(head1, head2);
  
    printList(mergedhead);
    return 0;
}
