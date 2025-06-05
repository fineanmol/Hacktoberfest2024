class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        
        vector<int> szToGroup[groupSizes.size() + 1];
        for (int i = 0; i < groupSizes.size(); i++) {
            szToGroup[groupSizes[i]].push_back(i);
            
            
            if (szToGroup[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(szToGroup[groupSizes[i]]);
                szToGroup[groupSizes[i]].clear();
            }
        }
        
        return ans;
    }
};