#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int is_empty(int front)
{
    if(front == -1)
    return 1;
    else
    return 0;
 
}
int is_full(int rear)
{
    if(rear == MAX-1)
    return 1;
    else
    return 0;
}
int enqueue(int *p,int front,int rear)
{
    if(is_full(rear))
    {
        printf("Queue Is Full!\n");
        return rear;
    }
    else
    {
        printf("Enter The Element?\n ");
        scanf("%d",(p+(++rear)));
        return rear;
    }
}
int dequeue(int *p,int front,int rear)
{
    if(is_empty(front))
    {
        printf("Queue Is Empty! \n");
        return front;
    }
    else
    {
        printf("Deleted Element is : %d \n",*(p+(front++)));
        return front;
    }
}
void peek(int *p,int front)
{
    if(is_empty(front))
    printf("Queue is Empty! \n");
    else
    printf("Front Element : %d \n",*(p+front));
}
void rear_view(int *p,int rear)
{
    if(is_empty(rear))
    printf("Queue is Empty! \n");
    else
    printf("Rear Element : %d \n",*(p+rear));
}
void display(int *p,int front,int rear)
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d \n",*(p+i));
    }
}
int main()
{
    int front = -1,rear = -1,a;
    int queue[MAX];
    do
    {
        printf("Enter The Choice?\n1. For Insertion \n2. For Deletion \n3. Peek\n4. Rear View \n5. Display \n6. Check For Empty \n7. Check For Full \n");
        scanf("%d",&a);
        switch(a)
        {
            case 1 : 
            {
                rear = enqueue(queue,front,rear);
                if(rear>-1&&front==-1)
                front++;
                break;
            }
            case 2:
            {
                front = dequeue(queue,front,rear);
                if(front>rear)
                {
                    front = rear = -1;
                }
                break;
            }
            case 3 :
            {
                peek(queue,front);
                break;
            }
            case 4:
            {
                rear_view(queue,rear);
                break;
            }
            case 5:
            {
                display(queue,front,rear);
                break;
            }
            case 6:
            {
                if(is_empty(front))
                printf("Queue Is Empty! \n");
                else
                printf("Queue Is Not Empty! \n");
                break;

            }
            case 7:
            {
                if(is_full(rear))
                printf("Queue Is Full! \n");
                else
                printf("Queue Is Not Full! \n");
                break;
            }
            default : exit(0);
        }
    } while (1);
    
}