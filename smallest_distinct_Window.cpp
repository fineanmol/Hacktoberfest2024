int findSubString(string s)
    {
        // Your code goes here   
        unordered_map<char,int>m;
        for(char c:s) m[c]++;
        int x = m.size();
        int j = 0;
        m.clear();
        int ans = s.length();
        m[s[0]]++;
        for(int i = 1;i<s.size();i++){
            m[s[i]]++;
            // while(m.size()==x){
            //     m[s[j]]--;
            //     ans = min(ans,i-j+1);
            //     if(m[s[j]]==0) {m[s[j]]++;break;}
            //     j++;
            // }
             if(m.size()==x){
               while(m[s[j]]>1){
                   m[s[j]]--;
                   j++;
               }
                ans=min(ans,i-j+1);
             }
        }
        return ans;
    }
