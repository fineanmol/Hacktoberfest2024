// https://leetcode.com/problems/binary-tree-level-order-traversal/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> currentLevel;
            for (int i=0;i<size;i++){
                TreeNode curr = q.front();
                q.pop();
                if (curr.left != nullptr) q.push(curr.left);
                if (curr.right != nullptr) q.push(curr.right);

                currentLevel.push_back(curr.val);
            }
            result.push_back(currentLevel;)
        }
        return result;
    }
};