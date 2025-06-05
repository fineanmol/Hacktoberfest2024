class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 1) return "";

        int start = 0, end = 0;

        for(int i = 0; i < s.length(); i++){
            int len1 = expandingFromMiddle(s, i, i);
            int len2 = expandingFromMiddle(s, i, i + 1);
            int len = max(len1, len2);
            if(len > (end - start))
            {
                // Formula is found by considering i as centre and breaking it into half
                start = i - ((len - 1) / 2);
                end = i + (len/ 2);
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandingFromMiddle(string s, int left, int right)
    {
        if(left > right) return 0;
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - (left + 1);
        // At the end of the loop, left will be one index to the left of the start of the palindrome substring, and right will be one index to the right of the end of the palindrome substring. Therefore, to calculate the length of the palindrome, we subtract (left + 1) from right.For example, if the palindrome substring has a length of 5, the indices will be left - 1, left, center, right, and right + 1. So, the distance between right and (left + 1) will be 5. Hence, we return right - (left + 1) as the length of the palindrome substring found by the expandingFromMiddle function.
    }
};
