#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void linkedlisttraversal(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("Element is : %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
//Insertion at head
struct Node * insertatfirst(struct Node *head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 8;
    head->next = second;

    second->data = 16;
    second->next = third;

    third->data = 24;
    third->next = fourth;

    fourth->data = 32;
    fourth->next = head;

    linkedlisttraversal(head);
    head = insertatfirst(head,0);
    printf("Circular Linked List after Insertion :\n");
    linkedlisttraversal(head);
    return 0;
}
