#include <iostream>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the target is found
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {12, 34, 56, 78, 90, 23, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    std::cout << "Enter the element you want to search for: ";
    std::cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
