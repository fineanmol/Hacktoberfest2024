class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0, lpf = 0;
        while(first < s.length() && lpf < t.length()){
            if(s[first] == t[lpf])
                lpf++;
            first++;
        }
        return t.length() - lpf;
    }
};