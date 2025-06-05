#include <iostream>
using namespace std;

void merge(int array[], int lower, int mid, int upper) {
    int i = lower, k = lower, j = mid + 1;
    int b[lower + upper + 1];
    while (i <= mid && j <= upper) {
        if (array[i] <= array[j])
            b[k] = array[i++];
        else
            b[k] = array[j++];
        k++;
    }
    while (i <= mid)
        b[k++] = array[i++];
    while (j <= upper)
        b[k++] = array[j++];
    for (int k = lower; k <= upper; k++)
        array[k] = b[k];
}

void mergeSort(int array[], int lower, int upper) {
    if (lower < upper) {
        int mid = (lower + upper) / 2;
        mergeSort(array, lower, mid);
        mergeSort(array, mid + 1, upper);
        merge(array, lower, mid, upper);
    }
}

void show(int array[], int n) {
    for (int i = 0; i < n; i++)
        cout << array[i] << ' ';
    cout << endl;
}

int main() {
    int array[] = {10, 80, 30, 25, 90, 40, 50, 70, 12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);
    cout << "Before \t";
    show(array, n);
    mergeSort(array, 0, n - 1);
    cout << "Sorted array: \t";
    show(array, n);
    return 0;
}