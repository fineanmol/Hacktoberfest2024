class Solution {
public:
    // int f(int i, int j, vector<vector<int>> &dp){
    //     if(i == 0 && j == 0) 
    //         return dp[i][j] = 1;
    //     if(dp[i][j] != -1) 
    //         return dp[i][j];
    //     int up = 0, left = 0;
    //     if(i > 0) 
    //         up = f(i - 1, j, dp);
    //     if(j > 0) 
    //         left = f(i, j - 1, dp);
    //     return dp[i][j] = up + left;
    // }
    // int uniquePaths(int m, int n){
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return f(m - 1, n - 1, dp);
    // }

    //  // Tabulation
    //  int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     dp[0][0] = 1;
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //                 if (i > 0 || j > 0) { 
    //                 int up = 0, left = 0;
    //                 if (i > 0) up = dp[i - 1][j];
    //                 if (j > 0) left = dp[i][j - 1];
    //                 dp[i][j] = up + left;
    //             }    
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // int uniquePaths(int m, int n) {
    //     vector<int> prev(n, 0), curr(n, 0);
    //     curr[0] = 1;
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //                 if (i > 0 || j > 0) { 
    //                 int up = 0, left = 0;
    //                 if (i > 0) up = prev[j];
    //                 if (j > 0) left = curr[j - 1];
    //                 curr[j] = up + left;
    //             }    
    //         }
    //         prev = curr;
    //     }
    //     return prev[n-1];
    // }


    // // Space optimized
    // int uniquePaths(int m, int n) {
    //     vector<int> prev(n, 0), cur(n, 0);
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //             if(i == 0 && j == 0) cur[j] = 1;
    //             else{
    //                 int up = 0, left = 0;
    //                 if(i > 0) up = prev[j];
    //                 if(j > 0) left = cur[j - 1];
    //                 cur[j] = up + left;
    //             }    
    //         }
    //         prev = cur; 
    //     }
    //     return prev[n-1];
    // }

    int uniquePaths(int m, int n) {
        //Best approach T.C = O(n), S.C = O(1)
        double res = 1;// Combinations formula from Pascal triangle
        int N = n + m - 2; // n + m - 2 => No of possible steps 
        for(int i = 0; i < n - 1 ; i++){
            res = res * (N - i); 
            res /= (i + 1);
        }
        return round(res);
    }
};