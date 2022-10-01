// https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root){
            return {};
        }
        
        if (root->val == targetSum && !root->right && !root->left){
            return {{root->val}};
        }
        
        int remTarget = targetSum-root->val;
        vector<vector<int>> leftPaths,rightPaths;
        if (root->left){
            leftPaths = pathSum(root->left,remTarget);
            
        }
        
        if (root->right){
            rightPaths = pathSum(root->right,remTarget);
        }
        
        vector<vector<int>> result;
        
        
        
        for (auto v:leftPaths){
            
            v.insert(v.begin(),root->val);
            result.push_back(v);
        }
        
        for (auto v:rightPaths){
                        

            v.insert(v.begin(),root->val);
            result.push_back(v);
        }
        
        return result;
        
        
        
        
    }
};