#include <bits/stdc++.h>
using namespace std;

void selection(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}
int main()
{
	int arr[6] = {5, 4, 3, 7, 1, 2};
	int size = 6;
	selection(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
