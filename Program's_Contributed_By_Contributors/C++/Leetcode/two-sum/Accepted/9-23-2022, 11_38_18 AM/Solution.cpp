// https://leetcode.com/problems/two-sum

#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        for (int i = 0;i<nums.size();i++){
            if (map.find(target-nums[i])!=map.end()){
                // cout<<map[nums[i]]
                result = {i,map[target-nums[i]]};
                break;
            }
            map[nums[i]] = i;
            
            
        }
        return result;
    }
};