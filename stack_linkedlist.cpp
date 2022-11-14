// Header Files and namespaces
#include<bits/stdc++.h>
using namespace std;

// implementing stack using linked list

class node{
public:
    int data;
    node *next;
    //****************constructor*****************creation of a dynamic node*****************
    node(int d){

        data = d;
        next = NULL;

    }
};

class Stack{
    node *head;

    public:

    Stack(){
        head = NULL;
    }

    void push(int d){

        if (head==NULL){
            head = new node(d); //creation of node (pointer) n
        }

        else{
            node* n = new node(d); 
            n->next = head; //next(address) of new node points towards head
            head=n; // head points towards n(new node)
        }

    }

    void pop(){

        if (!head) return;
        node* t = head;
        head = head->next;
        delete t;
        
    }

    bool empty(){
        return head == NULL;
    }

    int top(){

        return head->data;
    }

};



// Code
int main()
{   
    
    Stack s;
    int number;
    cout<<"How many numbers do yo want to push in the stack? ";
    cin>>number;
    for (int i=0; i<number; i++){
        int elem;
        cin>>elem;
        s.push(elem);
    }
    cout<<"printing the elemnts in the stack :"
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
