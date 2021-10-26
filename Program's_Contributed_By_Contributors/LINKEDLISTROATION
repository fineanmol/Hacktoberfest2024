// C++ program to rotate
// a linked list counter clock wise

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

// This function rotates a linked list
// counter-clockwise and updates the
// head. The function assumes that k is
// smaller than size of linked list.
// It doesn't modify the list if
// k is greater than or equal to size
void rotate(Node** head_ref, int k)
{
	if (k == 0)
		return;

	// Let us understand the below
	// code for example k = 4 and
	// list = 10->20->30->40->50->60.
	Node* current = *head_ref;

	// current will either point to
	// kth or NULL after this loop.
	// current will point to node
	// 40 in the above example
	int count = 1;
	while (count < k && current != NULL) {
		current = current->next;
		count++;
	}

	// If current is NULL, k is greater than
	// or equal to count of nodes in linked list.
	// Don't change the list in this case
	if (current == NULL)
		return;

	// current points to kth node.
	// Store it in a variable. kthNode
	// points to node 40 in the above example
	Node* kthNode = current;

	// current will point to
	// last node after this loop
	// current will point to
	// node 60 in the above example
	while (current->next != NULL)
		current = current->next;

	// Change next of last node to previous head
	// Next of 60 is now changed to node 10
	current->next = *head_ref;

	// Change head to (k+1)th node
	// head is now changed to node 50
	*head_ref = kthNode->next;

	// change next of kth node to NULL
	// next of 40 is now NULL
	kthNode->next = NULL;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code*/
int main(void)
{
	/* Start with the empty list */
	Node* head = NULL;

	// create a list 10->20->30->40->50->60
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	rotate(&head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}

// This code is contributed by rathbhupendra
