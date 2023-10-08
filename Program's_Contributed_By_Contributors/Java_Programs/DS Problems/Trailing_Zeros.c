// Count the number of trailing zeros in n!
#include <stdio.h>

// function to calculate n!
long int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return (long)1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
// function to calculate trailing zeros in n!
int countZeros(int n)
{
    int res = 0;
    // to count the number of 5's in the gap of 5,25,125,625..so on
    for (int i = 5; i <= n; i = i * 5)
    {
        res = res + (n / i);
    }
    return res;
}
int main()
{
    int n;
    printf("Enter the number--> ");
    scanf("%d", &n);
    long int f = fact(n);
    int tz = countZeros(n);
    printf("\nFactorial of %d is-->%ld", n, f);
    printf("\nNumber of trailing zeros in factorial %d is-->%d", n, tz);
    return 0;
}