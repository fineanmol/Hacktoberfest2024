#include <iostream>

using std::cout;
    
// Insertion Sort Algorithm

// Time complexity
// Best: O(n)
// Average: O(n^2)
// Worst: O(n^2)

// Space complexity: O(1)
void insertionSort(int arr[], int n) // n is the size of the array
{
    int i, key, j; // i is the index of the element to be inserted, key is the element to be inserted, j is the index of the element to be compared
    for (i = 1; i < n; i++) // i starts at 1 because the first element is already sorted
    {
        key = arr[i]; // key is the element to be inserted
        j = i - 1; // j is the index of the element to be compared
        while (j >= 0 && arr[j] > key) // while the element to be compared is greater than the element to be inserted
        {
            arr[j + 1] = arr[j]; // shift the element to the right
            j = j - 1; // decrement j
        }
        arr[j + 1] = key; // insert the element
    }
}



int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    cout << "Sorted array is \n";
    insertionSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        cout << arr[i] << " ";
    return 0;
}
