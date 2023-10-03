#include <stdio.h>
#include <conio.h>
// finds smallest element in the array and swaps with i(0) then next iteration starts from i+i ---> finds smallest element swaps with (i+1)th position and so on....
void recurselectSort(int arr1[], int len1, int pos1);

int main()
{
    int size, i;
    printf("Enter size of array : ");
    scanf("%d", &size);
    int a[size];
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    // for (i = 0; i < size; i++)
    // {
    //     int min = i;
    //     for (int j = i + 1; j < size; j++)
    //     {
    //         if (a[j] < a[min])
    //         {
    //             min = j;
    //         }
    //     }
    //     if (a[i] != a[min])
    //     {
    //         int temp = a[i];
    //         a[i] = a[min];
    //         a[min] = temp;
    //     }
    // }
    recurselectSort(a, size, 0);
    for (i = 0; i < size; i++)
    {
        printf("%d   ", a[i]);
    }
    return 0;
}
int findMin(int arr[], int i, int j)
{
    int minpos;
    if (i == j)
    {
        return i;
    }
    minpos = findMin(arr, i + 1, j);
    if (arr[i] < arr[minpos])
    {
        minpos = i;
    }
    return (minpos);
}
void recurselectSort(int arr1[], int len1, int pos1)
{
    int temp;
    int minpos1;
    if (pos1 == len1)
    {
        return;
    }
    minpos1 = findMin(arr1, pos1, len1 - 1);
    if (minpos1 != pos1)
    {
        temp = arr1[pos1];
        arr1[pos1] = arr1[minpos1];
        arr1[minpos1] = temp;
    }
    recurselectSort(arr1, len1, pos1 + 1);
}