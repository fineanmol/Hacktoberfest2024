#include <stdio.h>
#include <ctype.h>
#DEFINE MAXSIZE 40;

char stack[MAXSIZE];
int top = -1;

void push(char symbol){
    if (top == MAXSIZE - 1)
        printf("Stack Overflow");
    else
        stack[++top] = symbol;
}

char pop(){
    if (top == -1)
        return '#';
    else
    item = stack[top - 1];
    return item;
}

int precedence(char op){
    if (op == '(')
        return 0;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
    return 3;
}

void infix_to_postfix(char infix[], char postfix[]){
    int i = 0;
    while(infix[i] != '\0'){
        ch = infix[i];
        if (ch == '(')
            push('(');
        else if(isalnum(ch))
            postfix[pos++] = ch;
        else if (ch == ')'){
            symbol = pop();
            while(symbol != '('){
                postfix[pos++] = symbol;
                symbol = pop();
            }
        }
        else{
            while(precedence(ch) < precedence(stack[top])){
                symbol = pop();
                postfix[pos++] = symbol;
            }
        }
        i++;
    }
}

int main(){
    char infix[40], postfix[40];
    printf("Enter the infix expression");
    gets(infix);
    printf("postfix expression is \n");
    printf("%s")
}
