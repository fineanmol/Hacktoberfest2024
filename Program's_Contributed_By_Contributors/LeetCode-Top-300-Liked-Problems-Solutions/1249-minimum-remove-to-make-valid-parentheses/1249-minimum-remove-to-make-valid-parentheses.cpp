class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string res = "";

        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                ++cnt;
            else if (s[i] == ')') {
                if (cnt == 0)
                    s[i] = '#';
                else
                    --cnt;
            }
        }

        cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')')
                ++cnt;
            else if (s[i] == '(') {
                if (cnt == 0)
                    s[i] = '#';
                else
                    --cnt;
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '#')
                res.push_back(s[i]);
        }

        return res;
    }
};