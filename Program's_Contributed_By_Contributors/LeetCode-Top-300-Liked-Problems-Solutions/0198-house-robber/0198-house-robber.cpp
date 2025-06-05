class Solution {
public:
    // // Memoization approach 
    // int f(int ind, vector<int> &nums, vector<int> &dp){
    //     if(ind == 0) nums[ind];
    //     if(ind < 0) return 0;

    //     if(dp[ind] != -1) return dp[ind];

    //     int pick = nums[ind] + f(ind - 2, nums, dp);
    //     int npick = f(ind - 1, nums, dp);

    //     return dp[ind] = max(pick, npick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     return f(n - 1, nums, dp);
    // }

        // //Tabulation
        // int rob(vector<int>& nums){
        //     int n = nums.size();
        //     vector<int> dp(n, 0);
        //     dp[0] = nums[0];
            
        //     for(int i = 1; i < n; i++){
        //         int pick = nums[i];
        //         if(i > 1) pick += dp[i - 2];
        //         int npick = dp[i - 1];

        //         dp[i] = max(pick, npick);
        //     }
        //     return dp[n - 1];
        // }

        // Space optimization
        int rob(vector<int>& nums){
            int n = nums.size();
            int prev = nums[0];
            int prev2 = 0;

            for(int i = 1; i < n; i++){
                int pick = nums[i];
                if(i > 1) pick += prev2;
                int npick = prev;

                int cur = max(pick, npick);
                prev2 = prev;
                prev = cur;
            }
            return prev;
        }
};