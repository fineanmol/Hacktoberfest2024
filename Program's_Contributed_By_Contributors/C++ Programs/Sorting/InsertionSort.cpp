#include <iostream>

using namespace std;

// Insertion Sort algorithm
int InsertionSort(int *arr, int size){
    int i, j, key;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return *arr;
}


int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, size);
    cout << "Sorted array: ";
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    
    return 0;
}