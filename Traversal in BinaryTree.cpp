//Inorder ,Preorder,Postorder traversal in tree.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node * root=NULL;
struct node * newnode(int item)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* insert(struct node *node,int key)
{
    if(node==NULL)
    {
        return newnode(key);
    }
    if(key<node->data)
    {
        node->left=insert(node->left,key);
    }
    else if(key>node->data)
    {
        node->right=insert(node->right,key);
    }

    return node;
}


void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d \t",root->data);
        inorder(root->right);
    }
}

void preorder(struct node*root)
{
    if(root!=NULL)
    {
        printf("%d \t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t",root->data);

    }
}


int main()
{
    int key,ch;
    while(1)
    {
        printf("----BINARY TREE MENU----\n");
        printf("\n1)Insert\n2)Display in inorder: \n3)Display in preorder: \n4)Display in postorder: \n5)Exit");
        printf( "\n Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
             printf("Insert value\n");
        scanf("%d",&key);
        if(root==NULL)
        {
            root=insert(root,key);
        }
             else
        {
             insert(root,key);
        }

            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");

        }
    }
}
