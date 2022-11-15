#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stack{
    int size;
    int top;
    char *arr;
};
char stackTop(struct stack* s)
{
    return s->arr[s->top];
}
int isEmpty(struct stack* s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isFull(struct stack* s)
{
    if(s->top==(s->size)-1)
        return 1;
    else 
        return 0;
}
void push(struct stack* s, char val)
{
    if(isFull(s))
        printf("Stack OverFlow! Cannot push elements\n");
    else
    {
        s->top++;
        s->arr[s->top]=val;
    }
}
char pop(struct stack* s)
{
    if(isEmpty(s))
        printf("Stack Underflow! Cannot Pop elements\n");
    else
    {
        char temp=s->arr[s->top];
        s->top--;
        return temp;
    }
}
int precedence(char c)
{
    if(c=='*' || c=='/')
        return 3;
    else if(c=='+' || c=='-')
        return 2;
    else 
        return 0;
}
int isOperator(char c)
{
    if(c=='*' || c=='/' || c=='+' || c=='-')
        return 1;
    else 
        return 0;
}
char *infixToPostfix(char *infix)
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(char*)malloc(s->size * sizeof(char));
    char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(precedence(infix[i])>precedence(stackTop(s)))
            {
                push(s,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(s);
                j++;
            }
        }
    }
    while(isEmpty(s))
    {
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char *infix="A+B*C+D+E";
    printf("Postfix is %s",infixToPostfix(infix));
    return 0;
}
