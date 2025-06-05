#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* next;
}Node;

Node* reverseList(Node* head)
{
	if (head->next == NULL)
		return head;
	Node* rest = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

Node* sortedMerge(Node* a, Node* b)
{
	a = reverseList(a);
	b = reverseList(b);
	Node* head = NULL;
	Node* temp;
	while (a != NULL && b != NULL) {
		if (a->key >= b->key) {
			temp = a->next;
			a->next = head;
			head = a;
			a = temp;
		}
		else {
			temp = b->next;
			b->next = head;
			head = b;
			b = temp;
		}
	}
	while (a != NULL) {
		temp = a->next;
		a->next = head;
		head = a;
		a = temp;
	}

	while (b != NULL) {
		temp = b->next;
		b->next = head;
		head = b;
		b = temp;
	}

	return head;
}


// Print the Linklist
void printList(struct Node* Node)
{
	while (Node != NULL) {
		printf("%d ",Node->key);
		Node = Node->next;
	}
}
Node* newNode(int key)
{
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->key = key;
	temp->next = NULL;
	return temp;
}

int main(){
	struct Node* res = NULL;
    // a: 5->10->15->40
    // b: 2->3->20->23 

    // List 1
	Node* a = newNode(5);
	a->next = newNode(10);
	a->next->next = newNode(15);
	a->next->next->next = newNode(40);

    // List 2
	Node* b = newNode(2);
	b->next = newNode(3);
	b->next->next = newNode(20);
    b->next->next = newNode(23);

	printf("List A before merge: \n");
	printList(a);

	printf("\nList B before merge: \n");
	printList(b);

	/* merge 2 sorted Linked Lists */
	res = sortedMerge(a, b);

	printf("\nMerged Linked List is: \n");
	printList(res);

	return 0;
}