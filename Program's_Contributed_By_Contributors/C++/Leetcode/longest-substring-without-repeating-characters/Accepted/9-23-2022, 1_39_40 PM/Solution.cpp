// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> index;
        
        
        int si=0,ei=0,maxSize = 0;
        
        for (int ei = 0;ei<s.size();ei++){
                
            if (index.find(s[ei])!=index.end()){
                si = max(si,index[s[ei]]+1);
            }
            
            maxSize = max(maxSize,ei-si+1);
            index[s[ei]] = ei;
        }
        
        return maxSize;
    }
};