#include<stdio.h>
#include<stdlib.h>

void main()
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head, *newnode, *temp, *prev;
    head = NULL ;
    int choice;

    while(choice)
    {
        newnode = (struct node*)malloc( sizeof(struct node) );

        printf("\n Enter data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head == NULL)
        { head=temp=newnode; }
        else
        {
            prev->next=newnode;
            prev=newnode;
        }
        
        printf("\n Do you wan to continue[print] (0-no)/(1-yes) : ");
        scanf("%d",&choice);

        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            prev=temp;
            temp=temp->next;
        }
    }    
   
}
