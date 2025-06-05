#include <iostream>
using namespace std; 

struct node{

    int data; 
    struct node *next; 

};

struct node *front = 0; 
struct node *rear = 0; 



//INSERTING (PUSHING)

void enqueue(int x)
{
    node *newnode = new node; 
    newnode -> data = x; 
    newnode -> next = 0; 

    if(front ==0 && rear ==0){
        front = rear = newnode; 
        rear -> next = front; 
    }

    else {
        rear -> next = newnode; 
        rear = newnode; 
        rear -> next = front; 

    }

}


//DISPLAYING

void display(){
    struct node *temp; 
    if(front == 0 && rear == 0){
        cout << "queue empty" <<endl; 

    }
    else{
        temp = front; 
        while(temp->next != front){
            cout << temp -> data <<endl; 
            temp = temp -> next; 

        }
         cout << temp -> data << endl; 
    }

}


//DELETING (POP)


void dequeue(){
    struct node *temp; 
    temp = front; 

    if(front == 0 && rear == 0){
        cout << "queue empty" <<endl; 
  }
 else if(front == rear){
    front = rear = 0; 
    delete temp; 
}

else {
    cout << front -> data <<endl; // to print deleted data 
    front =  front -> next; 
    rear -> next = front; 
    delete temp; 

}
}


//PEEK 

void peek(){
     if(front == 0 && rear == 0){
        cout << "queue empty" <<endl; 
     } else{
        cout << front  -> data <<endl; 
     }

}



int main(){
    enqueue(5);
    display();
    dequeue();
    peek(); 
    display();

    
    return 0; 

}
