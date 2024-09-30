class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> map1(26, 0), map2(26, 0);
        for (char c : word1) {
            map1[c - 'a']++;
        }
        for (char c : word2) {
            map2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            // Since we can only replace an existing character in both strings, if a character doesnt exist in one but exist in other, it is not close
            if ((map1[i] == 0 && map2[i] != 0) || (map1[i] != 0 && map2[i] == 0)) {
                return false;
            }
        }
        sort(map1.begin(), map1.end());
        sort(map2.begin(), map2.end());
        return map1 == map2;
    }
};