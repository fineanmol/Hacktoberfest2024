#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* lchild, *rchild;
}*top=NULL;

struct node * createNode(int element){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = element;
    t->lchild = NULL;
    t->rchild = NULL;
    return t;
}

struct node * insert(struct node *r, int data){
    if (r==NULL){
        return createNode(data);
    }
    else{
        int left=0;
        do{
            printf("Left Subtree (0/1) --");
            scanf("%d",&left);
        }
        while ((left!=0)&&(left!=1));
        if (left==1){
            r->lchild = insert(r->lchild,data);
        }
        else{
            r->rchild = insert(r->rchild,data);
        }
    }
    return r;
}

int preOrder(struct node *r){
    if (r!=NULL){
        printf("%d ",r->data);
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
    return 0;
}

int inOrder(struct node *r){
    if (r!=NULL){
        inOrder(r->lchild);
        printf("%d ",r->data);
        inOrder(r->rchild);
    }
    return 0;
}

int postOrder(struct node *r){
    if (r!=NULL){
        postOrder(r->lchild);
        postOrder(r->rchild);
        printf("%d ",r->data);
    }
    return 0;
}

int main(){
    printf("---------BINARY TREES---------\n");
    printf("1. Insert\n");
    printf("2. Pre Order\n");
    printf("3. In Order\n");
    printf("4. Post Order\n");
    printf("5. Exit\n");

    int choice=0;

    while (choice!=5){
        printf("Enter your command ---- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            int element;

            printf("Enter the element : ");
            scanf("%d",&element);
            top = insert(top,element);
            break;
            case 2:
            if (top==NULL){
                printf("Please enter a binary tree!\n");
            }
            else{
                printf("Pre Order Traversal -- ");
                preOrder(top);
                printf("\n"); 
            }
            break;
            case 3:
            if (top==NULL){
                printf("Please enter a binary tree!\n");
            }
            else{
                printf("In Order Traversal -- ");
                inOrder(top);
                printf("\n");
            }
            break;
            case 4:
            if (top==0){
                printf("Please enter a binary tree!\n");
            }
            else{
                printf("Post Order Traversal -- ");
                postOrder(top);
                printf("\n");
            }
            break;
            case 5:
            printf("-----EXITING-----\n");
            break;
            default:
            printf("Please enter a valid input !\n");
        }
    }
    return 0;
}