// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> close = {{'(',')'},{'{','}'},{'[',']'}};
        
        stack<char> stack;
        
        for (char c:s){
            if (!stack.empty()){
                
                char top = stack.top();
                if (close[top] == c){
                    stack.pop();
                } else {
                    stack.push(c);
                }
                            

            } else {
                stack.push(c);
            }
            
        }
        
        
        if (!stack.empty())
            return false;
        else
            return true;
        
    }
};