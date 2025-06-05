class Solution {
public:
    void generate(vector<string> &ans, int n, int open, int close, string cur){
        if(cur.size() == 2 * n){
            ans.push_back(cur);
            return;
        }

        if(open < n)
            generate(ans, n, open + 1, close, cur + "(");
        
        if(close < open)
            generate(ans, n, open, close + 1, cur + ")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, n, 0, 0, "");
        return ans;
    }
};