#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*top;

void push()
{
    int item;
    printf("Enter the key value you want to insert\n");
    scanf("%d",&item);
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    if(top == NULL)
    {
        top = temp;
       temp->next = NULL;
       return;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}
void display()
{
    struct Node *temp ;
    temp = top;
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void pop()
{
    if(top == NULL)
    {
        printf("Underflow condition\n");
        return;
    }
    if(top->next == NULL)
    {
        top = NULL;
        return;
    }

    top = top->next;
}

int main()
{
    push();
    push();
    push();
    push();
    push();
    push();
    printf("\nElements in stack are \n");
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}