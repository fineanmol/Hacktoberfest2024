//Implement circular queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Cqueue{
    int size,front,rear;
    int *arr;
};

int createCqueue(int n);
int insert();
int Delete();
int Noel();
int isEmpty();
int isFull();

int main()
{
    struct Cqueue *q;
    q=(struct Cqueue *)malloc(sizeof(struct Cqueue));
    int choice;
    while(1){
        printf("\n1: Create\n2: Insert\n3: Delete\n4: Noel\n5: isEmpty\n6: isFull\nAny: Stop\n");
        scanf("%u", &choice);
        switch(choice){
            case 1/*Create*/:{
                int n;
                printf("\nEnter number of element you want in the queue:\t");
                scanf("%d", &n);
                n++;
                free(q);
                q=createCqueue(n);
                printf("\nCircular Queue is created:\n");
                break;
            }
            case 2/*Insert*/:{
                int element,check;
                printf("\nEnter element you want to enter\n");
                scanf("%d",&element);
                check=insert(q,element);
                if(check==1){
                    printf("\nElement is inserted\n");
                }
                else{
                    printf("\nCircular queue is full\n");
                }
                break;
            }
            case 3/*Delete*/:{
                int element;
                element=Delete(q);
                if(element==INT_MAX){
                    printf("\nQueue is Empty\n");
                }
                else{
                    printf("\nElement deleted:\t%d\n", element);
                }
                break;
            }

            case 4/*Noel*/:{
                printf("\nNumber of elements:\t%d", Noel(q));
                break;
            }
            case 5/*isEmpty*/:{
                if(isEmpty(q)==1)
                    printf("\nQueue is empty\n");
                else
                    printf("\nQueue is full\n");
                break;
            }
            case 6/*isFull*/:{
                if(isFull(q)==1)
                    printf("\nQueue is full\n");
                else
                    printf("\nQueue is not full\n");
                break;
            }
            default/*Stop*/:{}
        }
    }
}

int createCqueue(int n){
    struct Cqueue *q;
    q=(struct Cqueue *)malloc(sizeof(struct Cqueue));
    q->front=0;
    q->rear=0;
    q->size=n;
    q->arr=(int *)calloc(n, sizeof(int));
}
int insert(struct Cqueue *q, int element){
    if(isFull(q)==1){
        return 0;
    }
    else{
        q->rear=((q->rear+1)%q->size);
        *(q->arr+q->rear)=element;
        return 1;
    }
}

int Delete(struct Cqueue *q){
    if(isEmpty(q)==1){
        return INT_MAX;
    }
    int element;
    q->front=((q->front+1)%(q->size));
    element=*(q->arr+q->front);
    return element;
}

int Noel(struct Cqueue *q){
    int noel=0,f,r,s;
    f=q->front;
    r=q->rear;
    s=q->size;
    while(f!=r){
        noel++;
        f=(f+1)%s;
    }
    return noel;
}

int isEmpty(struct Cqueue *q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}

int isFull(struct Cqueue *q){
    int s=0;
    if(q->rear==0 && q->front!=0){
        s=q->size;
    }
    if((q->rear+1)%q->size == q->front){
        return 1;
    }
    return 0;
}
