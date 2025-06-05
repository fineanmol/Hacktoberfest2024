class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(string str : strs){
            string word = str;
            sort(word.begin(), word.end());
            mp[word].push_back(str);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};