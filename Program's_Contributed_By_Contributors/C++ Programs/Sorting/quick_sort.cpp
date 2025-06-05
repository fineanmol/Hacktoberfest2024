
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (int arr[], int low, int top)
{
	int pivot = arr[top]; 
	int i = (low - 1); 

	for (int j = low; j <= top - 1; j++)
	{
	
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[top]);
	return (i + 1);
}


void quickSort(int arr[], int low, int top)
{
	if (low < top)
	{
	
		int pi = partition(arr, low, top);

		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, top);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

