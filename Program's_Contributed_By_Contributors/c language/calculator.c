#include<stdio.h>
int main()
{
    char choice;
    int a,b;
    printf("enter a choice + - * /");
    scanf("%c",choice);
	printf("enter two numbers");
    scanf("%d\n%d",&a,&b);
    switch(choice)
    {
        case '+':printf("%d+%d=%d",a,b,a+b);
        break;
        case '-':printf("%d-%d=%d",a,b,a-b);
        break;
        case '*':printf("%d+%d=%d",a,b,a*b);
        break;
        case '/':printf("%f/%f=%f",a,b,a/b);
        break;
        default:printf("ERORR INPUT");
    }
}
