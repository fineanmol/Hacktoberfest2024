/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> map;
        for (auto i : nums) {
            if (map.find(i) != map.end())
                return true;
            map[i] = 1;
        }
        return false;
    }
};