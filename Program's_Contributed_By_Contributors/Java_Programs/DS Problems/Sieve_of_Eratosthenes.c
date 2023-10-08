// to find the number of prime numbers in between the range of 1 to n
#include <stdio.h>

int isPrime(int n)
{
    char store[n + 2];
    // initialize all values to true
    for (int i = 0; i <= n; i++)
    {
        store[i] = 'T';
    }
    // make the value of 0 and 1 false
    store[0] = 'F';
    store[1] = 'F';

    /*iterte loop from 2 to sqrt(n) and make false
        the numbers which is multiple of 2,3,5,..and so on
    */
    for (int i = 2; i * i <= n; i++)
    {
        if (store[i] == 'T')
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                store[j] = 'F';
            }
        }
    }
    // to count the prime numbers
    int c = 0;
    for (int i = 0; i <= n; i++)
    {
        if (store[i] == 'T')
        {
            c++;
        }
    }
    return c;
}
int main()
{
    int n;
    printf("Enter the range--> ");
    scanf("%d", &n);
    int count = isPrime(n);
    printf("\nThe number of prime numbers between 1 to %d--> %d", n, count);
    return 0;
}