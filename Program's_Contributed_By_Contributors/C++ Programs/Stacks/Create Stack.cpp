/* C++ program to implement basic stack operations */
#include <bits/stdc++.h> 

using namespace std; 

#define MAX 1000 

class Stack { 
	int top; 

public: 
	int a[MAX]; // Maximum size of Stack 

	Stack() { top = -1; } 
	bool push(int x); 
	int pop(); 
	int peek(); 
	bool isEmpty(); 
}; 

bool Stack::push(int x) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		a[++top] = x; 
		cout << x << " pushed into stack\n"; 
		return true; 
	} 
} 

int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[top--]; 
		return x; 
	} 
} 
int Stack::peek() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else { 
		int x = a[top]; 
		return x; 
	} 
} 

bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
	class Stack s; 
	s.push(10); 
	s.push(20); 
	s.push(30); 
	cout << s.pop() << " Popped from stack\n"; 
	
	//print top element of stack after popping 
	cout << "Top element is : " << s.peek() << endl; 
	
	//print all elements in stack : 
	cout <<"Elements present in stack : "; 
	while(!s.isEmpty()) 
	{ 
		// print top element in stack 
		cout << s.peek() <<" "; 
		// remove top element in stack 
		s.pop(); 
	} 

	return 0; 
}
