#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
void beginInsert()

{
    struct node *temp, *ptr;
    int value;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be stored in the begining of the list:\n");
    scanf("%d", &value);
    ptr->data = value;

    if (head == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        ptr->data = value;
        ptr->next = head;
        head = ptr;
        printf("Node Inserted\n");
    }
}
void endInsert()
{
    struct node *temp, *ptr;
    int value;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be stored at the end of the list:\n");
    scanf("%d", &value);
    ptr->data = value;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        printf("Node inserted\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        printf("Node inserted\n");
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("Data in list are:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
void randominsert()
{
    int i, loc, value;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the location after which you want to insert\n");
    scanf("%d", &loc);
    printf("Enter node value\n");
    scanf("%d", &value);
    ptr->data = value;
    temp = head;
    for (i = 0; i < loc - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Can't Insert'\n");
            return;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("Node inserted\n");
}
int main()
{
    //struct node *first;
    //first=(struct node*)malloc(sizeof(struct node));
    //first->data=9;
    //first->next=NULL;
    //head=first;
    endInsert();
    beginInsert();
    endInsert();
    display();
    // printf("h%d\n",head->data);
    randominsert();
    display();
    // printf("h%d\n",head->data);
    return 0;
}
