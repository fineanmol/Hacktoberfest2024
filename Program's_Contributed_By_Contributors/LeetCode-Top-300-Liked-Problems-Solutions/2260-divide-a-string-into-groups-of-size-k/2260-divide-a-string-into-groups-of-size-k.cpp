class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string temp = "";
        vector<string> ans;
        for(int i = 0; i < s.size(); i++){
            temp += s[i];
            if(temp.size() == k){
                ans.push_back(temp);
                temp = "";
            }
        }
        while(temp != "" && temp.size() != k){
            temp += fill;
            if(temp.size() == k)
                ans.push_back(temp);
        }
        return ans;
    }
};