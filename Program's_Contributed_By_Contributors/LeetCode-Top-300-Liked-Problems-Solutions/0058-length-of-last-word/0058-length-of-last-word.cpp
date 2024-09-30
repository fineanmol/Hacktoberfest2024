class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        int cnt = 0;

        while(s[n] == ' ')
            n--;
        
        int start = n;
        while(n >= 0 && s[n] != ' ' ){
            n--;
        }
        
        return start - n;
    }
};