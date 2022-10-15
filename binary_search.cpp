#include "bits/stdc++.h"
using namespace std;

int binary_search(int *arr, int n, int target)
{
	int l = 0, r = n-1;
	while(l < r)
	{
		int m = l + (r - l) / 2;
		if(arr[m] == target)
			return m; 	
		if(arr[m] < target)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main()
{
	int arr = {1, 2, 3, 4, 5};
	cout << binary_search(arr, 5, 3) << "\n";
}