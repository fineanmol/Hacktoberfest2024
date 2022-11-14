//Advantages of Doubly linked list over singly linked list:
//1. It can be traversed in both the directions.
//2. We can delete any node in o(1) time with the reference pointer to it.
//3. We can insert/delete before a given node.
//4. We can insert/delete from both ends in o(1) time by maintaining both head and tail.

//Disadvantages of Doubly linked list over singly linked list:
//1. Extra space for previous
//2. Code becomes more complex

#include<bits/stdc++.h>
using namespace std;

struct node{
	node *prev;
	int data;
	node *next;
	node(int value){
		prev=NULL;
		data=value;
		next=NULL;
	}
};

void display(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

node *head = new node(10);
node *temp1 = new node(20);
node *temp2 = new node(30);

head->next = temp1;
temp1->prev = head;
temp1->next = temp2;
temp2->prev = temp1;

display(head);
}