#include <stdio.h>
int FirstOccure(int arr[], int size, int key);
int LastOccure(int arr[], int size, int key);
int main()
{
    int even[10] = {1, 2, 3, 3, 3, 3, 6, 7};
    int size = 8;
    int key = 3;
    int FO,LO;
    FO = FirstOccure(even, size, key);
    LO = LastOccure(even, size, key);

    printf("Element %d First Occures at Index %d", key,FO);
    printf("\nElement %d Last Occures at Index %d", key,LO);
    int count =(LO-FO)+1;
    printf("\nFrequency of Element %d is %d",key,count);
    return 0;
}
int FirstOccure(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        mid = (s + e)/2;
    }
    return ans;
}
int LastOccure(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        mid = (s + e)/2;
    }
    return ans;
}
