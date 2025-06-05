#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 6, 6, 7};

    // Sort the vector to bring duplicates together
    std::sort(numbers.begin(), numbers.end());

    // Use std::unique to remove adjacent duplicates
    auto it = std::unique(numbers.begin(), numbers.end());

    // Erase the elements after the unique ones
    numbers.erase(it, numbers.end());

    // Print the vector with duplicates removed
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
