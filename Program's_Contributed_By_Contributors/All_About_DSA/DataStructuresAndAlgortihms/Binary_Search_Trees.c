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
    else if(data<r->data){
        r->lchild = insert(r->lchild,data);
    }
    else{
        r->rchild = insert(r->rchild,data);
    }
    return r;
}

int maxNode(struct node *r){
    int right=0;
    struct node *temp;
    struct node *s;
    s = r;
    temp = r;
    r = r->lchild;
    while (r->rchild!=NULL){
        s = r;
        r = r->rchild;
        right = 1;
    }
    temp->data = r->data;
    if (right==1){
        s->rchild = NULL;
    }
    else{
        s->lchild = NULL;
    }
    return 0;
}
int delete(struct node *r,int data){
    struct node *temp=top;
    int left=0;
    int flag=0;
    while (flag==0){
        if(r->data>data){
            temp = r;
            r = r->lchild;
            left = 1;
        }
        else if(r->data<data){
            temp = r;
            r = r->rchild;
            left = 0;
        }
        else{
            if ((r->lchild==NULL)&&(r->rchild==NULL)){
                printf("Deleted Node : %d\n",r->data);
                if (r==top){
                    top = NULL;
                }
                else if (left==1){
                    temp->lchild = NULL;
                }
                else{
                    temp->rchild = NULL;
                }
                flag = 1;
            }
            else if (r->lchild==NULL){
                printf("Deleted Node : %d\n",r->data);
                if (r->data==top->data){
                    top = r->rchild;
                }
                else if (left==1){
                    temp->lchild = r->rchild;
                }
                else{
                    temp->rchild = r->rchild;
                }
                flag = 1;
            }
            else if (r->rchild==NULL){
                printf("Deleted Node : %d\n",r->data);
                if (r->data==top->data){
                    top = r->lchild;
                }
                else if (left==1){
                    temp->lchild = r->lchild;
                }
                else{
                    temp->rchild = r->lchild;
                }
                flag = 1;
            }
            else{
                printf("Deleted Node : %d\n",r->data);
                maxNode(r);
                flag = 1;
            }
        }
    }
    return 0;
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

int search(struct node *r,int data){
    while (r!=NULL){
        if (r->data==data){
            return 1;
        }
        else if (r->data>data){
            r = r->lchild;
        }
        else{
            r = r->rchild;
        }
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
    printf("2. Delete\n");
    printf("3. Pre Order\n");
    printf("4. In Order\n");
    printf("5. Post Order\n");
    printf("6. Exit\n");

    int choice=0;

    while (choice!=6){
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
                struct node *t;
                int element;
                int flag;

                t = top;
                printf("Enter the element : ");
                scanf("%d",&element);
                flag = search(t,element);
                if (flag==0){
                    printf("Element not Present!\n");
                }
                else{
                    t = top;
                    delete(t,element);
                } 
            }
            break;
            case 3:
            if (top==NULL){
                printf("Please enter a binary tree!\n");
            }
            else{
                printf("Pre Order Traversal -- ");
                preOrder(top);
                printf("\n"); 
            }
            break;
            case 4:
            if (top==0){
                printf("Please enter a binary tree!\n");
            }
            else{
                printf("In Order Traversal -- ");
                inOrder(top);
                printf("\n");
            }
            break;
            case 5:
            if (top==0){
                printf("Please enter a binary tree!\n");
            }
            else{
                printf("Post Order Traversal -- ");
                postOrder(top);
                printf("\n");
            }
            break;
            case 6:
            printf("-----EXITING-----\n");
            break;
            default:
            printf("Please enter a valid input !\n");
        }
    }
    return 0;
}