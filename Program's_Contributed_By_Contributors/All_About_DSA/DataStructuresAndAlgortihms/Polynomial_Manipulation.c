#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int index;
    struct node * next;
}*top1=0,*top2=0,*top3;

int display(){
    printf("First Polynomial --\n");
    if (top1==0){
        printf("NO NODES!\n");
    }
    else{
        struct node *t;
        t = top1;
        while (t!=0){
            printf("%d*x^%d + ",t->data,t->index);
            t = t->next;
        }
        printf("\n");
    }
    printf("Second Polynomial --\n");
    if (top2==0){
        printf("NO NODES!\n");
    }
    else{
        struct node *t;
        t = top2;
        while (t!=0){
            printf("%d*x^%d + ",t->data,t->index);
            t = t->next;
        }
        printf("\n");
    }
    return 0;
}

int e_insertion_first(){
    struct node *t,*temp;
    int element,coeff,flag=0;
    printf("Inserting Polynomial - 1\n");
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d",&element);
    printf("Enter the coefficient : ");
    scanf("%d",&coeff);
    t->data = element;
    t->index = coeff;
    t->next = 0;
    if (top1==0){
        top1 = t;
    }
    else{
        temp = top1;
        while (temp->next!=0){
            if (temp->index==t->index){
                temp->data = temp->data+element;
                flag = 1;
                break;
            }
            else{
                temp = temp->next;
            }
        }
        if (temp->index==t->index){
            temp->data = temp->data+element;
            flag=1;
        }
        if (flag==0){
            temp->next = t;
        }
    }
    return 0;
}

int e_insertion_second(){
    struct node *t,*temp;
    int element,coeff,flag=0;
    printf("Inserting Polynomial - 2\n");
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d",&element);
    printf("Enter the coefficient : ");
    scanf("%d",&coeff);
    t->data = element;
    t->index = coeff;
    t->next = 0;
    if (top2==0){
        top2 = t;
    }
    else{
        temp = top2;
        while (temp->next!=0){
            if (temp->index==t->index){
                temp->data = temp->data+element;
                flag=1;
                break;
            }
            else{
                temp = temp->next;
            }
        }
        if (temp->index==t->index){
            temp->data = temp->data+element;
            flag=1;
        }
        if (flag==0){
            temp->next = t;
        }
    }
    return 0;
}

int addition(){
    struct node *temp1;
    struct node *temp2;
    struct node *temp3;
    int flag;
    temp2 = top2;
    while (temp2!=0){
        temp1 = top1;
        flag=0;
        while (temp1!=0){
            if (temp2->index == temp1->index){
                temp1->data = temp2->data+temp1->data;
                flag=1;
                break;
            }
            else{
                temp1 = temp1->next;
            }
        }
        if (flag==0){
            struct node *t;
            t = (struct node*)malloc(sizeof(struct node));
            t->data = temp2->data;
            t->index = temp2->index;
            t->next = top3;
            top3 = t;
        }
        temp2 = temp2->next;
    }
    temp3 = top3;
    while (temp3!=0){
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = temp3->data;
        t->index = temp3->index;
        t->next = top1;
        top1 = t;
        temp3 = temp3->next;
    }
    printf("Polynomial-1 + Polynomial 2 --> ");
    struct node *t;
    t = top1;
    while (t!=0){
        printf("%d*x^%d + ",t->data,t->index);
        t = t->next;
    }
    printf("\n");
    return 0;
}

int multiplication(){
    struct node *t;
    struct node *t2;
    struct node *t3;
    int ind,element,flag;
    t2 = top2;
    while (t2!=0){
        struct node *t1;
        t1 = top1;
        while (t1!=0){
            element = t1->data*t2->data;
            ind = t1->index+t2->index;
            flag=0;
            t3 = top3;
            while (t3!=0){
                if (t3->index == ind){
                    t3->data = element+t3->data;
                    flag=1;
                    break;
                }
                else{
                    t3 = t3->next;
                }
            }
            if (flag==0){
                t3 = top3;
                t = (struct node *)malloc(sizeof(struct node));
                t->data = element;
                t->index = ind;
                t->next = top3;
                top3 = t;
            }
            t1 = t1->next;
        }
        free(t1);
        t2 = t2->next;
    }
    printf("Polynomial-1 * Polynomial 2 --> ");
    t = top3;
    while (t!=0){
        printf("%d*x^%d + ",t->data,t->index);
        t = t->next;
    }
    printf("\n");
    return 0;
}

int main(){
    int choice,flag1=0,flag2=0;
    printf("---------POLYNOMIAL MANIPULATION---------\n");
    printf("1.Enter the first polynomial\n");
    printf("2.Enter the second polynomial\n");
    printf("3.Display\n");
    printf("4.Polynomial Addition\n");
    printf("5.Polynomial Multiplication\n");
    printf("6.Exit\n");
    while (choice!=6){
        printf("Enter the command -- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            e_insertion_first();
            flag1 = 1;
            break;
            case 2:
            e_insertion_second();
            flag2 = 1;
            break;
            case 3:
            display();
            break;
            case 4:
            if ((flag1==0)||(flag2==0)){
                printf("Please enter a polynomial first!\n");
            }
            else{
                addition();
            }
            break;
            case 5:
            if((flag1==0)||(flag2==0)){
                printf("Please enter a polynomial first!\n");
            }
            else{
                multiplication();
            }
            break;
            case 6:
            printf("--------Exiting--------\n");
            break;
            default:
            printf("Please enter a valid input !\n");
        }
    }
    return 0;
}