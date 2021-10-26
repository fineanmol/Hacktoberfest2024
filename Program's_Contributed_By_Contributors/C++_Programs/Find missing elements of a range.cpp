// A sorting based C++ program to find missing
// elements from an array
#include <bits/stdc++.h>
using namespace std;

// Print all elements of range [low, high] that
// are not present in arr[0..n-1]
void printMissing(int arr[], int n, int low,
				int high)
{
	// Sort the array
	sort(arr, arr + n);

	// Do binary search for 'low' in sorted
	// array and find index of first element
	// which either equal to or greater than
	// low.
	int* ptr = lower_bound(arr, arr + n, low);
	int index = ptr - arr;

	// Start from the found index and linearly
	// search every range element x after this
	// index in arr[]
	int i = index, x = low;
	while (i < n && x <= high) {
		// If x doesn't math with current element
		// print it
		if (arr[i] != x)
			cout << x << " ";

		// If x matches, move to next element in arr[]
		else
			i++;

		// Move to next element in range [low, high]
		x++;
	}

	// Print range elements thar are greater than the
	// last element of sorted array.
	while (x <= high)
		cout << x++ << " ";
}

// Driver program
int main()
{
	int arr[] = { 1, 3, 5, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int low = 1, high = 10;
	printMissing(arr, n, low, high);
	return 0;
}
