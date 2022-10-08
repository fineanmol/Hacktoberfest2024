class Solution {
public:
    int subsetSum(vector<int>& nums, int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        
        for(int i = 0; i < n + 1; i++) {
            dp[i][0] = 1;
        }
    
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n  = nums.size();
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        int x = (sum + target) / 2;
        
        if((target + sum) % 2 != 0 || abs(target) > sum) {
            return 0;            
        }
        
        return subsetSum(nums, n, x);
    }
};
