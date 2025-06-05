#include <iostream>
using namespace std;

int maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void countSort(int arr[], int n, int pos) {
    int output[n]; 
    int i, count[10] = { 0 };


    for (i=0; i<n; i++)
        count[(arr[i]/pos)%10]++;


    for (i=1; i<10; i++)
        count[i] += count[i-1];

    for (i=n-1; i>=0; i--)
        output[--count[(arr[i]/pos)%10]] = arr[i];

   
    for (i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {

    int max = maximum(arr, n);
   
    for (int pos=1; max/pos > 0; pos*=10)
        countSort(arr, n, pos);
}

void show(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {141, 456, 342, 789, 90, 2, 870, 192, 938, 243};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before \t";
    show(arr, n);
    radixSort(arr, n);
    cout << "Sorted array: \t";
    show(arr, n);
    return 0;
}