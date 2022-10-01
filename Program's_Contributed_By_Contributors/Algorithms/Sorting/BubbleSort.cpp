#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {2, 5, 3, 1, 6, 7, 9, 4, 8, 10};
    int l = sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            int temp = arr[i];
            if (arr[j] < temp)
            {
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int j = 0; j < l; j++)
    {
        cout<<arr[j]<<" ";
    }
    
}