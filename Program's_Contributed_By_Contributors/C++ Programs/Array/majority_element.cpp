// C++ program to find Majority
// element in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find Majority element
// in an array
void findMajority(int arr[], int n)
{
	int maxCount = 0;
	int index = -1; // sentinels
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j])
				count++;
		}

		// update maxCount if count of
		// current element is greater
		if (count > maxCount) {
			maxCount = count;
			index = i;
		}
	}

	// if maxCount is greater than n/2
	// return the corresponding element
	if (maxCount > n / 2)
		cout << arr[index] << endl;

	else
		cout << "No Majority Element" << endl;
}

// Driver code
int main()
{
	int arr[] = { 1, 1, 2, 1, 3, 5, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function calling
	findMajority(arr, n);

	return 0;
}
