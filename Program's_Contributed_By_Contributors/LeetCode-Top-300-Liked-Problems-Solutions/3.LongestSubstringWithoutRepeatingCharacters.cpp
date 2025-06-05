 // Using map
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> mpp;
        int left = 0, right = 0;

        while (right < n) {
            if (mpp.find(s[right]) != mpp.end())
                left = max(mpp[s[right]] + 1, left); // moving left ptr only if the current left value was less than the previous occurrence of the current character

            mpp[s[right]] = right; // Mapping the occurrence of a character

            maxLength = max(maxLength, right - left + 1);

            right++; // Moving to the next character
        }

        return maxLength;
    }
