#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// As the stack introduced by the linked list is dynamic stack there is no need of size operations as size can be infinte

struct node
{
    int data;
    struct node *next;
} *head;

bool isempty(struct node *head)
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct node *push(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (isempty(head))
    {
        head = newnode;
    }

    {
        newnode->next = head;
    }

    return head;
}

struct node *pop(struct node *head)
{
    if (isempty(head))
    {
        printf("\nNo element left to pop as the stack is empty\n");
        return head;
    }
    else
    {
        printf("The popped element is %d", head->data);
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

int peek(struct node *head)
{

    if (isempty(head))
    {
        printf("The stack is empty leave it!!");
    }
    else
    {
        return head->data;
    }
}

void printStack(struct node *head)
{
    if (isempty(head))
    {
        printf("\nThe stack is empty\n");
        exit(0);
    }
    printf("\nStack: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int ch, size, value;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    while (1)
    {
        printf("\n1. Push an element for a preset size\n2.Push specific element into the stack\n3.Pop the element of the stack\n4.Displays the top element on the list\n5.Exit the program\n");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the size of the preset stack: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("\nEnter the value for %d position: ", i);
                scanf("%d", &value);
                head = push(head, value);
            }
            printf("\nThe updated list is:\n");
            printStack(head);
            break;
        case 2:
            printf("\nEnter the value: ");
            scanf("%d", &value);
            head = push(head, value);
            printf("\nThe updated list is:\n");
            printStack(head);
            break;
        case 3:
            head = pop(head);
            printf("\nThe updated list is:\n");
            printStack(head);
        case 4:
            printf("The top element of the stack is %d", peek(head));
            break;
        case 5:
            printf("\nExiting the program...\n");
            exit(0);
        default:
            break;
        }
    }

    return 0;
}

/*
Advantages of array implementation:
->Easy to implement.
->Memory is saved as pointers are not involved.

Disadvantages of array implementation:
->It is not dynamic i.e., it doesn’t grow and shrink depending on needs at runtime. [But in case of dynamic sized arrays like vector in C++, list in Python, ArrayList in Java, stacks can grow and shrink with array implementation as well].
->The total size of the stack must be defined beforehand.


Advantages of Linked List implementation:
->The linked list implementation of a stack can grow and shrink according to the needs at runtime.
->It is used in many virtual machines like JVM.

Disadvantages of Linked List implementation:
->Requires extra memory due to the involvement of pointers.
->Random accessing is not possible in stack.
*/