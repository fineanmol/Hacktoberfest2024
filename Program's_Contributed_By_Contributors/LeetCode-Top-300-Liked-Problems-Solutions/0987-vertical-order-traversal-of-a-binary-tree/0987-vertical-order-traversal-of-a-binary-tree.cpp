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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q; // (node, vertical, level)
        map<int, map<int, multiset<int>>> nodes; // (vertical, level, multi nodes)

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;

            nodes[x][y].push_back(node->val);

            if(node->left) q.push_back({node->left, x - 1, y + 1});
            if(node->right) q.push_back({node->right, x + 1, y + 1});
        }

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                for(auto node: q.second){
                    col.push_back(node);
                }
            }
            ans.push_back(col);
        }
    
};