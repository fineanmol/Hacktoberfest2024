#include <stdio.h>
int power(int a,int b){
    int i;
    int mul=1;
    for (i=0;i<b;i++){
        mul = mul*a;
    }
    return mul;
}
int push(char a[],int size,char element){
    a[size] = element;
    return 0;
}
int int_push(int a[],int size,int element){
    a[size] = element;
    return 0;
}
int pop(char a[],int size){
    return a[size-1];
}
int int_pop(int a[],int size){
    return a[size-1];
}
int postfix_convert(char infix[],char pf_array[]){
    char stack[20];
    int pf_size = 0;
    int size = 0;
    int flag=0;
    for (int i=0;infix[i]!='\0';i++){
        switch(infix[i]){
            //Operators
            case '^':
            flag=0;
            while (flag==0){
                if (stack[size-1]!='^'){
                    push(stack,size,'^');
                    size = size+1;
                    flag=1;
                }
                else{
                    pf_array[pf_size] = pop(stack,size);
                    size = size-1;
                    pf_size = pf_size+1;
                }
            }
            break;
            case '*':
            flag=0;
            while (flag==0){
                if ((stack[size-1]!='^')&&(stack[size-1]!='/')&&(stack[size-1]!='*')){
                    push(stack,size,'*');
                    size = size+1;
                    flag=1;
                }
                else{
                    pf_array[pf_size] = pop(stack,size);
                    size = size-1;
                    pf_size = pf_size+1;
                }
            }
            break;
            case '/':
            printf("Working\n");
            flag=0;
            while (flag==0){
                if ((stack[size-1]!='^')&&(stack[size-1]!='/')&&(stack[size-1]!='*')){
                    push(stack,size,'/');
                    size = size+1;
                    flag=1;
                }
                else{
                    pf_array[pf_size] = pop(stack,size);
                    size = size-1;
                    pf_size = pf_size+1;
                }
            }
            break;
            case '+':
            flag = 0;
            while (flag==0){
                if ((stack[size-1]!='^')&&(stack[size-1]!='/')&&(stack[size-1]!='*')&&
                (stack[size-1]!='+')&&(stack[size-1]!='-')){
                    push(stack,size,'+');
                    size=size+1;
                    flag = 1;
                }
                else{
                    pf_array[pf_size]=pop(stack,size);
                    size = size-1;
                    pf_size = pf_size+1;
                }
            }
            break;
            case '-':
            flag = 0;
            while (flag==0){
                if ((stack[size-1]!='^')&&(stack[size-1]!='/')&&(stack[size-1]!='*')&&
                (stack[size-1]!='+')&&(stack[size-1]!='-')){
                    push(stack,size,'-');
                    size=size+1;
                    flag = 1;
                }
                else{
                    pf_array[pf_size]=pop(stack,size);
                    size = size-1;
                    pf_size = pf_size+1;
                }
            }
            break;
            //Brackets
            case '(':
            push(stack,size,'(');
            size = size+1;
            break;
            case ')':
            while (pop(stack,size)!='('){
                pf_array[pf_size] = pop(stack,size);
                size = size-1;
                pf_size = pf_size+1;
            }
            size = size-1;
            break;
            //Numbers
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            pf_array[pf_size] = infix[i];
            pf_size = pf_size+1;
            break;
            //Invalid Values
            default:
            break;
        }
    }
    while (size!=0){
        pf_array[pf_size] = pop(stack,size);
        size = size-1;
        pf_size = pf_size+1;
    }
    pf_array[pf_size] = '\0';
    return 0;
}
int postfix_evaluate(char postfix[]){
    int int_stack[50];
    int size=0;
    int i,mid;
    for (i=0;postfix[i]!='\0';i++){
        switch (postfix[i]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            postfix[i] = postfix[i] - '0';
            int_push(int_stack,size,postfix[i]);
            size = size+1;
            break;
            case '+':
            mid = int_pop(int_stack,size)+int_pop(int_stack,size-1);
            size = size-2; 
            int_push(int_stack,size,mid);
            size = size+1;
            break;
            case '-':
            mid = int_pop(int_stack,size)-int_pop(int_stack,size-1);
            size = size-2; 
            int_push(int_stack,size,mid);
            size = size+1;
            break;
            case '*':
            mid = int_pop(int_stack,size)*int_pop(int_stack,size-1);
            size = size-2; 
            int_push(int_stack,size,mid);
            size = size+1;
            break;
            case '/':
            mid = int_pop(int_stack,size-1)/int_pop(int_stack,size);
            size = size-2; 
            int_push(int_stack,size,mid);
            size = size+1;
            break;
            case '^':
            mid = power(int_pop(int_stack,size-1),int_pop(int_stack,size));
            size = size-2; 
            int_push(int_stack,size,mid);
            size = size+1;
            break;
            default:
            break;
        }
    }
    printf("%d",int_stack[0]);
    printf("\n");
    return 0;
}
int main(){
    int choice,i,flag=0;
    char infix[50];
    char postfix[50];
    printf("----------INFIX TO POSTFIX----------\n");
    printf("----------MENU----------\n");
    printf("1. Enter Infix Expression\n");
    printf("2. Evaluate the Expression\n");
    printf("3. Exit\n");
    while (choice!=3){
        printf("-----COMMAND-----");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            printf("Enter the expression : ");
            scanf("%s",infix);
            printf("---Converting to Postfix---\n");
            postfix_convert(infix,postfix);
            printf("---Displaying the Expression---\n");
            for (i=0;postfix[i]!='\0';i++){
                printf("%c ",postfix[i]);
            }
            flag = 1;
            printf("\n");
            break;
            case 2:
            if (flag==1){
                printf("---Evaluating the Expression---\n");
                postfix_evaluate(postfix);
                break;
            }
            else{
                printf("No exression to evaluate\n");
            }
            case 3:
            break;
        }
    }
}