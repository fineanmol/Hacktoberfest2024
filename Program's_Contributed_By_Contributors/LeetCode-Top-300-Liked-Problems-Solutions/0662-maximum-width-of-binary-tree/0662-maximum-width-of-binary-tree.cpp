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
    int widthOfBinaryTree(TreeNode* root) {
        // Width => Max no of nodes in a level between two nodes
        if(!root) return 0;
        int ans = 1;
        queue<pair<TreeNode*, long long>> q; // Node, level
        q.push({root, 0}); // 0-based indexing
        while(!q.empty()){
            long long mmin = q.front().second;
            int size = q.size();
            int first, last;
            for(int i = 0; i < size; i++){
                long long cur_idx = q.front().second - mmin; // To prevent overflow
                auto p = q.front().first;
                q.pop();
                if(i == 0) first = cur_idx;
                if(i == size - 1) last = cur_idx;
                if(p->left) q.push({p->left, cur_idx * 2 + 1});
                if(p->right) q.push({p->right, cur_idx * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};