class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string t = "", ans = "";
        int cnt = 0;
        for(int i = 0; i < n; i++){
            t += s[i];
            if(s[i] == '(') cnt += 1;
            else cnt -= 1;
            if(cnt == 0){
                ans += t.substr(1, t.length() - 2);
                t = "";
            }
        }
        return ans;
    }
};