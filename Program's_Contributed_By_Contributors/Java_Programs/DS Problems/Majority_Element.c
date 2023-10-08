/*Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 */

#include <stdio.h>

int majorityElement(int arr[], int n)
{
    int ansInd = 0, count = 1, c = 0;
    // to check the probable majority element
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[ansInd])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            ansInd = i;
            count = 1;
        }
    }
    // to check if the guess is actually majority element or not
    for (int i = 0; i < n; i++)
    {
        if (arr[ansInd] == arr[i])
        {
            c++;
        }
    }
    if (c > n / 2)
    {
        return arr[ansInd];
    }
    else
    {
        return -1;
    }
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
    int ans = majorityElement(a, n);
    if (ans == -1)
    {
        printf("\nThere is no majority element in the given array!!!\n");
    }
    else
    {
        printf("\nThe majority element in the given array is-->%d\n", ans);
    }
    return 0;
}