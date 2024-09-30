class Solution {
public:
    int f(int i, vector<vector<int>>& pairs, vector<int> &dp){
        int n = pairs.size();
        if(i > n)
            return 0;
        
        if(dp[i] != -1) return dp[i];

        int count = 1;
        for(int j = i + 1; j < n; j++){
            if(pairs[i][1] < pairs[j][0])
                count = max(count, 1 + f(j, pairs, dp));
        }
        return dp[i] = count;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size(), ans = 0;
        vector<int> dp(n + 1, -1);
        for(int i = 0; i < n; i++){
            ans = max(ans, f(i, pairs, dp));
        }
        return ans;
    }
};