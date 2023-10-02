#include<stdio.h>
#define MAX 5


void qinsert (int q[],int *c,int *r)
{
    int item;
    if(*c==MAX)
        printf("queue overflow");
    else
    {
        printf("enter the item:");
        scanf("%d",&item);
        *c = *c +1;
        *r = (*r+1)%MAX;
        q[*r] = item;
    }
}

void qdelete (int q[],int *c,int *f)
{

    if(*c == 0)
        printf("queue underflow");
    else {
        *c = *c -1;
        printf("deleted : %d",q[*f]);
        *f = (*f+1)%MAX;
        }
}

void display(int q[],int c,int f)
{
    int i;
    if(c==0)
        printf("queue underflow");
    else {
        for(i=1;i<=c;i++)
        {
            printf("%d ",q[f]);
            f=(f+1)%MAX;
        }
    }
}

void main()
{
    int q[MAX],r=-1,c=0,f=0,ch;
    do
    {
        printf("\n 1.PUSH\n");
        printf(" 2.POP\n");
        printf(" 3.DISPLAY\n");
        printf(" 4.EXIT\n");
        scanf("%d",&ch);
        system("CLS");
        switch(ch)
        {
            case 1:
                    qinsert(q,&c,&r);
                    break;
            case 2:
                   qdelete(q,&c,&f);
                    break;
            case 3:
                    display(q,c,f);
                    break;
            case 4: exit(0);

        }
    }while(ch!=4);
}

