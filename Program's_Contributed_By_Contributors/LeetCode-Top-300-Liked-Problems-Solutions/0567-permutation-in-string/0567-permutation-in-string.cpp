class Solution {
public:
    // Brute Force
    // void permutations(int ind, int n, string s, vector<string> &perms){
    //     if(ind == n) {
    //         perms.push_back(s);
    //         return;
    //     }
    //     for(int i = ind; i < n; i++){
    //         swap(s[ind], s[i]);
    //         permutations(ind + 1, n, s, perms);
    //         swap(s[ind], s[i]);
    //     }
    // }
    // bool checkInclusion(string s1, string s2) {
    //     vector<string> perms;
    //     permutations(0, s1.size(), s1, perms);
    //     for(auto c : perms){
    //         if(s2.find(c) != string::npos) 
    //             return true;
    //     }
    //     return false;
    // }

    // Optimal - from 438) find all anagrams in a string 

    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.length();
        int s2Len = s2.length();
        
        if (s1Len > s2Len)
            return false;
        
        unordered_map<char, int> s1Freq, s2Freq;
        
        for (char c : s1)
            s1Freq[c]++;
        
        for (int i = 0; i < s1Len; i++)
            s2Freq[s2[i]]++;
        
        if (s1Freq == s2Freq)
            return true;
        
        for (int i = s1Len; i < s2Len; i++) {
            s2Freq[s2[i - s1Len]]--;
            if (s2Freq[s2[i - s1Len]] == 0)
                s2Freq.erase(s2[i - s1Len]);
            
            s2Freq[s2[i]]++;
            
            if (s1Freq == s2Freq)
                return true;
        }
        
        return false;
    }
};