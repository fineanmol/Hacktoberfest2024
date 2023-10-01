#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head;

struct node *createdcll(struct node *head, int n)
{
    if (n < 1)
    {
        printf("Invalid value for n\n");
        return NULL;
    }
    struct node *temp, *newnode;
    head = NULL;
    for (int i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("\nAddress not allocated");
            exit(0);
        }
        printf("Enter the element %d:\n", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp; // set prev of new node to temp
            temp = newnode;
        }
    }
    temp->next = head; // connect last node to head
    head->prev = temp; // connect head to last node
    return head;
}

void printList(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\nThe list is empty");
        return;
    }
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

struct node *insertAtBegin(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    newnode->prev = NULL;
    struct node *temp = head;
    while (head == NULL)
    {
        head = newnode;
        head->next = head;
        return head;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    head = newnode;
    return head;
}

struct node *insertAtEnd(struct node *head, int item)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    struct node *temp = head;
    while (head == NULL)
    {
        head = newnode;
        head->next = head;
        return head;
    }
    newnode->prev = NULL;
    newnode->next = NULL;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = head;
    return head;
}
struct node *insertAfterSpecific(struct node *head, int value, int finder)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory allocation failed");
        return head;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) // if list is empty
    {
        head = newnode;
        newnode->next = head;
        return head;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == finder)
        {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            temp->next->prev = newnode;
            return head;
        }
        temp = temp->next;
    }
    if (temp->data == finder) // if last node matches
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("\nElement not found");
    }
    return head;
}

struct node *deleteAtBegin(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty.");
        return head;
    }
    struct node *temp = head;
    struct node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp->next;
    head = head->next;
    free(temp);
    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    struct node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = head->next;
    return head;
}
struct node *deleteEntireList(struct node *head)
{
    struct node *temp = head;
    struct node *next;
    while (temp->next != head)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(temp);
    head = NULL;
    return head;
}

int getNthNode(struct node *head, int n)
{
    if (head == NULL) // if list is empty
    {
        printf("\nList is empty");
        exit(0);
    }

    struct node *temp = head;
    int count = 1;
    do // use do-while loop to traverse the circular list at least once
    {
        if (count == n)
        {
            return temp->data;
        }
        count++;
        temp = temp->next;
    } while (temp != head); // continue until we reach the first node again

    printf("\nNode not found");
}

int getlength(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count = count + 1;
    return count;
}

struct node *deleteAfterspecific(struct node *head, int finder)
{
    if (head == NULL) // if list is empty
    {
        printf("\nList is empty");
        exit(0);
    }
    struct node *temp = head;
    struct node *l = head->next;
    while (l->next != head && l->data != finder)
    {
        temp = l;
        l = l->next;
    }
    temp->next = l->next;
    l->next->prev = temp;
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextnode;
    do
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    } while (current != head);
    head->next = prev;
    head = prev;
    return head;
}
int main()
{
    int n, choice, item, finder;
    printf("Enter the no. of elements: \n");
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = createdcll(head, n);
    printf("\nThe elements are:");
    printList(head);

    while (1)
    {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert after a specific node\n4.Delete at Beginning\n5.Delete at End\n6.Delete entire list\n7.Get Nth Element\n8.Get Length of the list\n9.Delete at specific node\n10.Reverse the list\n11.Exit the program\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert at the beginning: ");
            scanf("%d", &item);
            head = insertAtBegin(head, item);
            printf("The updated list is:\n");
            printList(head);
            break;
        case 2:
            printf("Enter the element to insert at the end: ");
            scanf("%d", &item);
            head = insertAtEnd(head, item);
            printf("The updated list is:\n");
            printList(head);
            break;
        case 3:
            printf("Enter the element to insert after the specific node: ");
            scanf("%d", &item);
            printf("Enter the data of the finding node: ");
            scanf("%d", &finder);
            head = insertAfterSpecific(head, item, finder);
            printf("The updated list is:\n");
            printList(head);
            break;
        case 4:
            head = deleteAtBegin(head);
            printf("The updated list is:\n");
            printList(head);
            break;
        case 5:
            head = deleteAtEnd(head);
            printf("The updated list:\n");
            printList(head);
            break;
        case 6:
            head = deleteEntireList(head);
            printf("The updated list:\n");
            printList(head);
            break;
        case 7:
            printf("\nEnter the nth index: ");
            scanf("%d", &n);
            printf("%d\n", getNthNode(head, n));
            break;
        case 8:
            printf("Length of the list is: %d\n", getlength(head));
            break;
        case 9:
            printf("\nEnter the finder element: ");
            scanf("%d", &finder);
            head = deleteAfterspecific(head, finder);
            printf("The updated list:\n");
            printList(head);
            break;
        case 10:
            head = reverse(head);
            printf("The updated list:\n");
            printList(head);
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("\nIncorrect value\n\a");
            break;
        }
    }
    return 0;
}