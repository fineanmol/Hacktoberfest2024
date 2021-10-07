// Program for parenthesis matching that is the string is balance or not

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <limits.h>

struct stack{
    int size;
    int top;
    char *arr;
};

bool isEmpty(struct stack *stack){
    if(stack->top == -1){
        return true;
    }
    return false;
}

bool isFull(struct stack *stack){
    if(stack->top == stack->size - 1){
        return true;
    }
    return false;
}

void push(struct stack *stack, char element){
    if(isFull(stack)){
        printf("Stack Overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = element;
}

char pop(struct stack * stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        return -1;
    }
    char val = stack->arr[stack->top];
    stack->top--;
    return val;
}

bool isMatch(char a, char b) {
    if(a=='(' && b==')')
        return true;
    if(a=='[' && b==']')
        return true;
    if(a=='{' && b=='}')
        return true;
    return false;
}

char * parenthesis_match(char * exp){
    struct stack *st = (struct stack * ) malloc(sizeof(struct stack));
    st->top = -1;
    st->size = sizeof(exp);
    st->arr = (char *) malloc(sizeof(st->size * sizeof(char)));
    char popped;
    
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(st, exp[i]);
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(isEmpty(st))
                return "Unbalanced";
            popped = pop(st);
            if(!isMatch(popped, exp[i]))
                return "Unbalanced";
        }
    }

    if(isEmpty(st))
        return "Balanced";
    return "Unbalanced";
}

int main()
{   
    char exp;
    scanf("%s", &exp);
    char * res = parenthesis_match(&exp);
    printf("%s", res);
    return 0;
}
