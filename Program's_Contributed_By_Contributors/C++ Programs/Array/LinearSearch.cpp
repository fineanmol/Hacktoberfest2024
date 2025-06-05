#include <iostream>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found
}

int main() {
    int n, key;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    int arr[n];

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the element you want to search for: ";
    std::cin >> key;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
