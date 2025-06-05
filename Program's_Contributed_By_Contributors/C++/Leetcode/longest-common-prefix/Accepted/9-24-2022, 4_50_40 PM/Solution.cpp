// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common;
        
        for (int i = 1;i<=strs[0].size();i++){
            for (int j = 0;j<strs.size();j++){
                if (j==0){
                    common = strs[j].substr(0,i);
                }
                
                else {
                    if (strs[j].substr(0,i)!=common){
                        return common.substr(0,common.size()-1);
                    }
                }
            }
        }
        
        return common;
    }
};