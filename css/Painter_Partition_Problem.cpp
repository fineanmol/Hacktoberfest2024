// CPP program for The painter's partition problem
#include <climits>
#include <iostream>
using namespace std;

// function to calculate sum between two indices
// in array
int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}

// for n boards and k partitions
int partition(int arr[], int n, int k)
{
	// base cases
	if (k == 1) // one partition
		return sum(arr, 0, n - 1);
	if (n == 1) // one board
		return arr[0];

	int best = INT_MAX;

	// find minimum of all possible maximum
	// k-1 partitions to the left of arr[i],
	// with i elements, put k-1 th divider
	// between arr[i-1] & arr[i] to get k-th
	// partition
	for (int i = 1; i <= n; i++)
		best = min(best, max(partition(arr, i, k - 1),
								sum(arr, i, n - 1)));

	return best;
}

int main()
{
	int arr[] = { 10, 20, 60, 50, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << partition(arr, n, k) << endl;

	return 0;
}
