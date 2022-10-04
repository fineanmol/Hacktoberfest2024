// C++ program for implementation of Quick sort
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// A function to implement quick sort
// Time Complexity : O(nlogn)
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{       
        // pi is partitioning index, arr[p] is now
		int pi = partition(arr, low, high); 

        // Separately sort elements before pi
        quickSort(arr, low, pi - 1); 
        // Separately sort elements after pi
        quickSort(arr, pi + 1, high);
	}
}

// Function to print an array
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
	int arr[] = { 5, 1, 4, 2, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, N-1);
	cout << "Sorted array: \n";
	printArray(arr, N);
	return 0;
}
