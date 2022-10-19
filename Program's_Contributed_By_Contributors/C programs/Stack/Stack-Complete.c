#include<stdio.h>
#define n 5
int stack_arr[n],top=-1;
int topno();
int isempty();
int isfull();
void traverse();
void push(int data);
int pop();
void main()
{
    int ch,sitem;
    while(1)
    {
        printf("\nStack Operation:\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.TOP\n");
        printf("4.Traverse\n");
        printf("5.isEmpty\n");
        printf("6.isFull\n");
        printf("7.Exit\n");
    
    printf("Enter your choice:\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("Enter stack item:\n");
        scanf("%d",&sitem);
        push(sitem);
        break;
    case 2:
        sitem=pop();
        if(sitem==0)
        {
            printf("Underflow");
        }
        else 
        printf("Last Poped item %d",sitem);
        break;
    case 3:
        topno();
        break;
    case 4:
        traverse();
        break;
    case 7:
        exit(0);
    case 5:
        if(isempty())
        printf("Stack is Empty");
        else
        printf("Not Empty");
        break;
    case 6:
        if(isfull())
        printf("Stack is full");
        else 
        printf("stack not full");
        break;
    default:
        printf("Incorrect choice");
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
int isempty()
{
    if(top==-1)
    return 1;
    else 
    return 0;
}
int isfull()
{
    if(top==(n-1))
    return 1;
    else
    return 0;
}
void traverse()
{
    if(!isempty())
    {
        int i;
        for(i=0;i<=top;i++)
        printf("%d\n",stack_arr[i]);
    }
    else
    printf("Stack is empty");
}
void push(int data)
{
    if(!isfull())
    {
        top+=1;
        stack_arr[top]=data;
    }
    else
    printf('Stack is full');
}
int pop()
{
    int value;
    if(!isempty())
    {
        value=stack_arr[top];
        top-=1;
        return value;
    }
    else
    printf("Underflow");
}
int topno()
{
    return stack_arr[top];
}