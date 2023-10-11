#include <iostream>
#include <vector>

// Function to solve the House Robber problem using a greedy approach
int robHouses(const std::vector<int>& houses) {
    int n = houses.size();
    
    if (n == 0) return 0;  // No houses to rob
    if (n == 1) return houses[0];  // Only one house to rob

    int prevMax = 0;  // Maximum stolen value for the previous house
    int currMax = 0;  // Maximum stolen value for the current house

    for (int i = 0; i < n; i++) {
        int temp = currMax;  // Temporary variable to store current maximum
        currMax = std::max(currMax, prevMax + houses[i]);  // Update current maximum
        prevMax = temp;  // Update previous maximum
    }

    return currMax;  // Return the maximum stolen value
}

int main() {
    std::vector<int> houses = {2, 7, 9, 3, 1};
    int maxStolen = robHouses(houses);

    std::cout << "The maximum stolen value is: " << maxStolen << std::endl;

    return 0;
}
