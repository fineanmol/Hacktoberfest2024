class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        vector<int> dp(n + 1, 0);

        // Set base cases
        for (int i = 0; i <= 3; i++) {
            dp[i] = i;
        }
        
        for (int num = 4; num <= n; num++) {
            int ans = num;
            for (int i = 2; i < num; i++) {
                ans = max(ans, i * dp[num - i]);
            }
            
            dp[num] = ans;
        }
        
        return dp[n];
    }
};