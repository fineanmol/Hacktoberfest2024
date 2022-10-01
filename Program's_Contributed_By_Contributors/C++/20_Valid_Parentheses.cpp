//https://leetcode.com/problems/valid-parentheses/

//code
class Solution {
public:
    bool isValid(string s) {
     stack<char> bracket;
    for (char& c : s) {
        switch (c) {
            case '(': bracket.push(c); break;
            case '{': bracket.push(c); break;
            case '[': bracket.push(c); break;
            case ')': if (bracket.empty() || bracket.top()!='(') return false; else bracket.pop(); break;
            case '}': if (bracket.empty() || bracket.top()!='{') return false; else bracket.pop(); break;
            case ']': if (bracket.empty() || bracket.top()!='[') return false; else bracket.pop(); break;
            default: ; 
        }
    }
    return bracket.empty() ; 
    }
    };
    
