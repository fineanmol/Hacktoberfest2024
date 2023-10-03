#include <stdio.h>
#include <conio.h>
void recursive_bubble(int arr[], int len);

int main()
{
    int n;
    printf("Enter Size of array : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    recursive_bubble(a, n);
    // int temp;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < n - 1 - i; j++)
    //     {
    //         if (a[j] > a[j + 1])
    //         {
    //             temp = a[j];
    //             a[j] = a[j + 1];
    //             a[j + 1] = temp;
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
}

// recursive code for bubble sort
void recursive_bubble(int arr[], int len)
{
    if (len == 1)
    {
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    recursive_bubble(arr, len - 1);
}