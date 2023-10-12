#include<stdlib.h>
#include<stdio.h>
#define max 10
void push(int *p,int *n)
{
    if(*n==(max-1))
    {
        printf("Stack Is Full");
    }
    else
    {
        int a;
        printf("Enter The Element? \n");
        scanf("%d",&a);
        *n = *n + 1;
        *(p+(*n)) = a;
    }
}
void pop(int *p,int *n)
{
    if(*n==-1)
    {
        printf("Stack Is Empty");

    }
    else
    {
        printf("The Popped Element is : %d \n",(*(p+(*n))));
        *n = *n - 1;
    }
}
int main()
{
    int c;
    int a[max];
    int TOP=-1;
    do
    {
    printf("Enter 1 if you want to Push And 2 If You want to Pop element? \n");
    scanf("%d",&c);
    switch(c)
    {
    case 1 : push(a,&TOP);
             break;
    case 2: pop(a,&TOP);
             break;
    default : exit(0);
    }
    }while(1);
}