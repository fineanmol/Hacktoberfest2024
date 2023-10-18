#include <iostream>

using namespace std;

class node{
    public:
        int val;
        node * next;

};

void print(node * head){
    while(head!= NULL){
        cout << head-> val << endl;
        head = head -> next; 
    }
}

int main(){
    node * head = new node();
    node * second = new node();
    node * third = new node();

    head -> val = 1;
    head -> next = second;
    second -> val = 2;
    second -> next = third;
    third -> val = 3;
    third -> next = NULL;

    print(head);


    system("pause>0");
}