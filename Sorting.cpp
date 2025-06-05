// C++ program to demonstrate performance of
// C qsort and C++ sort() algorithm
#include <bits/stdc++.h>
using namespace std;

// Number of elements to be sorted
#define N 1000000

// A comparator function used by qsort
int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

// Driver program to test above functions
int main()
{
	int arr[N], dupArr[N];

	// seed for random input
	srand(time(NULL));

	// to measure time taken by qsort and sort
	clock_t begin, end;
	double time_spent;

	// generate random input
	for (int i = 0; i < N; i++)
		dupArr[i] = arr[i] = rand()%100000;

	begin = clock();
	qsort(arr, N, sizeof(int), compare);
	end = clock();

	// calculate time taken by C qsort function
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Time taken by C qsort() - "
		<< time_spent << endl;

	time_spent = 0.0;

	begin = clock();
	sort(dupArr, dupArr + N);
	end = clock();

	// calculate time taken by C++ sort
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Time taken by C++ sort() - "
		<< time_spent << endl;

	return 0;
}
