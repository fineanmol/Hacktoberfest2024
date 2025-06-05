// https://leetcode.com/problems/n-ary-tree-preorder-traversal/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
    // Create an empty vector to store the preorder traversal result.
    vector<int> res;

    // Check if the root is NULL.
    if (root == NULL) {
        // If the root is NULL, return the empty vector.
        return res;
    }

    // Add the value of the root node to the result vector.
    res.push_back(root->val);

    // Traverse each child node of the root node.
    for (int i = 0; i < root->children.size(); i++) {
        // Call the preorder function recursively on the current child node.
        vector<int> temp = preorder(root->children[i]);
        // Append the result of the recursive call to the result vector.
        res.insert(res.end(), temp.begin(), temp.end());
    }

    // Return the preorder traversal result.
    return res;
}
};