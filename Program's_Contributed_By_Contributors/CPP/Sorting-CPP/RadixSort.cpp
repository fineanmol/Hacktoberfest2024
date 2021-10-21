/*

Introduction:

  Radix sort is a sorting algorithm that sorts numbers by the positions of their digits.
  Radix sort uses counting sort as a subroutine to sort.
  The way it works is that it uses the place value of the digits in a number (from least significant digit to most significant digit)
  In contrast to other sorting algorithms, Merge Sort, Insertion Sort, Bubble Sort,
  the number are not compared.

  It can also be applied to string with just a little change of the place value used (here we go from most significant to least significant digit).

  To sort the digits, Radix sort uses a stable sorting algorithm as a subroutine.
  Using a variation of cing sort, I have sorted the digits using the radix in every position.

*/


/*
Time and Space Complexity:

  Time Complexity:

  Best:              O(n+k)
  Worst:	     O(n+k)
  Average:           O(n+k)

  Space Complexity:  O(max)

  The performance of Radix Sort depends on the stable sorting algorithm chosen to sort the digits.
*/
// code

// C++ implementation of Radix Sort
#include<iostream>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Function Call
	radixsort(arr, n);
	print(arr, n);
	return 0;
}


