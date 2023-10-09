#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, max;
    for (i = n-1; i>0; i--) {
        max = 0;
        for (j = 1; j <= i; j++)
            if (arr[j] > arr[max])
                max = j;
        if (max != i)
            swap(&arr[max], &arr[i]);

    }
}

void show(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before \t";
    show(arr, n);
    selectionSort(arr, n);
    cout << "Sorted array: \t";
    show(arr, n);
    return 0;
}