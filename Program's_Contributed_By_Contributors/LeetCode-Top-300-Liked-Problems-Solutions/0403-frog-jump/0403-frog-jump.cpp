class Solution {
public:
    unordered_map<int, int> mark;
    int dp[2001][2001];
    
    int solve(vector<int>& stones, int n, int index, int prevJump) {
        // If reached the last stone, return 1.
        if (index == n - 1) {
            return 1;
        }
        
        // If this subproblem has been already calculated, return it.
        if (dp[index][prevJump] != -1) {
            return dp[index][prevJump];  
        }
        
        int ans = false;
        // Iterate over the three possibilities {k - 1, k, k + 1}.
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0 && mark.find(stones[index] + nextJump) != mark.end()) {
                ans = ans || solve(stones, n, mark[stones[index] + nextJump], nextJump);
            }
        }

        // Store the result to fetch later.
        return dp[index][prevJump] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        // Mark stones in the map to identify if such stone exists or not.
        for (int i = 0 ; i < stones.size(); i++) {
            mark.insert({stones[i], i});
        }
        
        // Mark all states as -1 to denote they're not calculated.
        memset(dp, -1, sizeof(dp));
        return solve(stones, stones.size(), 0, 0);
    }
};