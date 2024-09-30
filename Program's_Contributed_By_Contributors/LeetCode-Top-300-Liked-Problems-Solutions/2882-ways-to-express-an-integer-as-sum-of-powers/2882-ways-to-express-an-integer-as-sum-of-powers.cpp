class Solution {
public:
    const int mod = 1e9 + 7;
    long long f(int ind , vector<long long>& v , int target , vector<vector<int>>& dp){
        if (ind == 0){
            if (target == v[0] || target == 0){
                return 1 ;
            }
            else {
                return 0 ;
            }
        }
        if (dp[ind][target] != -1){
            return dp[ind][target] ;
        }
        int not_take = f(ind-1 , v , target , dp) ;
        int take = 0 ;
        if (v[ind] <= target){
            take = f(ind-1 , v , target-v[ind] , dp) ;
        }
        return dp[ind][target] = (take+not_take)%mod ;
    }
    int numberOfWays(int n, int x) {
        vector<long long> v ;
        for (int i = 1 ; i <= n ; i++){
            long long num = 1 ;
            for (int j = 0 ; j < x ; j++){
                num *= i ;
            }
            if (num <= n){
                v.push_back(num) ;
            }
            else
                break;
        }
        int t = v.size() ;
        vector<vector<int>> dp(t , vector<int>(n+1 , -1)) ;
        long long count = f(t-1 , v , n , dp) ;
        return count ;
    }
};