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
	q.rear=0; 
	q.front=-1;
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
	if(q->front==-1)
	{
		q->front=0;
		q->rear=0;
	}
	else
		q->rear=(q->rear+1)%MAXQUE;
	q->item[q->rear]=x;
}

int IsFull(queue *q)
{
	if(q->front==(q->rear+1)%MAXQUE)
		return 1;
	else
		return 0;
}

int Delete(queue* q)
{
	int x;
	if(IsEmpty(q))
		return -1;
	x=q->item[q->front];
	if(q->front==q->rear){
		q->front=-1;
		q->rear=-1;
	}
	else
		q->front=(q->front+1)%MAXQUE;
	return x;
}

int IsEmpty(queue *q)
{
	if(q->front==-1)
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
	if(q->front<=q->rear)
	{
		for(i=q->front;i<=q->rear;i++)
			printf("\n%d",q->item[i]);
	}
	else
	{
		for(i=q->front;i<=MAXQUE-1;i++)
			printf("\n%d",q->item[i]);
		for(i=0;i<=q->rear;i++)
			printf("\n%d",q->item[i]);
	}
}
