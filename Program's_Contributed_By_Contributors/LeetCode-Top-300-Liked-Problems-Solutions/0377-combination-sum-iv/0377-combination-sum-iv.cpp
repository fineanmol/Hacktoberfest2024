class Solution {
public:
    int f(int i, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(target == 0)
            return 1;
        if(i >= nums.size() || target < 0)
            return 0;
        
        if(dp[i][target] != -1) return dp[i][target];

        int take = f(0, nums, target - nums[i], dp);
        int notTake = f(i + 1, nums, target, dp);

        return dp[i][target] = take + notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(0, nums, target, dp);
    }
};