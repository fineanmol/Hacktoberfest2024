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
    t->next=0;
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

int b_deletion(){
    if (top==0){
        printf("QUEUE UNDEFLOW!\n");
    }
    else{
        printf("Deleted element -- %d\n",top->data);
        top = top->next;
    }
    return 0;
}

int display(){
    if (top==0){
        printf("QUEUE UNDEERFLOW!\n");
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
        printf("QUEUE UNDEERFLOW!\n");
    }
    else{
        struct node *t;
        int element,pos=1,flag=0;
        printf("Enter the element : ");
        scanf("%d",&element);
        t = top;
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
            printf("Element not found !\n");
        }
    }
    return 0;
}

int main(){
    int choice;
    printf("-----------QUEUE USING LINKED LIST-----------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("5. Exit\n");
    while (choice!=5){
        printf("Enter your command -- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            e_insertion();
            break;
            case 2:
            b_deletion();
            break;
            case 3:
            display();
            break;
            case 4:
            search();
            break;
            case 5:
            printf("------Exiting------\n");
            break;
            default:
            printf("Please enter a valid input!\n");
        }
    }
    return 0;
}