#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printlist(struct node *head){
    struct node* ptr; 
    ptr = head;//head denotes start of linked list
    if(head == NULL) {
        printf("\n\nStarting address : NULL");//no node to display
        return;
    }
    else printf("\n\nStarting address : %p --->",ptr);

    while(ptr->next != NULL){
        printf("|%d|%p| ---> ",ptr->data,ptr->next);
        ptr = ptr->next;
    }
    if(ptr->next == NULL) printf("|%d|NULL| ",ptr->data);//the last missed node due to loop breaking at that point
}


void appendafter(struct node **head,int pos,int ele){
    struct node *newnode;
    struct node *ptr;
    newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->data = ele;
    newnode->next = NULL;
    if(*head == NULL) {
        *head = newnode;
        return;
    }
    else{
        ptr = *head;
        while(--pos){//positioning starts from 1 till n hence always start from
                     //1 less as (if pos = 2 then 2nd node's next is required)
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        return;
    }
}

void appendbefore(struct node **head,int pos,int ele){
    struct node *newnode;
    struct node *ptr;
    newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->data = ele;
    newnode->next = NULL;
    if(*head == NULL) {
        *head = newnode;
        return;
    }
    else{
        ptr = *head;
        pos--;//a node before hence after a the previous of that required node
        while(--pos>0){//positioning starts from 1 till n hence always start from
                     //1 less as (if pos = 2 then 2nd node's next is required)
            ptr = ptr->next;
        }
        if(ptr == *head){
            newnode->next = ptr;
            *head = newnode;
        }
        else{
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        return;
    }
}

void delfromstart(struct node **head){
    struct node *ptr;
    if(*head==NULL) printf("\nSorry! No node present to delete!!!\n\n");
    else {
        ptr = *head;
        *head = (*head)->next;
        printf("\nFirst node deleted successfully!!!\n\n");
        free(ptr);
    }
}

void delfromend(struct node **head){
    struct node *ptr,*prev;
    if(*head==NULL) printf("\nSorry! No node present to delete!!!\n\n");
    else {
        ptr = *head;
        prev = ptr;
        while(ptr->next !=NULL){
            prev = ptr;
            ptr = ptr->next;
        }
        if((*head)->next==NULL) *head = NULL;//empty the list i.e. delete the
                                             //only one node
        else prev->next = NULL;
        free(ptr);
        printf("\nLast node deleted successfully!!!\n\n");
    }
}

int main(){
    struct node *head = NULL;
    int ch,ele,nodenum;
    while(1){
        printf("\n\n0. Exit\n1. Add element after given node\n2. Add element before given node\n3. Print list\n4. Delete node from start\n5. Delete node from end\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch>=0 && ch<=5){
            if(ch==0)break;
            else if(ch<3){
                printf("Enter element : ");
                scanf("%d",&ele);
                printf("Enter a valid node number : ");
                scanf("%d",&nodenum);
                if(ch==1) appendafter(&head,nodenum,ele);
                else appendbefore(&head,nodenum,ele);
            }
            else if(ch==3) printlist(head);
            else if(ch==4) delfromstart(&head);
            else delfromend(&head);
        }
        else printf("Wrong choice!!! Try Again.\n\n");
    }
    return 0;
}

