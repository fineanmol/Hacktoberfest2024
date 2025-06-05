/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void isLeaf(TreeNode* root, vector<int> &leaf){
        if(!root)
            return;
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return;
        }

        isLeaf(root->left, leaf);
        isLeaf(root->right, leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        isLeaf(root1, r1);
        isLeaf(root2, r2);
        return r1 == r2;
    }
};