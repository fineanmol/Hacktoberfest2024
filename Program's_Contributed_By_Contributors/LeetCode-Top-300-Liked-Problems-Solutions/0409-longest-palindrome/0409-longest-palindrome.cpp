class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;

        int len = 0, cnt = 0;
        for(auto it : mp){
            if(it.second % 2 == 0)
                len += it.second;
            else{
                len += it.second - 1;
                cnt++;
            }
        }

        if (cnt > 0)
            return len + 1;
        return len;
    }
};