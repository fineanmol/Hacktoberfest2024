class Solution {
public:
    int countVowels(string s){
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                cnt += 1;
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        return countVowels(s.substr(0, n / 2)) == countVowels(s.substr(n / 2, n / 2));
    }
};