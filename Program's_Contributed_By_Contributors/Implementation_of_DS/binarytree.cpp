#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	// Val is the key or the value that
	// has to be added to the data part
	Node(int val)
	{
		data = val;
		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}
};

int main()
{
	/*create root*/
	Node* root = new Node(1);

	/* following is the tree after above statement
	1
	/ \
	NULL NULL
	*/
	root->left = new Node(2);
	root->right = new Node(3);

	/* 2 and 3 become left and right children of 1
	1
	/ \
	2 3
	/ \ / \
	NULL NULL NULL NULL
	*/
	root->left->left = new Node(4);
	/* 4 becomes left child of 2
		1
	/ \
	2	 3
	/ \ / \
	4 NULL NULL NULL
	/ \
	NULL NULL
	*/
	return 0;
}
