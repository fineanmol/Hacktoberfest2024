class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), maxLen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mp;

        while (r < n) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l); // moving left ptr only if the current left value was less than the previous occurance of current character
            }
            maxLen = max(maxLen, r - l + 1); 
            mp[s[r]] = r;
            r++;
            if(n - l - 1 < maxLen) break;
        }

        return maxLen;
    }
};
