class Solution {
public:
    string getHint(string s, string g) {
        int bulls = 0, cows = 0;
        map<char, int> mp;
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == g[i])
                bulls++;
            else{
                mp[s[i]]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] != g[i]){
                if(mp[g[i]]-- > 0)
                    cows++;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};