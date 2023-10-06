/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> index_map;

        for (int index = 0;; index++) {
            auto iter = index_map.find(target - nums[index]);

            if (iter != index_map.end())
                return vector<int> {index, iter -> second};

            index_map[nums[index]] = index;
        }
    }
};