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
    int sumNumbers(TreeNode* root, int num = 0) {
        if (!root)
            return 0;
        num = num * 10 + root->val;
        // If it's a leaf node, return the formed number
        if (!root->left && !root->right)
            return num;
        // Otherwise, continue recursively
        return sumNumbers(root->left, num) + sumNumbers(root->right, num);
    }
};
