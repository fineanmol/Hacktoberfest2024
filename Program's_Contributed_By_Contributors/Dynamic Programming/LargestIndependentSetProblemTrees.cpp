#include<iostream>
using namespace std;

class Node{

public:

    int data;
    Node*left;
    Node*right;

    Node(int d):data(d),left(NULL),right(NULL){}
};

//return the largest independent set(unconnected nodes) in the binary tree.

int LISS(Node*root){

    if(root==NULL){
        return 0;
    }

    int including_current = 1;
    if(root->left){
        including_current += LISS(root->left->left) + LISS(root->left->right);
    }
    if(root->right){
        including_current += LISS(root->right->left) +  LISS(root->right->right);
    }

    int excluding_current = LISS(root->left) + LISS(root->right);

    return max(including_current,excluding_current);
}


int main(){

    Node *root                = new Node(20);
    root->left                = new Node(8);
    root->left->left          = new Node(4);
    root->left->right         = new Node(12);
    root->left->right->left   = new Node(10);
    root->left->right->right  = new Node(14);
    root->right               = new Node(22);
    root->right->right        = new Node(25);

    cout<<LISS(root);
return 0;
}
