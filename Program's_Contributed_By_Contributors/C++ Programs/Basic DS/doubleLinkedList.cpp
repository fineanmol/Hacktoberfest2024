#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node * next;
        Node * prev;
};

void printForward(Node * head){
    Node * Traverser = head;
    while (Traverser != nullptr){
        cout << Traverser->val << endl;
        Traverser = Traverser->next;
    }
    
}

void printBackward(Node * tail){
    Node * Traverser = tail;
    while (Traverser != nullptr){
        cout << Traverser->val << endl;
        Traverser = Traverser->prev;
    }
    
}

int main(){

    Node * head;
    Node * tail;

    // Adding  first node 
    Node * n1 = new Node();
    n1 -> val = 4;
    n1 -> next = nullptr;
    n1 -> prev = nullptr;
    head = n1;
    tail = n1;

    // Adding 2nd node
    n1 = new Node();
    n1 -> val = 5;
    n1 -> next = nullptr;
    n1 -> prev = tail;
    tail -> next = n1;
    tail = n1;

    // Add 3rd Node
    n1 = new Node();
    n1 -> val = 6;
    n1 -> next = nullptr;
    n1 -> prev = tail;
    tail -> next = n1;
    tail = n1;

    // Adding 4th node
    n1 = new Node();
    n1 -> val = 7;
    n1 -> next = nullptr;
    n1 -> prev = tail;
    tail -> next = n1;
    tail = n1;

    cout << "Forward Traversing" << endl;
    printForward(head);

    cout << "Backward Traversing" << endl;
    printBackward(tail);


    system("pause>0");
}