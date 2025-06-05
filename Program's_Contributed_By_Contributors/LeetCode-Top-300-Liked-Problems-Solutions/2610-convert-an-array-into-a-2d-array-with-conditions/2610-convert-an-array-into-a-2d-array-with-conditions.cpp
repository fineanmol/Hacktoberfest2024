class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size() + 1);
        
        vector<vector<int>> ans;
        for (int c : nums) {
            if (freq[c] >= ans.size()) {
                ans.push_back({});
            }
            
            // Store the integer in the list corresponding to its current frequency.
            ans[freq[c]].push_back(c);
            freq[c]++;
        }
        
        return ans;
    }
};