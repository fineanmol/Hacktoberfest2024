class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        for(int i = 0; i < t.size(); i++){
            freq[t[i] - 'a']++;
            freq[s[i] - 'a']--;
        }
    
        int cnt = 0;

        for(int i = 0; i < 26; i++){
            cnt += max(0, freq[i]);
        }
        
        return cnt;
    }
};