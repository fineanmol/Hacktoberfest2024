/* C++ program to merge two sorted linked lists */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* pull off the front node of
the source and put it in dest */
void MoveNode(Node** destRef, Node** sourceRef);

/* Takes two lists sorted in increasing
order, and splices their nodes together
to make one big sorted list which
is returned. */
Node* SortedMerge(Node* a, Node* b)
{
	/* a dummy first node to hang the result on */
	Node dummy;

	/* tail points to the last result node */
	Node* tail = &dummy;

	/* so tail->next is the place to
	add new nodes to the result. */
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs out, use the
			other list */
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the
node from the front of the source,
and move it to the front of the dest.
It is an error to call this with the
source list empty.
Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}
After calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(Node** destRef, Node** sourceRef)
{
	/* the front source node */
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}


/* Function to insert a node at
the beginning of the linked list */
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

	/* Let us create two sorted linked lists
	to test the functions
	Created lists, a: 5->10->15, b: 2->3->20 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = SortedMerge(a, b);

	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}
