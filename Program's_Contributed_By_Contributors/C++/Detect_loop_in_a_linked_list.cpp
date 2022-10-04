#include <bits/stdc++.h>
using namespace std;
 
// Link list node
struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head_main, int new_data)
{
    // allocate node 
    struct Node* New_Node_temp = new Node;
 
    // put data in New Node
    New_Node_temp->data = new_data;
 
    // link the old list off the new node 
    New_Node_temp->next = (*head_main);
 
    /* move the head to point to the new node */
    (*head_main) = New_Node_temp;
}
 
// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(struct Node* head)
{
    unordered_set<Node*> store;
    while (head != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you will be encountering the
        // node for the second time).
        if (store.find(head) != store.end())
            return true;
 
        // If we are seeing the node for
        // the first time, insert it in hash
        store.insert(head);
 
        head = head->next;
    }
 
    return false;
}
 
//Main function
int main()
{
    //empty list
    struct Node* start = NULL;
 
    push(&start, 23);
    push(&start, 62);
    push(&start, 122);
    push(&start, 153);
    push(&start, 23);
    push(&start, 43);
    push(&start, 422);
    push(&start, 123);
    push(&start, 64);
    push(&start, 103);
    push(&start, 135);
    push(&start, 163);
 
    // Create a loop for testing 
    start->next->next->next->next->next->next = start;
 
    if (detectLoop(start))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}

// This code is contributed by Moksh Gupta


