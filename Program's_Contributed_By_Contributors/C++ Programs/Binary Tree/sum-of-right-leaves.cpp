// The sum of right leaves algorithm uses a queue to navigate through a binary tree
// Worst Case Time Complexity: O(n)
// Average Time Complexity: O(n)

#include <iostream>
#include <queue>

using namespace std;

// Node structure for tree
struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

int sumRightLeaves(Node* root) {
    queue<Node*> q;
    int rightSum = 0;

    // Checking if the root is nullptr push to queue if it exists
    if(root)
    {
        q.push(root);
    }

    while(!q.empty())
    {
        // Check if there exists a right node
        if(q.front()->right)
        {
            // Check if this is a leaf node
            if(q.front()->right->right == nullptr && q.front()->right->left == nullptr)
            {
                rightSum += q.front()->right->val;
            }
            else
            {
                q.push(q.front()->right);
            }
        }
        if(q.front()->left) // Check down left side of tree
        {
            q.push(q.front()->left);
        }

        q.pop();
    }

    return rightSum;
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(10);
    root->right->right = new Node(13);

//                     3
//                    / \
//                   5   7
//                  / \   \
//                 8   10  13
//
//          Sample Output
//          Sum of the right leaves: 23

// Outputting sum of right leaves
    cout << "Sum of right leaves: " << sumRightLeaves(root);

    return 0;
}