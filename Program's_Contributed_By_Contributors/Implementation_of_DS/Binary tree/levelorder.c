#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* newnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
}

void printcurrentlevel(struct node* root,int level){
   if(root==NULL)
   return;

   if(level==1)
   printf("%d", root->data);
   else if(level>1){
    printcurrentlevel(root->left,level-1)
;
printcurrentlevel(root->right,level-1);   } 
}
int height(struct node* node){
if(node==NULL)
return 0;

else{
    int lheight=height(node->left);
    int rheight=height(node->right);

    if(lheight>rheight)
    return(lheight+1);
    else
    return(rheight+1);
}

}

void printlevel(struct node* root){
    int h=height(root);
    int i;
    for(int i=1; i<=h;i++)
    printcurrentlevel(root,i);
}

int main(){
    struct node* root;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    printlevel(root);
    return 0;
}

//n square
//n auxiliary space
