class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_freq;
        for (char c : s) {
            char_freq[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (char_freq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};