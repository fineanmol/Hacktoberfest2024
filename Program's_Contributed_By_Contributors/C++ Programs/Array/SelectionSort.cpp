#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of elements in array- ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("\n\n Sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }   
    return 0;
}