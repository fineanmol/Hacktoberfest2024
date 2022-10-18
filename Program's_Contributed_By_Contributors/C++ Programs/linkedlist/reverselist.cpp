#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
};

Node* reverse(Node* head)
{
	Node* dummy = NULL;
	while(head!=NULL)
	{
		Node* temp = head->next;
		head->next = dummy;
		dummy = head;
		head = temp;
	}
	return dummy;
}

int main()
{
	Node* head = new Node();
	Node* one = new Node();
	Node* two = new Node();
	Node* three = new Node();
	Node* four = new Node();
	head->val = 5;
	one->val = 2;
	two->val = 3;
	three->val = 1;
	four->val = 4;
	head->next = one;
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = NULL;
	Node* temp = head;
	while(temp)
	{
		cout<<temp->val<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
	Node* newHead = reverse(head);
	while(newHead)
	{
		cout<<newHead->val<<"->";
		newHead = newHead->next;
	}
	cout<<"NULL"<<endl;

	return 0;
}