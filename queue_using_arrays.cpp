#include <iostream>
#define N 5
using namespace std; 

int queue[N]; 
int front = -1; 
int rear = -1; 



//ENQUE(insertion)

void enqueue(int n){

    if(rear == N-1){
        cout << "queue is full" << endl; 

    }
    else if (front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = n;   

      }
      else {
        rear++;
        queue[rear] = n; 
      }
}



//DEQEUE (DELETION)

void dequeue(){
    if(front ==-1 && rear ==-1){
        cout << "empty queue" <<endl; 

    } else if(front == rear){
        front = rear == -1; 

    }   
    else {
        cout << "deleted item: " << queue[front] << endl; 
        front++; 
    }

  }




//PEEK (SHOW FIRST ELEMENT WITHOUT REMOVING)

void Peek(){
    if(front == -1 && rear == -1){
        cout << "empty queue" << endl; 
    }
    else {
        cout << queue[front] << endl; 
    }
}




//DISPLAY ALL ELEMENTS

void display(){ 

    if(front == -1 && rear == -1){
        cout << "empty queue" << endl; 

    }
    else{
        for(int i = front; i<= rear+1; i++){
            cout << queue[i] <<endl;
        }
    }


}

//sample cases

int main(){
    enqueue(5); 
    enqueue(4);
    enqueue(3); 
    dequeue();
    dequeue();
    enqueue(9); 
    Peek();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    display();


    


}


