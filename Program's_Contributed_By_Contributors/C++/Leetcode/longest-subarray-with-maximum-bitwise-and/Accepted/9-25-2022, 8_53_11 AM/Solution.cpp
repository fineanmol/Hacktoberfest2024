// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target = *max_element(nums.begin(),nums.end());
        vector<int> indices;
        auto it = nums.begin();
        while ((it = find_if(it, nums.end(), [&] (int const &e) { return e == target; }))
            != nums.end())
        {
            indices.push_back(distance(nums.begin(), it));
            it++;
        }
        
        int maxcount = 1;
        int curr = 1;
        for (int i = 0;i<indices.size()-1;i++){
            if (indices[i+1] == indices[i]+1){
                curr++;
                maxcount = max(maxcount,curr);
            } else {
                curr = 1;
            }
        }
        
        return maxcount;
    }
};