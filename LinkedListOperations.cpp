#include <iostream>

using namespace std;

class node{
    public:
        int val;
        node *next;
};

void print(node *head){
    while(head!=NULL){
        cout << head->val << endl;
        head=  head-> next; 
    }
}

void insertAtFront(node **head, int newValue){
    //   i) Prepare a new node
    node *newNode= new node();
    newNode-> val= newValue;
    //   ii) Put it in front of LL
    newNode-> next= *head;
    //   iii) Move head of the list to the newNode
    *head= newNode;
}

void insertAtEnd(node **head, int newValue){
    // i) Prepare a new node
    node *newNode = new node();
    newNode->val= newValue;
    newNode->next= NULL;
    // ii) if LinkedList is empty, newNode will be head
    if(*head==NULL){
        *head= newNode;
        return;
    }
    // iii) Find the last node
    node * lastNode = *head;
    while(lastNode->next!=NULL){
        lastNode= lastNode->next;
    }
    // iv) Insert newNode after last node(at the end)
    lastNode -> next= newNode;
}

void insertAfter(node *previous, int newValue){
    // i) check if previous node is NULL
    if(previous==NULL){
        cout << "Previous cannot be NULL" << endl;
    }
    // ii) create newNode
    node *newNode = new node();
    newNode-> val = newValue;
    // iii) Insert newNode after previous
    newNode -> next = previous-> next;
    previous -> next = newNode;
}

int main(){
    node *head = new node();
    node *second = new node();
    node * third = new node();

    head-> val=1;
    head-> next= second;
    second-> val=2;
    second-> next = third;
    third-> val=3;  
    third-> next = NULL;

    // insertAtFront(&head, -1);
    // insertAtFront(&head, -2);
    // insertAtEnd(&head, 4);
    // insertAtEnd(&head, 5);
    insertAfter(head, -1);
    insertAfter(second, -2);
    print(head);


    system("pause>0");
}