#include <iostream>
using namespace std;

int binary(int arr[], int key, int start, int end) {
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int Recursive(int arr[], int key, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            return Recursive(arr, key, mid + 1, end);
        else
            return Recursive(arr, key, start, mid - 1);
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 50, 60, 80, 100, 110, 130, 170};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 100;
    int result = binary(arr, key, 0, n - 1);
    (result == -1)
        ? cout << "Element " << key << " not found"
        : cout << "Element " << key << " found at index " << result;
    cout << endl;
    
    key = 20;
    result = Recursive(arr, key, 0, n - 1);
    (result == -1)
        ? cout << "Element " << key << " not found"
        : cout << "Element " << key << " found at index " << result;
}