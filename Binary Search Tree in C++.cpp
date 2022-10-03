/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* getNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode*));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
    if(root == NULL){
        root = getNewNode(data);
    }
    
    else if(data <= root->data){
            root->left = Insert(root->left,data);
        }
    else {
            root->right = Insert(root->right,data);
        }    
    return root;    
}

bool Search(struct BstNode* root, int data){
    if(root==NULL){
        return false;
    }
    else if(root->data == data) {
		return true;
	}
    else if(data <= root->data){
        return Search(root->left,data);
    }
    else {
        return Search(root->right,data);
    }
}

int main()
{
    int a,x;
    struct BstNode* root = NULL;
    root = Insert(root,15);
     root = Insert(root,10);
      root = Insert(root,10);
       root = Insert(root,20);
        root = Insert(root,25);
         root = Insert(root,8);
         printf("\nEnter number to be searched: ");
         scanf("%d",&x);
    
    if(Search(root,x) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
         
    

    return 0;
}
