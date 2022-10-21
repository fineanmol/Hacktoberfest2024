#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*start=NULL,*p,*t;

void display()
{	
	printf("\n");
    if(start==NULL)
        printf("List is empty!!");
    else
    {
        p=start;
        printf("The linked list is:\n");
        while(p!=NULL)
        {
            printf("%d->",p->data);
            p=p->next;
        }
    }
	printf("\n\n");
}

void insBeg()
{
	int num;
	t = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element: ");
	scanf("%d",&num);
	t->data=num;
	if (start == NULL)
	{
		t->next = NULL;
		t->prev = NULL;
		start = t;
	}
	else
	{
		t->next = start;
		t->prev = NULL;
		start=t;
	}
	printf("element inserted at begining!\n");
	display();
}
int insMid()
{
	int pos,i,num;
	if(start == NULL)
	{
		printf("The list is empty\n");
		return 0;	
	}
	t = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element: ");
	scanf("%d",&num);
	printf("\nEnter the position!");
	scanf("%d",&pos);
	t->data = num;
	p = start;
	for(i=0;i<pos-1;i++)
	{
		if(p->next ==NULL)
		{
			printf("\nOVERFLOW!");
			return 0;
		}
		p=p->next;
	}
	t->next = p->next;
	t->prev = p;
	p->next = t;
	if(t->next!= NULL)
		t->next->prev = t;
	printf("Element inserted at the middle\n");
}
void insEnd()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
   	printf("Enter data:");
   	scanf("%d",&num);
   	t->data=num;
   	t->next=NULL;
   	if(start==NULL)  
   	{
        start=t;
		t->prev = NULL;
    }
    else
   {
     	p=start;
     	while(q->next!=NULL)
        	p=p->next;
       	p->next=t;
		t->prev = p;
    }
	printf("element inserted at the end!\n");
}

int del()
{
	if (start == NULL)
	{
		printf("\nThe list is EMPTY! [UNDDERFLOW!]\n");
		return 0;
	}
	else
	{
		p = start;
		while(p->next->next !=NULL)
			p = p->next;
		t = p->next;
		p->prev = t;
		p->next = NULL;
		printf("Deleted element is: %d\n",t->data);
	}
}

void main()
{
	int ch='y', action, pos;
	while(y=='y')
	{
		printf("\t\t\tMAIN MENU\n\n");
		printf("1. Insert\n2. Delete\n3. Print\n\nenter the option number!\n\t");
		scanf("%d",&action);
		if(action ==1)
		{
			printf("From where would you like to insert?\n");
			printf("1. Begining\n2. Middle\n3. End\n");
			scanf("%d",&pos);
			if(pos==1)
				insBeg();
			else if(pos==2)
				insMid();
			else if(pos==3)
				insEnd();
			else 
				printf("Invalid choice");
		}
		else if(action == 2)
			del();
		else if(action == 3)
			display();
		else 
				printf("Invalid choice");
		printf("Do you want to continue? (y/n)");
		scanf("%c",&ch);
	}
}