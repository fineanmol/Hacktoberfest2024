#include <iostream>

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int data;
	TreeNode(const int& data): data(data), left(nullptr), right(nullptr){}
};

TreeNode* find(TreeNode* root, const int& data){
        /**
         * Find the node that contains the given data and
         * return that node
         *
         * @params: `root` root/parent node of the tree
         * @params: `data` data to be find in the tree
         * @return: tree node that contains the data
         *
         * Average case Time Complexity: O(log(n))
         * Worst case Time Complexity: O(n)
         *
         */

        if(root == nullptr)         { throw std::runtime_error("Error: find() cannot find the data. The data doesn't exist."); }
        else if(root->data == data) { return root; }
        else if(root->data < data)  { return find(root->right, data); }
        else                        { return find(root->left, data); }
}

void Insert(TreeNode*& root, const int& data){
        /**
         * Create and Insert the node in the appropriate place of the tree
         *
         * @params: `root` root/parent node of the tree
         * @params: `data` data to be inserted in the tree
         * @return: void
         *
         * Average case Time Complexity: O(log(n))
         * Worst case Time Complexity: O(n)
         *
         */

        if(root == nullptr)         { root = new TreeNode(data); }
        else if(root->data == data) { throw std::runtime_error("The node already exist. Duplicates not allowed"); }
        else if(root->data < data)  { Insert(root->right, data); }
        else                        { Insert(root->left, data); }
}

TreeNode* rightmost(TreeNode* node){
	/**
	 * Find and return the rightmost value of the sub-tree
	 *
         * @params: `root` root/parent node of the tree
	 *
	 * @return: value of the node at the rightmost end of the sub tree
	 */

	if(node->right == nullptr){ return node; }
	return rightmost(node->right); 
}

TreeNode* predecessor(TreeNode* node, const int& data, TreeNode* value){
	/**
	 * Find and return the previous smallest value to data
	 *
         * @params: `node` root/parent node of the tree
	 * @params: `data` data to compare with
	 * @params: `value` holds the previous smaller value to data
	 *
	 * @return: previous smallest value to data
	 */
	
	if(node->data < data){ return predecessor(node->right, data, node); }	
	else if(node->data > data){ return predecessor(node->left, data, value); }
	return value;
}

TreeNode* in_order_predecessor(TreeNode* root, const int& data){
	/**
	 * Find the in-order predecessor of the given data
	 *
	 * @params: `root` root of the tree 
	 * @params: `data` data where it's predecessor to be found
	 *
	 * @return: in-order predecessor for the given data
	 */

	TreeNode* node = find(root, data);
	if(node->left !=nullptr){ return rightmost(node->left); }
	return predecessor(root, data, nullptr); 
}

TreeNode* leftmost(TreeNode* node){
	/**
	 * Find and return the leftmost value of the sub-tree
	 *
         * @params: `root` root/parent node of the tree
	 *
	 * @return: value of the node at the leftmost end of the sub tree
	 */

	if(node->left == nullptr){ return node; }
	return leftmost(node->left); 
}

TreeNode* successor(TreeNode* node, const int& data, TreeNode* value){
	/**
	 * Find and return the next biggest value to data
	 *
         * @params: `root` root/parent node of the tree
	 * @params: `data` data to compare with
	 * @params: `value` holds the next biggest value to data
	 *
	 * @return: previous smaller value to data
	 */

	if(node->data < data){ return successor(node->right, data, value); }	
	else if(node->data > data){ return successor(node->left, data, node); }
	return value;
}

TreeNode* in_order_successor(TreeNode* root, const int& data){
	/**
	 * Find the in-order successor of the given data
	 *
	 * @params: `data` data where it's predecessor to be found
	 * @params: `root` root of the tree for the prevSmallerAncester function
	 *
	 * @return: in-order successor for the given data
	 */

	TreeNode* node = find(root, data);
	if(node->right !=nullptr){ return leftmost(node->right); }
	return successor(root, data, nullptr); 
}

void print(TreeNode* root){
        /**
         * Print the tree in an inorder fashion
         * 
         * @params: `root` root/parent node of the tree
         * @return: void
         */

        if(root != nullptr){
                print(root->left);
                std::cout << root->data << " ";
                print(root->right);
        }
}

int main(){
        TreeNode* root = nullptr;

        Insert(root, 37);
        Insert(root, 19);
        Insert(root, 4);
        Insert(root, 22);
        Insert(root, 51);
        Insert(root, 55);
        Insert(root, 42);
        Insert(root, 20);
        Insert(root, 11);
        Insert(root, 0);

        print(root);

  	/* 
        Tree structure
                37
               /  \
              19  51
             / \   / \
            4  22 42 55
           /\   /       
          0 11  20

        OUTPUT:
          0 4 11 19 20 22 37 42 51 55
	*/	

	int value = 4;
	if(in_order_predecessor(root, value)){
		std::cout << "\nPredecessor of " << value << " is " << in_order_predecessor(root, value)->data << std::endl;
	}
	else{ std::cout << "\nNo predecessor" << std::endl; }
	
	if(in_order_successor(root, value)){
		std::cout << "Successor of " << value << " is " << in_order_successor(root, value)->data << std::endl;
	}
	else{ std::cout << "No successor" << std::endl; }

	return 0;
}
