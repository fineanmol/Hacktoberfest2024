class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), l = 0, r = 0, minLen = INT_MAX, startIndex = -1;
        vector<int> freq(256, 0);
        int cnt = 0;
        for(char c : t)
            freq[c]++;

        while(r < n){
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;

            while(cnt == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    startIndex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt -= 1;
                l++;
            }
            r++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};