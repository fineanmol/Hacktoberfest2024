/*
Given a string s, find the length of the longest substring without repeating characters.

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

class Solution {
public:
    bool isPresent(vector<char> chars, char c) {
        return find(chars.begin(), chars.end(), c) != chars.end();
    }
    int lengthOfLongestSubstring(string s) {
        vector<char> chars;
        int count = 0, maxCount = 0;

        for (char i : s) {
            if (!isPresent(chars, i)) {
                chars.push_back(i);
                count++;
            } else {
                // Find the index of the repeating character and remove all characters before it.
                auto it = find(chars.begin(), chars.end(), i);
                chars.erase(chars.begin(), it + 1);
                chars.push_back(i);
                count = chars.size();
            }

            if (count > maxCount) {
                maxCount = count;
            }
        }

        return maxCount;
    }
};