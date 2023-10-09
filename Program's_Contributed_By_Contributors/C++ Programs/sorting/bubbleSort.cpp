#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}

void show(int array[], int n) {
    for (int i = 0; i < n; i++)
        cout << array[i] << ' ';
    cout << endl;
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);
    cout << "Before: \t";
    show(array, n);
    bubbleSort(array, n);
    cout << "Sorted: \t";
    show(array, n);
    return 0;
}