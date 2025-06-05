class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int openBrackets = 0;

        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else if (c == ')') {
                openBrackets--;
            }
            
            ans = max(ans, openBrackets);
        }
        
        return ans;
    }
};