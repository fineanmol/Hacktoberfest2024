#include <iostream>

using namespace std;

// Bubble Sort algorithm
int BubbleShort(int a[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
    return -1;
}


int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleShort(arr, n);
    cout << "Sorted array: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}