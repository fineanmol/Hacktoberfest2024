class Solution {
    vector<string> ans;

    void helper(string &s, int i, string sentence, unordered_map<string,int>& dict) {
        if (i >= s.size()) {
            if (sentence.back() == ' ')
                sentence.pop_back();
            ans.push_back(sentence);
            return;
        }
        string temp = "";
        for (int j=i; j<s.size(); j++) {
            
            // push_back() method of C++ string has a 
            // time complexity of amortized constant 
            temp.push_back(s[j]);

            // if the `word` thus made so far, is found
            // in the given dict then append this word
            // to our line and repeat same procedure 
            // again starting with new index j+1.  
            if (dict.find(temp) != dict.end()) { 
                helper(s, j+1, sentence+temp+' ', dict);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        // Hashmap as a dict to store count/presence of contents
        // of `wordDict`
        unordered_map<string, int> dict; 
        for (auto s0: wordDict)
            dict[s0]++;

        // Helper method's call stack is like that of a DFS
        helper(s, 0, "", dict);
        return ans;
    }
};