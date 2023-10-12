#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bucketSort(double arr[], int n) {
    if (n <= 0) return;

    vector<double> buckets[n];

    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (double value : buckets[i]) {
            arr[index] = value;
            index++;
        }
    }
}

int main() {
    double arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:" << endl;
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Sorted Array:" << endl;
    printArray(arr, n);

    return 0;
}
