class Solution {
public:

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, (right - 1) - (left + 1) + 1);
}

string longestPalindrome(string s) {
        int n = s.length();
        string longest = "";

        for(int i = 0; i < n; i++){
            string oddPal = expandAroundCenter(s, i, i);
            string evenPal = expandAroundCenter(s, i, i + 1);

            if(oddPal.length() > longest.length())
                longest = oddPal;
            
            if(evenPal.length() > longest.length())
                longest = evenPal;
        }

        return longest;
    }


};