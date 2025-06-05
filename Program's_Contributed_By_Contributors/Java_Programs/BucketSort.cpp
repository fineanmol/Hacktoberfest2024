#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(float arr[], int n) {
    std::vector<float> bucket[n];
    
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        bucket[bucketIndex].push_back(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        std::sort(bucket[i].begin(), bucket[i].end());
    }
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() {
    float arr[] = { 0.42, 0.32, 0.52, 0.12, 0.62, 0.92 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
