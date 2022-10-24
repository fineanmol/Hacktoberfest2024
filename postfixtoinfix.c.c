#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX 1001 // max limit is 1000 chars

char infix[MAX], postfix[MAX];

// LL Stack
struct node
{
    char expression[MAX];
    struct node *link;
};

struct node *top = NULL;

// push function
void push_char(char c)
{
    char ch[2];
    ch[0]=c;
    ch[1]='\0';
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory could not be allocated\n");
        exit(1);
    }
    strncpy(tmp->expression, ch, sizeof(tmp->expression));
    tmp->expression[strlen(ch)] = '\0';
    tmp->link = top;
    top = tmp;
}

void push_str(char *c)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory could not be allocated\n");
        exit(1);
    }
    strncpy(tmp->expression, c, sizeof(tmp->expression));
    tmp->expression[strlen(c)] = '\0';
    tmp->link = top;
    top = tmp;
}

// pop function
char first[MAX], second[MAX];
void pop()
{
    if (top == NULL || top->link == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    strncpy(first, top->expression, sizeof(first));
    first[strlen(top->expression)] = '\0';
    top = top->link;
    strncpy(second, top->expression, sizeof(second));
    second[strlen(top->expression)] = '\0';
    top = top->link;
}

// makestring function
char newstring[MAX];
void makestring(char op)
{
    char operator[2];
    operator[0]=op;
    operator[1]='\0';
    char open[] = "(";
    char close[] = ")";
    strncpy(newstring, open, sizeof(newstring));
    newstring[strlen(open)] = '\0';
    strncat(newstring, second, sizeof(newstring) - strlen(newstring) - 1);
    strncat(newstring, operator, sizeof(newstring) - strlen(newstring) - 1);
    strncat(newstring, first, sizeof(newstring) - strlen(newstring) - 1);
    strncat(newstring, close, sizeof(newstring) - strlen(newstring) - 1);
}

int isOperator(char p)
{
    if (p == '+' || p == '-' || p == '*' || p == '/' || p == '^' || p == '%')
        return 1;
    return 0;
}

int isOperand(char p)
{
    if (p == '+' || p == '-' || p == '*' || p == '/' || p == '^' || p == '%')
        return 0;
    return 1;
}

void toInfix(char p[])
{
    if (!strlen(p))
    {
        printf("The string is Empty!\n");
        exit(1);
    }
    int len = strlen(p);
    for (int i = 0; i < len; i++)
    {
        if (isOperand(p[i]) == 1)
        {
            // push it in the stack
            push_char(p[i]);
        }
        else if (isOperator(p[i])==1)
        {
            pop();
            makestring(p[i]);
            push_str(newstring);
        }
    }
    printf("The string in infix is: %s\n", top->expression);
}

int main(int argc, char const *argv[])
{
    printf("Enter the string in Postfix: ");
    scanf("%s", postfix);
    toInfix(postfix);
    return 0;
}
