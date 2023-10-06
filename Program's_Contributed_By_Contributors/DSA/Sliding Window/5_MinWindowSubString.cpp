/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

https://leetcode.com/problems/minimum-window-substring/description/
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreq;
        unordered_map<char, int> windowFreq;

        // Initialize the frequency map for string t
        for (char c : t) {
            targetFreq[c]++;
        }

        int left = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        int matchedChars = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // Update the frequency of the current character in the window
            windowFreq[currentChar]++;

            // Check if the current character is in string t and its count in the window is not exceeding the target count
            if (targetFreq.find(currentChar) != targetFreq.end() &&
                windowFreq[currentChar] <= targetFreq[currentChar]) {
                matchedChars++;
            }

            // Try to minimize the window size by moving the left pointer
            while (left <= right && matchedChars == t.length()) {
                // Update the minimum window size
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Move the left pointer and update the window frequency
                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (targetFreq.find(leftChar) != targetFreq.end() &&
                    windowFreq[leftChar] < targetFreq[leftChar]) {
                    matchedChars--;
                }

                left++;
            }
        }

        // Check if a valid window was found
        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(minLeft, minLen);
    }
};