class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        bottomLeftValue = 0;
        dfs(root, 0);
        return bottomLeftValue;
    }

private:
    int maxDepth;
    int bottomLeftValue;

    void dfs(TreeNode* current, int depth) {
        if (current == nullptr) {
            return;
        }
        if (depth > maxDepth) { 
            maxDepth = depth;
            bottomLeftValue = current->val;
        }
        dfs(current->left, depth + 1);
        dfs(current->right, depth + 1);
    }
};

