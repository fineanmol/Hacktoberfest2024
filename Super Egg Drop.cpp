class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[N+1][K+1] ; 
        memset(dp , 0 , sizeof dp) ; 
        int m = 0 ; 
        while(dp[m][K] < N){
            ++m;
            for(int k = 1 ; k <= K ; ++k){
                dp[m][k] = 1 + dp[m-1][k - 1 ] + dp[m-1][k] ; 
            }
        }
        return m;
    }
};
