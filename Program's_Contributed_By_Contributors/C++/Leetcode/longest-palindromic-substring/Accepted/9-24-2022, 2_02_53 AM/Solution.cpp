// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size()));
        auto max = make_pair(0,0);
        for (int i = 0;i<s.size();i++){
            for (int j = 0;j<s.size();j++){
                
                if (j+i>=s.size()){
                    break;
                }
                
                if (j+i==j){
                    dp[j][j+i] = 1;
                }
                
                else if (i==1){
                    if (s[j]==s[j+i]){
                        dp[j][j+i] = 1;
                    } else {
                        dp[j][j+1] = 0;
                    }
                }
                else {
                    if (s[j]==s[j+i] && dp[j+1][j+i-1]){
                        dp[j][i+j] = 1;
                    } else {
                        dp[j][j+i] = 0;
                    }
                }
                
                if (dp[j][j+i]){
                    if(i+1>(max.second-max.first+1)){
                        max = make_pair(j,j+i);
                    }
                }
            }
        }
        
        return s.substr(max.first,max.second-max.first+1);
    }
};