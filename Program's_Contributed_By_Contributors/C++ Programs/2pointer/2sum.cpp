#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (numMap.find(complement) != numMap.end()) {
            result.push_back(numMap[complement]);
            result.push_back(i);
            return result;
        }

        numMap[nums[i]] = i;
    }

    return result; // If no solution is found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices are: " << result[0] << " and " << result[1] << std::endl;
        std::cout << "Numbers are: " << nums[result[0]] << " and " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No solution found!" << std::endl;
    }

    return 0;
}
