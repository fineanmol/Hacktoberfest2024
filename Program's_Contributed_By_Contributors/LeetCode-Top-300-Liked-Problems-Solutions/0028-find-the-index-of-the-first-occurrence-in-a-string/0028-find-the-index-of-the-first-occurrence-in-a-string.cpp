class Solution {
private:

public:
    int strStr(string haystack, string needle) {
        // Z-function 
        if(needle.length() == 0) return 0;
        int hayLen = haystack.length(), needleLen = needle.length();
        if(needleLen > hayLen) return -1;
        for(int i = 0; i <= hayLen - needleLen; i++)
        {
            int j;
            for(j = 0; j < needleLen; j++)
            {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == needleLen) 
                return i;
        }
        return -1;
    }
    
};