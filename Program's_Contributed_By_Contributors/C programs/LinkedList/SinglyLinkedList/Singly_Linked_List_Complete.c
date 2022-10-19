#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *createlist(struct node *head);
struct node* addtoempty(struct node* head,int data);
struct node* addtoend(struct node* head,int data);
void findelement(struct node* head,int n);
struct node* reverse(struct node* head);
void lastnodeaddress(struct node* head);
struct node* insertbegin(struct node* head,int data);
struct node* insertpos(struct node* head,int data,int pos);
struct node* deletebegin(struct node* head);
struct node* deleteend(struct node* head);
struct node* deletepos(struct node* head,int pos);
int main()
{
    struct node * head=NULL;
    struct node *ptr,*ptrloop;
    head=createlist(head);
    if(head==NULL)
    {
        printf("Node not created");
        exit(0);
    }
    ptr=head;
    int i=0;
    while(ptr!=NULL)
    {
        ++i;
        printf("Data for node %d is: %d\n",i,ptr->data);
        ptr=ptr->link;
    }
    i=0;
    int ch;
    while(1)
    {
    printf("\nEnter your choice:\n----------------------------\n");
    printf("1 for Finding a particular element in a linked list\n2 for Reversal of a linked list\n3 for Insertion\n4 for Deletion\n5 for Find address of the last node\n6 Traverse\n7 Exit\n");
    scanf("%d",&ch);
    
    int oh;
    
    switch (ch)
    {
    case 1:
        int num;
        printf("Enter the elemet to find in linked list: ");
        scanf("%d",&num);
        findelement(head,num);
        break;
    case 2:
        head=reverse(head);
        break;

    case 5:
        lastnodeaddress(head);
        break;

    case 3:
        int no;
        printf("\n1.Insertion at beggining\n2.Insertion at end\n3.Insertion at specified location\n");
        scanf("%d",&oh);
        switch (oh)
        {
        case 1:
            printf("Enter Data for Inserting Node: ");
            scanf("%d",&no);
            head=insertbegin(head,no);
            break;
        case 2:
            printf("Enter Data for Inserting Node: ");
            scanf("%d",&no);
            head=addtoend(head,no);
            break;
        case 3:
            int pos;
            printf("Enter Data for Inserting Node: ");
            scanf("%d",&no);
            printf("Enter Position for Inserting Node: ");
            scanf("%d",&pos);
            head=insertpos(head,no,pos);
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
        break;

    case 4:
        printf("\n1.Delete beggining node\n2.Delete end node\n3.Delete specified node\n");
        scanf("%d",&oh);
        switch (oh)
        {
        case 1:
            head=deletebegin(head);
            break;
        case 2:
            head=deleteend(head);
            break;
        case 3:
            int pos;
            printf("Enter Position for Inserting Node: ");
            scanf("%d",&pos);
            head=deletepos(head,pos);
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
        break;
    case 6:
        printf("Traversing Through the Linked List:\n");
        ptrloop=head;
        printf("\n");
        while(ptrloop!=NULL)
        {
            ++i;
            printf("Data for node %d is: %d\n",i,ptrloop->data);
            ptrloop=ptrloop->link;
        }
        i=0;
        break;
    
    case 7:
        exit(0);

    default:
        printf("Enter Correct Choice\n");
        break;
    }
    int end;
    printf("\nDo you wish to continue: 1 for Yes & 0 for No\n");
    scanf("%d",&end);
    if (end==1)
    continue;
    else if(end==0)
    exit(0);

    }

}
struct node *createlist(struct node *head)
{
    int n,data,i;
    printf("Enter no of node: ");
    scanf("%d",&n);
    if(n==0)
    return head;
    printf("Enter the data for 1st node : \n");
    scanf("%d",&data);
    head=addtoempty(head,data);
    for(i=1;i<n;i++)
    {
        printf("Enter data for node %d : \n",(i+1));
        scanf("%d",&data);
        head=addtoend(head,data);
    }
    return head;
}
struct node* addtoempty(struct node* head,int data)
{
    struct node* temp =(struct node*)malloc(sizeof(struct node*));
    temp->data=data;
    temp->link=NULL;
    head=temp;
    return head;

}
struct node* addtoend(struct node* head,int data)
{
    struct node *temp,*tp;
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=data;
    temp->link=NULL;
    tp=head;
    while(tp->link!=NULL)
    tp=tp->link;
    tp->link=temp;
    return head;  
}
void findelement(struct node* head,int n)
{
    struct node* temp=head;int f=0,loc=0;
    while(temp!=NULL)
    {
        ++loc;
        if(temp->data==n)
        {
            ++f;
            break;
        }
        temp=temp->link;
    }
    if(f==1)
    printf("Found element at node %d\n",loc);
    else
    printf("Not Found");

}
struct node* reverse(struct node* head)
{
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) 
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;

}
void lastnodeaddress(struct node* head)
{
   struct node* temp = head;
    while(temp->link!=NULL)
    temp=temp->link;
    printf("Address of last node is: %p",&temp);
}
struct node* insertbegin(struct node* head,int data)
{
    struct node *temp=head,*tp = (struct node*)malloc(sizeof(struct node*));
    tp->data=data;
    tp->link=temp;
    head=tp;
    return head;
}
struct node* insertpos(struct node* head,int data,int pos)
{
    struct node* tp=(struct node*)malloc(sizeof(struct node*));
    struct node* temp=head,*tp2;
    tp->data=data;
    tp->link=NULL;
    pos--;
    while(pos!=0)
    {
        tp2=temp;
        temp=temp->link;
        --pos;
    }
    tp2->link=tp;
    tp->link=temp;
    return head;
}
struct node* deletebegin(struct node* head)
{
    struct node* temp=head;
    head=head->link;
    printf("Deleting node data is: %d",temp->data); 
    free(temp);
    return head;
}
struct node* deleteend(struct node* head)
{
    struct node *temp=head,*tp;
    while(temp->link!=NULL)
    {
        tp=temp;
        temp=temp->link;
    }
    tp->link=NULL;
    printf("Deleting node data is: %d",temp->data); 
    free(temp);
    return head;
}
struct node* deletepos(struct node* head,int pos)
{
    struct node* temp=head,*tp;
    --pos;
    while(pos!=0)
    {
        tp=temp;
        temp=temp->link;
        --pos;
    }
    tp->link=temp->link;
    printf("Deleting node data is: %d",temp->data); 
    free(temp);
    return head;
}
