class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        string str, vowels = "aeiou";
        vector<int> prefix(1, 0), ans;
        int sum = 0, n = words.size();
        
        for(int i = 0; i < n; i++){
            str = words[i];
            if(vowels.find(str[0]) != -1 && vowels.find(str.back()) != -1)
                sum += 1;
            prefix.push_back(sum);
        }

        for(auto v : queries){
            int left = v[0], right = v[1];
            ans.push_back(prefix[right + 1] - prefix[left]);
        }

        return ans;
    }
};