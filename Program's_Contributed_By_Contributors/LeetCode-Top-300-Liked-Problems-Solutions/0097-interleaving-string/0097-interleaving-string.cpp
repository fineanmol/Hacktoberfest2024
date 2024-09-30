class Solution {
public:
    bool checkInterleave(const string& s1, const string& s2, const string& s3,
                         int i, int j, int k, vector<vector<int>>& memo) {
        if (k == s3.length()) {
            return i == s1.length() && j == s2.length();
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        bool result = false;
        
        if (i < s1.length() && s1[i] == s3[k]) {
            result |= checkInterleave(s1, s2, s3, i + 1, j, k + 1, memo);
        }
        
        if (j < s2.length() && s2[j] == s3[k]) {
            result |= checkInterleave(s1, s2, s3, i, j + 1, k + 1, memo);
        }
        
        memo[i][j] = result ? 1 : 0;
        return result;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));
        
        return checkInterleave(s1, s2, s3, 0, 0, 0, memo);
    }
};
