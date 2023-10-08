/*
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
*/
#include <stdio.h>

int kadane(int arr[], int n)
{
    int maxSum = arr[0];
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum = currSum + arr[i];
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
        /*if we get an negetive sum then it will be of no use to get the max sum so we have to discard it
         */
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int n;
    printf("Enter the size of the array--> ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements--> ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = kadane(a, n);
    printf("\nMaximum sub-array sum is-->%d\n", ans);
    return 0;
}