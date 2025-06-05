class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007;
        // Cache to store sub-problem results.
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n + 1, 
                                            vector<vector<int>>(2, vector<int>(3, 0)));

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp[0][0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller sub-problem 
        // to generate results for bigger sub-problems.
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (int consecutiveLates = 0; consecutiveLates <= 2; ++consecutiveLates) {
                    // Store the count when 'P' is chosen.
                    dp[len + 1][totalAbsences][0] = (
                        dp[len + 1][totalAbsences][0] +
                        dp[len][totalAbsences][consecutiveLates]
                    ) % MOD;
                    // Store the count when 'A' is chosen.
                    if (totalAbsences < 1) {
                        dp[len + 1][totalAbsences + 1][0] = (
                            dp[len + 1][totalAbsences + 1][0] + 
                            dp[len][totalAbsences][consecutiveLates]
                        ) % MOD;
                    }
                    // Store the count when 'L' is chosen.
                    if (consecutiveLates < 2) {
                        dp[len + 1][totalAbsences][consecutiveLates + 1] = (
                            dp[len + 1][totalAbsences][consecutiveLates + 1] + 
                            dp[len][totalAbsences][consecutiveLates]
                        ) % MOD;
                    }
                }
            }
        }

        // Sum up the counts for all combinations of length 'n' with different absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (int consecutiveLates = 0; consecutiveLates <= 2; ++consecutiveLates) {
                count = (count + dp[n][totalAbsences][consecutiveLates]) % MOD;
            }
        }
        return count;
    }
};