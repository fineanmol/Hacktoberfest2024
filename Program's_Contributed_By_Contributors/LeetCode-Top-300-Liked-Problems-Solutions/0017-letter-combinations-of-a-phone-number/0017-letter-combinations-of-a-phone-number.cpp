class Solution {
public:
    unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    
    void backtrack(int ind, string digits, string str, vector<string> &ans){
        if(ind == digits.size()){
            ans.push_back(str);
            return;
        }
        for(char ch : mp[digits[ind]]){
            backtrack(ind + 1, digits, str + ch, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ans;
        string str = "";
        backtrack(0, digits, str, ans);
        return ans;
    }
};