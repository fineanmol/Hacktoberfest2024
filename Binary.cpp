#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node * right;
    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
int idx = 0;
Node *insert(int arr[],int n){
    if(idx==n){
        return nullptr;
    }
    if(arr[idx]==-1) {
        idx++;
        return nullptr;
    }
    Node * root = new Node(arr[idx++]);
    root -> left = insert(arr,n);
    root -> right = insert(arr,n);
    return root;

}

void preOrder(Node * root){
    if(root==NULL) return;
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}
int main()
{

    int arr[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node *root = insert(arr,n);

    preOrder(root);




    return 0;
}