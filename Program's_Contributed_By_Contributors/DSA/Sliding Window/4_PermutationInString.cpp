/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

https://leetcode.com/problems/permutation-in-string/
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> count(26, 0);  // Character count for s1
        for (char c : s1) {
            count[c - 'a']++;
        }
        int left = 0, right = 0;
        int remaining_chars = s1.length();
        while (right < s2.length()) {
            if (count[s2[right] - 'a'] > 0) {
                remaining_chars--;
            }
            count[s2[right] - 'a']--;
            right++;
            if (remaining_chars == 0) {
                return true;
            }
            if (right - left == s1.length()) {
                count[s2[left] - 'a']++;
                if (count[s2[left] - 'a'] > 0) {
                    remaining_chars++;
                }
                left++;
            }
        }
        return false;
    }
};