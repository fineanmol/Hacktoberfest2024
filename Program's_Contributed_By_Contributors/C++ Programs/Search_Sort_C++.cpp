/** C++ program for implementation of
    Bubble sort
    selection sort
    insertion sort
    linear search
    Binary search

**/
#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubble_sort(int arr[], int n)
{
    int i, j,temp;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                //or use swap(&arr[j], &arr[j+1]);
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
}

void selection_sort(int arr[], int n)
{
    int i,j,min_index,temp;
    for(i=0; i<n-1; i++)
    {
        min_index = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min_index])
                min_index = j;
        }

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

}

void insertion_sort(int arr[], int n)
{
    int i,j,key;
    for(i=1; i<n ; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

bool binarySearch(int array[], int n, int value)
{
    int first = 0;
    int last = n-1;
    int middle;
    while ( first <= last )
    {
        middle = (first + last) / 2;
        if (array[middle] == value)
            return true;
        else if (array[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return false;
}

bool Linear_Search(int array[], int n, int value)
{
    for(int i=0; i<n; i++)
    {
        if(array[i]==value)
        {
            return true;
            break;
        }
    }
    return false;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    bubble_sort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);

    cout << endl;

    int arr2[] = {40,10,50,90,30,60,80,70,20};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printArray(arr2, n2);
    selection_sort(arr2, n2);
    cout<<"Sorted array: \n";
    printArray(arr2, n2);

    cout << endl;

    int arr3[] = {19,11,13,12,15,16,14,18,17};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printArray(arr3, n3);
    insertion_sort(arr3, n3);
    cout<<"Sorted array: \n";
    printArray(arr3, n3);

    cout << endl;

    cout << "Enter a value to Binary search on First array - ";
    int value;
    cin >> value;
    if(binarySearch(arr,n,value))
        cout << "Value is Found";
    else
        cout << "Value is NOT Found";

    cout << endl;

    cout << "Enter a value to Linear search on Second array - ";
    int value2;
    cin >> value2;
    if(Linear_Search(arr2,n2,value2))
        cout << "Value is Found";
    else
        cout << "Value is NOT Found";

    return 0;
}