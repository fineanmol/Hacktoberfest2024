#include<stdio.h>
#include<stdlib.h>

#define makeAVL(name) AVL *name = (AVL *)malloc(sizeof(AVL));\
                      __initAVL__(name);

#define inOrder(tree) _inOrder(tree->root);\
                      printf("\n");

typedef struct node{
    int data;
    struct node *left, *right, *parent;
    int bf;
}AVLnode;

typedef struct AVL_tree{
    AVLnode *root;
    int balanced;
}AVL;


void __initNODE__(AVLnode *node){
    node->bf = 0;
    node->data = 0x1<<31;
    node->left = NULL;
    node->parent = NULL;
    node->right = NULL;
    return;
}

void __initAVL__(AVL *tree){
    tree->balanced = 1;
    tree->root = NULL;
    return;
}

int maxint(int a, int b) {return (a > b) ? a : b;}

int height(AVLnode *node){
    if(node == NULL) return -1;
    if(node->left == NULL && node->right == NULL) return 0;
    if(node->left == NULL && node->right != NULL) return 1 + height(node->right);
    if(node->left != NULL && node->right == NULL) return 1 + height(node->left);
    return 1 + maxint(height(node->left), height(node->right));
}

void fillBalanceFactor(AVLnode *node){
    if(node == NULL) return;
    fillBalanceFactor(node->left);
    node->bf = height(node->left) - height(node->right);
    fillBalanceFactor(node->right);
    return;
}

void insertAVL(AVL *tree, int data){
    AVLnode *newnode = (AVLnode *)malloc(sizeof(AVLnode));
    __initNODE__(newnode);
    newnode->data = data;
    if(tree->root == NULL) tree->root = newnode;
    else{
        AVLnode *p = tree->root, *q = NULL;
        while(p != NULL){
            q = p;
            if(p->data > data) p = p->left;
            else p = p->right;
        }
        if(q->data > data) q->left = newnode;
        else q->right = newnode;
        newnode->parent = q;
        fillBalanceFactor(tree->root);
    }
    return;
}

void _inOrder(AVLnode *node){
    if(node == NULL) return;
    _inOrder(node->left);
    printf("NODE >> %d Balance Fac >> %d\n", node->data, node->bf);
    _inOrder(node->right);
    return;
}

void main(){
    makeAVL(tree);
    insertAVL(tree, 5);
    insertAVL(tree, 3);
    insertAVL(tree, 7);
    insertAVL(tree, 1);
    insertAVL(tree, 9);
    insertAVL(tree, 2);
    insertAVL(tree, 6);
    insertAVL(tree, 11);

    inOrder(tree);

    return;
}