#include <bits/stdc++.h>
using namespace std;

// A binary search based function
// that returns index of a peak element
int findPeak(int arr[], int n)
{
    int l = 0;
    int r = n - 1;
    int mid;

    while (l <= r)
    {

        // finding mid by binary right shifting.
        mid = (l + r) >> 1;

        // first case if mid is the answer
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) and (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            break;

        // move the right pointer
        if (mid > 0 and arr[mid - 1] > arr[mid])
            r = mid - 1;

        // move the left pointer
        else
            l = mid + 1;
    }

    return mid;
}

// Driver Code
int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is " << findPeak(arr, N);
    return 0;
}