#include <bits/stdc++.h>
using namespace std;

// Function for Selection sort
void selectionSort(int array[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {

		// Find the minimum element in unsorted array

		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		// Swap the found minimum element with the first element
		if (min_idx != i)
			swap(array[min_idx], array[i]);
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
		cout << endl;
	}
}

// Driver code
int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	selectionSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
