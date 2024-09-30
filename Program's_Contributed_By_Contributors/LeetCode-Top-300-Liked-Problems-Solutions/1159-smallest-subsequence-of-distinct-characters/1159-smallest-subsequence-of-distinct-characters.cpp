class Solution {
public:
    string smallestSubsequence(string s) {
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