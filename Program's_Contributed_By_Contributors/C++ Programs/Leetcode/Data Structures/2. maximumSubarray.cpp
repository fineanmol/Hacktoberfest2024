#include <bits/stdc++.h>
#include <math.h>

using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=nums[0];
        int cur_sum=max_sum;

        for (int i=1; i<nums.size();i++){
            cur_sum = max(nums[i], cur_sum+nums[i]);
            max_sum = max(max_sum, cur_sum);
        }        
        return max_sum;
    }
};