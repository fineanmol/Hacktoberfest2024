class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2) return false;
        
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;

        for (int i = 0; i <= length; i++) {
            // Count open parentheses or asterisks
            if (s[i] == '(' || locked[i] == '0') {
                openCount++;
            } else {
                openCount--;
            }
            
            // Count close parentheses or asterisks
            if (s[length - i] == ')' || locked[length - i] == '0') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        return true;
    }
};