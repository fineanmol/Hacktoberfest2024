#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting left of root" << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting right of root" << endl;
    root->right = buildTree(root->right);

    return root;
}

void buildFromLevelOrderTraversal(Node* &root){
    queue<Node*> q;
    int data;
    cout << "Enter data for root" << endl;	
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << endl;
        int leftData; cin >> leftData;

        if(leftData != -1)
        {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->left = new Node(rightData);
            q.push(temp->left);
        }
    }
}

int main()
{
    Node *root = NULL;

    // root = buildTree(root);
    cout << "buildFromLevelOrder Traversal" << endl;
    buildFromLevelOrderTraversal(root);
    return 0;
}
