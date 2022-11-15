#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//Delete at first
struct Node * deleteatfirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
//Delete in between
struct Node * deleteinbetween(struct Node * head,int index){
    struct Node * p = head;
    struct Node * q = head->next;
    int i=0;
    for(i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
//Delete in End
struct Node * deleteatend(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
//Delete at Key
struct Node * deleteatkey(struct Node * head,int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 14;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 21;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 28;
    fourth->next = NULL;
    printf("Linked List before Deletion :\n");
    linkedListTraversal(head);
    //head = deleteatfirst(head);
    //head = deleteinbetween(head,2);
    //head = deleteatend(head);
    head = deleteatkey(head,14);
    printf("Linked List after Deletion :\n");
    linkedListTraversal(head);
    return 0;
}
