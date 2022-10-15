/** 
 * Conduct a morris in-order traversal of a binary tree,
 * printing out the value at each node according to 
 * the traversal using user defined inputs.
 * Node.val can take any number except -1
 **/
# include <iostream>
# include <vector>
using namespace std;

// Basic tree definition
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {};

};

/**
 * Print out the values of the treenodes using an in-order traversal
 * (left subtree - root - right subtree) without using additional memory
 * node values are printed with a space between the values of each 2 nodes
 **/

void print_morris(Node* root) {
    if (!root) cout << "\n";

    Node* previous;

    while(root) {
        if (!root->left) {
            cout << root->val << " ";
            root = root->right;
        } else {
            previous = root->left;

            while (previous->right && previous->right != root) 
                previous = previous->right;

            if (!previous->right) {
                previous->right = root;
                root = root->left;
            } else {
                previous->right = NULL;
                cout << root->val << " ";
                root = root->right;
            }
        }
    }
}

Node* build_tree(vector<int>& nodes, Node* root, int i, int n) {
    if (i < n) {
        if (nodes[i] == -1) return NULL;
        Node* temp = new Node(nodes[i]);
        root = temp;

        root->left = build_tree(nodes, root->left, 2 * i + 1, n);
        root->right = build_tree(nodes, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    vector<int> nodes;
    int numNodes;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    if (!numNodes) { cout << "\n"; return 0; }

    for (int i = 0; i < numNodes; i++) {
        cout << "Enter the value for node followed by ENTER (-1 for no node) " << i + 1 << ": ";
        int nodeVal;
        cin >> nodeVal;
        nodes.push_back(nodeVal);
    }

    Node* my_root = build_tree(nodes, my_root, 0, nodes.size());

    /**
     * Test for the morris traversal:
     * tree referenced by my_root:
     *              8
     *            /   \
     *           5    10
     *               /  \
     *              9    6
     * 
     * for input:7, 8 5 10 -1 -1 9 6
     * expected output: 5 8 9 10 6
     * time complexity: O(n), space complexity O(1)
     **/

    print_morris(my_root);
    return 0;
}
