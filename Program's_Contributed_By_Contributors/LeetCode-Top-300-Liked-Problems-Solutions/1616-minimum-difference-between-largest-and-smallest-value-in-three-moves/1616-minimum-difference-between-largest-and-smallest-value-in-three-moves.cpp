class Solution {
public:
    int minDifference(vector<int>& nums) {
        int numSize = nums.size();

        if(nums.size() <= 4) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        for(int left = 0, right = numSize - 4; left < 4; left++, right++)
            minDiff = min(minDiff, nums[right] - nums[left]);
        
        return minDiff;
    }
};