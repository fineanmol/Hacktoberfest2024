class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> sj;
        
        for (auto x : strs) {
            string temp = x;
            sort(temp.begin(), temp.end());
            
            sj[temp].push_back(x);
        }
        
        vector<vector<string>>Output;
        
        for (auto it : sj) {
            Output.push_back(it.second);
        }
        
        return Output;
    }
};
