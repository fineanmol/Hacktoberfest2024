#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * insertFront(struct Node *,int);
struct Node * insertBack(struct Node *,int);
struct Node * insertAtIndex(struct Node *,int,int);
void insertAfterNode(struct Node *,int);
void print(struct Node *);
int main()
{
    struct Node *head,*second, *third,*fourth;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

    print(head);
    head=insertFront(head,5);
    print(head);
    head=insertBack(head, 7);
    print(head);
    head=insertAtIndex(head,1,12);
    print(head);
    insertAfterNode(fourth,5);
    print(head);
    return 0;
}

struct Node * insertFront(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct Node * insertBack(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct Node * insertAtIndex(struct Node *head,int position,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=position-1){
        ++i;
        p=p->next;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head;
}

void insertAfterNode(struct Node *p,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
}

void print(struct Node *ptr){
    printf("\nData:\n");
    while(ptr->next!=NULL){
        printf("%d\n" ,ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n" ,ptr->data);
}
