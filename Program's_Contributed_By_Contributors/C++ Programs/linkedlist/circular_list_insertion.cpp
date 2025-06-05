#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        // constructor
        Node(int d){
            this -> data = d;
            this -> next = NULL;
        }

        // destructor
        ~Node(){
            int value = this -> data;
            if(this -> next != NULL){
                delete next;
                next = NULL;
            }
            cout << "Memory free!" << value << endl;
        }
};

// insertion of node
void insertNode(Node* &tail, int element, int d){

    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // non empty list
        // assuming the element is already in the list
        Node *curr = tail;

        while(curr -> data != element){
            curr = curr -> next;
        }

        // element found which is represenetd by curr
        Node *temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

// traverse the linked list
void print(Node *tail){
    Node *temp = tail;

    do{
        cout << temp -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);
    return 0;
}
