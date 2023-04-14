#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.size()==0) return "";
        for (int i = 0; i<strs[0].size();i++){
            for (int j=1;j<strs.size();j++){
                if (strs[j][i]!=strs[0][i]){
                    return res;
                }
            }
                res+=strs[0][i];
        }
        return res;
    }
};