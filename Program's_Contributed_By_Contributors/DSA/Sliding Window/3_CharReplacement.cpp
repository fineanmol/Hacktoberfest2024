/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

https://leetcode.com/problems/longest-repeating-character-replacement/
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_length = 0;
        int max_count = 0;
        vector<int> char_count(26, 0);
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            char_count[s[right] - 'A']++;
            max_count = max(max_count, char_count[s[right] - 'A']);

            if ((right - left + 1 - max_count) > k) {
                char_count[s[left] - 'A']--;
                left++;
            }

            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};