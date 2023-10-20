
//Program in C for implementation of Queue Using Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};//to make a newnode
struct node *newnode, *temp;
	struct node *front=0; //front points first node
	struct node *rear=0;//rear should point last node

	
void enqueue(int x)
{
	//struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=0;
	
	//check whether the queue is empty or not
	
	if(front==0 && rear==0 )	//if empty
	{
		front=rear=newnode;	
	}	
	else		//add new node at begining
	{
		rear->next=newnode;
		rear=newnode;
	}
}

void dequeue()
{
    temp=front;
    if(front==0 && rear==0 )
    	printf("\nQueue is Empty!!");
   else
   {
    printf("\nElement Deleted : %d", temp->data);
    front = front->next;
     }
	
}

void display()
{
	temp=0;
	if(rear==0 && front==0)  //if the queue is empty 
	{
		printf("Queue is Empty!!");
	}
	else
	{
		temp=front;
		while(temp!=0)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
	 
int main()
{
	int ch,d,i;	
	do
	{	printf("\nMenu");
	printf("\n1.Insert the elements\n2.Delete an element\n3.Display the list\n4.Exit\n\nEnter your choice:");
	scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			{
			printf("Enter no of element to be entered:");
			scanf("%d",&d);
			int inp[d];
			printf("Enter %d elements: \n",d);
			for(i=0;i<d;i++)
			{
				scanf("%d",&inp[i]);
				enqueue(inp[i]);
			}
		
		break;
	}
		case 2:
			dequeue();
				break;
		case 3:
			display();
				break;
		case 4:
			printf("Exit Program!");	
				break;
		default:
			printf("Invalid Choice");
				break;
			
		}
	}while(ch!=4);
	return 0;
}
