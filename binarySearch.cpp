#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void insertSorted(int arr[], int &size, int element) {
    int i = size - 1;
    while (i >= 0 && arr[i] > element) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
    size++;
}

void deleteAtIndex(int arr[], int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index for deletion." << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the target element: ";
    cin >> target;

    int foundIndex = binarySearch(arr, size, target);
    if (foundIndex != -1) {
        deleteAtIndex(arr, size, foundIndex);
    } else {
        insertSorted(arr, size, target);
    }

    cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
