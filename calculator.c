//A basic calculator using switch case
#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    int op,g,h;
    float a,b,c;
    printf("Enter 1 for add\nEnter 2 for sub\nEnter 3 for multiply\nEnter 4 for div\nEnter 5 for mod\nEnter 6 for power\nEnter 7 for square root\nEnter 8 to check even or odd\nEnter 9 to check no. is positive or negative\n");
    scanf("%d",&op);
    switch (op)
    {
        case 1:
        printf("Enter the value of Num1 & Num2 respectively\n");
        scanf("%f%f",&a,&b);
        printf("%f",a+b);
        break;
        case 2:
        printf("Enter the value of Num1 & Num2 respectively\n");
        scanf("%f%f",&a,&b);
        printf("%f",a-b);
        break;
        case 3:
        printf("Enter the value of Num1 & Num2 respectively\n");
        scanf("%f%f",&a,&b);
        printf("%f",a*b);
        break;
        case 4:
        printf("Enter the value of Num1 & Num2 respectively\n");
        scanf("%f%f",&a,&b);
        printf("%f",a/b);
        break;
        case 5:
        printf("Enter the value of Num1 & Num2 respectively\n");
        scanf("%f%f",&g,&h);
        printf("%d",g%h);
        break;
        case 6:
        printf("Enter the value of base value and power value\n");
        scanf("%f%f",&a,&b);
        printf("%f",pow(a,b));
        break;
        case 7:
        printf("Enter the value to get square root\n");
        scanf("%f",&a);
        printf("%f",sqrt(a));
        break;
        case 8:
        printf("Enter the value to know its odd or even\n");
        scanf("%d",&g);
        if (g%2==0)
        {
            printf("Even");
        }
        else{
            printf("Odd");
        }
        break;
        case 9:
        printf("Enter the value to know its positive or negative");
        scanf("%d",&g);
        if (g>0)
        {
            printf("Positive");
        }
        else if (g=0)
        {
            printf("Zero");
        }
        else{
            printf("Negative");
        }
        break;
    default:
        printf("Enter correct input");
        break;
    }
    return 0;
}
