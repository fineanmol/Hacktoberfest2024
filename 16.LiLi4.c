/*Linked List creation and working with double pointers.
Case 1 for creating
Case 2 for displaying
Case 3 for adding node in beginning
Case 4 for adding node before a given value
Case 5 for deleting a node of a given position
Case 6 for deleting a node with even value
Case 7 for counting no. of nodes
*/

#include<stdio.h>
#include<stdlib.h>             //for dynamic memory allocation
struct node
{
    int data;
    struct node *link;
};
void createlist(struct node **h, int N)
{
    int val,i;
    struct node *ptr=NULL;
    struct node *temp=NULL;
    for(i=0;i<N;i++)
    {
        printf("Enter the value to be inserted in node %d:\n",i+1);
        scanf("%d",&val);
        temp= (struct node*)malloc(sizeof(struct node));
        temp->data=val;
        temp->link=NULL;
        if(*h==NULL)
        {
            *h=temp;
            ptr=temp;
        }
        else
        {
            ptr->link=temp;
            ptr=temp;
        }
    }
    printf("Linked list created!!\n\n");
}
void displaylist(struct node **h)
{
    struct node* ptr;
    ptr=*h;
    printf("The linked list is:\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n\n");
}
void addnodebeg(struct node**h)
{
    int val;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted:\n");
    scanf("%d",&val);
    temp->data=val;
    temp->link=*h;
    *h=temp;
    printf("A node is added in the beginning of the linked list !!\n\n");
}
void addnodeval(struct node**h,int x)
{
    int val,item,p,i;
    struct node*ptr=*h;
    printf("Enter the value from linked list before which another node is to be added: ");
    scanf("%d",&item);
    printf("Value of x is:%d\n",x);
    for(i=0;i<x;i++)
    {
        if(ptr->data==item)
        {
            p=i+1;
        }
            ptr=ptr->link;
        
    }
    printf("The position of the value,%d in the linked list is %d\n",item,p);
    printf("Enter the value to be inserted: \n ");
    scanf("%d",&val);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    ptr=*h;
    if(p==1)
    {
        temp->link=*h;
        *h=temp;
    }
    else
    {
        for(i=1;i<p-1;i++)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
        
    }

    printf("A node is added before the value %d!!\n\n",item);
}
void delnode(struct node**h,int x)
{
    struct node* curr=*h;
    struct node* prev=*h;
    struct node* q;
    int dn,p,i;
    printf("Enter the position of the node which is to be deleted: \n");
    scanf("%d",&p);
    if(p<=x && p>=1)
    {
        for(i=1;i<=p;i++)
        {
            if(i==p)
            {
                if(p==1)
                {
                    q=curr;

                    dn=curr->data;
                    curr=curr->link;
                    *h=curr;
                    free(q);
                    printf("The node of position 1 is deleted which had value %d !\n\n",dn);
                }
                else
                {
                    q=curr;
                    dn=curr->data;
                    prev->link=curr->link;
                    curr=curr->link;
                    free(q);
                    printf("The node of position %d is deleted which had value %d !\n\n",p,dn);

                }
                
            }
            prev=curr;
            curr=curr->link;
        }
    }
    else
    {
        printf("this position does not exist in the Linked list!!\n\n");
    }
}
void delnodeeven(struct node**h)
{
    struct node* curr=*h;
    struct node* prev=*h;
    struct node* q;
    int p=1;

    while(curr!=NULL)
    {
        if(curr->data%2==0)
        {
            if(p==1)
            {
                q=curr;
                *h=curr->link;
                curr=curr->link->link;
                free(q);
            }
            else
            {
                q=curr;
                prev->link=curr->link;
                curr=curr->link;
                free(q);
            }
        }
        else
        {
            prev=curr;
            curr=curr->link;
        }
        p++;
    }
    printf("the desired nodes were deleted!!\n\n");  
}
int countnode(struct node**h )
{
    int cn=0;
    struct node*ptr=*h;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        cn++;
    }
    printf("The no. of nodes are:%d\n\n\n",cn);
    return cn;
}
int main()
{
    struct node* head=NULL;
    int c,n,ch;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    for(;;)
    {
    printf("Enter 1 to create list\nEnter 2 to display list\nEnter 3 to add a node in the beginning\nEnter 4 to add node before a specific value of the linked list\nEnter 5 to delete a node\n");
    printf("Enter 6 to delete the nodes with an even value\nEnter 7 to count the no. of nodes in Linked List\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
                createlist(&head,n); 
                break;
        case 2:
                displaylist(&head);
                break;
        case 3:
                addnodebeg(&head);
                break;
        case 4:
                c=countnode(&head);
                addnodeval(&head,c);
                break;
        case 5:
                c=countnode(&head);
                delnode(&head,c);
                break;
        case 6:
                delnodeeven(&head);
                break;
        case 7:
                countnode(&head);
                break;
        default:
                printf("wrong choice!");
    }

    }
    return 0;
}