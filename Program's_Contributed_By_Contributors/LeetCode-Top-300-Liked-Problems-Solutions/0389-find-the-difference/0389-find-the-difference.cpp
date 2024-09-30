class Solution {
public:
    // char findTheDifference(string s, string t) {
    //     unordered_map<char, int> mp;
    //     char ans;
    //     for(char c : s){
    //         mp[c]++;
    //     }
    //     for(char c : t){
    //         if(mp.find(c) == mp.end() || mp[c] == 0)
    //         {
    //             ans = c;
    //             break;  
    //         }
    //         mp[c]--;
    //     }
    //     return ans;
    // }

    char findTheDifference(string s, string t) {
        int c1 = 0, c2 = 0;
        for(int i = 0; i < s.length(); i++) 
            c1 += s[i];
        for(int i = 0; i < t.length(); i++) 
            c2 += t[i];

        return (char)(c2 - c1);
    }
};