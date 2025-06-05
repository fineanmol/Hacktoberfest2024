class Solution {
public:
    // Brute force
    // bool isAnagram(string s, string t){
    //     unordered_map<char, int> mp;

    //     for(char c : s) mp[c]++;

    //     for(char c : t){
    //         mp[c]--;
    //         if(mp[c] < 0) return false;
    //     }
    //     return true;
    // }
    // vector<int> findAnagrams(string s, string p) {
    //     int n1 = s.length(), n2 = p.length();
    //     vector<int> ans;
    //     if(n2 > n1) return ans; 
    //     for(int i = 0; i <= n1 - n2; i++){
    //         string sub = s.substr(i, n2);
    //         if(isAnagram(sub, p))
    //             ans.push_back(i);
    //     }
    //     return ans;
    // }

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sLen = s.length();
        int pLen = p.length();
        
        if (sLen < pLen)
            return result;
        
        unordered_map<char, int> pFreq, sFreq;
        
        for (char c : p)
            pFreq[c]++;
        
        for (int i = 0; i < pLen; i++)
            sFreq[s[i]]++;
        
        if (sFreq == pFreq)
            result.push_back(0);
        
        for (int i = pLen; i < sLen; i++) {
            sFreq[s[i - pLen]]--;
            if (sFreq[s[i - pLen]] == 0)
                sFreq.erase(s[i - pLen]);
            
            sFreq[s[i]]++;
            
            if (sFreq == pFreq)
                result.push_back(i - pLen + 1);
        }
        
        return result;
    }
};