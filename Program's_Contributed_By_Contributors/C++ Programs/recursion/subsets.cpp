class Solution {
public:
    void func(vector<int>& nums, int ind, vector<int>& v, vector<vector<int>>& ans) {
        if(ind >= nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        func(nums, ind + 1, v, ans);
        v.pop_back();
        func(nums, ind + 1, v, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        func(nums, 0, v, ans);
        return ans;
    }
};