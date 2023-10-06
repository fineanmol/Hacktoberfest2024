/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

https://leetcode.com/problems/valid-palindrome/
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        // Remove non-alphanumeric characters and convert to lowercase
        string cleanedString;
        for (char c : s) {
            if (isalnum(c)) {
                cleanedString += tolower(c);
            }
        }
        
        left = 0;
        right = cleanedString.length() - 1;
        
        while (left <= right) {
            if (cleanedString[left] != cleanedString[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};