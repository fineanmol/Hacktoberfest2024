#include <bits/stdc++.h>
using namespace std;


class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void markParents(BinaryTreeNode *root, unordered_map<BinaryTreeNode *, BinaryTreeNode *> &parent_track) {
    if (!root) return;
    
    queue<BinaryTreeNode *> queue;
    queue.push(root);
    
    while (!queue.empty()) {
        BinaryTreeNode *current = queue.front();
        queue.pop();
        
        if (current->left) {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        
        if (current->right) {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> printNodesAtDistanceK(BinaryTreeNode *root, BinaryTreeNode *target, int k) {
    unordered_map<BinaryTreeNode *, BinaryTreeNode *> parent_track;
    markParents(root, parent_track);

    unordered_map<BinaryTreeNode *, bool> visited;
    
    queue<BinaryTreeNode *> queue;
    queue.push(target);
    visited[target] = true;
    
    int curr_level = 0;
    
    while (!queue.empty()) {
        int size = queue.size();
        
        if (curr_level++ == k) {
            break;
        }
        
        for (int i = 0; i < size; i++) {
            BinaryTreeNode *current = queue.front();
            queue.pop();
            
            if (current->left && !visited[current->left]) {
                queue.push(current->left);
                visited[current->left] = true;
            }
            
            if (current->right && !visited[current->right]) {
                queue.push(current->right);
                visited[current->right] = true;
            }
            
            if (parent_track[current] && !visited[parent_track[current]]) {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    
    vector<int> result;
    
    while (!queue.empty()) {
        BinaryTreeNode *current = queue.front();
        queue.pop();
        result.push_back(current->data);
    }
    
    return result;
}

int main() {
    
    BinaryTreeNode *root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);
    BinaryTreeNode *target = root->left;
    
    int k = 2;
    vector<int> result = printNodesAtDistanceK(root, target, k);
    
    cout << "Nodes at distance " << k << " from target: ";
    for (int node : result) {
        cout << node << " ";
    }
    
    return 0;
}
