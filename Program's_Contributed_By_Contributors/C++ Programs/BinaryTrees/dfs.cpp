#include <iostream>
#include <stack>

// Define a structure for a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Recursive function for in-order DFS traversal
void inOrderDFS(TreeNode *root)
{
    if (root != nullptr)
    {
        inOrderDFS(root->left);
        std::cout << root->data << " ";
        inOrderDFS(root->right);
    }
}

// Iterative function for in-order DFS traversal using a stack
void iterativeInOrderDFS(TreeNode *root)
{
    std::stack<TreeNode *> stack;
    TreeNode *current = root;

    while (current != nullptr || !stack.empty())
    {
        while (current != nullptr)
        {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        std::cout << current->data << " ";

        current = current->right;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "In-order DFS recursive: ";
    inOrderDFS(root);
    std::cout << std::endl;

    std::cout << "In-order DFS iterative: ";
    iterativeInOrderDFS(root);
    std::cout << std::endl;

    // Don't forget to free the allocated memory in a real program
    // You can create a function to do this, e.g., deleteTree(root);

    return 0;
}
