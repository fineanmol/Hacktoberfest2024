//Insert an element from an unsorted array into its correct position in a sorted array
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 5, 2, 7, 3, 8, 9, 4, 6};
    int l = sizeof(arr) / sizeof(*arr);
    for (int i = 1; i < l; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for (int k = 0; k < l; k++)
    {
        cout << arr[k] << " ";
    }
}