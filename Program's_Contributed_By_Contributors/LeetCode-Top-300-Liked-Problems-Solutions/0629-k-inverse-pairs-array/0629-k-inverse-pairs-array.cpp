class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k + 1, 0);
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            vector<int> tmp(k + 1, 0);
            tmp[0] = 1;
            for (int j = 1; j <= k; j++) {
                long long val =
                    (dp[j] + mod - ((j - i) >= 0 ? dp[j - i] : 0)) % mod;
                tmp[j] = (tmp[j - 1] + val) % mod;
            }
            dp = tmp;
        }
        return (dp[k] + mod - (k > 0 ? dp[k - 1] : 0)) % mod;
    }
};