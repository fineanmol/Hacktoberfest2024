//Menu driven circular queue using array in  C++
#include<iostream>
using namespace std;
# define max 5

class cqueue {
    int front,rear;
    int a[max];  
  public:
    cqueue() { front=rear=-1; }
    void addq(int);
    void delq();
    void display();
};

void cqueue :: addq(int num) {

    if(front == 0 && rear == max-1 || rear == front-1) {
        cout<<"Queue is full";
    }
    else{

        if(rear = max-1)
          rear=0;
        else
          rear++;
      
        a[rear]=num;
      
        if(front==-1)
          front=0;
    }

}    

void cqueue :: display() {

    if(front == -1)
        cout << "Queue is empty "<< endl;

    else {
        if(front<=rear)
          for(int i=front;i<=rear;i++)
            cout<<a[i]<<" ";
        else {
            for(int i=front;i<=max-1;i++)
              cout<<a[i]<<" ";
            for(int i=0;i<=rear;i++)
              cout<<a[i]<<" ";
        }
    }
} 

void cqueue :: delq() {

    if(front == -1)
        cout << " queue is empty" << endl;
    else{
      
        cout<<"Deleted element is "<<a[front];

        if(front == rear)
            front = rear=-1;
        else 
            if(front == max-1 )
                 front = 0; 
            else
                 front++;
          
        }

}

int main() {
    cqueue q;
    int ch;
    while(1)
{
cout<<"\n1.INSERT   2.DELETE   3.DISPLAY    4.EXIT\nEnter your choice";
cin >> ch;
switch(ch)
{
case 1: cout<<"Enter element: ";
        cin >> ch;
        q.addq(ch); break;

case 2: q.delq(); break;
case 3: q.display(); break;
case 4: exit(0);
default: cout<<"Invalid choice";
}
}
    return 0;
}
