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
    bool hasPathSum(TreeNode* root, int x) {
        if(root == NULL) {
            return false;
        }
        if(x == root->val and !root->right and !root->left)
            return true;
        return hasPathSum(root->left,x-root->val) || hasPathSum(root->right,x-root->val);
    }
};
