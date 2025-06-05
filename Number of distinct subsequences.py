class Solution:
    def distinctSubsequences(self, S):
        mod = 10**9 + 7
        n = len(S)
        dp = [0] * (n + 1)
        dp[0] = 1
        map = {}
        
        for i in range(1, n + 1):
            ch = S[i - 1]
            dp[i] = (2 * dp[i - 1]) % mod
            
            if ch in map:
                ind = map[ch]
                dp[i] = (dp[i] - dp[ind - 1] + mod) % mod
            
            map[ch] = i
        
        return dp[n]
