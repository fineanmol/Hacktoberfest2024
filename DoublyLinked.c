#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL;

void insert(int n)
{
	struct node *ptr,*p;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=n;
	ptr->next=NULL;
	ptr->prev=NULL;
	if(start==NULL)
		start=ptr;
	else
	{
		for(p=start;p->next!=NULL;p=p->next);
	  	p->next=ptr;	
	  	ptr->prev=p;
	}
}

void display()
{
	struct node *ptr=start;
	printf("\n [");
	if(ptr==NULL)
		printf("List is empty! ]");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d ", ptr->data);
			ptr=ptr->next;
		}
		printf("] \n");
	}
}
int main()
{
	int n,ch;
	while(1)
	{
		printf("Enter \n 1.Insert! \n 2.Display! \n 3.Exit! \n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter the element you want to insert: ");
					scanf("%d", &n);
					insert(n);
					break;
			case 2:	display();
					break;
			case 3:	exit(0);
			default: printf("Invalid Choice!Try Again!");
		}
	}
}