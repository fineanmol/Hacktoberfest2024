class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBrackets;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                int start = openBrackets.top();
                openBrackets.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        
        string ans;
        for (char c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            }
        }
        return ans;
    }
};