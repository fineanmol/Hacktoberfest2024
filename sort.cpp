// C++ program to demonstrate sort()

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 0, 1, 5, 8, 9, 6, 7, 3, 4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Sort the elements which lies in the range of 2 to
	// (n-1)
	sort(arr + 2, arr + n);

	cout << "Array after sorting : \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}
// This code is contributed by Suruchi Kumari
