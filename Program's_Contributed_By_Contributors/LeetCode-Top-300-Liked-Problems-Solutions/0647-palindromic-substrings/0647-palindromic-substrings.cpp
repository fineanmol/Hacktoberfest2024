class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int even = palindromeCount(s, i, i + 1);
            int odd = palindromeCount(s, i - 1, i + 1);
            ans += even + odd + 1;
        }
        return ans;
    }

    int palindromeCount(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left--] == s[right++]) {
            count += 1;
        }
        return count;
    }
};