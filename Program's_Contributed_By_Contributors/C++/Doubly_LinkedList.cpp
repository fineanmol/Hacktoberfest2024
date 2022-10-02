#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node* lft;
    struct node* rgt;
    node(int d){
        this->data=d;
        this->rgt=NULL;
    }
};

void display(node* cur){
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur=cur->rgt;
    }
    cout<<"\n";
}

void atTail(node* &tail,int d){
    node* temp = new node(d);
    temp->lft=tail;
    temp->rgt=NULL;
    tail->rgt=temp;
    tail=temp;
}

void atHead(node* &head,int d){
    node* temp = new node(d);
    head->lft=temp;
    temp->rgt=head;
    head=temp;
}

void atPos(node* cur,int d,int pos){
    node *temp = new node(d);
    pos--;
    while(pos-->1){
        cur = cur->rgt;
    }
    temp->lft=cur;
    temp->rgt=cur->rgt;
    cur->rgt->lft=temp;
    cur->rgt=temp;
}

void delHead(node* &head){
    node* temp = head->rgt;
    head->rgt=NULL;
    head=temp;
    head->lft=NULL;
}

void delTail(node* &tail){
    node* temp = tail->lft;
    tail->lft=NULL;
    tail=temp;
    tail->rgt=NULL;   
}

void delPos(node* cur,int pos){
    pos--;
    while(pos-->1){
        cur = cur->rgt;
    }
    cur->rgt=cur->rgt->rgt;
    cur = cur->rgt;
    cur->lft=cur->lft->lft;
}

int main(void){
    int n,d,x,p;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    cin>>d;
    node* head = new node(d);
    node* tail = head;
    x=n-1;
    while(x--){
        cin>>d;
        atTail(tail,d);
    }
    cout<<"Value to add at head: ";
    cin>>d;
    atHead(head,d);
    display(head);

    cout<<"Value to add on tail: ";
    cin>>d;
    atTail(tail,d);
    display(head);

    cout<<"Value to add at any position: ";
    cin>>d;
    cout<<"Position to add on: ";
    cin>>p;
    atPos(head,d,p);
    display(head);

    cout<<"Deleting at head...\n";
    delHead(head);
    display(head);

    cout<<"Deleting at tail...\n";
    delTail(tail);
    display(head);

    cout<<"Enter the position to delete on: ";
    cin>>p;
    delPos(head,p);
    display(head);
    return 0;    
}
