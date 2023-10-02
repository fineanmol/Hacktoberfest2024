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
void deleteHead(struct Node** head);
void deleteEnd(struct Node** head);
void deleteUser(struct Node** head, int position);
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

    printf("Deleting first element ");
    deleteHead(&head);
    print(head);

    printf("Deleting Last node ");
    deleteEnd(&head);
    print(head);

    printf("Deleting at position 3 ");
    deleteUser(&head, 3);
    printf("The list becomes ");
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
        printf("%d -> " ,ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n" ,ptr->data);
}

void deleteHead(struct Node** head)
{
    //new temp to store head node
    struct Node* temp = *head;

    //point head to the next node
    *head = (*head)->next;

    //free unused memory temp
    free(temp);
}
void deleteEnd(struct Node** head)
{
    //new temp to store head
    struct Node* temp = *head;
    //while temp data is not equal to NULL
    while (temp->next->next != NULL)
    {
        //next node equal to temp
        temp = temp->next;
    }
    //make the last node equal no NULL
    temp->next = NULL;

    //free unused memory
    //free(temp);
}

void deleteUser(struct Node** head, int position)
{
    //making head value equal to temp
    struct Node* temp = *head;

    int num;
    /*if element to be deleted is head*/
    if (position == 0)
    {
        printf("\n Element deleted is : %d\n",temp->data);
        /*make the next value to be head*/
        *head = (*head)->next;
        /*make temp head value equal none*/
        temp->next = NULL;
        /*free unused memory temp*/
        free(temp);
    }
    else
    {
        for(num = 0; num < position - 1; num++)
        {
            /*temp pointer points to previous node of node to be deleted*/
            temp = temp->next;
        }
        /*creating delete variable make it equal previous value to be deleted*/
        struct Node* delete = temp->next;

        /*delete will now be equal to node to be deleted*/
        temp->next = temp->next->next;
        printf(" and element deleted is : %d\n", delete->data);
        /*make value equal 0*/
        delete->next = NULL;
        /*free memory*/
        free(delete);
    }
}