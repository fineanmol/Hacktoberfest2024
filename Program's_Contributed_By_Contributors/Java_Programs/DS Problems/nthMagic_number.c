/*
A magic number is defined as a number that can be expressed as a power of 5 or sum of unique powers of 5. First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….
*/

#include <stdio.h>

int findmagic(int n)
{
    int ans = 0, base = 5;
    while (n > 0)
    {
        int last = n & 1;
        n = n >> 1;
        ans += last * base;
        base = base * 5;
    }
    return ans;
}
int main()
{
    int n;
    printf("Enter the value of n--> ");
    scanf("%d", &n);
    int ans = findmagic(n);
    printf("\nThe %dth magical number is-->%d\n", n, ans);
    return 0;
}