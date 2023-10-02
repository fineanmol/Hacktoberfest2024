#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node(int val): val(val)
        , left(NULL)
        , right(NULL){

        }
};

void Insert(Node* &root, int val){
    if(!root){
        root = new Node(val);
        return;
    }
    Node *node = root;
    while(true){
        if(val < node->val){
            if(node->left){
                node = node->left;
            }
            else{
                node->left = new Node(val);
                break;
            }
        }
        else{
            if(node->right){
                node = node->right;
            }
            else{
                node->right = new Node(val);
                break;
            }
        }
    }
}

void inorder(Node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

Node *lca(Node* &root, int n1, int n2){
    if(!root || root->val == n1 || root->val == n2){
        return root;
    }
    if(n1 > root->val && n2 > root->val){
        return lca(root->right, n1, n2);
    }
    else if(n1 < root->val && n2 < root->val){
        return lca(root->left, n1, n2);
    }
    return root;
}

int main(){
    Node *root = NULL;
    Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);

    // inorder(root);
    int n1, n2;
    cin>>n1>>n2;
    Node *node = lca(root, n1, n2);
    cout<<node->val<<endl;
}
