#include<stdio.h>
#include<stdlib.h>

char *arr;
int top=-1;
int size = 50;
int valid = 1;

int isEmpty(){

    if(top == -1)   return 1;
    return 0;
}

int isFull(){

    if(top == size-1)   return 1;
    return 0;
}

void push(char ch){

    if(!isFull()){
        arr[++top] = ch;
    }
    else
        printf("\nThe stack is overflowed!!\n");

}

char pop(){

    if(!isEmpty()){
        char ch = arr[top];
        top--;
        return ch;
    }
    printf("\nThe stack is empty!!\n");
}

int main(){

    arr=(char *)malloc(sizeof(char)*size);
    printf("Enter an expression : \n");
    gets(arr);


    for(int i=0;arr[i]!='\0';i++){

        if(arr[i] == '(')
            push('(');
        else{
            if(isEmpty()){
                valid = 0;
                break;
            }
                
            else{   
                char ch = pop();
                if(ch != '('){
                    valid = 0;
                    break;
                }
                    
            }   
        }
    }
    if(!isEmpty())  valid = 0;
    if(valid == 0)
        printf("Parenthesis not matching\n");
    else
        printf("Parenthesis matching\n");
    return 0;
}