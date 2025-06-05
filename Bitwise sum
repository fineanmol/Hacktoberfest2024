#include<stdio.h>
 
int bitwiseadd(int x, int y)
{
    while (y != 0)
    {
        int carry = x & y;
        x = x ^ y; 
        y = carry << 1;
    }
    return x;
}
 
int main()
{
    int num1, num2;
    printf("\nEnter two numbers to perform addition using bitwise operators: ");
    scanf("%d%d", &num1, &num2);
    printf("\nSum is %d", bitwiseadd(num1, num2));
    return 0;
}
