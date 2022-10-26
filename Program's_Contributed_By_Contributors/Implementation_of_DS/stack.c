//Implementation of stack in c;
#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int createStack();
void push(struct stack *s, int,int *);
int pop(struct stack *, int *);
int peek(struct stack *);
int Noel(struct stack *);
int isEmpty(struct stack *);
int isFull(struct stack *);

int main()
{
    unsigned int n,choise,*check;
    check=(int*)calloc(1,sizeof(char));
    struct stack *stac;
    stac=createStack(n);
    while(1){
        printf("\nAny:-Exit\n1:-create\n2:-push\n3:-pop\n4:-peek\n5:-Noel\n6:-isEmpty\n7:-isFull\n");
        scanf("%d", &choise);
        switch(choise){
            case 1/*create*/:{
                printf("Enter the size of the stack:   ");
                free(stac);
                scanf("%u", &n);
                stac=createStack(n);
                printf("Stack of size %d is crated", n);
                break;
            }
            case 2/*push*/:{
                *check=0;
                printf("Enter the element you want to push:");
                int element;
                scanf("%d",&element);
                push(stac,element,check);
                if(*check==1){
                    printf("\n%d is pushed into stack", element);
                }
                else{
                    printf("\nStack is full");
                }
                break;
            }
            case 3/*pop*/:{
                *check=0;
                int element= pop(stac,check);
                if(*check==1){
                    printf("\nElement pop: %d", element);
                }
                else
                    printf("\nStack is empty");
                break;
            }
            case 4/*peek*/:{
                printf("%d is on top of the stack", peek(stac));
                break;
            }
            case 5/*Noel*/:{
                printf("Number of elements in stack:  %d", (stac->top+1));
                break;
            }
            case 6/*isEmpty*/:{
                if(isEmpty(stac)==1){
                    printf("Stack is empty");
                }
                else
                    printf("Stack is not empty");
                break;
            }
            case 7/*isFull*/:{
                if(isFull(stac)==1){
                    printf("Stack is full");
                }
                else
                    printf("Stack is not full");
                break;
            }
            default:{
                free(stac);
                free(check);
                return 0;
            }
        }
    }
}

int createStack(int n){
    struct stack *s;
    s=(struct stack*)malloc(sizeof(struct stack));
    s->size=n;
    s->arr=calloc(n,sizeof(int));
    s->top=-1;
    return s;
}

void push(struct stack *s, int element, int *check){
    if(isFull(s)==1){
        return 0;
    }
    else{
        s->top=(s->top+1);
        int *array=s->arr;
        *(array+s->top)=element;
        *check=1;
    }
}
;
int pop(struct stack *s,int *check){
    if(isEmpty(s)==1){
        return 0;
    }
    else{
        int element;
        element=*(s->arr+s->top);
        *(s->arr+s->top)=0;
        s->top=s->top-1;
        *check=1;
        return element;
    }
}
int peek(struct stack *s){
         int element;
         element=*(s->arr+s->top);
         return element;
}

int Noel(struct stack *s){
    return s->top;
}

int isFull(struct stack *s){
    if(s->top+1==s->size)
        return 1;
    else
        return 0;

}

int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else
        return 0;
}
