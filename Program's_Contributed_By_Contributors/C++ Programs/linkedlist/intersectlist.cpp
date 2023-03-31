#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
};

int main()
{
	Node* head1 = new Node();
	Node* head2 = new Node();
	Node* one = new Node();
	Node* two = new Node();
	Node* three = new Node();
	Node* four = new Node();
	Node* five = new Node();
	Node* six = new Node();
	head1->val = 1;
	head2->val = 1;
	one->val = 2;
	two->val = 3;
	three->val = 4;
	four->val = 5;
	five->val = 8;
	six->val = 2;
	head1->next = one;
	one->next = three;
	three->next = four;
	head2->next = two;
	two->next = four;
	four->next = five;
	five->next = six;
	six->next = NULL;

	Node* temp = head1;
	while(temp)
	{
		cout<<temp->val<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;

	temp = head2;
	while(temp)
	{
		cout<<temp->val<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;

	Node* a = head1;
	Node* b = head2;

	while(a!=b)
	{
		a=a==NULL?head2:a->next;
		b=b==NULL?head1:b->next;
	}
	cout<<a->val<<endl;

	return 0;
}
	