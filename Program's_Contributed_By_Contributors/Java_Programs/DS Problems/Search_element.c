// Search element in sorted rotated array
#include <stdio.h>

int find(int array[], int n, int target)
{
    int low = 0, high = n - 1,mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == target)
        {
            return mid;
        }
        // if left part of the mi element is sorted
        if (array[low] <= array[mid])
        {
            if (target >= array[low] && target < array[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // if right part of the mi element is sorted
        else
        {
            if (target > array[mid] && target <= array[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int n, key;
    printf("Enter the size of the array--> ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the rotated sorted array--> ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter the key to be searched--> ");
    scanf("%d", &key);
    int ans = find(a, n, key);
    if (ans == -1)
    {
        printf("\nThe element is not present in the array!!!\n");
    }
    else
    {
        printf("\nThe element present at index %d in the array\n", ans);
    }
    return 0;
}