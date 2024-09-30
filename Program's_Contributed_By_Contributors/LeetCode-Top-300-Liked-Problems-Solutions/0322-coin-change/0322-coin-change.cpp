class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,amount + 1);
        dp[0] = 0;
        for(int c : coins){
            for(int j = c; j <= amount; j++){
                dp[j] = min(dp[j], 1 + dp[j - c]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};