#include<stdio.h>
#include<stdlib.h>
typedef struct Snode
{
    int info;
    struct Snode *next;
}SN;
SN* insertatbig(SN *head)
{
    SN *temp;
    temp = (SN*)malloc(sizeof(SN));
    if (temp == NULL)
    printf("Memory Is Not Available! \n");
    else
    {
        printf("Enter The Value ? \n");
        scanf("%d",&temp->info);
        temp->next = head;
        head = temp;
    }
    return head;
    }
SN* insertatlast(SN *head)
    {
    SN *temp;
    temp = (SN*)malloc(sizeof(SN));
    if (temp == NULL)
    printf("Memory Is Not Available! \n");
    else if(head==NULL)
    {
        printf("Enter The Value?\n");
        scanf("%d",&temp->info);
        head=temp;
        temp->next = NULL;
    }
    else
    {
        SN *p1;
        p1 = head;
        while(p1->next!=NULL)
        p1 = p1->next;
            printf("Enter Info? \n");
            scanf("%d",&temp->info);
            temp->next = NULL;
            p1->next= temp;

    }
    return head;
    }
SN* Display(SN *head)
    {
        SN *temp = head;
        if (head == NULL)
        printf("LINKED LIST IS Empty \n");
        else
        while(temp!=NULL)
        {
            printf("%d \n",temp->info);
            temp = temp->next;

        }
        return head;
    }
SN* Delfrombig(SN *head)
    {
        if(head == NULL)
        printf("Linked List Is Empty \n");
        else
        {
         SN *p1 = head;
         head = p1->next;
         printf("Deleted Info = %d \n",p1->info);
         free(p1);
        }
    return head;
    }
SN* Delfromlast(SN *head)
    {
        if(head == NULL)
        printf("Linked List Is Empty \n");
        else
        {
        SN *p1,*p2;
        p1=head;
         while(p1->next!=NULL)
         {
            p2 = p1;
            p1 = p1->next;
         }
        p2->next = NULL;
        printf("Deleted Info = %d \n",p1->info);
        free(p1);

    }
    return head;
    }
    SN* search(SN* head)
    {
    int c=1,t;

    if(head==NULL)
    printf("Linked List IS Empty\n");
    else
    {   SN* p1 = head;
        printf("Enter elem. you want to search \n");
        scanf("%d",&t);
        while(p1->info!=t && p1!=NULL)
        {
            p1=p1->next;
            c++;
        }
        if(p1==NULL)
            printf("Not found\n");
        else
            printf("Found at %d Position\n", c);
    }
    return head;
}
SN* insertatpos(SN *head)
    { 
      int a,c = 1;
      SN *temp;
      SN *p1 = head;
      temp = (SN*)malloc(sizeof(SN));
      if (temp == NULL)
      printf("Memory Is Not Available! \n");
      else
      {
        printf("Enter The Position ? \n");
        scanf("%d",&a);
        while(c!=(a-1))
        {
            p1 = p1->next;
            c++;
        }
        printf("Enter The Value? \n");
        scanf("%d",&temp->info);
        temp->next = p1->next;
        p1->next = temp;
      }
    return head;
    }
SN* Deletefrompos(SN *head)
    {
        int c=1,a;
        SN *p1,*p2;
        p1 = head;
        if(head == NULL)
        printf("Linked List Is Empty \n");
        else
        {
        printf("Enter The Position ? \n");
        scanf("%d",&a);
        while(c!=(a-1))
        {
            p2 = p1;
            p1 = p1->next;
            c++;
        }
        printf("Deleted Info = %d \n",p1->info);
        p2->next = p1->next;
        free(p1);
        }
        return head;
    }
