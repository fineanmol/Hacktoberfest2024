/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.
*/
#include <stdio.h>

int jos(int n, int k)
{
    // if there is just 1 person then he itself the winner
    if (n == 1)
    {
        return 0;
    }
    /*otherwise map the originial problem with (n-1) people with the sub problem, and move the index i to (i+k)%n to get the answer*/
    else
    {
        return (jos(n - 1, k) + k) % n;
    }
}
int main()
{
    int n, k;
    printf("Enter the number of persons--> ");
    scanf("%d", &n);
    printf("Enter the value of k--> ");
    scanf("%d", &k);
    int c = jos(n, k);
    printf("\nThe winning person is--%d\n", c+1);
    return 0;
}