class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> mp1, mp2;
        for(int i = 0; i < s.length(); i++)
        {   
            if(mp1[s[i]] && mp1[s[i]] != t[i]) return false;
            if(mp2[t[i]] && mp2[t[i]] != s[i]) return false;
            // Mapping one character of an index in a string to another character of that same index in another string
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};