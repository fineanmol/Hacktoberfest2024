/*
 * Avl tree's are self-balancing binary search tree such that
 * the balance factor of each node will be -1 or 0 or 1.
 */

#include <iostream>

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int data, height;
	TreeNode(const int& data): data(data), left(nullptr), right(nullptr), height(0){}
};
 
int height(TreeNode* node){
	 //Return the height of the node

	if(node == nullptr){ return -1; }
	return node->height;
}

void updateheight(TreeNode*& node){
	 //Update the height of the node

	if(node == nullptr){ return; }
	node->height = 1 + std::max(height(node->left), height(node->right));
}

int balance_factor(TreeNode* node){	
	 //Find the balance factor of the given node

	if(node != nullptr){ return height(node->right) - height(node->left); }
	return 0;
}

void leftrotation(TreeNode*& node){
	//Rotate the sub-tree rooted with the node to left

	if(node == nullptr){ return; }

	TreeNode* a = node;
	TreeNode* b = node->right;

	a->right = b->left;
	b->left = a;
	node = b;

	updateheight(a);
	updateheight(b);
}

void rightrotation(TreeNode*& node){
	 //Rotate the sub-tree rooted with the node to right

	if(node == nullptr){ return; }

	TreeNode* a = node;
	TreeNode* b = node->left;

	a->left = b->right;
	b->right= a;
	node = b;

	updateheight(a); 
	updateheight(b);
}

void right_leftrotation(TreeNode*& node){
	 //Rotate the sub-tree rooted with the node to the right and then left

	if(node == nullptr){ return; }
	
	rightrotation(node->right);
	leftrotation(node);
}

void left_rightrotation(TreeNode*& node){
	 //Rotate the sub-tree rooted with the node to the left and then right  

	if(node == nullptr){ return; }
	
	leftrotation(node->left);
	rightrotation(node);
}

void insert(TreeNode*& root, const int& data){
	/*
	 * Create and insert the node in the appropriate place of the tree
	 * Update the height of every node in the tree
	 * Check the balance factor of the node and do the appropriate rotation
	 * To make the tree balanced
	 */

	if(root == nullptr) { 
		root = new TreeNode(data);
	}
	else if(root->data < data){ insert(root->right, data); }
	else{ insert(root->left, data); }

	updateheight(root);

	const int initial_bal = balance_factor(root) ; 

	if(initial_bal == 2){
		int r_bal = balance_factor(root->right);
		if(r_bal == 1 || r_bal == 0){ leftrotation(root); }	
		else if(r_bal == -1){ right_leftrotation(root); }
	}
	else if(initial_bal == -2){
		int l_bal = balance_factor(root->left); 
		if(l_bal == 1 || l_bal == 0){ left_rightrotation(root); } 
		else if(l_bal == -1){ rightrotation(root); }
	}
}

void print(TreeNode* root){
	if(root != nullptr){
		std::cout << root->data << " "; 
		print(root->left);
		print(root->right);
	}
}

int main(){
	TreeNode* root = nullptr;
	insert(root, 1);
        insert(root, 2);
        insert(root, 3);
        insert(root, 4);
        insert(root, 5);
        insert(root, 6);
        insert(root, 7);
        insert(root, 8);
        insert(root, 9);
        insert(root, 10);

	/*

      Binary tree                         
	   1  
	    \
	     2
	      \
	       3
	        \
		 4
		  \
		   5
		    \
		     6
		      \
		       7
		        \
			 8
			  \
			   9
			    \
			     10
	
	Output: 1 2 3 4 5 6 7 8 9 10
	Here the balance factor of the root node is 9    
	
	Average case Time complexity for insert and remove: O(log(n))
	Worst cose Time complexity for insert and remove: O(n)

	AVL Tree
	   4
	 /  \
	2    8
       /\   / \
      1  3 6   9
	  / \   \
	 5   7	 10

	Output: 4 2 1 3 8 6 5 7 9 10
	Here the balance factor of the root node is 1

	Average and worst case time complexity for insert and remove: O(log(n))
	*/

	print(root);
}
