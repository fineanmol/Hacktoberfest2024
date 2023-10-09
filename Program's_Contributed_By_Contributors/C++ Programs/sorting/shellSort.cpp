#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap=n/2; gap>=1; gap/=2)
       
        for (i=gap; i<n; i++) {
            temp = arr[i];

            for (j=i; j>=gap && arr[j-gap] > temp; j-=gap)
                arr[j] = arr[j-gap];
        
            arr[j] = temp;
        }
}

void show(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 64, 34, 25, 22, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before \t";
    show(arr, n);
    shellSort(arr, n);
    cout << "Sorted array: \t";
    show(arr, n);
    return 0;
}