#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int * arr;
   

};
int Empty (struct stack * ptr){
 if (ptr -> top ==-1)
 {
        return 1;
    }

    else{
        return 0;
    }
}

    int full(struct stack *ptr){
    if (ptr -> top = ptr->size-1)
    {
        return 1 ;
    }
    else{
        return 0 ;
    }
}
int main()
{
    // struct stack s ;
    // s.size = 90;
    // s.top = -1;
    // s.array = (int*) malloc(s.size*size of (int));
    // return 0;

    struct stack * s ;
    s -> size = 80;
    s -> top = -1;
    s ->arr = (int*) malloc(s->size* sizeof (int));
    if( Empty(s)){
        printf("The stack is empty");
    }
    else{
        printf("The stack is empty");
    }
    return 0;

}
