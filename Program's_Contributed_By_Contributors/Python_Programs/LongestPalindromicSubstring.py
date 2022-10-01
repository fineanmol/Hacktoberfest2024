//Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/

class Solution:
    def countPalindromeAroundCenter(self, lo: int, hi: int, s: str) -> str:
        while lo >= 0 and hi < len(s):
            if s[lo] != s[hi]:
                break
            lo -= 1
            hi += 1
        res = s[(lo+1):hi]
        return res
                
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        for i in range (len(s)):
            s1 = self.countPalindromeAroundCenter(i, i, s)
            s2 = self.countPalindromeAroundCenter(i, i + 1, s)
            if len(s1) > len(ans):
                ans = s1
            if len(s2) > len(ans):
                ans = s2
        return ans
