// This code is to implement Binary Search in C++

// Here elements[] refers to the array of elements in sorted order and searchkey refers to the key element we are searching

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int elements[], int searchkey, int low, int high)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (elements[mid] == searchkey)
            return mid;

        if (elements[mid] < searchkey)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int elements[] = {-3, 5, 7, 12, 45, 72, 430};
    int searchkey = 7;
    int n = sizeof(elements) / sizeof(elements[0]);
    int result = binarySearch(elements, searchkey, 0, n - 1);
    if (result == -1)
        cout << "Element Not found";
    else
        cout << "Element is found at index " << result;
    return 0;
}