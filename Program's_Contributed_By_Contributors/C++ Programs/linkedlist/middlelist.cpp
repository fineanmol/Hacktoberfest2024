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
	if(head==NULL)
            return 0;
        Node* slow = head;
        Node* fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    cout<<slow->val<<endl;
    return 0;
}