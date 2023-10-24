#include <iostream>

using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
};

Node* createNode(int data){
    Node * newNode = new Node();
    newNode -> data = data;
    newNode -> left = nullptr;
    newNode -> right = nullptr;

    return newNode;
}


//   Preorder Traversal

void preorder(Node * root){

    if(root == nullptr) return;

    cout << root -> data << endl;
    preorder(root -> left);
    preorder(root -> right);
}

//  Inorder Traversal

void inorder(Node * root){

    if(root == nullptr) return;

    inorder(root -> left);
    cout << root -> data << endl;
    inorder(root -> right);
}

// Postorder Traversal

void postorder(Node * root){
    
    if(root == nullptr) return;
    
    postorder(root -> left);
     postorder(root -> right);
    cout << root -> data << endl;
   

}

int main(){

    // Level 1
    Node * root = createNode(1);
    // Level 2
    root -> left = createNode(2);
    root -> right = createNode(3);
    // Level 3
    root ->left -> left = createNode(4);
    root ->left -> right = createNode(5);
    root ->right -> left = createNode(6);
    root ->right -> right = createNode(7);
    // Level 4
    root-> left-> right-> left = createNode(9);
    root-> right-> right -> left = createNode(15);

    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << "Postorder Traversal" << endl;
    postorder(root);
    

    system("pause>0");  

}