#include<stdio.h>
#include<mm_malloc.h>

// header for boolean data types true/false
#include <stdbool.h>

#define INT_MIN -9999



// defining a new user-defined
// data type STACK -> mySTACK
typedef struct STACK
{
    int *array;
    int max_size;
    int top;
}mySTACK;


// operation supported on STACK
mySTACK* init_stack(int max_size);
void push(mySTACK *s, int x);
void show_stack(mySTACK *s);
int pop(mySTACK *s);
int get_top(mySTACK *s);
void delete_stack(mySTACK *s);
bool check_stack_overflow(mySTACK *s);
bool check_stack_underflow(mySTACK *s);


int main()
{
    mySTACK *s1; 
    mySTACK *s2;
    int x;
    // Calling init_stack
    s1 = init_stack(10);
    //printf("\n Line 28 s1->top=%d",s1->top);

    // Adding elelments by calling push function
    push(s1, 4);
    push(s1, 1);
    push(s1, 19);
    show_stack(s1);
    x = pop(s1);
    printf("\nDeleted element is: %d\n", x);
    show_stack(s1);

    return 0;
}

mySTACK* init_stack(int max_size)
{ 
    mySTACK *s;
    //Allocate memory for stack
    s = malloc(sizeof(mySTACK));
    if(s==NULL)
        return NULL;
    // allocate memory for array
    s->array = malloc(sizeof(int) * max_size);
    // free the stack memory if array memory not allocated
    if(s->array ==NULL)
    {
        free(s);
        return NULL;
    }
    // Assigning the max_size and top
    s->max_size = max_size;
    s->top = -1;
    return s;
    
}

void push(mySTACK *s, int x)
{
    if(check_stack_overflow(s))
        printf("\t STACK overflow \n");
    else
    {
        s->top +=1;
        s->array[s->top] = x;
    }
}

void show_stack(mySTACK *s)
{
    int i;
    printf("\t STACK elements are: ");
    for(i=0; i<=s->top; i++)
        printf("%d ", s->array[i]);
    printf("\n");
}

int pop(mySTACK *s)
{
    int x;
    if(check_stack_underflow(s))
    {
        printf("\n STACK Underflow \n");
        return INT_MIN;
    }
    else
    {
        x = s->array[s->top];
        s->top -=1;
        return x;
    }
}

int get_top(mySTACK *s)
{
    int x;
    if(check_stack_underflow(s))
    {
        printf("\n STACK Underflow \n");
        return INT_MIN;

    }
    else
    {
        x = s->array[s->top];
        return x;
    }
}

bool check_stack_overflow(mySTACK *s)
{
    return (s->max_size -1 == s->top);
}

bool check_stack_underflow(mySTACK *s)
{
    return (s->top ==-1);
}

void delete_stack(mySTACK *s)
{
    if(s)
    {
        if(s->array)
            free(s->array);
        free(s);
    }
}
