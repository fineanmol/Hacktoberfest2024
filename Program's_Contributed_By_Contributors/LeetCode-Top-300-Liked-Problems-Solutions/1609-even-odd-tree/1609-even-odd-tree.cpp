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
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            int prevVal = level % 2 == 0 ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prevVal)) ||
                    (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prevVal))) {
                    return false;
                }

                prevVal = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level++; 
        }

        return true;
    }
};