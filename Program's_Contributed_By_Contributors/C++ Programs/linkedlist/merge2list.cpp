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
	head1->val = 1;
	head2->val = 1;
	one->val = 2;
	two->val = 3;
	three->val = 4;
	four->val = 5;
	head1->next = one;
	one->next = three;
	head2->next = two;
	two->next = four;
	three->next = NULL;
	four->next = NULL;
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

	
	if(head1->val>head2->val)
	{
		swap(head1,head2);
	}
	Node* res = head1;

	while(head1!=NULL and head2!=NULL)
	{
		Node* tmp = NULL;
		while(head1!=NULL and head1->val<=head2->val)
		{
			tmp = head1;
			head1 = head1->next;
		}
		tmp->next = head2;
		swap(head1,head2);
	}

	while(res!=NULL)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<"NULL"<<endl;
	return 0;
}