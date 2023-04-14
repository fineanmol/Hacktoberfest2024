// https://leetcode.com/problems/find-pivot-index/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        // sum of all elements
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == sum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};