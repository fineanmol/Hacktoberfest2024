#include<iostream>
#include<queue>
#define endl "\n"
using namespace std;


// Basic Structure of a Tree
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* Level order Traversal of a Binary Tree using Queue */
/* Complexity : O(n) */

// Here NULLs are used to keep track of levels

void level_order(Node* root){
    if(root == NULL) 
     return;

    queue<Node*> q;
    q.push(root); q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
            
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    cout<<endl;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    /*                       
                    1
                   / \
                  2   3
                 / \   \
                4   5   7    
        Expected-> level-order :  1,2,3,4,5,7
                   
    
    */
   cout<<"Level Order is : ";
   level_order(root);

    return 0;
}