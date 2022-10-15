#include<iostream>
using namespace std;


// Basic Structure of a Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


//Function to find the height of the tree
int height(struct Node* root)
{
    if (root == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = height(root->left);
        int rDepth = height(root->right);

        /* use the larger one */
        return max(lDepth, rDepth) + 1;
    }

}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    /*
                    1----height=2
                   / \
                  2   3----height=1
                 / \   \
                4   5   7----height=0
        Expected-> height=2

    */
    cout << "Height of the tree is : " << height(root) << endl;;

    return 0;
}