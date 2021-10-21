/*TimSort is a sorting algorithm based on Insertion Sort and Merge Sort.

A stable sorting algorithm works in O(n Log n) time and O(n) in best case.
Used in Java’s Arrays.sort() as well as Python’s sorted() and sort().
First sort small pieces using Insertion Sort, then merges the pieces using merge of merge sort.
We divide the Array into blocks known as Run. 
We sort those runs using insertion sort one by one and then merge those runs using the combine function used in merge sort. 
If the size of the Array is less than run, then Array gets sorted just by using Insertion Sort. 
The size of the run may vary from 32 to 64 depending upon the size of the array. 
Note that the merge function performs well when size subarrays are powers of 2. 
The idea is based on the fact that insertion sort performs well for small arrays.

*/
//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
const int RUN = 32;

// This function sorts array from left index to
// to right index which is of size atmost RUN
void insertion_sort(int A[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = A[i];
        int j = i - 1;
        while (j >= left && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

// Merge function merges the sorted runs
void merge(int A[], int l, int m, int r)
{

    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = A[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = A[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left, if any
    while (i < len1)
    {
        A[k] = left[i];
        k++;
        i++;
    }

    // Copy remaining element of right, if any
    while (j < len2)
    {
        A[k] = right[j];
        k++;
        j++;
    }
}

// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void tim_sort(int A[], int n)
{

    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i += RUN)
        insertion_sort(A, i, min((i + RUN - 1), (n - 1)));

    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
         size = 2 * size)
    {

        // pick starting point of
        // left sub array. We
        // are going to merge
        // A[left..left+size-1]
        // and A[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left < n;
             left += 2 * size)
        {

            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1),
                            (n - 1));

            // merge sub array A[left.....mid] &
            // A[mid+1....right]
            if (mid < right)
                merge(A, left, mid, right);
        }
    }
}

// Utility function to print the Array
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", A[i]);
    printf("\n");
}

// Driver program to test above function
int main()
{
    int A[] = {-2, 7, 15, -14, 0, 15, 0, 7, -7,
                 -4, -13, 5, 8, -14, 12};
    int n = sizeof(A) / sizeof(A[0]);
    cout<<"Given Array is\n";
    printArray(A, n);

    // Function Call
    tim_sort(A, n);

    cout<<"\nAfter Sorting Array is\n";
    printArray(A, n);
    return 0;
}
