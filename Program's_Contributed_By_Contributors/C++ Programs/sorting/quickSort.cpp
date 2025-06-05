#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int partition(int arr[], int lb, int ub) {
    int start = lb, end = ub;
    int pivot = arr[lb];
    while (start < end) {
        while (arr[start] <= pivot && start < ub)
            start++;
        while (arr[end] > pivot && end > lb)
            end--;
        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[lb], &arr[end]); 
    return end;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
      
        int pi = partition(arr, lb, ub);
       
        quickSort(arr, lb, pi - 1);
        quickSort(arr, pi + 1, ub);
    }
}

void show(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {10, 80, 30, 25, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before \t";
    show(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \t";
    show(arr, n);
    return 0;
}