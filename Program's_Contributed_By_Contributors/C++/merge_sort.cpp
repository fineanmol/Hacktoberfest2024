// C++ program for merge sort

#include <bits/stdc++.h>

using namespace std;

// Function to merge the sorted array
void mergeArr(int a[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int b[n1];
    int c[n2];

    for (int i = 0; i < n1; i++)
    {
        b[i] = a[start + i];
    }

    for (int i = 0; i < n2; i++)
    {
        c[i] = a[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2)
    {
        if (b[i] < c[j])
        {
            a[k++] = b[i++];
        }
        else
        {
            a[k++] = c[j++];
        }
    }

    while (i < n1)
    {
        a[k++] = b[i++];
    }

    while (j < n2)
    {
        a[k++] = c[j++];
    }
}

// Function to sort an array using
// merge sort
void mergeSort(int a[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        mergeArr(a, start, mid, end);
    }
}

int main()
{
    int a[] = {34, 2, 1, 55, 21, 33};
    int n = sizeof(a) / sizeof(int);

    mergeSort(a, 0, n - 1);

    for (auto it : a)
    {
        cout << it << " ";
    }

    return 0;
}