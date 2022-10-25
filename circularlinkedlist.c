#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
}*num,*head,*tail,*temp;
int creation()
{
    int n,i,value;
    printf("\n\nEnter Number of Elements : ");
    scanf("%d",&n);
    printf("Enter the Elements : ");
    for(i=1;i<=n;i++)
    {
        num = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
        num->data = value;
        num->next = NULL;
        if(head == NULL)
        {
            head = num;
            tail = num;
        }
        else
        {
            tail->next = num;
            tail = num;
            num->next = head;
        }
    }
    printf("\n***The List has Been Created Successfully***");
    return 0;
}
int traversal()
{
    int counter=0;
    temp = head;
    printf("\n The Elements in the List are : \n\t\t");
    while(temp->next != head)
    {
        printf(" %d ->",temp->data);
        counter++;
        temp = temp->next;
    }
    printf(" %d",temp->data);
    printf("\n\t***There are %d Number of Nodes Present in the List***",counter+1);
    return 0;
}
int insertbeg()
{
    int value;
    printf("\nEnter the Element to be Inserted at the Beginning : ");
    num = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&value);
    num->data = value;
    if(head == NULL)
    {
        head = num;
        tail = num;
    }
    else
    {
        num->next = head;
        tail->next = num;
        head = num;
    }
    printf("\n***The Element %d has been Inserted at the Beginning Successfully***",value);
    return 0;
}
int insertend()
{
    int value;
    printf("\nEnter the Element to be Inserted at the Ending : ");
    num = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&value);
    num->data = value;
    if(head == NULL)
    {
        head = num;
        tail = num;
    }
    else
    {
        tail->next = num;
        num->next = head;
        tail = num;
    }
    printf("\n***The Element %d has been Inserted at the Ending Successfully***",value);
    return 0;
}
int insertpos()
{
    int value,p,i;
    printf("\nEnter the Position of Element to be Inserted : ");
    scanf("%d",&p);
    printf("Enter the Element to be Inserted : ");
    num = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&value);
    temp = head;
    for(i=0;i<p-1;i++)
    {
        temp = temp->next;
        num->data = value;
    }
    num->next = temp->next;
    temp->next = num;
    printf("\n***The Element %d has been Inserted at %d Position of the List Successfully***",value,p);
    return 0;
}
int delbeg()
{
    int value;
    temp = head;
    value = temp->data;
    head = head->next;
    tail->next = head;
    temp->next = NULL;
    free(temp);
    printf("\n***The Element %d  which is at the Beginning of the List has been Deleted Successfully***",value);
    return 0;
}
int delend()
{
    int value;
    temp = head;
    while(temp->next != tail)
    {
        temp = temp->next;
    }
    value = temp->next->data;
    temp->next = head;
    tail->next = NULL;
    tail = temp;
    printf("\n***The Element %d Which is at the End of the List has been Deleted Successfully***",value);
    return 0;
}
int delpos()
{
    int p,i;
    printf("\n\nEnter the Position of the Element to be Deleted : ");
    scanf("%d",&p);
    temp = head;
    for(i=0;i<p-1;i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    printf("\n***The Element at %d Position of the List has been Deleted Successfully***",p);
    return 0;
}
int reverse()
{
    struct node *current,*prev,*rnext;
    current = head;
    temp = head;
    prev = NULL;
    while(current != NULL)
    {
        rnext = current->next;
        current->next = prev;
        prev = current;
        current = rnext;
    }
    head = prev;
    tail = temp;
    printf("\n\n\tAfter Reversing the Elements in the List : ");
    temp = head;
    while(temp->next != head)
    {
        printf(" %d ->",temp->data);
        temp = temp->next;
    }
    printf(" %d",temp->data);
    return 0;
}
int search()
{
    int s,count=0,flag=0;
    printf("\n\n\t\tEnter the Search Element : ");
    scanf("%d",&s);
    temp = head;
    if(temp == NULL)
    {
        printf("\n\t\tThe List is Empty");
    }
    while(temp->next != head)
    {
        if(temp->data == s)
        {
            flag = 1;
            break;
        }
        else
        {
            count++;
            temp = temp->next;
        }
    }
    if(flag == 1)
        {printf("\n\tThe %d Element is Present at %d Position in the List",s,count+1);}
    else
       {
           printf("\n\tThe %d Element is not Present in the List",s);
       }
    return 0;
}
int sort()
{
    struct node *i,*j,*start;
    int temp;
    start = head;
    for(i=start;i->next != head;i=i->next)
    {
        for(j=i->next; j != head;j=j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("\n\t\t*** The Elements in the List has been Sorted Successfully *** ");
    return 0;
}
int choice()
{
	int c;
	printf("\n\nEnter Your Choice \n\t(1).Creation \n\t(2).Traversal \n\t(3).Insertion at the Beginning \n\t(4).Insertion at the Ending \n\t(5).Insertion at the Specific Position \n\t(6).Deletion at the Beginning \n\t(7).Deletion at the Ending \n\t(8).Deletion at the Specific Position \n\t(9).Reversing the List \n\t(10).Searching an Element \n\t(11).Sorting the Elements in the List \n\t(12).Exit : ");
	scanf("%d",&c);
	switch (c)
	{
		case 1:
		    creation();
		    choice();
		case 2:
		    traversal();
		    choice();
		case 3:
			insertbeg();
			choice();
		case 4:
		    insertend();
		    choice();
		case 5:
			insertpos();
			choice();
        case 6:
            delbeg();
            choice();
        case 7:
            delend();
            choice();
        case 8:
            delpos();
            choice();
        case 9:
            reverse();
            choice();
        case 10:
            search();
            choice();
        case 11:
            sort();
            choice();
        case 12:
            exit(0);
		default:
		    printf("Wrong Choice Entered !! Please Check your Choice");
		    choice();
	}
	return 0;
}
int main()
{
	int n;
	printf("\t\t\tLINKED LIST\n\t\tPress 1 to Continue : ");
	scanf("%d",&n);
	if(n == 1)
	{
	choice();
	}
	else
	  {
	  printf("\nYou Have Not Created any List");
	  }
	  return 0;
	getch();
}
