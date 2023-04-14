// https://leetcode.com/problems/running-sum-of-1d-array/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result={};
        int sum = 0;
        for (auto i:nums){
            sum+=i;
            result.push_back(sum);
        }
        return result;        
    }
};      