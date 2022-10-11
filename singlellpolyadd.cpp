#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

// addition code for polynomial
struct node {
    int exponent;
    int coef;
    struct node * next;

};
void join(struct node **s1,struct node *s2)
{
    struct node * q;
    if(*s1==NULL)
    {
        *s1=s2;

    }
    else{
        for (q=(*s1);q->next!=NULL;q=q->next);
        q->next=s2;
    }
}
void display(struct node *start)
{
    struct node * q;
    
    for (q=start;q!=NULL;q=q->next)
    {
        
        printf("coefficient : %d exponent : %d\n",q->coef,q->exponent);
    }
    
}

void insert_end(struct node ** start,struct node **last,int val1,int val2)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->coef=val1;
    temp->exponent=val2;
    temp->next=NULL;
    if(*start==NULL)
    {
        *start=temp;
        *last=temp;

    }
    else{
        (*last)->next=temp;
        *last=(*last)->next;
    }
}
int main()
{
    struct node *start1,*start2,*p1,*p2,*prev,*last1=NULL,*last2=NULL;
    start1=start2=p1=p2=prev=NULL;
    printf("enter the no of terms for ll1:");
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int coef,exponent;
        scanf("%d%d",&coef,&exponent);
        insert_end(&start1,&last1,coef,exponent);
    }
    int n1;
    printf("enter the no of terms for ll2:");
    scanf("%d",&n1);
    for (int i = 0; i < n1; i++)
    {
        int coef,exponent;
        scanf("%d%d",&coef,&exponent);
        insert_end(&start2,&last2,coef,exponent);

    }
    
    join(&start1,start2);
    
    for(p1=start1;p1!=NULL;p1=p1->next)
    {
        prev=p1;
        for (p2=p1->next;p2!=NULL;)
        {
            if(p1->exponent!=p2->exponent)
            {
                prev=p2;
                p2=p2->next;
            }
            else{
                p1->coef=p2->coef+p1->coef;
                prev->next=p2->next;
                free(p2);
                p2=prev->next;
            }
        }
        
    }
    display(start1);
    
 
    
}