class Solution {
public:
    string countAndSay(int n, string s = "1") {
        if(n==1)
            return s;
        int i=0,j,len = s.size();
        string ans = "";
            while(i<len)
            {
                j = i;
                while(i<len && s[i]==s[j])
                    i++;
                ans += to_string(i-j) + s[j];
            }
            return countAndSay(n-1,ans);
    }
};
