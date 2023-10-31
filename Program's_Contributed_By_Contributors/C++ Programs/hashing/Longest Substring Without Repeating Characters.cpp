class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int j=0;
        int ans=0;
        map<char,int> m;
        int maximum=0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            ans++;
            if(m[s[i]]>1){
                while(m[s[i]]>1){
                    m[s[j++]]--;
                    ans--;
                }
            }
            maximum=max(ans,maximum);
        }
        return maximum;
    }
};
