#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *back;
    int data;
    struct node *front;
};
struct node *createlist(struct node *head);
struct node* addtoempty(struct node* head,int data);
struct node* addtoend(struct node* head,int data);
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
    ptr=head;
    int i=0;
    while(ptr!=NULL)
    {
        ++i;
        printf("Data for %d node is: %d\n",i,ptr->data);
        ptr=ptr->front;
    }
    i=0;
    int ch;
    while(1)
    {
    printf("\nEnter your choice:\n----------------------------\n");
    printf("1 for Insertion\n2 for Deletion\n3 Traverse\n4 Exit\n");
    scanf("%d",&ch);
    int oh;
    switch (ch)
    {
    case 1:
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

    case 2:
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
            printf("Enter Position for Deleting Node: ");
            scanf("%d",&pos);
            head=deletepos(head,pos);
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
        break;
    case 3:
        printf("Traversing Through the Linked List:\n");
        ptrloop=head;
        printf("\n");
        while(ptrloop!=NULL)
        {
            ++i;
            printf("Data for node %d is: %d\n",i,ptrloop->data);
            ptrloop=ptrloop->front;
        }
        i=0;
        break;
    
    case 4:
        exit(0);

    default:
        printf("Enter Correct Choice\n");
        break;
    }
    ptrloop=head;
    printf("\n");
    while(ptrloop!=NULL)
        {
            ++i;
            printf("Data for node %d is: %d\n",i,ptrloop->data);
            ptrloop=ptrloop->front;
        }
        i=0;
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
    printf("Enter the data for 1st node: \n");
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
    temp->back=NULL;
    temp->data=data;
    temp->front=NULL;
    head=temp;
    return head;

}
struct node* addtoend(struct node* head,int data)
{
    struct node *temp,*tp;
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->back=NULL;
    temp->data=data;
    temp->front=NULL;
    tp=head;
    while(tp->front!=NULL)
    tp=tp->front;
    tp->front=temp;
    temp->back=tp;
    return head;
    
}
struct node* insertbegin(struct node* head,int data)
{
    struct node *temp=head,*tp = (struct node*)malloc(sizeof(struct node*));
    tp->data=data;
    tp->front=temp;
    tp->back=NULL;
    temp->back=tp;
    head=tp;
    return head;
}
struct node* insertpos(struct node* head,int data,int pos)
{
    struct node* tp=(struct node*)malloc(sizeof(struct node*));
    struct node* temp=head;
    tp->data=data;
    tp->front=NULL;
    tp->back=NULL;
    pos--;
    while(pos!=0)
    {
        temp=temp->front;
        --pos;
    }
    (temp->back)->front=tp;
    tp->front=temp;
    temp->back=tp;
    return head;
}
struct node* deletebegin(struct node* head)
{
    struct node* temp=head;
    head=head->front;
    head->back=NULL;
    printf("Deleting node data is: %d\n",temp->data); 
    free(temp);
    return head;
}
struct node* deleteend(struct node* head)
{
    struct node *temp=head;
    while(temp->front!=NULL)
    {
        temp=temp->front;
    }
    (temp->back)->front=NULL;
    printf("Deleting node data is: %d\n",temp->data); 
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
        temp=temp->front;
        --pos;
    }
    tp->front=temp->front;
    printf("Deleting node data is: %d\n",temp->data); 
    free(temp);
    return head;
}