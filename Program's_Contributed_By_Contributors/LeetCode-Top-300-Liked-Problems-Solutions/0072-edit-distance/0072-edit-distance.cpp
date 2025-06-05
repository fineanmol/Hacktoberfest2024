class Solution {
public:
    // Memoization
    // int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    //     if(i < 0) return j + 1;
    //     if(j < 0) return i + 1;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == t[j]) return dp[i][j] = 0 + f(i - 1, j - 1, s, t, dp);

    //     return dp[i][j] = 1 + min(f(i - 1, j - 1, s, t, dp), min(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp)));
    // }
    // int minDistance(string s, string t){
    //     int n = s.length(), m = t.length();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     return f(n - 1, m - 1, s, t, dp);
    // }

    // Tabulation
    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]) dp[i][j] = 0 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }

        return dp[n][m];

    }


    // // Space Optimization
    // int minDistance(string s, string t) {
    //     int n = s.length(), m = t.length();
    //     vector<int> prev(m + 1, 0), cur(m + 1, 0);
    //     for(int j = 0; j <= m; j++) prev[j] = j;

    //     for(int i = 1; i <= n; i++){
    //         cur[0] = i; // Base case for if(j == 0) in tabulation method
    //         for(int j = 1; j <= m; j++){
    //             if(s[i - 1] == t[j - 1]) 
    //                 cur[j] = prev[j - 1];
    //             else 
    //                 cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
    //         }
    //         prev = cur;
    //     }

    //     return prev[m];

    // }
};