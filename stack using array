#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int arr[MAX];
int top = -1;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (isFull())
    {
        printf("stack overflow\n");
        return;
    }
    top += 1;
    arr[top] = data;
}

int pop()
{
    int data;
    if (isEmpty())
    {
        printf("stack underflow");
        exit(1);
    }
    data = arr[top];
    top -= 1;
    return data;
}

int peek()
{
    if (isEmpty)
    {
        printf("stack underflow\n");
        exit(1);
    }
    return arr[top];
}

int print()
{
    if (isEmpty())
    {
        printf("stack underflow\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d", arr[i]);
            printf("\n");
        }
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print top\n");
        printf("4. print all\n");
        printf("5. quit\n");
        printf("\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("enter element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            data = pop();
            printf("deleted element is %d\n", data);
            break;

        case 3:
            printf("the top element in stack is %d\n", arr[top]);
            break;

        case 4:
            print();
            break;

        case 5:
            exit(1);

        default:
            printf("wrong choice\n");
        }
    }

    return 0;
}