SN* insertaftg(SN *head)
{
    int t;
    SN *temp;
    temp = (SN*)malloc(sizeof(SN));
    if (temp == NULL)
    printf("Memory Is Not Available! \n");
    else
    {   SN* p1 = head;
        printf("Enter Element After which The Element is to be inserted? \n");
        scanf("%d",&t);
        while(p1->info!=t && p1!=NULL)
        p1=p1->next;
        if(p1==NULL)
            printf("Not found\n");
        else
        {
        printf("Enter The Value? \n");
        scanf("%d",&temp->info);
        temp->next = p1 ->next;
        p1 ->next = temp;
        }
    }
return head;
}
SN* insertbefrg(SN *head)
{
    int t;
    SN *temp;
    temp = (SN*)malloc(sizeof(SN));
    if (temp == NULL)
    printf("Memory Is Not Available! \n");
    else
    {   SN *p1 = head;
        SN *p2 = head;
        printf("Enter Element Before which The Element is to be inserted? \n");
        scanf("%d",&t);
        while(p1->info!=t && p1!=NULL)
            {   p2 = p1;
                p1=p1->next;
            }
             printf("Enter The Value? \n");
             scanf("%d",&temp->info);
            temp->next = p2 ->next;
            p2 ->next = temp;
}
return head;
}
SN* deleteaftg(SN *head)
{
    int t;
    SN *temp;
    if(head == NULL)
    printf("Linked List Is Empty \n");
    else
    {   SN *p1 = head;
        printf("Enter Element After which The Element is to be Deleted? \n");
        scanf("%d",&t);
        while(p1->info!=t && p1!=NULL)
        p1=p1->next;
        if(p1==NULL)
            printf("Not found\n");
        else
        {
            temp = p1->next;
            printf("Deleted Info = %d \n",temp->info);
            p1->next = temp->next;
            free(temp);
        }
            
     } 
return head;
}
SN* deletebefrg(SN *head)
{
    int t;
    SN *p1=head;
    SN *p2=head;
    SN *p3=head;
    if(head == NULL)
    printf("Linked List Is Empty \n");
    else
    {   SN *p1 = head;
        printf("Enter Element Before which The Element is to be Deleted? \n");
        scanf("%d",&t);
        while(p1->info!=t && p1!=NULL)
        {
            p3=p2;
            p2=p1;
            p1=p1->next;
        }
        if(p1==NULL)
            printf("Not found\n");
        else
        {
            printf("Deleted Info = %d \n",p2->info);
            p3->next = p2->next;
            free(p2);
        }
            
     } 
return head;
}

SN* alternate(SN* head)
{
    if(head==NULL)
    printf("Empty!");
    else if(head->next==NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
    SN *p1 = head;
    SN *p2;
    while(p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
        p2->next=p1->next;
        free(p1);
        p1=p2->next;

       
    }
    return head;
}
}
    int main()
    {
        SN *head = NULL;
        int a;
        do{
        printf("Enter The Choice?\n1. For Insertion At Beginning \n2. For Insertion At Last \n3. Display\n4.Delete From Beginning\n5.Delete From Last\n6.Insert At Position\n7.Delete From Position\n8.Search\n9.Insert After An Element\n10.Insert Before An Element\n11.Delete After An Element\n12. Delete before an element\n13. Delete Alternate");
        scanf("%d",&a);
        switch(a)
        {
            case 1 : head = insertatbig(head);
            break;
            case 2 : head = insertatlast(head);
            break;
            case 3 : head = Display(head);
            break;
            case 4 : head = Delfrombig(head);
            break;
            case 5 : head = Delfromlast(head);
            break;
            case 6 : head = insertatpos(head);
            break;
            case 7 : head = Deletefrompos(head);
            break;
            case 8: head = search(head);
            break;
            case 9: head = insertaftg(head);
            break;
            case 10: head = insertbefrg(head);
            break;
            case 11: head = deleteaftg(head);
            break;
            case 12: head = deletebefrg(head);
            break;
            case 13: head = alternate(head);
            break;
            default : exit(0);
        }
        }while(1);
    }    