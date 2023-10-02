#include <iostream>
#define MAX 8
using namespace std;

// Declaration of the stack struct
struct Stack {
	int top, data[MAX];
} Stack;

void init() {
	Stack.top = -1;
}

bool isEmpty() {
	return Stack.top == -1;
}

bool isFull() {
	return Stack.top == MAX - 1;
}

void push() {
	if (isFull()) {
		cout << "\nStack is full" << endl;
	}
	else {
		Stack.top++;
		cout << "\nEnter data = ";
		cin >> Stack.data[Stack.top];
		cout << "Data " << Stack.data[Stack.top] << " pushed into the stack" << endl;
	}
}

void pop() {
	if (isEmpty()) {
		cout << "\nStack is empty\n" << endl;
	}
	else {
		cout << "\nData " << Stack.data[Stack.top] << " has been popped" << endl;
		Stack.top--;
	}
}

void Print() {
	if (isEmpty()) {
		cout << "Stack is empty";
	}
	else {
		cout << "\nStack: ";
		for (int i = Stack.top; i >= 0; i--)
			cout << Stack.data[i] << ((i == 0) ? "" : ",");
	}
}

int main() {
	int choice;
	init();
	do {
		Print();
		cout << "\n1. Push\n"
			<< "2. Pop\n"
			<< "3. Exit\n"
			<< "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 3);
}
