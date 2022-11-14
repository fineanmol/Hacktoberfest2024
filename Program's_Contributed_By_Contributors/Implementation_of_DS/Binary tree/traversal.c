#include <stdio.h>
#include <stdlib.h>
struct node
{

   int data;
   struct node *left;
   struct node *right;
};

//typedef struct node node;


struct node *newNode(int data)
{
   struct node *node = (struct node *)malloc(sizeof(struct node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;

   return (node);
}

void printpostorder(struct node *node)
{
   if (node == NULL)
      return;
   printpostorder(node->left);
   printpostorder(node->right);
   printf("%d", node->data);
}

void printinorder(struct node *node)
{
   if (node == NULL)
   {
      return;
      printinorder(node->left);
      printinorder(node->right);
      printf("%d", node->data);
   }
}

int main()
{
   struct node *root;
   root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(5);
   printinorder(root);
   printpostorder(root);

   return 0;
}