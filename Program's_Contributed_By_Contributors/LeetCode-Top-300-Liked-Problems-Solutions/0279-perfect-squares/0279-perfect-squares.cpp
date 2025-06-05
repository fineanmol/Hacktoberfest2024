class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                int notTake = dp[i]; // Not including that perfect square num
                int take = 1 + dp[i - j * j]; // Including that perfect square num
                dp[i] = min(take, notTake);
            }
        }

        return dp[n];
    }
};