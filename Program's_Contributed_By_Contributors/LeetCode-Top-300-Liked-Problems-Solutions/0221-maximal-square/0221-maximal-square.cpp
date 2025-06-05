class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxi = max(maxi, dp[i][0]);
        }
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i] - '0';
            maxi = max(maxi, dp[0][i]);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi * maxi;
    }
};