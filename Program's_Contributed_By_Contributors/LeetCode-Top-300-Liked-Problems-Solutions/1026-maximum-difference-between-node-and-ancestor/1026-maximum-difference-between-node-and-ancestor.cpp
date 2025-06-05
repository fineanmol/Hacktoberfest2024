/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<vector<int>>& paths, vector<int>& path) {
        if (!root)
            return;

        path.push_back(root->val);

        if (!root->left && !root->right) {
            paths.push_back(path);
            path.pop_back();

            return;
        }
        inorder(root->left, paths, path);
        inorder(root->right, paths, path);

        path.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;

        vector<vector<int>> paths;
        vector<int> path;

        inorder(root, paths, path);

        int n = paths.size();

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int maxi = *max_element(paths[i].begin(), paths[i].end());
            int mini = *min_element(paths[i].begin(), paths[i].end());

            ans = max(ans, abs(maxi - mini));
        }

        return ans;
    }
};