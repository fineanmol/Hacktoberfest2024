#include <stdio.h>
int main (){

        int a,b;
        char op;

        printf("Enter the first number: ");
        scanf("%d", &a);                      //first number input
        printf("Enter the operator: ");
        scanf(" %c", &op);                     //operator input
        printf("Enter the second number: ");
        scanf("%d", &b);                      //second number input

        switch (op){                        //switch case on operator

        case '+':printf("The sum of %d and %d is: %d", a, b, a+b);
        break;
        case '-':printf("The difference of %d and %d is: %d", a,b,a-b);
        break;
        case '*': printf("The multiplication of %d and %d is: %d",a,b,a*b);
        break;
        case '/':printf("The division of %d by %d is: %d",a,b,a/b);
        break;
        default: printf("Enter the correct values");
        }






return 0;
}
