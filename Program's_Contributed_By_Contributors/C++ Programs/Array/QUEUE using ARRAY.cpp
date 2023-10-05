#include<iostream>
#include<conio.h>
using namespace std;
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(){
	int add_elem;
	cout<<"\nEnter the Element to be added to the Queue : ";
	cin>>add_elem;
	if(rear==N-1){
		cout<<"\nThe QUEUE is FULL !\n";
	}
	else if(rear==-1 && front==-1){
		rear = front = 0;
		queue[rear] = add_elem;
	}
	else{
		rear++;
		queue[rear] = add_elem;
	}
}
void dequeue(){
	int del_elem;
	if(rear == -1 && front == -1){
		cout<<"\nThe Queue is EMPTY !\n";
	}
	else if(rear == front){
		rear = front = -1;
	}
	else{
		del_elem = queue[front];
		front++;
		cout<<"\nThe deleted element is : "<<del_elem<<endl;
	}
}
void peek(){
	if(rear==-1 && front == -1){
		cout<<"The queue is EMPTY !";
	}
	else{
		cout<<"\nThe element at the front is : "<<queue[front]<<endl;
	}
}
void display(){
	if(rear==-1 && front == -1){
		cout<<"\nThe queue is EMPTY !";
	}
	else{
		cout<<"\nThe elements of the QUEUE are : ";
		for(int i = front;i<rear+1;i++){
			cout<<queue[i]<<" ";
		}
	}
}
int main(){
	cout<<"Name   - Shubham Mishra"<<endl;
	cout<<"Enroll - 0832CS221196"<<endl;
	cout<<"\n\n***Welcome to the QUEUE implementation using ARRAY program !***\n\n";
	int user_choice;
	do{
		cout<<"\nPress 1 to enter an element to the QUEUE.\n";
		cout<<"\nPress 2 to remove an element from the QUEUE.\n";
		cout<<"\nPress 3 to display the front element in the QUEUE.\n";
		cout<<"\nPress 4 to display all the elements of the QUEUE. \n";
		cout<<"\n\nEnter your choice : ";
		cin>>user_choice;
		switch(user_choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			default:
				cout<<"\nInvalid choice !....\n\n";
				break;
		}
	}while(user_choice!=0);
		getch();
}
