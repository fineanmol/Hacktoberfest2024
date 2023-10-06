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
	head1->val = 7;
	head2->val = 3;
	one->val = 5;
	two->val = 8;
	three->val = 9;
	four->val = 1;
	five->val = 6;
	head1->next = one;
	one->next = three;
	head2->next = two;
	two->next = four;
	three->next = NULL;
	four->next = five;
	five->next = NULL;
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

	Node* dummy = new Node();
	temp = dummy;
	int carry = 0;
	while(head1 or head2 or carry)
	{
		int sum = 0;
		if(head1)
			{
				sum+=head1->val;
				head1 = head1->next;
			}
		if(head2)
			{
				sum+=head2->val;
				head2 = head2->next;
			}
		sum+=carry;
		carry = sum/10;
		sum%=10;
		Node* new_node = new Node();
		new_node->val = sum;
		temp->next = new_node;
		temp = temp->next;
	}

	dummy = dummy->next;
	while(dummy!=NULL)
	{
		cout<<dummy->val<<"->";
		dummy = dummy->next;
	}
	cout<<"NULL"<<endl;
	
	return 0;
}