class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> c;
        for(char ch : s){
            if(!c.empty()){
                if(ch == c.top() + 32 || ch == c.top() - 32)
                    c.pop();
                else
                    c.push(ch);
            }else{
                c.push(ch);
            }
        }
        while(!c.empty()){
            ans += c.top();
            c.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};