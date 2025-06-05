/* Description - We have to print all nodes at a level 'k' of the tree.

For example- If we are given the following tree, the nodes at level 1 are 1, nodes at level 2 are 2,3, nodes at level 3 are 7, 9 and nodes at level 4 are 21 and 11.
(Note- The level starts from 1, i.e root is at level 1)

            1          level 1
          /   \
         2     3       level 2
      	      /  \    
             7    9    level 3
	    /      \
	   21      11  level 4
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int val)
	{
		data= val;
		left=right=NULL;
	}
}node;

//function for level order traversal
void levelorder(Node* root, int k)
{
	if(root==NULL)
		return;
		
	queue<Node*> q;
	
	q.push(root);
	int count=0;  //for calculating at which level we are.
	
	while(!q.empty())
	{
		count++;  //increment the value of count as level is incremented
		int n=q.size();
		
		for(int i=0; i<n; i++)
		{
			Node* temp=q.front();
			q.pop();
			if(count==k) { //if level is equal to the required level, then print its nodes
				cout<<temp->data<<" ";
			}
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
		}	
	}
}

//main function
int main()
{
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->right->left=new node(7);
	root->right->right=new node(9);
	root->right->left->left=new node(21);
	root->right->right->right=new node(11);

	int k = 3;  // here we have taken k=3 (third level of tree)
	
	levelorder(root,k);   //calling level order function
}

// The output of the above program will be 7 9. Since k=3 and nodes at level 3 are 7 and 9.

// Time Complexity: O(n) where n is the number of nodes in the binary tree 
// Space Complexity: O(n) where n is the number of nodes in the binary tree
