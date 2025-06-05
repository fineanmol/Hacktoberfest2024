/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

https://leetcode.com/problems/valid-parentheses/description/
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char iter : s) {
            if (iter == '{' || iter == '[' || iter == '(') {
                stack.push_back(iter);
            } 
            else {
                if (stack.empty()) {
                    return false;
                }
                char top = stack.back();
                stack.pop_back();
                if ((iter == '}' && top != '{') ||
                    (iter == ']' && top != '[') ||
                    (iter == ')' && top != '(')) {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};