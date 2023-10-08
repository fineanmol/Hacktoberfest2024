#include<bits/stdc++.h> 
using namespace std; 

/* Linked list Node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

// To remove complete list (Needed for 
// case when k is 1) 
void freeList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		Node *next = node->next; 
		delete (node); 
		node = next; 
	} 
} 

// Deletes every k-th node and returns head 
// of modified list. 
Node *deleteKthNode(struct Node *head, int k) 
{ 
	// If linked list is empty 
	if (head == NULL) 
		return NULL; 

	if (k == 1) 
	{ 
	freeList(head); 
	return NULL; 
	} 

	// Initialize ptr and prev before starting 
	// traversal. 
	struct Node *ptr = head, *prev = NULL; 

	// Traverse list and delete every k-th node 
	int count = 0; 
	while (ptr != NULL) 
	{ 
		// increment Node count 
		count++; 

		// check if count is equal to k 
		// if yes, then delete current Node 
		if (k == count) 
		{ 
			// put the next of current Node in 
			// the next of previous Node 
			delete(prev->next); 
			prev->next = ptr->next; 

			// set count = 0 to reach further 
			// k-th Node 
			count = 0; 
		} 

		// update prev if count is not 0 
		if (count != 0) 
			prev = ptr; 

		ptr = prev->next; 
	} 

	return head; 
} 

/* Function to print linked list */
void displayList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while (temp != NULL) 
	{ 
		cout<<temp->data<<" "; 
		temp = temp->next; 
	} 
} 

// Utility function to create a new node. 
struct Node *newNode(int x) 
{ 
	Node *temp = new Node; 
	temp->data = x; 
	temp->next = NULL; 
	return temp; 
} 

/* Driver program to test count function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(5); 
	head->next->next->next->next->next = newNode(6); 
	head->next->next->next->next->next->next = 
										newNode(7); 
	head->next->next->next->next->next->next->next = 
										newNode(8); 

	int k = 3; 
	head = deleteKthNode(head, k); 

	displayList(head); 

	return 0; 
} 
