#include <stdio.h>
#include <stdlib.h>

struct node {
    char a[20];
    struct node* next;
}*top1=0,*top2=0;

int end_insertion(struct node* r,int n){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the name : ");
    scanf("%s",p->a);
    p->next = 0;
    if (r==0){
        if (n==1){
            top1 = p;
        }
        else{
            top2 = p;
        }
    }
    else{
        while (r->next!=0){
            r = r->next;
        }
        r->next = p;
    }
    return 0;
}

struct node * end_deletion(struct node *r){
    struct node *s = r;
    while (r->next!=0){
        s = r;
        r = r->next;
    }
    s->next = 0;
    return r;
}

int display(struct node *r){
    while (r!=0){
        printf("%s\n",r->a);
        r = r->next;
    }
    return 0;
}

int concatenate(struct node *r){
    while (r->next!=0){
        r = r->next;
    }
    while (top2!=0){
        r->next = top2;
        top2 = top2->next;
        r = r->next;
    }
    return 0;
}

int reverse(struct node *r){
    struct node *temp;
    struct node *s;
    struct node *top3 = 0;
    temp = top3;
    while (r!=0){
        s = end_deletion(r);
        if (temp==0){
            top3 = s;
        }
        else{
            
        }
    }
}

int main(){
    printf("--------LINKED LISTS STRINGS--------\n");
    printf("1. Append an element to the end of the list\n");
    printf("2. Display the list\n");
    printf("3. Concatenate the two lists (1=1+2)\n");
    printf("4. Reverse the list\n");
    printf("17. Exit\n");

    int n,choice=0;
    struct node *temp;

    while (choice!=17){
        printf("Enter your command ---- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("List 1 or List 2 : ");
            scanf("%d",&n);
            switch(n){
                case 1:
                temp = top1;
                end_insertion(temp,1);
                break;
                case 2:
                temp = top2;
                end_insertion(temp,2);
                break;
                default:
                printf("Please enter a valid input!\n");
            }
            break;
            case 2:
            printf("List 1 or List 2 : ");
            scanf("%d",&n);
            switch(n){
                case 1:
                temp = top1;
                if (temp==0){
                    printf("No List Entered!\n");
                }
                else{
                    display(temp);
                }
                break;
                case 2:
                temp = top2;
                if (temp==0){
                    printf("No List Entered!\n");
                }
                else{
                    display(temp);
                }
                break;
                default:
                printf("Please enter a valid input!\n");
            }
            break;
            case 3:
            temp = top1;
            concatenate(temp);
            printf("Lists are susccessufully added\n");
            break;
            case 4:
            printf("List 1 or List 2 : ");
            scanf("%d",&n);
            switch(n){
                case 1:

                break;
                case 2:

                break;
                default:
                printf("Please enter a valid input!\n");
            }
            case 17:
            printf("----Exiting!----\n");
            break;
            default:
            printf("Enter a valid input!\n");
        }
    }
    return 0;
}