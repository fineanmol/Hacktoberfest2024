
#include <iostream>
#include <algorithm>

using namespace std;

int isPairSum(int A[], int N, int X)
{
		int i = 0;

	int j = N - 1;

	while (i < j) {

		if (A[i] + A[j] == X)
			return 1;

		else if (A[i] + A[j] < X)
			i++;

		else
			j--;
	}
	return 0;
}

int main()
{
	int arr[] = { 2, 3, 5, 8, 9, 10, 11 };
	int val = 17;
	int arrSize = *(&arr + 1) - arr;
	sort(arr, arr+7);
	cout << (bool)isPairSum(arr, arrSize, val);

	return 0;
}
