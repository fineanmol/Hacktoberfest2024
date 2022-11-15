#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If element is at mid return it
    if (array[mid] == x)
      return mid;

    // Try to search on left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Try to search on right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main(void) {
	int n, x;
	cout<<"Enter the length of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the values you want to add to array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the value you want to find in the array: ";
	cin>>x;
  	int result = binarySearch(arr, x, 0, n - 1);
  	if (result == -1){
  	cout<<"Value not found in the array"<<endl;
  	}
  	else{
  	cout<<"Value found at index: "<<result<<endl;
  	}
}
