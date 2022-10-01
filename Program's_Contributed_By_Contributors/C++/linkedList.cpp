#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

class Node{
    public:
        int data;
        Node *next;
    
};

class LinkedList{
    private:
        Node *first;
        Node *last;
    public:
        LinkedList(){
            first=NULL;
        }
        LinkedList(int A[],int n);
        ~LinkedList();
        void Display();
        int Length();
        int Sum();
        int max();
        void insertAtHead(int x);
        void insertAtTail(int x);
        void insert(int index,int x);
        int Delete(int index);
        bool isSorted();
        void removeDuplicatesSorted();
        void reverseLink();
};

int main()
{
    int A[]={1,2,3,4,5};
    LinkedList L(A,5);
    L.reverseLink();
    L.Display(); 
    cout<<"Length is:"<<L.Length()<<endl<<"Sum is:"<<L.max()<<endl;
    return 0;
}

LinkedList::LinkedList(int A[],int n){
    Node *t;
    int i=0;

    first= new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

    }

LinkedList::~LinkedList(){
            Node *temp=first;
            while(temp!=NULL){
                first=first->next;
                delete temp;
                temp=first;
            }
        };

void LinkedList::Display(){
            Node *temp=first;
            cout<< first->data<<" "<<last->data<<endl;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        };

int LinkedList::Length(){
            Node *temp=first;
            int count=0;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            return count;
        };

int LinkedList::Sum(){
            Node *temp=first;
            int sum=0;
            while(temp!=NULL){
                sum+= temp->data;
                temp=temp->next;
            }
            return sum;
        };

int LinkedList::max(){
            Node *temp=first;
            int max=0;
            while(temp!=NULL){
                if(temp->data>max)
                    max=temp->data;
                temp=temp->next;
            }
            return max;
        };

void LinkedList::insertAtHead(int x){
            Node *temp=new Node;
            temp->data=x;
            temp->next=first;
            first=temp;
        };

void LinkedList::insertAtTail(int x){
            Node *temp=new Node;
            if(first==NULL){
                temp->data=x;
                first=temp;
                last=temp;
            }
            else{
                temp->data=x;
                last->next=temp;
                last=temp;
                temp->next=NULL;
            }
            }

void LinkedList::insert(int index,int x){

    if(index==1){
        insertAtHead(x);
        return;
    }
    Node* temp=first;
    int i=1;
    while(i<index-1){
        temp=temp->next;
        i++;
    }  
    if(temp->next==NULL){
        insertAtTail(x);
        return ;
    }

        Node* element= new Node;
        element->data=x;
        element->next=temp->next;
        temp->next = element;
    
};

int LinkedList::Delete(int index){
    Node *p,*q=NULL;
    if(index<1 || index>Length()){return 0;}
    int x=0;
    if(index==1){
        p=first;
        first=p->next;
        x=p->data;
        p->next=NULL;
        delete p;
        return x;
    }else{
        p=first;
        for(int i=1;i<index;i++){
            q=p;
            p=p->next;
        }
        if(p->next==NULL){
            q->next=p->next;
            x=p->data;
            last=q;
            p->next=NULL;
            delete p;
            return x;
        }
            q->next=p->next;
            p->next=NULL;
            x=p->data;
            delete p;
        
    }
    return x;
    
}

bool LinkedList::isSorted(){
    Node* p=first;
    int x=INT16_MIN;
    while(p->next!=NULL){
        if(p->data>x){
            x=p->data;
        }else{
            return false;
        }
        p=p->next;
    }
    return true;
}

void LinkedList::removeDuplicatesSorted(){
    Node* p=first;
    Node* q=NULL;
    q=p->next;
    while(q->next!=NULL){
        if(p->data==q->data){
            p->next=q->next;
            delete q;
            q=p->next;
        }
        else{
            p=q;
            q=q->next;
        }
    }
}

void LinkedList::reverseLink(){
    Node* p=first;
    Node* q=NULL;
    Node* r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    last=first;
    first=q;
}