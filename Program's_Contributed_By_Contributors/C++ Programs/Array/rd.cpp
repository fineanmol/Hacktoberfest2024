#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> removeDuplicates(std::vector<int>& nums) {
    // Sort the array to bring duplicates together
    std::sort(nums.begin(), nums.end());

    // Use unique algorithm to move duplicates to the end
    auto last = std::unique(nums.begin(), nums.end());

    // Resize the vector to remove duplicates
    nums.erase(last, nums.end());

    return nums;
}

int main() {
    std::vector<int> nums = {1, 3, 2, 2, 4, 1, 5, 3, 6};

    std::cout << "Original array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> result = removeDuplicates(nums);

    std::cout << "Array after removing duplicates: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
