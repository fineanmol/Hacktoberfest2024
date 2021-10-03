#include <bits/stdc++.h>
using namespace std;
//                     Condition
// array must be sorted as it will be further divided in half
// worst case complexity is O(log(n))
// we have to maintain and chech  |Low| |High| |Mid|
// mid greatest integer is [11/2 = 5] as   (int / int = int)
int BinarySearch(int arr[], int size, int element)
{   
    int low, mid, high;
    low = 0;
    high = size - 1; // these low mid high are the index;

    while (low <= high)
    { 
        // search starts till low is not eqaual to high i.e. no element btw low and high
        mid = (low + high) / 2; // greatest integer i.e. 7/2 =3
        if (arr[mid] == element) 
        {
            return mid; //  element found so return 
        }
        else if (arr[mid] < element)
        {
            low = mid + 1; // when the element is at right side of the mid so low will be one element right of mid i.e. not inclusize as we know that element will not be on mid because we searched above already 
        }
        else
        {
            high = mid - 1;// when the element is at left side of the mid so high will be one element left of mid i.e. not inclusize as we know that element will not be on mid because we searched above already 
        }
    }
    
    return -1;// when seached in whole while loop and still not found so will return -1 as outside of while loop
}

int main()
{
    int size, element;
    cout << "input size" << endl;
    cin >> size;
    int arr[size];
    cout << "input array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "enter element to be searched" << endl;
    cin >> element;

    cout << BinarySearch(arr, size, element);
    return 0;
}