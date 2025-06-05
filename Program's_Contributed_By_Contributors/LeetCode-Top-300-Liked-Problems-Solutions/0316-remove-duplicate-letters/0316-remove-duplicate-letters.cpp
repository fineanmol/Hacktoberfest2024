class Solution {
public:
    // Brute force : TLE - 270 / 290 passed
    // bool isSubsequence(string s, string t) {
    //     int n = s.length(), m = t.length();
    //     int i = 0, j = 0;

    //     while(i < n && j < m){
    //         if(s[i] == t[j]){
    //             i++;
    //             j++;
    //         }
    //         else{
    //             j++;
    //         }
    //     }

    //     return i == n;
    // }

    // string removeDuplicateLetters(string s) {
    //     set<char> st;
    //     int cnt = 0;
    //     string ans;
    //     for(char c : s){
    //         if(st.find(c) == st.end()){
    //             cnt += 1;
    //             ans += c;
    //         }
    //         st.insert(c);
    //     }

    //     cout << ans;

    //     sort(ans.begin(), ans.end());
        
    //     do{
    //         if(isSubsequence(ans, s))
    //         {
    //             break;
    //         }
    //     }while(next_permutation(ans.begin(), ans.end()));

    //     return ans;
    // }

    string removeDuplicateLetters(string s){
        vector<int> last(26, 0);
        vector<bool> vis(26, false);
        string ans;

        for(int i = 0; i < s.length(); i++)
            last[s[i] - 'a'] = i;
        
        for(int i = 0; i < s.length(); i++){
            if(vis[s[i] - 'a']) continue;

            while(!ans.empty() && ans.back() > s[i] && last[ans.back() - 'a'] > i){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            vis[ans.back() - 'a'] = true;
        }

        return ans;
    }
};