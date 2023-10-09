#include <iostream>
using namespace std;

void insertionSort(int array[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = array[i];
       
        for (j = i - 1; (j >= 0 && array[j] > key); j--)
            array[j + 1] = array[j];
        array[j + 1] = key;
    }
}

void show(int array[], int n) {
    for (int i = 0; i < n; i++)
        cout << array[i] << ' ';
    cout << endl;
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);
    cout << "Before : \t";
    show(array, n);
    insertionSort(array, n);
    cout << "Sorted : \t";
    show(array, n);
    return 0;
}