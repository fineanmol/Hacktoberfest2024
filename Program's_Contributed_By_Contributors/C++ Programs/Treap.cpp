#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int key;
    int priority;
    Node* left;
    Node* right;

    Node(int k, int p) : key(k), priority(p), left(NULL), right(NULL) {}
};

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node* insert(Node* root, int key, int priority) {
    if (root == NULL) return new Node(key, priority);

    if (key <= root->key) {
        root->left = insert(root->left, key, priority);

        if (root->left->priority > root->priority)
            root = rotateRight(root);
    } else {
        root->right = insert(root->right, key, priority);

        if (root->right->priority > root->priority)
            root = rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << "Key: " << root->key << ", Priority: " << root->priority << endl;
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Insert keys with random priorities
    root = insert(root, 10, 5);
    root = insert(root, 20, 10);
    root = insert(root, 5, 15);

    // Print inorder traversal
    inorder(root);

    return 0;
}
