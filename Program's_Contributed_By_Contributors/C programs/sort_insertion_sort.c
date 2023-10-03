#include <stdio.h>
#include <conio.h>
/*
In first step 2nd element is compared with 1st element, if found larger then we do swapping
In 2nd step 3rd element is compared with first two elements
In 3rd step 4th element is compared with first three element
In last step last element is compared with first n-1 elements.
https://www.youtube.com/watch?v=ep8uG1IBApQ
*/

void recursiveInsertionSort(int arr[], int len);

int main()
{
    int a[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &a[i]);
    }
    // for (int i = 1; i < 8; i++)
    // {
    //     int key = a[i];
    //     int j = i - 1;
    //     while (j >= 0 && a[j] > key)
    //     {
    //         a[j + 1] = a[j]; // here we are storing jth element at (j+1)th position
    //         j--;
    //     }
    //     a[j + 1] = key;
    // }
    recursiveInsertionSort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d  ", a[i]);
    }
}

void recursiveInsertionSort(int arr[], int len)
{
    if (len <= 1)
        return;
    recursiveInsertionSort(arr, len - 1);
    int last = arr[len - 1];
    int j = len - 2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
