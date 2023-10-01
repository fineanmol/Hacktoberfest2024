#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
} *last=0;


int b_insertion(){
    int element;
    struct node *t;
    struct node *temp;
    printf("Enter the Element : ");
    scanf("%d",&element);
    t = malloc(sizeof(struct node));
    t->data = element;
    if (last==0){
        t->next = t;
        last = t;
    }
    else{
        t->next = last->next;
        last->next = t;
    }
    return 0;
}

int e_insertion(){
    int element;
    struct node *t;
    struct node *s;
    printf("Enter the Element : ");
    scanf("%d",&element);
    t = malloc(sizeof(struct node));
    t->data = element;
    if (last==0){
        t->next  = t;
        last = t;
    }
    else{
        t->next = last->next;
        last->next= t;
        last = t;
    }
    return 0;
}

int p_insertion(){
    int element,pos;
    struct node *t;
    struct node *p;
    t = last->next;

    printf("Enter the Element : ");
    scanf("%d",&element);
    printf("Enter the Element after which you want to insert : ");
    scanf("%d",&pos);
    do{
        if (t->data==pos){
            p = (struct node *)malloc(sizeof(struct node));
            p->data = element;
            p->next = t->next;
            t->next = p;
            if (t==last)
                last = p;
            break;
        }
        else{
            t = t->next;
        }
    }while (t!= last->next);
    return 0;
}

int b_deletion(){
    struct node *t;
    if (last==0){
        printf("NO NODES\n");
    }
    else if (last->next == last){
        printf("Deleted Element -- %d\n",last->data);
        last = 0;
    }
    else{
        t = last->next;
        printf("Deleted Element -- %d\n",t->data);
        last->next = t->next;
    }
    return 0;
}

int e_deletion(){
    struct node *t;
    if (last==0){
        printf("NO NODES!\n");
    }
    else if (last->next == last){
        printf("Deleted Element -- %d\n",last->data);
        last = 0;
    }
    else{
        t = last->next;
        while (t->next!=last){
            t = t->next;
        }
        printf("Deleted Element -- %d\n",last->data);
        t->next = last->next;
        last = t;
    }
    return 0;
}

int p_deletion(){
    if (last==0){
        printf("NO NODES!\n");
    }
    else if (last->next == last){
        printf("Deleted Element -- %d\n",last->data);
        last = 0;
    }
    else{
        struct node *t;
        struct node *s;
        int pos,count=1,flag=0;
        printf("Enter the position : ");
        scanf("%d",&pos);
        t = last->next;
        while (count<=pos-1){
            t = t->next;
            count++;
        }
        s = t->next;
        t->next = s->next;
     }
    return 0;
}

int search(){
    if (last==0){
        printf("NO NODES!\n");
    }
    else{
        struct node *t;
        int element,pos=1,flag = 0;
        t = last;
        printf("Enter the element : ");
        scanf("%d",&element);
        t =t->next;
        do{
            if (t->data == element){
                printf("Element found at %d\n",pos);
                flag=1;
                break;
            }
            else{
                t = t->next;
                pos++;
            }
        } while (t!=last->next);
        if (flag==0){
            printf("Element not found!\n");
        }
    }
    return 0;
}
int display(){
    struct node *t;
    t = last;
    if (t==0){
        printf("NO NODES!\n");
    }
    else{
        t = t->next;
        do{
            printf("%d ",t->data);
            t = t->next;
        } while (t!=last->next);
        printf("\n");
    }
    return 0;
}
int main(){
    printf("--------MENU--------\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    int choice,insert_choice,delete_choice;
    while (choice!=5){
        printf("Enter the Command -- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("------Inserion------\n");
            printf("1. Beginning Insertion\n");
            printf("2. End Insertion\n");
            printf("3. Position Insertion\n");
            printf("Enter the Choice -- ");
            scanf("%d",&insert_choice);
            switch(insert_choice){
                case 1:
                b_insertion();
                break;
                case 2:
                e_insertion();
                break;
                case 3:
                p_insertion();
                break;
                default:
                printf("Please enter a valid input!\n");
            }
            break;
            case 2:
            printf("------Deletion------\n");
            printf("1. Beginning Deletion\n");
            printf("2. End Deletion\n");
            printf("3. Position Deletion\n");
            printf("Enter the Choice -- ");
            scanf("%d",&delete_choice);
            switch(delete_choice){
                case 1:
                b_deletion();
                break;
                case 2:
                e_deletion();
                break;
                case 3:
                p_deletion();
                break;
                default:
                printf("Please enter a valid input!\n");
            }
            break;
            case 3:
            search();
            break;
            case 4:
            display();
            break;
            case 5:
            printf("--------Exiting--------\n");
            break;
            default:
            printf("Please enter a valid input!\n");
        }
    }
}