#include<iostream>
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

/* Construct a binary tree using Pre, In and Post order traversals */
/* Complexity in Both cases : O(n^2) */

// Utility function to search the element in Inorder
int search (int in[],int start ,int end,int curr){
    for(int i=start;i<=end;++i){
        if(in[i] == curr) 
         return i;
    }
    return -1; 
}

// Build a binary Tree using Pre & In order (using Recursion)
Node* buildTreePreIn(int pre[],int in[],int start, int end){
    static int idx = 0;
    if(start > end)
     return NULL;

    int curr = pre[idx]; 
    idx++;
    Node* node = new Node(curr);

    if(start == end)
     return node;

    int pos = search(in,start,end,curr);
    node->left = buildTreePreIn(pre,in,start,pos-1);
    node->right = buildTreePreIn(pre,in,pos+1,end);

    return node;
}

// Build a binary Tree using Post & In order (using Recursion)
Node* buildTreePostIn(int post[],int in[],int start,int end){
    static int idx = end;
    if(start > end)
     return NULL;

    int curr = post[idx];
    idx--;
    Node* node = new Node(curr);

    if(start == end) 
     return node;

    int pos = search(in,start,end,curr);
    node->right = buildTreePostIn(post,in,pos+1,end);
    node->left = buildTreePostIn(post,in,start,pos-1);

    return node;
}

// Inorder function to check if tree was built successfully!!
void inOrder(struct Node* root){
    if(root == NULL)
      return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    //n=5
    int preorder[] =  {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3}; // This order should match the output
    int postorder[] = {4,2,5,3,1};
    Node* t1 = buildTreePreIn(preorder,inorder,0,4);
    Node* t2 = buildTreePostIn(postorder,inorder,0,4);

     /*  Tree t
            1
           / \
          2   3
         /   /
        4   5
    
    */
   cout<<"Output Inorder : ";
   inOrder(t2);
   return 0;
}