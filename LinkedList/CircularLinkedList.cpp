#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

void insertNode(node* &tail, int data, int value){
    node* temp = tail;

    if(tail==NULL){
        node* newNode = new node;
        newNode->data = data;
        newNode->next = newNode;

        tail = newNode;
    }
    else{
        while(temp->data != value){
            temp = temp->next;
        }

        //New node creation
        node* newNode = new node;
        newNode->data = data;
        newNode->next = temp->next;

        //Previous node pointing to new node created
        temp->next = newNode;
    }
}

void deleteNode(node* &tail, int data){

    if(tail == NULL){
        cout << "List is Empty! cannot delete" << endl;
        return;
    }
    else if(tail->next = tail){
        node* prev = tail;
        tail == NULL;

        delete prev;
        return;
    }

    node* prev = tail;
    node* curr = prev->next;

    while(curr->data != data){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    delete curr;
}

void print(node* &tail){

    if(tail == NULL){
        cout << "List is Empty, cannot traverse" << endl;
        return;
    }

    node* temp = tail;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail);

    cout << endl;

}


int main(){

    node* tail = NULL;

    print(tail);

    insertNode(tail, 1, 0);
    // insertNode(tail, 2, 1);
    // insertNode(tail, 3, 2);
    // insertNode(tail, 4, 3);
    // insertNode(tail, 5, 4);

    print(tail);

    deleteNode(tail, 1);

    print(tail);


    return 0;
}