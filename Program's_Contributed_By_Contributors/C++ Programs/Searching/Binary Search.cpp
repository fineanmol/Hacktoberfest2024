#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int key){
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int key = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, key);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}
