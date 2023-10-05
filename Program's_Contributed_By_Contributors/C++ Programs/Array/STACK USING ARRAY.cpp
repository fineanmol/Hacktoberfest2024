//Implementation of STACK using ARRAY by Shubham.

#include<iostream>
#include<conio.h>
using namespace std;
#define N 5     // Defining Size of Array
int stack[N];
int top = -1;
void push(){
	cout<<"\n";
	int user_elem;
	cout<<"Enter the element to be inserted to the top : ";
	cin>>user_elem;
	if(top==N-1){
		cout<<"\n\nThe Stack is Full !\n";   //overflow
	}
	else{
		top++;
		stack[top] = user_elem;
	}
}
void pop(){
	cout<<"\n";
	int popped_elem;
	if(top==-1){
		cout<<"\n\nThe Stack is empty !\n";  //underflow
	}
	else{
		popped_elem = stack[top];
		top--;
		cout<<"The deleted element is : "<<popped_elem<<endl;
	}
}
void peek(){
	cout<<"\n";
	if(top==-1){
		cout<<"\n\nThe stack is empty !"<<endl;  //underflow
	}
	else{
		cout<<"The element on the top is : "<<stack[top]<<"\n";
	}
}
void display(){
	cout<<"\n";
	if(top==-1){
		cout<<"\n\nThe stack is empty !"<<endl;  //underflow
	}
	else{
		for(int i=top;i>=0;i--){
			cout<<stack[i]<<" ";
		}
	}
}
int main(){
	cout<<"Name   - Shubham Mishra"<<endl;
	cout<<"Enroll - 0832CS221196"<<endl;
	int user_choice;
	cout<<"\n*** Welcome to STACK Implementation using array program! ***\n\n";
	do{
		cout<<"\n\n";
		cout<<"\nPress 1 to push an element to the STACK.\n";
		cout<<"\nPress 2 to pop an element from the STACK.\n";
		cout<<"\nPress 3 to display the top element in the STACK.\n";
		cout<<"\nPress 4 to display all the elements of the STACK.\n";
		cout<<"\nPress 0 to Exit from the Program.\n";
		cout<<"\n\nEnter your choice : ";
		cin>>user_choice;
		switch(user_choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 0:
				cout<<"\n\nSuccessfully exited the program !";
				return 0;
				break;
			default:
				cout<<"Invalid Choice ! Please try again....";
		}		
	}
	while(user_choice!=0);
		getch();
	}
