/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private: 
    unordered_map<Node*, Node*> vis;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        if(vis.find(node) != vis.end())
            return vis[node];
        
        Node *copy = new Node(node->val);
        vis[node] = copy;

        for(auto neighbor : node->neighbors)
            copy->neighbors.push_back(cloneGraph(neighbor));
        
        return copy;
    }
};