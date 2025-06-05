#include<stdio.h>
#include<stdlib.h>
#define size 100
struct deque{
    int arr[size];
    int front;
    int rear;
};

struct deque *create()
{
    struct deque *q=(struct deque*)malloc(sizeof(struct deque));
    q->front=-1;
    q->rear=-1;
    return q;
}
int isFull(struct deque *q)//Function used to check whether the queue is full or not
{
    if(q->front==q->rear+1%size||(q->front==0&&q->rear==size-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct deque *q)//Function to check whether the queue is empty or not
{
    if(q->front==-1 && q->rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void addfront(struct deque *q,int data)//Add element from the front of the queue
{
   // int data;
    if(isFull(q))
    {
        printf("Queue is Full \n");
        exit(1);
    }
    if(q->front==-1)
    {
        q->front=q->rear=0;
    }
    else if(q->front==0)
    {
        q->front=size-1;
    }
    else
    {
        q->front--;
    }
    
    q->arr[q->front]=data;
    printf("Added element in queue is %d \n",data);
}

void addend(struct deque *q,int data)//Add element from the rear end of the queue
{
   // int data;
    if(isFull(q))
    {
        printf("Queue is full \n");
        exit(1);
    }
    if(q->front==-1)
    {
        q->front=q->rear=0;
    }
    else if(q->rear==size-1)
    {
        q->rear=0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear]=data;
    printf("Element has been added at end %d \n",data);
}

int deletefront(struct deque *q)//Delete element from the front of the queue
{
    int data;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        exit(1);
    }
    q->arr[q->front]=data;
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else if(q->front==size-1)
    {
        q->front=0;
    }
    else
    {
        q->front++;
    }
    printf("Element has been removed from queue %d \n",data);
    return data;
    
}

int deleterear(struct deque *q)//Delete element from the rear end of the queue
{
    int data;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        exit(1);
    }
    q->arr[q->rear]=data;
    if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
    else if(q->rear==size-1)
    {
        q->rear=0;
    }
    else
    {
        q->rear--;
    }
    printf("Element deleted from rear end is %d \n",data);
    return data;
}


void display(struct deque *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        return;
    }
    int i=q->front;
    printf("Displaying contents \n");
    while(i!=(q->rear+1)%size)
    {
        printf("%d ",q->arr[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    struct deque *q=create();
    int choice,data;
    do{
        printf("Double ended Queue operations \n");
        printf("1. Add element at front\n");
        printf("2. Add element at rear\n");
        printf("3. Remove element from front\n");
        printf("4. Remove element from rear\n");
        printf("5. Display contents of deque\n");
        printf("6. Exit\n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter element to be inserted  front\n");
            scanf("%d",&data);
            addfront(q,data);
            break;
            case 2:
            printf("Enter element to be inserted rear \n");
            scanf("%d",&data);
            addend(q,data);
            break;
            case 3:
            data=deletefront(q);
            printf("Element deleted is from front %d \n",data);
            break;
            case 4:
            data=deleterear(q);
            printf("Element deleted from end %d \n",data);
            break;
            case 5:
            display(q);
            break;
            case 6:
            printf("Exitting program \n");
            exit(1);
            break;
            default:
            printf("invalid choice,enter again \n");
            
        }
    }while(choice!=6);
    
    return 0;
}




