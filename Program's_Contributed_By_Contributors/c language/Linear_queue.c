#include<stdio.h>
#define MAXQUE 5
typedef struct
{
	int rear;
	int front;
	int item[MAXQUE];
}queue;

int IsEmpty(queue*);
int IsFull(queue*);
void Insert(queue*,int);
int Delete(queue*);
int Peep(queue*);
void Display(queue*);

int main()
{
	queue q;
	q.rear=-1;
	q.front=0;
	int x,ch,ele;
	do
	{
		printf("\nEnter 1 for Insert");
		printf("\nEnter 2 for Delete");
		printf("\nEnter 3 for Display");
		printf("\nEnter 4 for Peep");
		printf("\nEnter 5 for Quit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the element to push\t");
				scanf("%d",&x);
				Insert(&q,x);
				break;
			
			case 2:
				ele=Delete(&q);
				if(ele==-1)
					printf("\n Queue is Empty");
				else
					printf("\n The element deleted is=%d",ele);
				break;
			
			case 3:
				Display(&q);
				break;
				
			case 4:
				Peep(&q);
				break;
				
			case 5:break;
			deafult: printf("WORNG INPUT, TRY AGAIN");			
		}
	}while(ch!=5);
	return 0;
}

void Insert(queue* q,int x)
{
	if(IsFull(q))
	{
		printf("Queue is Full");
		return;
	}
	else
	{
		q->rear++;
		q->item[q->rear]=x;
	}
}

int IsFull(queue *q)
{
	if(q->rear==MAXQUE-1)
		return 1;
	else
		return 0;
}

int Delete(queue* q)
{
	int x;
	if(IsEmpty(q))
		return -1;
	else
	{
		x=q->item[q->front];
		q->front++;
		return x;
	}
}

int IsEmpty(queue *q)
{
	if(q->rear< q->front)
		return 1;
	else
		return 0;
}

int Peep(queue* q)
{
	int x;
	if(IsEmpty(q))
	{
		printf("\nQueue is Overflow");
		return -1;
	}
	else
	printf("%d",q->item[q->front]);
}
void Display(queue *q)
{
	int i;
	if(IsEmpty(q))
	{
		printf("The Queue is Empty");
		return;
	}
	else
	{
		for(i=q->front;i<=q->rear;i++)
			printf("\n%d",q->item[i]);
	}
}
