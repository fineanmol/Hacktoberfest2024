#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main()
{

    int pos, i, j, arr;
    cout << "Enter the size of array: ";
    cin >> j;
    cout << "enter the elment of array: ";
    for (i = 0; i < j; i++)
    {
        cin >> array;
    }

    cout << "Enter the position of kth element: " << endl;
    cin >> pos;

    sort(arr, arr + size, greater<int>()); // C++ library function for sorting the array
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == k - 1) //k-1 since the array elements start from 0-th index
        {
            cout << "K-th largest element is : " << arr[i] << endl;
            break;
        }
    }
}
// if (pos <= j)
// {
//     int element = pos;
//     cout << pos << "array is " << element;
// }
// else
// {
//     cout << "invalid positon";
// }
return (0);
}