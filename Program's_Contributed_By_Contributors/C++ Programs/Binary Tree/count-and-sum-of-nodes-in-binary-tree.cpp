/*
Problem:
Count the Number of Nodes in the binary tree, 
and to find the sum of all nodes in a binary tree.
*/

/*-------------------------
Recursive Solution
Time Complexity: O(n)
---------------------*/

#include <iostream>
using namespace std;

// Basic Structure of a tree
class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

    void insert(Node *&root, int data)
    {

        if (root == NULL)
            root = new Node(data);
        else if (root->data > data)
            insert(root->left, data);
        else
            insert(root->right, data);
    }

    /* Counting Nodes Algorithm

    Left subtree Count + Right Subtree Count + 1

    */

    int CountNodes(Node *&root)
    {
        //Base Case
        if (root == NULL)
            return 0;
 return CountNodes(root->left) + CountNodes(root->right) + 1;
    }

    /* Sum of Nodes Nodes 
    Left subtree Sum + Right Subtree Sum + Node Value
    */

    int SumNodes(Node *&root)
    {
        //Base Case
        if (root == NULL)
            return 0;
 return SumNodes(root->left) + SumNodes(root->right) + root->data;
    }
};

int main()
{
    //User Input
    Node *root = NULL;
    int n, num;
    cout << "Enter the Number of nodes";
    cin >> n;
    cout << "Enter the value of the nodes";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        root->insert(root, num);
    }

    //Counting nodes
    cout << "Number of Nodes : " << root->CountNodes(root) << endl;

    //Sum of Nodes
    cout << "Sum of Nodes : " << root->SumNodes(root);    
}

    /*        
Example:   
    
                    1
                   / \
                  2   3
                 / \   \
                4   5   7    
        
    Expected Output:
    Step 1 - First find the Left subtree Count recursively 
    Step 2 - Secondly Find  Right Subtree count Recursively
    Step 3 = Add one for current node
    You can see here that there are total of 7 nodes in the tree.
        
    Similarly as Count node you can find sum of nodes data
    Step 1 - First find the Left subtree Sum  recursively 
    Step 2 - Secondly Find  Right Subtree Sum Recursively
    Step 3 = Add the Current Node Value
    You can see here that total sum is 28
*/
