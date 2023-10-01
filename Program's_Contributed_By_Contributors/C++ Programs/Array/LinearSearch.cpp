#include <iostream>

// Function to perform linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target element if found
        }
    }
    return -1; // Return -1 if the target element is not found in the array
}

int main() {
    int arr[] = {5, 12, 25, 8, 15, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}
