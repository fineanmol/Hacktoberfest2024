#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* lchild, *rchild;
};

struct node * createNode(char element,struct node *left,struct node *right){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = element;
    t->lchild = left;
    t->rchild = right;
    return t;
}

int push(struct node *a[],int size,struct node *element){
    a[size] = element;
    return 0;
}

struct node * pop(struct node* a[],int size){
    return a[size-1];
}

struct node * expression_tree(struct node *a[],char postfix[]){
    int size=0;
    struct node * left,* right;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    for (int i=0;postfix[i]!='\0';i++){
        switch(postfix[i]){
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
            temp = createNode(postfix[i],NULL,NULL);
            push(a,size,temp);
            size = size+1;
            break;
            case '^':
            case '*':
            case '+':
            case '-':
            case '/':
            right = pop(a,size);
            size = size-1;
            left = pop(a,size);
            size = size-1;
            temp = createNode(postfix[i],left,right);
            push(a,size,temp);
            size = size+1;
            break;
            default:
            break;
        }
    }
    return a[0];
}

int preOrder(struct node *r){
    if (r!=NULL){
        printf("%c ",r->data);
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
    return 0;
}

int inOrder(struct node *r){
    if (r!=NULL){
        inOrder(r->lchild);
        printf("%c ",r->data);
        inOrder(r->rchild);
    }
    return 0;
}

int postOrder(struct node *r){
    if (r!=NULL){
        postOrder(r->lchild);
        postOrder(r->rchild);
        printf("%c ",r->data);
    }
    return 0;
}

int main(){
    printf("--------EXPRESSION TREE--------\n");
    printf("--------MENU--------\n");
    printf("1. Enter an Expression\n");
    printf("2. Pre Order Traversal\n");
    printf("3. In Order Traversal\n");
    printf("4. Post Order Traversal\n");
    printf("5. Exit\n");

    int choice=0,flag=0;
    struct node *exp[50];
    char postfix[50];
    struct node *top;

    while (choice!=5){
        printf("Enter your command -- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the postfix expression : ");
            scanf("%s",postfix);
            top = expression_tree(exp,postfix);
            flag = 1;
            break;
            case 2:
            if (flag==0){
                printf("Please enter an expression!\n");
            }
            else{
                printf("Pre Order Traversal -- ");
                preOrder(top);
                printf("\n"); 
            }
            break;
            case 3:
            if (flag==0){
                printf("Please enter an expression!\n");
            }
            else{
                printf("In Order Traversal -- ");
                inOrder(top);
                printf("\n");
            }
            break;
            case 4:
            if (flag==0){
                printf("Please enter an expression!\n");
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
            printf("Please enter a valid input!\n");
        }
    }
    return 0;
}