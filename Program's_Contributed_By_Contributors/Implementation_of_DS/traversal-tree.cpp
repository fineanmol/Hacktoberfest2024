#include<bits/stdc++.h>
using namespace std;

// declalration of tree's node structure
struct Node{
    int item;
    struct Node *left,*right;
};

// TRAVERSALS-->
// Inorder traversal
void inorderT(struct Node *root)
{
    if(root==NULL)
        return;
    inorderT(root->left);
    cout<<root->item<<" ";
    inorderT(root->right);
}
// preorder traversal
void preorderT(struct Node *root)
{
    if(root==NULL)
        return;
    cout<<root->item<<" ";
    preorderT(root->left);
    preorderT(root->right);
}
// postorder traversal
void postrderT(struct Node *root)
{
    if(root==NULL)
        return;
    postrderT(root->left);
    postrderT(root->right);
    cout<<root->item<<" ";
}

// creating a new node
struct Node *createNode(int value)
{
    struct Node *new_node=new Node();
    new_node->item=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
// creating left subtree
struct Node *instleft(struct Node *root,int value)
{
    root->left=createNode(value);
    return root->left;
}
// creating right subtree
struct Node *instright(struct Node *root,int value)
{
    root->right=createNode(value);
    return root->right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct Node *root=createNode(1);
    instleft(root,12);
    instright(root,9);
    instleft(root->left,5);
    instright(root->left,6);
    cout<<"Inorder traversal \n";
    inorderT(root);
    cout<<"\n";
    cout<<"preorder traversal \n";
    preorderT(root);
    cout<<"\n";
    cout<<"postrder traversal \n";
    postrderT(root);
    cout<<"\n";
    return 0;
}
