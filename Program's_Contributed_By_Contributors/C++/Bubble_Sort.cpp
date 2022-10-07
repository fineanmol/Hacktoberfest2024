// C++ program for implementation
// of Bubble sort
#include <bits/stdc++.h>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{       
		bool swapped = false;
		//swapped is used to maintain the stability of array elements
		// Last i elements are already
		// in place
		for (j = 0; j < n - i - 1; j++)
		{	if (arr[j] > arr[j + 1])
			{
			    swap(arr[j], arr[j + 1]);
		            swapped=true;
			}
		}
	        if(swapped == false){
			break;
		}
	}
}

// Function to print an array
void print(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = {9,3,4,2,7,6};
	int N = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, N);
	cout << "Sorted array: \n";
	print(arr, N);
	return 0;
}
