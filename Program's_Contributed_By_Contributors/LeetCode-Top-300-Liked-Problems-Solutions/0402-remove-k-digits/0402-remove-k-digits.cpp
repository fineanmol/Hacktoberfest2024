class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n) return "0";
        
        string result = "";
        for (char c : num) {
            while (k > 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        
        result.resize(result.size() - k);
        
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        
        if (start == result.size()) return "0";
        
        return result.substr(start);
    }
};