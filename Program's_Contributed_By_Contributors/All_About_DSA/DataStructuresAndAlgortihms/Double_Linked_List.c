#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
}*start=0,*end=0;

int binsert(){
    int num;
    struct node *t;
    struct node *temp;
    printf("Enter the element : ");
    scanf("%d",&num);
    t = (struct node*)malloc(sizeof(struct node));
    t->data = num;
    t->rlink = 0;
    t->llink = 0;
    if (start==0){
        start = t;
        end = t;
    }
    else{
        temp = start;
        t->rlink = start;
        start->llink = t;
        start = t;
        while (temp->rlink!=0){
            temp = temp->rlink;
        }
        end = temp;
    }
    return 0;
}

int einsert(){
    int num;
    struct node *t;
    printf("Enter the element : ");
    scanf("%d",&num);
    t = (struct node*)malloc(sizeof(struct node));
    t->data = num;
    if (start==0){
        t->rlink = 0;
        t->llink = 0;
        start = t;
        end = t;
    }
    else{
        end->rlink = t;
        t->llink = end;
        t->rlink = 0;
        end = t;
    }
    return 0;
}

int pinsert(){
    int num,pos,flag=0;
    struct node *temp,*t;
    printf("Enter element and position : ");
    scanf("%d %d",&num,&pos);
    if (pos==1){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = num;
        t->llink = 0;
        start->llink = t;
        t->rlink = start;
        start = t;
    }
    else{
        temp = start;
        for (int i=1;i<pos-1;i++){
            if (temp!=0){
                temp = temp->rlink;
            }
            else{
                flag=1;
            }
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = num;

        if (flag==0){
            t->rlink = temp->rlink;
            t->llink = temp;
            temp->rlink = t;
            t->rlink->llink = t;
            return 0;
        }
        else{
            end->rlink = t;
            t->llink = end;
            t->rlink = 0;
            end = t;
        }
    }  
    return 0;
}

int delete(){
    if (start==0){
        printf("NO NODES!\n");
    }
    else{
        int num,flag=0;
        struct node *old,*temp;
        printf("Enter the element : ");
        scanf("%d",&num);
        temp = start;
        old = start;
        while (temp!=0){
            if (temp->data==num){
                if ((temp->rlink==0)&&(temp->llink==0)){
                    printf("Deleted Element %d\n",temp->data);
                    start = 0;
                    end = 0;
                }
                else if (temp==start){
                    printf("Deleted Element %d\n",temp->data);
                    start = start->rlink;
                    start->llink = 0;
                }
                else if (temp==end){
                    printf("Deleted Element %d\n",temp->data);
                    temp = temp->llink;
                    temp->rlink = 0;
                    end = temp;
                }
                else{
                    old->rlink = temp->rlink;
                    temp->rlink->llink = old;
                    printf("Deleted Element %d\n",temp->data);
                    free(temp);
                }
                flag=1;
                break;
            }
            else{
                old = temp;
                temp = temp->rlink;
            }
        }
        if (flag==0){
            printf("Element not found!\n");
        }
    }
    return 0;
}
int display(){
    if (start==0){
        printf("NO NODES!\n");
    }
    else{
        struct node *temp;
        temp = start;
        while (temp!=0){
            printf("%d ",temp->data);
            temp = temp->rlink;
        }
        printf("\n");
    }
    return 0;
}

int search(){
    if (start==0){
        printf("NO NODES!\n");
    }
    else{
        struct node *temp;
        int element,pos=1,flag=0;
        printf("Enter the element : ");
        scanf("%d",&element);
        temp = start;
        while (temp!=0){
            if (temp->data==element){
                printf("Element found at %d\n",pos);
                flag=1;
                break;
            }
            else{
                temp = temp->rlink;
                pos++;
            }
        }
        if (flag==0){
            printf("Element not found !\n");
        }
    }
    return 0;
}

int main(){
    int choice,choice_insert;
    printf("-----------DOUBLY LINKED LIST-----------\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("5. Exit\n");
    while (choice!=5){
        printf("Enter the command -- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("-------INSERTION-------\n");
            printf("1. Beginning Insertion\n");
            printf("2. End Insertion\n");
            printf("3. Position Insertion\n");
            printf("Enter the command -- ");
            scanf("%d",&choice_insert);
            switch(choice_insert){
                case 1:
                binsert();
                break;
                case 2:
                einsert();
                break;
                case 3:
                pinsert();
                break;
                default:
                printf("Please enter a valid input !\n");
            }
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            search();
            break;
            case 5:
            printf("--------Exiting--------\n");
            break;
            default:
            printf("Please enter a valid input!\n");
        }
    }
    return 0;
}