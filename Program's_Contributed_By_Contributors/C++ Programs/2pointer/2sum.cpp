#include <iostream>
#include <algorithm>

using namespace std;

// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with a given sum.
int isPairSum(int A[], int N, int X)
{
    // represents first pointer
    int i = 0;

    // represents second pointer
    int j = N - 1;

    while (i < j)
    {

        // If we find a pair
        if (A[i] + A[j] == X)
            return 1;

        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (A[i] + A[j] < X)
            i++;

        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing j--
        else
            j--;
    }
    return 0;
}

// Driver code
int main()
{
    // array declaration
    int arr[] = {2, 3, 5, 8, 9, 10, 11};

    // value to search
    int val = 17;

    // size of the array
    int arrSize = *(&arr + 1) - arr;

    // array should be sorted before using two-pointer technique
    sort(arr, arr + 7);

    // Function call
    cout << (bool)isPairSum(arr, arrSize, val);

    return 0;
}