#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int main_array[], int n)
{
	int i, j, flag;
	for (i = 0; i < n - 1; i++) {
		flag = 0;
		for (j = 0; j < n - i - 1; j++) {
			if (main_array[j] > main_array[j + 1]) {
				swap(main_array[j], main_array[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void printer(int main_array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << " " << main_array[i];
}

int main()
{
	int main_array[] = { 4, 134, 5, 2, 22, 111, 0 };
	int size = sizeof(main_array) / sizeof(main_array[0]);
	bubbleSort(main_array, size);
	cout << "Sorted array: \n";
	printer(main_array, size);
	return 0;
}
