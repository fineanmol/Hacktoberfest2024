# polynomial_addition
#include<stdio.h>
#include<stdlib.h>
typedef struct poly{
    int coefficient,exp;
    struct poly *nxt;
}POLYNOMIAL;
void initialize(POLYNOMIAL **aah)
{
    *aah=NULL;
}
void insert(POLYNOMIAL **aap,int c,int e)
{
    POLYNOMIAL *cur,*prv,*t;
if(c==0) return;
for(cur=*aap, prv=NULL;cur && e<cur->exp; cur=cur->nxt)
prv=cur;
if(cur && e == cur->exp)
{
(cur->coefficient)+=c;
if (cur->coefficient == 0)
/* A node is created with Zero Coefficient (as for example 0x^2). */
{
if(prv)
prv->nxt=cur->nxt;
else
*aap=cur->nxt;
free(cur);
}
return;
}
t=(POLYNOMIAL *)malloc (sizeof(POLYNOMIAL));
t->coefficient=c;
t->exp=e;
t->nxt=cur;
if(prv)
prv->nxt=t;
else
*aap=t;
}
void input(POLYNOMIAL **aah)
{
int c,e;
char ans;
initialize(aah);
do
{
printf("\nEnter the coefficient: ");
scanf("%d", &c);
printf("Enter the exponent: ");
scanf("%d", &e);
insert(aah,c,e);
printf("\n Do you want to continue?(Y/N)\n");
scanf("%*c %c", &ans);
}while(ans!='N' && ans!='n');
}
void display(POLYNOMIAL *ap)
{
POLYNOMIAL *cur=ap;
printf("\n\t %d x^%d",cur->coefficient,cur->exp);
for(cur=ap->nxt; cur; cur=cur->nxt)
{
if(cur->coefficient==0)
continue;
else if(cur->coefficient>0)
printf("+%d x^%d", cur->coefficient, cur->exp);
else
printf("%d x^%d", cur->coefficient, cur->exp);
}
}
void poly_add(POLYNOMIAL *p1,POLYNOMIAL *p2,POLYNOMIAL **p)
{
    POLYNOMIAL *cur;
    initialize(p);
    for(;p1;p1=p1->nxt)
    {
       insert(p,p1->coefficient,p1->exp);
    }
    for(cur=p2;cur;cur=cur->nxt)
        {
            insert(p,cur->coefficient,cur->exp);
        }
}
void main()
{
    POLYNOMIAL *p,*p1,*p2;
    input(&p1);
    input(&p2);
    //poly_mult(p1,p2,&p);
   // display(p);
    poly_add(p1,p2,&p);
    display(p);
}
