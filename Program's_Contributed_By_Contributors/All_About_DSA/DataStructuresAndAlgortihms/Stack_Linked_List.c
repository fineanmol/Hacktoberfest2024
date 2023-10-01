#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=0;

int e_insertion(){
    struct node *t;
    struct node *s;
    int element;
    printf("Enter the element : ");
    scanf("%d",&element);
    t = (struct node *)malloc(sizeof(struct node));
    t->data = element;
    t->next = 0;
    if (top==0){
        top = t;
    }
    else{
        s = top;
        while (s->next!=0){
            s = s->next;
        }
        s->next = t;
    }
    return 0;
    
}

int e_deletion(){
    if (top==0){
        printf("STACK UNDEERFLOW!\n");
    }
    else if (top->next==0){
        printf("Deleted Element -- %d\n",top->data);
        top = 0;
    }
    else{
        struct node *t;
        struct node *s;
        t = top;
        while (t->next!=0){
            s = t;
            t = t->next;
        }
        printf("Delted Element -- %d\n",t->data);
        s->next = 0;
    }
    return 0;
}

int display(){
    if (top==0){
        printf("NO NODE!\n");
    }
    else{
        struct node *t;
        t = top;
        while (t!=0){
            printf("%d ",t->data);
            t = t->next;
        }
        printf("\n");
    }
    return 0;
}

int search(){
    if (top==0){
        printf("NO NODE!\n");
    }
    else{
        struct node *t;
        int element,pos=1,flag=0;
        t = top;
        printf("Enter the element : ");
        scanf("%d",&element);
        while (t!=0){
            if (t->data==element){
                printf("Element found at %d\n",pos);
                flag=1;
                break;
            }
            else{
                t = t->next;
                pos++;
            }
        }
        if (flag==0){
            printf("Element not found!\n");
        }
    }
    return 0;
}

int main(){
    int choice;
    printf("-------------STACK USING LINKED LIST-------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("5. Exit\n");
    while (choice!=5){
        printf("Enter your choice -- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            e_insertion();
            break;
            case 2:
            e_deletion();
            break;
            case 3:
            display();
            break;
            case 4:
            search();
            break;
            case 5:
            printf("-------EXITING-------\n");
            break;
            default:
            printf("Please enter a valid input!\n");
        }
    }
    return 0;
}