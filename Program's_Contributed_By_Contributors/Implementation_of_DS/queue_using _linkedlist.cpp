#include<iostream>
using namespace std;

typedef struct node{
    int number;
    struct node *next;
}node;

node* front = NULL;
node* rear = NULL;

void insert(){
    int n;
    cout << "Enter the element : ";
    cin >> n;
    node* temp = (node*)malloc(sizeof(node));
    if(front==NULL){
        temp->number=n;
        temp->next=NULL;
        rear=temp;
        front=rear;
    }
    else{
        temp->number = n;
        temp->next = NULL;
        rear -> next = temp ;
        rear = temp;
    }
}
void del(){
    if(front == NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
        node* ptr = (node*)malloc(sizeof(node));
        ptr = front;
        cout<<ptr->number<<" deleted from queue\n";
        front = front->next;
        free(ptr);
    }
}
void display(){
    if(!front){
        cout<<"The Queue is Empty!!!\n";
    }
    else {
         for(node* i = front;front!=NULL;i=i->next){
            cout<<i->number<<" "<<"\t";
         }
    }
}

int main(){
    while(1){
        cout << endl << "Menu:" << endl;
        cout << "1. Insert the element" << endl;
        cout << "2. Delete an element from the queue." << endl;
        cout << "3. Display elements of a queue." << endl;
        cout << "4. Exit." << endl;
        cout << "Enter your choice: ";
        int x;
        cin >> x;

        switch(x){
            case 1:
                insert();
                break;
            case 2:
                 del();
                 break;
            case 3:
                 display();
                 break;
            case 4:
                 exit(1);
                 break;
        }
    }
}