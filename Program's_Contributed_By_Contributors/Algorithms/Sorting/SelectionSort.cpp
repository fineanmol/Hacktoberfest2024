#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {3, 2, 4, 6, 1, 7, 5, 9, 8};
    int l = sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < l; i++)
    {
        int min = arr[i];
        int index = i;
        for (int j = i + 1; j < l; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
    for (int k = 0; k < l; k++)
    {
        cout << arr[k] << " ";
    }
}