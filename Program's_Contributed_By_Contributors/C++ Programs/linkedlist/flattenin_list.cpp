// C++ program for flattening a Linked List
#include <bits/stdc++.h>
using namespace std;

// Link list node
class Node {
public:
	int data;
	Node *right, *down;
};

Node* head = NULL;

// An utility function to merge two sorted
// linked lists
Node* merge(Node* a, Node* b)
{

	// If first linked list is empty then second
	// is the answer
	if (a == NULL)
		return b;

	// If second linked list is empty then first
	// is the result
	if (b == NULL)
		return a;

	// Compare the data members of the two linked
	// lists and put the larger one in the result
	Node* result;

	if (a->data < b->data) {
		result = a;
		result->down = merge(a->down, b);
	}

	else {
		result = b;
		result->down = merge(a, b->down);
	}
	result->right = NULL;
	return result;
}

Node* flatten(Node* root)
{

	// Base Cases
	if (root == NULL || root->right == NULL)
		return root;

	// Recur for list on right
	root->right = flatten(root->right);

	// Now merge
	root = merge(root, root->right);

	// Return the root
	// it will be in turn merged with its left
	return root;
}

// Utility function to insert a node at
// beginning of the linked list
Node* push(Node* head_ref, int data)
{

	// Allocate the Node & Put in the data
	Node* new_node = new Node();

	new_node->data = data;
	new_node->right = NULL;

	// Make next of new Node as head
	new_node->down = head_ref;

	// Move the head to point to new Node
	head_ref = new_node;

	return head_ref;
}

void printList()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->down;
	}
	cout << endl;
}

// Driver's code
int main()
{

	/* Let us create the following linked list
		5 -> 10 -> 19 -> 28
		| |	 |	 |
		V V	 V	 V
		7 20 22 35
		|		 |	 |
		V		 V	 V
		8		 50 40
		|			 |
		V			 V
		30			 45
	*/
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->right = push(head->right, 20);
	head->right = push(head->right, 10);

	head->right->right = push(head->right->right, 50);
	head->right->right = push(head->right->right, 22);
	head->right->right = push(head->right->right, 19);

	head->right->right->right
		= push(head->right->right->right, 45);
	head->right->right->right
		= push(head->right->right->right, 40);
	head->right->right->right
		= push(head->right->right->right, 35);
	head->right->right->right
		= push(head->right->right->right, 20);

	// Function call
	head = flatten(head);

	printList();
	return 0;
}

