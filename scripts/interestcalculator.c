// c program to Calculate Simple Interest and Compound Interest 
#include <stdio.h>
#include <math.h>
int main()
{
    int type_of_interest;

    printf("enter 1 for simple interest enter 2 for compoud interest \n");
    scanf("%d",&type_of_interest);
    

    if (type_of_interest == 1)
    {
        int a, b, c;
        printf("enter the principal amount \n");
        scanf("%d", &a);

        printf("enter the rate of interest \n");
        scanf("%d", &b);

        printf("enter the time in years \n ");
        scanf("%d", &c);

        int totalAmount = {a + (a * b * c) / 100};
        printf("The value of total amount after %d years is %d", c, totalAmount);
        
    }
    else
    {
        float p, r, n;
        printf("Enter the Principal Amount : \n");
        scanf("%f", &p);
        printf("Enter the Rate of Interest : \n");
        scanf("%f", &r);
        printf("Enter the duration in Years : \n");
        scanf("%f", &n);
        float i1 = ((100 + r )/ 100);
        float i2 = pow(i1, n);
        float i3 =  p * i2;

        printf("The total Amount after %.0f years will be %.4f \n", n , i3 );
        printf("The Compound interest after %.0f years will be %.4f  \n", n, i3-p);

    }

    return 0;
}