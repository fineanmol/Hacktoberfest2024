#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
};

int main()
{
	Node* head = new Node();
	Node* one = new Node();
	Node* two = new Node();
	Node* three = new Node();
	Node* four = new Node();
	int n = 5;
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
	Node* dummy = new Node();
	dummy->val = -1;
	dummy->next = head;
	Node* slow = dummy;
	Node* fast = dummy;
	for(int i=0;i<n;i++)
	{
		fast = fast->next;
	}
	while(fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;
	dummy = dummy->next;
	while(dummy)
	{
		cout<<dummy->val<<"->";
		dummy = dummy->next;
	}
	cout<<"NULL"<<endl;
	return 0;
}