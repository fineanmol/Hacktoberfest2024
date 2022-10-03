#include <bits/stdc++.h>
using namespace std;

//defining the structure of tree

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//pre-order traversal of a binary tree
 
void traverse(TreeNode *root, vector<TreeNode*>&preorder) {
        if (root == NULL)
            return;
        preorder.push_back(root);
        traverse(root->left, preorder);
        traverse(root->right, preorder);
}

//main function which flattens the binary tree

void flatten(TreeNode* root) {
        vector<TreeNode*> preorder;
        traverse(root,preorder);
        TreeNode* temp=root;
        for(int i=1;i<preorder.size();i++) {
            temp->right=preorder[i];
            temp->left=NULL;
            temp=temp->right;
        }
}

int main()
{
    //building the binary tree which we want to flatten
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    //flatten the tree by calling flatten method
    flatten(root);
    //now printing the flattened tree
    while(root)
    {
        cout<<root->val<<" ";
        root=root->right;
    }cout<<endl;

    return 0;
}
