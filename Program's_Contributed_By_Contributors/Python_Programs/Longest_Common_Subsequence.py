# Problem Description:- Longest_Common_Subsequence
#Link:- https://leetcode.com/problems/longest-common-subsequence/


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        m = len(text2)
        n = len(text1)
        
        memo = [[0 for j in range(m+1)] for i in range(n+1)]
        
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                
                if text1[i] == text2[j]:
                    memo[i][j] = 1 + memo[i+1][j+1]
                    
                else:
                    memo[i][j] = max(memo[i+1][j],memo[i][j+1])
           
        return memo[0][0]

