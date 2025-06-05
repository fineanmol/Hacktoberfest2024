#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}Node;
Node *head;

Node *creatnode()
{
    Node* nw;
    nw=(Node *)malloc(sizeof(Node));
    nw->prev=nw;
    nw->next=nw;
    return nw;
}

void insleft(int data)
{
    Node *p;
    p=creatnode();
    p->data=data;
    if(head!=NULL)
    {
        p->next=head;
        p->prev=head->prev;
        head->prev->next=p;
        head->prev=p;
    }
    head=p;
}

Node *find(int data)
{
    Node *p;
    p=head;
    while((p->data!=data) && (p!=NULL))
    {
        p=p->next;
    }
    return p;
}

void insertany(int  data,int x)
{
    Node *p=NULL,*pw;
     p=find(x);
    if(p==NULL)
    {
        printf("Node dose not exist\n");
    }
    else{
    pw=creatnode();
    pw->data=data;
    pw->next=p->next;
    pw->prev=p;
    p->next->prev=pw;
    p->next=pw;

    }
    // p=NULL;
}

void insright(int data)
{
    Node *p;
    p=creatnode();
    p->data=data;
    if(head!=NULL)
    {
        p->next=head;
        p->prev=head->prev;
        head->prev->next=p;
        head->prev=p;
    }
    else
    head=p;
}

void delfirst()
{
    Node *p;
    int k=head->data;
    p=head;
    if(head==NULL)
    printf("no node present\n");
    else{
    p->next->prev=p->prev;
    p->prev->next=p->next;
    head=p->next;
    }
    free(p);
    p=NULL;
    printf("%d \n",k);
}

int deleany(int data)
{
    Node *p,*q;
    int da=-999;
     q=find(data);
    if(q!=NULL)
    {
     p=q->prev;
    da=q->data;
    p->next=q->next;
    q->next->prev=q->prev;
    
    free(q);
    }
    else
    printf("there is no node\n");
    return da;
}

void delend()
{
     Node *p,*q;
     p=head;q=p->prev->prev;
     int k=head->prev->data;
    q->next=head;
     head->prev=q;//(ye shyad issiliye kamm nhi kr ra lkyu ki q ka value iske upperr me already change ho gaya hsai.)
     free(head->prev);
    // p=NULL;
//      printf("%d \n",k);
   
// Node *p=head->prev;
// p->prev->next=head;
// head->prev=p->prev;
// free(p);
}

void traverse()
{
    Node *p;
    p=head;
    do{
        printf("%d ->",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

int main()
{
    int a,da,c,n;
    do{
    printf("\n1. inster at the left position\n");
    printf("2. inster at any position\n");
    printf("3. enter at the right posiiotn\n");
    printf("4. delet at the first position\n");
    printf("5. delet at any position\n");
    printf("6. delet from the end positon\n");
    printf("7. display the node\n");
    printf("8. EXIT\n");
    printf("enter your choice\n");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        /* code */
        printf("enter the data\n");
        scanf("%d",&da);
       insleft(da);
        break;
    case 2:
             printf("enter the data\n");
        scanf("%d",&da);
        printf("enter the data's position\n");
        scanf("%d",&a);
        insertany(da,a);
    break;

    case 3:
        printf("enter the data\n");
        scanf("%d",&da);
        
        insright(da);
    break;

    case 4:
            delfirst();
    break;
    case 5:
        printf("enter the data\n");
        scanf("%d",&da);
        printf("%d",deleany(da));
    break;
    case 6:
        delend();
        break;
    case 7:
        traverse();
    break;
    default:
    printf("please enter the correct choisce\n");
        break;
    }
}while(n!=8);
return 0;
}
