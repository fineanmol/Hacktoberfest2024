Insertion sort Implementation in C++:

#include <stdlib.h>
#include <iostream>

using namespace std;

//member functions declaration
void insertionSort(int arr[], int length);
void printArray(int array[], int size);

// main function
int main() 
{
    int array[6] = {5, 1, 6, 2, 4, 3};
    // calling insertion sort function to sort the array
    insertionSort(array, 6);
    return 0;
}

void insertionSort(int arr[], int length) 
{
    int i, j, key;
    for (i = 1; i < length; i++) 
    {
        key = arr[i];
        j = i-1;
        
        while (j >= 0 && arr[j] >key) 
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j +1] = key;
        
    }
    cout << "Sorted Array: ";
    // print the sorted array
    printArray(arr, length);
}

// function to print the given array 
void printArray(int array[], int size)
{ 
    int j;
    for (j = 0; j < size; j++)
    {
        cout <<" "<< array[j];  
    }
    cout << endl;
}
