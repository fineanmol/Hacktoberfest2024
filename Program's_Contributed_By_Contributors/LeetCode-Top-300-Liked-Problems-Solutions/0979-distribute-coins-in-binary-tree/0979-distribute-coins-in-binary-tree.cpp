class Solution {
public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
private:
    int moves;
    int dfs(TreeNode* current) {
        if (current == nullptr) return 0;

        // Calculate the coins each subtree has available to exchange
        int leftCoins = dfs(current->left);
        int rightCoins = dfs(current->right);

        // Add the total number of exchanges to moves
        moves += abs(leftCoins) + abs(rightCoins);

        // The number of coins current has available to exchange
        return (current->val - 1) + leftCoins + rightCoins;
    }
};