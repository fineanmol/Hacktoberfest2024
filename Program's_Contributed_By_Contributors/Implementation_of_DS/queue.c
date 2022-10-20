//Implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct queue{
    int size;
    int front;
    int end;
    int *arr;
};

int createQueue();
int push(struct queue*,int);
int pop(struct queue*);
int peek(struct queue*);
int isEmpty(struct queue*);
int isFull(struct queue*);

int main(){
    struct queue *q;
    q=(struct queue *)malloc(sizeof(struct queue));
    unsigned int n,choice;
    while(2){
        printf("1:Create\n2:Push\n3:Pop\n4:Peek\n5:isEmpty\n6:isFull\n");
        scanf("%u", &choice);
        switch(choice){
            case 1/*CreateQueue*/:{
                printf("\nEnter the number of elements:\t");
                scanf("%u", &n);
                free(q);
                q=createQueue(n);
                printf("\nQueue is created\n");
                break;
            }
            case 2/*push*/:{
                int element,check;
                printf("\nEnter element you want to push:\t");
                scanf("%d", &element);
                check=push(q,element);
                if(check==0){
                    printf("\nQueue is full\n");
                }
                else
                    printf("\nElement is pushed\n", q->end);
                break;
            }
            case 3/*pop*/:{
                int element,check;
                element=pop(q);
                if(element==INT_MAX)
                    printf("\nQueue is empty\n");
                else
                    printf("\nElement popped: %d\n", element);

                break;
            }
            case 4/*peek*/:{
                int element;
                element=peek(q);
                printf("Element %d\n", element);
                break;
            }
            case 5/*isEmpty*/:{
                int check;
                check=isEmpty(q);
                if(check==0){
                    printf("\nQueue is not empty\n");
                }
                else{
                    printf("\nQueue is empty\n");
                }
                break;
            }
            case 6/*isFull*/:{
                int check;
                check=isFull(q);
                if(check==0){
                    printf("\nQueue is not full\n");
                }
                else{
                    printf("\nQueue is full\n");
                }
                break;
            }
            default:{
                exit(0);
            }
        }
        if(q->front==q->end){
            q->front=-1;
            q->end=-1;
            printf("\nReset\n");
        }
    }
}

int createQueue(int n){
    struct queue *q;
    q=(struct queue *)malloc(sizeof(struct queue));
    q->size=n;
    q->front=-1;
    q->end=-1;
    q->arr=(int *)calloc(n, sizeof(int));
    return q;
}

int push(struct queue *q, int element){
    if(isFull(q)==1){
        return 0;
    }
    else{
        q->end=q->end+1;
        *(q->arr+q->end)=element;
        return 1;
    }
}

int pop(struct queue *q){
    int element;
    if(isEmpty(q)==1){
            return INT_MAX;
    }
    else{
        element=peek(q);
        q->front=q->front+1;
        return element;
    }
}

int peek(struct queue *q){
    int element;
    element=*(q->arr+q->front+1);
    return element;
}

int isEmpty(struct queue *q){
    if(q->end==-1){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->end==q->size-1){
        return 1;
    }
    return 0;

}
