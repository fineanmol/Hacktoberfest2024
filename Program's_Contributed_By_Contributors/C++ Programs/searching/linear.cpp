#include <iostream>
using namespace std;

int linear(int arr[], int n, int key) {
    int i;
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int main() {
    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 130;
    int result = linear(arr, n, key);
    (result == -1)
        ? cout << "Element " << key << " not found"
        : cout << "Element " << key << " found at index " << result;
}