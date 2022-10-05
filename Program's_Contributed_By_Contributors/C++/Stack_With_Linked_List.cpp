// Author : Neelanjan Mukherji

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack * );
int peek(struct stack *);

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr -> data = val;
    if(top == NULL)
    {
        ptr -> next = NULL;
        top = ptr;
    }
    else
    {
        ptr -> next = top;
        top = ptr;
    }
    return top;
}
struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if(top == NULL)
    {
        printf("STACK is Empty \n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d \n",ptr -> data);
            ptr = ptr -> next;
        }
    }
    return top;
}
struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("STACK UNDERFLOW!");
    }
    else
    {
        top = top -> next;
        printf("TOP Value : %d Deleted\n", ptr -> data);
        free(ptr);
    }
    return top;
}
int peek(struct stack *top)
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        return top -> data;
    }
    
}





int main()
{
    int val, option;
    do
    {
        printf("******** MAIN MENU ******** \n");
        printf("1. PUSH \n");
        printf("2. POP \n");
        printf("3. PEEK \n");
        printf("4. DISPLAY \n");
        printf("4. EXIT \n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter The Number to pushed : \n");
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            val = peek(top);
            if (val != -1)
            {
                printf("Value at the top of stack : %d \n", val);
            }
            else
            {
                top = display(top);
                break;
            }
        case 4:
            top = display(top);
        }
    } while (option != 5);
    return 0;
}