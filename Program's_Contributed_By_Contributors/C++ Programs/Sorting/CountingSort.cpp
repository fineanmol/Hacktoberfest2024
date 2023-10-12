#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n) {
    if (n <= 0) return;

    int max = *max_element(arr, arr + n);
    int min = *min_element(arr, arr + n);
    int range = max - min + 1;

    int count[range] = {0};
    int output[n];

    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    copy(output, output + n, arr);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:" << endl;
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Sorted Array:" << endl;
    printArray(arr, n);

    return 0;
}
