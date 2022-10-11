## https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

class Solution(object):
    def numOfStrings(self, patterns, word):
        count = 0
        for pattern in patterns:
            if pattern in word:
                count+=1
        return count