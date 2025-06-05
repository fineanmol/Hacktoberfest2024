class Solution {
public:
    string removeOuterParentheses(string s) {
        int start = 0, count = 0;
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                count += 1;
            else 
                count -= 1;
            
            if(count == 0){
                for(int j = start + 1; j < i; j++)
                    ans += s[j];
                
                start = i + 1;
            }
        }
        return ans;
    }
};