// C++ program to implement recursive Binary Search
//contributed by whyanujjwhy
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}

int main(void)
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    
    cout<<"\nEnter elements in increasing order!";
    int arr[n];
    for(int i=0; i<n; i++) {
        cout<<"\nEnter element "<<i+1<<" ";
        cin>>arr[i];
    }
    int x;
    cout<<"\nEnter element to search: ";
    cin>>x;
	
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Element is not present in array!"
		: cout << "Element is present at index " << result;
	return 0;
}
