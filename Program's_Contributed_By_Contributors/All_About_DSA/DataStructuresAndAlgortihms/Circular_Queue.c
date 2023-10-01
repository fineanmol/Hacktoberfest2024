#include <stdio.h>

int enqueue(int a[],int rear,int front,int n){
    int element;
    if ((front==0)&&(rear == n-1)||(rear+1==front)){
        printf("FULL QUEUE !\n");
    }
    else{
        printf("Enter the element : ");
        scanf("%d",&element);
        if (rear==-1){
            rear = 0;
            a[rear] = element;
        }
        else if (rear==n-1){
            rear = 0;
            a[rear] = element;
        }
        else {
            rear = rear+1;
            a[rear] = element;
        }
    }
    return rear;
}
int dequeue(int a[],int front,int rear,int n){
    if ((front==-1)&&(rear==-1)){
        printf("EMPTY QUEUE !\n");
    }
    else if (front==rear){
        printf("%d is popped !\n",a[front]);
        front = -1;
    }
    else if (front==n-1){
        printf("%d is popped !\n",a[front]);
        front = 0;
    }
    else {
        printf("%d is popped !\n",a[front]);
        front = front+1;
    }
    return front;
}
int display(int a[],int front,int rear,int n){
    int i;
    if ((front==-1)&&(rear==-1)){
        printf("EMPTY QUEUE !\n");
    }
    else{
        if (front<=rear){
            for (i=0;i<front;i++){
                printf("_ ");
            }
            for (i=front;i<=rear;i++){
                printf("%d ",a[i]);
            }
        }
        else{
            for (i=0;i<=rear;i++){
                printf("%d ",a[i]);
            }
            for (i=rear+1;i<front;i++){
                printf("_ ");
            }
            for (i=front;i<=n-1;i++){
                printf("%d ",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
int displayFront(int a[],int front){
    if (front==-1){
        printf("EMPTY QUEUE !\n");
    }
    else{
        printf("%d\n",a[front]);
        return 0;
    }
}
int displayRear(int a[],int rear){
    if (rear==-1){
        printf("EMPTY QUEUE !\n");
    }
    else{
        printf("%d\n",a[rear]);
        return 0;
    }
}
int main(){
    int n;
    printf("Enter the length of the queue : ");
    scanf("%d",&n);
    if (n>0){
        printf("--------Circular Queue--------\n");
        printf("--------MENU--------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Display Front\n");
        printf("5. Display Rear\n");
        printf("6. Exit\n");

        int a[n];
        int front=-1,rear=-1,choice=0;
        while (choice!=6){
            printf("-----Enter Command-----");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                rear = enqueue(a,rear,front,n);
                if (front==-1){
                    front = 0;
                }
                break;
                case 2:
                front = dequeue(a,front,rear,n);
                if (front==-1){
                    rear = -1;
                }
                break;
                case 3:
                display(a,front,rear,n);
                break;
                case 4:
                displayFront(a,front);
                break;
                case 5:
                displayRear(a,rear);
                break;
                case 6:
                printf("--------Exiting--------\n");
                break;
                default:
                printf("Please enter a valid input !\n");
            }
        }
    }
    else{
        printf("Length cannot be negative !\n");
    }
    return 0;
}